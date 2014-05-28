/* Include files */

#include "blascompat32.h"
#include "lab2_next_level_sfun.h"
#include "c2_lab2_next_level.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lab2_next_level_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[10] = { "nargin", "nargout", "P",
  "cmd1", "cmd2", "cmd3", "P1", "P2", "P3", "P4" };

/* Function Declarations */
static void initialize_c2_lab2_next_level(SFc2_lab2_next_levelInstanceStruct
  *chartInstance);
static void initialize_params_c2_lab2_next_level
  (SFc2_lab2_next_levelInstanceStruct *chartInstance);
static void enable_c2_lab2_next_level(SFc2_lab2_next_levelInstanceStruct
  *chartInstance);
static void disable_c2_lab2_next_level(SFc2_lab2_next_levelInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_lab2_next_level
  (SFc2_lab2_next_levelInstanceStruct *chartInstance);
static void ext_mode_exec_c2_lab2_next_level(SFc2_lab2_next_levelInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c2_lab2_next_level
  (SFc2_lab2_next_levelInstanceStruct *chartInstance);
static void set_sim_state_c2_lab2_next_level(SFc2_lab2_next_levelInstanceStruct *
  chartInstance, const mxArray *c2_st);
static void finalize_c2_lab2_next_level(SFc2_lab2_next_levelInstanceStruct
  *chartInstance);
static void sf_c2_lab2_next_level(SFc2_lab2_next_levelInstanceStruct
  *chartInstance);
static void initSimStructsc2_lab2_next_level(SFc2_lab2_next_levelInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c2_P4, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn(SFc2_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_d_emlrt_marshallIn(SFc2_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c2_is_active_c2_lab2_next_level, const char_T
  *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn(SFc2_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_lab2_next_levelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_lab2_next_level(SFc2_lab2_next_levelInstanceStruct
  *chartInstance)
{
  int32_T *c2_sfEvent;
  uint8_T *c2_is_active_c2_lab2_next_level;
  c2_is_active_c2_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c2_is_active_c2_lab2_next_level = 0U;
}

static void initialize_params_c2_lab2_next_level
  (SFc2_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void enable_c2_lab2_next_level(SFc2_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_lab2_next_level(SFc2_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_lab2_next_level
  (SFc2_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c2_lab2_next_level(SFc2_lab2_next_levelInstanceStruct *
  chartInstance)
{
  c2_update_debugger_state_c2_lab2_next_level(chartInstance);
}

static const mxArray *get_sim_state_c2_lab2_next_level
  (SFc2_lab2_next_levelInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_d_hoistedGlobal;
  real_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  uint8_T c2_e_hoistedGlobal;
  uint8_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  real_T *c2_P1;
  real_T *c2_P2;
  real_T *c2_P3;
  real_T *c2_P4;
<<<<<<< HEAD
=======
  uint8_T *c2_is_active_c2_lab2_next_level;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  c2_P4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_P3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_P2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_P1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
<<<<<<< HEAD
=======
  c2_is_active_c2_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(5), FALSE);
  c2_hoistedGlobal = *c2_P1;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_P2;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *c2_P3;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = *c2_P4;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
<<<<<<< HEAD
  c2_e_hoistedGlobal = chartInstance->c2_is_active_c2_lab2_next_level;
=======
  c2_e_hoistedGlobal = *c2_is_active_c2_lab2_next_level;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_lab2_next_level(SFc2_lab2_next_levelInstanceStruct *
  chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
<<<<<<< HEAD
=======
  boolean_T *c2_doneDoubleBufferReInit;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  real_T *c2_P1;
  real_T *c2_P2;
  real_T *c2_P3;
  real_T *c2_P4;
<<<<<<< HEAD
=======
  uint8_T *c2_is_active_c2_lab2_next_level;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  c2_P4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_P3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_P2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_P1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
<<<<<<< HEAD
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
=======
  c2_is_active_c2_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c2_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c2_doneDoubleBufferReInit = TRUE;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  c2_u = sf_mex_dup(c2_st);
  *c2_P1 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "P1");
  *c2_P2 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
    "P2");
  *c2_P3 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
    "P3");
  *c2_P4 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)),
    "P4");
<<<<<<< HEAD
  chartInstance->c2_is_active_c2_lab2_next_level = c2_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 4)),
     "is_active_c2_lab2_next_level");
=======
  *c2_is_active_c2_lab2_next_level = c2_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 4)), "is_active_c2_lab2_next_level");
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_lab2_next_level(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_lab2_next_level(SFc2_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

static void sf_c2_lab2_next_level(SFc2_lab2_next_levelInstanceStruct
  *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_P;
  real_T c2_cmd1;
  real_T c2_cmd2;
  real_T c2_cmd3;
  uint32_T c2_debug_family_var_map[10];
  real_T c2_nargin = 4.0;
  real_T c2_nargout = 4.0;
  real_T c2_P1;
  real_T c2_P2;
  real_T c2_P3;
  real_T c2_P4;
<<<<<<< HEAD
=======
  int32_T *c2_sfEvent;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  real_T *c2_b_P;
  real_T *c2_b_P1;
  real_T *c2_b_cmd1;
  real_T *c2_b_cmd2;
  real_T *c2_b_cmd3;
  real_T *c2_b_P2;
  real_T *c2_b_P3;
  real_T *c2_b_P4;
  c2_b_P4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_b_P3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_P2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_cmd3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_cmd2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_cmd1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_P1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_P = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
<<<<<<< HEAD
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
=======
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, *c2_sfEvent);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  _SFD_DATA_RANGE_CHECK(*c2_b_P, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_P1, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_b_cmd1, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_b_cmd2, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_b_cmd3, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_b_P2, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_b_P3, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_b_P4, 7U);
<<<<<<< HEAD
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
=======
  *c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, *c2_sfEvent);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  c2_hoistedGlobal = *c2_b_P;
  c2_b_hoistedGlobal = *c2_b_cmd1;
  c2_c_hoistedGlobal = *c2_b_cmd2;
  c2_d_hoistedGlobal = *c2_b_cmd3;
  c2_P = c2_hoistedGlobal;
  c2_cmd1 = c2_b_hoistedGlobal;
  c2_cmd2 = c2_c_hoistedGlobal;
  c2_cmd3 = c2_d_hoistedGlobal;
<<<<<<< HEAD
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_P, 2U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_cmd1, 3U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_cmd2, 4U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_cmd3, 5U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_P1, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_P2, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_P3, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_P4, 9U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_P1 = ((c2_P + c2_cmd1) + c2_cmd2) + c2_cmd3;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_P2 = ((c2_P - c2_cmd1) + c2_cmd2) - c2_cmd3;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_P3 = ((c2_P + c2_cmd1) - c2_cmd2) - c2_cmd3;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_P4 = ((c2_P - c2_cmd1) - c2_cmd2) + c2_cmd3;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -7);
  _SFD_SYMBOL_SCOPE_POP();
