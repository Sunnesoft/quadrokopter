/* Include files */

<<<<<<< HEAD
#include <stddef.h>
#include "blas.h"
=======
#include "blascompat32.h"
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
#include "lab2_next_level_sfun.h"
#include "c23_lab2_next_level.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lab2_next_level_sfun_debug_macros.h"
<<<<<<< HEAD
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);
=======
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
<<<<<<< HEAD
static const char * c23_debug_family_names[12] = { "s", "e", "M", "i", "k", "w",
  "h", "nargin", "nargout", "signal", "wc", "y" };
=======
static const char * c23_debug_family_names[11] = { "s", "e", "M", "k", "w", "h",
  "nargin", "nargout", "signal", "wc", "y" };
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711

/* Function Declarations */
static void initialize_c23_lab2_next_level(SFc23_lab2_next_levelInstanceStruct
  *chartInstance);
static void initialize_params_c23_lab2_next_level
  (SFc23_lab2_next_levelInstanceStruct *chartInstance);
static void enable_c23_lab2_next_level(SFc23_lab2_next_levelInstanceStruct
  *chartInstance);
static void disable_c23_lab2_next_level(SFc23_lab2_next_levelInstanceStruct
  *chartInstance);
static void c23_update_debugger_state_c23_lab2_next_level
  (SFc23_lab2_next_levelInstanceStruct *chartInstance);
<<<<<<< HEAD
=======
static void ext_mode_exec_c23_lab2_next_level
  (SFc23_lab2_next_levelInstanceStruct *chartInstance);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
static const mxArray *get_sim_state_c23_lab2_next_level
  (SFc23_lab2_next_levelInstanceStruct *chartInstance);
static void set_sim_state_c23_lab2_next_level
  (SFc23_lab2_next_levelInstanceStruct *chartInstance, const mxArray *c23_st);
static void finalize_c23_lab2_next_level(SFc23_lab2_next_levelInstanceStruct
  *chartInstance);
static void sf_c23_lab2_next_level(SFc23_lab2_next_levelInstanceStruct
  *chartInstance);
static void initSimStructsc23_lab2_next_level
  (SFc23_lab2_next_levelInstanceStruct *chartInstance);
<<<<<<< HEAD
static void registerMessagesc23_lab2_next_level
  (SFc23_lab2_next_levelInstanceStruct *chartInstance);
=======
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber);
static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static real_T c23_emlrt_marshallIn(SFc23_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c23_y, const char_T *c23_identifier);
static real_T c23_b_emlrt_marshallIn(SFc23_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static int32_T c23_c_emlrt_marshallIn(SFc23_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static uint8_T c23_d_emlrt_marshallIn(SFc23_lab2_next_levelInstanceStruct
<<<<<<< HEAD
  *chartInstance, const mxArray *c23_b_is_active_c23_lab2_next_level, const
  char_T *c23_identifier);
=======
  *chartInstance, const mxArray *c23_is_active_c23_lab2_next_level, const char_T
  *c23_identifier);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
static uint8_T c23_e_emlrt_marshallIn(SFc23_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void init_dsm_address_info(SFc23_lab2_next_levelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c23_lab2_next_level(SFc23_lab2_next_levelInstanceStruct
  *chartInstance)
{
<<<<<<< HEAD
  chartInstance->c23_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c23_is_active_c23_lab2_next_level = 0U;
=======
  int32_T *c23_sfEvent;
  uint8_T *c23_is_active_c23_lab2_next_level;
  c23_is_active_c23_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c23_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c23_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c23_is_active_c23_lab2_next_level = 0U;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
}

static void initialize_params_c23_lab2_next_level
  (SFc23_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void enable_c23_lab2_next_level(SFc23_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c23_lab2_next_level(SFc23_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c23_update_debugger_state_c23_lab2_next_level
  (SFc23_lab2_next_levelInstanceStruct *chartInstance)
{
}

<<<<<<< HEAD
=======
static void ext_mode_exec_c23_lab2_next_level
  (SFc23_lab2_next_levelInstanceStruct *chartInstance)
{
  c23_update_debugger_state_c23_lab2_next_level(chartInstance);
}

>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
static const mxArray *get_sim_state_c23_lab2_next_level
  (SFc23_lab2_next_levelInstanceStruct *chartInstance)
{
  const mxArray *c23_st;
  const mxArray *c23_y = NULL;
  real_T c23_hoistedGlobal;
  real_T c23_u;
  const mxArray *c23_b_y = NULL;
  uint8_T c23_b_hoistedGlobal;
  uint8_T c23_b_u;
  const mxArray *c23_c_y = NULL;
  real_T *c23_d_y;
<<<<<<< HEAD
  c23_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
=======
  uint8_T *c23_is_active_c23_lab2_next_level;
  c23_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c23_is_active_c23_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  c23_st = NULL;
  c23_st = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_createcellarray(2), FALSE);
  c23_hoistedGlobal = *c23_d_y;
  c23_u = c23_hoistedGlobal;
  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c23_y, 0, c23_b_y);
<<<<<<< HEAD
  c23_b_hoistedGlobal = chartInstance->c23_is_active_c23_lab2_next_level;
=======
  c23_b_hoistedGlobal = *c23_is_active_c23_lab2_next_level;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  c23_b_u = c23_b_hoistedGlobal;
  c23_c_y = NULL;
  sf_mex_assign(&c23_c_y, sf_mex_create("y", &c23_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c23_y, 1, c23_c_y);
  sf_mex_assign(&c23_st, c23_y, FALSE);
  return c23_st;
}

static void set_sim_state_c23_lab2_next_level
  (SFc23_lab2_next_levelInstanceStruct *chartInstance, const mxArray *c23_st)
{
  const mxArray *c23_u;
<<<<<<< HEAD
  real_T *c23_y;
  c23_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c23_doneDoubleBufferReInit = TRUE;
  c23_u = sf_mex_dup(c23_st);
  *c23_y = c23_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u,
    0)), "y");
  chartInstance->c23_is_active_c23_lab2_next_level = c23_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 1)),
     "is_active_c23_lab2_next_level");
