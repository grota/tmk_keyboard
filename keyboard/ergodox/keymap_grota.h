/*
 * NOTES:
 * ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT)
 * Works as a modifier key while holding, but registers a key on tap(press and release quickly)
 *
 * ACTION_LAYER_MOMENTARY(layernumber)
 * it activates when key is pressed and deactivate when released
 * From the docs it seems like the destination layer button must be the same or transparent.
 *
 * ACTION_LAYER_TOGGLE(layer)
 * Turns on layer with first type(press and release) and turns off with next.
 *
 * ACTION_LAYER_TAP_KEY(layer, key)
 * Turns on layer momentary while holding, but registers key on tap(press and release quickly).
 *
 * ACTION_LAYER_SET(layer, on)
 * Turn on layer only. layer_state = (1<<layer) [layer: 0-31]
 *
 * MACRO()
 *
 * ACTION_FUNCTION(id)
 * ACTION_FUNCTION_TAP(id)
 * Both should be handled in the callback action_function, with the second define you
 * have the possibility to define a dual role key (i.e. discriminate between tap and hold).
 *
 */
static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0:
     * ,-----------------------------------------------.           ,-----------------------------------------------------.
     * |   Esc   |  1  |  2  |  3  |  4   |  5  |   6  |           |   7  |   8   | Left  | Down  |  Up | Right |   \|   |
     * |---------+-----+-----+-----+------+------------|           |------+-------+-------+-------+-----+-------+--------|
     * |   Tab   |  Q  |  F  |  W  |  R   |  Y  | Home |           | End  |  `~   |   H   |   J   |  K  |   L   |  PgUp  |
     * |---------+-----+-----+-----+------+-----|      |           |      |-------+-------+-------+-----+-------+--------|
     * |    -_   |  A  |  S  |  D  |  G   |  X  |------|           |------|  ,<   |   C   |   E   |  I  |   O   |  PgDwn |
     * |---------+-----+-----+-----+------+-----|  [{  |           |  ]}  |-------+-------+-------+-----+-------+--------|
     * | LShift  |  Z  |  T  |  M  |  B   |  V  |      |           |      |  /?   |   N   |   P   | .>  |   U   |=+/RShft|
     * `---------+-----+-----+-----+------+------------'           `--------------+-------+-------+-----+-------+--------'
     *  | LCtrl  |RAlt | LAlt| ~L1 |Bksp/Del|                                     | Space |;:/LAlt| '"  |   9   |   0   |
     *  `-----------------------------------'                                     `-------------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |  F2  | LGui |       |  L1  |  F1  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | C-x  |       |  F3  |      |      |
     *                                 | C-c  |S-Ins |------|       |------| Del  |Enter |
     *                                 |      |      | C-v  |       | KP0  |      |RCtrl |
     *                                 `--------------------'       `--------------------'
     *
     * Layer 1:
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |      |  F11 |   F12  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      |      |  Up  |      |      |      |           |      |      |      |  M_U |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      | Left | Down | Right|      |------|           |------|      |  M_L |  M_D |  M_R | BTN1 |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |      | BTN2 | BTN2 | KP_8 |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       | WH_D | WH_U | KP_4 | KP_2 | KP_6 |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |Teensy|       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |  L0  |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       | Prev | Next | Play |
     *                                 `--------------------'       `--------------------'
     */

    KEYMAP(  // Layer0, Left hand.
        ESC,    1,     2,     3,      4,   5,     6,
        TAB,    Q,     F,     W,      R,   Y,  HOME,
       MINS,    A,     S,     D,      G,   X,
     LSHIFT,    Z,     T,     M,      B,   V,  LBRC,
      LCTRL, RALT,  LALT,   FN2,    FN7,

                                         F2, LGUI,
                                             FN11,
                                  FN8, FN10, FN4,

            // Right hand.
               7,      8, LEFT,   DOWN,   UP,   RGHT,  BSLS,
             END,    GRV,    H,      J,    K,     L,   PGUP,
                   COMMA,    C,      E,    I,     O,   PGDN,
            RBRC,   SLSH,    N,      P,  DOT,     U,    FN5,
                           SPC,    FN3,QUOTE,     9,      0,

        FN12,     F1,
          F3,
          P0, DEL, FN6
    ),

    KEYMAP(  // Layer1, left hand
        TRNS,  F1,  F2,  F3,  F4,  F5,  F6,
        TRNS,TRNS,TRNS,  UP,TRNS,TRNS,TRNS,
        TRNS,TRNS,LEFT,DOWN,RGHT,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,  FN1,
                                            TRNS,
                                TRNS, TRNS, TRNS,
        // right hand
               F7,   F8,   F9,  F10, TRNS, F11,    F12,
             TRNS, TRNS, TRNS, MS_U, TRNS, TRNS,  TRNS,
                   TRNS, MS_L, MS_D, MS_R, BTN1,  TRNS,
             TRNS, TRNS, TRNS, BTN2, BTN2,   P8,  TRNS,
                         WH_D, WH_U,   P4,   P2,    P6,
        TRNS,TRNS,
        FN0,
        MEDIA_PREV_TRACK,MEDIA_NEXT_TRACK,MEDIA_PLAY_PAUSE
    ),
};

