/* Copyright 2024 ~ 2025 @ Keychron (https://www.keychron.com)
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
#include "rgb_matrix_ledmaps.h"
#include "keychron_common.h"
#include "transport.h"

enum layers {
    BASE,
    _L1,
    _L2, // active with dip switch
    _L3,
};

enum custom_keycodes {
    KVM_SW1 = SAFE_RANGE, // switch to KVM input #1
    KVM_SW2,              // switch to KVM input #2
};


// captured by hammerspoon
#define CM_MUTE LCTL(LALT(LGUI(LSFT(KC_Y))))
#define CM_VID  LCTL(LALT(LGUI(LSFT(KC_V))))
#define CM_BAIL LCTL(LALT(LGUI(LSFT(KC_E))))

enum {
    TD_CONF_MUTE,
    TD_PW_1,
    TD_PW_2,
};

tap_dance_action_t tap_dance_actions[] = {
    // once for video conference audio mute, twice for video toggle
    [TD_CONF_MUTE] = ACTION_TAP_DANCE_DOUBLE(CM_MUTE, CM_VID),
    [TD_PW_1]      = ACTION_TAP_DANCE_DOUBLE(KC_F18, LSFT(KC_F18)), // password1 (hammerspoon)
    [TD_PW_2]      = ACTION_TAP_DANCE_DOUBLE(KC_F19, LSFT(KC_F19)), // password2 (hammerspoon)
};

#define _CM TD(TD_CONF_MUTE)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        rot btn     Esc       F1        F2        F3        F4        F5         F6        F7        F8        F9        F10       F11       F12       Del                           Pgup
        M1          `         1         2         3         4         5          6         7         8         9         0         -         =         ⌫                             Pgdn
        M2          →         Q         W         E         R         T          Y         U         I         O         P         [         ]                   \                   Home
        M3          Caps      A         S         D         F         G          H         J         K         L         ;         '                   ⏎                             End
        M4          ⇧                   Z         X         C         V          B         B         N         M         ,         .         /         ⇧                   Up
        M5          ^         ⌥                   ⌘         Space     fn                             Space               ⌘                                       Left      Down      Rght
    */
    [BASE] = LAYOUT_ansi_89(
        KC_MPLY,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,                       KC_HOME,
        _CM,        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,                      KC_PGUP,
        MC_2,       KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,            KC_BSLS,            KC_PGDN,
        MC_3,       KC_ESC ,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,                       KC_END,
        MC_4,       KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_NO,    KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,
        MO(_L2),    KC_LCTL,  KC_LOPTN,           KC_LCMMD, KC_SPC,   MO(_L1),                       KC_SPC,             KC_RCMMD,                               KC_LEFT,  KC_DOWN,  KC_RGHT),

    [_L1] = LAYOUT_ansi_89(
        RGB_TOG,    _______,  KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,                      _______,
        _______,    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_DEL,                       _______,
        _______,    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,    _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,            _______,                      KC_END,
        _______,    _______,            _______,  _______,  _______,  _______,   BAT_LVL,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,    _______,  _______,            _______,  _______,  _______,                       _______,            _______,                                _______,  _______,  _______),

    [_L2] = LAYOUT_ansi_89(
        XXXXXXX,    XXXXXXX,  KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15,    KC_F16,   KC_F17,TD(TD_PW_1),TD(TD_PW_2),KC_F20,  KC_F21,   KC_F22,   XXXXXXX,                      XXXXXXX,
        CM_BAIL,    XXXXXXX,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,            XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,                      XXXXXXX,
        XXXXXXX,    XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  MO(_L3),                       XXXXXXX,            XXXXXXX,                                XXXXXXX,  XXXXXXX,  XXXXXXX),

    // alternative to bootmagic entry via escape with QK_BOOT
    [_L3] = LAYOUT_ansi_89(
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,                      XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,                      XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,            XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,                      XXXXXXX,
        XXXXXXX,    XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,            XXXXXXX,                                 QK_MAKE,  XXXXXXX,  QK_BOOT),
};