=======
  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_P, 2U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_cmd1, 3U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_cmd2, 4U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_cmd3, 5U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_P1, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_P2, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_P3, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_P4, 9U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c2_sfEvent, 4);
  c2_P1 = ((c2_P + c2_cmd1) + c2_cmd2) + c2_cmd3;
  _SFD_EML_CALL(0U, *c2_sfEvent, 5);
  c2_P2 = ((c2_P - c2_cmd1) + c2_cmd2) - c2_cmd3;
  _SFD_EML_CALL(0U, *c2_sfEvent, 6);
  c2_P3 = ((c2_P + c2_cmd1) - c2_cmd2) - c2_cmd3;
  _SFD_EML_CALL(0U, *c2_sfEvent, 7);
  c2_P4 = ((c2_P - c2_cmd1) - c2_cmd2) + c2_cmd3;
  _SFD_EML_CALL(0U, *c2_sfEvent, -7);
  sf_debug_symbol_scope_pop();
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  *c2_b_P1 = c2_P1;
  *c2_b_P2 = c2_P2;
  *c2_b_P3 = c2_P3;
  *c2_b_P4 = c2_P4;
<<<<<<< HEAD
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lab2_next_levelMachineNumber_,
=======
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *c2_sfEvent);
  sf_debug_check_for_state_inconsistency(_lab2_next_levelMachineNumber_,
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_lab2_next_level(SFc2_lab2_next_levelInstanceStruct *
  chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc2_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c2_P4, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_P4), &c2_thisId);
  sf_mex_destroy(&c2_P4);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
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
  const mxArray *c2_P4;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc2_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c2_P4 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_P4), &c2_thisId);
  sf_mex_destroy(&c2_P4);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_lab2_next_level_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc2_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn(SFc2_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i0, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc2_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c2_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_sfEvent), &c2_thisId);
  sf_mex_destroy(&c2_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c2_is_active_c2_lab2_next_level, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_is_active_c2_lab2_next_level), &c2_thisId);
  sf_mex_destroy(&c2_is_active_c2_lab2_next_level);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c2_lab2_next_level_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2487325305U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2934237547U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1867918189U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3327054518U);
}

