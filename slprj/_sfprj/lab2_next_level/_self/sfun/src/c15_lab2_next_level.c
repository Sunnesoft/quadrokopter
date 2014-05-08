/* Include files */

#include "blascompat32.h"
#include "lab2_next_level_sfun.h"
#include "c15_lab2_next_level.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lab2_next_level_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c15_debug_family_names[15] = { "roll", "pitch", "yaw", "x",
  "y", "z", "P", "M", "nargin", "nargout", "angles", "accel", "xs", "ys", "zs" };

/* Function Declarations */
static void initialize_c15_lab2_next_level(SFc15_lab2_next_levelInstanceStruct
  *chartInstance);
static void initialize_params_c15_lab2_next_level
  (SFc15_lab2_next_levelInstanceStruct *chartInstance);
static void enable_c15_lab2_next_level(SFc15_lab2_next_levelInstanceStruct
  *chartInstance);
static void disable_c15_lab2_next_level(SFc15_lab2_next_levelInstanceStruct
  *chartInstance);
static void c15_update_debugger_state_c15_lab2_next_level
  (SFc15_lab2_next_levelInstanceStruct *chartInstance);
static void ext_mode_exec_c15_lab2_next_level
  (SFc15_lab2_next_levelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c15_lab2_next_level
  (SFc15_lab2_next_levelInstanceStruct *chartInstance);
static void set_sim_state_c15_lab2_next_level
  (SFc15_lab2_next_levelInstanceStruct *chartInstance, const mxArray *c15_st);
static void finalize_c15_lab2_next_level(SFc15_lab2_next_levelInstanceStruct
  *chartInstance);
static void sf_c15_lab2_next_level(SFc15_lab2_next_levelInstanceStruct
  *chartInstance);
static void c15_chartstep_c15_lab2_next_level
  (SFc15_lab2_next_levelInstanceStruct *chartInstance);
static void initSimStructsc15_lab2_next_level
  (SFc15_lab2_next_levelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber);
static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static real_T c15_emlrt_marshallIn(SFc15_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c15_zs, const char_T *c15_identifier);
static real_T c15_b_emlrt_marshallIn(SFc15_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_c_emlrt_marshallIn(SFc15_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[3]);
static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static void c15_eml_scalar_eg(SFc15_lab2_next_levelInstanceStruct *chartInstance);
static void c15_d_emlrt_marshallIn(SFc15_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c15_rotationMatrix, const char_T
  *c15_identifier, real_T c15_y[9]);
static void c15_e_emlrt_marshallIn(SFc15_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[9]);
static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static int32_T c15_f_emlrt_marshallIn(SFc15_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static uint8_T c15_g_emlrt_marshallIn(SFc15_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c15_is_active_c15_lab2_next_level, const char_T
  *c15_identifier);
static uint8_T c15_h_emlrt_marshallIn(SFc15_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void init_dsm_address_info(SFc15_lab2_next_levelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c15_lab2_next_level(SFc15_lab2_next_levelInstanceStruct
  *chartInstance)
{
  int32_T *c15_sfEvent;
  uint8_T *c15_is_active_c15_lab2_next_level;
  c15_is_active_c15_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c15_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c15_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c15_is_active_c15_lab2_next_level = 0U;
}

static void initialize_params_c15_lab2_next_level
  (SFc15_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void enable_c15_lab2_next_level(SFc15_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c15_lab2_next_level(SFc15_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c15_update_debugger_state_c15_lab2_next_level
  (SFc15_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c15_lab2_next_level
  (SFc15_lab2_next_levelInstanceStruct *chartInstance)
{
  c15_update_debugger_state_c15_lab2_next_level(chartInstance);
}

static const mxArray *get_sim_state_c15_lab2_next_level
  (SFc15_lab2_next_levelInstanceStruct *chartInstance)
{
  const mxArray *c15_st;
  const mxArray *c15_y = NULL;
  real_T c15_hoistedGlobal;
  real_T c15_u;
  const mxArray *c15_b_y = NULL;
  real_T c15_b_hoistedGlobal;
  real_T c15_b_u;
  const mxArray *c15_c_y = NULL;
  real_T c15_c_hoistedGlobal;
  real_T c15_c_u;
  const mxArray *c15_d_y = NULL;
  uint8_T c15_d_hoistedGlobal;
  uint8_T c15_d_u;
  const mxArray *c15_e_y = NULL;
  real_T *c15_xs;
  real_T *c15_ys;
  real_T *c15_zs;
  uint8_T *c15_is_active_c15_lab2_next_level;
  c15_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c15_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c15_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c15_is_active_c15_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c15_st = NULL;
  c15_st = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_createcellarray(4), FALSE);
  c15_hoistedGlobal = *c15_xs;
  c15_u = c15_hoistedGlobal;
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", &c15_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c15_y, 0, c15_b_y);
  c15_b_hoistedGlobal = *c15_ys;
  c15_b_u = c15_b_hoistedGlobal;
  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", &c15_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c15_y, 1, c15_c_y);
  c15_c_hoistedGlobal = *c15_zs;
  c15_c_u = c15_c_hoistedGlobal;
  c15_d_y = NULL;
  sf_mex_assign(&c15_d_y, sf_mex_create("y", &c15_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c15_y, 2, c15_d_y);
  c15_d_hoistedGlobal = *c15_is_active_c15_lab2_next_level;
  c15_d_u = c15_d_hoistedGlobal;
  c15_e_y = NULL;
  sf_mex_assign(&c15_e_y, sf_mex_create("y", &c15_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c15_y, 3, c15_e_y);
  sf_mex_assign(&c15_st, c15_y, FALSE);
  return c15_st;
}

static void set_sim_state_c15_lab2_next_level
  (SFc15_lab2_next_levelInstanceStruct *chartInstance, const mxArray *c15_st)
{
  const mxArray *c15_u;
  boolean_T *c15_doneDoubleBufferReInit;
  real_T *c15_xs;
  real_T *c15_ys;
  real_T *c15_zs;
  uint8_T *c15_is_active_c15_lab2_next_level;
  c15_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c15_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c15_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c15_is_active_c15_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c15_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c15_doneDoubleBufferReInit = TRUE;
  c15_u = sf_mex_dup(c15_st);
  *c15_xs = c15_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u,
    0)), "xs");
  *c15_ys = c15_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u,
    1)), "ys");
  *c15_zs = c15_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u,
    2)), "zs");
  *c15_is_active_c15_lab2_next_level = c15_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c15_u, 3)), "is_active_c15_lab2_next_level");
  sf_mex_destroy(&c15_u);
  c15_update_debugger_state_c15_lab2_next_level(chartInstance);
  sf_mex_destroy(&c15_st);
}

