/* Include files */

#include <stddef.h>
#include "blas.h"
#include "lab2_next_level_sfun.h"
#include "c11_lab2_next_level.h"
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
static const char * c11_debug_family_names[21] = { "cr", "sr", "cp", "sp", "cy",
  "sy", "CY", "CX", "CZ", "M", "nargin", "nargout", "roll", "pitch", "yaw", "x",
  "y", "z", "xs", "ys", "zs" };

/* Function Declarations */
static void initialize_c11_lab2_next_level(SFc11_lab2_next_levelInstanceStruct
  *chartInstance);
static void initialize_params_c11_lab2_next_level
  (SFc11_lab2_next_levelInstanceStruct *chartInstance);
static void enable_c11_lab2_next_level(SFc11_lab2_next_levelInstanceStruct
  *chartInstance);
static void disable_c11_lab2_next_level(SFc11_lab2_next_levelInstanceStruct
  *chartInstance);
static void c11_update_debugger_state_c11_lab2_next_level
  (SFc11_lab2_next_levelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_lab2_next_level
  (SFc11_lab2_next_levelInstanceStruct *chartInstance);
static void set_sim_state_c11_lab2_next_level
  (SFc11_lab2_next_levelInstanceStruct *chartInstance, const mxArray *c11_st);
static void finalize_c11_lab2_next_level(SFc11_lab2_next_levelInstanceStruct
  *chartInstance);
static void sf_c11_lab2_next_level(SFc11_lab2_next_levelInstanceStruct
  *chartInstance);
static void c11_chartstep_c11_lab2_next_level
  (SFc11_lab2_next_levelInstanceStruct *chartInstance);
static void initSimStructsc11_lab2_next_level
  (SFc11_lab2_next_levelInstanceStruct *chartInstance);
static void registerMessagesc11_lab2_next_level
  (SFc11_lab2_next_levelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_zs, const char_T *c11_identifier);
static real_T c11_b_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_c_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[3]);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_d_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[9]);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static void c11_info_helper(c11_ResolvedFunctionInfo c11_info[13]);
static void c11_eml_scalar_eg(SFc11_lab2_next_levelInstanceStruct *chartInstance);
static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_e_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static uint8_T c11_f_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_lab2_next_level, const
  char_T *c11_identifier);
