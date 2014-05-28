/* Include files */

#include <stddef.h>
#include "blas.h"
#include "lab2_next_level_sfun.h"
#include "c14_lab2_next_level.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lab2_next_level_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c14_debug_family_names[15] = { "roll", "pitch", "yaw", "x",
  "y", "z", "P", "M", "nargin", "nargout", "angles", "accel", "xs", "ys", "zs" };

/* Function Declarations */
static void initialize_c14_lab2_next_level(SFc14_lab2_next_levelInstanceStruct
  *chartInstance);
static void initialize_params_c14_lab2_next_level
  (SFc14_lab2_next_levelInstanceStruct *chartInstance);
static void enable_c14_lab2_next_level(SFc14_lab2_next_levelInstanceStruct
  *chartInstance);
static void disable_c14_lab2_next_level(SFc14_lab2_next_levelInstanceStruct
  *chartInstance);
static void c14_update_debugger_state_c14_lab2_next_level
  (SFc14_lab2_next_levelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c14_lab2_next_level
  (SFc14_lab2_next_levelInstanceStruct *chartInstance);
static void set_sim_state_c14_lab2_next_level
  (SFc14_lab2_next_levelInstanceStruct *chartInstance, const mxArray *c14_st);
static void finalize_c14_lab2_next_level(SFc14_lab2_next_levelInstanceStruct
  *chartInstance);
static void sf_c14_lab2_next_level(SFc14_lab2_next_levelInstanceStruct
  *chartInstance);
static void c14_chartstep_c14_lab2_next_level
  (SFc14_lab2_next_levelInstanceStruct *chartInstance);
static void initSimStructsc14_lab2_next_level
  (SFc14_lab2_next_levelInstanceStruct *chartInstance);
static void registerMessagesc14_lab2_next_level
  (SFc14_lab2_next_levelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber);
static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static real_T c14_emlrt_marshallIn(SFc14_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c14_zs, const char_T *c14_identifier);
static real_T c14_b_emlrt_marshallIn(SFc14_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_c_emlrt_marshallIn(SFc14_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[3]);
static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static void c14_eml_scalar_eg(SFc14_lab2_next_levelInstanceStruct *chartInstance);
static void c14_d_emlrt_marshallIn(SFc14_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c14_rotationMatrix, const char_T
  *c14_identifier, real_T c14_y[9]);
static void c14_e_emlrt_marshallIn(SFc14_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[9]);
static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static int32_T c14_f_emlrt_marshallIn(SFc14_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static uint8_T c14_g_emlrt_marshallIn(SFc14_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_lab2_next_level, const
  char_T *c14_identifier);
static uint8_T c14_h_emlrt_marshallIn(SFc14_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void init_dsm_address_info(SFc14_lab2_next_levelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c14_lab2_next_level(SFc14_lab2_next_levelInstanceStruct
  *chartInstance)
{
  chartInstance->c14_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c14_is_active_c14_lab2_next_level = 0U;
}

static void initialize_params_c14_lab2_next_level
  (SFc14_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void enable_c14_lab2_next_level(SFc14_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c14_lab2_next_level(SFc14_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c14_update_debugger_state_c14_lab2_next_level
  (SFc14_lab2_next_levelInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c14_lab2_next_level
  (SFc14_lab2_next_levelInstanceStruct *chartInstance)
{
  const mxArray *c14_st;
  const mxArray *c14_y = NULL;
  real_T c14_hoistedGlobal;
  real_T c14_u;
  const mxArray *c14_b_y = NULL;
  real_T c14_b_hoistedGlobal;
  real_T c14_b_u;
  const mxArray *c14_c_y = NULL;
  real_T c14_c_hoistedGlobal;
  real_T c14_c_u;
  const mxArray *c14_d_y = NULL;
  uint8_T c14_d_hoistedGlobal;
  uint8_T c14_d_u;
  const mxArray *c14_e_y = NULL;
  real_T *c14_xs;
  real_T *c14_ys;
  real_T *c14_zs;
  c14_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c14_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c14_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c14_st = NULL;
  c14_st = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_createcellarray(4), FALSE);
  c14_hoistedGlobal = *c14_xs;
  c14_u = c14_hoistedGlobal;
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c14_y, 0, c14_b_y);
  c14_b_hoistedGlobal = *c14_ys;
  c14_b_u = c14_b_hoistedGlobal;
  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", &c14_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c14_y, 1, c14_c_y);
  c14_c_hoistedGlobal = *c14_zs;
  c14_c_u = c14_c_hoistedGlobal;
  c14_d_y = NULL;
  sf_mex_assign(&c14_d_y, sf_mex_create("y", &c14_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c14_y, 2, c14_d_y);
  c14_d_hoistedGlobal = chartInstance->c14_is_active_c14_lab2_next_level;
  c14_d_u = c14_d_hoistedGlobal;
  c14_e_y = NULL;
  sf_mex_assign(&c14_e_y, sf_mex_create("y", &c14_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c14_y, 3, c14_e_y);
  sf_mex_assign(&c14_st, c14_y, FALSE);
  return c14_st;
}

static void set_sim_state_c14_lab2_next_level
  (SFc14_lab2_next_levelInstanceStruct *chartInstance, const mxArray *c14_st)
{
  const mxArray *c14_u;
  real_T *c14_xs;
  real_T *c14_ys;
  real_T *c14_zs;
  c14_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c14_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c14_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c14_doneDoubleBufferReInit = TRUE;
  c14_u = sf_mex_dup(c14_st);
  *c14_xs = c14_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u,
    0)), "xs");
  *c14_ys = c14_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u,
    1)), "ys");
  *c14_zs = c14_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u,
    2)), "zs");
  chartInstance->c14_is_active_c14_lab2_next_level = c14_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 3)),
     "is_active_c14_lab2_next_level");
  sf_mex_destroy(&c14_u);
  c14_update_debugger_state_c14_lab2_next_level(chartInstance);
  sf_mex_destroy(&c14_st);
}