static void finalize_c15_lab2_next_level(SFc15_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

static void sf_c15_lab2_next_level(SFc15_lab2_next_levelInstanceStruct
  *chartInstance)
{
  int32_T c15_i0;
  int32_T c15_i1;
  int32_T *c15_sfEvent;
  real_T *c15_xs;
  real_T *c15_ys;
  real_T *c15_zs;
  real_T (*c15_accel)[3];
  real_T (*c15_angles)[3];
  c15_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c15_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c15_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c15_accel = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c15_angles = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c15_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, *c15_sfEvent);
  for (c15_i0 = 0; c15_i0 < 3; c15_i0++) {
    _SFD_DATA_RANGE_CHECK((*c15_angles)[c15_i0], 0U);
  }

  for (c15_i1 = 0; c15_i1 < 3; c15_i1++) {
    _SFD_DATA_RANGE_CHECK((*c15_accel)[c15_i1], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c15_xs, 2U);
  _SFD_DATA_RANGE_CHECK(*c15_ys, 3U);
  _SFD_DATA_RANGE_CHECK(*c15_zs, 4U);
  *c15_sfEvent = CALL_EVENT;
  c15_chartstep_c15_lab2_next_level(chartInstance);
  sf_debug_check_for_state_inconsistency(_lab2_next_levelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c15_chartstep_c15_lab2_next_level
  (SFc15_lab2_next_levelInstanceStruct *chartInstance)
{
  int32_T c15_i2;
  real_T c15_angles[3];
  int32_T c15_i3;
  real_T c15_accel[3];
  uint32_T c15_debug_family_var_map[15];
  real_T c15_roll;
  real_T c15_pitch;
  real_T c15_yaw;
  real_T c15_x;
  real_T c15_y;
  real_T c15_z;
  real_T c15_P[9];
  real_T c15_M[3];
  real_T c15_nargin = 2.0;
  real_T c15_nargout = 3.0;
  real_T c15_xs;
  real_T c15_ys;
  real_T c15_zs;
  int32_T c15_i4;
  real_T c15_u;
  const mxArray *c15_b_y = NULL;
  real_T c15_b_u;
  const mxArray *c15_c_y = NULL;
  real_T c15_c_u;
  const mxArray *c15_d_y = NULL;
  real_T c15_dv0[9];
  int32_T c15_i5;
  int32_T c15_i6;
  int32_T c15_i7;
  int32_T c15_i8;
  int32_T c15_i9;
  real_T c15_a[9];
  real_T c15_b[3];
  int32_T c15_i10;
  int32_T c15_i11;
  int32_T c15_i12;
  real_T c15_C[3];
  int32_T c15_i13;
  int32_T c15_i14;
  int32_T c15_i15;
  int32_T c15_i16;
  int32_T c15_i17;
  int32_T c15_i18;
  real_T *c15_b_xs;
  real_T *c15_b_ys;
  real_T *c15_b_zs;
  real_T (*c15_b_accel)[3];
  real_T (*c15_b_angles)[3];
  int32_T *c15_sfEvent;
  c15_b_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c15_b_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c15_b_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c15_b_accel = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c15_b_angles = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c15_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, *c15_sfEvent);
  for (c15_i2 = 0; c15_i2 < 3; c15_i2++) {
    c15_angles[c15_i2] = (*c15_b_angles)[c15_i2];
  }

  for (c15_i3 = 0; c15_i3 < 3; c15_i3++) {
    c15_accel[c15_i3] = (*c15_b_accel)[c15_i3];
  }

  sf_debug_symbol_scope_push_eml(0U, 15U, 15U, c15_debug_family_names,
    c15_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c15_roll, 0U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c15_pitch, 1U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c15_yaw, 2U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c15_x, 3U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c15_y, 4U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c15_z, 5U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c15_P, 6U, c15_c_sf_marshallOut,
    c15_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c15_M, 7U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c15_nargin, 8U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c15_nargout, 9U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c15_angles, 10U, c15_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c15_accel, 11U, c15_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c15_xs, 12U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c15_ys, 13U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c15_zs, 14U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c15_sfEvent, 5);
  c15_roll = c15_angles[0];
  _SFD_EML_CALL(0U, *c15_sfEvent, 6);
  c15_pitch = c15_angles[0];
  _SFD_EML_CALL(0U, *c15_sfEvent, 7);
  c15_yaw = c15_angles[2];
  _SFD_EML_CALL(0U, *c15_sfEvent, 9);
  c15_x = c15_accel[0];
  _SFD_EML_CALL(0U, *c15_sfEvent, 10);
  c15_y = c15_accel[1];
  _SFD_EML_CALL(0U, *c15_sfEvent, 11);
  c15_z = c15_accel[2];
  _SFD_EML_CALL(0U, *c15_sfEvent, 13);
  _SFD_EML_CALL(0U, *c15_sfEvent, 15);
  for (c15_i4 = 0; c15_i4 < 9; c15_i4++) {
    c15_P[c15_i4] = 0.0;
  }

  _SFD_EML_CALL(0U, *c15_sfEvent, 16);
  c15_u = c15_roll;
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", &c15_u, 0, 0U, 0U, 0U, 0), FALSE);
  c15_b_u = c15_pitch;
  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", &c15_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  c15_c_u = c15_yaw;
  c15_d_y = NULL;
  sf_mex_assign(&c15_d_y, sf_mex_create("y", &c15_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  c15_d_emlrt_marshallIn(chartInstance, sf_mex_call_debug("rotationMatrix", 1U,
    3U, 14, c15_b_y, 14, c15_c_y, 14, c15_d_y), "rotationMatrix", c15_dv0);
  for (c15_i5 = 0; c15_i5 < 9; c15_i5++) {
    c15_P[c15_i5] = c15_dv0[c15_i5];
  }

  _SFD_EML_CALL(0U, *c15_sfEvent, 18);
  c15_i6 = 0;
  for (c15_i7 = 0; c15_i7 < 3; c15_i7++) {
    c15_i8 = 0;
    for (c15_i9 = 0; c15_i9 < 3; c15_i9++) {
      c15_a[c15_i9 + c15_i6] = c15_P[c15_i8 + c15_i7];
      c15_i8 += 3;
    }

    c15_i6 += 3;
  }

  c15_b[0] = c15_x;
  c15_b[1] = c15_y;
  c15_b[2] = c15_z;
  c15_eml_scalar_eg(chartInstance);
  c15_eml_scalar_eg(chartInstance);
  for (c15_i10 = 0; c15_i10 < 3; c15_i10++) {
    c15_M[c15_i10] = 0.0;
  }

  for (c15_i11 = 0; c15_i11 < 3; c15_i11++) {
    c15_M[c15_i11] = 0.0;
  }

  for (c15_i12 = 0; c15_i12 < 3; c15_i12++) {
    c15_C[c15_i12] = c15_M[c15_i12];
  }

  for (c15_i13 = 0; c15_i13 < 3; c15_i13++) {
    c15_M[c15_i13] = c15_C[c15_i13];
  }

  for (c15_i14 = 0; c15_i14 < 3; c15_i14++) {
    c15_C[c15_i14] = c15_M[c15_i14];
  }

  for (c15_i15 = 0; c15_i15 < 3; c15_i15++) {
    c15_M[c15_i15] = c15_C[c15_i15];
  }

  for (c15_i16 = 0; c15_i16 < 3; c15_i16++) {
    c15_M[c15_i16] = 0.0;
    c15_i17 = 0;
    for (c15_i18 = 0; c15_i18 < 3; c15_i18++) {
      c15_M[c15_i16] += c15_a[c15_i17 + c15_i16] * c15_b[c15_i18];
      c15_i17 += 3;
    }
  }

  _SFD_EML_CALL(0U, *c15_sfEvent, 20);
  c15_xs = c15_M[0];
  _SFD_EML_CALL(0U, *c15_sfEvent, 21);
  c15_ys = c15_M[1];
  _SFD_EML_CALL(0U, *c15_sfEvent, 22);
  c15_zs = c15_M[2];
  _SFD_EML_CALL(0U, *c15_sfEvent, -22);
  sf_debug_symbol_scope_pop();
  *c15_b_xs = c15_xs;
  *c15_b_ys = c15_ys;
  *c15_b_zs = c15_zs;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, *c15_sfEvent);
}

static void initSimStructsc15_lab2_next_level
  (SFc15_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber)
{
}

static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  real_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc15_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(real_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static real_T c15_emlrt_marshallIn(SFc15_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c15_zs, const char_T *c15_identifier)
{
  real_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_zs), &c15_thisId);
  sf_mex_destroy(&c15_zs);
  return c15_y;
}

static real_T c15_b_emlrt_marshallIn(SFc15_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  real_T c15_y;
  real_T c15_d0;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_d0, 1, 0, 0U, 0, 0U, 0);
  c15_y = c15_d0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_zs;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y;
  SFc15_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc15_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c15_zs = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_zs), &c15_thisId);
  sf_mex_destroy(&c15_zs);
  *(real_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i19;
  real_T c15_b_inData[3];
  int32_T c15_i20;
  real_T c15_u[3];
  const mxArray *c15_y = NULL;
  SFc15_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc15_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i19 = 0; c15_i19 < 3; c15_i19++) {
    c15_b_inData[c15_i19] = (*(real_T (*)[3])c15_inData)[c15_i19];
  }

  for (c15_i20 = 0; c15_i20 < 3; c15_i20++) {
    c15_u[c15_i20] = c15_b_inData[c15_i20];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static void c15_c_emlrt_marshallIn(SFc15_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[3])
{
  real_T c15_dv1[3];
  int32_T c15_i21;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c15_i21 = 0; c15_i21 < 3; c15_i21++) {
    c15_y[c15_i21] = c15_dv1[c15_i21];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_M;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y[3];
  int32_T c15_i22;
  SFc15_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc15_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c15_M = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_M), &c15_thisId, c15_y);
  sf_mex_destroy(&c15_M);
  for (c15_i22 = 0; c15_i22 < 3; c15_i22++) {
    (*(real_T (*)[3])c15_outData)[c15_i22] = c15_y[c15_i22];
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i23;
  int32_T c15_i24;
  int32_T c15_i25;
  real_T c15_b_inData[9];
  int32_T c15_i26;
  int32_T c15_i27;
  int32_T c15_i28;
  real_T c15_u[9];
  const mxArray *c15_y = NULL;
  SFc15_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc15_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_i23 = 0;
  for (c15_i24 = 0; c15_i24 < 3; c15_i24++) {
    for (c15_i25 = 0; c15_i25 < 3; c15_i25++) {
      c15_b_inData[c15_i25 + c15_i23] = (*(real_T (*)[9])c15_inData)[c15_i25 +
        c15_i23];
    }

    c15_i23 += 3;
  }

  c15_i26 = 0;
  for (c15_i27 = 0; c15_i27 < 3; c15_i27++) {
    for (c15_i28 = 0; c15_i28 < 3; c15_i28++) {
      c15_u[c15_i28 + c15_i26] = c15_b_inData[c15_i28 + c15_i26];
    }

    c15_i26 += 3;
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_rotationMatrix;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y[9];
  int32_T c15_i29;
  int32_T c15_i30;
  int32_T c15_i31;
  SFc15_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc15_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c15_rotationMatrix = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_rotationMatrix),
    &c15_thisId, c15_y);
  sf_mex_destroy(&c15_rotationMatrix);
  c15_i29 = 0;
  for (c15_i30 = 0; c15_i30 < 3; c15_i30++) {
    for (c15_i31 = 0; c15_i31 < 3; c15_i31++) {
      (*(real_T (*)[9])c15_outData)[c15_i31 + c15_i29] = c15_y[c15_i31 + c15_i29];
    }

    c15_i29 += 3;
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

const mxArray *sf_c15_lab2_next_level_get_eml_resolved_functions_info(void)
{
  const mxArray *c15_nameCaptureInfo;
  c15_ResolvedFunctionInfo c15_info[9];
  c15_ResolvedFunctionInfo (*c15_b_info)[9];
  const mxArray *c15_m0 = NULL;
  int32_T c15_i32;
  c15_ResolvedFunctionInfo *c15_r0;
  c15_nameCaptureInfo = NULL;
  c15_nameCaptureInfo = NULL;
  c15_b_info = (c15_ResolvedFunctionInfo (*)[9])c15_info;
  (*c15_b_info)[0].context = "";
  (*c15_b_info)[0].name = "mtimes";
  (*c15_b_info)[0].dominantType = "double";
  (*c15_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c15_b_info)[0].fileTimeLo = 1289508892U;
  (*c15_b_info)[0].fileTimeHi = 0U;
  (*c15_b_info)[0].mFileTimeLo = 0U;
  (*c15_b_info)[0].mFileTimeHi = 0U;
  (*c15_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c15_b_info)[1].name = "eml_index_class";
  (*c15_b_info)[1].dominantType = "";
  (*c15_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c15_b_info)[1].fileTimeLo = 1323159778U;
  (*c15_b_info)[1].fileTimeHi = 0U;
  (*c15_b_info)[1].mFileTimeLo = 0U;
  (*c15_b_info)[1].mFileTimeHi = 0U;
  (*c15_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c15_b_info)[2].name = "eml_scalar_eg";
  (*c15_b_info)[2].dominantType = "double";
  (*c15_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c15_b_info)[2].fileTimeLo = 1286811596U;
  (*c15_b_info)[2].fileTimeHi = 0U;
  (*c15_b_info)[2].mFileTimeLo = 0U;
  (*c15_b_info)[2].mFileTimeHi = 0U;
  (*c15_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c15_b_info)[3].name = "eml_xgemm";
  (*c15_b_info)[3].dominantType = "char";
  (*c15_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c15_b_info)[3].fileTimeLo = 1299065972U;
  (*c15_b_info)[3].fileTimeHi = 0U;
  (*c15_b_info)[3].mFileTimeLo = 0U;
  (*c15_b_info)[3].mFileTimeHi = 0U;
  (*c15_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c15_b_info)[4].name = "eml_blas_inline";
  (*c15_b_info)[4].dominantType = "";
  (*c15_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  (*c15_b_info)[4].fileTimeLo = 1299065968U;
  (*c15_b_info)[4].fileTimeHi = 0U;
  (*c15_b_info)[4].mFileTimeLo = 0U;
  (*c15_b_info)[4].mFileTimeHi = 0U;
  (*c15_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  (*c15_b_info)[5].name = "mtimes";
  (*c15_b_info)[5].dominantType = "double";
  (*c15_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c15_b_info)[5].fileTimeLo = 1289508892U;
  (*c15_b_info)[5].fileTimeHi = 0U;
  (*c15_b_info)[5].mFileTimeLo = 0U;
  (*c15_b_info)[5].mFileTimeHi = 0U;
  (*c15_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c15_b_info)[6].name = "eml_index_class";
  (*c15_b_info)[6].dominantType = "";
  (*c15_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c15_b_info)[6].fileTimeLo = 1323159778U;
  (*c15_b_info)[6].fileTimeHi = 0U;
  (*c15_b_info)[6].mFileTimeLo = 0U;
  (*c15_b_info)[6].mFileTimeHi = 0U;
  (*c15_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c15_b_info)[7].name = "eml_scalar_eg";
  (*c15_b_info)[7].dominantType = "double";
  (*c15_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c15_b_info)[7].fileTimeLo = 1286811596U;
  (*c15_b_info)[7].fileTimeHi = 0U;
  (*c15_b_info)[7].mFileTimeLo = 0U;
  (*c15_b_info)[7].mFileTimeHi = 0U;
  (*c15_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c15_b_info)[8].name = "eml_refblas_xgemm";
  (*c15_b_info)[8].dominantType = "char";
  (*c15_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c15_b_info)[8].fileTimeLo = 1299065974U;
  (*c15_b_info)[8].fileTimeHi = 0U;
  (*c15_b_info)[8].mFileTimeLo = 0U;
  (*c15_b_info)[8].mFileTimeHi = 0U;
  sf_mex_assign(&c15_m0, sf_mex_createstruct("nameCaptureInfo", 1, 9), FALSE);
  for (c15_i32 = 0; c15_i32 < 9; c15_i32++) {
    c15_r0 = &c15_info[c15_i32];
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", c15_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c15_r0->context)), "context", "nameCaptureInfo",
                    c15_i32);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", c15_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c15_r0->name)), "name", "nameCaptureInfo",
                    c15_i32);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo",
      c15_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c15_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c15_i32);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", c15_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c15_r0->resolved)), "resolved",
                    "nameCaptureInfo", c15_i32);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", &c15_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c15_i32);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", &c15_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c15_i32);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo",
      &c15_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c15_i32);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo",
      &c15_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c15_i32);
  }

  sf_mex_assign(&c15_nameCaptureInfo, c15_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c15_nameCaptureInfo);
  return c15_nameCaptureInfo;
}

