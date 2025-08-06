# nuke NKRO, which interferes with my kvm
NKRO_ENABLE = no
OPT_DEFS += -UAPDAPTIVE_NKRO_ENABLE

# I don't know what it is but I don't want it. but keychron doesn't believe in ifdef guards. 🫠
# OPT_DEFS += -UFACTORY_TEST_ENABLE
