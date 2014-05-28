/* Include files */

#include <stddef.h>
#include "blas.h"
#include "lab2_next_level_sfun.h"
#include "c31_lab2_next_level.h"
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
static const char * c31_debug_family_names[12] = { "s", "e", "M", "i", "k", "w",
  "h", "nargin", "nargout", "signal", "wc", "y" };

/* Function Declarations */
static void initialize_c31_lab2_next_level(SFc31_lab2_next_levelInstanceStruct
  *chartInstance);
static void initialize_params_c31_lab2_next_level
  (SFc31_lab2_next_levelInstanceStruct *chartInstance);
static void enable_c31_lab2_next_level(SFc31_lab2_next_levelInstanceStruct
  *chartInstance);
static void disable_c31_lab2_next_level(SFc31_lab2_next_levelInstanceStruct
  *chartInstance);
static void c31_update_debugger_state_c31_lab2_next_level
  (SFc31_lab2_next_levelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c31_lab2_next_level
  (SFc31_lab2_next_levelInstanceStruct *chartInstance);
static void set_sim_state_c31_lab2_next_level
  (SFc31_lab2_next_levelInstanceStruct *chartInstance, const mxArray *c31_st);
static void finalize_c31_lab2_next_level(SFc31_lab2_next_levelInstanceStruct
  *chartInstance);
static void sf_c31_lab2_next_level(SFc31_lab2_next_levelInstanceStruct
  *chartInstance);
static void initSimStructsc31_lab2_next_level
  (SFc31_lab2_next_levelInstanceStruct *chartInstance);
static void registerMessagesc31_lab2_next_level
  (SFc31_lab2_next_levelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c31_machineNumber, uint32_T
  c31_chartNumber);
static const mxArray *c31_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static real_T c31_emlrt_marshallIn(SFc31_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c31_y, const char_T *c31_identifier);
static real_T c31_b_emlrt_marshallIn(SFc31_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId);
static void c31_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static const mxArray *c31_b_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static const mxArray *c31_c_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static int32_T c31_c_emlrt_marshallIn(SFc31_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId);
static void c31_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static uint8_T c31_d_emlrt_marshallIn(SFc31_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c31_b_is_active_c31_lab2_next_level, const
  char_T *c31_identifier);
static uint8_T c31_e_emlrt_marshallIn(SFc31_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId);
static void init_dsm_address_info(SFc31_lab2_next_levelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c31_lab2_next_level(SFc31_lab2_next_levelInstanceStruct
  *chartInstance)
{
  chartInstance->c31_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c31_is_active_c31_lab2_next_level = 0U;
}

static void initialize_params_c31_lab2_next_level
  (SFc31_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void enable_c31_lab2_next_level(SFc31_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c31_lab2_next_level(SFc31_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c31_update_debugger_state_c31_lab2_next_level
  (SFc31_lab2_next_levelInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c31_lab2_next_level
  (SFc31_lab2_next_levelInstanceStruct *chartInstance)
{
  const mxArray *c31_st;
  const mxArray *c31_y = NULL;
  real_T c31_hoistedGlobal;
  real_T c31_u;
  const mxArray *c31_b_y = NULL;
  uint8_T c31_b_hoistedGlobal;
  uint8_T c31_b_u;
  const mxArray *c31_c_y = NULL;
  real_T *c31_d_y;
  c31_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c31_st = NULL;
  c31_st = NULL;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_createcellarray(2), FALSE);
  c31_hoistedGlobal = *c31_d_y;
  c31_u = c31_hoistedGlobal;
  c31_b_y = NULL;
  sf_mex_assign(&c31_b_y, sf_mex_create("y", &c31_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c31_y, 0, c31_b_y);
  c31_b_hoistedGlobal = chartInstance->c31_is_active_c31_lab2_next_level;
  c31_b_u = c31_b_hoistedGlobal;
  c31_c_y = NULL;
  sf_mex_assign(&c31_c_y, sf_mex_create("y", &c31_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c31_y, 1, c31_c_y);
  sf_mex_assign(&c31_st, c31_y, FALSE);
  return c31_st;
}

static void set_sim_state_c31_lab2_next_level
  (SFc31_lab2_next_levelInstanceStruct *chartInstance, const mxArray *c31_st)
{
  const mxArray *c31_u;
  real_T *c31_y;
  c31_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c31_doneDoubleBufferReInit = TRUE;
  c31_u = sf_mex_dup(c31_st);
  *c31_y = c31_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c31_u,
    0)), "y");
  chartInstance->c31_is_active_c31_lab2_next_level = c31_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c31_u, 1)),
     "is_active_c31_lab2_next_level");
  sf_mex_destroy(&c31_u);
  c31_update_debugger_state_c31_lab2_next_level(chartInstance);
  sf_mex_destroy(&c31_st);
}

static void finalize_c31_lab2_next_level(SFc31_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

static void sf_c31_lab2_next_level(SFc31_lab2_next_levelInstanceStruct
  *chartInstance)
{
  int32_T c31_i0;
  real_T c31_hoistedGlobal;
  int32_T c31_i1;
  real_T c31_signal[10];
  real_T c31_wc;
  uint32_T c31_debug_family_var_map[12];
  real_T c31_s;
  real_T c31_e;
  real_T c31_M;
  real_T c31_i;
  real_T c31_k;
  real_T c31_w;
  real_T c31_h;
  real_T c31_nargin = 2.0;
  real_T c31_nargout = 1.0;
  real_T c31_y;
  int32_T c31_b_i;
  real_T c31_b;
  real_T c31_b_y;
  real_T c31_A;
  real_T c31_x;
  real_T c31_b_x;
  real_T c31_b_A;
  real_T c31_c_x;
  real_T c31_d_x;
  real_T c31_c_y;
  real_T c31_a;
  real_T c31_b_b;
  real_T c31_d_y;
  real_T c31_b_a;
  real_T c31_c_b;
  real_T c31_e_y;
  real_T c31_c_a;
  real_T c31_d_b;
  real_T c31_f_y;
  real_T c31_e_x;
  real_T c31_f_x;
  real_T c31_e_b;
  real_T c31_g_y;
  real_T c31_c_A;
  real_T c31_B;
  real_T c31_g_x;
  real_T c31_h_y;
  real_T c31_h_x;
  real_T c31_i_y;
  real_T c31_d_a;
  real_T c31_f_b;
  real_T c31_j_y;
  real_T c31_e_a;
  real_T c31_g_b;
  real_T c31_k_y;
  real_T *c31_b_wc;
  real_T *c31_l_y;
  real_T (*c31_b_signal)[10];
  c31_b_wc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c31_l_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c31_b_signal = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 26U, chartInstance->c31_sfEvent);
  for (c31_i0 = 0; c31_i0 < 10; c31_i0++) {
    _SFD_DATA_RANGE_CHECK((*c31_b_signal)[c31_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c31_l_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c31_b_wc, 2U);
  chartInstance->c31_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 26U, chartInstance->c31_sfEvent);
  c31_hoistedGlobal = *c31_b_wc;
  for (c31_i1 = 0; c31_i1 < 10; c31_i1++) {
    c31_signal[c31_i1] = (*c31_b_signal)[c31_i1];
  }

  c31_wc = c31_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c31_debug_family_names,
    c31_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_s, 0U, c31_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_e, 1U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_M, 2U, c31_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_i, 3U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_k, 4U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_w, 5U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_h, 6U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_nargin, 7U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_nargout, 8U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c31_signal, 9U, c31_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_wc, 10U, c31_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_y, 11U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 4);
  c31_s = 10.0;
  c31_e = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 5);
  c31_y = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 7);
  c31_M = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 9);
  c31_i = 1.0;
  c31_b_i = 0;
  while (c31_b_i < 10) {
    c31_i = 1.0 + (real_T)c31_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 10);
    c31_k = c31_i - 1.0;
    _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 11);
    c31_b = c31_k;
    c31_b_y = 2.0 * c31_b;
    c31_A = c31_b_y;
    c31_x = c31_A;
    c31_b_x = c31_x;
    c31_w = c31_b_x / 9.0;
    _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 13);
    if (CV_EML_IF(0, 1, 0, c31_k > 5.0)) {
      _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 14);
      c31_w = 2.0 - c31_w;
    }

    _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 18);
    if (CV_EML_IF(0, 1, 1, c31_i != c31_s)) {
      _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 19);
      c31_b_A = c31_wc;
      c31_c_x = c31_b_A;
      c31_d_x = c31_c_x;
      c31_c_y = c31_d_x / 3.1415926535897931;
      c31_h = 1.0 - c31_c_y;
      _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 20);
      c31_a = c31_w;
      c31_b_b = c31_h;
      c31_d_y = c31_a * c31_b_b;
      c31_b_a = c31_d_y;
      c31_c_b = c31_signal[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("signal",
        (int32_T)_SFD_INTEGER_CHECK("s-k", c31_s - c31_k), 1, 10, 1, 0) - 1];
      c31_e_y = c31_b_a * c31_c_b;
      c31_y += c31_e_y;
      _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 21);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 24);
      c31_c_a = c31_wc;
      c31_d_b = c31_k - c31_M;
      c31_f_y = c31_c_a * c31_d_b;
      c31_e_x = c31_f_y;
      c31_f_x = c31_e_x;
      c31_f_x = muDoubleScalarSin(c31_f_x);
      c31_e_b = c31_k - c31_M;
      c31_g_y = 3.1415926535897931 * c31_e_b;
      c31_c_A = -c31_f_x;
      c31_B = c31_g_y;
      c31_g_x = c31_c_A;
      c31_h_y = c31_B;
      c31_h_x = c31_g_x;
      c31_i_y = c31_h_y;
      c31_h = c31_h_x / c31_i_y;
      _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 25);
      c31_d_a = c31_w;
      c31_f_b = c31_h;
      c31_j_y = c31_d_a * c31_f_b;
      c31_e_a = c31_j_y;
      c31_g_b = c31_signal[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("signal",
        (int32_T)_SFD_INTEGER_CHECK("s-k", c31_s - c31_k), 1, 10, 1, 0) - 1];
      c31_k_y = c31_e_a * c31_g_b;
      c31_y += c31_k_y;
    }

    c31_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, -25);
  _SFD_SYMBOL_SCOPE_POP();
  *c31_l_y = c31_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c31_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lab2_next_levelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc31_lab2_next_level
  (SFc31_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void registerMessagesc31_lab2_next_level
  (SFc31_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c31_machineNumber, uint32_T
  c31_chartNumber)
{
}

static const mxArray *c31_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  real_T c31_u;
  const mxArray *c31_y = NULL;
  SFc31_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc31_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  c31_u = *(real_T *)c31_inData;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", &c31_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, FALSE);
  return c31_mxArrayOutData;
}

