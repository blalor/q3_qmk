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

#pragma once

/*
 * Keyboard Matrix Assignments
 */
#define DIRECT_PINS            \
    {                          \
        { D5, B6, D4, D2, E6, D7 } \
    }

// These pins are not broken out, and cannot be used normally.
// - D1, D3, B4, B7, D6, C7, F6, F5, F3, F7

// If board has a debug LED, you can enable it by defining this
#define RGB_DI_PIN B5
#define RGBLED_NUM 3
#define RGBLIGHT_LIMIT_VAL 40
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
