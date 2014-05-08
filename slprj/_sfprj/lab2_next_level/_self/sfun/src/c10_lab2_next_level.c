/* Include files */

#include "blascompat32.h"
#include "lab2_next_level_sfun.h"
#include "c10_lab2_next_level.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lab2_next_level_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c10_debug_family_names[12] = { "M", "nargin", "nargout",
  "roll", "pitch", "yaw", "x", "y", "z", "xs", "ys", "zs" };

/* Function Declarations */
static void initialize_c10_lab2_next_level(SFc10_lab2_next_levelInstanceStruct
  *chartInstance);
static void initialize_params_c10_lab2_next_level
  (SFc10_lab2_next_levelInstanceStruct *chartInstance);
static void enable_c10_lab2_next_level(SFc10_lab2_next_levelInstanceStruct
  *chartInstance);
static void disable_c10_lab2_next_level(SFc10_lab2_next_levelInstanceStruct
  *chartInstance);
static void c10_update_debugger_state_c10_lab2_next_level
  (SFc10_lab2_next_levelInstanceStruct *chartInstance);
static void ext_mode_exec_c10_lab2_next_level
  (SFc10_lab2_next_levelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_lab2_next_level
  (SFc10_lab2_next_levelInstanceStruct *chartInstance);
static void set_sim_state_c10_lab2_next_level
  (SFc10_lab2_next_levelInstanceStruct *chartInstance, const mxArray *c10_st);
static void finalize_c10_lab2_next_level(SFc10_lab2_next_levelInstanceStruct
  *chartInstance);
static void sf_c10_lab2_next_level(SFc10_lab2_next_levelInstanceStruct
  *chartInstance);
static void c10_chartstep_c10_lab2_next_level
  (SFc10_lab2_next_levelInstanceStruct *chartInstance);
static void initSimStructsc10_lab2_next_level
  (SFc10_lab2_next_levelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber);
static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static real_T c10_emlrt_marshallIn(SFc10_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c10_zs, const char_T *c10_identifier);
static real_T c10_b_emlrt_marshallIn(SFc10_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_c_emlrt_marshallIn(SFc10_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[3]);
static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static void c10_eml_scalar_eg(SFc10_lab2_next_levelInstanceStruct *chartInstance);
static void c10_d_emlrt_marshallIn(SFc10_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c10_rotationMatrix, const char_T
  *c10_identifier, real_T c10_y[9]);
static void c10_e_emlrt_marshallIn(SFc10_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[9]);
static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int32_T c10_f_emlrt_marshallIn(SFc10_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static uint8_T c10_g_emlrt_marshallIn(SFc10_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c10_is_active_c10_lab2_next_level, const char_T
  *c10_identifier);
static uint8_T c10_h_emlrt_marshallIn(SFc10_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void init_dsm_address_info(SFc10_lab2_next_levelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c10_lab2_next_level(SFc10_lab2_next_levelInstanceStruct
  *chartInstance)
{
  int32_T *c10_sfEvent;
  uint8_T *c10_is_active_c10_lab2_next_level;
  c10_is_active_c10_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c10_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c10_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c10_is_active_c10_lab2_next_level = 0U;
}

static void initialize_params_c10_lab2_next_level
  (SFc10_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void enable_c10_lab2_next_level(SFc10_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c10_lab2_next_level(SFc10_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c10_update_debugger_state_c10_lab2_next_level
  (SFc10_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c10_lab2_next_level
  (SFc10_lab2_next_levelInstanceStruct *chartInstance)
{
  c10_update_debugger_state_c10_lab2_next_level(chartInstance);
}

static const mxArray *get_sim_state_c10_lab2_next_level
  (SFc10_lab2_next_levelInstanceStruct *chartInstance)
{
  const mxArray *c10_st;
  const mxArray *c10_y = NULL;
  real_T c10_hoistedGlobal;
  real_T c10_u;
  const mxArray *c10_b_y = NULL;
  real_T c10_b_hoistedGlobal;
  real_T c10_b_u;
  const mxArray *c10_c_y = NULL;
  real_T c10_c_hoistedGlobal;
  real_T c10_c_u;
  const mxArray *c10_d_y = NULL;
  uint8_T c10_d_hoistedGlobal;
  uint8_T c10_d_u;
  const mxArray *c10_e_y = NULL;
  real_T *c10_xs;
  real_T *c10_ys;
  real_T *c10_zs;
  uint8_T *c10_is_active_c10_lab2_next_level;
  c10_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c10_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c10_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c10_is_active_c10_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c10_st = NULL;
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellarray(4), FALSE);
  c10_hoistedGlobal = *c10_xs;
  c10_u = c10_hoistedGlobal;
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_b_hoistedGlobal = *c10_ys;
  c10_b_u = c10_b_hoistedGlobal;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 1, c10_c_y);
  c10_c_hoistedGlobal = *c10_zs;
  c10_c_u = c10_c_hoistedGlobal;
  c10_d_y = NULL;
  sf_mex_assign(&c10_d_y, sf_mex_create("y", &c10_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 2, c10_d_y);
  c10_d_hoistedGlobal = *c10_is_active_c10_lab2_next_level;
  c10_d_u = c10_d_hoistedGlobal;
  c10_e_y = NULL;
  sf_mex_assign(&c10_e_y, sf_mex_create("y", &c10_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 3, c10_e_y);
  sf_mex_assign(&c10_st, c10_y, FALSE);
  return c10_st;
}

static void set_sim_state_c10_lab2_next_level
  (SFc10_lab2_next_levelInstanceStruct *chartInstance, const mxArray *c10_st)
{
  const mxArray *c10_u;
  boolean_T *c10_doneDoubleBufferReInit;
  real_T *c10_xs;
  real_T *c10_ys;
  real_T *c10_zs;
  uint8_T *c10_is_active_c10_lab2_next_level;
  c10_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c10_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c10_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c10_is_active_c10_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c10_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c10_doneDoubleBufferReInit = TRUE;
  c10_u = sf_mex_dup(c10_st);
  *c10_xs = c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u,
    0)), "xs");
  *c10_ys = c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u,
    1)), "ys");
  *c10_zs = c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u,
    2)), "zs");
  *c10_is_active_c10_lab2_next_level = c10_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c10_u, 3)), "is_active_c10_lab2_next_level");
  sf_mex_destroy(&c10_u);
  c10_update_debugger_state_c10_lab2_next_level(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_lab2_next_level(SFc10_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

static void sf_c10_lab2_next_level(SFc10_lab2_next_levelInstanceStruct
  *chartInstance)
{
  int32_T *c10_sfEvent;
  real_T *c10_roll;
  real_T *c10_pitch;
  real_T *c10_yaw;
  real_T *c10_x;
  real_T *c10_y;
  real_T *c10_z;
  real_T *c10_xs;
  real_T *c10_ys;
  real_T *c10_zs;
  c10_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c10_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c10_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c10_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c10_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c10_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c10_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c10_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c10_roll = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c10_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, *c10_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c10_roll, 0U);
  _SFD_DATA_RANGE_CHECK(*c10_pitch, 1U);
  _SFD_DATA_RANGE_CHECK(*c10_yaw, 2U);
  _SFD_DATA_RANGE_CHECK(*c10_x, 3U);
  _SFD_DATA_RANGE_CHECK(*c10_y, 4U);
  _SFD_DATA_RANGE_CHECK(*c10_z, 5U);
  _SFD_DATA_RANGE_CHECK(*c10_xs, 6U);
  _SFD_DATA_RANGE_CHECK(*c10_ys, 7U);
  _SFD_DATA_RANGE_CHECK(*c10_zs, 8U);
  *c10_sfEvent = CALL_EVENT;
  c10_chartstep_c10_lab2_next_level(chartInstance);
  sf_debug_check_for_state_inconsistency(_lab2_next_levelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c10_chartstep_c10_lab2_next_level
  (SFc10_lab2_next_levelInstanceStruct *chartInstance)
{
  real_T c10_hoistedGlobal;
  real_T c10_b_hoistedGlobal;
  real_T c10_c_hoistedGlobal;
  real_T c10_d_hoistedGlobal;
  real_T c10_e_hoistedGlobal;
  real_T c10_f_hoistedGlobal;
  real_T c10_roll;
  real_T c10_pitch;
  real_T c10_yaw;
  real_T c10_x;
  real_T c10_y;
  real_T c10_z;
  uint32_T c10_debug_family_var_map[12];
  real_T c10_M[9];
  real_T c10_b_M[3];
  real_T c10_nargin = 6.0;
  real_T c10_nargout = 3.0;
  real_T c10_xs;
  real_T c10_ys;
  real_T c10_zs;
  int32_T c10_i0;
  real_T c10_u;
  const mxArray *c10_b_y = NULL;
  real_T c10_b_u;
  const mxArray *c10_c_y = NULL;
  real_T c10_c_u;
  const mxArray *c10_d_y = NULL;
  real_T c10_dv0[9];
  int32_T c10_i1;
  int32_T c10_i2;
  real_T c10_a[9];
  real_T c10_b[3];
  int32_T c10_i3;
  int32_T c10_i4;
  int32_T c10_i5;
  real_T c10_C[3];
  int32_T c10_i6;
  int32_T c10_i7;
  int32_T c10_i8;
  int32_T c10_i9;
  int32_T c10_i10;
  int32_T c10_i11;
  real_T *c10_b_roll;
  real_T *c10_b_pitch;
  real_T *c10_b_yaw;
  real_T *c10_b_x;
  real_T *c10_e_y;
  real_T *c10_b_z;
  real_T *c10_b_xs;
  real_T *c10_b_ys;
  real_T *c10_b_zs;
  int32_T *c10_sfEvent;
  c10_b_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c10_b_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c10_b_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c10_b_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c10_e_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c10_b_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c10_b_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c10_b_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c10_b_roll = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c10_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, *c10_sfEvent);
  c10_hoistedGlobal = *c10_b_roll;
  c10_b_hoistedGlobal = *c10_b_pitch;
  c10_c_hoistedGlobal = *c10_b_yaw;
  c10_d_hoistedGlobal = *c10_b_x;
  c10_e_hoistedGlobal = *c10_e_y;
  c10_f_hoistedGlobal = *c10_b_z;
  c10_roll = c10_hoistedGlobal;
  c10_pitch = c10_b_hoistedGlobal;
  c10_yaw = c10_c_hoistedGlobal;
  c10_x = c10_d_hoistedGlobal;
  c10_y = c10_e_hoistedGlobal;
  c10_z = c10_f_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 12U, 13U, c10_debug_family_names,
    c10_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c10_M, MAX_uint32_T,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c10_b_M, MAX_uint32_T,
    c10_b_sf_marshallOut, c10_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c10_nargin, 1U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c10_nargout, 2U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c10_roll, 3U, c10_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c10_pitch, 4U, c10_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c10_yaw, 5U, c10_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c10_x, 6U, c10_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c10_y, 7U, c10_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c10_z, 8U, c10_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c10_xs, 9U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c10_ys, 10U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c10_zs, 11U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c10_sfEvent, 5);
  _SFD_EML_CALL(0U, *c10_sfEvent, 7);
  for (c10_i0 = 0; c10_i0 < 9; c10_i0++) {
    c10_M[c10_i0] = 0.0;
  }

  sf_debug_symbol_switch(0U, 0U);
  _SFD_EML_CALL(0U, *c10_sfEvent, 8);
  c10_u = c10_roll;
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), FALSE);
  c10_b_u = c10_pitch;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  c10_c_u = c10_yaw;
  c10_d_y = NULL;
  sf_mex_assign(&c10_d_y, sf_mex_create("y", &c10_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  c10_d_emlrt_marshallIn(chartInstance, sf_mex_call_debug("rotationMatrix", 1U,
    3U, 14, c10_b_y, 14, c10_c_y, 14, c10_d_y), "rotationMatrix", c10_dv0);
  for (c10_i1 = 0; c10_i1 < 9; c10_i1++) {
    c10_M[c10_i1] = c10_dv0[c10_i1];
  }

  sf_debug_symbol_switch(0U, 0U);
  _SFD_EML_CALL(0U, *c10_sfEvent, 9);
  for (c10_i2 = 0; c10_i2 < 9; c10_i2++) {
    c10_a[c10_i2] = c10_M[c10_i2];
  }

  c10_b[0] = c10_x;
  c10_b[1] = c10_y;
  c10_b[2] = c10_z;
  c10_eml_scalar_eg(chartInstance);
  c10_eml_scalar_eg(chartInstance);
  for (c10_i3 = 0; c10_i3 < 3; c10_i3++) {
    c10_b_M[c10_i3] = 0.0;
  }

  for (c10_i4 = 0; c10_i4 < 3; c10_i4++) {
    c10_b_M[c10_i4] = 0.0;
  }

  for (c10_i5 = 0; c10_i5 < 3; c10_i5++) {
    c10_C[c10_i5] = c10_b_M[c10_i5];
  }

  for (c10_i6 = 0; c10_i6 < 3; c10_i6++) {
    c10_b_M[c10_i6] = c10_C[c10_i6];
  }

  for (c10_i7 = 0; c10_i7 < 3; c10_i7++) {
    c10_C[c10_i7] = c10_b_M[c10_i7];
  }

  for (c10_i8 = 0; c10_i8 < 3; c10_i8++) {
    c10_b_M[c10_i8] = c10_C[c10_i8];
  }

  for (c10_i9 = 0; c10_i9 < 3; c10_i9++) {
    c10_b_M[c10_i9] = 0.0;
    c10_i10 = 0;
    for (c10_i11 = 0; c10_i11 < 3; c10_i11++) {
      c10_b_M[c10_i9] += c10_a[c10_i10 + c10_i9] * c10_b[c10_i11];
      c10_i10 += 3;
    }
  }

  sf_debug_symbol_switch(0U, 1U);
  _SFD_EML_CALL(0U, *c10_sfEvent, 11);
  c10_xs = c10_b_M[0];
  _SFD_EML_CALL(0U, *c10_sfEvent, 12);
  c10_ys = c10_b_M[1];
  _SFD_EML_CALL(0U, *c10_sfEvent, 13);
  c10_zs = c10_b_M[2];
  _SFD_EML_CALL(0U, *c10_sfEvent, -13);
  sf_debug_symbol_scope_pop();
  *c10_b_xs = c10_xs;
  *c10_b_ys = c10_ys;
  *c10_b_zs = c10_zs;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, *c10_sfEvent);
}