static void finalize_c14_lab2_next_level(SFc14_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

static void sf_c14_lab2_next_level(SFc14_lab2_next_levelInstanceStruct
  *chartInstance)
{
  int32_T c14_i0;
  int32_T c14_i1;
  real_T *c14_xs;
  real_T *c14_ys;
  real_T *c14_zs;
  real_T (*c14_accel)[3];
  real_T (*c14_angles)[3];
  c14_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c14_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c14_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c14_accel = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c14_angles = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c14_sfEvent);
  for (c14_i0 = 0; c14_i0 < 3; c14_i0++) {
    _SFD_DATA_RANGE_CHECK((*c14_angles)[c14_i0], 0U);
  }

  for (c14_i1 = 0; c14_i1 < 3; c14_i1++) {
    _SFD_DATA_RANGE_CHECK((*c14_accel)[c14_i1], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c14_xs, 2U);
  _SFD_DATA_RANGE_CHECK(*c14_ys, 3U);
  _SFD_DATA_RANGE_CHECK(*c14_zs, 4U);
  chartInstance->c14_sfEvent = CALL_EVENT;
  c14_chartstep_c14_lab2_next_level(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lab2_next_levelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c14_chartstep_c14_lab2_next_level
  (SFc14_lab2_next_levelInstanceStruct *chartInstance)
{
  int32_T c14_i2;
  real_T c14_angles[3];
  int32_T c14_i3;
  real_T c14_accel[3];
  uint32_T c14_debug_family_var_map[15];
  real_T c14_roll;
  real_T c14_pitch;
  real_T c14_yaw;
  real_T c14_x;
  real_T c14_y;
  real_T c14_z;
  real_T c14_P[9];
  real_T c14_M[3];
  real_T c14_nargin = 2.0;
  real_T c14_nargout = 3.0;
  real_T c14_xs;
  real_T c14_ys;
  real_T c14_zs;
  int32_T c14_i4;
  real_T c14_u;
  const mxArray *c14_b_y = NULL;
  real_T c14_b_u;
  const mxArray *c14_c_y = NULL;
  real_T c14_c_u;
  const mxArray *c14_d_y = NULL;
  real_T c14_dv0[9];
  int32_T c14_i5;
  int32_T c14_i6;
  real_T c14_a[9];
  real_T c14_b[3];
  int32_T c14_i7;
  int32_T c14_i8;
  int32_T c14_i9;
  real_T c14_C[3];
  int32_T c14_i10;
  int32_T c14_i11;
  int32_T c14_i12;
  int32_T c14_i13;
  int32_T c14_i14;
  int32_T c14_i15;
  real_T *c14_b_xs;
  real_T *c14_b_ys;
  real_T *c14_b_zs;
  real_T (*c14_b_accel)[3];
  real_T (*c14_b_angles)[3];
  c14_b_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c14_b_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c14_b_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c14_b_accel = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c14_b_angles = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c14_sfEvent);
  for (c14_i2 = 0; c14_i2 < 3; c14_i2++) {
    c14_angles[c14_i2] = (*c14_b_angles)[c14_i2];
  }

  for (c14_i3 = 0; c14_i3 < 3; c14_i3++) {
    c14_accel[c14_i3] = (*c14_b_accel)[c14_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c14_debug_family_names,
    c14_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_roll, 0U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_pitch, 1U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_yaw, 2U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_x, 3U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_y, 4U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_z, 5U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_P, 6U, c14_c_sf_marshallOut,
    c14_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_M, 7U, c14_b_sf_marshallOut,
    c14_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargin, 8U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargout, 9U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c14_angles, 10U, c14_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c14_accel, 11U, c14_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_xs, 12U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_ys, 13U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_zs, 14U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 5);
  c14_roll = c14_angles[0];
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 6);
  c14_pitch = c14_angles[0];
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 7);
  c14_yaw = c14_angles[2];
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 9);
  c14_x = c14_accel[0];
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 10);
  c14_y = c14_accel[1];
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 11);
  c14_z = c14_accel[2];
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 13);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 15);
  for (c14_i4 = 0; c14_i4 < 9; c14_i4++) {
    c14_P[c14_i4] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 16);
  c14_u = c14_roll;
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0), FALSE);
  c14_b_u = c14_pitch;
  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", &c14_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  c14_c_u = c14_yaw;
  c14_d_y = NULL;
  sf_mex_assign(&c14_d_y, sf_mex_create("y", &c14_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  c14_d_emlrt_marshallIn(chartInstance, sf_mex_call_debug("rotationMatrix", 1U,
    3U, 14, c14_b_y, 14, c14_c_y, 14, c14_d_y), "rotationMatrix", c14_dv0);
  for (c14_i5 = 0; c14_i5 < 9; c14_i5++) {
    c14_P[c14_i5] = c14_dv0[c14_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 18);
  for (c14_i6 = 0; c14_i6 < 9; c14_i6++) {
    c14_a[c14_i6] = c14_P[c14_i6];
  }

  c14_b[0] = c14_x;
  c14_b[1] = c14_y;
  c14_b[2] = c14_z;
  c14_eml_scalar_eg(chartInstance);
  c14_eml_scalar_eg(chartInstance);
  for (c14_i7 = 0; c14_i7 < 3; c14_i7++) {
    c14_M[c14_i7] = 0.0;
  }

  for (c14_i8 = 0; c14_i8 < 3; c14_i8++) {
    c14_M[c14_i8] = 0.0;
  }

  for (c14_i9 = 0; c14_i9 < 3; c14_i9++) {
    c14_C[c14_i9] = c14_M[c14_i9];
  }

  for (c14_i10 = 0; c14_i10 < 3; c14_i10++) {
    c14_M[c14_i10] = c14_C[c14_i10];
  }

  for (c14_i11 = 0; c14_i11 < 3; c14_i11++) {
    c14_C[c14_i11] = c14_M[c14_i11];
  }

  for (c14_i12 = 0; c14_i12 < 3; c14_i12++) {
    c14_M[c14_i12] = c14_C[c14_i12];
  }

  for (c14_i13 = 0; c14_i13 < 3; c14_i13++) {
    c14_M[c14_i13] = 0.0;
    c14_i14 = 0;
    for (c14_i15 = 0; c14_i15 < 3; c14_i15++) {
      c14_M[c14_i13] += c14_a[c14_i14 + c14_i13] * c14_b[c14_i15];
      c14_i14 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 20);
  c14_xs = c14_M[0];
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 21);
  c14_ys = c14_M[1];
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 22);
  c14_zs = c14_M[2];
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, -22);
  _SFD_SYMBOL_SCOPE_POP();
  *c14_b_xs = c14_xs;
  *c14_b_ys = c14_ys;
  *c14_b_zs = c14_zs;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c14_sfEvent);
}

