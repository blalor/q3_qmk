# github.com/blalor/q3_qmk

As of 2025-11-30.  Note: this repo's name hasn't been accurate for years.

## branches

### [`customized`](https://github.com/blalor/q3_qmk/tree/customized)

Should track qmk/qmk_firmware:master.

* Keychron Q3
* Keychron Q10
* Ploopy Thumb

### [`wls_2025q1_customized`](https://github.com/blalor/q3_qmk/tree/wls_2025q1_customized)

Branched from [Keychron/qmk_firmware:wls_2025q1](https://github.com/Keychron/qmk_firmware/commit/ed3f307267fa63acd12377f21117b4471d2df82e).

* Keychron K1 Pro
* Keychron V10 Max
* Keychron K15 Max (no longer have)

## building

Check out the appropriate branch.

* Q3 - `qmk compile -kb keychron/q3/ansi_encoder -km blalor`
* Q10 - `qmk compile -kb keychron/q10/ansi_encoder -km blalor`
* Ploopy Thumb - `qmk compile -kb ploopyco/trackball_thumb -km blalor`
* K1 Pro - `qmk compile -kb keychron/k1_pro/ansi/rgb -km blalor`
* V10 Max - `qmk compile -kb keychron/v10_max/ansi_encoder -km blalor`

Flash with `qmk flash -kb … -km blalor`

<!--
# This is blalor's `customized` branch

It has my customizations for the Keychron Q3, originally forked from [Keychron's playground branch/fork](https://github.com/Keychron/qmk_firmware/tree/playground/keyboards/keychron), and now tracking [their PR](https://github.com/qmk/qmk_firmware/pull/16912) to merge into the QMK mainline. See [`keyboards/keychron/q3/rev_0121/keymaps/custom-no-via`](keyboards/keychron/q3/rev_0121/keymaps/custom-no-via).

Also here is the Ploopy Thumb trackball, tracking [their PR](https://github.com/qmk/qmk_firmware/pull/18214) into the QMK mainline.. See [`keyboards/ploopyco/trackball_thumb/keymaps/default`](keyboards/ploopyco/trackball_thumb/keymaps/default).
-->
