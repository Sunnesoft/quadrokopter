/* Include files */

#include "blascompat32.h"
#include "lab2_next_level_sfun.h"
#include "c21_lab2_next_level.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lab2_next_level_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c21_debug_family_names[11] = { "s", "e", "M", "k", "w", "h",
  "nargin", "nargout", "signal", "wc", "y" };

/* Function Declarations */
static void initialize_c21_lab2_next_level(SFc21_lab2_next_levelInstanceStruct
  *chartInstance);
static void initialize_params_c21_lab2_next_level
  (SFc21_lab2_next_levelInstanceStruct *chartInstance);
static void enable_c21_lab2_next_level(SFc21_lab2_next_levelInstanceStruct
  *chartInstance);
static void disable_c21_lab2_next_level(SFc21_lab2_next_levelInstanceStruct
  *chartInstance);
static void c21_update_debugger_state_c21_lab2_next_level
  (SFc21_lab2_next_levelInstanceStruct *chartInstance);
static void ext_mode_exec_c21_lab2_next_level
  (SFc21_lab2_next_levelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c21_lab2_next_level
  (SFc21_lab2_next_levelInstanceStruct *chartInstance);
static void set_sim_state_c21_lab2_next_level
  (SFc21_lab2_next_levelInstanceStruct *chartInstance, const mxArray *c21_st);
static void finalize_c21_lab2_next_level(SFc21_lab2_next_levelInstanceStruct
  *chartInstance);
static void sf_c21_lab2_next_level(SFc21_lab2_next_levelInstanceStruct
  *chartInstance);
static void initSimStructsc21_lab2_next_level
  (SFc21_lab2_next_levelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber);
static const mxArray *c21_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static real_T c21_emlrt_marshallIn(SFc21_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c21_y, const char_T *c21_identifier);
static real_T c21_b_emlrt_marshallIn(SFc21_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static const mxArray *c21_b_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static const mxArray *c21_c_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static int32_T c21_c_emlrt_marshallIn(SFc21_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static uint8_T c21_d_emlrt_marshallIn(SFc21_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c21_is_active_c21_lab2_next_level, const char_T
  *c21_identifier);
static uint8_T c21_e_emlrt_marshallIn(SFc21_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void init_dsm_address_info(SFc21_lab2_next_levelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c21_lab2_next_level(SFc21_lab2_next_levelInstanceStruct
  *chartInstance)
{
  int32_T *c21_sfEvent;
  uint8_T *c21_is_active_c21_lab2_next_level;
  c21_is_active_c21_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c21_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c21_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c21_is_active_c21_lab2_next_level = 0U;
}

static void initialize_params_c21_lab2_next_level
  (SFc21_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void enable_c21_lab2_next_level(SFc21_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c21_lab2_next_level(SFc21_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c21_update_debugger_state_c21_lab2_next_level
  (SFc21_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c21_lab2_next_level
  (SFc21_lab2_next_levelInstanceStruct *chartInstance)
{
  c21_update_debugger_state_c21_lab2_next_level(chartInstance);
}

static const mxArray *get_sim_state_c21_lab2_next_level
  (SFc21_lab2_next_levelInstanceStruct *chartInstance)
{
  const mxArray *c21_st;
  const mxArray *c21_y = NULL;
  real_T c21_hoistedGlobal;
  real_T c21_u;
  const mxArray *c21_b_y = NULL;
  uint8_T c21_b_hoistedGlobal;
  uint8_T c21_b_u;
  const mxArray *c21_c_y = NULL;
  real_T *c21_d_y;
  uint8_T *c21_is_active_c21_lab2_next_level;
  c21_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c21_is_active_c21_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c21_st = NULL;
  c21_st = NULL;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_createcellarray(2), FALSE);
  c21_hoistedGlobal = *c21_d_y;
  c21_u = c21_hoistedGlobal;
  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", &c21_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c21_y, 0, c21_b_y);
  c21_b_hoistedGlobal = *c21_is_active_c21_lab2_next_level;
  c21_b_u = c21_b_hoistedGlobal;
  c21_c_y = NULL;
  sf_mex_assign(&c21_c_y, sf_mex_create("y", &c21_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c21_y, 1, c21_c_y);
  sf_mex_assign(&c21_st, c21_y, FALSE);
  return c21_st;
}

static void set_sim_state_c21_lab2_next_level
  (SFc21_lab2_next_levelInstanceStruct *chartInstance, const mxArray *c21_st)
{
  const mxArray *c21_u;
  boolean_T *c21_doneDoubleBufferReInit;
  real_T *c21_y;
  uint8_T *c21_is_active_c21_lab2_next_level;
  c21_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c21_is_active_c21_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c21_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c21_doneDoubleBufferReInit = TRUE;
  c21_u = sf_mex_dup(c21_st);
  *c21_y = c21_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c21_u,
    0)), "y");
  *c21_is_active_c21_lab2_next_level = c21_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c21_u, 1)), "is_active_c21_lab2_next_level");
  sf_mex_destroy(&c21_u);
  c21_update_debugger_state_c21_lab2_next_level(chartInstance);
  sf_mex_destroy(&c21_st);
}

static void finalize_c21_lab2_next_level(SFc21_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

static void sf_c21_lab2_next_level(SFc21_lab2_next_levelInstanceStruct
  *chartInstance)
{
  int32_T c21_i0;
  real_T c21_hoistedGlobal;
  int32_T c21_i1;
  real_T c21_signal[10];
  real_T c21_wc;
  uint32_T c21_debug_family_var_map[11];
  real_T c21_s;
  real_T c21_e;
  real_T c21_M;
  real_T c21_k;
  real_T c21_w;
  real_T c21_h;
  real_T c21_nargin = 2.0;
  real_T c21_nargout = 1.0;
  real_T c21_y;
  int32_T c21_i;
  real_T c21_b_i;
  real_T c21_b;
  real_T c21_b_y;
  real_T c21_A;
  real_T c21_x;
  real_T c21_b_x;
  real_T c21_b_A;
  real_T c21_c_x;
  real_T c21_d_x;
  real_T c21_c_y;
  real_T c21_a;
  real_T c21_b_b;
  real_T c21_d_y;
  real_T c21_b_a;
  real_T c21_c_b;
  real_T c21_e_y;
  real_T c21_c_a;
  real_T c21_d_b;
  real_T c21_f_y;
  real_T c21_e_x;
  real_T c21_f_x;
  real_T c21_e_b;
  real_T c21_g_y;
  real_T c21_c_A;
  real_T c21_B;
  real_T c21_g_x;
  real_T c21_h_y;
  real_T c21_h_x;
  real_T c21_i_y;
  real_T c21_d_a;
  real_T c21_f_b;
  real_T c21_j_y;
  real_T c21_e_a;
  real_T c21_g_b;
  real_T c21_k_y;
  real_T *c21_b_wc;
  real_T *c21_l_y;
  int32_T *c21_sfEvent;
  real_T (*c21_b_signal)[10];
  c21_b_wc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c21_l_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c21_b_signal = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 0);
  c21_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 14U, *c21_sfEvent);
  for (c21_i0 = 0; c21_i0 < 10; c21_i0++) {
    _SFD_DATA_RANGE_CHECK((*c21_b_signal)[c21_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c21_l_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c21_b_wc, 2U);
  *c21_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 14U, *c21_sfEvent);
  c21_hoistedGlobal = *c21_b_wc;
  for (c21_i1 = 0; c21_i1 < 10; c21_i1++) {
    c21_signal[c21_i1] = (*c21_b_signal)[c21_i1];
  }

  c21_wc = c21_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 11U, 11U, c21_debug_family_names,
    c21_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c21_s, 0U, c21_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c21_e, 1U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c21_M, 2U, c21_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c21_k, 3U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c21_w, 4U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c21_h, 5U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c21_nargin, 6U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c21_nargout, 7U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c21_signal, 8U, c21_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c21_wc, 9U, c21_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c21_y, 10U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c21_sfEvent, 4);
  c21_s = 10.0;
  c21_e = 1.0;
  _SFD_EML_CALL(0U, *c21_sfEvent, 5);
  c21_y = 0.0;
  _SFD_EML_CALL(0U, *c21_sfEvent, 7);
  c21_M = 10.0;
  _SFD_EML_CALL(0U, *c21_sfEvent, 9);
  c21_i = 0;
  while (c21_i < 10) {
    c21_b_i = 1.0 + (real_T)c21_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, *c21_sfEvent, 10);
    c21_k = c21_b_i - 1.0;
    _SFD_EML_CALL(0U, *c21_sfEvent, 11);
    c21_b = c21_k;
    c21_b_y = 2.0 * c21_b;
    c21_A = c21_b_y;
    c21_x = c21_A;
    c21_b_x = c21_x;
    c21_w = c21_b_x / 9.0;
    _SFD_EML_CALL(0U, *c21_sfEvent, 13);
    if (CV_EML_IF(0, 1, 0, c21_k > 5.0)) {
      _SFD_EML_CALL(0U, *c21_sfEvent, 14);
      c21_w = 2.0 - c21_w;
    }

    _SFD_EML_CALL(0U, *c21_sfEvent, 18);
    if (CV_EML_IF(0, 1, 1, c21_b_i != c21_s)) {
      _SFD_EML_CALL(0U, *c21_sfEvent, 19);
      c21_b_A = c21_wc;
      c21_c_x = c21_b_A;
      c21_d_x = c21_c_x;
      c21_c_y = c21_d_x / 3.1415926535897931;
      c21_h = 1.0 - c21_c_y;
      _SFD_EML_CALL(0U, *c21_sfEvent, 20);
      c21_a = c21_w;
      c21_b_b = c21_h;
      c21_d_y = c21_a * c21_b_b;
      c21_b_a = c21_d_y;
      c21_c_b = c21_signal[_SFD_EML_ARRAY_BOUNDS_CHECK("signal", (int32_T)
        _SFD_INTEGER_CHECK("s-k", c21_s - c21_k), 1, 10, 1, 0) - 1];
      c21_e_y = c21_b_a * c21_c_b;
      c21_y += c21_e_y;
      _SFD_EML_CALL(0U, *c21_sfEvent, 21);
    } else {
      _SFD_EML_CALL(0U, *c21_sfEvent, 24);
      c21_c_a = c21_wc;
      c21_d_b = c21_k - c21_M;
      c21_f_y = c21_c_a * c21_d_b;
      c21_e_x = c21_f_y;
      c21_f_x = c21_e_x;
      c21_f_x = muDoubleScalarSin(c21_f_x);
      c21_e_b = c21_k - c21_M;
      c21_g_y = 3.1415926535897931 * c21_e_b;
      c21_c_A = -c21_f_x;
      c21_B = c21_g_y;
      c21_g_x = c21_c_A;
      c21_h_y = c21_B;
      c21_h_x = c21_g_x;
      c21_i_y = c21_h_y;
      c21_h = c21_h_x / c21_i_y;
      _SFD_EML_CALL(0U, *c21_sfEvent, 25);
      c21_d_a = c21_w;
      c21_f_b = c21_h;
      c21_j_y = c21_d_a * c21_f_b;
      c21_e_a = c21_j_y;
      c21_g_b = c21_signal[_SFD_EML_ARRAY_BOUNDS_CHECK("signal", (int32_T)
        _SFD_INTEGER_CHECK("s-k", c21_s - c21_k), 1, 10, 1, 0) - 1];
      c21_k_y = c21_e_a * c21_g_b;
      c21_y += c21_k_y;
    }

    c21_i++;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, *c21_sfEvent, -25);
  sf_debug_symbol_scope_pop();
  *c21_l_y = c21_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, *c21_sfEvent);
  sf_debug_check_for_state_inconsistency(_lab2_next_levelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc21_lab2_next_level
  (SFc21_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber)
{
}

static const mxArray *c21_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  real_T c21_u;
  const mxArray *c21_y = NULL;
  SFc21_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc21_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_u = *(real_T *)c21_inData;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, FALSE);
  return c21_mxArrayOutData;
}

