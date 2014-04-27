/* Include files */

#include <stddef.h>
#include "blas.h"
#include "lab2_sfun.h"
#include "c2_lab2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lab2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[13] = { "max", "el", "nargin",
  "nargout", "etalX", "etalY", "etalH", "curX", "curY", "curH", "counter",
  "error", "way" };

/* Function Declarations */
static void initialize_c2_lab2(SFc2_lab2InstanceStruct *chartInstance);
static void initialize_params_c2_lab2(SFc2_lab2InstanceStruct *chartInstance);
static void enable_c2_lab2(SFc2_lab2InstanceStruct *chartInstance);
static void disable_c2_lab2(SFc2_lab2InstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_lab2(SFc2_lab2InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_lab2(SFc2_lab2InstanceStruct
  *chartInstance);
static void set_sim_state_c2_lab2(SFc2_lab2InstanceStruct *chartInstance, const
  mxArray *c2_st);
static void finalize_c2_lab2(SFc2_lab2InstanceStruct *chartInstance);
static void sf_c2_lab2(SFc2_lab2InstanceStruct *chartInstance);
static void initSimStructsc2_lab2(SFc2_lab2InstanceStruct *chartInstance);
static void registerMessagesc2_lab2(SFc2_lab2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_lab2InstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_b_emlrt_marshallIn(SFc2_lab2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_c_emlrt_marshallIn(SFc2_lab2InstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_lab2, const char_T *c2_identifier);
static uint8_T c2_d_emlrt_marshallIn(SFc2_lab2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_lab2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_lab2(SFc2_lab2InstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_lab2 = 0U;
}

static void initialize_params_c2_lab2(SFc2_lab2InstanceStruct *chartInstance)
{
}

static void enable_c2_lab2(SFc2_lab2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_lab2(SFc2_lab2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_lab2(SFc2_lab2InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_lab2(SFc2_lab2InstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_u;
  const mxArray *c2_b_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(1), FALSE);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_lab2;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_lab2(SFc2_lab2InstanceStruct *chartInstance, const
  mxArray *c2_st)
{
  const mxArray *c2_u;
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  chartInstance->c2_is_active_c2_lab2 = c2_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 0)), "is_active_c2_lab2");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_lab2(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_lab2(SFc2_lab2InstanceStruct *chartInstance)
{
}

static void sf_c2_lab2(SFc2_lab2InstanceStruct *chartInstance)
{
  int32_T c2_i0;
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_f_hoistedGlobal;
  real_T c2_g_hoistedGlobal;
  real_T c2_h_hoistedGlobal;
  real_T c2_etalX;
  real_T c2_etalY;
  real_T c2_etalH;
  real_T c2_curX;
  real_T c2_curY;
  real_T c2_curH;
  real_T c2_counter;
  real_T c2_error;
  int32_T c2_i1;
  real_T c2_way[30];
  uint32_T c2_debug_family_var_map[13];
  real_T c2_max;
  real_T c2_el;
  real_T c2_nargin = 9.0;
  real_T c2_nargout = 0.0;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_y;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_b_y;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_c_y;
  int32_T c2_i2;
  static char_T c2_cv0[14] = { 'l', 'a', 'b', '2', '/', 'C', 'o', 'n', 's', 't',
    'a', 'n', 't', '1' };

  char_T c2_u[14];
  const mxArray *c2_d_y = NULL;
  int32_T c2_i3;
  static char_T c2_cv1[5] = { 'V', 'a', 'l', 'u', 'e' };

  char_T c2_b_u[5];
  const mxArray *c2_e_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_f_y = NULL;
  int32_T c2_i4;
  static char_T c2_cv2[6] = { 'l', 'a', 'b', '2', '/', 'X' };

  char_T c2_d_u[6];
  const mxArray *c2_g_y = NULL;
  int32_T c2_i5;
  char_T c2_e_u[5];
  const mxArray *c2_h_y = NULL;
  real_T c2_f_u;
  const mxArray *c2_i_y = NULL;
  int32_T c2_i6;
  static char_T c2_cv3[6] = { 'l', 'a', 'b', '2', '/', 'Y' };

  char_T c2_g_u[6];
  const mxArray *c2_j_y = NULL;
  int32_T c2_i7;
  char_T c2_h_u[5];
  const mxArray *c2_k_y = NULL;
  real_T c2_i_u;
  const mxArray *c2_l_y = NULL;
  int32_T c2_i8;
  static char_T c2_cv4[6] = { 'l', 'a', 'b', '2', '/', 'H' };

  char_T c2_j_u[6];
  const mxArray *c2_m_y = NULL;
  int32_T c2_i9;
  char_T c2_k_u[5];
  const mxArray *c2_n_y = NULL;
  real_T c2_l_u;
  const mxArray *c2_o_y = NULL;
  real_T *c2_b_etalX;
  real_T *c2_b_etalY;
  real_T *c2_b_etalH;
  real_T *c2_b_curX;
  real_T *c2_b_curY;
  real_T *c2_b_curH;
  real_T *c2_b_counter;
  real_T *c2_b_error;
  real_T (*c2_b_way)[30];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c2_b_way = (real_T (*)[30])ssGetInputPortSignal(chartInstance->S, 8);
  c2_b_error = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c2_b_counter = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c2_b_curH = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_b_curY = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_curX = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_etalH = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_etalY = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_etalX = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_b_etalX, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_etalY, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_b_etalH, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_b_curX, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_b_curY, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_b_curH, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_b_counter, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_b_error, 7U);
  for (c2_i0 = 0; c2_i0 < 30; c2_i0++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_way)[c2_i0], 8U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_etalX;
  c2_b_hoistedGlobal = *c2_b_etalY;
  c2_c_hoistedGlobal = *c2_b_etalH;
  c2_d_hoistedGlobal = *c2_b_curX;
  c2_e_hoistedGlobal = *c2_b_curY;
  c2_f_hoistedGlobal = *c2_b_curH;
  c2_g_hoistedGlobal = *c2_b_counter;
  c2_h_hoistedGlobal = *c2_b_error;
  c2_etalX = c2_hoistedGlobal;
  c2_etalY = c2_b_hoistedGlobal;
  c2_etalH = c2_c_hoistedGlobal;
  c2_curX = c2_d_hoistedGlobal;
  c2_curY = c2_e_hoistedGlobal;
  c2_curH = c2_f_hoistedGlobal;
  c2_counter = c2_g_hoistedGlobal;
  c2_error = c2_h_hoistedGlobal;
  for (c2_i1 = 0; c2_i1 < 30; c2_i1++) {
    c2_way[c2_i1] = (*c2_b_way)[c2_i1];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_max, 0U, c2_b_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_el, 1U, c2_b_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 2U, c2_b_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 3U, c2_b_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_etalX, 4U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_etalY, 5U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_etalH, 6U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_curX, 7U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_curY, 8U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_curH, 9U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_counter, 10U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_error, 11U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_way, 12U, c2_sf_marshallOut);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_max = 10.0;
  c2_el = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_x = c2_etalX - c2_curX;
  c2_b_x = c2_x;
  c2_y = muDoubleScalarAbs(c2_b_x);
  guard1 = FALSE;
  guard2 = FALSE;
  guard3 = FALSE;
  if (CV_EML_COND(0, 1, 0, c2_y <= c2_error)) {
    c2_c_x = c2_etalY - c2_curY;
    c2_d_x = c2_c_x;
    c2_b_y = muDoubleScalarAbs(c2_d_x);
    if (CV_EML_COND(0, 1, 1, c2_b_y <= c2_error)) {
      c2_e_x = c2_etalH - c2_curH;
      c2_f_x = c2_e_x;
      c2_c_y = muDoubleScalarAbs(c2_f_x);
      if (CV_EML_COND(0, 1, 2, c2_c_y <= c2_error)) {
        if (CV_EML_COND(0, 1, 3, c2_counter < c2_max)) {
          CV_EML_MCDC(0, 1, 0, TRUE);
          CV_EML_IF(0, 1, 0, TRUE);
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
          c2_counter++;
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
          for (c2_i2 = 0; c2_i2 < 14; c2_i2++) {
            c2_u[c2_i2] = c2_cv0[c2_i2];
          }

          c2_d_y = NULL;
          sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1,
            14), FALSE);
          for (c2_i3 = 0; c2_i3 < 5; c2_i3++) {
            c2_b_u[c2_i3] = c2_cv1[c2_i3];
          }

          c2_e_y = NULL;
          sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1,
            5), FALSE);
          c2_c_u = c2_counter;
          c2_f_y = NULL;
          sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          sf_mex_call_debug("set_param", 0U, 3U, 14, c2_d_y, 14, c2_e_y, 14,
                            sf_mex_call_debug("num2str", 1U, 1U, 14, c2_f_y));
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
          for (c2_i4 = 0; c2_i4 < 6; c2_i4++) {
            c2_d_u[c2_i4] = c2_cv2[c2_i4];
          }

          c2_g_y = NULL;
          sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_d_u, 10, 0U, 1U, 0U, 2, 1,
            6), FALSE);
          for (c2_i5 = 0; c2_i5 < 5; c2_i5++) {
            c2_e_u[c2_i5] = c2_cv1[c2_i5];
          }

          c2_h_y = NULL;
          sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_e_u, 10, 0U, 1U, 0U, 2, 1,
            5), FALSE);
          c2_f_u = c2_way[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("way",
            (int32_T)_SFD_INTEGER_CHECK("counter", c2_counter), 1, 10, 1, 0) - 1];
          c2_i_y = NULL;
          sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          sf_mex_call_debug("set_param", 0U, 3U, 14, c2_g_y, 14, c2_h_y, 14,
                            sf_mex_call_debug("num2str", 1U, 1U, 14, c2_i_y));
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
          for (c2_i6 = 0; c2_i6 < 6; c2_i6++) {
            c2_g_u[c2_i6] = c2_cv3[c2_i6];
          }

          c2_j_y = NULL;
          sf_mex_assign(&c2_j_y, sf_mex_create("y", c2_g_u, 10, 0U, 1U, 0U, 2, 1,
            6), FALSE);
          for (c2_i7 = 0; c2_i7 < 5; c2_i7++) {
            c2_h_u[c2_i7] = c2_cv1[c2_i7];
          }

          c2_k_y = NULL;
          sf_mex_assign(&c2_k_y, sf_mex_create("y", c2_h_u, 10, 0U, 1U, 0U, 2, 1,
            5), FALSE);
          c2_i_u = c2_way[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("way",
            (int32_T)_SFD_INTEGER_CHECK("counter", c2_counter), 1, 10, 1, 0) + 9];
          c2_l_y = NULL;
          sf_mex_assign(&c2_l_y, sf_mex_create("y", &c2_i_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          sf_mex_call_debug("set_param", 0U, 3U, 14, c2_j_y, 14, c2_k_y, 14,
                            sf_mex_call_debug("num2str", 1U, 1U, 14, c2_l_y));
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
          for (c2_i8 = 0; c2_i8 < 6; c2_i8++) {
            c2_j_u[c2_i8] = c2_cv4[c2_i8];
          }

          c2_m_y = NULL;
          sf_mex_assign(&c2_m_y, sf_mex_create("y", c2_j_u, 10, 0U, 1U, 0U, 2, 1,
            6), FALSE);
          for (c2_i9 = 0; c2_i9 < 5; c2_i9++) {
            c2_k_u[c2_i9] = c2_cv1[c2_i9];
          }

          c2_n_y = NULL;
          sf_mex_assign(&c2_n_y, sf_mex_create("y", c2_k_u, 10, 0U, 1U, 0U, 2, 1,
            5), FALSE);
          c2_l_u = c2_way[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("way",
            (int32_T)_SFD_INTEGER_CHECK("counter", c2_counter), 1, 10, 1, 0) +
            19];
          c2_o_y = NULL;
          sf_mex_assign(&c2_o_y, sf_mex_create("y", &c2_l_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          sf_mex_call_debug("set_param", 0U, 3U, 14, c2_m_y, 14, c2_n_y, 14,
                            sf_mex_call_debug("num2str", 1U, 1U, 14, c2_o_y));
        } else {
          guard1 = TRUE;
        }
      } else {
        guard2 = TRUE;
      }
    } else {
      guard3 = TRUE;
    }
  } else {
    guard3 = TRUE;
  }

  if (guard3 == TRUE) {
    guard2 = TRUE;
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 0, FALSE);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lab2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_lab2(SFc2_lab2InstanceStruct *chartInstance)
{
}

static void registerMessagesc2_lab2(SFc2_lab2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  real_T c2_b_inData[30];
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  real_T c2_u[30];
  const mxArray *c2_y = NULL;
  SFc2_lab2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lab2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i10 = 0;
  for (c2_i11 = 0; c2_i11 < 3; c2_i11++) {
    for (c2_i12 = 0; c2_i12 < 10; c2_i12++) {
      c2_b_inData[c2_i12 + c2_i10] = (*(real_T (*)[30])c2_inData)[c2_i12 +
        c2_i10];
    }

    c2_i10 += 10;
  }

  c2_i13 = 0;
  for (c2_i14 = 0; c2_i14 < 3; c2_i14++) {
    for (c2_i15 = 0; c2_i15 < 10; c2_i15++) {
      c2_u[c2_i15 + c2_i13] = c2_b_inData[c2_i15 + c2_i13];
    }

    c2_i13 += 10;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 10, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_lab2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lab2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_lab2InstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_lab2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lab2InstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_lab2_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[2];
  c2_ResolvedFunctionInfo (*c2_b_info)[2];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i16;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[2])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "abs";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c2_b_info)[0].fileTimeLo = 1343823166U;
  (*c2_b_info)[0].fileTimeHi = 0U;
  (*c2_b_info)[0].mFileTimeLo = 0U;
  (*c2_b_info)[0].mFileTimeHi = 0U;
  (*c2_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c2_b_info)[1].name = "eml_scalar_abs";
  (*c2_b_info)[1].dominantType = "double";
  (*c2_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  (*c2_b_info)[1].fileTimeLo = 1286811512U;
  (*c2_b_info)[1].fileTimeHi = 0U;
  (*c2_b_info)[1].mFileTimeLo = 0U;
  (*c2_b_info)[1].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 2), FALSE);
  for (c2_i16 = 0; c2_i16 < 2; c2_i16++) {
    c2_r0 = &c2_info[c2_i16];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i16);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i16);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i16);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i16);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i16);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i16);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i16);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i16);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_lab2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lab2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_b_emlrt_marshallIn(SFc2_lab2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i17;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i17, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i17;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_lab2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lab2InstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_c_emlrt_marshallIn(SFc2_lab2InstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_lab2, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_is_active_c2_lab2),
    &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_lab2);
  return c2_y;
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_lab2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_lab2InstanceStruct *chartInstance)
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

