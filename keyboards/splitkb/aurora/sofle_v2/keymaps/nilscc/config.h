/* Copyright 2023 splitkb.com <support@splitkb.com>
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

// increase LED hit count, might be a bit excessive...
#define LED_HITS_TO_REMEMBER 100

// rgb matrix effects moved to different header to keep things organized
#include "rgb_effects.h"

#define RGB_MATRIX_SLEEP
#define RGB_MATRIX_KEYPRESSES

// #define ENCODER_RESOLUTIONS { 2 }

// data sync options, see:
// - https://docs.qmk.fm/features/split_keyboard#data-sync-options
#define SPLIT_LAYER_STATE_ENABLE // requiered for rgb layer indicators
#define SPLIT_MODS_ENABLE // transfer modifiers to both sides

// Default delay when tapping key codes in macros
// #define TAP_CODE_DELAY 80 // in ms