static real_T c31_emlrt_marshallIn(SFc31_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c31_y, const char_T *c31_identifier)
{
  real_T c31_b_y;
  emlrtMsgIdentifier c31_thisId;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_b_y = c31_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_y), &c31_thisId);
  sf_mex_destroy(&c31_y);
  return c31_b_y;
}

static real_T c31_b_emlrt_marshallIn(SFc31_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId)
{
  real_T c31_y;
  real_T c31_d0;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), &c31_d0, 1, 0, 0U, 0, 0U, 0);
  c31_y = c31_d0;
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static void c31_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_y;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  real_T c31_b_y;
  SFc31_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc31_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c31_y = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_b_y = c31_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_y), &c31_thisId);
  sf_mex_destroy(&c31_y);
  *(real_T *)c31_outData = c31_b_y;
  sf_mex_destroy(&c31_mxArrayInData);
}

static const mxArray *c31_b_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  int32_T c31_i2;
  real_T c31_b_inData[10];
  int32_T c31_i3;
  real_T c31_u[10];
  const mxArray *c31_y = NULL;
  SFc31_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc31_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  for (c31_i2 = 0; c31_i2 < 10; c31_i2++) {
    c31_b_inData[c31_i2] = (*(real_T (*)[10])c31_inData)[c31_i2];
  }

  for (c31_i3 = 0; c31_i3 < 10; c31_i3++) {
    c31_u[c31_i3] = c31_b_inData[c31_i3];
  }

  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", c31_u, 0, 0U, 1U, 0U, 1, 10), FALSE);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, FALSE);
  return c31_mxArrayOutData;
}

