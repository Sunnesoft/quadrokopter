/* Include files */

#include <stddef.h>
#include "blas.h"
#include "lab2_next_level_sfun.h"
#include "c9_lab2_next_level.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lab2_next_level_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c9_debug_family_names[14] = { "ya", "cy", "sy", "CZ", "M",
  "nargin", "nargout", "yaw", "x", "y", "z", "xs", "ys", "zs" };

/* Function Declarations */
static void initialize_c9_lab2_next_level(SFc9_lab2_next_levelInstanceStruct
  *chartInstance);
static void initialize_params_c9_lab2_next_level
  (SFc9_lab2_next_levelInstanceStruct *chartInstance);
static void enable_c9_lab2_next_level(SFc9_lab2_next_levelInstanceStruct
  *chartInstance);
static void disable_c9_lab2_next_level(SFc9_lab2_next_levelInstanceStruct
  *chartInstance);
static void c9_update_debugger_state_c9_lab2_next_level
  (SFc9_lab2_next_levelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_lab2_next_level
  (SFc9_lab2_next_levelInstanceStruct *chartInstance);
static void set_sim_state_c9_lab2_next_level(SFc9_lab2_next_levelInstanceStruct *
  chartInstance, const mxArray *c9_st);
static void finalize_c9_lab2_next_level(SFc9_lab2_next_levelInstanceStruct
  *chartInstance);
static void sf_c9_lab2_next_level(SFc9_lab2_next_levelInstanceStruct
  *chartInstance);
static void c9_chartstep_c9_lab2_next_level(SFc9_lab2_next_levelInstanceStruct
  *chartInstance);
static void initSimStructsc9_lab2_next_level(SFc9_lab2_next_levelInstanceStruct *
  chartInstance);
static void registerMessagesc9_lab2_next_level
  (SFc9_lab2_next_levelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static real_T c9_emlrt_marshallIn(SFc9_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c9_zs, const char_T *c9_identifier);
static real_T c9_b_emlrt_marshallIn(SFc9_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_c_emlrt_marshallIn(SFc9_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[3]);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_d_emlrt_marshallIn(SFc9_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[9]);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[13]);
static void c9_eml_scalar_eg(SFc9_lab2_next_levelInstanceStruct *chartInstance);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_e_emlrt_marshallIn(SFc9_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_f_emlrt_marshallIn(SFc9_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_lab2_next_level, const char_T
  *c9_identifier);
static uint8_T c9_g_emlrt_marshallIn(SFc9_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info(SFc9_lab2_next_levelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_lab2_next_level(SFc9_lab2_next_levelInstanceStruct
  *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c9_is_active_c9_lab2_next_level = 0U;
}

static void initialize_params_c9_lab2_next_level
  (SFc9_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void enable_c9_lab2_next_level(SFc9_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c9_lab2_next_level(SFc9_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c9_update_debugger_state_c9_lab2_next_level
  (SFc9_lab2_next_levelInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c9_lab2_next_level
  (SFc9_lab2_next_levelInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  real_T c9_hoistedGlobal;
  real_T c9_u;
  const mxArray *c9_b_y = NULL;
  real_T c9_b_hoistedGlobal;
  real_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  real_T c9_c_hoistedGlobal;
  real_T c9_c_u;
  const mxArray *c9_d_y = NULL;
  uint8_T c9_d_hoistedGlobal;
  uint8_T c9_d_u;
  const mxArray *c9_e_y = NULL;
  real_T *c9_xs;
  real_T *c9_ys;
  real_T *c9_zs;
  c9_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(4), FALSE);
  c9_hoistedGlobal = *c9_xs;
  c9_u = c9_hoistedGlobal;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_b_hoistedGlobal = *c9_ys;
  c9_b_u = c9_b_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  c9_c_hoistedGlobal = *c9_zs;
  c9_c_u = c9_c_hoistedGlobal;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 2, c9_d_y);
  c9_d_hoistedGlobal = chartInstance->c9_is_active_c9_lab2_next_level;
  c9_d_u = c9_d_hoistedGlobal;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 3, c9_e_y);
  sf_mex_assign(&c9_st, c9_y, FALSE);
  return c9_st;
}

static void set_sim_state_c9_lab2_next_level(SFc9_lab2_next_levelInstanceStruct *
  chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  real_T *c9_xs;
  real_T *c9_ys;
  real_T *c9_zs;
  c9_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c9_doneDoubleBufferReInit = TRUE;
  c9_u = sf_mex_dup(c9_st);
  *c9_xs = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 0)),
    "xs");
  *c9_ys = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 1)),
    "ys");
  *c9_zs = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 2)),
    "zs");
  chartInstance->c9_is_active_c9_lab2_next_level = c9_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 3)),
     "is_active_c9_lab2_next_level");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_lab2_next_level(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_lab2_next_level(SFc9_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

static void sf_c9_lab2_next_level(SFc9_lab2_next_levelInstanceStruct
  *chartInstance)
{
  real_T *c9_yaw;
  real_T *c9_x;
  real_T *c9_y;
  real_T *c9_z;
  real_T *c9_xs;
  real_T *c9_ys;
  real_T *c9_zs;
  c9_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c9_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c9_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c9_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c9_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c9_yaw, 0U);
  _SFD_DATA_RANGE_CHECK(*c9_x, 1U);
  _SFD_DATA_RANGE_CHECK(*c9_y, 2U);
  _SFD_DATA_RANGE_CHECK(*c9_z, 3U);
  _SFD_DATA_RANGE_CHECK(*c9_xs, 4U);
  _SFD_DATA_RANGE_CHECK(*c9_ys, 5U);
  _SFD_DATA_RANGE_CHECK(*c9_zs, 6U);
  chartInstance->c9_sfEvent = CALL_EVENT;
  c9_chartstep_c9_lab2_next_level(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lab2_next_levelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c9_chartstep_c9_lab2_next_level(SFc9_lab2_next_levelInstanceStruct
  *chartInstance)
{
  real_T c9_hoistedGlobal;
  real_T c9_b_hoistedGlobal;
  real_T c9_c_hoistedGlobal;
  real_T c9_d_hoistedGlobal;
  real_T c9_yaw;
  real_T c9_x;
  real_T c9_y;
  real_T c9_z;
  uint32_T c9_debug_family_var_map[14];
  real_T c9_ya;
  real_T c9_cy;
  real_T c9_sy;
  real_T c9_CZ[9];
  real_T c9_M[3];
  real_T c9_nargin = 4.0;
  real_T c9_nargout = 3.0;
  real_T c9_xs;
  real_T c9_ys;
  real_T c9_zs;
  real_T c9_b_x;
  real_T c9_c_x;
  real_T c9_d_x;
  real_T c9_e_x;
  int32_T c9_i0;
  int32_T c9_i1;
  static real_T c9_dv0[3] = { 0.0, 0.0, 1.0 };

  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_i4;
  int32_T c9_i5;
  real_T c9_a[9];
  real_T c9_b[3];
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  real_T c9_C[3];
  int32_T c9_i9;
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i12;
  int32_T c9_i13;
  int32_T c9_i14;
  real_T *c9_b_yaw;
  real_T *c9_f_x;
  real_T *c9_b_y;
  real_T *c9_b_z;
  real_T *c9_b_xs;
  real_T *c9_b_ys;
  real_T *c9_b_zs;
  c9_b_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_b_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_b_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_b_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c9_b_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c9_f_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c9_b_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c9_sfEvent);
  c9_hoistedGlobal = *c9_b_yaw;
  c9_b_hoistedGlobal = *c9_f_x;
  c9_c_hoistedGlobal = *c9_b_y;
  c9_d_hoistedGlobal = *c9_b_z;
  c9_yaw = c9_hoistedGlobal;
  c9_x = c9_b_hoistedGlobal;
  c9_y = c9_c_hoistedGlobal;
  c9_z = c9_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_ya, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_cy, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_sy, 2U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_CZ, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_M, 4U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 5U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_yaw, 7U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_x, 8U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_y, 9U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_z, 10U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_xs, 11U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_ys, 12U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_zs, 13U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ya = c9_yaw;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_b_x = c9_ya;
  c9_cy = c9_b_x;
  c9_c_x = c9_cy;
  c9_cy = c9_c_x;
  c9_cy = muDoubleScalarCos(c9_cy);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_d_x = c9_ya;
  c9_sy = c9_d_x;
  c9_e_x = c9_sy;
  c9_sy = c9_e_x;
  c9_sy = muDoubleScalarSin(c9_sy);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 10);
  c9_CZ[0] = c9_cy;
  c9_CZ[3] = c9_sy;
  c9_CZ[6] = 0.0;
  c9_CZ[1] = -c9_sy;
  c9_CZ[4] = c9_cy;
  c9_CZ[7] = 0.0;
  c9_i0 = 0;
  for (c9_i1 = 0; c9_i1 < 3; c9_i1++) {
    c9_CZ[c9_i0 + 2] = c9_dv0[c9_i1];
    c9_i0 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 12);
  c9_i2 = 0;
  for (c9_i3 = 0; c9_i3 < 3; c9_i3++) {
    c9_i4 = 0;
    for (c9_i5 = 0; c9_i5 < 3; c9_i5++) {
      c9_a[c9_i5 + c9_i2] = c9_CZ[c9_i4 + c9_i3];
      c9_i4 += 3;
    }

    c9_i2 += 3;
  }

  c9_b[0] = c9_x;
  c9_b[1] = c9_y;
  c9_b[2] = c9_z;
  c9_eml_scalar_eg(chartInstance);
  c9_eml_scalar_eg(chartInstance);
  for (c9_i6 = 0; c9_i6 < 3; c9_i6++) {
    c9_M[c9_i6] = 0.0;
  }

  for (c9_i7 = 0; c9_i7 < 3; c9_i7++) {
    c9_M[c9_i7] = 0.0;
  }

  for (c9_i8 = 0; c9_i8 < 3; c9_i8++) {
    c9_C[c9_i8] = c9_M[c9_i8];
  }

  for (c9_i9 = 0; c9_i9 < 3; c9_i9++) {
    c9_M[c9_i9] = c9_C[c9_i9];
  }

  for (c9_i10 = 0; c9_i10 < 3; c9_i10++) {
    c9_C[c9_i10] = c9_M[c9_i10];
  }

  for (c9_i11 = 0; c9_i11 < 3; c9_i11++) {
    c9_M[c9_i11] = c9_C[c9_i11];
  }

  for (c9_i12 = 0; c9_i12 < 3; c9_i12++) {
    c9_M[c9_i12] = 0.0;
    c9_i13 = 0;
    for (c9_i14 = 0; c9_i14 < 3; c9_i14++) {
      c9_M[c9_i12] += c9_a[c9_i13 + c9_i12] * c9_b[c9_i14];
      c9_i13 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 14);
  c9_xs = c9_M[0];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 15);
  c9_ys = c9_M[1];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 16);
  c9_zs = c9_M[2];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -16);
  _SFD_SYMBOL_SCOPE_POP();
  *c9_b_xs = c9_xs;
  *c9_b_ys = c9_ys;
  *c9_b_zs = c9_zs;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c9_sfEvent);
}

