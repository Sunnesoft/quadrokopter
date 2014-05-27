/* Include files */

#include "blascompat32.h"
#include "lab2_next_level_sfun.h"
#include "c1_lab2_next_level.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lab2_next_level_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[13] = { "max", "el", "nargin",
  "nargout", "etalX", "etalY", "etalH", "curX", "curY", "curH", "counter",
  "error", "way" };

/* Function Declarations */
static void initialize_c1_lab2_next_level(SFc1_lab2_next_levelInstanceStruct
  *chartInstance);
static void initialize_params_c1_lab2_next_level
  (SFc1_lab2_next_levelInstanceStruct *chartInstance);
static void enable_c1_lab2_next_level(SFc1_lab2_next_levelInstanceStruct
  *chartInstance);
static void disable_c1_lab2_next_level(SFc1_lab2_next_levelInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_lab2_next_level
  (SFc1_lab2_next_levelInstanceStruct *chartInstance);
static void ext_mode_exec_c1_lab2_next_level(SFc1_lab2_next_levelInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c1_lab2_next_level
  (SFc1_lab2_next_levelInstanceStruct *chartInstance);
static void set_sim_state_c1_lab2_next_level(SFc1_lab2_next_levelInstanceStruct *
  chartInstance, const mxArray *c1_st);
static void finalize_c1_lab2_next_level(SFc1_lab2_next_levelInstanceStruct
  *chartInstance);
static void sf_c1_lab2_next_level(SFc1_lab2_next_levelInstanceStruct
  *chartInstance);
static void initSimStructsc1_lab2_next_level(SFc1_lab2_next_levelInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_b_emlrt_marshallIn(SFc1_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_c_emlrt_marshallIn(SFc1_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c1_is_active_c1_lab2_next_level, const char_T
  *c1_identifier);
static uint8_T c1_d_emlrt_marshallIn(SFc1_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_lab2_next_levelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_lab2_next_level(SFc1_lab2_next_levelInstanceStruct
  *chartInstance)
{
  int32_T *c1_sfEvent;
  uint8_T *c1_is_active_c1_lab2_next_level;
  c1_is_active_c1_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c1_is_active_c1_lab2_next_level = 0U;
}

static void initialize_params_c1_lab2_next_level
  (SFc1_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void enable_c1_lab2_next_level(SFc1_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_lab2_next_level(SFc1_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_lab2_next_level
  (SFc1_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c1_lab2_next_level(SFc1_lab2_next_levelInstanceStruct *
  chartInstance)
{
  c1_update_debugger_state_c1_lab2_next_level(chartInstance);
}

static const mxArray *get_sim_state_c1_lab2_next_level
  (SFc1_lab2_next_levelInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_u;
  const mxArray *c1_b_y = NULL;
  uint8_T *c1_is_active_c1_lab2_next_level;
  c1_is_active_c1_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(1), FALSE);
  c1_hoistedGlobal = *c1_is_active_c1_lab2_next_level;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_lab2_next_level(SFc1_lab2_next_levelInstanceStruct *
  chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  boolean_T *c1_doneDoubleBufferReInit;
  uint8_T *c1_is_active_c1_lab2_next_level;
  c1_is_active_c1_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c1_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_is_active_c1_lab2_next_level = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 0)), "is_active_c1_lab2_next_level");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_lab2_next_level(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_lab2_next_level(SFc1_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

static void sf_c1_lab2_next_level(SFc1_lab2_next_levelInstanceStruct
  *chartInstance)
{
  int32_T c1_i0;
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_hoistedGlobal;
  real_T c1_e_hoistedGlobal;
  real_T c1_f_hoistedGlobal;
  real_T c1_g_hoistedGlobal;
  real_T c1_h_hoistedGlobal;
  real_T c1_etalX;
  real_T c1_etalY;
  real_T c1_etalH;
  real_T c1_curX;
  real_T c1_curY;
  real_T c1_curH;
  real_T c1_counter;
  real_T c1_error;
  int32_T c1_i1;
  real_T c1_way[12];
  uint32_T c1_debug_family_var_map[13];
  real_T c1_max;
  real_T c1_el;
  real_T c1_nargin = 9.0;
  real_T c1_nargout = 0.0;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_y;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_b_y;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_c_y;
  int32_T c1_i2;
  static char_T c1_cv0[39] = { 'l', 'a', 'b', '2', '_', 'n', 'e', 'x', 't', '_',
    'l', 'e', 'v', 'e', 'l', '/', 'C', 'o', 'n', 't', 'r', 'o', 'l', 'S', 'y',
    's', 't', 'e', 'm', '/', 'C', 'o', 'n', 's', 't', 'a', 'n', 't', '1' };

  char_T c1_u[39];
  const mxArray *c1_d_y = NULL;
  int32_T c1_i3;
  static char_T c1_cv1[5] = { 'V', 'a', 'l', 'u', 'e' };

  char_T c1_b_u[5];
  const mxArray *c1_e_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_f_y = NULL;
  int32_T c1_i4;
  static char_T c1_cv2[31] = { 'l', 'a', 'b', '2', '_', 'n', 'e', 'x', 't', '_',
    'l', 'e', 'v', 'e', 'l', '/', 'C', 'o', 'n', 't', 'r', 'o', 'l', 'S', 'y',
    's', 't', 'e', 'm', '/', 'X' };

  char_T c1_d_u[31];
  const mxArray *c1_g_y = NULL;
  int32_T c1_i5;
  char_T c1_e_u[5];
  const mxArray *c1_h_y = NULL;
  real_T c1_f_u;
  const mxArray *c1_i_y = NULL;
  int32_T c1_i6;
  static char_T c1_cv3[31] = { 'l', 'a', 'b', '2', '_', 'n', 'e', 'x', 't', '_',
    'l', 'e', 'v', 'e', 'l', '/', 'C', 'o', 'n', 't', 'r', 'o', 'l', 'S', 'y',
    's', 't', 'e', 'm', '/', 'Y' };

  char_T c1_g_u[31];
  const mxArray *c1_j_y = NULL;
  int32_T c1_i7;
  char_T c1_h_u[5];
  const mxArray *c1_k_y = NULL;
  real_T c1_i_u;
  const mxArray *c1_l_y = NULL;
  int32_T c1_i8;
  static char_T c1_cv4[31] = { 'l', 'a', 'b', '2', '_', 'n', 'e', 'x', 't', '_',
    'l', 'e', 'v', 'e', 'l', '/', 'C', 'o', 'n', 't', 'r', 'o', 'l', 'S', 'y',
    's', 't', 'e', 'm', '/', 'H' };

  char_T c1_j_u[31];
  const mxArray *c1_m_y = NULL;
  int32_T c1_i9;
  char_T c1_k_u[5];
  const mxArray *c1_n_y = NULL;
  real_T c1_l_u;
  const mxArray *c1_o_y = NULL;
  int32_T *c1_sfEvent;
  real_T *c1_b_etalX;
  real_T *c1_b_etalY;
  real_T *c1_b_etalH;
  real_T *c1_b_curX;
  real_T *c1_b_curY;
  real_T *c1_b_curH;
  real_T *c1_b_counter;
  real_T *c1_b_error;
  real_T (*c1_b_way)[12];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c1_b_way = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 8);
  c1_b_error = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_b_counter = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_b_curH = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_b_curY = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_b_curX = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_etalH = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_etalY = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_etalX = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, *c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_b_etalX, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_b_etalY, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_b_etalH, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_b_curX, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_b_curY, 4U);
  _SFD_DATA_RANGE_CHECK(*c1_b_curH, 5U);
  _SFD_DATA_RANGE_CHECK(*c1_b_counter, 6U);
  _SFD_DATA_RANGE_CHECK(*c1_b_error, 7U);
  for (c1_i0 = 0; c1_i0 < 12; c1_i0++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_way)[c1_i0], 8U);
  }

  *c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *c1_sfEvent);
  c1_hoistedGlobal = *c1_b_etalX;
  c1_b_hoistedGlobal = *c1_b_etalY;
  c1_c_hoistedGlobal = *c1_b_etalH;
  c1_d_hoistedGlobal = *c1_b_curX;
  c1_e_hoistedGlobal = *c1_b_curY;
  c1_f_hoistedGlobal = *c1_b_curH;
  c1_g_hoistedGlobal = *c1_b_counter;
  c1_h_hoistedGlobal = *c1_b_error;
  c1_etalX = c1_hoistedGlobal;
  c1_etalY = c1_b_hoistedGlobal;
  c1_etalH = c1_c_hoistedGlobal;
  c1_curX = c1_d_hoistedGlobal;
  c1_curY = c1_e_hoistedGlobal;
  c1_curH = c1_f_hoistedGlobal;
  c1_counter = c1_g_hoistedGlobal;
  c1_error = c1_h_hoistedGlobal;
  for (c1_i1 = 0; c1_i1 < 12; c1_i1++) {
    c1_way[c1_i1] = (*c1_b_way)[c1_i1];
  }

  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_max, 0U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_el, 1U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 2U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 3U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_etalX, 4U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_etalY, 5U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_etalH, 6U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_curX, 7U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_curY, 8U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_curH, 9U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_counter, 10U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_error, 11U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_way, 12U, c1_sf_marshallOut);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c1_sfEvent, 3);
  _SFD_EML_CALL(0U, *c1_sfEvent, 4);
  _SFD_EML_CALL(0U, *c1_sfEvent, 6);
  c1_max = 4.0;
  c1_el = 3.0;
  _SFD_EML_CALL(0U, *c1_sfEvent, 8);
  c1_x = c1_etalX - c1_curX;
  c1_b_x = c1_x;
  c1_y = muDoubleScalarAbs(c1_b_x);
  guard1 = FALSE;
  guard2 = FALSE;
  guard3 = FALSE;
  if (CV_EML_COND(0, 1, 0, c1_y <= c1_error)) {
    c1_c_x = c1_etalY - c1_curY;
    c1_d_x = c1_c_x;
    c1_b_y = muDoubleScalarAbs(c1_d_x);
    if (CV_EML_COND(0, 1, 1, c1_b_y <= c1_error)) {
      c1_e_x = c1_etalH - c1_curH;
      c1_f_x = c1_e_x;
      c1_c_y = muDoubleScalarAbs(c1_f_x);
      if (CV_EML_COND(0, 1, 2, c1_c_y <= c1_error)) {
        if (CV_EML_COND(0, 1, 3, c1_counter < c1_max)) {
          CV_EML_MCDC(0, 1, 0, TRUE);
          CV_EML_IF(0, 1, 0, TRUE);
          _SFD_EML_CALL(0U, *c1_sfEvent, 9);
          c1_counter++;
          _SFD_EML_CALL(0U, *c1_sfEvent, 10);
          for (c1_i2 = 0; c1_i2 < 39; c1_i2++) {
            c1_u[c1_i2] = c1_cv0[c1_i2];
          }

          c1_d_y = NULL;
          sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1,
            39), FALSE);
          for (c1_i3 = 0; c1_i3 < 5; c1_i3++) {
            c1_b_u[c1_i3] = c1_cv1[c1_i3];
          }

          c1_e_y = NULL;
          sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1,
            5), FALSE);
          c1_c_u = c1_counter;
          c1_f_y = NULL;
          sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          sf_mex_call_debug("set_param", 0U, 3U, 14, c1_d_y, 14, c1_e_y, 14,
                            sf_mex_call_debug("num2str", 1U, 1U, 14, c1_f_y));
          _SFD_EML_CALL(0U, *c1_sfEvent, 11);
          for (c1_i4 = 0; c1_i4 < 31; c1_i4++) {
            c1_d_u[c1_i4] = c1_cv2[c1_i4];
          }

          c1_g_y = NULL;
          sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_d_u, 10, 0U, 1U, 0U, 2, 1,
            31), FALSE);
          for (c1_i5 = 0; c1_i5 < 5; c1_i5++) {
            c1_e_u[c1_i5] = c1_cv1[c1_i5];
          }

          c1_h_y = NULL;
          sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_e_u, 10, 0U, 1U, 0U, 2, 1,
            5), FALSE);
          c1_f_u = c1_way[_SFD_EML_ARRAY_BOUNDS_CHECK("way", (int32_T)
            _SFD_INTEGER_CHECK("counter", c1_counter), 1, 4, 1, 0) - 1];
          c1_i_y = NULL;
          sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          sf_mex_call_debug("set_param", 0U, 3U, 14, c1_g_y, 14, c1_h_y, 14,
                            sf_mex_call_debug("num2str", 1U, 1U, 14, c1_i_y));
          _SFD_EML_CALL(0U, *c1_sfEvent, 12);
          for (c1_i6 = 0; c1_i6 < 31; c1_i6++) {
            c1_g_u[c1_i6] = c1_cv3[c1_i6];
          }

          c1_j_y = NULL;
          sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_g_u, 10, 0U, 1U, 0U, 2, 1,
            31), FALSE);
          for (c1_i7 = 0; c1_i7 < 5; c1_i7++) {
            c1_h_u[c1_i7] = c1_cv1[c1_i7];
          }

          c1_k_y = NULL;
          sf_mex_assign(&c1_k_y, sf_mex_create("y", c1_h_u, 10, 0U, 1U, 0U, 2, 1,
            5), FALSE);
          c1_i_u = c1_way[_SFD_EML_ARRAY_BOUNDS_CHECK("way", (int32_T)
            _SFD_INTEGER_CHECK("counter", c1_counter), 1, 4, 1, 0) + 3];
          c1_l_y = NULL;
          sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          sf_mex_call_debug("set_param", 0U, 3U, 14, c1_j_y, 14, c1_k_y, 14,
                            sf_mex_call_debug("num2str", 1U, 1U, 14, c1_l_y));
          _SFD_EML_CALL(0U, *c1_sfEvent, 13);
          for (c1_i8 = 0; c1_i8 < 31; c1_i8++) {
            c1_j_u[c1_i8] = c1_cv4[c1_i8];
          }

          c1_m_y = NULL;
          sf_mex_assign(&c1_m_y, sf_mex_create("y", c1_j_u, 10, 0U, 1U, 0U, 2, 1,
            31), FALSE);
          for (c1_i9 = 0; c1_i9 < 5; c1_i9++) {
            c1_k_u[c1_i9] = c1_cv1[c1_i9];
          }

          c1_n_y = NULL;
          sf_mex_assign(&c1_n_y, sf_mex_create("y", c1_k_u, 10, 0U, 1U, 0U, 2, 1,
            5), FALSE);
          c1_l_u = c1_way[_SFD_EML_ARRAY_BOUNDS_CHECK("way", (int32_T)
            _SFD_INTEGER_CHECK("counter", c1_counter), 1, 4, 1, 0) + 7];
          c1_o_y = NULL;
          sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_l_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          sf_mex_call_debug("set_param", 0U, 3U, 14, c1_m_y, 14, c1_n_y, 14,
                            sf_mex_call_debug("num2str", 1U, 1U, 14, c1_o_y));
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

  _SFD_EML_CALL(0U, *c1_sfEvent, -13);
  sf_debug_symbol_scope_pop();
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c1_sfEvent);
  sf_debug_check_for_state_inconsistency(_lab2_next_levelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_lab2_next_level(SFc1_lab2_next_levelInstanceStruct *
  chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  real_T c1_b_inData[12];
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  real_T c1_u[12];
  const mxArray *c1_y = NULL;
  SFc1_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc1_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i10 = 0;
  for (c1_i11 = 0; c1_i11 < 3; c1_i11++) {
    for (c1_i12 = 0; c1_i12 < 4; c1_i12++) {
      c1_b_inData[c1_i12 + c1_i10] = (*(real_T (*)[12])c1_inData)[c1_i12 +
        c1_i10];
    }

    c1_i10 += 4;
  }

  c1_i13 = 0;
  for (c1_i14 = 0; c1_i14 < 3; c1_i14++) {
    for (c1_i15 = 0; c1_i15 < 4; c1_i15++) {
      c1_u[c1_i15 + c1_i13] = c1_b_inData[c1_i15 + c1_i13];
    }

    c1_i13 += 4;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 4, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc1_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc1_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_lab2_next_level_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[2];
  c1_ResolvedFunctionInfo (*c1_b_info)[2];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i16;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[2])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "abs";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c1_b_info)[0].fileTimeLo = 1286811494U;
  (*c1_b_info)[0].fileTimeHi = 0U;
  (*c1_b_info)[0].mFileTimeLo = 0U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  (*c1_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c1_b_info)[1].name = "eml_scalar_abs";
  (*c1_b_info)[1].dominantType = "double";
  (*c1_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  (*c1_b_info)[1].fileTimeLo = 1286811512U;
  (*c1_b_info)[1].fileTimeHi = 0U;
  (*c1_b_info)[1].mFileTimeLo = 0U;
  (*c1_b_info)[1].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 2), FALSE);
  for (c1_i16 = 0; c1_i16 < 2; c1_i16++) {
    c1_r0 = &c1_info[c1_i16];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i16);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i16);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i16);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i16);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i16);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i16);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i16);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i16);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc1_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_b_emlrt_marshallIn(SFc1_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i17;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i17, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i17;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc1_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c1_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_sfEvent), &c1_thisId);
  sf_mex_destroy(&c1_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_c_emlrt_marshallIn(SFc1_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c1_is_active_c1_lab2_next_level, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_is_active_c1_lab2_next_level), &c1_thisId);
  sf_mex_destroy(&c1_is_active_c1_lab2_next_level);
  return c1_y;
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c1_lab2_next_level_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1973407179U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3519174372U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3622076534U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4131488103U);
}

