/* Copyright 2017 Jason Williams
 * Copyright 2017 Jack Humbert
 * Copyright 2018 Yiancar
 * Copyright 2019 Daniel Prilik
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

#include <stdint.h>
#include <stdbool.h>
#include "color.h"
#include "quantum.h"

#ifdef IS31FL3731
    #include "is31fl3731.h"
#elif defined (IS31FL3733)
    #include "is31fl3733.h"
#endif

enum rgb_matrix_effects {
	RGB_MATRIX_SOLID_COLOR = 1,
#ifndef DISABLE_RGB_MATRIX_ALPHAS_MODS
    RGB_MATRIX_ALPHAS_MODS,
#endif
#ifndef DISABLE_RGB_MATRIX_DUAL_BEACON
    RGB_MATRIX_DUAL_BEACON,
#endif
#ifndef DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    RGB_MATRIX_GRADIENT_UP_DOWN,
#endif
#ifndef DISABLE_RGB_MATRIX_RAINDROPS
    RGB_MATRIX_RAINDROPS,
#endif
#ifndef DISABLE_RGB_MATRIX_CYCLE_ALL
    RGB_MATRIX_CYCLE_ALL,
#endif
#ifndef DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    RGB_MATRIX_CYCLE_LEFT_RIGHT,
#endif
#ifndef DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
    RGB_MATRIX_CYCLE_UP_DOWN,
#endif
#ifndef DISABLE_RGB_MATRIX_RAINBOW_BEACON
    RGB_MATRIX_RAINBOW_BEACON,
#endif
#ifndef DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    RGB_MATRIX_RAINBOW_PINWHEELS,
#endif
#ifndef DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    RGB_MATRIX_RAINBOW_MOVING_CHEVRON,
#endif
#ifndef DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    RGB_MATRIX_JELLYBEAN_RAINDROPS,
#endif
#ifndef DISABLE_RGB_MATRIX_DIGITAL_RAIN
    RGB_MATRIX_DIGITAL_RAIN,
#endif
#ifndef DISABLE_RGB_MATRIX_BREATHING
    RGB_MATRIX_BREATHING,
#endif
#ifdef RGB_MATRIX_KEYPRESSES
   #ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE
       RGB_MATRIX_SOLID_REACTIVE,
   #endif
   #ifndef DISABLE_RGB_MATRIX_SPLASH
       RGB_MATRIX_SPLASH,
   #endif
   #ifndef DISABLE_RGB_MATRIX_MULTISPLASH
       RGB_MATRIX_MULTISPLASH,
   #endif
   #ifndef DISABLE_RGB_MATRIX_SOLID_SPLASH
       RGB_MATRIX_SOLID_SPLASH,
   #endif
   #ifndef DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
       RGB_MATRIX_SOLID_MULTISPLASH,
   #endif
#endif
    RGB_MATRIX_CUSTOM
};

// Expose built-in effects
void rgb_matrix_effect_all_off                (uint16_t led_i);
void rgb_matrix_effect_alphas_mods            (uint16_t led_i);
void rgb_matrix_effect_breathing              (uint16_t led_i);
void rgb_matrix_effect_cycle_all              (uint16_t led_i);
void rgb_matrix_effect_cycle_left_right       (uint16_t led_i);
void rgb_matrix_effect_cycle_up_down          (uint16_t led_i);
void rgb_matrix_effect_digital_rain           (uint16_t led_i, bool init);
void rgb_matrix_effect_dual_beacon            (uint16_t led_i);
void rgb_matrix_effect_gradient_up_down       (uint16_t led_i);
void rgb_matrix_effect_jellybean_raindrops    (uint16_t led_i, bool init);
void rgb_matrix_effect_multisplash            (uint16_t led_i);
void rgb_matrix_effect_rainbow_beacon         (uint16_t led_i);
void rgb_matrix_effect_rainbow_moving_chevron (uint16_t led_i);
void rgb_matrix_effect_rainbow_pinwheels      (uint16_t led_i);
void rgb_matrix_effect_raindrops              (uint16_t led_i, bool init);
void rgb_matrix_effect_solid_color            (uint16_t led_i);
void rgb_matrix_effect_solid_multisplash      (uint16_t led_i);
void rgb_matrix_effect_solid_reactive         (uint16_t led_i);
void rgb_matrix_effect_solid_splash           (uint16_t led_i);
void rgb_matrix_effect_splash                 (uint16_t led_i);

// Specify single-led color (in various formats)
void rgb_matrix_set_color(uint16_t index, uint8_t red, uint8_t green, uint8_t blue);
void rgb_matrix_set_color_rgb(uint16_t index, RGB rgb);
void rgb_matrix_set_color_hsv(uint16_t index, HSV hsv);

void rgb_matrix_init(void);
void rgb_matrix_task(void);
bool process_rgb_matrix(uint16_t keycode, keyrecord_t *record);

void rgb_matrix_toggle(void);
void rgb_matrix_enable(void);
void rgb_matrix_enable_noeeprom(void);
void rgb_matrix_disable(void);
void rgb_matrix_disable_noeeprom(void);
void rgb_matrix_step(void);
void rgb_matrix_sethsv(uint16_t hue, uint8_t sat, uint8_t val);
void rgb_matrix_sethsv_noeeprom(uint16_t hue, uint8_t sat, uint8_t val);
void rgb_matrix_step_reverse(void);
void rgb_matrix_increase_hue(void);
void rgb_matrix_decrease_hue(void);
void rgb_matrix_increase_sat(void);
void rgb_matrix_decrease_sat(void);
void rgb_matrix_increase_val(void);
void rgb_matrix_decrease_val(void);
void rgb_matrix_increase_speed(void);
void rgb_matrix_decrease_speed(void);
void rgb_matrix_mode(uint8_t mode);
void rgb_matrix_mode_noeeprom(uint8_t mode);
void rgb_matrix_set_suspend_state(bool state);
uint32_t rgb_matrix_get_mode(void);

#ifndef RGBLIGHT_ENABLE
#define rgblight_toggle() rgb_matrix_toggle()
#define rgblight_enable() rgb_matrix_enable()
#define rgblight_enable_noeeprom() rgb_matrix_enable_noeeprom()
#define rgblight_disable() rgb_matrix_disable()
#define rgblight_disable_noeeprom() rgb_matrix_disable_noeeprom()
#define rgblight_step() rgb_matrix_step()
#define rgblight_sethsv(hue, sat, val) rgb_matrix_sethsv(hue, sat, val)
#define rgblight_sethsv_noeeprom(hue, sat, val) rgb_matrix_sethsv_noeeprom(hue, sat, val)
#define rgblight_step_reverse() rgb_matrix_step_reverse()
#define rgblight_increase_hue() rgb_matrix_increase_hue()
#define rgblight_decrease_hue() rgb_matrix_decrease_hue()
#define rgblight_increase_sat() rgb_matrix_increase_sat()
#define rgblight_decrease_sat() rgb_matrix_decrease_sat()
#define rgblight_increase_val() rgb_matrix_increase_val()
#define rgblight_decrease_val() rgb_matrix_decrease_val()
#define rgblight_increase_speed() rgb_matrix_increase_speed()
#define rgblight_decrease_speed() rgb_matrix_decrease_speed()
#define rgblight_mode(mode) rgb_matrix_mode(mode)
#define rgblight_mode_noeeprom(mode) rgb_matrix_mode_noeeprom(mode)
#define rgblight_get_mode() rgb_matrix_get_mode()
#endif

/*-------------------  Globals (mainly used in effects)  ---------------------*/