static void initSimStructsc9_lab2_next_level(SFc9_lab2_next_levelInstanceStruct *
  chartInstance)
{
}

static void registerMessagesc9_lab2_next_level
  (SFc9_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber)
{
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc9_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static real_T c9_emlrt_marshallIn(SFc9_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c9_zs, const char_T *c9_identifier)
{
  real_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_zs), &c9_thisId);
  sf_mex_destroy(&c9_zs);
  return c9_y;
}

static real_T c9_b_emlrt_marshallIn(SFc9_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_zs;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc9_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c9_zs = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_zs), &c9_thisId);
  sf_mex_destroy(&c9_zs);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i15;
  real_T c9_b_inData[3];
  int32_T c9_i16;
  real_T c9_u[3];
  const mxArray *c9_y = NULL;
  SFc9_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc9_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i15 = 0; c9_i15 < 3; c9_i15++) {
    c9_b_inData[c9_i15] = (*(real_T (*)[3])c9_inData)[c9_i15];
  }

  for (c9_i16 = 0; c9_i16 < 3; c9_i16++) {
    c9_u[c9_i16] = c9_b_inData[c9_i16];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static void c9_c_emlrt_marshallIn(SFc9_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[3])
{
  real_T c9_dv1[3];
  int32_T c9_i17;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c9_i17 = 0; c9_i17 < 3; c9_i17++) {
    c9_y[c9_i17] = c9_dv1[c9_i17];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_M;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[3];
  int32_T c9_i18;
  SFc9_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc9_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c9_M = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_M), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_M);
  for (c9_i18 = 0; c9_i18 < 3; c9_i18++) {
    (*(real_T (*)[3])c9_outData)[c9_i18] = c9_y[c9_i18];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i19;
  int32_T c9_i20;
  int32_T c9_i21;
  real_T c9_b_inData[9];
  int32_T c9_i22;
  int32_T c9_i23;
  int32_T c9_i24;
  real_T c9_u[9];
  const mxArray *c9_y = NULL;
  SFc9_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc9_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i19 = 0;
  for (c9_i20 = 0; c9_i20 < 3; c9_i20++) {
    for (c9_i21 = 0; c9_i21 < 3; c9_i21++) {
      c9_b_inData[c9_i21 + c9_i19] = (*(real_T (*)[9])c9_inData)[c9_i21 + c9_i19];
    }

    c9_i19 += 3;
  }

  c9_i22 = 0;
  for (c9_i23 = 0; c9_i23 < 3; c9_i23++) {
    for (c9_i24 = 0; c9_i24 < 3; c9_i24++) {
      c9_u[c9_i24 + c9_i22] = c9_b_inData[c9_i24 + c9_i22];
    }

    c9_i22 += 3;
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static void c9_d_emlrt_marshallIn(SFc9_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[9])
{
  real_T c9_dv2[9];
  int32_T c9_i25;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv2, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c9_i25 = 0; c9_i25 < 9; c9_i25++) {
    c9_y[c9_i25] = c9_dv2[c9_i25];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_CZ;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[9];
  int32_T c9_i26;
  int32_T c9_i27;
  int32_T c9_i28;
  SFc9_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc9_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c9_CZ = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_CZ), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_CZ);
  c9_i26 = 0;
  for (c9_i27 = 0; c9_i27 < 3; c9_i27++) {
    for (c9_i28 = 0; c9_i28 < 3; c9_i28++) {
      (*(real_T (*)[9])c9_outData)[c9_i28 + c9_i26] = c9_y[c9_i28 + c9_i26];
    }

    c9_i26 += 3;
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray *sf_c9_lab2_next_level_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo;
  c9_ResolvedFunctionInfo c9_info[13];
  const mxArray *c9_m0 = NULL;
  int32_T c9_i29;
  c9_ResolvedFunctionInfo *c9_r0;
  c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  c9_info_helper(c9_info);
  sf_mex_assign(&c9_m0, sf_mex_createstruct("nameCaptureInfo", 1, 13), FALSE);
  for (c9_i29 = 0; c9_i29 < 13; c9_i29++) {
    c9_r0 = &c9_info[c9_i29];
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->context)), "context", "nameCaptureInfo",
                    c9_i29);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c9_r0->name)), "name", "nameCaptureInfo", c9_i29);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c9_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c9_i29);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->resolved)), "resolved", "nameCaptureInfo",
                    c9_i29);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c9_i29);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c9_i29);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c9_i29);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c9_i29);
  }

  sf_mex_assign(&c9_nameCaptureInfo, c9_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c9_nameCaptureInfo);
  return c9_nameCaptureInfo;
}