/* id for user defined functions & macros */
enum function_id {
    TEENSY_KEY,
    CTRLC_AND_LALT,
    BACKSPACE_AND_DEL_WITH_SHIFT,
};

enum macro_id {
  CTRLX,
  CTRLC,
  CTRLV,
  SHIFTINS,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    [2] =  ACTION_LAYER_MOMENTARY(1),
    [3] =  ACTION_MODS_TAP_KEY(MOD_LALT, KC_SCOLON),
    [4] =  ACTION_MACRO(CTRLV),
    [5] =  ACTION_MODS_TAP_KEY(MOD_RSFT, KC_EQUAL),
    [6] =  ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT),
    [7] =  ACTION_FUNCTION(BACKSPACE_AND_DEL_WITH_SHIFT),
    [8] =  ACTION_MACRO(CTRLC),
    //[9] =  ACTION_LAYER_TAP_KEY(1, KC_N),
    [10] = ACTION_MACRO(SHIFTINS),
    [11] = ACTION_MACRO(CTRLX),
    [12] = ACTION_LAYER_SET(1, ON_PRESS),
    //[13] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_QUOTE),     // FN13
};

static const uint16_t PROGMEM fn_actions_1[] = {
    [0] = ACTION_LAYER_SET(0, ON_BOTH),                   // FN0  - Set Layer0
    [1] = ACTION_FUNCTION(TEENSY_KEY),                    // FN1  - Teensy key
    [3] = ACTION_NO,
    //[4] = ACTION_LAYER_SET(2, ON_PRESS),                  // FN3 -  Set L2
};