=======
  boolean_T *c23_doneDoubleBufferReInit;
  real_T *c23_y;
  uint8_T *c23_is_active_c23_lab2_next_level;
  c23_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c23_is_active_c23_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c23_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c23_doneDoubleBufferReInit = TRUE;
  c23_u = sf_mex_dup(c23_st);
  *c23_y = c23_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u,
    0)), "y");
  *c23_is_active_c23_lab2_next_level = c23_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c23_u, 1)), "is_active_c23_lab2_next_level");
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  sf_mex_destroy(&c23_u);
  c23_update_debugger_state_c23_lab2_next_level(chartInstance);
  sf_mex_destroy(&c23_st);
}

static void finalize_c23_lab2_next_level(SFc23_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

static void sf_c23_lab2_next_level(SFc23_lab2_next_levelInstanceStruct
  *chartInstance)
{
  int32_T c23_i0;
  real_T c23_hoistedGlobal;
  int32_T c23_i1;
  real_T c23_signal[10];
  real_T c23_wc;
<<<<<<< HEAD
  uint32_T c23_debug_family_var_map[12];
  real_T c23_s;
  real_T c23_e;
  real_T c23_M;
  real_T c23_i;
=======
  uint32_T c23_debug_family_var_map[11];
  real_T c23_s;
  real_T c23_e;
  real_T c23_M;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  real_T c23_k;
  real_T c23_w;
  real_T c23_h;
  real_T c23_nargin = 2.0;
  real_T c23_nargout = 1.0;
  real_T c23_y;
<<<<<<< HEAD
  int32_T c23_b_i;
=======
  int32_T c23_i;
  real_T c23_b_i;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  real_T c23_b;
  real_T c23_b_y;
  real_T c23_A;
  real_T c23_x;
  real_T c23_b_x;
  real_T c23_c_y;
  real_T c23_c_x;
  real_T c23_d_x;
  real_T c23_b_b;
  real_T c23_b_A;
  real_T c23_e_x;
  real_T c23_f_x;
  real_T c23_d_y;
  real_T c23_a;
  real_T c23_c_b;
  real_T c23_e_y;
  real_T c23_b_a;
  real_T c23_d_b;
  real_T c23_f_y;
  real_T c23_c_a;
  real_T c23_e_b;
  real_T c23_g_y;
  real_T c23_g_x;
  real_T c23_h_x;
  real_T c23_f_b;
  real_T c23_h_y;
  real_T c23_c_A;
  real_T c23_B;
  real_T c23_i_x;
  real_T c23_i_y;
  real_T c23_j_x;
  real_T c23_j_y;
  real_T c23_d_a;
  real_T c23_g_b;
  real_T c23_k_y;
  real_T c23_e_a;
  real_T c23_h_b;
  real_T c23_l_y;
  real_T *c23_b_wc;
  real_T *c23_m_y;
<<<<<<< HEAD
=======
  int32_T *c23_sfEvent;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  real_T (*c23_b_signal)[10];
  c23_b_wc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c23_m_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c23_b_signal = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 0);
<<<<<<< HEAD
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 18U, chartInstance->c23_sfEvent);
=======
  c23_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 16U, *c23_sfEvent);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  for (c23_i0 = 0; c23_i0 < 10; c23_i0++) {
    _SFD_DATA_RANGE_CHECK((*c23_b_signal)[c23_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c23_m_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c23_b_wc, 2U);
<<<<<<< HEAD
  chartInstance->c23_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 18U, chartInstance->c23_sfEvent);
=======
  *c23_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 16U, *c23_sfEvent);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  c23_hoistedGlobal = *c23_b_wc;
  for (c23_i1 = 0; c23_i1 < 10; c23_i1++) {
    c23_signal[c23_i1] = (*c23_b_signal)[c23_i1];
  }

  c23_wc = c23_hoistedGlobal;