static uint8_T c11_g_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void init_dsm_address_info(SFc11_lab2_next_levelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_lab2_next_level(SFc11_lab2_next_levelInstanceStruct
  *chartInstance)
{
  chartInstance->c11_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c11_is_active_c11_lab2_next_level = 0U;
}

static void initialize_params_c11_lab2_next_level
  (SFc11_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void enable_c11_lab2_next_level(SFc11_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c11_lab2_next_level(SFc11_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c11_update_debugger_state_c11_lab2_next_level
  (SFc11_lab2_next_levelInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c11_lab2_next_level
  (SFc11_lab2_next_levelInstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  real_T c11_hoistedGlobal;
  real_T c11_u;
  const mxArray *c11_b_y = NULL;
  real_T c11_b_hoistedGlobal;
  real_T c11_b_u;
  const mxArray *c11_c_y = NULL;
  real_T c11_c_hoistedGlobal;
  real_T c11_c_u;
  const mxArray *c11_d_y = NULL;
  uint8_T c11_d_hoistedGlobal;
  uint8_T c11_d_u;
  const mxArray *c11_e_y = NULL;
  real_T *c11_xs;
  real_T *c11_ys;
  real_T *c11_zs;
  c11_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c11_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c11_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellarray(4), FALSE);
  c11_hoistedGlobal = *c11_xs;
  c11_u = c11_hoistedGlobal;
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_b_hoistedGlobal = *c11_ys;
  c11_b_u = c11_b_hoistedGlobal;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c11_y, 1, c11_c_y);
  c11_c_hoistedGlobal = *c11_zs;
  c11_c_u = c11_c_hoistedGlobal;
  c11_d_y = NULL;
  sf_mex_assign(&c11_d_y, sf_mex_create("y", &c11_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c11_y, 2, c11_d_y);
  c11_d_hoistedGlobal = chartInstance->c11_is_active_c11_lab2_next_level;
  c11_d_u = c11_d_hoistedGlobal;
  c11_e_y = NULL;
  sf_mex_assign(&c11_e_y, sf_mex_create("y", &c11_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c11_y, 3, c11_e_y);
  sf_mex_assign(&c11_st, c11_y, FALSE);
  return c11_st;
}

static void set_sim_state_c11_lab2_next_level
  (SFc11_lab2_next_levelInstanceStruct *chartInstance, const mxArray *c11_st)
{
  const mxArray *c11_u;
  real_T *c11_xs;
  real_T *c11_ys;
  real_T *c11_zs;
  c11_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c11_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c11_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c11_doneDoubleBufferReInit = TRUE;
  c11_u = sf_mex_dup(c11_st);
  *c11_xs = c11_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u,
    0)), "xs");
  *c11_ys = c11_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u,
    1)), "ys");
  *c11_zs = c11_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u,
    2)), "zs");
  chartInstance->c11_is_active_c11_lab2_next_level = c11_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 3)),
     "is_active_c11_lab2_next_level");
  sf_mex_destroy(&c11_u);
  c11_update_debugger_state_c11_lab2_next_level(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void finalize_c11_lab2_next_level(SFc11_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

static void sf_c11_lab2_next_level(SFc11_lab2_next_levelInstanceStruct
  *chartInstance)
{
  real_T *c11_roll;
  real_T *c11_pitch;
  real_T *c11_yaw;
  real_T *c11_x;
  real_T *c11_y;
  real_T *c11_z;
  real_T *c11_xs;
  real_T *c11_ys;
  real_T *c11_zs;
  c11_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c11_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c11_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c11_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c11_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c11_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c11_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c11_roll = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c11_roll, 0U);
  _SFD_DATA_RANGE_CHECK(*c11_pitch, 1U);
  _SFD_DATA_RANGE_CHECK(*c11_yaw, 2U);
  _SFD_DATA_RANGE_CHECK(*c11_x, 3U);
  _SFD_DATA_RANGE_CHECK(*c11_y, 4U);
  _SFD_DATA_RANGE_CHECK(*c11_z, 5U);
  _SFD_DATA_RANGE_CHECK(*c11_xs, 6U);
  _SFD_DATA_RANGE_CHECK(*c11_ys, 7U);
  _SFD_DATA_RANGE_CHECK(*c11_zs, 8U);
  chartInstance->c11_sfEvent = CALL_EVENT;
  c11_chartstep_c11_lab2_next_level(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lab2_next_levelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c11_chartstep_c11_lab2_next_level
  (SFc11_lab2_next_levelInstanceStruct *chartInstance)
{
  real_T c11_hoistedGlobal;
  real_T c11_b_hoistedGlobal;
  real_T c11_c_hoistedGlobal;
  real_T c11_d_hoistedGlobal;
  real_T c11_e_hoistedGlobal;
  real_T c11_f_hoistedGlobal;
  real_T c11_roll;
  real_T c11_pitch;
  real_T c11_yaw;
  real_T c11_x;
  real_T c11_y;
  real_T c11_z;
  uint32_T c11_debug_family_var_map[21];
  real_T c11_cr;
  real_T c11_sr;
  real_T c11_cp;
  real_T c11_sp;
  real_T c11_cy;
  real_T c11_sy;
  real_T c11_CY[9];
  real_T c11_CX[9];
  real_T c11_CZ[9];
  real_T c11_M[3];
  real_T c11_nargin = 6.0;
  real_T c11_nargout = 3.0;
  real_T c11_xs;
  real_T c11_ys;
  real_T c11_zs;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_f_x;
  real_T c11_g_x;
  real_T c11_h_x;
  real_T c11_i_x;
  int32_T c11_i0;
  int32_T c11_i1;
  static real_T c11_dv0[3] = { 0.0, 1.0, 0.0 };

  int32_T c11_i2;
  int32_T c11_i3;
  static real_T c11_dv1[3] = { 1.0, 0.0, 0.0 };

  int32_T c11_i4;
  int32_T c11_i5;
  static real_T c11_dv2[3] = { 0.0, 0.0, 1.0 };

  int32_T c11_i6;
  int32_T c11_i7;
  int32_T c11_i8;
  int32_T c11_i9;
  real_T c11_a[9];
  real_T c11_b[3];
  int32_T c11_i10;
  int32_T c11_i11;
  int32_T c11_i12;
  real_T c11_C[3];
  int32_T c11_i13;
  int32_T c11_i14;
  int32_T c11_i15;
  int32_T c11_i16;
  int32_T c11_i17;
  int32_T c11_i18;
  real_T *c11_b_roll;
  real_T *c11_b_pitch;
  real_T *c11_b_yaw;
  real_T *c11_j_x;
  real_T *c11_b_y;
  real_T *c11_b_z;
  real_T *c11_b_xs;
  real_T *c11_b_ys;
  real_T *c11_b_zs;
  c11_b_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c11_b_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c11_b_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_b_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c11_b_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c11_j_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c11_b_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c11_b_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c11_b_roll = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
  c11_hoistedGlobal = *c11_b_roll;
  c11_b_hoistedGlobal = *c11_b_pitch;
  c11_c_hoistedGlobal = *c11_b_yaw;
  c11_d_hoistedGlobal = *c11_j_x;
  c11_e_hoistedGlobal = *c11_b_y;
  c11_f_hoistedGlobal = *c11_b_z;
  c11_roll = c11_hoistedGlobal;
  c11_pitch = c11_b_hoistedGlobal;
  c11_yaw = c11_c_hoistedGlobal;
  c11_x = c11_d_hoistedGlobal;
  c11_y = c11_e_hoistedGlobal;
  c11_z = c11_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 21U, 21U, c11_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_cr, 0U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_sr, 1U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_cp, 2U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_sp, 3U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_cy, 4U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_sy, 5U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_CY, 6U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_CX, 7U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_CZ, 8U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_M, 9U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 10U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 11U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_roll, 12U, c11_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_pitch, 13U, c11_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_yaw, 14U, c11_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_x, 15U, c11_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_y, 16U, c11_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_z, 17U, c11_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_xs, 18U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_ys, 19U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_zs, 20U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 6);
  c11_roll = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 6);
  c11_pitch = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_cr = 0.0;
  c11_b_x = c11_cr;
  c11_cr = c11_b_x;
  c11_cr = muDoubleScalarCos(c11_cr);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_sr = 0.0;
  c11_c_x = c11_sr;
  c11_sr = c11_c_x;
  c11_sr = muDoubleScalarSin(c11_sr);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 9);
  c11_cp = 0.0;
  c11_d_x = c11_cp;
  c11_cp = c11_d_x;
  c11_cp = muDoubleScalarCos(c11_cp);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 9);
  c11_sp = 0.0;
  c11_e_x = c11_sp;
  c11_sp = c11_e_x;
  c11_sp = muDoubleScalarSin(c11_sp);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 10);
  c11_f_x = c11_yaw;
  c11_cy = c11_f_x;
  c11_g_x = c11_cy;
  c11_cy = c11_g_x;
  c11_cy = muDoubleScalarCos(c11_cy);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 10);
  c11_h_x = c11_yaw;
  c11_sy = c11_h_x;
  c11_i_x = c11_sy;
  c11_sy = c11_i_x;
  c11_sy = muDoubleScalarSin(c11_sy);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 12);
  c11_CY[0] = c11_cp;
  c11_CY[3] = 0.0;
  c11_CY[6] = -c11_sp;
  c11_i0 = 0;
  for (c11_i1 = 0; c11_i1 < 3; c11_i1++) {
    c11_CY[c11_i0 + 1] = c11_dv0[c11_i1];
    c11_i0 += 3;
  }

  c11_CY[2] = c11_sp;
  c11_CY[5] = 0.0;
  c11_CY[8] = c11_cp;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 13);
  c11_i2 = 0;
  for (c11_i3 = 0; c11_i3 < 3; c11_i3++) {
    c11_CX[c11_i2] = c11_dv1[c11_i3];
    c11_i2 += 3;
  }

  c11_CX[1] = 0.0;
  c11_CX[4] = c11_cr;
  c11_CX[7] = c11_sr;
  c11_CX[2] = 0.0;
  c11_CX[5] = -c11_sr;
  c11_CX[8] = c11_cr;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 14);
  c11_CZ[0] = c11_cy;
  c11_CZ[3] = c11_sy;
  c11_CZ[6] = 0.0;
  c11_CZ[1] = -c11_sy;
  c11_CZ[4] = c11_cy;
  c11_CZ[7] = 0.0;
  c11_i4 = 0;
  for (c11_i5 = 0; c11_i5 < 3; c11_i5++) {
    c11_CZ[c11_i4 + 2] = c11_dv2[c11_i5];
    c11_i4 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 16);
  c11_i6 = 0;
  for (c11_i7 = 0; c11_i7 < 3; c11_i7++) {
    c11_i8 = 0;
    for (c11_i9 = 0; c11_i9 < 3; c11_i9++) {
      c11_a[c11_i9 + c11_i6] = c11_CZ[c11_i8 + c11_i7];
      c11_i8 += 3;
    }

    c11_i6 += 3;
  }

  c11_b[0] = c11_x;
  c11_b[1] = c11_y;
  c11_b[2] = c11_z;
  c11_eml_scalar_eg(chartInstance);
  c11_eml_scalar_eg(chartInstance);
  for (c11_i10 = 0; c11_i10 < 3; c11_i10++) {
    c11_M[c11_i10] = 0.0;
  }

  for (c11_i11 = 0; c11_i11 < 3; c11_i11++) {
    c11_M[c11_i11] = 0.0;
  }

  for (c11_i12 = 0; c11_i12 < 3; c11_i12++) {
    c11_C[c11_i12] = c11_M[c11_i12];
  }

  for (c11_i13 = 0; c11_i13 < 3; c11_i13++) {
    c11_M[c11_i13] = c11_C[c11_i13];
  }

  for (c11_i14 = 0; c11_i14 < 3; c11_i14++) {
    c11_C[c11_i14] = c11_M[c11_i14];
  }

  for (c11_i15 = 0; c11_i15 < 3; c11_i15++) {
    c11_M[c11_i15] = c11_C[c11_i15];
  }

  for (c11_i16 = 0; c11_i16 < 3; c11_i16++) {
    c11_M[c11_i16] = 0.0;
    c11_i17 = 0;
    for (c11_i18 = 0; c11_i18 < 3; c11_i18++) {
      c11_M[c11_i16] += c11_a[c11_i17 + c11_i16] * c11_b[c11_i18];
      c11_i17 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 18);
  c11_xs = c11_M[0];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 19);
  c11_ys = c11_M[1];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 20);
  c11_zs = c11_M[2];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
  *c11_b_xs = c11_xs;
  *c11_b_ys = c11_ys;
  *c11_b_zs = c11_zs;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
}