static void initSimStructsc14_lab2_next_level
  (SFc14_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void registerMessagesc14_lab2_next_level
  (SFc14_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber)
{
}

static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  real_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc14_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(real_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, FALSE);
  return c14_mxArrayOutData;
}

static real_T c14_emlrt_marshallIn(SFc14_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c14_zs, const char_T *c14_identifier)
{
  real_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_zs), &c14_thisId);
  sf_mex_destroy(&c14_zs);
  return c14_y;
}

static real_T c14_b_emlrt_marshallIn(SFc14_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  real_T c14_y;
  real_T c14_d0;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_d0, 1, 0, 0U, 0, 0U, 0);
  c14_y = c14_d0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_zs;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y;
  SFc14_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc14_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c14_zs = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_zs), &c14_thisId);
  sf_mex_destroy(&c14_zs);
  *(real_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i16;
  real_T c14_b_inData[3];
  int32_T c14_i17;
  real_T c14_u[3];
  const mxArray *c14_y = NULL;
  SFc14_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc14_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  for (c14_i16 = 0; c14_i16 < 3; c14_i16++) {
    c14_b_inData[c14_i16] = (*(real_T (*)[3])c14_inData)[c14_i16];
  }

  for (c14_i17 = 0; c14_i17 < 3; c14_i17++) {
    c14_u[c14_i17] = c14_b_inData[c14_i17];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, FALSE);
  return c14_mxArrayOutData;
}