<<<<<<< HEAD
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c23_debug_family_names,
    c23_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c23_s, 0U, c23_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_e, 1U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c23_M, 2U, c23_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_i, 3U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_k, 4U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_w, 5U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_h, 6U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargin, 7U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargout, 8U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c23_signal, 9U, c23_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c23_wc, 10U, c23_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_y, 11U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 4);
  c23_s = 10.0;
  c23_e = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 5);
  c23_y = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 7);
  c23_M = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 9);
  c23_i = 1.0;
  c23_b_i = 0;
  while (c23_b_i < 10) {
    c23_i = 1.0 + (real_T)c23_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 10);
    c23_k = c23_i - 1.0;
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 12);
=======
  sf_debug_symbol_scope_push_eml(0U, 11U, 11U, c23_debug_family_names,
    c23_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c23_s, 0U, c23_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c23_e, 1U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c23_M, 2U, c23_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c23_k, 3U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c23_w, 4U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c23_h, 5U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c23_nargin, 6U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c23_nargout, 7U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c23_signal, 8U, c23_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c23_wc, 9U, c23_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c23_y, 10U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c23_sfEvent, 4);
  c23_s = 10.0;
  c23_e = 1.0;
  _SFD_EML_CALL(0U, *c23_sfEvent, 5);
  c23_y = 0.0;
  _SFD_EML_CALL(0U, *c23_sfEvent, 7);
  c23_M = 10.0;
  _SFD_EML_CALL(0U, *c23_sfEvent, 9);
  c23_i = 0;
  while (c23_i < 10) {
    c23_b_i = 1.0 + (real_T)c23_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, *c23_sfEvent, 10);
    c23_k = c23_b_i - 1.0;
    _SFD_EML_CALL(0U, *c23_sfEvent, 12);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
    c23_b = c23_k;
    c23_b_y = 6.2831853071795862 * c23_b;
    c23_A = c23_b_y;
    c23_x = c23_A;
    c23_b_x = c23_x;
    c23_c_y = c23_b_x / 9.0;
    c23_c_x = c23_c_y;
    c23_d_x = c23_c_x;
    c23_d_x = muDoubleScalarCos(c23_d_x);
    c23_b_b = 1.0 - c23_d_x;
    c23_w = 0.5 * c23_b_b;
<<<<<<< HEAD
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 14);
    if (CV_EML_IF(0, 1, 0, c23_i != c23_s)) {
      _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 15);
=======
    _SFD_EML_CALL(0U, *c23_sfEvent, 14);
    if (CV_EML_IF(0, 1, 0, c23_b_i != c23_s)) {
      _SFD_EML_CALL(0U, *c23_sfEvent, 15);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
      c23_b_A = c23_wc;
      c23_e_x = c23_b_A;
      c23_f_x = c23_e_x;
      c23_d_y = c23_f_x / 3.1415926535897931;
      c23_h = 1.0 - c23_d_y;
<<<<<<< HEAD
      _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 16);