static void c15_eml_scalar_eg(SFc15_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void c15_d_emlrt_marshallIn(SFc15_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c15_rotationMatrix, const char_T
  *c15_identifier, real_T c15_y[9])
{
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_rotationMatrix),
    &c15_thisId, c15_y);
  sf_mex_destroy(&c15_rotationMatrix);
}

static void c15_e_emlrt_marshallIn(SFc15_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[9])
{
  real_T c15_dv2[9];
  int32_T c15_i33;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv2, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c15_i33 = 0; c15_i33 < 9; c15_i33++) {
    c15_y[c15_i33] = c15_dv2[c15_i33];
  }

  sf_mex_destroy(&c15_u);
}

static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc15_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(int32_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static int32_T c15_f_emlrt_marshallIn(SFc15_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  int32_T c15_y;
  int32_T c15_i34;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_i34, 1, 6, 0U, 0, 0U, 0);
  c15_y = c15_i34;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_sfEvent;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  int32_T c15_y;
  SFc15_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc15_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c15_sfEvent = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_sfEvent),
    &c15_thisId);
  sf_mex_destroy(&c15_sfEvent);
  *(int32_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static uint8_T c15_g_emlrt_marshallIn(SFc15_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c15_is_active_c15_lab2_next_level, const char_T
  *c15_identifier)
{
  uint8_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_is_active_c15_lab2_next_level), &c15_thisId);
  sf_mex_destroy(&c15_is_active_c15_lab2_next_level);
  return c15_y;
}

