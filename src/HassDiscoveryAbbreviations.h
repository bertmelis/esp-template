/*
Copyright (c) 2023 Bert Melis. All rights reserved.

This work is licensed under the terms of the MIT license.  
For a copy, see <https://opensource.org/licenses/MIT> or
the LICENSE file.
*/

#define DISCOVERY_BASETOPIC "~"
#define DISCOVERY_ACTION_TOPIC "act_t"
#define DISCOVERY_ACTION_TEMPLATE "act_tpl"
#define DISCOVERY_AUTOMATION_TYPE "atype"
#define DISCOVERY_AUX_COMMAND_TOPIC "aux_cmd_t"
#define DISCOVERY_AUX_STATE_TEMPLATE "aux_stat_tpl"
#define DISCOVERY_AUX_STATE_TOPIC "aux_stat_t"
#define DISCOVERY_AVAILABLE_TONES "av_tones"
#define DISCOVERY_AVAILABILITY "avty"
#define DISCOVERY_AVAILABILITY_MODE "avty_mode"
#define DISCOVERY_AVAILABILITY_TOPIC "avty_t"
#define DISCOVERY_AVAILABILITY_TEMPLATE "avty_tpl"
#define DISCOVERY_AWAY_MODE_COMMAND_TOPIC "away_mode_cmd_t"
#define DISCOVERY_AWAY_MODE_STATE_TEMPLATE "away_mode_stat_tpl"
#define DISCOVERY_AWAY_MODE_STATE_TOPIC "away_mode_stat_t"
#define DISCOVERY_BLUE_TEMPLATE "b_tpl"
#define DISCOVERY_BRIGHTNESS_COMMAND_TOPIC "bri_cmd_t"
#define DISCOVERY_BRIGHTNESS_COMMAND_TEMPLATE "bri_cmd_tpl"
#define DISCOVERY_BRIGHTNESS_SCALE "bri_scl"
#define DISCOVERY_BRIGHTNESS_STATE_TOPIC "bri_stat_t"
#define DISCOVERY_BRIGHTNESS_TEMPLATE "bri_tpl"
#define DISCOVERY_BRIGHTNESS_VALUE_TEMPLATE "bri_val_tpl"
#define DISCOVERY_COLOR_TEMP_COMMAND_TEMPLATE "clr_temp_cmd_tpl"
#define DISCOVERY_BATTERY_LEVEL_TOPIC "bat_lev_t"
#define DISCOVERY_BATTERY_LEVEL_TEMPLATE "bat_lev_tpl"
#define DISCOVERY_CHARGING_TOPIC "chrg_t"
#define DISCOVERY_CHARGING_TEMPLATE "chrg_tpl"
#define DISCOVERY_COLOR_TEMP_COMMAND_TOPIC "clr_temp_cmd_t"
#define DISCOVERY_COLOR_TEMP_STATE_TOPIC "clr_temp_stat_t"
#define DISCOVERY_COLOR_TEMP_TEMPLATE "clr_temp_tpl"
#define DISCOVERY_COLOR_TEMP_VALUE_TEMPLATE "clr_temp_val_tpl"
#define DISCOVERY_COLOR_MODE "clrm"
#define DISCOVERY_COLOR_MODE_STATE_TOPIC "clrm_stat_t"
#define DISCOVERY_COLOR_MODE_VALUE_TEMPLATE "clrm_val_tpl"
#define DISCOVERY_CLEANING_TOPIC "cln_t"
#define DISCOVERY_CLEANING_TEMPLATE "cln_tpl"
#define DISCOVERY_COMMAND_OFF_TEMPLATE "cmd_off_tpl"
#define DISCOVERY_COMMAND_ON_TEMPLATE "cmd_on_tpl"
#define DISCOVERY_COMMAND_TOPIC "cmd_t"
#define DISCOVERY_COMMAND_TEMPLATE "cmd_tpl"
#define DISCOVERY_CODE_ARM_REQUIRED "cod_arm_req"
#define DISCOVERY_CODE_DISARM_REQUIRED "cod_dis_req"
#define DISCOVERY_CODE_TRIGGER_REQUIRED "cod_trig_req"
#define DISCOVERY_CURRENT_TEMPERATURE_TOPIC "curr_temp_t"
#define DISCOVERY_CURRENT_TEMPERATURE_TEMPLATE "curr_temp_tpl"
#define DISCOVERY_DEVICE "dev"
#define DISCOVERY_DEVICE_CLASS "dev_cla"
#define DISCOVERY_DOCKED_TOPIC "dock_t"
#define DISCOVERY_DOCKED_TEMPLATE "dock_tpl"
#define DISCOVERY_ENCODING "e"
#define DISCOVERY_ENABLED_BY_DEFAULT "en"
#define DISCOVERY_ENTITY_CATEGORY "ent_cat"
#define DISCOVERY_ENTITY_PICTURE "ent_pic"
#define DISCOVERY_ERROR_TOPIC "err_t"
#define DISCOVERY_ERROR_TEMPLATE "err_tpl"
#define DISCOVERY_FAN_SPEED_TOPIC "fanspd_t"
#define DISCOVERY_FAN_SPEED_TEMPLATE "fanspd_tpl"
#define DISCOVERY_FAN_SPEED_LIST "fanspd_lst"
#define DISCOVERY_FLASH_TIME_LONG "flsh_tlng"
#define DISCOVERY_FLASH_TIME_SHORT "flsh_tsht"
#define DISCOVERY_EFFECT_COMMAND_TOPIC "fx_cmd_t"
#define DISCOVERY_EFFECT_COMMAND_TEMPLATE "fx_cmd_tpl"
#define DISCOVERY_EFFECT_LIST "fx_list"
#define DISCOVERY_EFFECT_STATE_TOPIC "fx_stat_t"
#define DISCOVERY_EFFECT_TEMPLATE "fx_tpl"
#define DISCOVERY_EFFECT_VALUE_TEMPLATE "fx_val_tpl"
#define DISCOVERY_EXPIRE_AFTER "exp_aft"
#define DISCOVERY_FAN_MODE_COMMAND_TEMPLATE "fan_mode_cmd_tpl"
#define DISCOVERY_FAN_MODE_COMMAND_TOPIC "fan_mode_cmd_t"
#define DISCOVERY_FAN_MODE_STATE_TEMPLATE "fan_mode_stat_tpl"
#define DISCOVERY_FAN_MODE_STATE_TOPIC "fan_mode_stat_t"
#define DISCOVERY_FORCE_UPDATE "frc_upd"
#define DISCOVERY_GREEN_TEMPLATE "g_tpl"
#define DISCOVERY_HOLD_COMMAND_TEMPLATE "hold_cmd_tpl"
#define DISCOVERY_HOLD_COMMAND_TOPIC "hold_cmd_t"
#define DISCOVERY_HOLD_STATE_TEMPLATE "hold_stat_tpl"
#define DISCOVERY_HOLD_STATE_TOPIC "hold_stat_t"
#define DISCOVERY_HS_COMMAND_TOPIC "hs_cmd_t"
#define DISCOVERY_HS_COMMAND_TEMPLATE "hs_cmd_tpl"
#define DISCOVERY_HS_STATE_TOPIC "hs_stat_t"
#define DISCOVERY_HS_VALUE_TEMPLATE "hs_val_tpl"
#define DISCOVERY_ICON "ic"
#define DISCOVERY_IMAGE_ENCODING "img_e"
#define DISCOVERY_INITIAL "init"
#define DISCOVERY_TARGET_HUMIDITY_COMMAND_TOPIC "hum_cmd_t"
#define DISCOVERY_TARGET_HUMIDITY_COMMAND_TEMPLATE "hum_cmd_tpl"
#define DISCOVERY_TARGET_HUMIDITY_STATE_TOPIC "hum_stat_t"
#define DISCOVERY_TARGET_HUMIDITY_STATE_TEMPLATE "hum_state_tpl"
#define DISCOVERY_JSON_ATTRIBUTES "json_attr"
#define DISCOVERY_JSON_ATTRIBUTES_TOPIC "json_attr_t"
#define DISCOVERY_JSON_ATTRIBUTES_TEMPLATE "json_attr_tpl"
#define DISCOVERY_LATEST_VERSION_TOPIC "l_ver_t"
#define DISCOVERY_LATEST_VERSION_TEMPLATE "l_ver_tpl"
#define DISCOVERY_LAST_RESET_TOPIC "lrst_t"
#define DISCOVERY_LAST_RESET_VALUE_TEMPLATE "lrst_val_tpl"
#define DISCOVERY_MAX "max"
#define DISCOVERY_MIN "min"
#define DISCOVERY_MAX_MIREDS "max_mirs"
#define DISCOVERY_MIN_MIREDS "min_mirs"
#define DISCOVERY_MAX_TEMP "max_temp"
#define DISCOVERY_MIN_TEMP "min_temp"
#define DISCOVERY_MAX_HUMIDITY "max_hum"
#define DISCOVERY_MIN_HUMIDITY "min_hum"
#define DISCOVERY_MODE "mode"
#define DISCOVERY_MODE_COMMAND_TEMPLATE "mode_cmd_tpl"
#define DISCOVERY_MODE_COMMAND_TOPIC "mode_cmd_t"
#define DISCOVERY_MODE_STATE_TEMPLATE "mode_stat_tpl"
#define DISCOVERY_MODE_STATE_TOPIC "mode_stat_t"
#define DISCOVERY_MODES "modes"
#define DISCOVERY_NAME "name"
#define DISCOVERY_OBJECT_ID "obj_id"
#define DISCOVERY_OFF_DELAY "off_dly"
#define DISCOVERY_ON_COMMAND_TYPE "on_cmd_type"
#define DISCOVERY_OPTIONS "ops"
#define DISCOVERY_OPTIMISTIC "opt"
#define DISCOVERY_OSCILLATION_COMMAND_TOPIC "osc_cmd_t"
#define DISCOVERY_OSCILLATION_COMMAND_TEMPLATE "osc_cmd_tpl"
#define DISCOVERY_OSCILLATION_STATE_TOPIC "osc_stat_t"
#define DISCOVERY_OSCILLATION_VALUE_TEMPLATE "osc_val_tpl"
#define DISCOVERY_PERCENTAGE_COMMAND_TOPIC "pct_cmd_t"
#define DISCOVERY_PERCENTAGE_COMMAND_TEMPLATE "pct_cmd_tpl"
#define DISCOVERY_PERCENTAGE_STATE_TOPIC "pct_stat_t"
#define DISCOVERY_PERCENTAGE_VALUE_TEMPLATE "pct_val_tpl"
#define DISCOVERY_PATTERN "ptrn"
#define DISCOVERY_PAYLOAD "pl"
#define DISCOVERY_PAYLOAD_ARM_AWAY "pl_arm_away"
#define DISCOVERY_PAYLOAD_ARM_HOME "pl_arm_home"
#define DISCOVERY_PAYLOAD_ARM_CUSTOM_BYPASS "pl_arm_custom_b"
#define DISCOVERY_PAYLOAD_ARM_NIGHT "pl_arm_nite"
#define DISCOVERY_PAYLOAD_ARM_VACATION "pl_arm_vacation"
#define DISCOVERY_PAYLOAD_PRESS "pl_prs"
#define DISCOVERY_PAYLOAD_RESET "pl_rst"
#define DISCOVERY_PAYLOAD_AVAILABLE "pl_avail"
#define DISCOVERY_PAYLOAD_CLEAN_SPOT "pl_cln_sp"
#define DISCOVERY_PAYLOAD_CLOSE "pl_cls"
#define DISCOVERY_PAYLOAD_DISARM "pl_disarm"
#define DISCOVERY_PAYLOAD_HOME "pl_home"
#define DISCOVERY_PAYLOAD_INSTALL "pl_inst"
#define DISCOVERY_PAYLOAD_LOCK "pl_lock"
#define DISCOVERY_PAYLOAD_LOCATE "pl_loc"
#define DISCOVERY_PAYLOAD_NOT_AVAILABLE "pl_not_avail"
#define DISCOVERY_PAYLOAD_NOT_HOME "pl_not_home"
#define DISCOVERY_PAYLOAD_OFF "pl_off"
#define DISCOVERY_PAYLOAD_ON "pl_on"
#define DISCOVERY_PAYLOAD_OPEN "pl_open"
#define DISCOVERY_PAYLOAD_OSCILLATION_OFF "pl_osc_off"
#define DISCOVERY_PAYLOAD_OSCILLATION_ON "pl_osc_on"
#define DISCOVERY_PAYLOAD_PAUSE "pl_paus"
#define DISCOVERY_PAYLOAD_STOP "pl_stop"
#define DISCOVERY_PAYLOAD_START "pl_strt"
#define DISCOVERY_PAYLOAD_START_PAUSE "pl_stpa"
#define DISCOVERY_PAYLOAD_RETURN_TO_BASE "pl_ret"
#define DISCOVERY_PAYLOAD_RESET_HUMIDITY "pl_rst_hum"
#define DISCOVERY_PAYLOAD_RESET_MODE "pl_rst_mode"
#define DISCOVERY_PAYLOAD_RESET_PERCENTAGE "pl_rst_pct"
#define DISCOVERY_PAYLOAD_RESET_PRESET_MODE "pl_rst_pr_mode"
#define DISCOVERY_PAYLOAD_TURN_OFF "pl_toff"
#define DISCOVERY_PAYLOAD_TURN_ON "pl_ton"
#define DISCOVERY_PAYLOAD_TRIGGER "pl_trig"
#define DISCOVERY_PAYLOAD_UNLOCK "pl_unlk"
#define DISCOVERY_POSITION_CLOSED "pos_clsd"
#define DISCOVERY_POSITION_OPEN "pos_open"
#define DISCOVERY_PRESET_MODE_COMMAND_TOPIC "pr_mode_cmd_t"
#define DISCOVERY_PRESET_MODE_COMMAND_TEMPLATE "pr_mode_cmd_tpl"
#define DISCOVERY_PRESET_MODE_STATE_TOPIC "pr_mode_stat_t"
#define DISCOVERY_PRESET_MODE_VALUE_TEMPLATE "pr_mode_val_tpl"
#define DISCOVERY_PRESET_MODES "pr_modes"
#define DISCOVERY_RED_TEMPLATE "r_tpl"
#define DISCOVERY_RELEASE_SUMMARY "rel_s"
#define DISCOVERY_RELEASE_URL "rel_u"
#define DISCOVERY_RETAIN "ret"
#define DISCOVERY_RGB_COMMAND_TOPIC "rgb_cmd_t"
#define DISCOVERY_RGB_COMMAND_TEMPLATE "rgb_cmd_tpl"
#define DISCOVERY_RGB_STATE_TOPIC "rgb_stat_t"
#define DISCOVERY_RGB_VALUE_TEMPLATE "rgb_val_tpl"
#define DISCOVERY_RGBW_COMMAND_TOPIC "rgbw_cmd_t"
#define DISCOVERY_RGBW_COMMAND_TEMPLATE "rgbw_cmd_tpl"
#define DISCOVERY_RGBW_STATE_TOPIC "rgbw_stat_t"
#define DISCOVERY_RGBW_VALUE_TEMPLATE "rgbw_val_tpl"
#define DISCOVERY_RGBWW_COMMAND_TOPIC "rgbww_cmd_t"
#define DISCOVERY_RGBWW_COMMAND_TEMPLATE "rgbww_cmd_tpl"
#define DISCOVERY_RGBWW_STATE_TOPIC "rgbww_stat_t"
#define DISCOVERY_RGBWW_VALUE_TEMPLATE "rgbww_val_tpl"
#define DISCOVERY_SEND_COMMAND_TOPIC "send_cmd_t"
#define DISCOVERY_SEND_IF_OFF "send_if_off"
#define DISCOVERY_SET_FAN_SPEED_TOPIC "set_fan_spd_t"
#define DISCOVERY_SET_POSITION_TEMPLATE "set_pos_tpl"
#define DISCOVERY_SET_POSITION_TOPIC "set_pos_t"
#define DISCOVERY_POSITION_TOPIC "pos_t"
#define DISCOVERY_POSITION_TEMPLATE "pos_tpl"
#define DISCOVERY_SPEED_RANGE_MIN "spd_rng_min"
#define DISCOVERY_SPEED_RANGE_MAX "spd_rng_max"
#define DISCOVERY_SOURCE_TYPE "src_type"
#define DISCOVERY_STATE_CLASS "stat_cla"
#define DISCOVERY_STATE_CLOSED "stat_clsd"
#define DISCOVERY_STATE_CLOSING "stat_closing"
#define DISCOVERY_STATE_JAMMED "stat_jam"
#define DISCOVERY_STATE_OFF "stat_off"
#define DISCOVERY_STATE_ON "stat_on"
#define DISCOVERY_STATE_OPEN "stat_open"
#define DISCOVERY_STATE_OPENING "stat_opening"
#define DISCOVERY_STATE_STOPPED "stat_stopped"
#define DISCOVERY_STATE_LOCKED "stat_locked"
#define DISCOVERY_STATE_LOCKING "stat_locking"
#define DISCOVERY_STATE_UNLOCKED "stat_unlocked"
#define DISCOVERY_STATE_UNLOCKING "stat_unlocking"
#define DISCOVERY_STATE_TOPIC "stat_t"
#define DISCOVERY_STATE_TEMPLATE "stat_tpl"
#define DISCOVERY_STATE_VALUE_TEMPLATE "stat_val_tpl"
#define DISCOVERY_STEP "step"
#define DISCOVERY_SUBTYPE "stype"
#define DISCOVERY_SUGGESTED_DISPLAY_PRECISION "sug_dsp_prc"
#define DISCOVERY_SUPPORTED_COLOR_MODES "sup_clrm"
#define DISCOVERY_SUPPORT_DURATION "sup_dur"
#define DISCOVERY_SUPPORT_VOLUME_SET "sup_vol"
#define DISCOVERY_SUPPORTED_FEATURES "sup_feat"
#define DISCOVERY_SWING_MODE_COMMAND_TEMPLATE "swing_mode_cmd_tpl"
#define DISCOVERY_SWING_MODE_COMMAND_TOPIC "swing_mode_cmd_t"
#define DISCOVERY_SWING_MODE_STATE_TEMPLATE "swing_mode_stat_tpl"
#define DISCOVERY_SWING_MODE_STATE_TOPIC "swing_mode_stat_t"
#define DISCOVERY_TEMPERATURE_COMMAND_TEMPLATE "temp_cmd_tpl"
#define DISCOVERY_TEMPERATURE_COMMAND_TOPIC "temp_cmd_t"
#define DISCOVERY_TEMPERATURE_HIGH_COMMAND_TEMPLATE "temp_hi_cmd_tpl"
#define DISCOVERY_TEMPERATURE_HIGH_COMMAND_TOPIC "temp_hi_cmd_t"
#define DISCOVERY_TEMPERATURE_HIGH_STATE_TEMPLATE "temp_hi_stat_tpl"
#define DISCOVERY_TEMPERATURE_HIGH_STATE_TOPIC "temp_hi_stat_t"
#define DISCOVERY_TEMPERATURE_LOW_COMMAND_TEMPLATE "temp_lo_cmd_tpl"
#define DISCOVERY_TEMPERATURE_LOW_COMMAND_TOPIC "temp_lo_cmd_t"
#define DISCOVERY_TEMPERATURE_LOW_STATE_TEMPLATE "temp_lo_stat_tpl"
#define DISCOVERY_TEMPERATURE_LOW_STATE_TOPIC "temp_lo_stat_t"
#define DISCOVERY_TEMPERATURE_STATE_TEMPLATE "temp_stat_tpl"
#define DISCOVERY_TEMPERATURE_STATE_TOPIC "temp_stat_t"
#define DISCOVERY_TEMPERATURE_UNIT "temp_unit"
#define DISCOVERY_TILT_CLOSED_VALUE "tilt_clsd_val"
#define DISCOVERY_TILT_COMMAND_TOPIC "tilt_cmd_t"
#define DISCOVERY_TILT_COMMAND_TEMPLATE "tilt_cmd_tpl"
#define DISCOVERY_TILT_INVERT_STATE "tilt_inv_stat"
#define DISCOVERY_TILT_MAX "tilt_max"
#define DISCOVERY_TILT_MIN "tilt_min"
#define DISCOVERY_TILT_OPENED_VALUE "tilt_opnd_val"
#define DISCOVERY_TILT_OPTIMISTIC "tilt_opt"
#define DISCOVERY_TILT_STATUS_TOPIC "tilt_status_t"
#define DISCOVERY_TILT_STATUS_TEMPLATE "tilt_status_tpl"
#define DISCOVERY_TITLE "tit"
#define DISCOVERY_TOPIC "t"
#define DISCOVERY_UNIQUE_ID "uniq_id"
#define DISCOVERY_UNIT_OF_MEASUREMENT "unit_of_meas"
#define DISCOVERY_VALUE_TEMPLATE "val_tpl"
#define DISCOVERY_WHITE_COMMAND_TOPIC "whit_cmd_t"
#define DISCOVERY_WHITE_SCALE "whit_scl"
#define DISCOVERY_WHITE_VALUE_COMMAND_TOPIC "whit_val_cmd_t"
#define DISCOVERY_WHITE_VALUE_SCALE "whit_val_scl"
#define DISCOVERY_WHITE_VALUE_STATE_TOPIC "whit_val_stat_t"
#define DISCOVERY_WHITE_VALUE_TEMPLATE "whit_val_tpl"
#define DISCOVERY_XY_COMMAND_TOPIC "xy_cmd_t"
#define DISCOVERY_XY_COMMAND_TEMPLATE "xy_cmd_tpl"
#define DISCOVERY_XY_STATE_TOPIC "xy_stat_t"
#define DISCOVERY_XY_VALUE_TEMPLATE "xy_val_tpl"

#define DISCOVERY_DEVICE_CONFIGURATION_URL "cu"
#define DISCOVERY_DEVICE_CONNECTIONS "cns"
#define DISCOVERY_DEVICE_IDENTIFIERS "ids"
#define DISCOVERY_DEVICE_NAME "name"
#define DISCOVERY_DEVICE_MANUFACTURER "mf"
#define DISCOVERY_DEVICE_MODEL "mdl"
#define DISCOVERY_DEVICE_HW_VERSION "hw"
#define DISCOVERY_DEVICE_SW_VERSION "sw"
#define DISCOVERY_DEVICE_SUGGESTED_AREA "sa"