=======
      _SFD_EML_CALL(0U, *c23_sfEvent, 16);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
      c23_a = c23_w;
      c23_c_b = c23_h;
      c23_e_y = c23_a * c23_c_b;
      c23_b_a = c23_e_y;
<<<<<<< HEAD
      c23_d_b = c23_signal[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("signal",
        (int32_T)_SFD_INTEGER_CHECK("s-k", c23_s - c23_k), 1, 10, 1, 0) - 1];
      c23_f_y = c23_b_a * c23_d_b;
      c23_y += c23_f_y;
      _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 17);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 20);
=======
      c23_d_b = c23_signal[_SFD_EML_ARRAY_BOUNDS_CHECK("signal", (int32_T)
        _SFD_INTEGER_CHECK("s-k", c23_s - c23_k), 1, 10, 1, 0) - 1];
      c23_f_y = c23_b_a * c23_d_b;
      c23_y += c23_f_y;
      _SFD_EML_CALL(0U, *c23_sfEvent, 17);
    } else {
      _SFD_EML_CALL(0U, *c23_sfEvent, 20);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
      c23_c_a = c23_wc;
      c23_e_b = c23_k - c23_M;
      c23_g_y = c23_c_a * c23_e_b;
      c23_g_x = c23_g_y;
      c23_h_x = c23_g_x;
      c23_h_x = muDoubleScalarSin(c23_h_x);
      c23_f_b = c23_k - c23_M;
      c23_h_y = 3.1415926535897931 * c23_f_b;
      c23_c_A = -c23_h_x;
      c23_B = c23_h_y;
      c23_i_x = c23_c_A;
      c23_i_y = c23_B;
      c23_j_x = c23_i_x;
      c23_j_y = c23_i_y;
      c23_h = c23_j_x / c23_j_y;
<<<<<<< HEAD
      _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 21);
=======
      _SFD_EML_CALL(0U, *c23_sfEvent, 21);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
      c23_d_a = c23_w;
      c23_g_b = c23_h;
      c23_k_y = c23_d_a * c23_g_b;
      c23_e_a = c23_k_y;
<<<<<<< HEAD
      c23_h_b = c23_signal[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("signal",
        (int32_T)_SFD_INTEGER_CHECK("s-k", c23_s - c23_k), 1, 10, 1, 0) - 1];
=======
      c23_h_b = c23_signal[_SFD_EML_ARRAY_BOUNDS_CHECK("signal", (int32_T)
        _SFD_INTEGER_CHECK("s-k", c23_s - c23_k), 1, 10, 1, 0) - 1];
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
      c23_l_y = c23_e_a * c23_h_b;
      c23_y += c23_l_y;
    }

<<<<<<< HEAD
    c23_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, -21);
  _SFD_SYMBOL_SCOPE_POP();
  *c23_m_y = c23_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c23_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lab2_next_levelMachineNumber_,
=======
    c23_i++;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, *c23_sfEvent, -21);
  sf_debug_symbol_scope_pop();
  *c23_m_y = c23_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, *c23_sfEvent);
  sf_debug_check_for_state_inconsistency(_lab2_next_levelMachineNumber_,
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc23_lab2_next_level
  (SFc23_lab2_next_levelInstanceStruct *chartInstance)
{
}

<<<<<<< HEAD
static void registerMessagesc23_lab2_next_level
  (SFc23_lab2_next_levelInstanceStruct *chartInstance)
{
}

=======
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber)
{
}

static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  real_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc23_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(real_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, FALSE);
  return c23_mxArrayOutData;
}

static real_T c23_emlrt_marshallIn(SFc23_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c23_y, const char_T *c23_identifier)
{
  real_T c23_b_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_b_y = c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_y), &c23_thisId);
  sf_mex_destroy(&c23_y);
  return c23_b_y;
}