void sf_c2_lab2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1159678218U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3977586703U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3338960516U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3326871737U);
}

mxArray *sf_c2_lab2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("3EQqgL9v1xQRPpdIUX5BqF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,9,3,dataFields);

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
      pr[0] = (double)(10);
      pr[1] = (double)(3);
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

mxArray *sf_c2_lab2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c2_lab2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c2_lab2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_lab2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_lab2InstanceStruct *chartInstance;
    chartInstance = (SFc2_lab2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _lab2MachineNumber_,
           2,
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
          init_script_number_translation(_lab2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_lab2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _lab2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"etalX");
          _SFD_SET_DATA_PROPS(1,1,1,0,"etalY");
          _SFD_SET_DATA_PROPS(2,1,1,0,"etalH");
          _SFD_SET_DATA_PROPS(3,1,1,0,"curX");
          _SFD_SET_DATA_PROPS(4,1,1,0,"curY");
          _SFD_SET_DATA_PROPS(5,1,1,0,"curH");
          _SFD_SET_DATA_PROPS(6,1,1,0,"counter");
          _SFD_SET_DATA_PROPS(7,1,1,0,"error");
          _SFD_SET_DATA_PROPS(8,1,1,0,"way");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,4,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,511);
        _SFD_CV_INIT_EML_IF(0,1,0,157,249,-1,510);

        {
          static int condStart[] = { 160, 186, 212, 238 };

          static int condEnd[] = { 182, 208, 234, 249 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,160,249,4,0,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 10;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c2_etalX;
          real_T *c2_etalY;
          real_T *c2_etalH;
          real_T *c2_curX;
          real_T *c2_curY;
          real_T *c2_curH;
          real_T *c2_counter;
          real_T *c2_error;
          real_T (*c2_way)[30];
          c2_way = (real_T (*)[30])ssGetInputPortSignal(chartInstance->S, 8);
          c2_error = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c2_counter = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c2_curH = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c2_curY = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_curX = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_etalH = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_etalY = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_etalX = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_etalX);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_etalY);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_etalH);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_curX);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_curY);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_curH);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_counter);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_error);
          _SFD_SET_DATA_VALUE_PTR(8U, *c2_way);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _lab2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "8oTk7WRTw61VxDa434dhCE";
}

