#pragma once

// slow the reporting rate down to avoid high-pitched whine. implied by
// <https://www.reddit.com/r/ploopy/comments/td702f/fixing_high_pitched_whine_when_using_a_1000hz/>.
// #define USB_POLLING_INTERVAL_MS 4

#define TAPPING_TERM 250

#define PLOOPY_DRAGSCROLL_FIXED
#define PLOOPY_DRAGSCROLL_DPI 100
// #define PLOOPY_DRAGSCROLL_MOMENTARY // incompatible with LT?
#define PLOOPY_DRAGSCROLL_INVERT