static real_T c23_b_emlrt_marshallIn(SFc23_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  real_T c23_y;
  real_T c23_d0;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_d0, 1, 0, 0U, 0, 0U, 0);
  c23_y = c23_d0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_y;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_b_y;
  SFc23_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc23_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c23_y = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_b_y = c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_y), &c23_thisId);
  sf_mex_destroy(&c23_y);
  *(real_T *)c23_outData = c23_b_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_i2;
  real_T c23_b_inData[10];
  int32_T c23_i3;
  real_T c23_u[10];
  const mxArray *c23_y = NULL;
  SFc23_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc23_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  for (c23_i2 = 0; c23_i2 < 10; c23_i2++) {
    c23_b_inData[c23_i2] = (*(real_T (*)[10])c23_inData)[c23_i2];
  }

  for (c23_i3 = 0; c23_i3 < 10; c23_i3++) {
    c23_u[c23_i3] = c23_b_inData[c23_i3];
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 1, 10), FALSE);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, FALSE);
  return c23_mxArrayOutData;
}

const mxArray *sf_c23_lab2_next_level_get_eml_resolved_functions_info(void)
{
  const mxArray *c23_nameCaptureInfo;
<<<<<<< HEAD
  c23_ResolvedFunctionInfo c23_info[9];
  c23_ResolvedFunctionInfo (*c23_b_info)[9];
=======
  c23_ResolvedFunctionInfo c23_info[8];
  c23_ResolvedFunctionInfo (*c23_b_info)[8];
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  const mxArray *c23_m0 = NULL;
  int32_T c23_i4;
  c23_ResolvedFunctionInfo *c23_r0;
  c23_nameCaptureInfo = NULL;
  c23_nameCaptureInfo = NULL;
<<<<<<< HEAD
  c23_b_info = (c23_ResolvedFunctionInfo (*)[9])c23_info;
=======
  c23_b_info = (c23_ResolvedFunctionInfo (*)[8])c23_info;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  (*c23_b_info)[0].context = "";
  (*c23_b_info)[0].name = "mtimes";
  (*c23_b_info)[0].dominantType = "double";
  (*c23_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
<<<<<<< HEAD
  (*c23_b_info)[0].fileTimeLo = 1289512492U;
=======
  (*c23_b_info)[0].fileTimeLo = 1289508892U;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  (*c23_b_info)[0].fileTimeHi = 0U;
  (*c23_b_info)[0].mFileTimeLo = 0U;
  (*c23_b_info)[0].mFileTimeHi = 0U;
  (*c23_b_info)[1].context = "";
  (*c23_b_info)[1].name = "mrdivide";
  (*c23_b_info)[1].dominantType = "double";
  (*c23_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
<<<<<<< HEAD
  (*c23_b_info)[1].fileTimeLo = 1357944348U;
=======
  (*c23_b_info)[1].fileTimeLo = 1342803744U;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  (*c23_b_info)[1].fileTimeHi = 0U;
  (*c23_b_info)[1].mFileTimeLo = 1319722766U;
  (*c23_b_info)[1].mFileTimeHi = 0U;
  (*c23_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c23_b_info)[2].name = "rdivide";
  (*c23_b_info)[2].dominantType = "double";
  (*c23_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
<<<<<<< HEAD
  (*c23_b_info)[2].fileTimeLo = 1346503188U;
=======
  (*c23_b_info)[2].fileTimeLo = 1286811644U;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  (*c23_b_info)[2].fileTimeHi = 0U;
  (*c23_b_info)[2].mFileTimeLo = 0U;
  (*c23_b_info)[2].mFileTimeHi = 0U;
  (*c23_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
<<<<<<< HEAD
  (*c23_b_info)[3].name = "eml_scalexp_compatible";
  (*c23_b_info)[3].dominantType = "double";
  (*c23_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c23_b_info)[3].fileTimeLo = 1286811596U;
  (*c23_b_info)[3].fileTimeHi = 0U;
  (*c23_b_info)[3].mFileTimeLo = 0U;
  (*c23_b_info)[3].mFileTimeHi = 0U;
  (*c23_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c23_b_info)[4].name = "eml_div";
  (*c23_b_info)[4].dominantType = "double";
  (*c23_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c23_b_info)[4].fileTimeLo = 1313340610U;
  (*c23_b_info)[4].fileTimeHi = 0U;
  (*c23_b_info)[4].mFileTimeLo = 0U;
  (*c23_b_info)[4].mFileTimeHi = 0U;
  (*c23_b_info)[5].context = "";
  (*c23_b_info)[5].name = "cos";
  (*c23_b_info)[5].dominantType = "double";
  (*c23_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c23_b_info)[5].fileTimeLo = 1343823172U;
  (*c23_b_info)[5].fileTimeHi = 0U;
  (*c23_b_info)[5].mFileTimeLo = 0U;
  (*c23_b_info)[5].mFileTimeHi = 0U;
  (*c23_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c23_b_info)[6].name = "eml_scalar_cos";
  (*c23_b_info)[6].dominantType = "double";
  (*c23_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c23_b_info)[6].fileTimeLo = 1286811522U;
  (*c23_b_info)[6].fileTimeHi = 0U;
  (*c23_b_info)[6].mFileTimeLo = 0U;
  (*c23_b_info)[6].mFileTimeHi = 0U;
  (*c23_b_info)[7].context = "";
  (*c23_b_info)[7].name = "sin";
  (*c23_b_info)[7].dominantType = "double";
  (*c23_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c23_b_info)[7].fileTimeLo = 1343823186U;
  (*c23_b_info)[7].fileTimeHi = 0U;
  (*c23_b_info)[7].mFileTimeLo = 0U;
  (*c23_b_info)[7].mFileTimeHi = 0U;
  (*c23_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c23_b_info)[8].name = "eml_scalar_sin";
  (*c23_b_info)[8].dominantType = "double";
  (*c23_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c23_b_info)[8].fileTimeLo = 1286811536U;
  (*c23_b_info)[8].fileTimeHi = 0U;
  (*c23_b_info)[8].mFileTimeLo = 0U;
  (*c23_b_info)[8].mFileTimeHi = 0U;
  sf_mex_assign(&c23_m0, sf_mex_createstruct("nameCaptureInfo", 1, 9), FALSE);
  for (c23_i4 = 0; c23_i4 < 9; c23_i4++) {
=======
  (*c23_b_info)[3].name = "eml_div";
  (*c23_b_info)[3].dominantType = "double";
  (*c23_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c23_b_info)[3].fileTimeLo = 1313340610U;
  (*c23_b_info)[3].fileTimeHi = 0U;
  (*c23_b_info)[3].mFileTimeLo = 0U;
  (*c23_b_info)[3].mFileTimeHi = 0U;
  (*c23_b_info)[4].context = "";
  (*c23_b_info)[4].name = "cos";
  (*c23_b_info)[4].dominantType = "double";
  (*c23_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c23_b_info)[4].fileTimeLo = 1286811506U;
  (*c23_b_info)[4].fileTimeHi = 0U;
  (*c23_b_info)[4].mFileTimeLo = 0U;
  (*c23_b_info)[4].mFileTimeHi = 0U;
  (*c23_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c23_b_info)[5].name = "eml_scalar_cos";
  (*c23_b_info)[5].dominantType = "double";
  (*c23_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c23_b_info)[5].fileTimeLo = 1286811522U;
  (*c23_b_info)[5].fileTimeHi = 0U;
  (*c23_b_info)[5].mFileTimeLo = 0U;
  (*c23_b_info)[5].mFileTimeHi = 0U;
  (*c23_b_info)[6].context = "";
  (*c23_b_info)[6].name = "sin";
  (*c23_b_info)[6].dominantType = "double";
  (*c23_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c23_b_info)[6].fileTimeLo = 1286811550U;
  (*c23_b_info)[6].fileTimeHi = 0U;
  (*c23_b_info)[6].mFileTimeLo = 0U;
  (*c23_b_info)[6].mFileTimeHi = 0U;
  (*c23_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c23_b_info)[7].name = "eml_scalar_sin";
  (*c23_b_info)[7].dominantType = "double";
  (*c23_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c23_b_info)[7].fileTimeLo = 1286811536U;
  (*c23_b_info)[7].fileTimeHi = 0U;
  (*c23_b_info)[7].mFileTimeLo = 0U;
  (*c23_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c23_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8), FALSE);
  for (c23_i4 = 0; c23_i4 < 8; c23_i4++) {
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
    c23_r0 = &c23_info[c23_i4];
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", c23_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c23_r0->context)), "context", "nameCaptureInfo",
                    c23_i4);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", c23_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c23_r0->name)), "name", "nameCaptureInfo", c23_i4);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo",
      c23_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c23_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c23_i4);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", c23_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c23_r0->resolved)), "resolved",
                    "nameCaptureInfo", c23_i4);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", &c23_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c23_i4);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", &c23_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c23_i4);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo",
      &c23_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c23_i4);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo",
      &c23_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c23_i4);
  }

  sf_mex_assign(&c23_nameCaptureInfo, c23_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c23_nameCaptureInfo);
  return c23_nameCaptureInfo;
}

