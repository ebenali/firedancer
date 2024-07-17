#!/usr/bin/env python3

"""
gen_features.py auto-generates fd_features_generated.{h,c} from
feature_map.json.
"""

import argparse
import json
from pathlib import Path
import struct

import fd58


def generate(feature_map_path, header_path, body_path):
    with open(feature_map_path, "r") as json_file:
        feature_map = json.load(json_file)

    header = open(header_path, "w")
    body = open(body_path, "w")

    # Generate struct body of fd_features_t.
    fd_features_t_params = []
    rmap = {}
    fm = feature_map
    for x in fm:
        short_id = "0x%016x" % (
            struct.unpack("<Q", fd58.dec32(x["pubkey"].encode("ascii"))[0:8])
        )
        fd_features_t_params.append(f"    /* {short_id} */ ulong {x['name']};")
        rmap[x["pubkey"]] = x["name"]
        if "old" in x:
            rmap[x["old"]] = x["name"]
    fd_features_t_params = "\n".join(fd_features_t_params)

    # Write header file.
    print(
        f"""/* Code generated by gen_features.py. DO NOT EDIT. */

#ifndef HEADER_fd_src_flamenco_features_fd_features_h
#error "Include fd_features.h instead of this file."
#endif

/* FEATURE_ID_CNT is the number of features in ids */

#define FD_FEATURE_ID_CNT ({len(fm)}UL)

union fd_features {{

  ulong f[ FD_FEATURE_ID_CNT ];

  struct {{
{fd_features_t_params}
  }};

}};""",
        file=header,
    )

    def pubkey_to_c_array(pubkey):
        raw = fd58.dec32(pubkey.encode("ascii"))
        return '"' + "".join([f"\\x{byte:02x}" for byte in raw]) + '"'

    print(
        f"""/* Code generated by gen_features.py. DO NOT EDIT. */

#include "fd_features.h"
#include <stddef.h>

fd_feature_id_t const ids[] = {{""",
        file=body,
    )
    for x in fm:
        print(
            f'''  {{ .index      = offsetof(fd_features_t, {x["name"]})>>3,
    .id         = {{{pubkey_to_c_array(x["pubkey"])}}},
                  /* {x["pubkey"]} */
    .name       = "{x["name"]}"''',
            file=body,
            end="",
        )
        if x.get("cleaned_up"):
            print(f",\n    .cleaned_up = {x.get('cleaned_up')}", file=body, end="")
        print(" },\n", file=body)
    print(
        f"""  {{ .index = ULONG_MAX }}
}};

/* TODO replace this with fd_map_perfect */

FD_FN_CONST fd_feature_id_t const *
fd_feature_id_query( ulong prefix ) {{

  switch( prefix ) {{""",
        file=body)
    for i, x in enumerate(fm):
        print(f'''  case {"0x%016x" % struct.unpack("<Q", fd58.dec32(x["pubkey"].encode('ascii'))[:8])}: return &ids[{"% 4d" % (i)} ];''',  file=body)
        if "old" in x:
            print(f'''  case {"0x%016x" % struct.unpack("<Q", fd58.dec32(x["old"].encode('ascii'))[:8])}: return &ids[{"% 4d" % (i)} ];''',  file=body)
    print(
        f"""  default: break;
  }}

  return NULL;
}}

/* Verify that offset calculations are correct */

{
    chr(0xa).join([
    'FD_STATIC_ASSERT( offsetof( fd_features_t, %-55s )>>3==%3dUL, layout );' % (x["name"], i)
    for i, x in enumerate(fm)
    ])
}

FD_STATIC_ASSERT( sizeof( fd_features_t )>>3==FD_FEATURE_ID_CNT, layout );""",
        file=body,
    )


def main():
    script_dir = Path(__file__).parent
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--feature_map",
        help="feature map file",
        type=Path,
        default=script_dir / "feature_map.json",
    )
    parser.add_argument(
        "--header",
        help="header file to write",
        type=Path,
        default=script_dir / "fd_features_generated.h",
    )
    parser.add_argument(
        "--body",
        help="body file to write",
        type=Path,
        default=script_dir / "fd_features_generated.c",
    )
    args = parser.parse_args()

    generate(
        feature_map_path=args.feature_map,
        header_path=args.header,
        body_path=args.body,
    )


if __name__ == "__main__":
    main()