static void c14_c_emlrt_marshallIn(SFc14_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[3])
{
  real_T c14_dv1[3];
  int32_T c14_i18;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c14_i18 = 0; c14_i18 < 3; c14_i18++) {
    c14_y[c14_i18] = c14_dv1[c14_i18];
  }

  sf_mex_destroy(&c14_u);
}

static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_M;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y[3];
  int32_T c14_i19;
  SFc14_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc14_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c14_M = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_M), &c14_thisId, c14_y);
  sf_mex_destroy(&c14_M);
  for (c14_i19 = 0; c14_i19 < 3; c14_i19++) {
    (*(real_T (*)[3])c14_outData)[c14_i19] = c14_y[c14_i19];
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i20;
  int32_T c14_i21;
  int32_T c14_i22;
  real_T c14_b_inData[9];
  int32_T c14_i23;
  int32_T c14_i24;
  int32_T c14_i25;
  real_T c14_u[9];
  const mxArray *c14_y = NULL;
  SFc14_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc14_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_i20 = 0;
  for (c14_i21 = 0; c14_i21 < 3; c14_i21++) {
    for (c14_i22 = 0; c14_i22 < 3; c14_i22++) {
      c14_b_inData[c14_i22 + c14_i20] = (*(real_T (*)[9])c14_inData)[c14_i22 +
        c14_i20];
    }

    c14_i20 += 3;
  }

  c14_i23 = 0;
  for (c14_i24 = 0; c14_i24 < 3; c14_i24++) {
    for (c14_i25 = 0; c14_i25 < 3; c14_i25++) {
      c14_u[c14_i25 + c14_i23] = c14_b_inData[c14_i25 + c14_i23];
    }

    c14_i23 += 3;
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, FALSE);
  return c14_mxArrayOutData;
}