mxArray *sf_c2_lab2_next_level_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
<<<<<<< HEAD
    mxArray *mxChecksum = mxCreateString("JquTjZK7IzwTTeKVqMBsEF");
=======
    mxArray *mxChecksum = mxCreateString("THIKj7K7i03gxM0Up0KFaD");
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_lab2_next_level(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"P1\",},{M[1],M[15],T\"P2\",},{M[1],M[16],T\"P3\",},{M[1],M[17],T\"P4\",},{M[8],M[0],T\"is_active_c2_lab2_next_level\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_lab2_next_level_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_lab2_next_levelInstanceStruct *chartInstance;
    chartInstance = (SFc2_lab2_next_levelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_lab2_next_levelMachineNumber_,
           2,
           1,
           1,
           8,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"P");
          _SFD_SET_DATA_PROPS(1,2,0,1,"P1");
          _SFD_SET_DATA_PROPS(2,1,1,0,"cmd1");
          _SFD_SET_DATA_PROPS(3,1,1,0,"cmd2");
          _SFD_SET_DATA_PROPS(4,1,1,0,"cmd3");
          _SFD_SET_DATA_PROPS(5,2,0,1,"P2");
          _SFD_SET_DATA_PROPS(6,2,0,1,"P3");
          _SFD_SET_DATA_PROPS(7,2,0,1,"P4");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,173);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          real_T *c2_P;
          real_T *c2_P1;
          real_T *c2_cmd1;
          real_T *c2_cmd2;
          real_T *c2_cmd3;
          real_T *c2_P2;
          real_T *c2_P3;
          real_T *c2_P4;
          c2_P4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c2_P3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c2_P2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_cmd3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_cmd2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_cmd1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_P1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_P = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_P);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_P1);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_cmd1);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_cmd2);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_cmd3);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_P2);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_P3);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_P4);
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
  return "cods73WN44Bs2OHeqUGlYE";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
<<<<<<< HEAD
  return "cods73WN44Bs2OHeqUGlYE";
=======
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 2, "dworkChecksum");
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
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
}

static void sf_opaque_initialize_c2_lab2_next_level(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc2_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc2_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_lab2_next_level((SFc2_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
  initialize_c2_lab2_next_level((SFc2_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_lab2_next_level(void *chartInstanceVar)
{
  enable_c2_lab2_next_level((SFc2_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_lab2_next_level(void *chartInstanceVar)
{
  disable_c2_lab2_next_level((SFc2_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_lab2_next_level(void *chartInstanceVar)
{
  sf_c2_lab2_next_level((SFc2_lab2_next_levelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c2_lab2_next_level(void *chartInstanceVar)
{
  ext_mode_exec_c2_lab2_next_level((SFc2_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_lab2_next_level(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_lab2_next_level
    ((SFc2_lab2_next_levelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_lab2_next_level();/* state var info */
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

extern void sf_internal_set_sim_state_c2_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_lab2_next_level();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_lab2_next_level((SFc2_lab2_next_levelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_lab2_next_level(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_lab2_next_level(S);
}

static void sf_opaque_set_sim_state_c2_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_lab2_next_level(S, st);
}

static void sf_opaque_terminate_c2_lab2_next_level(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_lab2_next_levelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_lab2_next_level((SFc2_lab2_next_levelInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_lab2_next_level_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_lab2_next_level((SFc2_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_lab2_next_level(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_lab2_next_level((SFc2_lab2_next_levelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c2_lab2_next_level_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c2_lab2_next_level\",T\"is_active_c2_lab2_next_level\"}}"
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

static void mdlSetWorkWidths_c2_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
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
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,4);
<<<<<<< HEAD
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
=======
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1935512779U));
  ssSetChecksum1(S,(2183947389U));
  ssSetChecksum2(S,(159257514U));
  ssSetChecksum3(S,(3380900804U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_lab2_next_level(SimStruct *S)
{
  SFc2_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc2_lab2_next_levelInstanceStruct *)malloc(sizeof
    (SFc2_lab2_next_levelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_lab2_next_levelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_lab2_next_level;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_lab2_next_level;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_lab2_next_level;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_lab2_next_level;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_lab2_next_level;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_lab2_next_level;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_lab2_next_level;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_lab2_next_level;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_lab2_next_level;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_lab2_next_level;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_lab2_next_level;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c2_lab2_next_level;
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

void c2_lab2_next_level_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_lab2_next_level(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_lab2_next_level(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_lab2_next_level(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_lab2_next_level_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