static real_T c21_emlrt_marshallIn(SFc21_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c21_y, const char_T *c21_identifier)
{
  real_T c21_b_y;
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_b_y = c21_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_y), &c21_thisId);
  sf_mex_destroy(&c21_y);
  return c21_b_y;
}

static real_T c21_b_emlrt_marshallIn(SFc21_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  real_T c21_y;
  real_T c21_d0;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_d0, 1, 0, 0U, 0, 0U, 0);
  c21_y = c21_d0;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_y;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  real_T c21_b_y;
  SFc21_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc21_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c21_y = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_b_y = c21_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_y), &c21_thisId);
  sf_mex_destroy(&c21_y);
  *(real_T *)c21_outData = c21_b_y;
  sf_mex_destroy(&c21_mxArrayInData);
}

static const mxArray *c21_b_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_i2;
  real_T c21_b_inData[10];
  int32_T c21_i3;
  real_T c21_u[10];
  const mxArray *c21_y = NULL;
  SFc21_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc21_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  for (c21_i2 = 0; c21_i2 < 10; c21_i2++) {
    c21_b_inData[c21_i2] = (*(real_T (*)[10])c21_inData)[c21_i2];
  }

  for (c21_i3 = 0; c21_i3 < 10; c21_i3++) {
    c21_u[c21_i3] = c21_b_inData[c21_i3];
  }

  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 0, 0U, 1U, 0U, 1, 10), FALSE);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, FALSE);
  return c21_mxArrayOutData;
}

