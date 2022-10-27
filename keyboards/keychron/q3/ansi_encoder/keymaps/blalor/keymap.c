#include QMK_KEYBOARD_H

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

qk_tap_dance_action_t tap_dance_actions[] = {
    // once for chime mute, twice for chime video toggle
    [TD_CHIME_MUTE] = ACTION_TAP_DANCE_DOUBLE(CH_MUTE, CH_VID),
    [TD_PW_1]       = ACTION_TAP_DANCE_DOUBLE(KC_F18, LSFT(KC_F18)), // password1 (hammerspoon)
    [TD_PW_2]       = ACTION_TAP_DANCE_DOUBLE(KC_F19, LSFT(KC_F19)), // password2 (hammerspoon)
};

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_tkl_f13_ansi(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MPLY,        KC_NO,    TD(TD_CHIME_MUTE),  MO(_L2),
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,        KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,        KC_DEL,   KC_END,   KC_PGDN,
        KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,                  KC_UP,
        KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_RCMD,  KC_ROPT,  MO(_L1), KC_RCTL,        KC_LEFT,  KC_DOWN,  KC_RGHT),

    [_L1] = LAYOUT_tkl_f13_ansi(
        KC_ESC,   KC_BRID,  KC_BRIU,  XXXXXXX,  XXXXXXX,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RGB_TOG,        _______,  _______,  RGB_MOD,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,        _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,    _______,        _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,        _______,  _______,  _______),

    [_L2] = LAYOUT_tkl_f13_ansi(
        XXXXXXX,  KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17, TD(TD_PW_1),TD(TD_PW_2),KC_F20, KC_F21,   KC_F22,     XXXXXXX,        XXXXXXX,  CH_BAIL,  XXXXXXX,
        XXXXXXX,  KVM_SW1,  KVM_SW2,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        _______,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,                  XXXXXXX,
        _______,  _______,  _______,                                XXXXXXX,                                 _______,  _______,  MO(_L3), _______,       XXXXXXX,  XXXXXXX,  XXXXXXX),

    // bootmagic entry via escape isn't working, but QK_BOOT does
    [_L3] = LAYOUT_tkl_f13_ansi(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,                  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                                XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,        QK_MAKE,  XXXXXXX,  QK_BOOT),
};

// clang-format on

const uint16_t PROGMEM encoder_map[][1][2] = {
    [BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_L1]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [_L2]  = {ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [_L3]  = {ENCODER_CCW_CW(XXXXXXX, XXXXXXX) }
};

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

// https://docs.qmk.fm/#/feature_rgb_matrix?id=indicators
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index <= led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_AZURE);
                }
            }
        }
    }
}