static uint8_T c15_h_emlrt_marshallIn(SFc15_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  uint8_T c15_y;
  uint8_T c15_u0;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_u0, 1, 3, 0U, 0, 0U, 0);
  c15_y = c15_u0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void init_dsm_address_info(SFc15_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c15_lab2_next_level_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1786295294U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1909421055U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1443661428U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3307325561U);
}

mxArray *sf_c15_lab2_next_level_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("WN7Y08Cew1uRTKAttGwzpG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c15_lab2_next_level(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[10],T\"xs\",},{M[1],M[11],T\"ys\",},{M[1],M[12],T\"zs\",},{M[8],M[0],T\"is_active_c15_lab2_next_level\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c15_lab2_next_level_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc15_lab2_next_levelInstanceStruct *chartInstance;
    chartInstance = (SFc15_lab2_next_levelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_lab2_next_levelMachineNumber_,
           15,
           1,
           1,
           5,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"angles");
          _SFD_SET_DATA_PROPS(1,1,1,0,"accel");
          _SFD_SET_DATA_PROPS(2,2,0,1,"xs");
          _SFD_SET_DATA_PROPS(3,2,0,1,"ys");
          _SFD_SET_DATA_PROPS(4,2,0,1,"zs");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,352);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c15_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c15_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)c15_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)c15_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)c15_sf_marshallIn);

        {
          real_T *c15_xs;
          real_T *c15_ys;
          real_T *c15_zs;
          real_T (*c15_angles)[3];
          real_T (*c15_accel)[3];
          c15_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c15_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c15_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c15_accel = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c15_angles = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c15_angles);
          _SFD_SET_DATA_VALUE_PTR(1U, *c15_accel);
          _SFD_SET_DATA_VALUE_PTR(2U, c15_xs);
          _SFD_SET_DATA_VALUE_PTR(3U, c15_ys);
          _SFD_SET_DATA_VALUE_PTR(4U, c15_zs);
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
  return "rjGLt8apbbdIPjqgtOa4OF";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 15, "dworkChecksum");
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

