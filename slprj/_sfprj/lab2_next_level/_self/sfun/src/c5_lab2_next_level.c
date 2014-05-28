/* Include files */

#include "blascompat32.h"
#include "lab2_next_level_sfun.h"
#include "c5_lab2_next_level.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lab2_next_level_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c5_debug_family_names[23] = { "AXES", "M", "MX", "MY", "MZ",
  "P", "PX", "PY", "PZ", "az", "el", "nargin", "nargout", "x", "y", "z", "roll",
  "pitch", "yaw", "proll", "ppitch", "pyaw", "C" };

/* Function Declarations */
static void initialize_c5_lab2_next_level(SFc5_lab2_next_levelInstanceStruct
  *chartInstance);
static void initialize_params_c5_lab2_next_level
  (SFc5_lab2_next_levelInstanceStruct *chartInstance);
static void enable_c5_lab2_next_level(SFc5_lab2_next_levelInstanceStruct
  *chartInstance);
static void disable_c5_lab2_next_level(SFc5_lab2_next_levelInstanceStruct
  *chartInstance);
static void c5_update_debugger_state_c5_lab2_next_level
  (SFc5_lab2_next_levelInstanceStruct *chartInstance);
static void ext_mode_exec_c5_lab2_next_level(SFc5_lab2_next_levelInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c5_lab2_next_level
  (SFc5_lab2_next_levelInstanceStruct *chartInstance);
static void set_sim_state_c5_lab2_next_level(SFc5_lab2_next_levelInstanceStruct *
  chartInstance, const mxArray *c5_st);
static void finalize_c5_lab2_next_level(SFc5_lab2_next_levelInstanceStruct
  *chartInstance);
static void sf_c5_lab2_next_level(SFc5_lab2_next_levelInstanceStruct
  *chartInstance);
static void c5_chartstep_c5_lab2_next_level(SFc5_lab2_next_levelInstanceStruct
  *chartInstance);
static void initSimStructsc5_lab2_next_level(SFc5_lab2_next_levelInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static real_T c5_emlrt_marshallIn(SFc5_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_b_emlrt_marshallIn(SFc5_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[6]);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_eml_scalar_eg(SFc5_lab2_next_levelInstanceStruct *chartInstance);
static void c5_c_emlrt_marshallIn(SFc5_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c5_rotationMatrix, const char_T *c5_identifier,
  real_T c5_y[9]);
static void c5_d_emlrt_marshallIn(SFc5_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[9]);
static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_e_emlrt_marshallIn(SFc5_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_f_emlrt_marshallIn(SFc5_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c5_is_active_c5_lab2_next_level, const char_T
  *c5_identifier);
static uint8_T c5_g_emlrt_marshallIn(SFc5_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_lab2_next_levelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_lab2_next_level(SFc5_lab2_next_levelInstanceStruct
  *chartInstance)
{
  int32_T *c5_sfEvent;
  uint8_T *c5_is_active_c5_lab2_next_level;
  c5_is_active_c5_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c5_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c5_is_active_c5_lab2_next_level = 0U;
}

static void initialize_params_c5_lab2_next_level
  (SFc5_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void enable_c5_lab2_next_level(SFc5_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_lab2_next_level(SFc5_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_lab2_next_level
  (SFc5_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c5_lab2_next_level(SFc5_lab2_next_levelInstanceStruct *
  chartInstance)
{
  c5_update_debugger_state_c5_lab2_next_level(chartInstance);
}

static const mxArray *get_sim_state_c5_lab2_next_level
  (SFc5_lab2_next_levelInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  uint8_T c5_hoistedGlobal;
  uint8_T c5_u;
  const mxArray *c5_b_y = NULL;
  uint8_T *c5_is_active_c5_lab2_next_level;
  c5_is_active_c5_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(1), FALSE);
  c5_hoistedGlobal = *c5_is_active_c5_lab2_next_level;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  sf_mex_assign(&c5_st, c5_y, FALSE);
  return c5_st;
}

static void set_sim_state_c5_lab2_next_level(SFc5_lab2_next_levelInstanceStruct *
  chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  boolean_T *c5_doneDoubleBufferReInit;
  uint8_T *c5_is_active_c5_lab2_next_level;
  c5_is_active_c5_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c5_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  *c5_is_active_c5_lab2_next_level = c5_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 0)), "is_active_c5_lab2_next_level");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_lab2_next_level(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_lab2_next_level(SFc5_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

static void sf_c5_lab2_next_level(SFc5_lab2_next_levelInstanceStruct
  *chartInstance)
{
  int32_T *c5_sfEvent;
  real_T *c5_x;
  real_T *c5_y;
  real_T *c5_z;
  real_T *c5_roll;
  real_T *c5_pitch;
  real_T *c5_yaw;
  real_T *c5_proll;
  real_T *c5_ppitch;
  real_T *c5_pyaw;
  real_T *c5_C;
  c5_C = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c5_pyaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c5_ppitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c5_proll = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c5_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c5_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c5_roll = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c5_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c5_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, *c5_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c5_x, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c5_z, 2U);
  _SFD_DATA_RANGE_CHECK(*c5_roll, 3U);
  _SFD_DATA_RANGE_CHECK(*c5_pitch, 4U);
  _SFD_DATA_RANGE_CHECK(*c5_yaw, 5U);
  _SFD_DATA_RANGE_CHECK(*c5_proll, 6U);
  _SFD_DATA_RANGE_CHECK(*c5_ppitch, 7U);
  _SFD_DATA_RANGE_CHECK(*c5_pyaw, 8U);
  _SFD_DATA_RANGE_CHECK(*c5_C, 9U);
  *c5_sfEvent = CALL_EVENT;
  c5_chartstep_c5_lab2_next_level(chartInstance);
  sf_debug_check_for_state_inconsistency(_lab2_next_levelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c5_chartstep_c5_lab2_next_level(SFc5_lab2_next_levelInstanceStruct
  *chartInstance)
{
  real_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  real_T c5_c_hoistedGlobal;
  real_T c5_d_hoistedGlobal;
  real_T c5_e_hoistedGlobal;
  real_T c5_f_hoistedGlobal;
  real_T c5_g_hoistedGlobal;
  real_T c5_h_hoistedGlobal;
  real_T c5_i_hoistedGlobal;
  real_T c5_j_hoistedGlobal;
  real_T c5_x;
  real_T c5_y;
  real_T c5_z;
  real_T c5_roll;
  real_T c5_pitch;
  real_T c5_yaw;
  real_T c5_proll;
  real_T c5_ppitch;
  real_T c5_pyaw;
  real_T c5_C;
  uint32_T c5_debug_family_var_map[23];
  real_T c5_AXES[9];
  real_T c5_M[9];
  real_T c5_MX[6];
  real_T c5_MY[6];
  real_T c5_MZ[6];
  real_T c5_P[9];
  real_T c5_PX[6];
  real_T c5_PY[6];
  real_T c5_PZ[6];
  const mxArray *c5_az = NULL;
  const mxArray *c5_el = NULL;
  real_T c5_nargin = 10.0;
  real_T c5_nargout = 0.0;
  int32_T c5_i0;
  static real_T c5_b[9] = { 100.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 100.0 };

  int32_T c5_i1;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T c5_c_u;
  const mxArray *c5_d_y = NULL;
  real_T c5_dv0[9];
  int32_T c5_i2;
  int32_T c5_i3;
  real_T c5_a[9];
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  real_T c5_b_C[9];
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  real_T c5_d_u;
  const mxArray *c5_e_y = NULL;
  real_T c5_e_u;
  const mxArray *c5_f_y = NULL;
  real_T c5_f_u;
  const mxArray *c5_g_y = NULL;
  real_T c5_dv1[9];
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  const mxArray *c5_b_el = NULL;
  const mxArray *c5_b_az = NULL;
  real_T c5_g_u;
  const mxArray *c5_h_y = NULL;
  real_T c5_h_u;
  const mxArray *c5_i_y = NULL;
  real_T c5_i_u;
  const mxArray *c5_j_y = NULL;
  int32_T c5_i29;
  static char_T c5_cv0[2] = { 'o', 'r' };

  char_T c5_j_u[2];
  const mxArray *c5_k_y = NULL;
  int32_T c5_i30;
  int32_T c5_i31;
  real_T c5_k_u[2];
  const mxArray *c5_l_y = NULL;
  int32_T c5_i32;
  int32_T c5_i33;
  real_T c5_l_u[2];
  const mxArray *c5_m_y = NULL;
  int32_T c5_i34;
  int32_T c5_i35;
  real_T c5_m_u[2];
  const mxArray *c5_n_y = NULL;
  int32_T c5_i36;
  static char_T c5_cv1[2] = { '-', 'r' };

  char_T c5_n_u[2];
  const mxArray *c5_o_y = NULL;
  int32_T c5_i37;
  int32_T c5_i38;
  real_T c5_o_u[2];
  const mxArray *c5_p_y = NULL;
  int32_T c5_i39;
  int32_T c5_i40;
  real_T c5_p_u[2];
  const mxArray *c5_q_y = NULL;
  int32_T c5_i41;
  int32_T c5_i42;
  real_T c5_q_u[2];
  const mxArray *c5_r_y = NULL;
  int32_T c5_i43;
  static char_T c5_cv2[2] = { '-', 'g' };

  char_T c5_r_u[2];
  const mxArray *c5_s_y = NULL;
  int32_T c5_i44;
  int32_T c5_i45;
  real_T c5_s_u[2];
  const mxArray *c5_t_y = NULL;
  int32_T c5_i46;
  int32_T c5_i47;
  real_T c5_t_u[2];
  const mxArray *c5_u_y = NULL;
  int32_T c5_i48;
  int32_T c5_i49;
  real_T c5_u_u[2];
  const mxArray *c5_v_y = NULL;
  int32_T c5_i50;
  static char_T c5_cv3[2] = { '-', 'b' };

  char_T c5_v_u[2];
  const mxArray *c5_w_y = NULL;
  int32_T c5_i51;
  int32_T c5_i52;
  real_T c5_w_u[2];
  const mxArray *c5_x_y = NULL;
  int32_T c5_i53;
  int32_T c5_i54;
  real_T c5_x_u[2];
  const mxArray *c5_y_y = NULL;
  int32_T c5_i55;
  int32_T c5_i56;
  real_T c5_y_u[2];
  const mxArray *c5_ab_y = NULL;
  int32_T c5_i57;
  static char_T c5_cv4[3] = { '-', '-', 'm' };

  char_T c5_ab_u[3];
  const mxArray *c5_bb_y = NULL;
  int32_T c5_i58;
  int32_T c5_i59;
  real_T c5_bb_u[2];
  const mxArray *c5_cb_y = NULL;
  int32_T c5_i60;
  int32_T c5_i61;
  real_T c5_cb_u[2];
  const mxArray *c5_db_y = NULL;
  int32_T c5_i62;
  int32_T c5_i63;
  real_T c5_db_u[2];
  const mxArray *c5_eb_y = NULL;
  int32_T c5_i64;
  static char_T c5_cv5[3] = { '-', '-', 'k' };

  char_T c5_eb_u[3];
  const mxArray *c5_fb_y = NULL;
  int32_T c5_i65;
  int32_T c5_i66;
  real_T c5_fb_u[2];
  const mxArray *c5_gb_y = NULL;
  int32_T c5_i67;
  int32_T c5_i68;
  real_T c5_gb_u[2];
  const mxArray *c5_hb_y = NULL;
  int32_T c5_i69;
  int32_T c5_i70;
  real_T c5_hb_u[2];
  const mxArray *c5_ib_y = NULL;
  int32_T c5_i71;
  static char_T c5_cv6[3] = { '-', '-', 'c' };

  char_T c5_ib_u[3];
  const mxArray *c5_jb_y = NULL;
  real_T c5_jb_u[5];
  const mxArray *c5_kb_y = NULL;
  real_T c5_kb_u[5];
  const mxArray *c5_lb_y = NULL;
  real_T c5_lb_u[5];
  const mxArray *c5_mb_y = NULL;
  int32_T c5_i72;
  static real_T c5_dv2[6] = { -1000.0, 1000.0, -1000.0, 1000.0, 0.0, 500.0 };

  real_T c5_mb_u[6];
  const mxArray *c5_nb_y = NULL;
  int32_T c5_i73;
  static char_T c5_cv7[2] = { 'o', 'n' };

  char_T c5_nb_u[2];
  const mxArray *c5_ob_y = NULL;
  real_T *c5_b_x;
  real_T *c5_pb_y;
  real_T *c5_b_z;
  real_T *c5_b_roll;
  real_T *c5_b_pitch;
  real_T *c5_b_yaw;
  real_T *c5_b_proll;
  real_T *c5_b_ppitch;
  real_T *c5_b_pyaw;
  real_T *c5_c_C;
  int32_T *c5_sfEvent;
  c5_c_C = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c5_b_pyaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c5_b_ppitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c5_b_proll = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c5_b_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c5_b_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c5_b_roll = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c5_b_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_pb_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c5_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, *c5_sfEvent);
  c5_hoistedGlobal = *c5_b_x;
  c5_b_hoistedGlobal = *c5_pb_y;
  c5_c_hoistedGlobal = *c5_b_z;
  c5_d_hoistedGlobal = *c5_b_roll;
  c5_e_hoistedGlobal = *c5_b_pitch;
  c5_f_hoistedGlobal = *c5_b_yaw;
  c5_g_hoistedGlobal = *c5_b_proll;
  c5_h_hoistedGlobal = *c5_b_ppitch;
  c5_i_hoistedGlobal = *c5_b_pyaw;
  c5_j_hoistedGlobal = *c5_c_C;
  c5_x = c5_hoistedGlobal;
  c5_y = c5_b_hoistedGlobal;
  c5_z = c5_c_hoistedGlobal;
  c5_roll = c5_d_hoistedGlobal;
  c5_pitch = c5_e_hoistedGlobal;
  c5_yaw = c5_f_hoistedGlobal;
  c5_proll = c5_g_hoistedGlobal;
  c5_ppitch = c5_h_hoistedGlobal;
  c5_pyaw = c5_i_hoistedGlobal;
  c5_C = c5_j_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 23U, 23U, c5_debug_family_names,
    c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c5_AXES, 0U, c5_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c5_M, 1U, c5_d_sf_marshallOut,
    c5_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_MX, 2U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_MY, 3U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_MZ, 4U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_P, 5U, c5_d_sf_marshallOut,
    c5_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_PX, 6U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_PY, 7U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_PZ, 8U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_az, 9U, c5_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_el, 10U, c5_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargin, 11U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargout, 12U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_x, 13U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_y, 14U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_z, 15U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_roll, 16U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_pitch, 17U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_yaw, 18U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_proll, 19U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_ppitch, 20U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_pyaw, 21U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_C, 22U, c5_sf_marshallOut);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c5_sfEvent, 3);
  _SFD_EML_CALL(0U, *c5_sfEvent, 4);
  _SFD_EML_CALL(0U, *c5_sfEvent, 5);
  _SFD_EML_CALL(0U, *c5_sfEvent, 6);
  _SFD_EML_CALL(0U, *c5_sfEvent, 7);
  _SFD_EML_CALL(0U, *c5_sfEvent, 9);
  if (CV_EML_IF(0, 1, 0, c5_C != 0.0)) {
    _SFD_EML_CALL(0U, *c5_sfEvent, 10);
  } else {
    _SFD_EML_CALL(0U, *c5_sfEvent, 13);
    for (c5_i0 = 0; c5_i0 < 9; c5_i0++) {
      c5_AXES[c5_i0] = c5_b[c5_i0];
    }

    _SFD_EML_CALL(0U, *c5_sfEvent, 15);
    for (c5_i1 = 0; c5_i1 < 9; c5_i1++) {
      c5_M[c5_i1] = 0.0;
    }

    _SFD_EML_CALL(0U, *c5_sfEvent, 16);
    c5_u = c5_roll;
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
    c5_b_u = c5_pitch;
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), FALSE);
    c5_c_u = c5_yaw;
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_c_u, 0, 0U, 0U, 0U, 0), FALSE);
    c5_c_emlrt_marshallIn(chartInstance, sf_mex_call_debug("rotationMatrix", 1U,
      3U, 14, c5_b_y, 14, c5_c_y, 14, c5_d_y), "rotationMatrix", c5_dv0);
    for (c5_i2 = 0; c5_i2 < 9; c5_i2++) {
      c5_M[c5_i2] = c5_dv0[c5_i2];
    }

    _SFD_EML_CALL(0U, *c5_sfEvent, 17);
    for (c5_i3 = 0; c5_i3 < 9; c5_i3++) {
      c5_a[c5_i3] = c5_M[c5_i3];
    }

    c5_eml_scalar_eg(chartInstance);
    c5_eml_scalar_eg(chartInstance);
    for (c5_i4 = 0; c5_i4 < 9; c5_i4++) {
      c5_M[c5_i4] = 0.0;
    }

    for (c5_i5 = 0; c5_i5 < 9; c5_i5++) {
      c5_M[c5_i5] = 0.0;
    }

    for (c5_i6 = 0; c5_i6 < 9; c5_i6++) {
      c5_b_C[c5_i6] = c5_M[c5_i6];
    }

    for (c5_i7 = 0; c5_i7 < 9; c5_i7++) {
      c5_M[c5_i7] = c5_b_C[c5_i7];
    }

    for (c5_i8 = 0; c5_i8 < 9; c5_i8++) {
      c5_b_C[c5_i8] = c5_M[c5_i8];
    }

    for (c5_i9 = 0; c5_i9 < 9; c5_i9++) {
      c5_M[c5_i9] = c5_b_C[c5_i9];
    }

    for (c5_i10 = 0; c5_i10 < 3; c5_i10++) {
      c5_i11 = 0;
      for (c5_i12 = 0; c5_i12 < 3; c5_i12++) {
        c5_M[c5_i11 + c5_i10] = 0.0;
        c5_i13 = 0;
        for (c5_i14 = 0; c5_i14 < 3; c5_i14++) {
          c5_M[c5_i11 + c5_i10] += c5_a[c5_i13 + c5_i10] * c5_b[c5_i14 + c5_i11];
          c5_i13 += 3;
        }

        c5_i11 += 3;
      }
    }

    _SFD_EML_CALL(0U, *c5_sfEvent, 19);
    c5_MX[0] = c5_x;
    c5_MX[3] = c5_M[0] + c5_x;
    c5_MX[1] = c5_y;
    c5_MX[4] = c5_M[1] + c5_y;
    c5_MX[2] = c5_z;
    c5_MX[5] = c5_M[2] + c5_z;
    _SFD_EML_CALL(0U, *c5_sfEvent, 20);
    c5_MY[0] = c5_x;
    c5_MY[3] = c5_M[3] + c5_x;
    c5_MY[1] = c5_y;
    c5_MY[4] = c5_M[4] + c5_y;
    c5_MY[2] = c5_z;
    c5_MY[5] = c5_M[5] + c5_z;
    _SFD_EML_CALL(0U, *c5_sfEvent, 21);
    c5_MZ[0] = c5_x;
    c5_MZ[3] = c5_M[6] + c5_x;
    c5_MZ[1] = c5_y;
    c5_MZ[4] = c5_M[7] + c5_y;
    c5_MZ[2] = c5_z;
    c5_MZ[5] = c5_M[8] + c5_z;
    _SFD_EML_CALL(0U, *c5_sfEvent, 23);
    for (c5_i15 = 0; c5_i15 < 9; c5_i15++) {
      c5_P[c5_i15] = 0.0;
    }

    _SFD_EML_CALL(0U, *c5_sfEvent, 24);
    c5_d_u = c5_proll;
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_d_u, 0, 0U, 0U, 0U, 0), FALSE);
    c5_e_u = c5_ppitch;
    c5_f_y = NULL;
    sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_e_u, 0, 0U, 0U, 0U, 0), FALSE);
    c5_f_u = c5_pyaw;
    c5_g_y = NULL;
    sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_f_u, 0, 0U, 0U, 0U, 0), FALSE);
    c5_c_emlrt_marshallIn(chartInstance, sf_mex_call_debug("rotationMatrix", 1U,
      3U, 14, c5_e_y, 14, c5_f_y, 14, c5_g_y), "rotationMatrix", c5_dv1);
    for (c5_i16 = 0; c5_i16 < 9; c5_i16++) {
      c5_P[c5_i16] = c5_dv1[c5_i16];
    }

    _SFD_EML_CALL(0U, *c5_sfEvent, 25);
    for (c5_i17 = 0; c5_i17 < 9; c5_i17++) {
      c5_a[c5_i17] = c5_P[c5_i17];
    }

    c5_eml_scalar_eg(chartInstance);
    c5_eml_scalar_eg(chartInstance);
    for (c5_i18 = 0; c5_i18 < 9; c5_i18++) {
      c5_P[c5_i18] = 0.0;
    }

    for (c5_i19 = 0; c5_i19 < 9; c5_i19++) {
      c5_P[c5_i19] = 0.0;
    }

    for (c5_i20 = 0; c5_i20 < 9; c5_i20++) {
      c5_b_C[c5_i20] = c5_P[c5_i20];
    }

    for (c5_i21 = 0; c5_i21 < 9; c5_i21++) {
      c5_P[c5_i21] = c5_b_C[c5_i21];
    }

    for (c5_i22 = 0; c5_i22 < 9; c5_i22++) {
      c5_b_C[c5_i22] = c5_P[c5_i22];
    }

    for (c5_i23 = 0; c5_i23 < 9; c5_i23++) {
      c5_P[c5_i23] = c5_b_C[c5_i23];
    }

    for (c5_i24 = 0; c5_i24 < 3; c5_i24++) {
      c5_i25 = 0;
      for (c5_i26 = 0; c5_i26 < 3; c5_i26++) {
        c5_P[c5_i25 + c5_i24] = 0.0;
        c5_i27 = 0;
        for (c5_i28 = 0; c5_i28 < 3; c5_i28++) {
          c5_P[c5_i25 + c5_i24] += c5_a[c5_i27 + c5_i24] * c5_b[c5_i28 + c5_i25];
          c5_i27 += 3;
        }

        c5_i25 += 3;
      }
    }

    _SFD_EML_CALL(0U, *c5_sfEvent, 27);
    c5_PX[0] = c5_x;
    c5_PX[3] = c5_P[0] + c5_x;
    c5_PX[1] = c5_y;
    c5_PX[4] = c5_P[1] + c5_y;
    c5_PX[2] = c5_z;
    c5_PX[5] = c5_P[2] + c5_z;
    _SFD_EML_CALL(0U, *c5_sfEvent, 28);
    c5_PY[0] = c5_x;
    c5_PY[3] = c5_P[3] + c5_x;
    c5_PY[1] = c5_y;
    c5_PY[4] = c5_P[4] + c5_y;
    c5_PY[2] = c5_z;
    c5_PY[5] = c5_P[5] + c5_z;
    _SFD_EML_CALL(0U, *c5_sfEvent, 29);
    c5_PZ[0] = c5_x;
    c5_PZ[3] = c5_P[6] + c5_x;
    c5_PZ[1] = c5_y;
    c5_PZ[4] = c5_P[7] + c5_y;
    c5_PZ[2] = c5_z;
    c5_PZ[5] = c5_P[8] + c5_z;
    _SFD_EML_CALL(0U, *c5_sfEvent, 31);
    sf_mex_call_debug("view", 2U, 0U, &c5_b_az, &c5_b_el);
    sf_mex_assign(&c5_az, sf_mex_dup(c5_b_az), FALSE);
    sf_mex_assign(&c5_el, sf_mex_dup(c5_b_el), FALSE);
    _SFD_EML_CALL(0U, *c5_sfEvent, 32);
    c5_g_u = c5_x;
    c5_h_y = NULL;
    sf_mex_assign(&c5_h_y, sf_mex_create("y", &c5_g_u, 0, 0U, 0U, 0U, 0), FALSE);
    c5_h_u = c5_y;
    c5_i_y = NULL;
    sf_mex_assign(&c5_i_y, sf_mex_create("y", &c5_h_u, 0, 0U, 0U, 0U, 0), FALSE);
    c5_i_u = c5_z;
    c5_j_y = NULL;
    sf_mex_assign(&c5_j_y, sf_mex_create("y", &c5_i_u, 0, 0U, 0U, 0U, 0), FALSE);
    for (c5_i29 = 0; c5_i29 < 2; c5_i29++) {
      c5_j_u[c5_i29] = c5_cv0[c5_i29];
    }

    c5_k_y = NULL;
    sf_mex_assign(&c5_k_y, sf_mex_create("y", c5_j_u, 10, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    c5_i30 = 0;
    for (c5_i31 = 0; c5_i31 < 2; c5_i31++) {
      c5_k_u[c5_i31] = c5_MX[c5_i30];
      c5_i30 += 3;
    }

    c5_l_y = NULL;
    sf_mex_assign(&c5_l_y, sf_mex_create("y", c5_k_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    c5_i32 = 0;
    for (c5_i33 = 0; c5_i33 < 2; c5_i33++) {
      c5_l_u[c5_i33] = c5_MX[c5_i32 + 1];
      c5_i32 += 3;
    }

    c5_m_y = NULL;
    sf_mex_assign(&c5_m_y, sf_mex_create("y", c5_l_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    c5_i34 = 0;
    for (c5_i35 = 0; c5_i35 < 2; c5_i35++) {
      c5_m_u[c5_i35] = c5_MX[c5_i34 + 2];
      c5_i34 += 3;
    }

    c5_n_y = NULL;
    sf_mex_assign(&c5_n_y, sf_mex_create("y", c5_m_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    for (c5_i36 = 0; c5_i36 < 2; c5_i36++) {
      c5_n_u[c5_i36] = c5_cv1[c5_i36];
    }

    c5_o_y = NULL;
    sf_mex_assign(&c5_o_y, sf_mex_create("y", c5_n_u, 10, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    c5_i37 = 0;
    for (c5_i38 = 0; c5_i38 < 2; c5_i38++) {
      c5_o_u[c5_i38] = c5_MY[c5_i37];
      c5_i37 += 3;
    }

    c5_p_y = NULL;
    sf_mex_assign(&c5_p_y, sf_mex_create("y", c5_o_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    c5_i39 = 0;
    for (c5_i40 = 0; c5_i40 < 2; c5_i40++) {
      c5_p_u[c5_i40] = c5_MY[c5_i39 + 1];
      c5_i39 += 3;
    }

    c5_q_y = NULL;
    sf_mex_assign(&c5_q_y, sf_mex_create("y", c5_p_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    c5_i41 = 0;
    for (c5_i42 = 0; c5_i42 < 2; c5_i42++) {
      c5_q_u[c5_i42] = c5_MY[c5_i41 + 2];
      c5_i41 += 3;
    }

    c5_r_y = NULL;
    sf_mex_assign(&c5_r_y, sf_mex_create("y", c5_q_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    for (c5_i43 = 0; c5_i43 < 2; c5_i43++) {
      c5_r_u[c5_i43] = c5_cv2[c5_i43];
    }

    c5_s_y = NULL;
    sf_mex_assign(&c5_s_y, sf_mex_create("y", c5_r_u, 10, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    c5_i44 = 0;
    for (c5_i45 = 0; c5_i45 < 2; c5_i45++) {
      c5_s_u[c5_i45] = c5_MZ[c5_i44];
      c5_i44 += 3;
    }

    c5_t_y = NULL;
    sf_mex_assign(&c5_t_y, sf_mex_create("y", c5_s_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    c5_i46 = 0;
    for (c5_i47 = 0; c5_i47 < 2; c5_i47++) {
      c5_t_u[c5_i47] = c5_MZ[c5_i46 + 1];
      c5_i46 += 3;
    }

    c5_u_y = NULL;
    sf_mex_assign(&c5_u_y, sf_mex_create("y", c5_t_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    c5_i48 = 0;
    for (c5_i49 = 0; c5_i49 < 2; c5_i49++) {
      c5_u_u[c5_i49] = c5_MZ[c5_i48 + 2];
      c5_i48 += 3;
    }

    c5_v_y = NULL;
    sf_mex_assign(&c5_v_y, sf_mex_create("y", c5_u_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    for (c5_i50 = 0; c5_i50 < 2; c5_i50++) {
      c5_v_u[c5_i50] = c5_cv3[c5_i50];
    }

    c5_w_y = NULL;
    sf_mex_assign(&c5_w_y, sf_mex_create("y", c5_v_u, 10, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    c5_i51 = 0;
    for (c5_i52 = 0; c5_i52 < 2; c5_i52++) {
      c5_w_u[c5_i52] = c5_PX[c5_i51];
      c5_i51 += 3;
    }

    c5_x_y = NULL;
    sf_mex_assign(&c5_x_y, sf_mex_create("y", c5_w_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    c5_i53 = 0;
    for (c5_i54 = 0; c5_i54 < 2; c5_i54++) {
      c5_x_u[c5_i54] = c5_PX[c5_i53 + 1];
      c5_i53 += 3;
    }

    c5_y_y = NULL;
    sf_mex_assign(&c5_y_y, sf_mex_create("y", c5_x_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    c5_i55 = 0;
    for (c5_i56 = 0; c5_i56 < 2; c5_i56++) {
      c5_y_u[c5_i56] = c5_PX[c5_i55 + 2];
      c5_i55 += 3;
    }

    c5_ab_y = NULL;
    sf_mex_assign(&c5_ab_y, sf_mex_create("y", c5_y_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    for (c5_i57 = 0; c5_i57 < 3; c5_i57++) {
      c5_ab_u[c5_i57] = c5_cv4[c5_i57];
    }

    c5_bb_y = NULL;
    sf_mex_assign(&c5_bb_y, sf_mex_create("y", c5_ab_u, 10, 0U, 1U, 0U, 2, 1, 3),
                  FALSE);
    c5_i58 = 0;
    for (c5_i59 = 0; c5_i59 < 2; c5_i59++) {
      c5_bb_u[c5_i59] = c5_PY[c5_i58];
      c5_i58 += 3;
    }

    c5_cb_y = NULL;
    sf_mex_assign(&c5_cb_y, sf_mex_create("y", c5_bb_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    c5_i60 = 0;
    for (c5_i61 = 0; c5_i61 < 2; c5_i61++) {
      c5_cb_u[c5_i61] = c5_PY[c5_i60 + 1];
      c5_i60 += 3;
    }

    c5_db_y = NULL;
    sf_mex_assign(&c5_db_y, sf_mex_create("y", c5_cb_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    c5_i62 = 0;
    for (c5_i63 = 0; c5_i63 < 2; c5_i63++) {
      c5_db_u[c5_i63] = c5_PY[c5_i62 + 2];
      c5_i62 += 3;
    }

    c5_eb_y = NULL;
    sf_mex_assign(&c5_eb_y, sf_mex_create("y", c5_db_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    for (c5_i64 = 0; c5_i64 < 3; c5_i64++) {
      c5_eb_u[c5_i64] = c5_cv5[c5_i64];
    }

    c5_fb_y = NULL;
    sf_mex_assign(&c5_fb_y, sf_mex_create("y", c5_eb_u, 10, 0U, 1U, 0U, 2, 1, 3),
                  FALSE);
    c5_i65 = 0;
    for (c5_i66 = 0; c5_i66 < 2; c5_i66++) {
      c5_fb_u[c5_i66] = c5_PZ[c5_i65];
      c5_i65 += 3;
    }

    c5_gb_y = NULL;
    sf_mex_assign(&c5_gb_y, sf_mex_create("y", c5_fb_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    c5_i67 = 0;
    for (c5_i68 = 0; c5_i68 < 2; c5_i68++) {
      c5_gb_u[c5_i68] = c5_PZ[c5_i67 + 1];
      c5_i67 += 3;
    }

    c5_hb_y = NULL;
    sf_mex_assign(&c5_hb_y, sf_mex_create("y", c5_gb_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    c5_i69 = 0;
    for (c5_i70 = 0; c5_i70 < 2; c5_i70++) {
      c5_hb_u[c5_i70] = c5_PZ[c5_i69 + 2];
      c5_i69 += 3;
    }

    c5_ib_y = NULL;
    sf_mex_assign(&c5_ib_y, sf_mex_create("y", c5_hb_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    for (c5_i71 = 0; c5_i71 < 3; c5_i71++) {
      c5_ib_u[c5_i71] = c5_cv6[c5_i71];
    }

    c5_jb_y = NULL;
    sf_mex_assign(&c5_jb_y, sf_mex_create("y", c5_ib_u, 10, 0U, 1U, 0U, 2, 1, 3),
                  FALSE);
    c5_jb_u[0] = c5_x + 50.0;
    c5_jb_u[1] = c5_x + 50.0;
    c5_jb_u[2] = c5_x - 50.0;
    c5_jb_u[3] = c5_x - 50.0;
    c5_jb_u[4] = c5_x + 50.0;
    c5_kb_y = NULL;
    sf_mex_assign(&c5_kb_y, sf_mex_create("y", c5_jb_u, 0, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
    c5_kb_u[0] = c5_y + 50.0;
    c5_kb_u[1] = c5_y - 50.0;
    c5_kb_u[2] = c5_y - 50.0;
    c5_kb_u[3] = c5_y + 50.0;
    c5_kb_u[4] = c5_y + 50.0;
    c5_lb_y = NULL;
    sf_mex_assign(&c5_lb_y, sf_mex_create("y", c5_kb_u, 0, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
    c5_lb_u[0] = c5_z;
    c5_lb_u[1] = c5_z;
    c5_lb_u[2] = c5_z;
    c5_lb_u[3] = c5_z;
    c5_lb_u[4] = c5_z;
    c5_mb_y = NULL;
    sf_mex_assign(&c5_mb_y, sf_mex_create("y", c5_lb_u, 0, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
    sf_mex_call_debug("plot3", 0U, 31U, 14, c5_h_y, 14, c5_i_y, 14, c5_j_y, 14,
                      c5_k_y, 14, c5_l_y, 14, c5_m_y, 14, c5_n_y, 14, c5_o_y, 14,
                      c5_p_y, 14, c5_q_y, 14, c5_r_y, 14, c5_s_y, 14, c5_t_y, 14,
                      c5_u_y, 14, c5_v_y, 14, c5_w_y, 14, c5_x_y, 14, c5_y_y, 14,
                      c5_ab_y, 14, c5_bb_y, 14, c5_cb_y, 14, c5_db_y, 14,
                      c5_eb_y, 14, c5_fb_y, 14, c5_gb_y, 14, c5_hb_y, 14,
                      c5_ib_y, 14, c5_jb_y, 14, c5_kb_y, 14, c5_lb_y, 14,
                      c5_mb_y);
    _SFD_EML_CALL(0U, *c5_sfEvent, 33);
    for (c5_i72 = 0; c5_i72 < 6; c5_i72++) {
      c5_mb_u[c5_i72] = c5_dv2[c5_i72];
    }

    c5_nb_y = NULL;
    sf_mex_assign(&c5_nb_y, sf_mex_create("y", c5_mb_u, 0, 0U, 1U, 0U, 2, 1, 6),
                  FALSE);
    sf_mex_call_debug("axis", 0U, 1U, 14, c5_nb_y);
    _SFD_EML_CALL(0U, *c5_sfEvent, 34);
    for (c5_i73 = 0; c5_i73 < 2; c5_i73++) {
      c5_nb_u[c5_i73] = c5_cv7[c5_i73];
    }

    c5_ob_y = NULL;
    sf_mex_assign(&c5_ob_y, sf_mex_create("y", c5_nb_u, 10, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    sf_mex_call_debug("grid", 0U, 1U, 14, c5_ob_y);
    _SFD_EML_CALL(0U, *c5_sfEvent, 35);
    sf_mex_call_debug("view", 0U, 1U, 14, sf_mex_call_debug("horzcat", 1U, 2U,
      14, sf_mex_dup(c5_az), 14, sf_mex_dup(c5_el)));
  }

  _SFD_EML_CALL(0U, *c5_sfEvent, -35);
  sf_debug_symbol_scope_pop();
  sf_mex_destroy(&c5_az);
  sf_mex_destroy(&c5_el);
  sf_mex_destroy(&c5_b_az);
  sf_mex_destroy(&c5_b_el);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *c5_sfEvent);
}

static void initSimStructsc5_lab2_next_level(SFc5_lab2_next_levelInstanceStruct *
  chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc5_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static real_T c5_emlrt_marshallIn(SFc5_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_nargout;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc5_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c5_nargout = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargout), &c5_thisId);
  sf_mex_destroy(&c5_nargout);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  const mxArray *c5_u;
  const mxArray *c5_y = NULL;
  SFc5_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc5_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = sf_mex_dup(*(const mxArray **)c5_inData);
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_duplicatearraysafe(&c5_u), FALSE);
  sf_mex_destroy(&c5_u);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i74;
  int32_T c5_i75;
  int32_T c5_i76;
  real_T c5_b_inData[6];
  int32_T c5_i77;
  int32_T c5_i78;
  int32_T c5_i79;
  real_T c5_u[6];
  const mxArray *c5_y = NULL;
  SFc5_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc5_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i74 = 0;
  for (c5_i75 = 0; c5_i75 < 2; c5_i75++) {
    for (c5_i76 = 0; c5_i76 < 3; c5_i76++) {
      c5_b_inData[c5_i76 + c5_i74] = (*(real_T (*)[6])c5_inData)[c5_i76 + c5_i74];
    }

    c5_i74 += 3;
  }

  c5_i77 = 0;
  for (c5_i78 = 0; c5_i78 < 2; c5_i78++) {
    for (c5_i79 = 0; c5_i79 < 3; c5_i79++) {
      c5_u[c5_i79 + c5_i77] = c5_b_inData[c5_i79 + c5_i77];
    }

    c5_i77 += 3;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 3, 2), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_b_emlrt_marshallIn(SFc5_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[6])
{
  real_T c5_dv3[6];
  int32_T c5_i80;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv3, 1, 0, 0U, 1, 0U, 2, 3, 2);
  for (c5_i80 = 0; c5_i80 < 6; c5_i80++) {
    c5_y[c5_i80] = c5_dv3[c5_i80];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_PZ;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[6];
  int32_T c5_i81;
  int32_T c5_i82;
  int32_T c5_i83;
  SFc5_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc5_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c5_PZ = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_PZ), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_PZ);
  c5_i81 = 0;
  for (c5_i82 = 0; c5_i82 < 2; c5_i82++) {
    for (c5_i83 = 0; c5_i83 < 3; c5_i83++) {
      (*(real_T (*)[6])c5_outData)[c5_i83 + c5_i81] = c5_y[c5_i83 + c5_i81];
    }

    c5_i81 += 3;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i84;
  int32_T c5_i85;
  int32_T c5_i86;
  real_T c5_b_inData[9];
  int32_T c5_i87;
  int32_T c5_i88;
  int32_T c5_i89;
  real_T c5_u[9];
  const mxArray *c5_y = NULL;
  SFc5_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc5_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i84 = 0;
  for (c5_i85 = 0; c5_i85 < 3; c5_i85++) {
    for (c5_i86 = 0; c5_i86 < 3; c5_i86++) {
      c5_b_inData[c5_i86 + c5_i84] = (*(real_T (*)[9])c5_inData)[c5_i86 + c5_i84];
    }

    c5_i84 += 3;
  }

  c5_i87 = 0;
  for (c5_i88 = 0; c5_i88 < 3; c5_i88++) {
    for (c5_i89 = 0; c5_i89 < 3; c5_i89++) {
      c5_u[c5_i89 + c5_i87] = c5_b_inData[c5_i89 + c5_i87];
    }

    c5_i87 += 3;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_rotationMatrix;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[9];
  int32_T c5_i90;
  int32_T c5_i91;
  int32_T c5_i92;
  SFc5_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc5_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c5_rotationMatrix = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_rotationMatrix), &c5_thisId,
                        c5_y);
  sf_mex_destroy(&c5_rotationMatrix);
  c5_i90 = 0;
  for (c5_i91 = 0; c5_i91 < 3; c5_i91++) {
    for (c5_i92 = 0; c5_i92 < 3; c5_i92++) {
      (*(real_T (*)[9])c5_outData)[c5_i92 + c5_i90] = c5_y[c5_i92 + c5_i90];
    }

    c5_i90 += 3;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_lab2_next_level_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo;
  c5_ResolvedFunctionInfo c5_info[9];
  c5_ResolvedFunctionInfo (*c5_b_info)[9];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i93;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  c5_b_info = (c5_ResolvedFunctionInfo (*)[9])c5_info;
  (*c5_b_info)[0].context = "";
  (*c5_b_info)[0].name = "mtimes";
  (*c5_b_info)[0].dominantType = "double";
  (*c5_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[0].fileTimeLo = 1289508892U;
  (*c5_b_info)[0].fileTimeHi = 0U;
  (*c5_b_info)[0].mFileTimeLo = 0U;
  (*c5_b_info)[0].mFileTimeHi = 0U;
  (*c5_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[1].name = "eml_index_class";
  (*c5_b_info)[1].dominantType = "";
  (*c5_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c5_b_info)[1].fileTimeLo = 1323159778U;
  (*c5_b_info)[1].fileTimeHi = 0U;
  (*c5_b_info)[1].mFileTimeLo = 0U;
  (*c5_b_info)[1].mFileTimeHi = 0U;
  (*c5_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[2].name = "eml_scalar_eg";
  (*c5_b_info)[2].dominantType = "double";
  (*c5_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c5_b_info)[2].fileTimeLo = 1286811596U;
  (*c5_b_info)[2].fileTimeHi = 0U;
  (*c5_b_info)[2].mFileTimeLo = 0U;
  (*c5_b_info)[2].mFileTimeHi = 0U;
  (*c5_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[3].name = "eml_xgemm";
  (*c5_b_info)[3].dominantType = "char";
  (*c5_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c5_b_info)[3].fileTimeLo = 1299065972U;
  (*c5_b_info)[3].fileTimeHi = 0U;
  (*c5_b_info)[3].mFileTimeLo = 0U;
  (*c5_b_info)[3].mFileTimeHi = 0U;
  (*c5_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c5_b_info)[4].name = "eml_blas_inline";
  (*c5_b_info)[4].dominantType = "";
  (*c5_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  (*c5_b_info)[4].fileTimeLo = 1299065968U;
  (*c5_b_info)[4].fileTimeHi = 0U;
  (*c5_b_info)[4].mFileTimeLo = 0U;
  (*c5_b_info)[4].mFileTimeHi = 0U;
  (*c5_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  (*c5_b_info)[5].name = "mtimes";
  (*c5_b_info)[5].dominantType = "double";
  (*c5_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[5].fileTimeLo = 1289508892U;
  (*c5_b_info)[5].fileTimeHi = 0U;
  (*c5_b_info)[5].mFileTimeLo = 0U;
  (*c5_b_info)[5].mFileTimeHi = 0U;
  (*c5_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c5_b_info)[6].name = "eml_index_class";
  (*c5_b_info)[6].dominantType = "";
  (*c5_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c5_b_info)[6].fileTimeLo = 1323159778U;
  (*c5_b_info)[6].fileTimeHi = 0U;
  (*c5_b_info)[6].mFileTimeLo = 0U;
  (*c5_b_info)[6].mFileTimeHi = 0U;
  (*c5_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c5_b_info)[7].name = "eml_scalar_eg";
  (*c5_b_info)[7].dominantType = "double";
  (*c5_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c5_b_info)[7].fileTimeLo = 1286811596U;
  (*c5_b_info)[7].fileTimeHi = 0U;
  (*c5_b_info)[7].mFileTimeLo = 0U;
  (*c5_b_info)[7].mFileTimeHi = 0U;
  (*c5_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c5_b_info)[8].name = "eml_refblas_xgemm";
  (*c5_b_info)[8].dominantType = "char";
  (*c5_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c5_b_info)[8].fileTimeLo = 1299065974U;
  (*c5_b_info)[8].fileTimeHi = 0U;
  (*c5_b_info)[8].mFileTimeLo = 0U;
  (*c5_b_info)[8].mFileTimeHi = 0U;
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 9), FALSE);
  for (c5_i93 = 0; c5_i93 < 9; c5_i93++) {
    c5_r0 = &c5_info[c5_i93];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context", "nameCaptureInfo",
                    c5_i93);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name", "nameCaptureInfo", c5_i93);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c5_i93);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved", "nameCaptureInfo",
                    c5_i93);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c5_i93);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c5_i93);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c5_i93);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c5_i93);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_eml_scalar_eg(SFc5_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void c5_c_emlrt_marshallIn(SFc5_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c5_rotationMatrix, const char_T *c5_identifier,
  real_T c5_y[9])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_rotationMatrix), &c5_thisId,
                        c5_y);
  sf_mex_destroy(&c5_rotationMatrix);
}

static void c5_d_emlrt_marshallIn(SFc5_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[9])
{
  real_T c5_dv4[9];
  int32_T c5_i94;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv4, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c5_i94 = 0; c5_i94 < 9; c5_i94++) {
    c5_y[c5_i94] = c5_dv4[c5_i94];
  }

  sf_mex_destroy(&c5_u);
}

static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc5_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static int32_T c5_e_emlrt_marshallIn(SFc5_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i95;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i95, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i95;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc5_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c5_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_sfEvent), &c5_thisId);
  sf_mex_destroy(&c5_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_f_emlrt_marshallIn(SFc5_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c5_is_active_c5_lab2_next_level, const char_T
  *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_is_active_c5_lab2_next_level), &c5_thisId);
  sf_mex_destroy(&c5_is_active_c5_lab2_next_level);
  return c5_y;
}

static uint8_T c5_g_emlrt_marshallIn(SFc5_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c5_lab2_next_level_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2222877254U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2699429309U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2837545525U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(88669379U);
}

mxArray *sf_c5_lab2_next_level_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("GPnlTXCn1y9uoLmp2mbpn");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,10,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c5_lab2_next_level(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c5_lab2_next_level\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_lab2_next_level_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_lab2_next_levelInstanceStruct *chartInstance;
    chartInstance = (SFc5_lab2_next_levelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_lab2_next_levelMachineNumber_,
           5,
           1,
           1,
           10,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_lab2_next_levelMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_lab2_next_levelMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_lab2_next_levelMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"x");
          _SFD_SET_DATA_PROPS(1,1,1,0,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"z");
          _SFD_SET_DATA_PROPS(3,1,1,0,"roll");
          _SFD_SET_DATA_PROPS(4,1,1,0,"pitch");
          _SFD_SET_DATA_PROPS(5,1,1,0,"yaw");
          _SFD_SET_DATA_PROPS(6,1,1,0,"proll");
          _SFD_SET_DATA_PROPS(7,1,1,0,"ppitch");
          _SFD_SET_DATA_PROPS(8,1,1,0,"pyaw");
          _SFD_SET_DATA_PROPS(9,1,1,0,"C");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1010);
        _SFD_CV_INIT_EML_IF(0,1,0,198,208,-1,-2);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c5_x;
          real_T *c5_y;
          real_T *c5_z;
          real_T *c5_roll;
          real_T *c5_pitch;
          real_T *c5_yaw;
          real_T *c5_proll;
          real_T *c5_ppitch;
          real_T *c5_pyaw;
          real_T *c5_C;
          c5_C = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c5_pyaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c5_ppitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c5_proll = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c5_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c5_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c5_roll = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c5_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c5_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_x);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_z);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_roll);
          _SFD_SET_DATA_VALUE_PTR(4U, c5_pitch);
          _SFD_SET_DATA_VALUE_PTR(5U, c5_yaw);
          _SFD_SET_DATA_VALUE_PTR(6U, c5_proll);
          _SFD_SET_DATA_VALUE_PTR(7U, c5_ppitch);
          _SFD_SET_DATA_VALUE_PTR(8U, c5_pyaw);
          _SFD_SET_DATA_VALUE_PTR(9U, c5_C);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_lab2_next_levelMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "7bmB8ztb6GYe0mpdzHGjJ";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 5, "dworkChecksum");
    if (mxRTWDWorkChecksum != NULL) {
      double *pr = mxGetPr(mxRTWDWorkChecksum);
      if ((uint32_T)pr[0] != sfunDWorkChecksum[0] ||
          (uint32_T)pr[1] != sfunDWorkChecksum[1] ||
          (uint32_T)pr[2] != sfunDWorkChecksum[2] ||
          (uint32_T)pr[3] != sfunDWorkChecksum[3]) {
        sf_mex_error_message("Code generation and simulation targets registered different sets of persistent variables for the block. "
                             "External or Rapid Accelerator mode simulation requires code generation and simulation targets to "
                             "register the same set of persistent variables for this block. "
                             "This discrepancy is typically caused by MATLAB functions that have different code paths for "
                             "simulation and code generation targets where these code paths define different sets of persistent variables. "
                             "Please identify these code paths in the offending block and rewrite the MATLAB code so that "
                             "the set of persistent variables is the same between simulation and code generation.");
      }
    }
  }
}

static void sf_opaque_initialize_c5_lab2_next_level(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc5_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc5_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_lab2_next_level((SFc5_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
  initialize_c5_lab2_next_level((SFc5_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_lab2_next_level(void *chartInstanceVar)
{
  enable_c5_lab2_next_level((SFc5_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_lab2_next_level(void *chartInstanceVar)
{
  disable_c5_lab2_next_level((SFc5_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_lab2_next_level(void *chartInstanceVar)
{
  sf_c5_lab2_next_level((SFc5_lab2_next_levelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c5_lab2_next_level(void *chartInstanceVar)
{
  ext_mode_exec_c5_lab2_next_level((SFc5_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_lab2_next_level(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_lab2_next_level
    ((SFc5_lab2_next_levelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_lab2_next_level();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c5_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_lab2_next_level();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_lab2_next_level((SFc5_lab2_next_levelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_lab2_next_level(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_lab2_next_level(S);
}

static void sf_opaque_set_sim_state_c5_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c5_lab2_next_level(S, st);
}

static void sf_opaque_terminate_c5_lab2_next_level(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_lab2_next_levelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_lab2_next_level((SFc5_lab2_next_levelInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_lab2_next_level_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_lab2_next_level((SFc5_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_lab2_next_level(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_lab2_next_level((SFc5_lab2_next_levelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c5_lab2_next_level_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c5_lab2_next_level\",T\"is_active_c5_lab2_next_level\"}}"
  };

  mxArray *mxTpInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  return mxTpInfo;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x4'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"int32\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 4, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 3851270630U, 3363230343U, 1651207761U,
    946165807U };

  return checksum;
}

static void mdlSetWorkWidths_c5_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,5,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,10);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2127771106U));
  ssSetChecksum1(S,(408798534U));
  ssSetChecksum2(S,(1829990536U));
  ssSetChecksum3(S,(2915315453U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_lab2_next_level(SimStruct *S)
{
  SFc5_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc5_lab2_next_levelInstanceStruct *)malloc(sizeof
    (SFc5_lab2_next_levelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_lab2_next_levelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_lab2_next_level;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_lab2_next_level;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_lab2_next_level;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_lab2_next_level;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_lab2_next_level;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_lab2_next_level;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_lab2_next_level;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_lab2_next_level;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_lab2_next_level;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_lab2_next_level;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_lab2_next_level;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c5_lab2_next_level;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c5_lab2_next_level_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_lab2_next_level(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_lab2_next_level(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_lab2_next_level(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_lab2_next_level_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