static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[13])
{
  c9_info[0].context = "";
  c9_info[0].name = "cos";
  c9_info[0].dominantType = "double";
  c9_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c9_info[0].fileTimeLo = 1343823172U;
  c9_info[0].fileTimeHi = 0U;
  c9_info[0].mFileTimeLo = 0U;
  c9_info[0].mFileTimeHi = 0U;
  c9_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c9_info[1].name = "eml_scalar_cos";
  c9_info[1].dominantType = "double";
  c9_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c9_info[1].fileTimeLo = 1286811522U;
  c9_info[1].fileTimeHi = 0U;
  c9_info[1].mFileTimeLo = 0U;
  c9_info[1].mFileTimeHi = 0U;
  c9_info[2].context = "";
  c9_info[2].name = "sin";
  c9_info[2].dominantType = "double";
  c9_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c9_info[2].fileTimeLo = 1343823186U;
  c9_info[2].fileTimeHi = 0U;
  c9_info[2].mFileTimeLo = 0U;
  c9_info[2].mFileTimeHi = 0U;
  c9_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c9_info[3].name = "eml_scalar_sin";
  c9_info[3].dominantType = "double";
  c9_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c9_info[3].fileTimeLo = 1286811536U;
  c9_info[3].fileTimeHi = 0U;
  c9_info[3].mFileTimeLo = 0U;
  c9_info[3].mFileTimeHi = 0U;
  c9_info[4].context = "";
  c9_info[4].name = "mtimes";
  c9_info[4].dominantType = "double";
  c9_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[4].fileTimeLo = 1289512492U;
  c9_info[4].fileTimeHi = 0U;
  c9_info[4].mFileTimeLo = 0U;
  c9_info[4].mFileTimeHi = 0U;
  c9_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[5].name = "eml_index_class";
  c9_info[5].dominantType = "";
  c9_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[5].fileTimeLo = 1323163378U;
  c9_info[5].fileTimeHi = 0U;
  c9_info[5].mFileTimeLo = 0U;
  c9_info[5].mFileTimeHi = 0U;
  c9_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[6].name = "eml_scalar_eg";
  c9_info[6].dominantType = "double";
  c9_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[6].fileTimeLo = 1286811596U;
  c9_info[6].fileTimeHi = 0U;
  c9_info[6].mFileTimeLo = 0U;
  c9_info[6].mFileTimeHi = 0U;
  c9_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[7].name = "eml_xgemm";
  c9_info[7].dominantType = "char";
  c9_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c9_info[7].fileTimeLo = 1299069572U;
  c9_info[7].fileTimeHi = 0U;
  c9_info[7].mFileTimeLo = 0U;
  c9_info[7].mFileTimeHi = 0U;
  c9_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c9_info[8].name = "eml_blas_inline";
  c9_info[8].dominantType = "";
  c9_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c9_info[8].fileTimeLo = 1299069568U;
  c9_info[8].fileTimeHi = 0U;
  c9_info[8].mFileTimeLo = 0U;
  c9_info[8].mFileTimeHi = 0U;
  c9_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c9_info[9].name = "mtimes";
  c9_info[9].dominantType = "double";
  c9_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[9].fileTimeLo = 1289512492U;
  c9_info[9].fileTimeHi = 0U;
  c9_info[9].mFileTimeLo = 0U;
  c9_info[9].mFileTimeHi = 0U;
  c9_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c9_info[10].name = "eml_index_class";
  c9_info[10].dominantType = "";
  c9_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[10].fileTimeLo = 1323163378U;
  c9_info[10].fileTimeHi = 0U;
  c9_info[10].mFileTimeLo = 0U;
  c9_info[10].mFileTimeHi = 0U;
  c9_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c9_info[11].name = "eml_scalar_eg";
  c9_info[11].dominantType = "double";
  c9_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[11].fileTimeLo = 1286811596U;
  c9_info[11].fileTimeHi = 0U;
  c9_info[11].mFileTimeLo = 0U;
  c9_info[11].mFileTimeHi = 0U;
  c9_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c9_info[12].name = "eml_refblas_xgemm";
  c9_info[12].dominantType = "char";
  c9_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c9_info[12].fileTimeLo = 1299069574U;
  c9_info[12].fileTimeHi = 0U;
  c9_info[12].mFileTimeLo = 0U;
  c9_info[12].mFileTimeHi = 0U;
}