static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc23_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(int32_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, FALSE);
  return c23_mxArrayOutData;
}

static int32_T c23_c_emlrt_marshallIn(SFc23_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  int32_T c23_y;
  int32_T c23_i5;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_i5, 1, 6, 0U, 0, 0U, 0);
  c23_y = c23_i5;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
<<<<<<< HEAD
  const mxArray *c23_b_sfEvent;
=======
  const mxArray *c23_sfEvent;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  int32_T c23_y;
  SFc23_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc23_lab2_next_levelInstanceStruct *)chartInstanceVoid;
<<<<<<< HEAD
  c23_b_sfEvent = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_sfEvent),
    &c23_thisId);
  sf_mex_destroy(&c23_b_sfEvent);
=======
  c23_sfEvent = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_sfEvent),
    &c23_thisId);
  sf_mex_destroy(&c23_sfEvent);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  *(int32_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static uint8_T c23_d_emlrt_marshallIn(SFc23_lab2_next_levelInstanceStruct
<<<<<<< HEAD
  *chartInstance, const mxArray *c23_b_is_active_c23_lab2_next_level, const
  char_T *c23_identifier)
=======
  *chartInstance, const mxArray *c23_is_active_c23_lab2_next_level, const char_T
  *c23_identifier)
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
{
  uint8_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_e_emlrt_marshallIn(chartInstance, sf_mex_dup
<<<<<<< HEAD
    (c23_b_is_active_c23_lab2_next_level), &c23_thisId);
  sf_mex_destroy(&c23_b_is_active_c23_lab2_next_level);
=======
    (c23_is_active_c23_lab2_next_level), &c23_thisId);
  sf_mex_destroy(&c23_is_active_c23_lab2_next_level);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  return c23_y;
}