const mxArray *sf_c31_lab2_next_level_get_eml_resolved_functions_info(void)
{
  const mxArray *c31_nameCaptureInfo;
  c31_ResolvedFunctionInfo c31_info[7];
  c31_ResolvedFunctionInfo (*c31_b_info)[7];
  const mxArray *c31_m0 = NULL;
  int32_T c31_i4;
  c31_ResolvedFunctionInfo *c31_r0;
  c31_nameCaptureInfo = NULL;
  c31_nameCaptureInfo = NULL;
  c31_b_info = (c31_ResolvedFunctionInfo (*)[7])c31_info;
  (*c31_b_info)[0].context = "";
  (*c31_b_info)[0].name = "mtimes";
  (*c31_b_info)[0].dominantType = "double";
  (*c31_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c31_b_info)[0].fileTimeLo = 1289512492U;
  (*c31_b_info)[0].fileTimeHi = 0U;
  (*c31_b_info)[0].mFileTimeLo = 0U;
  (*c31_b_info)[0].mFileTimeHi = 0U;
  (*c31_b_info)[1].context = "";
  (*c31_b_info)[1].name = "mrdivide";
  (*c31_b_info)[1].dominantType = "double";
  (*c31_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c31_b_info)[1].fileTimeLo = 1357944348U;
  (*c31_b_info)[1].fileTimeHi = 0U;
  (*c31_b_info)[1].mFileTimeLo = 1319722766U;
  (*c31_b_info)[1].mFileTimeHi = 0U;
  (*c31_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c31_b_info)[2].name = "rdivide";
  (*c31_b_info)[2].dominantType = "double";
  (*c31_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c31_b_info)[2].fileTimeLo = 1346503188U;
  (*c31_b_info)[2].fileTimeHi = 0U;
  (*c31_b_info)[2].mFileTimeLo = 0U;
  (*c31_b_info)[2].mFileTimeHi = 0U;
  (*c31_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c31_b_info)[3].name = "eml_scalexp_compatible";
  (*c31_b_info)[3].dominantType = "double";
  (*c31_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c31_b_info)[3].fileTimeLo = 1286811596U;
  (*c31_b_info)[3].fileTimeHi = 0U;
  (*c31_b_info)[3].mFileTimeLo = 0U;
  (*c31_b_info)[3].mFileTimeHi = 0U;
  (*c31_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c31_b_info)[4].name = "eml_div";
  (*c31_b_info)[4].dominantType = "double";
  (*c31_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c31_b_info)[4].fileTimeLo = 1313340610U;
  (*c31_b_info)[4].fileTimeHi = 0U;
  (*c31_b_info)[4].mFileTimeLo = 0U;
  (*c31_b_info)[4].mFileTimeHi = 0U;
  (*c31_b_info)[5].context = "";
  (*c31_b_info)[5].name = "sin";
  (*c31_b_info)[5].dominantType = "double";
  (*c31_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c31_b_info)[5].fileTimeLo = 1343823186U;
  (*c31_b_info)[5].fileTimeHi = 0U;
  (*c31_b_info)[5].mFileTimeLo = 0U;
  (*c31_b_info)[5].mFileTimeHi = 0U;
  (*c31_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c31_b_info)[6].name = "eml_scalar_sin";
  (*c31_b_info)[6].dominantType = "double";
  (*c31_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c31_b_info)[6].fileTimeLo = 1286811536U;
  (*c31_b_info)[6].fileTimeHi = 0U;
  (*c31_b_info)[6].mFileTimeLo = 0U;
  (*c31_b_info)[6].mFileTimeHi = 0U;
  sf_mex_assign(&c31_m0, sf_mex_createstruct("nameCaptureInfo", 1, 7), FALSE);
  for (c31_i4 = 0; c31_i4 < 7; c31_i4++) {
    c31_r0 = &c31_info[c31_i4];
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo", c31_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c31_r0->context)), "context", "nameCaptureInfo",
                    c31_i4);
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo", c31_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c31_r0->name)), "name", "nameCaptureInfo", c31_i4);
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo",
      c31_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c31_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c31_i4);
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo", c31_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c31_r0->resolved)), "resolved",
                    "nameCaptureInfo", c31_i4);
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo", &c31_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c31_i4);
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo", &c31_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c31_i4);
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo",
      &c31_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c31_i4);
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo",
      &c31_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c31_i4);
  }

  sf_mex_assign(&c31_nameCaptureInfo, c31_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c31_nameCaptureInfo);
  return c31_nameCaptureInfo;
}