static void initSimStructsc11_lab2_next_level
  (SFc11_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void registerMessagesc11_lab2_next_level
  (SFc11_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber)
{
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc11_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static real_T c11_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_zs, const char_T *c11_identifier)
{
  real_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_zs), &c11_thisId);
  sf_mex_destroy(&c11_zs);
  return c11_y;
}

static real_T c11_b_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d0;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d0, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_zs;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc11_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c11_zs = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_zs), &c11_thisId);
  sf_mex_destroy(&c11_zs);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i19;
  real_T c11_b_inData[3];
  int32_T c11_i20;
  real_T c11_u[3];
  const mxArray *c11_y = NULL;
  SFc11_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc11_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i19 = 0; c11_i19 < 3; c11_i19++) {
    c11_b_inData[c11_i19] = (*(real_T (*)[3])c11_inData)[c11_i19];
  }

  for (c11_i20 = 0; c11_i20 < 3; c11_i20++) {
    c11_u[c11_i20] = c11_b_inData[c11_i20];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static void c11_c_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[3])
{
  real_T c11_dv3[3];
  int32_T c11_i21;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c11_i21 = 0; c11_i21 < 3; c11_i21++) {
    c11_y[c11_i21] = c11_dv3[c11_i21];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_M;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[3];
  int32_T c11_i22;
  SFc11_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc11_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c11_M = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_M), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_M);
  for (c11_i22 = 0; c11_i22 < 3; c11_i22++) {
    (*(real_T (*)[3])c11_outData)[c11_i22] = c11_y[c11_i22];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i23;
  int32_T c11_i24;
  int32_T c11_i25;
  real_T c11_b_inData[9];
  int32_T c11_i26;
  int32_T c11_i27;
  int32_T c11_i28;
  real_T c11_u[9];
  const mxArray *c11_y = NULL;
  SFc11_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc11_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_i23 = 0;
  for (c11_i24 = 0; c11_i24 < 3; c11_i24++) {
    for (c11_i25 = 0; c11_i25 < 3; c11_i25++) {
      c11_b_inData[c11_i25 + c11_i23] = (*(real_T (*)[9])c11_inData)[c11_i25 +
        c11_i23];
    }

    c11_i23 += 3;
  }

  c11_i26 = 0;
  for (c11_i27 = 0; c11_i27 < 3; c11_i27++) {
    for (c11_i28 = 0; c11_i28 < 3; c11_i28++) {
      c11_u[c11_i28 + c11_i26] = c11_b_inData[c11_i28 + c11_i26];
    }

    c11_i26 += 3;
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static void c11_d_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[9])
{
  real_T c11_dv4[9];
  int32_T c11_i29;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv4, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c11_i29 = 0; c11_i29 < 9; c11_i29++) {
    c11_y[c11_i29] = c11_dv4[c11_i29];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_CZ;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[9];
  int32_T c11_i30;
  int32_T c11_i31;
  int32_T c11_i32;
  SFc11_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc11_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c11_CZ = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_CZ), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_CZ);
  c11_i30 = 0;
  for (c11_i31 = 0; c11_i31 < 3; c11_i31++) {
    for (c11_i32 = 0; c11_i32 < 3; c11_i32++) {
      (*(real_T (*)[9])c11_outData)[c11_i32 + c11_i30] = c11_y[c11_i32 + c11_i30];
    }

    c11_i30 += 3;
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

const mxArray *sf_c11_lab2_next_level_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo;
  c11_ResolvedFunctionInfo c11_info[13];
  const mxArray *c11_m0 = NULL;
  int32_T c11_i33;
  c11_ResolvedFunctionInfo *c11_r0;
  c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  c11_info_helper(c11_info);
  sf_mex_assign(&c11_m0, sf_mex_createstruct("nameCaptureInfo", 1, 13), FALSE);
  for (c11_i33 = 0; c11_i33 < 13; c11_i33++) {
    c11_r0 = &c11_info[c11_i33];
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->context)), "context", "nameCaptureInfo",
                    c11_i33);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->name)), "name", "nameCaptureInfo",
                    c11_i33);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      c11_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c11_i33);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->resolved)), "resolved",
                    "nameCaptureInfo", c11_i33);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c11_i33);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c11_i33);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      &c11_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c11_i33);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      &c11_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c11_i33);
  }

  sf_mex_assign(&c11_nameCaptureInfo, c11_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c11_nameCaptureInfo);
  return c11_nameCaptureInfo;
}