const mxArray *sf_c21_lab2_next_level_get_eml_resolved_functions_info(void)
{
  const mxArray *c21_nameCaptureInfo;
  c21_ResolvedFunctionInfo c21_info[6];
  c21_ResolvedFunctionInfo (*c21_b_info)[6];
  const mxArray *c21_m0 = NULL;
  int32_T c21_i4;
  c21_ResolvedFunctionInfo *c21_r0;
  c21_nameCaptureInfo = NULL;
  c21_nameCaptureInfo = NULL;
  c21_b_info = (c21_ResolvedFunctionInfo (*)[6])c21_info;
  (*c21_b_info)[0].context = "";
  (*c21_b_info)[0].name = "mtimes";
  (*c21_b_info)[0].dominantType = "double";
  (*c21_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c21_b_info)[0].fileTimeLo = 1289508892U;
  (*c21_b_info)[0].fileTimeHi = 0U;
  (*c21_b_info)[0].mFileTimeLo = 0U;
  (*c21_b_info)[0].mFileTimeHi = 0U;
  (*c21_b_info)[1].context = "";
  (*c21_b_info)[1].name = "mrdivide";
  (*c21_b_info)[1].dominantType = "double";
  (*c21_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c21_b_info)[1].fileTimeLo = 1342803744U;
  (*c21_b_info)[1].fileTimeHi = 0U;
  (*c21_b_info)[1].mFileTimeLo = 1319722766U;
  (*c21_b_info)[1].mFileTimeHi = 0U;
  (*c21_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c21_b_info)[2].name = "rdivide";
  (*c21_b_info)[2].dominantType = "double";
  (*c21_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c21_b_info)[2].fileTimeLo = 1286811644U;
  (*c21_b_info)[2].fileTimeHi = 0U;
  (*c21_b_info)[2].mFileTimeLo = 0U;
  (*c21_b_info)[2].mFileTimeHi = 0U;
  (*c21_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c21_b_info)[3].name = "eml_div";
  (*c21_b_info)[3].dominantType = "double";
  (*c21_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c21_b_info)[3].fileTimeLo = 1313340610U;
  (*c21_b_info)[3].fileTimeHi = 0U;
  (*c21_b_info)[3].mFileTimeLo = 0U;
  (*c21_b_info)[3].mFileTimeHi = 0U;
  (*c21_b_info)[4].context = "";
  (*c21_b_info)[4].name = "sin";
  (*c21_b_info)[4].dominantType = "double";
  (*c21_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c21_b_info)[4].fileTimeLo = 1286811550U;
  (*c21_b_info)[4].fileTimeHi = 0U;
  (*c21_b_info)[4].mFileTimeLo = 0U;
  (*c21_b_info)[4].mFileTimeHi = 0U;
  (*c21_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c21_b_info)[5].name = "eml_scalar_sin";
  (*c21_b_info)[5].dominantType = "double";
  (*c21_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c21_b_info)[5].fileTimeLo = 1286811536U;
  (*c21_b_info)[5].fileTimeHi = 0U;
  (*c21_b_info)[5].mFileTimeLo = 0U;
  (*c21_b_info)[5].mFileTimeHi = 0U;
  sf_mex_assign(&c21_m0, sf_mex_createstruct("nameCaptureInfo", 1, 6), FALSE);
  for (c21_i4 = 0; c21_i4 < 6; c21_i4++) {
    c21_r0 = &c21_info[c21_i4];
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", c21_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c21_r0->context)), "context", "nameCaptureInfo",
                    c21_i4);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", c21_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c21_r0->name)), "name", "nameCaptureInfo", c21_i4);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo",
      c21_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c21_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c21_i4);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", c21_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c21_r0->resolved)), "resolved",
                    "nameCaptureInfo", c21_i4);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", &c21_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c21_i4);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", &c21_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c21_i4);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo",
      &c21_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c21_i4);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo",
      &c21_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c21_i4);
  }

  sf_mex_assign(&c21_nameCaptureInfo, c21_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c21_nameCaptureInfo);
  return c21_nameCaptureInfo;
}