static void initSimStructsc10_lab2_next_level
  (SFc10_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber)
{
}

static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  real_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc10_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(real_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static real_T c10_emlrt_marshallIn(SFc10_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c10_zs, const char_T *c10_identifier)
{
  real_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_zs), &c10_thisId);
  sf_mex_destroy(&c10_zs);
  return c10_y;
}

static real_T c10_b_emlrt_marshallIn(SFc10_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  real_T c10_y;
  real_T c10_d0;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_d0, 1, 0, 0U, 0, 0U, 0);
  c10_y = c10_d0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_zs;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y;
  SFc10_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc10_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c10_zs = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_zs), &c10_thisId);
  sf_mex_destroy(&c10_zs);
  *(real_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i12;
  real_T c10_b_inData[3];
  int32_T c10_i13;
  real_T c10_u[3];
  const mxArray *c10_y = NULL;
  SFc10_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc10_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i12 = 0; c10_i12 < 3; c10_i12++) {
    c10_b_inData[c10_i12] = (*(real_T (*)[3])c10_inData)[c10_i12];
  }

  for (c10_i13 = 0; c10_i13 < 3; c10_i13++) {
    c10_u[c10_i13] = c10_b_inData[c10_i13];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static void c10_c_emlrt_marshallIn(SFc10_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[3])
{
  real_T c10_dv1[3];
  int32_T c10_i14;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c10_i14 = 0; c10_i14 < 3; c10_i14++) {
    c10_y[c10_i14] = c10_dv1[c10_i14];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_M;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[3];
  int32_T c10_i15;
  SFc10_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc10_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c10_M = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_M), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_M);
  for (c10_i15 = 0; c10_i15 < 3; c10_i15++) {
    (*(real_T (*)[3])c10_outData)[c10_i15] = c10_y[c10_i15];
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i16;
  int32_T c10_i17;
  int32_T c10_i18;
  real_T c10_b_inData[9];
  int32_T c10_i19;
  int32_T c10_i20;
  int32_T c10_i21;
  real_T c10_u[9];
  const mxArray *c10_y = NULL;
  SFc10_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc10_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_i16 = 0;
  for (c10_i17 = 0; c10_i17 < 3; c10_i17++) {
    for (c10_i18 = 0; c10_i18 < 3; c10_i18++) {
      c10_b_inData[c10_i18 + c10_i16] = (*(real_T (*)[9])c10_inData)[c10_i18 +
        c10_i16];
    }

    c10_i16 += 3;
  }

  c10_i19 = 0;
  for (c10_i20 = 0; c10_i20 < 3; c10_i20++) {
    for (c10_i21 = 0; c10_i21 < 3; c10_i21++) {
      c10_u[c10_i21 + c10_i19] = c10_b_inData[c10_i21 + c10_i19];
    }

    c10_i19 += 3;
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_rotationMatrix;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[9];
  int32_T c10_i22;
  int32_T c10_i23;
  int32_T c10_i24;
  SFc10_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc10_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c10_rotationMatrix = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_rotationMatrix),
    &c10_thisId, c10_y);
  sf_mex_destroy(&c10_rotationMatrix);
  c10_i22 = 0;
  for (c10_i23 = 0; c10_i23 < 3; c10_i23++) {
    for (c10_i24 = 0; c10_i24 < 3; c10_i24++) {
      (*(real_T (*)[9])c10_outData)[c10_i24 + c10_i22] = c10_y[c10_i24 + c10_i22];
    }

    c10_i22 += 3;
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

const mxArray *sf_c10_lab2_next_level_get_eml_resolved_functions_info(void)
{
  const mxArray *c10_nameCaptureInfo;
  c10_ResolvedFunctionInfo c10_info[9];
  c10_ResolvedFunctionInfo (*c10_b_info)[9];
  const mxArray *c10_m0 = NULL;
  int32_T c10_i25;
  c10_ResolvedFunctionInfo *c10_r0;
  c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  c10_b_info = (c10_ResolvedFunctionInfo (*)[9])c10_info;
  (*c10_b_info)[0].context = "";
  (*c10_b_info)[0].name = "mtimes";
  (*c10_b_info)[0].dominantType = "double";
  (*c10_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c10_b_info)[0].fileTimeLo = 1289508892U;
  (*c10_b_info)[0].fileTimeHi = 0U;
  (*c10_b_info)[0].mFileTimeLo = 0U;
  (*c10_b_info)[0].mFileTimeHi = 0U;
  (*c10_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c10_b_info)[1].name = "eml_index_class";
  (*c10_b_info)[1].dominantType = "";
  (*c10_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c10_b_info)[1].fileTimeLo = 1323159778U;
  (*c10_b_info)[1].fileTimeHi = 0U;
  (*c10_b_info)[1].mFileTimeLo = 0U;
  (*c10_b_info)[1].mFileTimeHi = 0U;
  (*c10_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c10_b_info)[2].name = "eml_scalar_eg";
  (*c10_b_info)[2].dominantType = "double";
  (*c10_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c10_b_info)[2].fileTimeLo = 1286811596U;
  (*c10_b_info)[2].fileTimeHi = 0U;
  (*c10_b_info)[2].mFileTimeLo = 0U;
  (*c10_b_info)[2].mFileTimeHi = 0U;
  (*c10_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c10_b_info)[3].name = "eml_xgemm";
  (*c10_b_info)[3].dominantType = "char";
  (*c10_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c10_b_info)[3].fileTimeLo = 1299065972U;
  (*c10_b_info)[3].fileTimeHi = 0U;
  (*c10_b_info)[3].mFileTimeLo = 0U;
  (*c10_b_info)[3].mFileTimeHi = 0U;
  (*c10_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c10_b_info)[4].name = "eml_blas_inline";
  (*c10_b_info)[4].dominantType = "";
  (*c10_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  (*c10_b_info)[4].fileTimeLo = 1299065968U;
  (*c10_b_info)[4].fileTimeHi = 0U;
  (*c10_b_info)[4].mFileTimeLo = 0U;
  (*c10_b_info)[4].mFileTimeHi = 0U;
  (*c10_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  (*c10_b_info)[5].name = "mtimes";
  (*c10_b_info)[5].dominantType = "double";
  (*c10_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c10_b_info)[5].fileTimeLo = 1289508892U;
  (*c10_b_info)[5].fileTimeHi = 0U;
  (*c10_b_info)[5].mFileTimeLo = 0U;
  (*c10_b_info)[5].mFileTimeHi = 0U;
  (*c10_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c10_b_info)[6].name = "eml_index_class";
  (*c10_b_info)[6].dominantType = "";
  (*c10_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c10_b_info)[6].fileTimeLo = 1323159778U;
  (*c10_b_info)[6].fileTimeHi = 0U;
  (*c10_b_info)[6].mFileTimeLo = 0U;
  (*c10_b_info)[6].mFileTimeHi = 0U;
  (*c10_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c10_b_info)[7].name = "eml_scalar_eg";
  (*c10_b_info)[7].dominantType = "double";
  (*c10_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c10_b_info)[7].fileTimeLo = 1286811596U;
  (*c10_b_info)[7].fileTimeHi = 0U;
  (*c10_b_info)[7].mFileTimeLo = 0U;
  (*c10_b_info)[7].mFileTimeHi = 0U;
  (*c10_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c10_b_info)[8].name = "eml_refblas_xgemm";
  (*c10_b_info)[8].dominantType = "char";
  (*c10_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c10_b_info)[8].fileTimeLo = 1299065974U;
  (*c10_b_info)[8].fileTimeHi = 0U;
  (*c10_b_info)[8].mFileTimeLo = 0U;
  (*c10_b_info)[8].mFileTimeHi = 0U;
  sf_mex_assign(&c10_m0, sf_mex_createstruct("nameCaptureInfo", 1, 9), FALSE);
  for (c10_i25 = 0; c10_i25 < 9; c10_i25++) {
    c10_r0 = &c10_info[c10_i25];
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->context)), "context", "nameCaptureInfo",
                    c10_i25);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->name)), "name", "nameCaptureInfo",
                    c10_i25);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      c10_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c10_i25);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->resolved)), "resolved",
                    "nameCaptureInfo", c10_i25);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c10_i25);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c10_i25);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      &c10_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c10_i25);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      &c10_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c10_i25);
  }

  sf_mex_assign(&c10_nameCaptureInfo, c10_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c10_nameCaptureInfo);
  return c10_nameCaptureInfo;
}

