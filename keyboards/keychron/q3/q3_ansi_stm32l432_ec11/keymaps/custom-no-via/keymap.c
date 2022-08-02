#include QMK_KEYBOARD_H

#include "qmk_rc.h"
#include "print.h"

// top row, 2nd in from right
#define MIC_INDICATOR_IDX 14
bool mic_is_enabled = false;
bool mic_is_muted = false;

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};

enum custom_keycodes {
    KC_MISSION_CONTROL = SAFE_RANGE,
    KC_LAUNCHPAD,
    KC_LOPTN,
    KC_ROPTN,
    KC_LCMMD,
    KC_RCMMD,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER,
    KC_SCREEN_SHOT,
    KC_CORTANA
};

#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_TASK KC_TASK_VIEW
#define KC_FLXP KC_FILE_EXPLORER
#define KC_SNAP KC_SCREEN_SHOT
#define KC_CRTA KC_CORTANA

#define CH_MUTE LCTL(LALT(LGUI(LSFT(KC_Y))))
#define CH_VID  LCTL(LALT(LGUI(LSFT(KC_V))))
#define CH_BAIL LCTL(LALT(LGUI(LSFT(KC_E))))

typedef struct PACKED {
    uint8_t len;
    uint8_t keycode[3];
} key_combination_t;

key_combination_t key_comb_list[4] = {
    {2, {KC_LWIN, KC_TAB}},
    {2, {KC_LWIN, KC_E}},
    {3, {KC_LSFT, KC_LCMD, KC_4}},
    {2, {KC_LWIN, KC_C}}
};

static uint8_t mac_keycode[4] = { KC_LOPT, KC_ROPT, KC_LCMD, KC_RCMD };

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
    [MAC_BASE] = LAYOUT_all(
                                                                                                                                        KC_VOLD, KC_VOLU,
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MPLY,        KC_NO,    TD(TD_CHIME_MUTE),  MO(WIN_BASE),
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,        KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,        KC_DEL,   KC_END,   KC_PGDN,
        KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,                  KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN, MO(MAC_FN), KC_RCTL,        KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_all(
                                                                                                                                        RGB_VAD, RGB_VAI,
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RGB_TOG,        _______,  _______,  RGB_MOD,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,        _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,    _______,        _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,        _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_all(
                                                                                                                                        XXXXXXX, XXXXXXX,
        XXXXXXX,  KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17, TD(TD_PW_1),TD(TD_PW_2),KC_F20, KC_F21,   KC_F22,     XXXXXXX,        XXXXXXX,  CH_BAIL,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        _______,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,                  XXXXXXX,
        _______,  _______,  _______,                                XXXXXXX,                                 _______,  _______,  MO(WIN_FN), _______,       XXXXXXX,  XXXXXXX,  XXXXXXX),

    // bootmagic entry via escape isn't working, but QK_BOOT does
    [WIN_FN] = LAYOUT_all(
                                                                                                                                        XXXXXXX, XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,                  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                                XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,        XXXXXXX,  XXXXXXX,  QK_BOOT),
};

// clang-format on

#if defined(ENCODER_ENABLE)

#define ENCODERS 1
static uint8_t  encoder_state[ENCODERS] = {0};
static keypos_t encoder_cw[ENCODERS]    = {{ 8, 5 }};
static keypos_t encoder_ccw[ENCODERS]  = {{ 7, 5 }};

void encoder_action_unregister(void) {
    for (int index = 0; index < ENCODERS; ++index) {
        if (encoder_state[index]) {
            keyevent_t encoder_event = (keyevent_t) {
                .key = encoder_state[index] >> 1 ? encoder_cw[index] : encoder_ccw[index],
                .pressed = false,
                .time = (timer_read() | 1)
            };
            encoder_state[index] = 0;
            action_exec(encoder_event);
        }
    }
}

void encoder_action_register(uint8_t index, bool clockwise) {
    keyevent_t encoder_event = (keyevent_t) {
        .key = clockwise ? encoder_cw[index] : encoder_ccw[index],
        .pressed = true,
        .time = (timer_read() | 1)
    };
    encoder_state[index] = (clockwise ^ 1) | (clockwise << 1);
    action_exec(encoder_event);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    encoder_action_register(index, clockwise);
    return false;
};

#endif

void matrix_scan_user(void) {
#if defined(ENCODER_ENABLE)
    encoder_action_unregister();
#endif
}

// bool dip_switch_update_user(uint8_t index, bool active) {
//     /* Send default layer state to host */
//     system_switch_state_report(index, active);
//     return true;
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key

        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key

        case KC_LOPTN:
        case KC_ROPTN:
        case KC_LCMMD:
        case KC_RCMMD:
            if (record->event.pressed) {
                register_code(mac_keycode[keycode - KC_LOPTN]);
            } else {
                unregister_code(mac_keycode[keycode - KC_LOPTN]);
            }
            return false;  // Skip all further processing of this key

        case KC_TASK:
        case KC_FLXP:
        case KC_SNAP:
        case KC_CRTA:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    register_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            } else {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    unregister_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            }
            return false;  // Skip all further processing of this key

        default:
            return true;  // Process all other keycodes normally
    }
}

// https://docs.qmk.fm/#/feature_rgb_matrix?id=indicators
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);
    if (layer > 0) {
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

    //
    if (mic_is_enabled) {
        if (mic_is_muted) {
            rgb_matrix_set_color(MIC_INDICATOR_IDX, RGB_RED);
        } else {
            rgb_matrix_set_color(MIC_INDICATOR_IDX, RGB_GREEN);
        }
    }
}

#ifdef RAW_ENABLE
#define QMK_RC_BUFFER_MAX 64
uint8_t qmk_rc_buffer[QMK_RC_BUFFER_MAX] = {};

void raw_hid_receive(uint8_t *data, uint8_t length) {
    qmk_rc_receive(qmk_rc_buffer, QMK_RC_BUFFER_MAX, data, length);
}

enum custom_rc_commands {
    SET_MIC_ON = 50,
    SET_MIC_OFF,
    SET_MUTE_ON,
    SET_MUTE_OFF,
};

void qmk_rc_process_command_user(qmk_rc_command_t* command) {
    xprintf("qmk_rc_process_command_user id %02d\n", command->id);

    switch (command->id) {
        case SET_MIC_ON:
            mic_is_enabled = true;
            break;

        case SET_MIC_OFF:
            mic_is_enabled = false;
            break;

        case SET_MUTE_ON:
            mic_is_muted = true;
            break;

        case SET_MUTE_OFF:
            mic_is_muted = false;
            break;
    }
}
#endif