static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_rotationMatrix;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y[9];
  int32_T c14_i26;
  int32_T c14_i27;
  int32_T c14_i28;
  SFc14_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc14_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c14_rotationMatrix = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_rotationMatrix),
    &c14_thisId, c14_y);
  sf_mex_destroy(&c14_rotationMatrix);
  c14_i26 = 0;
  for (c14_i27 = 0; c14_i27 < 3; c14_i27++) {
    for (c14_i28 = 0; c14_i28 < 3; c14_i28++) {
      (*(real_T (*)[9])c14_outData)[c14_i28 + c14_i26] = c14_y[c14_i28 + c14_i26];
    }

    c14_i26 += 3;
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

const mxArray *sf_c14_lab2_next_level_get_eml_resolved_functions_info(void)
{
  const mxArray *c14_nameCaptureInfo;
  c14_ResolvedFunctionInfo c14_info[9];
  c14_ResolvedFunctionInfo (*c14_b_info)[9];
  const mxArray *c14_m0 = NULL;
  int32_T c14_i29;
  c14_ResolvedFunctionInfo *c14_r0;
  c14_nameCaptureInfo = NULL;
  c14_nameCaptureInfo = NULL;
  c14_b_info = (c14_ResolvedFunctionInfo (*)[9])c14_info;
  (*c14_b_info)[0].context = "";
  (*c14_b_info)[0].name = "mtimes";
  (*c14_b_info)[0].dominantType = "double";
  (*c14_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c14_b_info)[0].fileTimeLo = 1289512492U;
  (*c14_b_info)[0].fileTimeHi = 0U;
  (*c14_b_info)[0].mFileTimeLo = 0U;
  (*c14_b_info)[0].mFileTimeHi = 0U;
  (*c14_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c14_b_info)[1].name = "eml_index_class";
  (*c14_b_info)[1].dominantType = "";
  (*c14_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c14_b_info)[1].fileTimeLo = 1323163378U;
  (*c14_b_info)[1].fileTimeHi = 0U;
  (*c14_b_info)[1].mFileTimeLo = 0U;
  (*c14_b_info)[1].mFileTimeHi = 0U;
  (*c14_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c14_b_info)[2].name = "eml_scalar_eg";
  (*c14_b_info)[2].dominantType = "double";
  (*c14_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c14_b_info)[2].fileTimeLo = 1286811596U;
  (*c14_b_info)[2].fileTimeHi = 0U;
  (*c14_b_info)[2].mFileTimeLo = 0U;
  (*c14_b_info)[2].mFileTimeHi = 0U;
  (*c14_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c14_b_info)[3].name = "eml_xgemm";
  (*c14_b_info)[3].dominantType = "char";
  (*c14_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c14_b_info)[3].fileTimeLo = 1299069572U;
  (*c14_b_info)[3].fileTimeHi = 0U;
  (*c14_b_info)[3].mFileTimeLo = 0U;
  (*c14_b_info)[3].mFileTimeHi = 0U;
  (*c14_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c14_b_info)[4].name = "eml_blas_inline";
  (*c14_b_info)[4].dominantType = "";
  (*c14_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  (*c14_b_info)[4].fileTimeLo = 1299069568U;
  (*c14_b_info)[4].fileTimeHi = 0U;
  (*c14_b_info)[4].mFileTimeLo = 0U;
  (*c14_b_info)[4].mFileTimeHi = 0U;
  (*c14_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  (*c14_b_info)[5].name = "mtimes";
  (*c14_b_info)[5].dominantType = "double";
  (*c14_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c14_b_info)[5].fileTimeLo = 1289512492U;
  (*c14_b_info)[5].fileTimeHi = 0U;
  (*c14_b_info)[5].mFileTimeLo = 0U;
  (*c14_b_info)[5].mFileTimeHi = 0U;
  (*c14_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c14_b_info)[6].name = "eml_index_class";
  (*c14_b_info)[6].dominantType = "";
  (*c14_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c14_b_info)[6].fileTimeLo = 1323163378U;
  (*c14_b_info)[6].fileTimeHi = 0U;
  (*c14_b_info)[6].mFileTimeLo = 0U;
  (*c14_b_info)[6].mFileTimeHi = 0U;
  (*c14_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c14_b_info)[7].name = "eml_scalar_eg";
  (*c14_b_info)[7].dominantType = "double";
  (*c14_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c14_b_info)[7].fileTimeLo = 1286811596U;
  (*c14_b_info)[7].fileTimeHi = 0U;
  (*c14_b_info)[7].mFileTimeLo = 0U;
  (*c14_b_info)[7].mFileTimeHi = 0U;
  (*c14_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c14_b_info)[8].name = "eml_refblas_xgemm";
  (*c14_b_info)[8].dominantType = "char";
  (*c14_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c14_b_info)[8].fileTimeLo = 1299069574U;
  (*c14_b_info)[8].fileTimeHi = 0U;
  (*c14_b_info)[8].mFileTimeLo = 0U;
  (*c14_b_info)[8].mFileTimeHi = 0U;
  sf_mex_assign(&c14_m0, sf_mex_createstruct("nameCaptureInfo", 1, 9), FALSE);
  for (c14_i29 = 0; c14_i29 < 9; c14_i29++) {
    c14_r0 = &c14_info[c14_i29];
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c14_r0->context)), "context", "nameCaptureInfo",
                    c14_i29);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c14_r0->name)), "name", "nameCaptureInfo",
                    c14_i29);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo",
      c14_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c14_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c14_i29);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c14_r0->resolved)), "resolved",
                    "nameCaptureInfo", c14_i29);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", &c14_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c14_i29);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", &c14_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c14_i29);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo",
      &c14_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c14_i29);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo",
      &c14_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c14_i29);
  }

  sf_mex_assign(&c14_nameCaptureInfo, c14_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c14_nameCaptureInfo);
  return c14_nameCaptureInfo;
}