static void c10_eml_scalar_eg(SFc10_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void c10_d_emlrt_marshallIn(SFc10_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c10_rotationMatrix, const char_T
  *c10_identifier, real_T c10_y[9])
{
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_rotationMatrix),
    &c10_thisId, c10_y);
  sf_mex_destroy(&c10_rotationMatrix);
}

static void c10_e_emlrt_marshallIn(SFc10_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[9])
{
  real_T c10_dv2[9];
  int32_T c10_i26;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv2, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c10_i26 = 0; c10_i26 < 9; c10_i26++) {
    c10_y[c10_i26] = c10_dv2[c10_i26];
  }

  sf_mex_destroy(&c10_u);
}

static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc10_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int32_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static int32_T c10_f_emlrt_marshallIn(SFc10_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int32_T c10_y;
  int32_T c10_i27;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i27, 1, 6, 0U, 0, 0U, 0);
  c10_y = c10_i27;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_sfEvent;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int32_T c10_y;
  SFc10_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc10_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c10_sfEvent = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_sfEvent),
    &c10_thisId);
  sf_mex_destroy(&c10_sfEvent);
  *(int32_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static uint8_T c10_g_emlrt_marshallIn(SFc10_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c10_is_active_c10_lab2_next_level, const char_T
  *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_is_active_c10_lab2_next_level), &c10_thisId);
  sf_mex_destroy(&c10_is_active_c10_lab2_next_level);
  return c10_y;
}