static const mxArray *c31_c_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  int32_T c31_u;
  const mxArray *c31_y = NULL;
  SFc31_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc31_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  c31_u = *(int32_T *)c31_inData;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", &c31_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, FALSE);
  return c31_mxArrayOutData;
}

static int32_T c31_c_emlrt_marshallIn(SFc31_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId)
{
  int32_T c31_y;
  int32_T c31_i5;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), &c31_i5, 1, 6, 0U, 0, 0U, 0);
  c31_y = c31_i5;
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static void c31_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_b_sfEvent;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  int32_T c31_y;
  SFc31_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc31_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c31_b_sfEvent = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_y = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_b_sfEvent),
    &c31_thisId);
  sf_mex_destroy(&c31_b_sfEvent);
  *(int32_T *)c31_outData = c31_y;
  sf_mex_destroy(&c31_mxArrayInData);
}

static uint8_T c31_d_emlrt_marshallIn(SFc31_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c31_b_is_active_c31_lab2_next_level, const
  char_T *c31_identifier)
{
  uint8_T c31_y;
  emlrtMsgIdentifier c31_thisId;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_y = c31_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c31_b_is_active_c31_lab2_next_level), &c31_thisId);
  sf_mex_destroy(&c31_b_is_active_c31_lab2_next_level);
  return c31_y;
}