static uint8_T c23_e_emlrt_marshallIn(SFc23_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  uint8_T c23_y;
  uint8_T c23_u0;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_u0, 1, 3, 0U, 0, 0U, 0);
  c23_y = c23_u0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void init_dsm_address_info(SFc23_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
<<<<<<< HEAD
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

=======
static uint32_T* sf_get_sfun_dwork_checksum();
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
void sf_c23_lab2_next_level_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3711787033U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3605563679U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3826873277U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3964627561U);
}

mxArray *sf_c23_lab2_next_level_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
<<<<<<< HEAD
    mxArray *mxChecksum = mxCreateString("LwWzKcNeoaKftINKW0CKOE");
=======
    mxArray *mxChecksum = mxCreateString("0mvZya5kZsgbBXcVaHzvJ");
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
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

<<<<<<< HEAD
mxArray *sf_c23_lab2_next_level_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

=======
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
static const mxArray *sf_get_sim_state_info_c23_lab2_next_level(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c23_lab2_next_level\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c23_lab2_next_level_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc23_lab2_next_levelInstanceStruct *chartInstance;
    chartInstance = (SFc23_lab2_next_levelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
<<<<<<< HEAD
          (sfGlobalDebugInstanceStruct,
           _lab2_next_levelMachineNumber_,
=======
          (_lab2_next_levelMachineNumber_,
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
           23,
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
<<<<<<< HEAD
            (sfGlobalDebugInstanceStruct,_lab2_next_levelMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _lab2_next_levelMachineNumber_,
=======
            (_lab2_next_levelMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_lab2_next_levelMachineNumber_,
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,303);
        _SFD_CV_INIT_EML_IF(0,1,0,148,158,-1,-2);
        _SFD_CV_INIT_EML_FOR(0,1,0,77,89,303);
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
            1.0,0,0,(MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)c23_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c23_y;
          real_T *c23_wc;
          real_T (*c23_signal)[10];
          c23_wc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c23_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c23_signal = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c23_signal);
          _SFD_SET_DATA_VALUE_PTR(1U, c23_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c23_wc);
        }
      }
    } else {
<<<<<<< HEAD
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _lab2_next_levelMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
=======
      sf_debug_reset_current_state_configuration(_lab2_next_levelMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
    }
  }
}

