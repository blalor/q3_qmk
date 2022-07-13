This is my custom keymap. 

My starting point was the `keychron/q3/q3_ansi_stm32l432_ec11` keyboard. I added this `custom` keymap, copying the `via` one. `config.h` changes the selection of RGB effects (based on what’s enabled in `keychron/q3/config.h`). If you compare my `keymap.c` against `via/keymap.c` you’ll see the changes I made. Seems to work fine with Via so far, although the first time I flashed the keyboard I lost my customizations, so back those up first.

## notable changes

`rgb_matrix_indicators_advanced_user` ([ref](https://docs.qmk.fm/#/feature_rgb_matrix?id=indicators)) illuminates the LEDs under active keys for the current layer, allowing me to see what's available.

Enabled `RGB_DISABLE_TIMEOUT` and `RGB_DISABLE_WHEN_USB_SUSPENDED` to turn off all LEDs after a delay, or when the computer's asleep.

Disabled various unwanted RGB effects.

Enabled typing heatmap, and made the default when waking from sleep.