static void c11_info_helper(c11_ResolvedFunctionInfo c11_info[13])
{
  c11_info[0].context = "";
  c11_info[0].name = "cos";
  c11_info[0].dominantType = "double";
  c11_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c11_info[0].fileTimeLo = 1343823172U;
  c11_info[0].fileTimeHi = 0U;
  c11_info[0].mFileTimeLo = 0U;
  c11_info[0].mFileTimeHi = 0U;
  c11_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c11_info[1].name = "eml_scalar_cos";
  c11_info[1].dominantType = "double";
  c11_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c11_info[1].fileTimeLo = 1286811522U;
  c11_info[1].fileTimeHi = 0U;
  c11_info[1].mFileTimeLo = 0U;
  c11_info[1].mFileTimeHi = 0U;
  c11_info[2].context = "";
  c11_info[2].name = "sin";
  c11_info[2].dominantType = "double";
  c11_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c11_info[2].fileTimeLo = 1343823186U;
  c11_info[2].fileTimeHi = 0U;
  c11_info[2].mFileTimeLo = 0U;
  c11_info[2].mFileTimeHi = 0U;
  c11_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c11_info[3].name = "eml_scalar_sin";
  c11_info[3].dominantType = "double";
  c11_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c11_info[3].fileTimeLo = 1286811536U;
  c11_info[3].fileTimeHi = 0U;
  c11_info[3].mFileTimeLo = 0U;
  c11_info[3].mFileTimeHi = 0U;
  c11_info[4].context = "";
  c11_info[4].name = "mtimes";
  c11_info[4].dominantType = "double";
  c11_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[4].fileTimeLo = 1289512492U;
  c11_info[4].fileTimeHi = 0U;
  c11_info[4].mFileTimeLo = 0U;
  c11_info[4].mFileTimeHi = 0U;
  c11_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[5].name = "eml_index_class";
  c11_info[5].dominantType = "";
  c11_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[5].fileTimeLo = 1323163378U;
  c11_info[5].fileTimeHi = 0U;
  c11_info[5].mFileTimeLo = 0U;
  c11_info[5].mFileTimeHi = 0U;
  c11_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[6].name = "eml_scalar_eg";
  c11_info[6].dominantType = "double";
  c11_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c11_info[6].fileTimeLo = 1286811596U;
  c11_info[6].fileTimeHi = 0U;
  c11_info[6].mFileTimeLo = 0U;
  c11_info[6].mFileTimeHi = 0U;
  c11_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[7].name = "eml_xgemm";
  c11_info[7].dominantType = "char";
  c11_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c11_info[7].fileTimeLo = 1299069572U;
  c11_info[7].fileTimeHi = 0U;
  c11_info[7].mFileTimeLo = 0U;
  c11_info[7].mFileTimeHi = 0U;
  c11_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c11_info[8].name = "eml_blas_inline";
  c11_info[8].dominantType = "";
  c11_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c11_info[8].fileTimeLo = 1299069568U;
  c11_info[8].fileTimeHi = 0U;
  c11_info[8].mFileTimeLo = 0U;
  c11_info[8].mFileTimeHi = 0U;
  c11_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c11_info[9].name = "mtimes";
  c11_info[9].dominantType = "double";
  c11_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[9].fileTimeLo = 1289512492U;
  c11_info[9].fileTimeHi = 0U;
  c11_info[9].mFileTimeLo = 0U;
  c11_info[9].mFileTimeHi = 0U;
  c11_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c11_info[10].name = "eml_index_class";
  c11_info[10].dominantType = "";
  c11_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[10].fileTimeLo = 1323163378U;
  c11_info[10].fileTimeHi = 0U;
  c11_info[10].mFileTimeLo = 0U;
  c11_info[10].mFileTimeHi = 0U;
  c11_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c11_info[11].name = "eml_scalar_eg";
  c11_info[11].dominantType = "double";
  c11_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c11_info[11].fileTimeLo = 1286811596U;
  c11_info[11].fileTimeHi = 0U;
  c11_info[11].mFileTimeLo = 0U;
  c11_info[11].mFileTimeHi = 0U;
  c11_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c11_info[12].name = "eml_refblas_xgemm";
  c11_info[12].dominantType = "char";
  c11_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c11_info[12].fileTimeLo = 1299069574U;
  c11_info[12].fileTimeHi = 0U;
  c11_info[12].mFileTimeLo = 0U;
  c11_info[12].mFileTimeHi = 0U;
}