static const mxArray *c21_c_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_u;
  const mxArray *c21_y = NULL;
  SFc21_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc21_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_u = *(int32_T *)c21_inData;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, FALSE);
  return c21_mxArrayOutData;
}

static int32_T c21_c_emlrt_marshallIn(SFc21_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  int32_T c21_y;
  int32_T c21_i5;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_i5, 1, 6, 0U, 0, 0U, 0);
  c21_y = c21_i5;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_sfEvent;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  int32_T c21_y;
  SFc21_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc21_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c21_sfEvent = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_sfEvent),
    &c21_thisId);
  sf_mex_destroy(&c21_sfEvent);
  *(int32_T *)c21_outData = c21_y;
  sf_mex_destroy(&c21_mxArrayInData);
}

static uint8_T c21_d_emlrt_marshallIn(SFc21_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c21_is_active_c21_lab2_next_level, const char_T
  *c21_identifier)
{
  uint8_T c21_y;
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c21_is_active_c21_lab2_next_level), &c21_thisId);
  sf_mex_destroy(&c21_is_active_c21_lab2_next_level);
  return c21_y;
}

static uint8_T c21_e_emlrt_marshallIn(SFc21_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  uint8_T c21_y;
  uint8_T c21_u0;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_u0, 1, 3, 0U, 0, 0U, 0);
  c21_y = c21_u0;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void init_dsm_address_info(SFc21_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c21_lab2_next_level_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(612317369U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(439322121U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3441690668U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3306924059U);
}

mxArray *sf_c21_lab2_next_level_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("yCEGEkS6FyFUqaAWsbj8L");
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

static const mxArray *sf_get_sim_state_info_c21_lab2_next_level(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c21_lab2_next_level\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c21_lab2_next_level_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc21_lab2_next_levelInstanceStruct *chartInstance;
    chartInstance = (SFc21_lab2_next_levelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_lab2_next_levelMachineNumber_,
           21,
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
            (_lab2_next_levelMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_lab2_next_levelMachineNumber_,
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
            1.0,0,0,(MexFcnForType)c21_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_sf_marshallOut,(MexInFcnForType)c21_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c21_y;
          real_T *c21_wc;
          real_T (*c21_signal)[10];
          c21_wc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c21_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c21_signal = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c21_signal);
          _SFD_SET_DATA_VALUE_PTR(1U, c21_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c21_wc);
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
  return "LmM1Rax0nqu4g4w1eNpScE";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 21, "dworkChecksum");
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

static void sf_opaque_initialize_c21_lab2_next_level(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc21_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc21_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c21_lab2_next_level((SFc21_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
  initialize_c21_lab2_next_level((SFc21_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c21_lab2_next_level(void *chartInstanceVar)
{
  enable_c21_lab2_next_level((SFc21_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c21_lab2_next_level(void *chartInstanceVar)
{
  disable_c21_lab2_next_level((SFc21_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c21_lab2_next_level(void *chartInstanceVar)
{
  sf_c21_lab2_next_level((SFc21_lab2_next_levelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c21_lab2_next_level(void *chartInstanceVar)
{
  ext_mode_exec_c21_lab2_next_level((SFc21_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c21_lab2_next_level(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c21_lab2_next_level
    ((SFc21_lab2_next_levelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c21_lab2_next_level();/* state var info */
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

extern void sf_internal_set_sim_state_c21_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c21_lab2_next_level();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c21_lab2_next_level((SFc21_lab2_next_levelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c21_lab2_next_level(SimStruct* S)
{
  return sf_internal_get_sim_state_c21_lab2_next_level(S);
}

static void sf_opaque_set_sim_state_c21_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c21_lab2_next_level(S, st);
}

static void sf_opaque_terminate_c21_lab2_next_level(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc21_lab2_next_levelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c21_lab2_next_level((SFc21_lab2_next_levelInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_lab2_next_level_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc21_lab2_next_level((SFc21_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c21_lab2_next_level(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c21_lab2_next_level((SFc21_lab2_next_levelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c21_lab2_next_level_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c21_lab2_next_level\",T\"is_active_c21_lab2_next_level\"}}"
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

static void mdlSetWorkWidths_c21_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      21);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,21,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,21,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,21,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,21,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,21);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2518649859U));
  ssSetChecksum1(S,(2149200829U));
  ssSetChecksum2(S,(1544303626U));
  ssSetChecksum3(S,(273527041U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c21_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c21_lab2_next_level(SimStruct *S)
{
  SFc21_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc21_lab2_next_levelInstanceStruct *)malloc(sizeof
    (SFc21_lab2_next_levelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc21_lab2_next_levelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c21_lab2_next_level;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c21_lab2_next_level;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c21_lab2_next_level;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c21_lab2_next_level;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c21_lab2_next_level;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c21_lab2_next_level;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c21_lab2_next_level;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c21_lab2_next_level;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c21_lab2_next_level;
  chartInstance->chartInfo.mdlStart = mdlStart_c21_lab2_next_level;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c21_lab2_next_level;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c21_lab2_next_level;
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

void c21_lab2_next_level_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c21_lab2_next_level(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c21_lab2_next_level(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c21_lab2_next_level(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c21_lab2_next_level_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