static void sf_opaque_initialize_c2_lab2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_lab2InstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c2_lab2((SFc2_lab2InstanceStruct*) chartInstanceVar);
  initialize_c2_lab2((SFc2_lab2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_lab2(void *chartInstanceVar)
{
  enable_c2_lab2((SFc2_lab2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_lab2(void *chartInstanceVar)
{
  disable_c2_lab2((SFc2_lab2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_lab2(void *chartInstanceVar)
{
  sf_c2_lab2((SFc2_lab2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_lab2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_lab2((SFc2_lab2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_lab2();/* state var info */
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

extern void sf_internal_set_sim_state_c2_lab2(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_lab2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_lab2((SFc2_lab2InstanceStruct*)chartInfo->chartInstance,
                        mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_lab2(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_lab2(S);
}

static void sf_opaque_set_sim_state_c2_lab2(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_lab2(S, st);
}

static void sf_opaque_terminate_c2_lab2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_lab2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_lab2_optimization_info();
    }

    finalize_c2_lab2((SFc2_lab2InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_lab2((SFc2_lab2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_lab2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_lab2((SFc2_lab2InstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_lab2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lab2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,9);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 9; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(846774487U));
  ssSetChecksum1(S,(1400184278U));
  ssSetChecksum2(S,(1823739226U));
  ssSetChecksum3(S,(940149216U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_lab2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_lab2(SimStruct *S)
{
  SFc2_lab2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lab2InstanceStruct *)utMalloc(sizeof
    (SFc2_lab2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_lab2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_lab2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_lab2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_lab2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_lab2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_lab2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_lab2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_lab2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_lab2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_lab2;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_lab2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_lab2;
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

void c2_lab2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_lab2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_lab2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_lab2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_lab2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