static void c11_eml_scalar_eg(SFc11_lab2_next_levelInstanceStruct *chartInstance)
{
}

static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc11_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static int32_T c11_e_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i34;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i34, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i34;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc11_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static uint8_T c11_f_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_lab2_next_level, const
  char_T *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_is_active_c11_lab2_next_level), &c11_thisId);
  sf_mex_destroy(&c11_b_is_active_c11_lab2_next_level);
  return c11_y;
}

static uint8_T c11_g_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void init_dsm_address_info(SFc11_lab2_next_levelInstanceStruct
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

void sf_c11_lab2_next_level_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3570930181U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(846382114U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1793479374U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1541246823U);
}

mxArray *sf_c11_lab2_next_level_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("n6nBuPeBY7yju8R7q2K1xE");
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

mxArray *sf_c11_lab2_next_level_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c11_lab2_next_level(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[10],T\"xs\",},{M[1],M[11],T\"ys\",},{M[1],M[12],T\"zs\",},{M[8],M[0],T\"is_active_c11_lab2_next_level\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_lab2_next_level_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_lab2_next_levelInstanceStruct *chartInstance;
    chartInstance = (SFc11_lab2_next_levelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _lab2_next_levelMachineNumber_,
           11,
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
            (sfGlobalDebugInstanceStruct,_lab2_next_levelMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _lab2_next_levelMachineNumber_,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,434);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);

        {
          real_T *c11_roll;
          real_T *c11_pitch;
          real_T *c11_yaw;
          real_T *c11_x;
          real_T *c11_y;
          real_T *c11_z;
          real_T *c11_xs;
          real_T *c11_ys;
          real_T *c11_zs;
          c11_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c11_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c11_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c11_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c11_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c11_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c11_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c11_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c11_roll = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c11_roll);
          _SFD_SET_DATA_VALUE_PTR(1U, c11_pitch);
          _SFD_SET_DATA_VALUE_PTR(2U, c11_yaw);
          _SFD_SET_DATA_VALUE_PTR(3U, c11_x);
          _SFD_SET_DATA_VALUE_PTR(4U, c11_y);
          _SFD_SET_DATA_VALUE_PTR(5U, c11_z);
          _SFD_SET_DATA_VALUE_PTR(6U, c11_xs);
          _SFD_SET_DATA_VALUE_PTR(7U, c11_ys);
          _SFD_SET_DATA_VALUE_PTR(8U, c11_zs);
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
  return "V7UZcsPFAURUsscbhoFkH";
}

