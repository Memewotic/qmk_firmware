#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "process_unicode.h"

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,

  WIDETXT, // w i d e t e x t   f o r   a   w i d e   b o y
  TAUNTXT, // FoR ThE UlTiMaTe sHiTpOsTiNg eXpErIeNcE

  UC_HELP, // URL for QMK unicode help
  UC_SHRG,                // shrug       - ¯\_(ツ)_/¯
#define UC_100  X(E_100)  // hundo       - 💯
#define UC_BBB  X(E_BBB)  // dat B       - 🅱️
#define UC_CLAP X(E_CLAP) // clap        - 👏
#define UC_EYES X(E_EYES) // shifty eyes - 👀
#define UC_GRIM X(E_GRIM) // grimmace    - 😬
#define UC_THNK X(E_THNK) // thinking    - 🤔
#define UC_UGHH X(E_UGHH) // UGHHHHH     - 😩
};

enum unicode_names {
  E_100,
  E_BBB,
  E_CLAP,
  E_EYES,
  E_GRIM,
  E_THNK,
  E_UGHH,
};
const uint32_t PROGMEM unicode_map[] = {
  [E_BBB]  = 0x1F171,
  [E_100]  = 0x1F4AF,
  [E_EYES] = 0x1F440,
  [E_CLAP] = 0x1f44f,
  [E_GRIM] = 0x1f62c,
  [E_THNK] = 0x1f914,
  [E_UGHH] = 0x1f629,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MEMES,
};

#define ___X___ XXXXXXX // KC_NO
#define LED_LVL LED_LEVEL


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MEMES MO(_MEMES)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_mit(
    KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
    KC_LCTL,  KC_LGUI, KC_LALT, MEMES,   LOWER,        KC_SPC,      RAISE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),

  [_LOWER] = LAYOUT_planck_mit(
    KC_TILD,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,  \
    KC_CAPS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   ___X___, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, \
    _______,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___X___, KC_VOLD, KC_VOLU, KC_PIPE, ___X___, \
    _______,  _______, _______, ___X___, _______,      _______,     _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
  ),

  [_RAISE] = LAYOUT_planck_mit(
    KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
    KC_CAPS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   ___X___, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, \
    _______,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MPLY, KC_MPRV, KC_MNXT, KC_BSLS, ___X___, \
    _______,  _______, _______, ___X___, _______,      _______,     _______, ___X___, ___X___, ___X___, ___X___  \
  ),

  [_ADJUST] = LAYOUT_planck_mit(
    ___X___, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, \
    ___X___, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, ___X___, ___X___, ___X___, ___X___, ___X___, RESET,   \
    ___X___, RGB_TOG, LED_LVL, MU_TOG,  MU_MOD,  AU_TOG,  ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, \
    ___X___, ___X___, ___X___, ___X___, ___X___,      ___X___,     ___X___, ___X___, ___X___, ___X___, ___X___  \
  ),

  [_MEMES] = LAYOUT_planck_mit(
    ___X___, UC_100,  ___X___, UC_EYES, ___X___, UC_THNK, ___X___, UC_UGHH, ___X___, ___X___, ___X___, ___X___, \
    TAUNTXT, ___X___, UC_SHRG, ___X___, ___X___, UC_GRIM, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, \
    ___X___, ___X___, ___X___, UC_CLAP, ___X___, UC_BBB,  ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, \
    UC_M_OS, UC_M_WC, UC_M_LN, ___X___, ___X___,      WIDETXT,     ___X___, ___X___, ___X___, ___X___, ___X___  \
  ),

  /*
  [X] = LAYOUT_planck_mit(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______  \
  ),
  */
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  static struct {
    bool on;
    bool first;
  } w_i_d_e_t_e_x_t = {false, false};

  if (w_i_d_e_t_e_x_t.on) {
    if (record->event.pressed) {
      switch (keycode) {
        case KC_A ... KC_0:
        case KC_SPC:
          if (w_i_d_e_t_e_x_t.first) {
            w_i_d_e_t_e_x_t.first = false;
          } else {
            send_char(' ');
          }
          break;
        case KC_ENT:
          w_i_d_e_t_e_x_t.first = true;
          break;
        case KC_BSPC:
          send_char('\b');  // backspace
          break;
      }
    }
  }

  static bool tAuNtTeXt = false;

  if (tAuNtTeXt) {
    if (record->event.pressed) {
      if (keycode != KC_SPC)
        tap_code(KC_CAPS);
    }
  }

  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    /* z e s t y   m e m e s */
    case WIDETXT:
      if (record->event.pressed) {
        w_i_d_e_t_e_x_t.on = !w_i_d_e_t_e_x_t.on;
        w_i_d_e_t_e_x_t.first = true;
      }
      return false;
    case TAUNTXT:
      if (record->event.pressed) {
        tAuNtTeXt = !tAuNtTeXt;
      }
      return false;
    /* Unicode */
    case UC_SHRG:  // ¯\_(ツ)_/¯
      if (record->event.pressed) {
        send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
      }
      return false;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo += 1;
      } else {
        muse_tempo -= 1;
      }
    }
  } else {
    if (clockwise) {
#ifdef MOUSEKEY_ENABLE
      register_code(KC_MS_WH_DOWN);
      unregister_code(KC_MS_WH_DOWN);
#else
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
#endif
    } else {
#ifdef MOUSEKEY_ENABLE
      register_code(KC_MS_WH_UP);
      unregister_code(KC_MS_WH_UP);
#else
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
#endif
    }
  }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
  if (muse_mode) {
    if (muse_counter == 0) {
      uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
      if (muse_note != last_muse_note) {
        stop_note(compute_freq_for_midi_note(last_muse_note));
        play_note(compute_freq_for_midi_note(muse_note), 0xF);
        last_muse_note = muse_note;
      }
    }
    muse_counter = (muse_counter + 1) % muse_tempo;
  }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
