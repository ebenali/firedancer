$(call add-hdrs,fd_metrics_all.h fd_metrics_quic.h)
$(call add-objs,fd_metrics_all fd_metrics_net fd_metrics_quic fd_metrics_verify fd_metrics_dedup fd_metrics_pack fd_metrics_bank fd_metrics_poh fd_metrics_store fd_metrics_shred,fd_disco)

ifdef FD_HAS_NO_AGAVE
$(call add-objs,fd_metrics_replay,fd_disco)
$(call add-objs,fd_metrics_storei,fd_disco)
endif