static const uint16_t PROGMEM fn_actions_2[] = {
    [0] = ACTION_LAYER_SET(0, ON_BOTH),                   // FN0  - Set Layer0
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // print("action_function called\n");
    // print("id  = "); phex(id); print("\n");
    // print("opt = "); phex(opt); print("\n");

    static uint8_t either_ctrl_is_on;
    switch (id) {
      case TEENSY_KEY:
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(50);
        bootloader_jump(); // should not return
        print("not supported.\n");
        break;
      case CTRLC_AND_LALT:
        if (record->event.pressed) {
          if (record->tap.count > 0 && !record->tap.interrupted) {
            //if (record->tap.interrupted) {
              //register_mods(MOD_BIT(KC_LALT));
            //}
          } else {
            register_mods(MOD_BIT(KC_LALT));
          }
        } else {
          if (record->tap.count > 0 && !(record->tap.interrupted)) {
            add_weak_mods(MOD_BIT(KC_LCTL));
            send_keyboard_report();
            register_code(KC_C);
            unregister_code(KC_C);
            del_weak_mods(MOD_BIT(KC_LCTL));
            send_keyboard_report();
            record->tap.count = 0;  // ad hoc: cancel tap
          } else {
            unregister_mods(MOD_BIT(KC_LALT));
          }
        }
        break;
      case BACKSPACE_AND_DEL_WITH_SHIFT:
#define MODS_CTRL_MASK (MOD_BIT(KC_LCTRL)|MOD_BIT(KC_RCTRL))
        either_ctrl_is_on = get_mods()&MODS_CTRL_MASK;
        if (record->event.pressed) {
          if (either_ctrl_is_on) {
            del_mods(either_ctrl_is_on);
            add_key(KC_DELETE);
            send_keyboard_report();
            add_mods(either_ctrl_is_on);
          } else {
            add_key(KC_BSPACE);
            send_keyboard_report();
          }
        } else {
          if (either_ctrl_is_on) {
            del_key(KC_DELETE);
            send_keyboard_report();
          } else {
            del_key(KC_BSPACE);
            send_keyboard_report();
          }
        }
        break;
    }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    case CTRLX:
      if(!record->event.pressed) {
        unregister_mods(MOD_BIT(KC_LCTL));
      }
      return (record->event.pressed ?
          MACRO( I(15), D(LCTL), T(X), U(LCTL), END ) :
          MACRO_NONE);
    case CTRLV:
      if(!record->event.pressed) {
        unregister_mods(MOD_BIT(KC_LCTL));
      }
      return (record->event.pressed ?
          MACRO( I(15), D(LCTL), T(V), U(LCTL), END ) :
          MACRO_NONE);
    case CTRLC:
      if(!record->event.pressed) {
        unregister_mods(MOD_BIT(KC_LCTL));
      }
      return (record->event.pressed ?
          MACRO( I(15), D(LCTL), T(C), U(LCTL), END ) :
          MACRO_NONE);
    case SHIFTINS:
      if(!record->event.pressed) {
        unregister_mods(MOD_BIT(KC_LSHIFT));
      }
      return (record->event.pressed ?
          MACRO( I(15), D(LSHIFT), T(INSERT), U(LSHIFT), END ) :
          MACRO_NONE);
  }
  return MACRO_NONE;
}

#define FN_ACTIONS_SIZE     (sizeof(fn_actions)   / sizeof(fn_actions[0]))
#define FN_ACTIONS_1_SIZE   (sizeof(fn_actions_1) / sizeof(fn_actions_1[0]))
#define FN_ACTIONS_2_SIZE   (sizeof(fn_actions_2) / sizeof(fn_actions_2[0]))

/*
 * translates Fn keycode to action
 * for some layers, use different translation table
 */
action_t keymap_fn_to_action(uint8_t keycode)
{
    uint8_t layer = biton32(layer_state);

    action_t action;
    action.code = ACTION_NO;

    if (layer == 1 && FN_INDEX(keycode) < FN_ACTIONS_1_SIZE) {
        action.code = pgm_read_word(&fn_actions_1[FN_INDEX(keycode)]);
    }
    if (layer == 2 && FN_INDEX(keycode) < FN_ACTIONS_2_SIZE) {
        action.code = pgm_read_word(&fn_actions_2[FN_INDEX(keycode)]);
    }

    // by default, use fn_actions from default layer 0
    // this is needed to get mapping for same key, that was used switch to some layer,
    // to have possibility to switch layers back
    if (action.code == ACTION_NO && FN_INDEX(keycode) < FN_ACTIONS_SIZE) {
        action.code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]);
    }

    return action;
}

/*
    // templates to copy from
    KEYMAP(  // LayerN: fully transparent
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       |      |      |      |      |        |
     *   `----------------------------------'                                       `------------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
 */