mxArray *sf_c1_lab2_next_level_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("0GYefm7ACLoVMzw0kmnljF");
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
      pr[0] = (double)(4);
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

static const mxArray *sf_get_sim_state_info_c1_lab2_next_level(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c1_lab2_next_level\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_lab2_next_level_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_lab2_next_levelInstanceStruct *chartInstance;
    chartInstance = (SFc1_lab2_next_levelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_lab2_next_levelMachineNumber_,
           1,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,611);
        _SFD_CV_INIT_EML_IF(0,1,0,157,249,-1,610);

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
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c1_etalX;
          real_T *c1_etalY;
          real_T *c1_etalH;
          real_T *c1_curX;
          real_T *c1_curY;
          real_T *c1_curH;
          real_T *c1_counter;
          real_T *c1_error;
          real_T (*c1_way)[12];
          c1_way = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 8);
          c1_error = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c1_counter = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c1_curH = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c1_curY = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c1_curX = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_etalH = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_etalY = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_etalX = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_etalX);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_etalY);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_etalH);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_curX);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_curY);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_curH);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_counter);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_error);
          _SFD_SET_DATA_VALUE_PTR(8U, *c1_way);
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
  return "6HoQ4rMfP620FhYsayQzCG";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 1, "dworkChecksum");
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

static void sf_opaque_initialize_c1_lab2_next_level(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc1_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc1_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_lab2_next_level((SFc1_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
  initialize_c1_lab2_next_level((SFc1_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_lab2_next_level(void *chartInstanceVar)
{
  enable_c1_lab2_next_level((SFc1_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_lab2_next_level(void *chartInstanceVar)
{
  disable_c1_lab2_next_level((SFc1_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_lab2_next_level(void *chartInstanceVar)
{
  sf_c1_lab2_next_level((SFc1_lab2_next_levelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c1_lab2_next_level(void *chartInstanceVar)
{
  ext_mode_exec_c1_lab2_next_level((SFc1_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_lab2_next_level(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_lab2_next_level
    ((SFc1_lab2_next_levelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_lab2_next_level();/* state var info */
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

extern void sf_internal_set_sim_state_c1_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_lab2_next_level();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_lab2_next_level((SFc1_lab2_next_levelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_lab2_next_level(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_lab2_next_level(S);
}

static void sf_opaque_set_sim_state_c1_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_lab2_next_level(S, st);
}

static void sf_opaque_terminate_c1_lab2_next_level(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_lab2_next_levelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_lab2_next_level((SFc1_lab2_next_levelInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_lab2_next_level_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_lab2_next_level((SFc1_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_lab2_next_level(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_lab2_next_level((SFc1_lab2_next_levelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c1_lab2_next_level_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c1_lab2_next_level\",T\"is_active_c1_lab2_next_level\"}}"
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

static void mdlSetWorkWidths_c1_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,9);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3635400017U));
  ssSetChecksum1(S,(3652556910U));
  ssSetChecksum2(S,(2576263652U));
  ssSetChecksum3(S,(2883074417U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_lab2_next_level(SimStruct *S)
{
  SFc1_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc1_lab2_next_levelInstanceStruct *)malloc(sizeof
    (SFc1_lab2_next_levelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_lab2_next_levelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_lab2_next_level;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_lab2_next_level;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_lab2_next_level;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_lab2_next_level;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_lab2_next_level;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_lab2_next_level;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_lab2_next_level;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_lab2_next_level;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_lab2_next_level;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_lab2_next_level;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_lab2_next_level;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c1_lab2_next_level;
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

void c1_lab2_next_level_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_lab2_next_level(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_lab2_next_level(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_lab2_next_level(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_lab2_next_level_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
