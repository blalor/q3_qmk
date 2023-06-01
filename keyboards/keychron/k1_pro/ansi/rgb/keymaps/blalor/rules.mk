VIA_ENABLE = no
TAP_DANCE_ENABLE = yes

## conflicts with the KVM
## https://forum.level1techs.com/t/kvm-troubles-with-a-qmk-device/184329
# NKRO_ENABLE = no

RGB_MATRIX_LEDMAPS = yes

ifeq ($(strip $(RGB_MATRIX_LEDMAPS)), yes)
	SRC += rgb_matrix_ledmaps.c
	OPT_DEFS += -DRGB_MATRIX_LEDMAPS_ENABLED
endif