static void c9_eml_scalar_eg(SFc9_lab2_next_levelInstanceStruct *chartInstance)
{
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc9_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static int32_T c9_e_emlrt_marshallIn(SFc9_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i30;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i30, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i30;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc9_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_f_emlrt_marshallIn(SFc9_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_lab2_next_level, const char_T
  *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_lab2_next_level), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_lab2_next_level);
  return c9_y;
}

static uint8_T c9_g_emlrt_marshallIn(SFc9_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info(SFc9_lab2_next_levelInstanceStruct
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

void sf_c9_lab2_next_level_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(54446043U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2774213296U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2600016809U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4271680100U);
}

mxArray *sf_c9_lab2_next_level_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("cmW80VUOzaTBi5fNhkvrFB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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

mxArray *sf_c9_lab2_next_level_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c9_lab2_next_level(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[10],T\"xs\",},{M[1],M[11],T\"ys\",},{M[1],M[12],T\"zs\",},{M[8],M[0],T\"is_active_c9_lab2_next_level\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_lab2_next_level_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_lab2_next_levelInstanceStruct *chartInstance;
    chartInstance = (SFc9_lab2_next_levelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _lab2_next_levelMachineNumber_,
           9,
           1,
           1,
           7,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"yaw");
          _SFD_SET_DATA_PROPS(1,1,1,0,"x");
          _SFD_SET_DATA_PROPS(2,1,1,0,"y");
          _SFD_SET_DATA_PROPS(3,1,1,0,"z");
          _SFD_SET_DATA_PROPS(4,2,0,1,"xs");
          _SFD_SET_DATA_PROPS(5,2,0,1,"ys");
          _SFD_SET_DATA_PROPS(6,2,0,1,"zs");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,277);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);

        {
          real_T *c9_yaw;
          real_T *c9_x;
          real_T *c9_y;
          real_T *c9_z;
          real_T *c9_xs;
          real_T *c9_ys;
          real_T *c9_zs;
          c9_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c9_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c9_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c9_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c9_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c9_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c9_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c9_yaw);
          _SFD_SET_DATA_VALUE_PTR(1U, c9_x);
          _SFD_SET_DATA_VALUE_PTR(2U, c9_y);
          _SFD_SET_DATA_VALUE_PTR(3U, c9_z);
          _SFD_SET_DATA_VALUE_PTR(4U, c9_xs);
          _SFD_SET_DATA_VALUE_PTR(5U, c9_ys);
          _SFD_SET_DATA_VALUE_PTR(6U, c9_zs);
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
  return "28KCbfErGjxDpdInGI7L7E";
}

