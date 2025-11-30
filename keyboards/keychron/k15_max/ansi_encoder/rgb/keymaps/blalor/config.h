#pragma once

#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS

#undef ENABLE_RGB_MATRIX_CYCLE_ALL
#undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#undef ENABLE_RGB_MATRIX_DUAL_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#undef ENABLE_RGB_MATRIX_RAINDROPS
#undef ENABLE_RGB_MATRIX_PIXEL_FLOW

// defined in the parent dir's config.h
#undef RGB_MATRIX_TIMEOUT
#define RGB_MATRIX_TIMEOUT 1000*60*5 // 5m

#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_TYPING_HEATMAP

/*
 * ⇧^QK_MAKE to type qmk flash … and enter bootloader
 */
#define ENABLE_COMPILE_KEYCODE

/* For smoother cursor movements, lower the value of MOUSEKEY_INTERVAL. If the
   refresh rate of your display is 60Hz, you could set it to 16 (1/60). As this
   raises the cursor speed significantly, you may want to lower
   MOUSEKEY_MAX_SPEED. */
// #define MOUSEKEY_INTERVAL 16
// #define MOUSEKEY_MAX_SPEED

#define MK_KINETIC_SPEED
#define MOUSEKEY_INITIAL_SPEED 200

#define MOUSEKEY_MOVE_DELTA 32 // default is 16

#define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 8 // default is 16
#define MOUSEKEY_WHEEL_BASE_MOVEMENTS 24 // default is 32

// see also from https://www.reddit.com/r/ErgoMechKeyboards/comments/qx7oqg/comment/hl81zbp/
/*
// Mouse key speed and acceleration.
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_INTERVAL       16
#define MOUSEKEY_WHEEL_DELAY    0
#define MOUSEKEY_MAX_SPEED      6
#define MOUSEKEY_TIME_TO_MAX    64
*/