static void c14_eml_scalar_eg(SFc14_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void c14_d_emlrt_marshallIn(SFc14_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c14_rotationMatrix, const char_T
  *c14_identifier, real_T c14_y[9])
{
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_rotationMatrix),
    &c14_thisId, c14_y);
  sf_mex_destroy(&c14_rotationMatrix);
}

static void c14_e_emlrt_marshallIn(SFc14_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[9])
{
  real_T c14_dv2[9];
  int32_T c14_i30;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv2, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c14_i30 = 0; c14_i30 < 9; c14_i30++) {
    c14_y[c14_i30] = c14_dv2[c14_i30];
  }

  sf_mex_destroy(&c14_u);
}

static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc14_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(int32_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, FALSE);
  return c14_mxArrayOutData;
}

static int32_T c14_f_emlrt_marshallIn(SFc14_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  int32_T c14_y;
  int32_T c14_i31;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_i31, 1, 6, 0U, 0, 0U, 0);
  c14_y = c14_i31;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_sfEvent;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  int32_T c14_y;
  SFc14_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc14_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c14_b_sfEvent = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_sfEvent),
    &c14_thisId);
  sf_mex_destroy(&c14_b_sfEvent);
  *(int32_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static uint8_T c14_g_emlrt_marshallIn(SFc14_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_lab2_next_level, const
  char_T *c14_identifier)
{
  uint8_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c14_b_is_active_c14_lab2_next_level), &c14_thisId);
  sf_mex_destroy(&c14_b_is_active_c14_lab2_next_level);
  return c14_y;
}