static void sf_opaque_initialize_c9_lab2_next_level(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_lab2_next_level((SFc9_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
  initialize_c9_lab2_next_level((SFc9_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c9_lab2_next_level(void *chartInstanceVar)
{
  enable_c9_lab2_next_level((SFc9_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c9_lab2_next_level(void *chartInstanceVar)
{
  disable_c9_lab2_next_level((SFc9_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c9_lab2_next_level(void *chartInstanceVar)
{
  sf_c9_lab2_next_level((SFc9_lab2_next_levelInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_lab2_next_level(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_lab2_next_level
    ((SFc9_lab2_next_levelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_lab2_next_level();/* state var info */
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

extern void sf_internal_set_sim_state_c9_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_lab2_next_level();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_lab2_next_level((SFc9_lab2_next_levelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_lab2_next_level(SimStruct* S)
{
  return sf_internal_get_sim_state_c9_lab2_next_level(S);
}

static void sf_opaque_set_sim_state_c9_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c9_lab2_next_level(S, st);
}

static void sf_opaque_terminate_c9_lab2_next_level(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_lab2_next_levelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_lab2_next_level_optimization_info();
    }

    finalize_c9_lab2_next_level((SFc9_lab2_next_levelInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_lab2_next_level((SFc9_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_lab2_next_level(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_lab2_next_level((SFc9_lab2_next_levelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,9,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,9);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3179002981U));
  ssSetChecksum1(S,(2137916771U));
  ssSetChecksum2(S,(1833269335U));
  ssSetChecksum3(S,(1185674678U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_lab2_next_level(SimStruct *S)
{
  SFc9_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc9_lab2_next_levelInstanceStruct *)utMalloc(sizeof
    (SFc9_lab2_next_levelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_lab2_next_levelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_lab2_next_level;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_lab2_next_level;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_lab2_next_level;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_lab2_next_level;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c9_lab2_next_level;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_lab2_next_level;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_lab2_next_level;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_lab2_next_level;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_lab2_next_level;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_lab2_next_level;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_lab2_next_level;
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

void c9_lab2_next_level_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_lab2_next_level(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_lab2_next_level(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_lab2_next_level(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_lab2_next_level_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