#ifdef RGB_MATRIX_LEDMAPS_ENABLED

#define ______ { RGB_OFF }
#define LYRIND { 0x11, 0x11, 0x11 }

#define OFFBLU {0x00, 0x80, 0xFF}      // new color: blue with a hint of green (RGB_OFFBLUE)
#define RGB_DKRED 0x28, 0x00, 0x00        // new color: dark red
#define ORANG2 {0xFF, 0x28, 0x00}      // fix: reduced green from 80 to 28 (RGB_ORANGE2)
#define RGB_PURPLE2 0x80, 0x00, 0xFF      // fix: increased red from 7A to 80
#define RGB_SPRINGGREEN2 0x00, 0xFF, 0x10 // fix: blue was 80, now 10
#define RGB_YELLOW2 0xFF, 0xB0, 0x00      // fix: green was FF, now B0


const ledmap PROGMEM ledmaps[] = {
    /*
        rot btn   Esc       F1        F2        F3        F4        F5        F6        F7        F8        F9        F10       F11       F12                 Ins                 Del
        M1        `         1         2         3         4         5         6         7         8         9         0         -         =         ⌫                   Pgup
        M2        →         Q         W         E         R         T         Y         U         I         O         P         [         ]         \                   Pgdn
        M3        Caps      A         S         D         F         G         H         J         K         L         ;         '                   ⏎                   Home
        M4        ⇧                   Z         X         C         V         B         B         N         M         ,         .         /         ⇧         Up
        M5        ^         ⌥                   ⌘         Space     fn                            Space               ⌘                             Left      Down      Rght
    */
    [BASE] = RGB_MATRIX_LAYOUT_LEDMAP(
                  ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,
        ORANG2,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,
        ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,
        ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,
        ______,   ______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,
        LYRIND,   ______,   ______,             ______,   ______,   LYRIND,                       ______,             ______,                       ______,   ______,   ______
    ),

    [_L1]  = RGB_MATRIX_LAYOUT_LEDMAP(
                  ______,   ______,   ______,   ______,   ______,   ______,   ______,   OFFBLU,   ______,   OFFBLU,   ______,   ______,   ______,   ______,             ______,
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,
        ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,
        ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,
        ______,   ______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,
        ______,   ______,   ______,             ______,   ______,   ______,                       ______,             ______,                       ______,   ______,   ______
    ),

    [_L2]  = RGB_MATRIX_LAYOUT_LEDMAP(
                  ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   PURPLE,   PURPLE,   ______,   ______,   ______,   ______,             ______,
        RED,      ______,   RED,      GREEN,    ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,
        ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,
        ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,
        ______,   ______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,
        ______,   ______,   ______,             ______,   ______,   LYRIND,                       ______,             ______,                       ______,   ______,   ______
    ),

    [_L3]  = RGB_MATRIX_LAYOUT_LEDMAP(
                  ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,
        ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,
        ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,
        ______,   ______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,
        ______,   ______,   ______,             ______,   ______,   ______,                       ______,             ______,                       GREEN,    ______,   RED
    ),
};
#endif // RGB_MATRIX_LEDMAPS_ENABLED
// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_L1]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_L2]  = {ENCODER_CCW_CW(XXXXXXX, XXXXXXX)},
    [_L3]  = {ENCODER_CCW_CW(XXXXXXX, XXXXXXX)}
};
#endif // ENCODER_MAP_ENABLE

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // switch to wireless host 1 or 2, or KVM input 1 or 2
        case BT_HST1 ... BT_HST3:
            if (get_transport() != TRANSPORT_BLUETOOTH) {
                // switch KVM input
                if (record->event.pressed) {
                    tap_code(KC_LCTL);
                    tap_code(KC_LCTL);
                    tap_code(KC_1 + (keycode - BT_HST1));

                    return false;
                }
            }
            else {
                // defer to the built-in handling for these keycodes
                return process_record_keychron_common(keycode, record);
            }

            break;

        default:
            break;
    }

    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }

    // Process all other keycodes normally
    return true;
}
