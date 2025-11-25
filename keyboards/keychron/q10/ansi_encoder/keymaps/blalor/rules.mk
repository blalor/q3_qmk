# nuke NKRO, which interferes with my kvm
NKRO_ENABLE = no
OPT_DEFS += -UAPDAPTIVE_NKRO_ENABLE

# I don't know what it is but I don't want it. but keychron doesn't believe in ifdef guards. 🫠
# OPT_DEFS += -UFACTORY_TEST_ENABLE

VIA_ENABLE = no
TAP_DANCE_ENABLE = yes

RGB_MATRIX_LEDMAPS = yes

ifeq ($(strip $(RGB_MATRIX_LEDMAPS)), yes)
	SRC += rgb_matrix_ledmaps.c
	OPT_DEFS += -DRGB_MATRIX_LEDMAPS_ENABLED
endif