static void sf_opaque_initialize_c11_lab2_next_level(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_lab2_next_level((SFc11_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
  initialize_c11_lab2_next_level((SFc11_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c11_lab2_next_level(void *chartInstanceVar)
{
  enable_c11_lab2_next_level((SFc11_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c11_lab2_next_level(void *chartInstanceVar)
{
  disable_c11_lab2_next_level((SFc11_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c11_lab2_next_level(void *chartInstanceVar)
{
  sf_c11_lab2_next_level((SFc11_lab2_next_levelInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c11_lab2_next_level(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c11_lab2_next_level
    ((SFc11_lab2_next_levelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_lab2_next_level();/* state var info */
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

extern void sf_internal_set_sim_state_c11_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_lab2_next_level();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c11_lab2_next_level((SFc11_lab2_next_levelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c11_lab2_next_level(SimStruct* S)
{
  return sf_internal_get_sim_state_c11_lab2_next_level(S);
}

static void sf_opaque_set_sim_state_c11_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c11_lab2_next_level(S, st);
}

static void sf_opaque_terminate_c11_lab2_next_level(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_lab2_next_levelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_lab2_next_level_optimization_info();
    }

    finalize_c11_lab2_next_level((SFc11_lab2_next_levelInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc11_lab2_next_level((SFc11_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_lab2_next_level(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c11_lab2_next_level((SFc11_lab2_next_levelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c11_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,11,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,11,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,11);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,11,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,11,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3077166450U));
  ssSetChecksum1(S,(3203680416U));
  ssSetChecksum2(S,(1263371681U));
  ssSetChecksum3(S,(2558211767U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c11_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c11_lab2_next_level(SimStruct *S)
{
  SFc11_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc11_lab2_next_levelInstanceStruct *)utMalloc(sizeof
    (SFc11_lab2_next_levelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_lab2_next_levelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_lab2_next_level;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_lab2_next_level;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c11_lab2_next_level;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c11_lab2_next_level;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c11_lab2_next_level;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_lab2_next_level;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_lab2_next_level;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_lab2_next_level;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_lab2_next_level;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_lab2_next_level;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c11_lab2_next_level;
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

void c11_lab2_next_level_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_lab2_next_level(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_lab2_next_level(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_lab2_next_level(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_lab2_next_level_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}