static void sf_opaque_initialize_c15_lab2_next_level(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc15_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc15_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c15_lab2_next_level((SFc15_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
  initialize_c15_lab2_next_level((SFc15_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c15_lab2_next_level(void *chartInstanceVar)
{
  enable_c15_lab2_next_level((SFc15_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c15_lab2_next_level(void *chartInstanceVar)
{
  disable_c15_lab2_next_level((SFc15_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c15_lab2_next_level(void *chartInstanceVar)
{
  sf_c15_lab2_next_level((SFc15_lab2_next_levelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c15_lab2_next_level(void *chartInstanceVar)
{
  ext_mode_exec_c15_lab2_next_level((SFc15_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c15_lab2_next_level(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c15_lab2_next_level
    ((SFc15_lab2_next_levelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c15_lab2_next_level();/* state var info */
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

extern void sf_internal_set_sim_state_c15_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c15_lab2_next_level();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c15_lab2_next_level((SFc15_lab2_next_levelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c15_lab2_next_level(SimStruct* S)
{
  return sf_internal_get_sim_state_c15_lab2_next_level(S);
}

static void sf_opaque_set_sim_state_c15_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c15_lab2_next_level(S, st);
}

static void sf_opaque_terminate_c15_lab2_next_level(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc15_lab2_next_levelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c15_lab2_next_level((SFc15_lab2_next_levelInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_lab2_next_level_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc15_lab2_next_level((SFc15_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c15_lab2_next_level(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c15_lab2_next_level((SFc15_lab2_next_levelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c15_lab2_next_level_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c15_lab2_next_level\",T\"is_active_c15_lab2_next_level\"}}"
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

static void mdlSetWorkWidths_c15_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      15);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,15,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,15,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,15,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,15,3);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,15);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2293832894U));
  ssSetChecksum1(S,(3071480954U));
  ssSetChecksum2(S,(105403781U));
  ssSetChecksum3(S,(2976814619U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c15_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c15_lab2_next_level(SimStruct *S)
{
  SFc15_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc15_lab2_next_levelInstanceStruct *)malloc(sizeof
    (SFc15_lab2_next_levelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc15_lab2_next_levelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c15_lab2_next_level;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c15_lab2_next_level;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c15_lab2_next_level;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c15_lab2_next_level;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c15_lab2_next_level;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c15_lab2_next_level;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c15_lab2_next_level;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c15_lab2_next_level;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c15_lab2_next_level;
  chartInstance->chartInfo.mdlStart = mdlStart_c15_lab2_next_level;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c15_lab2_next_level;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c15_lab2_next_level;
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

void c15_lab2_next_level_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c15_lab2_next_level(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c15_lab2_next_level(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c15_lab2_next_level(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c15_lab2_next_level_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
