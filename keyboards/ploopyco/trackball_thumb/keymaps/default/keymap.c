/* Copyright 2021 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// safe range starts at `PLOOPY_SAFE_RANGE` instead.

enum {
    TD_B5,
    TD_B6,
};

void handle_btn5(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_BTN5);
        reset_tap_dance(state);
    } else if (state->count == 2) {
        // … ?
        reset_tap_dance(state);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_B5] = ACTION_TAP_DANCE_FN(handle_btn5),
    // once for button 6, twice DPI change
    [TD_B6] = ACTION_TAP_DANCE_DOUBLE(KC_BTN6, DPI_CONFIG),
};

/*
0 | 2 | 3 | 4 | 5 |
1 |
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_BTN4,       MO(1),      KC_BTN1,    KC_BTN3,    KC_BTN2,    KC_BTN5),
    [1] = LAYOUT(DRAG_SCROLL,   _______,    _______,    _______,    _______,    DPI_CONFIG),
};