static uint8_T c10_h_emlrt_marshallIn(SFc10_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u0, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void init_dsm_address_info(SFc10_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c10_lab2_next_level_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2481080415U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2516961254U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3909822235U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2787576488U);
}

mxArray *sf_c10_lab2_next_level_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("JheO9KrW5VBJhWBgEgKDxF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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

static const mxArray *sf_get_sim_state_info_c10_lab2_next_level(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[10],T\"xs\",},{M[1],M[11],T\"ys\",},{M[1],M[12],T\"zs\",},{M[8],M[0],T\"is_active_c10_lab2_next_level\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_lab2_next_level_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_lab2_next_levelInstanceStruct *chartInstance;
    chartInstance = (SFc10_lab2_next_levelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_lab2_next_levelMachineNumber_,
           10,
           1,
           1,
           9,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"roll");
          _SFD_SET_DATA_PROPS(1,1,1,0,"pitch");
          _SFD_SET_DATA_PROPS(2,1,1,0,"yaw");
          _SFD_SET_DATA_PROPS(3,1,1,0,"x");
          _SFD_SET_DATA_PROPS(4,1,1,0,"y");
          _SFD_SET_DATA_PROPS(5,1,1,0,"z");
          _SFD_SET_DATA_PROPS(6,2,0,1,"xs");
          _SFD_SET_DATA_PROPS(7,2,0,1,"ys");
          _SFD_SET_DATA_PROPS(8,2,0,1,"zs");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,265);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)c10_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)c10_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)c10_sf_marshallIn);

        {
          real_T *c10_roll;
          real_T *c10_pitch;
          real_T *c10_yaw;
          real_T *c10_x;
          real_T *c10_y;
          real_T *c10_z;
          real_T *c10_xs;
          real_T *c10_ys;
          real_T *c10_zs;
          c10_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c10_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c10_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c10_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c10_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c10_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c10_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c10_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c10_roll = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c10_roll);
          _SFD_SET_DATA_VALUE_PTR(1U, c10_pitch);
          _SFD_SET_DATA_VALUE_PTR(2U, c10_yaw);
          _SFD_SET_DATA_VALUE_PTR(3U, c10_x);
          _SFD_SET_DATA_VALUE_PTR(4U, c10_y);
          _SFD_SET_DATA_VALUE_PTR(5U, c10_z);
          _SFD_SET_DATA_VALUE_PTR(6U, c10_xs);
          _SFD_SET_DATA_VALUE_PTR(7U, c10_ys);
          _SFD_SET_DATA_VALUE_PTR(8U, c10_zs);
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
  return "S0XB7oGev3JDlWYZIVEjrF";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 10, "dworkChecksum");
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