static uint8_T c31_e_emlrt_marshallIn(SFc31_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId)
{
  uint8_T c31_y;
  uint8_T c31_u0;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), &c31_u0, 1, 3, 0U, 0, 0U, 0);
  c31_y = c31_u0;
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static void init_dsm_address_info(SFc31_lab2_next_levelInstanceStruct
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

void sf_c31_lab2_next_level_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(612317369U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(439322121U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3441690668U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3306924059U);
}

mxArray *sf_c31_lab2_next_level_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("j33284cgAhzVWjnM0ydLmD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c31_lab2_next_level_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c31_lab2_next_level(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c31_lab2_next_level\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c31_lab2_next_level_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc31_lab2_next_levelInstanceStruct *chartInstance;
    chartInstance = (SFc31_lab2_next_levelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _lab2_next_levelMachineNumber_,
           31,
           1,
           1,
           3,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"signal");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"wc");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,329);
        _SFD_CV_INIT_EML_IF(0,1,0,128,139,-1,164);
        _SFD_CV_INIT_EML_IF(0,1,1,174,184,-1,-2);
        _SFD_CV_INIT_EML_FOR(0,1,0,77,89,329);
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
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c31_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)c31_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c31_y;
          real_T *c31_wc;
          real_T (*c31_signal)[10];
          c31_wc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c31_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c31_signal = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c31_signal);
          _SFD_SET_DATA_VALUE_PTR(1U, c31_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c31_wc);
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
  return "LmM1Rax0nqu4g4w1eNpScE";
}

static void sf_opaque_initialize_c31_lab2_next_level(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc31_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c31_lab2_next_level((SFc31_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
  initialize_c31_lab2_next_level((SFc31_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c31_lab2_next_level(void *chartInstanceVar)
{
  enable_c31_lab2_next_level((SFc31_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c31_lab2_next_level(void *chartInstanceVar)
{
  disable_c31_lab2_next_level((SFc31_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c31_lab2_next_level(void *chartInstanceVar)
{
  sf_c31_lab2_next_level((SFc31_lab2_next_levelInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c31_lab2_next_level(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c31_lab2_next_level
    ((SFc31_lab2_next_levelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c31_lab2_next_level();/* state var info */
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

extern void sf_internal_set_sim_state_c31_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c31_lab2_next_level();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c31_lab2_next_level((SFc31_lab2_next_levelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c31_lab2_next_level(SimStruct* S)
{
  return sf_internal_get_sim_state_c31_lab2_next_level(S);
}

static void sf_opaque_set_sim_state_c31_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c31_lab2_next_level(S, st);
}

static void sf_opaque_terminate_c31_lab2_next_level(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc31_lab2_next_levelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_lab2_next_level_optimization_info();
    }

    finalize_c31_lab2_next_level((SFc31_lab2_next_levelInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc31_lab2_next_level((SFc31_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c31_lab2_next_level(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c31_lab2_next_level((SFc31_lab2_next_levelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c31_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      31);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,31,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,31,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,31);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,31,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,31,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,31);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(330184875U));
  ssSetChecksum1(S,(1047203863U));
  ssSetChecksum2(S,(1267090024U));
  ssSetChecksum3(S,(3883413929U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c31_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c31_lab2_next_level(SimStruct *S)
{
  SFc31_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc31_lab2_next_levelInstanceStruct *)utMalloc(sizeof
    (SFc31_lab2_next_levelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc31_lab2_next_levelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c31_lab2_next_level;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c31_lab2_next_level;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c31_lab2_next_level;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c31_lab2_next_level;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c31_lab2_next_level;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c31_lab2_next_level;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c31_lab2_next_level;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c31_lab2_next_level;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c31_lab2_next_level;
  chartInstance->chartInfo.mdlStart = mdlStart_c31_lab2_next_level;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c31_lab2_next_level;
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

void c31_lab2_next_level_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c31_lab2_next_level(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c31_lab2_next_level(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c31_lab2_next_level(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c31_lab2_next_level_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