<<<<<<< HEAD
static const char* sf_get_instance_specialization(void)
=======
static const char* sf_get_instance_specialization()
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
{
  return "6iJpylMXH6x4uTmmbhoXQE";
}

<<<<<<< HEAD
static void sf_opaque_initialize_c23_lab2_next_level(void *chartInstanceVar)
{
=======
static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 23, "dworkChecksum");
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

static void sf_opaque_initialize_c23_lab2_next_level(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc23_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  chart_debug_initialization(((SFc23_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c23_lab2_next_level((SFc23_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
  initialize_c23_lab2_next_level((SFc23_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c23_lab2_next_level(void *chartInstanceVar)
{
  enable_c23_lab2_next_level((SFc23_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c23_lab2_next_level(void *chartInstanceVar)
{
  disable_c23_lab2_next_level((SFc23_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c23_lab2_next_level(void *chartInstanceVar)
{
  sf_c23_lab2_next_level((SFc23_lab2_next_levelInstanceStruct*) chartInstanceVar);
}

<<<<<<< HEAD
=======
static void sf_opaque_ext_mode_exec_c23_lab2_next_level(void *chartInstanceVar)
{
  ext_mode_exec_c23_lab2_next_level((SFc23_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
extern const mxArray* sf_internal_get_sim_state_c23_lab2_next_level(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c23_lab2_next_level
    ((SFc23_lab2_next_levelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c23_lab2_next_level();/* state var info */
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

extern void sf_internal_set_sim_state_c23_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c23_lab2_next_level();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c23_lab2_next_level((SFc23_lab2_next_levelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c23_lab2_next_level(SimStruct* S)
{
  return sf_internal_get_sim_state_c23_lab2_next_level(S);
}

static void sf_opaque_set_sim_state_c23_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c23_lab2_next_level(S, st);
}

static void sf_opaque_terminate_c23_lab2_next_level(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc23_lab2_next_levelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
<<<<<<< HEAD
      unload_lab2_next_level_optimization_info();
=======
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
    }

    finalize_c23_lab2_next_level((SFc23_lab2_next_levelInstanceStruct*)
      chartInstanceVar);
<<<<<<< HEAD
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
=======
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_lab2_next_level_optimization_info();
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc23_lab2_next_level((SFc23_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c23_lab2_next_level(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c23_lab2_next_level((SFc23_lab2_next_levelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

<<<<<<< HEAD
=======
mxArray *sf_c23_lab2_next_level_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c23_lab2_next_level\",T\"is_active_c23_lab2_next_level\"}}"
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

>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
static void mdlSetWorkWidths_c23_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      23);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,23,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,23,
      "gatewayCannotBeInlinedMultipleTimes"));
<<<<<<< HEAD
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,23);
=======
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,23,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,23,1);
    }

<<<<<<< HEAD
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,23);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4055680554U));
  ssSetChecksum1(S,(3734395427U));
  ssSetChecksum2(S,(141929304U));
  ssSetChecksum3(S,(3549941679U));
=======
    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,23);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1171952331U));
  ssSetChecksum1(S,(838713659U));
  ssSetChecksum2(S,(3850701576U));
  ssSetChecksum3(S,(2586606038U));
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c23_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c23_lab2_next_level(SimStruct *S)
{
  SFc23_lab2_next_levelInstanceStruct *chartInstance;
<<<<<<< HEAD
  chartInstance = (SFc23_lab2_next_levelInstanceStruct *)utMalloc(sizeof
=======
  chartInstance = (SFc23_lab2_next_levelInstanceStruct *)malloc(sizeof
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
    (SFc23_lab2_next_levelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc23_lab2_next_levelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c23_lab2_next_level;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c23_lab2_next_level;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c23_lab2_next_level;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c23_lab2_next_level;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c23_lab2_next_level;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c23_lab2_next_level;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c23_lab2_next_level;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c23_lab2_next_level;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c23_lab2_next_level;
  chartInstance->chartInfo.mdlStart = mdlStart_c23_lab2_next_level;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c23_lab2_next_level;
<<<<<<< HEAD
  chartInstance->chartInfo.extModeExec = NULL;
=======
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c23_lab2_next_level;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
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

void c23_lab2_next_level_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c23_lab2_next_level(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c23_lab2_next_level(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c23_lab2_next_level(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c23_lab2_next_level_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