static void sf_opaque_initialize_c10_lab2_next_level(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc10_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc10_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c10_lab2_next_level((SFc10_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
  initialize_c10_lab2_next_level((SFc10_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c10_lab2_next_level(void *chartInstanceVar)
{
  enable_c10_lab2_next_level((SFc10_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c10_lab2_next_level(void *chartInstanceVar)
{
  disable_c10_lab2_next_level((SFc10_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c10_lab2_next_level(void *chartInstanceVar)
{
  sf_c10_lab2_next_level((SFc10_lab2_next_levelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c10_lab2_next_level(void *chartInstanceVar)
{
  ext_mode_exec_c10_lab2_next_level((SFc10_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c10_lab2_next_level(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c10_lab2_next_level
    ((SFc10_lab2_next_levelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_lab2_next_level();/* state var info */
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

extern void sf_internal_set_sim_state_c10_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_lab2_next_level();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c10_lab2_next_level((SFc10_lab2_next_levelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c10_lab2_next_level(SimStruct* S)
{
  return sf_internal_get_sim_state_c10_lab2_next_level(S);
}

static void sf_opaque_set_sim_state_c10_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c10_lab2_next_level(S, st);
}

static void sf_opaque_terminate_c10_lab2_next_level(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_lab2_next_levelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c10_lab2_next_level((SFc10_lab2_next_levelInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_lab2_next_level_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc10_lab2_next_level((SFc10_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_lab2_next_level(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c10_lab2_next_level((SFc10_lab2_next_levelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c10_lab2_next_level_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c10_lab2_next_level\",T\"is_active_c10_lab2_next_level\"}}"
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

static void mdlSetWorkWidths_c10_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,10,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,10,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,10,3);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3785369184U));
  ssSetChecksum1(S,(3764540015U));
  ssSetChecksum2(S,(929079147U));
  ssSetChecksum3(S,(709119222U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c10_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_lab2_next_level(SimStruct *S)
{
  SFc10_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc10_lab2_next_levelInstanceStruct *)malloc(sizeof
    (SFc10_lab2_next_levelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc10_lab2_next_levelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_lab2_next_level;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_lab2_next_level;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c10_lab2_next_level;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c10_lab2_next_level;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c10_lab2_next_level;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_lab2_next_level;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_lab2_next_level;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_lab2_next_level;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_lab2_next_level;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_lab2_next_level;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_lab2_next_level;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c10_lab2_next_level;
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

void c10_lab2_next_level_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_lab2_next_level(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_lab2_next_level(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_lab2_next_level(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_lab2_next_level_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
