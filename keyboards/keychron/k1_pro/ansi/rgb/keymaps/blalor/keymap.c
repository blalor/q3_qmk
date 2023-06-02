#include QMK_KEYBOARD_H
#include "rgb_matrix_ledmaps.h"

enum layers{
    BASE,
    _L1,
    _L2, // active with dip switch
    _L3
};

enum custom_keycodes {
    KVM_SW1 = SAFE_RANGE, // switch to KVM input #1
    KVM_SW2,              // switch to KVM input #2
};

// captured by hammerspoon
#define CH_MUTE LCTL(LALT(LGUI(LSFT(KC_Y))))
#define CH_VID  LCTL(LALT(LGUI(LSFT(KC_V))))
#define CH_BAIL LCTL(LALT(LGUI(LSFT(KC_E))))

enum {
    TD_CHIME_MUTE,
    TD_PW_1,
    TD_PW_2,
};

tap_dance_action_t tap_dance_actions[] = {
    // once for chime mute, twice for chime video toggle
    [TD_CHIME_MUTE] = ACTION_TAP_DANCE_DOUBLE(CH_MUTE, CH_VID),
    [TD_PW_1]       = ACTION_TAP_DANCE_DOUBLE(KC_F18, LSFT(KC_F18)), // password1 (hammerspoon)
    [TD_PW_2]       = ACTION_TAP_DANCE_DOUBLE(KC_F19, LSFT(KC_F19)), // password2 (hammerspoon)
};

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        Esc                 F1        F2        F3        F4        F5        F6        F7        F8        F9        F10       F11       F12               clip      mic       bulb
        `         1         2         3         4         5         6         7         8         9         0         -         =           ⌫               Ins       Home      Pgup
        →         Q         W         E         R         T         Y         U         I         O         P         [         ]           \               Del       End       Pgdn
        Caps      A         S         D         F         G         H         J         K         L         ;         '                     ⏎
        ⇧                   Z         X         C         V         B         N         M         ,         .         /                     ⇧                         Up
        ^         ⌥         ⌘                                       Space                                   ⌘         ⌥         fn          ^               Left      Down      Rght
    */
    [BASE] = LAYOUT_tkl_ansi(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,         KC_NO,    TD(TD_CHIME_MUTE),  MO(_L2),
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,        KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,        KC_DEL,   KC_END,   KC_PGDN,
        KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,                  KC_UP,
        KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_RCMD,  KC_ROPT,  MO(_L1),    KC_RCTL,        KC_LEFT,  KC_DOWN,  KC_RGHT),

    [_L1] = LAYOUT_tkl_ansi(
        KC_ESC,             KC_BRID,  KC_BRIU,  XXXXXXX,  XXXXXXX,  RGB_VAD,  RGB_VAI,  KC_MPRV,  XXXXXXX,  KC_MNXT,  XXXXXXX,  XXXXXXX,    XXXXXXX,        _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,        _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,    _______,        _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,        _______,  _______,  _______),

    [_L2] = LAYOUT_tkl_ansi(
        XXXXXXX,            KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17, TD(TD_PW_1),TD(TD_PW_2),KC_F20, KC_F21,     KC_F22,         XXXXXXX,  CH_BAIL,  XXXXXXX,
        XXXXXXX,  KVM_SW1,  KVM_SW2,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        _______,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,                  XXXXXXX,
        _______,  _______,  _______,                                XXXXXXX,                                _______,  _______,  MO(_L3),    _______,        XXXXXXX,  XXXXXXX,  XXXXXXX),

    // bootmagic entry via escape isn't working, but QK_BOOT does
    [_L3] = LAYOUT_tkl_ansi(
        XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,                  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                                XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,        QK_MAKE,  XXXXXXX,  QK_BOOT),
};

#ifdef RGB_MATRIX_LEDMAPS_ENABLED

#define ______ { RGB_OFF }
#define LYRIND { 0x11, 0x11, 0x11 }

#define RGB_OFFBLUE 0x00, 0x80, 0xFF      // new color: blue with a hint of green
#define RGB_DKRED 0x28, 0x00, 0x00        // new color: dark red
#define RGB_ORANGE2 0xFF, 0x28, 0x00      // fix: reduced green from 80 to 28
#define RGB_PURPLE2 0x80, 0x00, 0xFF      // fix: increased red from 7A to 80
#define RGB_SPRINGGREEN2 0x00, 0xFF, 0x10 // fix: blue was 80, now 10
#define RGB_YELLOW2 0xFF, 0xB0, 0x00      // fix: green was FF, now B0


const ledmap PROGMEM ledmaps[] = {
    /*
        Esc       F1        F2        F3        F4        F5        F6        F7        F8        F9        F10       F11       F12                         Lndr      Astro     Moon
        `         1         2         3         4         5         6         7         8         9         0         -         =           ⌫               Ins       Home      Pgup
        →         Q         W         E         R         T         Y         U         I         O         P         [         ]           \               Del       End       Pgdn
        Caps      A         S         D         F         G         H         J         K         L         ;         '                     ⏎
        ⇧                   Z         X         C         V         B         N         M         ,         .         /                     ⇧                         Up
        ^         ⌥         ⌘                                       Space                                   ⌘         ⌥         fn          ^               Left      Down      Rght
    */
    [BASE] = RGB_MATRIX_LAYOUT_LEDMAP(
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,                     ______,   {RGB_ORANGE2},   LYRIND,
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,     ______,         ______,   ______,   ______,
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,     ______,         ______,   ______,   ______,
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,               ______,
        ______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,               ______,                   ______,
        ______,   ______,   ______,                                 ______,                                 ______,   ______,   LYRIND,     ______,         ______,   ______,   ______
    ),

    [_L1]  = RGB_MATRIX_LAYOUT_LEDMAP(
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   {RGB_OFFBLUE},   ______,   {RGB_OFFBLUE},   ______,   ______,   ______,       ______,   ______,   ______,
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,     ______,         ______,   ______,   ______,
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,     ______,         ______,   ______,   ______,
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,               ______,
        ______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,               ______,                   ______,
        ______,   ______,   ______,                                 ______,                                 ______,   ______,   ______,     ______,         ______,   ______,   ______
    ),

    [_L2]  = RGB_MATRIX_LAYOUT_LEDMAP(
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   PURPLE,   PURPLE,   ______,   ______,   ______,                     ______,   RED,      ______,
        ______,   RED,      GREEN,    ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,     ______,         ______,   ______,   ______,
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,     ______,         ______,   ______,   ______,
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,               ______,
        ______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,               ______,                   ______,
        ______,   ______,   ______,                                 ______,                                 ______,   ______,   LYRIND,     ______,         ______,   ______,   ______
    ),

    [_L3]  = RGB_MATRIX_LAYOUT_LEDMAP(
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,                     ______,   ______,   ______,
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,     ______,         ______,   ______,   ______,
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,     ______,         ______,   ______,   ______,
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,               ______,
        ______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,               ______,                   ______,
        ______,   ______,   ______,                                 ______,                                 ______,   ______,   ______,     ______,         GREEN,    ______,   RED
    ),
};
#endif // RGB_MATRIX_LEDMAPS_ENABLED
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KVM_SW1:
            if (record->event.pressed) {
                tap_code(KC_LCTL);
                tap_code(KC_LCTL);
                tap_code(KC_1);

                return false;
            }
            break;

        case KVM_SW2:
            if (record->event.pressed) {
                tap_code(KC_LCTL);
                tap_code(KC_LCTL);
                tap_code(KC_2);

                return false;
            }
            break;

        default:
            break;
    }

    // Process all other keycodes normally
    return true;
}