static uint8_T c14_h_emlrt_marshallIn(SFc14_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  uint8_T c14_y;
  uint8_T c14_u0;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_u0, 1, 3, 0U, 0, 0U, 0);
  c14_y = c14_u0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void init_dsm_address_info(SFc14_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c14_lab2_next_level_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(610676443U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(483216120U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2498528544U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(908622084U);
}

mxArray *sf_c14_lab2_next_level_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("V878yxmFC9oe7WGApG5anC");
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

mxArray *sf_c14_lab2_next_level_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c14_lab2_next_level(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[10],T\"xs\",},{M[1],M[11],T\"ys\",},{M[1],M[12],T\"zs\",},{M[8],M[0],T\"is_active_c14_lab2_next_level\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c14_lab2_next_level_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc14_lab2_next_levelInstanceStruct *chartInstance;
    chartInstance = (SFc14_lab2_next_levelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _lab2_next_levelMachineNumber_,
           14,
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
            (sfGlobalDebugInstanceStruct,_lab2_next_levelMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _lab2_next_levelMachineNumber_,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,351);
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
            1.0,0,0,(MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)c14_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)c14_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)c14_sf_marshallIn);

        {
          real_T *c14_xs;
          real_T *c14_ys;
          real_T *c14_zs;
          real_T (*c14_angles)[3];
          real_T (*c14_accel)[3];
          c14_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c14_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c14_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c14_accel = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c14_angles = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c14_angles);
          _SFD_SET_DATA_VALUE_PTR(1U, *c14_accel);
          _SFD_SET_DATA_VALUE_PTR(2U, c14_xs);
          _SFD_SET_DATA_VALUE_PTR(3U, c14_ys);
          _SFD_SET_DATA_VALUE_PTR(4U, c14_zs);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _lab2_next_levelMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "uMiMxksBgc6vc6nryy9JJD";
}

static void sf_opaque_initialize_c14_lab2_next_level(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc14_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c14_lab2_next_level((SFc14_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
  initialize_c14_lab2_next_level((SFc14_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c14_lab2_next_level(void *chartInstanceVar)
{
  enable_c14_lab2_next_level((SFc14_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c14_lab2_next_level(void *chartInstanceVar)
{
  disable_c14_lab2_next_level((SFc14_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c14_lab2_next_level(void *chartInstanceVar)
{
  sf_c14_lab2_next_level((SFc14_lab2_next_levelInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c14_lab2_next_level(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c14_lab2_next_level
    ((SFc14_lab2_next_levelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c14_lab2_next_level();/* state var info */
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

extern void sf_internal_set_sim_state_c14_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c14_lab2_next_level();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c14_lab2_next_level((SFc14_lab2_next_levelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c14_lab2_next_level(SimStruct* S)
{
  return sf_internal_get_sim_state_c14_lab2_next_level(S);
}

static void sf_opaque_set_sim_state_c14_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c14_lab2_next_level(S, st);
}

static void sf_opaque_terminate_c14_lab2_next_level(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc14_lab2_next_levelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_lab2_next_level_optimization_info();
    }

    finalize_c14_lab2_next_level((SFc14_lab2_next_levelInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc14_lab2_next_level((SFc14_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c14_lab2_next_level(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c14_lab2_next_level((SFc14_lab2_next_levelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c14_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      14);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,14,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,14,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,14);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,14,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,14,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,14);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2111004675U));
  ssSetChecksum1(S,(3462273144U));
  ssSetChecksum2(S,(1084410505U));
  ssSetChecksum3(S,(1840233102U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c14_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c14_lab2_next_level(SimStruct *S)
{
  SFc14_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc14_lab2_next_levelInstanceStruct *)utMalloc(sizeof
    (SFc14_lab2_next_levelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc14_lab2_next_levelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c14_lab2_next_level;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c14_lab2_next_level;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c14_lab2_next_level;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c14_lab2_next_level;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c14_lab2_next_level;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c14_lab2_next_level;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c14_lab2_next_level;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c14_lab2_next_level;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c14_lab2_next_level;
  chartInstance->chartInfo.mdlStart = mdlStart_c14_lab2_next_level;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c14_lab2_next_level;
  chartInstance->chartInfo.extModeExec = NULL;
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

void c14_lab2_next_level_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c14_lab2_next_level(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c14_lab2_next_level(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c14_lab2_next_level(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c14_lab2_next_level_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
