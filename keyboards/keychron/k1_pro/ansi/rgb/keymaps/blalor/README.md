This is my custom keymap. 

My starting point was the `keychron/q3/rev_0121` keyboard. I added the `custom` keymap, copying the `via` one, then created this `custom-no-via` keymap and dropped VIA support. `config.h` changes the selection of RGB effects (based on what’s enabled in `keychron/q3/config.h`). If you compare my `keymap.c` against `via/keymap.c` you’ll see the changes I made. 

## notable changes

`rgb_matrix_indicators_advanced_user` ([ref](https://docs.qmk.fm/#/feature_rgb_matrix?id=indicators)) illuminates the LEDs under active keys for the current layer, allowing me to see what's available.

Enabled `RGB_DISABLE_TIMEOUT` and `RGB_DISABLE_WHEN_USB_SUSPENDED` to turn off all LEDs after a delay, or when the computer's asleep.

Disabled various unwanted RGB effects.

Enabled typing heatmap, and made the default when waking from sleep.

## flashing

I couldn't get the bootmagic lite method of flashing to work (hold ESC while plugging in cable), but I found the I could enable command mode. After flashing the first time (which requires plugging in while holding reset button, which is under the spacebar), the bootloader can be entered at any time by pressing left+right-alt+control+shift-b.