#ifdef RGB_MATRIX_EXTRA_TOG
typedef enum {
  RGB_ZONE_OFF = 0,
  RGB_ZONE_ALL,
  RGB_ZONE_KEYS,
  RGB_ZONE_UNDER,
} rgb_zone_t;
#endif

typedef union {
  uint32_t raw;
  struct {
#ifdef RGB_MATRIX_EXTRA_TOG
    uint8_t enable  :2;
    uint8_t mode    :6;
#else
    uint8_t enable  :1;
    uint8_t mode    :7;
#endif
    HSV hsv;
    //EECONFIG needs to be increased to support these
    uint8_t speed;
    uint8_t custom;
  };
} rgb_config_t;

extern rgb_config_t rgb_matrix_config;

extern bool g_suspend_state;
extern uint32_t g_tick;                     // Ticks every frame
extern uint8_t g_key_hit[DRIVER_LED_TOTAL]; // Ticks since this key was last hit.
extern uint32_t g_any_key_hit;              // Ticks since any key was last hit.
extern uint16_t g_last_keycode;             // Last keycode hit

/*---------------------------  Things to override  ---------------------------*/
// https://docs.qmk.fm/#/feature_rgb_matrix

typedef struct Point {
  uint8_t x;
  uint8_t y;
} __attribute__((packed)) Point;

typedef struct rgb_led {
  union {
    uint8_t raw;
    struct {
      uint8_t row:4; // 16 max
      uint8_t col:4; // 16 max
    };
  } matrix_co;
  Point point;
  uint8_t modifier:1;
} __attribute__((packed)) rgb_led;

extern const rgb_led g_rgb_leds[DRIVER_LED_TOTAL];

typedef struct {
    /* Perform any initialisation required for the other driver functions to work. */
    void (*init)(void);
    /* Set the colour of a single LED in the buffer. */
    void (*set_color)(int index, uint8_t r, uint8_t g, uint8_t b);
    /* Flush any buffered changes to the hardware. */
    void (*flush)(void);
} rgb_matrix_driver_t;

extern const rgb_matrix_driver_t rgb_matrix_driver;

// This runs after another backlight effect and replaces
// colors already set
void rgb_matrix_indicators_kb(uint16_t led_i);
void rgb_matrix_indicators_user(uint16_t led_i);

// Custom Mode support
typedef void (*rgb_matrix_effect_f)(uint16_t led_i, bool init);
extern const rgb_matrix_effect_f rgb_matrix_effects_kb[];
extern const rgb_matrix_effect_f rgb_matrix_effects_user[];
extern const uint8_t rgb_matrix_effects_kb_count;
extern const uint8_t rgb_matrix_effects_user_count;

