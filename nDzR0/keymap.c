#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};



#define DUAL_FUNC_0 LT(10, KC_1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_WWW_FAVORITES,                                KC_MEDIA_PLAY_PAUSE,KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_LEFT,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_RIGHT,                                       KC_AUDIO_VOL_UP,KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    KC_BSPC,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_DELETE,                                                                      KC_AUDIO_VOL_DOWN,KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    KC_MY_COMPUTER, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
    KC_CALCULATOR,  CW_TOGG,        KC_DOWN,        KC_UP,          KC_TAB,         MT(MOD_LCTL, KC_APPLICATION),                                                                                                DUAL_FUNC_0,    KC_TRANSPARENT, KC_LBRC,        KC_RBRC,        KC_EQUAL,       KC_TRANSPARENT, 
    KC_SPACE,       MT(MOD_LSFT, KC_ENTER),KC_RIGHT_ALT,                   KC_LEFT_ALT,    KC_CAPS,        OSM(MOD_LSFT)
  ),
  [1] = LAYOUT_moonlander(
    TO(0),          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_ASTERISK, KC_KP_SLASH,    
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          KC_NO,          KC_BSPC,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_MINUS,    KC_DELETE,      
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_PLUS,     KC_KP_ENTER,    
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          RGB_MODE_FORWARD,                                                                                                KC_NO,          KC_KP_0,        KC_KP_COMMA,    KC_KP_DOT,      KC_KP_EQUAL,    KC_NO,          
    RGB_SPD,        RGB_SPI,        TOGGLE_LAYER_COLOR,                KC_NO,          KC_NO,          KC_NO
  ),
};


const uint16_t PROGMEM combo0[] = { KC_D, KC_S, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_GRAVE, KC_1, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_3, KC_4, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_6, KC_MEDIA_PLAY_PAUSE, COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_6, KC_7, COMBO_END};
const uint16_t PROGMEM combo8[] = { KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM combo9[] = { KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM combo10[] = { KC_9, KC_0, COMBO_END};
const uint16_t PROGMEM combo11[] = { KC_0, KC_MINUS, COMBO_END};
const uint16_t PROGMEM combo12[] = { KC_MINUS, KC_BSLS, COMBO_END};
const uint16_t PROGMEM combo13[] = { KC_D, KC_F, KC_SPACE, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_ESCAPE),
    COMBO(combo1, KC_F1),
    COMBO(combo2, KC_F2),
    COMBO(combo3, KC_F3),
    COMBO(combo4, KC_F4),
    COMBO(combo5, KC_F5),
    COMBO(combo6, KC_F6),
    COMBO(combo7, KC_F7),
    COMBO(combo8, KC_F8),
    COMBO(combo9, KC_F9),
    COMBO(combo10, KC_F10),
    COMBO(combo11, KC_F11),
    COMBO(combo12, KC_F12),
    COMBO(combo13, TT(1)),
};


bool capslock_active = false;

bool led_update_user(led_t led_state) {
  capslock_active = led_state.caps_lock;
  return true;
}

extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [1] = { {145,218,166}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {65,255,255}, {65,255,255}, {65,255,255}, {203,235,78}, {203,235,78}, {65,255,255}, {65,255,255}, {65,255,255}, {203,235,78}, {203,235,78}, {65,255,255}, {65,255,255}, {65,255,255}, {65,255,255}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78}, {203,235,78} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 1:
        set_layer_color(1);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  if (capslock_active && biton32(layer_state) == 0) {
    RGB rgb = hsv_to_rgb_with_value((HSV) { 0, 0, 255 });
    rgb_matrix_set_color( 69, rgb.r, rgb.g, rgb.b );
  } 
  return true;
}





bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_GUI);
        } else {
          unregister_code16(KC_RIGHT_GUI);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_CTRL);
        } else {
          unregister_code16(KC_RIGHT_CTRL);
        }  
      }  
      return false;
    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}

