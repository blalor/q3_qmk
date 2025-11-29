# nuke NKRO, which interferes with my kvm
NKRO_ENABLE = no

VIA_ENABLE = no
TAP_DANCE_ENABLE = yes

RGB_MATRIX_LEDMAPS = yes

ifeq ($(strip $(RGB_MATRIX_LEDMAPS)), yes)
	SRC += rgb_matrix_ledmaps.c
	OPT_DEFS += -DRGB_MATRIX_LEDMAPS_ENABLED
endif
