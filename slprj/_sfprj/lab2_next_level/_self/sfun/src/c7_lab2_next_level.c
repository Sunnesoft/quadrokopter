/* Include files */

#include "blascompat32.h"
#include "lab2_next_level_sfun.h"
#include "c7_lab2_next_level.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lab2_next_level_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c7_debug_family_names[17] = { "h", "Jx", "Jy", "Jz", "M_x",
  "M_y", "k", "M_z", "k_roll", "k_pitch", "k_yaw", "nargin", "nargout", "P",
  "ddroll", "ddpitch", "ddyaw" };

/* Function Declarations */
static void initialize_c7_lab2_next_level(SFc7_lab2_next_levelInstanceStruct
  *chartInstance);
static void initialize_params_c7_lab2_next_level
  (SFc7_lab2_next_levelInstanceStruct *chartInstance);
static void enable_c7_lab2_next_level(SFc7_lab2_next_levelInstanceStruct
  *chartInstance);
static void disable_c7_lab2_next_level(SFc7_lab2_next_levelInstanceStruct
  *chartInstance);
static void c7_update_debugger_state_c7_lab2_next_level
  (SFc7_lab2_next_levelInstanceStruct *chartInstance);
static void ext_mode_exec_c7_lab2_next_level(SFc7_lab2_next_levelInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c7_lab2_next_level
  (SFc7_lab2_next_levelInstanceStruct *chartInstance);
static void set_sim_state_c7_lab2_next_level(SFc7_lab2_next_levelInstanceStruct *
  chartInstance, const mxArray *c7_st);
static void finalize_c7_lab2_next_level(SFc7_lab2_next_levelInstanceStruct
  *chartInstance);
static void sf_c7_lab2_next_level(SFc7_lab2_next_levelInstanceStruct
  *chartInstance);
static void initSimStructsc7_lab2_next_level(SFc7_lab2_next_levelInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static real_T c7_emlrt_marshallIn(SFc7_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c7_ddyaw, const char_T *c7_identifier);
static real_T c7_b_emlrt_marshallIn(SFc7_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_c_emlrt_marshallIn(SFc7_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint8_T c7_d_emlrt_marshallIn(SFc7_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c7_is_active_c7_lab2_next_level, const char_T
  *c7_identifier);
static uint8_T c7_e_emlrt_marshallIn(SFc7_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void init_dsm_address_info(SFc7_lab2_next_levelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c7_lab2_next_level(SFc7_lab2_next_levelInstanceStruct
  *chartInstance)
{
  int32_T *c7_sfEvent;
  uint8_T *c7_is_active_c7_lab2_next_level;
  c7_is_active_c7_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c7_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c7_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c7_is_active_c7_lab2_next_level = 0U;
}

static void initialize_params_c7_lab2_next_level
  (SFc7_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void enable_c7_lab2_next_level(SFc7_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c7_lab2_next_level(SFc7_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c7_update_debugger_state_c7_lab2_next_level
  (SFc7_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c7_lab2_next_level(SFc7_lab2_next_levelInstanceStruct *
  chartInstance)
{
  c7_update_debugger_state_c7_lab2_next_level(chartInstance);
}

static const mxArray *get_sim_state_c7_lab2_next_level
  (SFc7_lab2_next_levelInstanceStruct *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  real_T c7_hoistedGlobal;
  real_T c7_u;
  const mxArray *c7_b_y = NULL;
  real_T c7_b_hoistedGlobal;
  real_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  real_T c7_c_hoistedGlobal;
  real_T c7_c_u;
  const mxArray *c7_d_y = NULL;
  uint8_T c7_d_hoistedGlobal;
  uint8_T c7_d_u;
  const mxArray *c7_e_y = NULL;
  real_T *c7_ddpitch;
  real_T *c7_ddroll;
  real_T *c7_ddyaw;
  uint8_T *c7_is_active_c7_lab2_next_level;
  c7_ddyaw = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_ddpitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_ddroll = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_is_active_c7_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellarray(4), FALSE);
  c7_hoistedGlobal = *c7_ddpitch;
  c7_u = c7_hoistedGlobal;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_b_hoistedGlobal = *c7_ddroll;
  c7_b_u = c7_b_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  c7_c_hoistedGlobal = *c7_ddyaw;
  c7_c_u = c7_c_hoistedGlobal;
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 2, c7_d_y);
  c7_d_hoistedGlobal = *c7_is_active_c7_lab2_next_level;
  c7_d_u = c7_d_hoistedGlobal;
  c7_e_y = NULL;
  sf_mex_assign(&c7_e_y, sf_mex_create("y", &c7_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 3, c7_e_y);
  sf_mex_assign(&c7_st, c7_y, FALSE);
  return c7_st;
}

static void set_sim_state_c7_lab2_next_level(SFc7_lab2_next_levelInstanceStruct *
  chartInstance, const mxArray *c7_st)
{
  const mxArray *c7_u;
  boolean_T *c7_doneDoubleBufferReInit;
  real_T *c7_ddpitch;
  real_T *c7_ddroll;
  real_T *c7_ddyaw;
  uint8_T *c7_is_active_c7_lab2_next_level;
  c7_ddyaw = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_ddpitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_ddroll = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_is_active_c7_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c7_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c7_doneDoubleBufferReInit = TRUE;
  c7_u = sf_mex_dup(c7_st);
  *c7_ddpitch = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c7_u, 0)), "ddpitch");
  *c7_ddroll = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u,
    1)), "ddroll");
  *c7_ddyaw = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u,
    2)), "ddyaw");
  *c7_is_active_c7_lab2_next_level = c7_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 3)), "is_active_c7_lab2_next_level");
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_lab2_next_level(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_lab2_next_level(SFc7_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

static void sf_c7_lab2_next_level(SFc7_lab2_next_levelInstanceStruct
  *chartInstance)
{
  int32_T c7_i0;
  int32_T c7_i1;
  real_T c7_P[4];
  uint32_T c7_debug_family_var_map[17];
  real_T c7_h;
  real_T c7_Jx;
  real_T c7_Jy;
  real_T c7_Jz;
  real_T c7_M_x;
  real_T c7_M_y;
  real_T c7_k;
  real_T c7_M_z;
  real_T c7_k_roll;
  real_T c7_k_pitch;
  real_T c7_k_yaw;
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 3.0;
  real_T c7_ddroll;
  real_T c7_ddpitch;
  real_T c7_ddyaw;
  real_T c7_a;
  real_T c7_y;
  real_T c7_A;
  real_T c7_x;
  real_T c7_b_x;
  real_T c7_b_a;
  real_T c7_b_y;
  real_T c7_b_A;
  real_T c7_c_x;
  real_T c7_d_x;
  real_T c7_c_a;
  real_T c7_c_y;
  real_T c7_d_a;
  real_T c7_d_y;
  real_T c7_c_A;
  real_T c7_e_x;
  real_T c7_f_x;
  real_T c7_e_a;
  real_T c7_f_a;
  real_T c7_g_a;
  real_T *c7_b_ddyaw;
  real_T *c7_b_ddpitch;
  real_T *c7_b_ddroll;
  int32_T *c7_sfEvent;
  real_T (*c7_b_P)[4];
  c7_b_ddyaw = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_b_ddpitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_b_ddroll = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_b_P = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  c7_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, *c7_sfEvent);
  for (c7_i0 = 0; c7_i0 < 4; c7_i0++) {
    _SFD_DATA_RANGE_CHECK((*c7_b_P)[c7_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c7_b_ddroll, 1U);
  _SFD_DATA_RANGE_CHECK(*c7_b_ddpitch, 2U);
  _SFD_DATA_RANGE_CHECK(*c7_b_ddyaw, 3U);
  *c7_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, *c7_sfEvent);
  for (c7_i1 = 0; c7_i1 < 4; c7_i1++) {
    c7_P[c7_i1] = (*c7_b_P)[c7_i1];
  }

  sf_debug_symbol_scope_push_eml(0U, 17U, 17U, c7_debug_family_names,
    c7_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c7_h, 0U, c7_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c7_Jx, 1U, c7_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c7_Jy, 2U, c7_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c7_Jz, 3U, c7_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c7_M_x, 4U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_M_y, 5U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c7_k, 6U, c7_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c7_M_z, 7U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c7_k_roll, 8U, c7_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c7_k_pitch, 9U, c7_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c7_k_yaw, 10U, c7_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c7_nargin, 11U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_nargout, 12U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c7_P, 13U, c7_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c7_ddroll, 14U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_ddpitch, 15U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_ddyaw, 16U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c7_sfEvent, 4);
  c7_h = 0.5;
  _SFD_EML_CALL(0U, *c7_sfEvent, 6);
  c7_Jx = 1.0;
  _SFD_EML_CALL(0U, *c7_sfEvent, 7);
  c7_Jy = 1.0;
  _SFD_EML_CALL(0U, *c7_sfEvent, 8);
  c7_Jz = 1.0;
  _SFD_EML_CALL(0U, *c7_sfEvent, 10);
  c7_a = ((c7_P[0] - c7_P[1]) + c7_P[2]) - c7_P[3];
  c7_y = c7_a * 0.5;
  c7_A = c7_y;
  c7_x = c7_A;
  c7_b_x = c7_x;
  c7_M_x = c7_b_x;
  _SFD_EML_CALL(0U, *c7_sfEvent, 11);
  c7_b_a = ((c7_P[0] + c7_P[1]) - c7_P[2]) - c7_P[3];
  c7_b_y = c7_b_a * 0.5;
  c7_b_A = c7_b_y;
  c7_c_x = c7_b_A;
  c7_d_x = c7_c_x;
  c7_M_y = c7_d_x;
  _SFD_EML_CALL(0U, *c7_sfEvent, 12);
  c7_k = 0.5;
  _SFD_EML_CALL(0U, *c7_sfEvent, 13);
  c7_c_a = ((c7_P[0] + c7_P[3]) - c7_P[1]) - c7_P[2];
  c7_c_y = c7_c_a * 0.5;
  c7_d_a = c7_c_y;
  c7_d_y = c7_d_a * 0.5;
  c7_c_A = c7_d_y;
  c7_e_x = c7_c_A;
  c7_f_x = c7_e_x;
  c7_M_z = c7_f_x;
  _SFD_EML_CALL(0U, *c7_sfEvent, 15);
  c7_k_roll = 0.8;
  _SFD_EML_CALL(0U, *c7_sfEvent, 16);
  c7_k_pitch = 0.8;
  _SFD_EML_CALL(0U, *c7_sfEvent, 17);
  c7_k_yaw = 0.8;
  _SFD_EML_CALL(0U, *c7_sfEvent, 20);
  c7_e_a = c7_M_x;
  c7_ddroll = c7_e_a * 0.8;
  _SFD_EML_CALL(0U, *c7_sfEvent, 21);
  c7_f_a = c7_M_y;
  c7_ddpitch = c7_f_a * 0.8;
  _SFD_EML_CALL(0U, *c7_sfEvent, 22);
  c7_g_a = c7_M_z;
  c7_ddyaw = c7_g_a * 0.8;
  _SFD_EML_CALL(0U, *c7_sfEvent, -22);
  sf_debug_symbol_scope_pop();
  *c7_b_ddroll = c7_ddroll;
  *c7_b_ddpitch = c7_ddpitch;
  *c7_b_ddyaw = c7_ddyaw;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, *c7_sfEvent);
  sf_debug_check_for_state_inconsistency(_lab2_next_levelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc7_lab2_next_level(SFc7_lab2_next_levelInstanceStruct *
  chartInstance)
{
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber)
{
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc7_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static real_T c7_emlrt_marshallIn(SFc7_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c7_ddyaw, const char_T *c7_identifier)
{
  real_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_ddyaw), &c7_thisId);
  sf_mex_destroy(&c7_ddyaw);
  return c7_y;
}

static real_T c7_b_emlrt_marshallIn(SFc7_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d0, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_ddyaw;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc7_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c7_ddyaw = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_ddyaw), &c7_thisId);
  sf_mex_destroy(&c7_ddyaw);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i2;
  real_T c7_b_inData[4];
  int32_T c7_i3;
  real_T c7_u[4];
  const mxArray *c7_y = NULL;
  SFc7_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc7_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i2 = 0; c7_i2 < 4; c7_i2++) {
    c7_b_inData[c7_i2] = (*(real_T (*)[4])c7_inData)[c7_i2];
  }

  for (c7_i3 = 0; c7_i3 < 4; c7_i3++) {
    c7_u[c7_i3] = c7_b_inData[c7_i3];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

const mxArray *sf_c7_lab2_next_level_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo;
  c7_ResolvedFunctionInfo c7_info[4];
  c7_ResolvedFunctionInfo (*c7_b_info)[4];
  const mxArray *c7_m0 = NULL;
  int32_T c7_i4;
  c7_ResolvedFunctionInfo *c7_r0;
  c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  c7_b_info = (c7_ResolvedFunctionInfo (*)[4])c7_info;
  (*c7_b_info)[0].context = "";
  (*c7_b_info)[0].name = "mtimes";
  (*c7_b_info)[0].dominantType = "double";
  (*c7_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c7_b_info)[0].fileTimeLo = 1289508892U;
  (*c7_b_info)[0].fileTimeHi = 0U;
  (*c7_b_info)[0].mFileTimeLo = 0U;
  (*c7_b_info)[0].mFileTimeHi = 0U;
  (*c7_b_info)[1].context = "";
  (*c7_b_info)[1].name = "mrdivide";
  (*c7_b_info)[1].dominantType = "double";
  (*c7_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c7_b_info)[1].fileTimeLo = 1342803744U;
  (*c7_b_info)[1].fileTimeHi = 0U;
  (*c7_b_info)[1].mFileTimeLo = 1319722766U;
  (*c7_b_info)[1].mFileTimeHi = 0U;
  (*c7_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c7_b_info)[2].name = "rdivide";
  (*c7_b_info)[2].dominantType = "double";
  (*c7_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c7_b_info)[2].fileTimeLo = 1286811644U;
  (*c7_b_info)[2].fileTimeHi = 0U;
  (*c7_b_info)[2].mFileTimeLo = 0U;
  (*c7_b_info)[2].mFileTimeHi = 0U;
  (*c7_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c7_b_info)[3].name = "eml_div";
  (*c7_b_info)[3].dominantType = "double";
  (*c7_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c7_b_info)[3].fileTimeLo = 1313340610U;
  (*c7_b_info)[3].fileTimeHi = 0U;
  (*c7_b_info)[3].mFileTimeLo = 0U;
  (*c7_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c7_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4), FALSE);
  for (c7_i4 = 0; c7_i4 < 4; c7_i4++) {
    c7_r0 = &c7_info[c7_i4];
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->context)), "context", "nameCaptureInfo",
                    c7_i4);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c7_r0->name)), "name", "nameCaptureInfo", c7_i4);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c7_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c7_i4);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->resolved)), "resolved", "nameCaptureInfo",
                    c7_i4);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c7_i4);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c7_i4);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c7_i4);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c7_i4);
  }

  sf_mex_assign(&c7_nameCaptureInfo, c7_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c7_nameCaptureInfo);
  return c7_nameCaptureInfo;
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc7_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static int32_T c7_c_emlrt_marshallIn(SFc7_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i5;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i5, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i5;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc7_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c7_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_sfEvent), &c7_thisId);
  sf_mex_destroy(&c7_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static uint8_T c7_d_emlrt_marshallIn(SFc7_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c7_is_active_c7_lab2_next_level, const char_T
  *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_is_active_c7_lab2_next_level), &c7_thisId);
  sf_mex_destroy(&c7_is_active_c7_lab2_next_level);
  return c7_y;
}

static uint8_T c7_e_emlrt_marshallIn(SFc7_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void init_dsm_address_info(SFc7_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c7_lab2_next_level_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2182811628U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4027885392U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3843411274U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3832281417U);
}

mxArray *sf_c7_lab2_next_level_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("UG2SrEtWKDhSOzjxTz5AJG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
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

static const mxArray *sf_get_sim_state_info_c7_lab2_next_level(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[6],T\"ddpitch\",},{M[1],M[5],T\"ddroll\",},{M[1],M[7],T\"ddyaw\",},{M[8],M[0],T\"is_active_c7_lab2_next_level\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_lab2_next_level_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_lab2_next_levelInstanceStruct *chartInstance;
    chartInstance = (SFc7_lab2_next_levelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_lab2_next_levelMachineNumber_,
           7,
           1,
           1,
           4,
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"ddroll");
          _SFD_SET_DATA_PROPS(2,2,0,1,"ddpitch");
          _SFD_SET_DATA_PROPS(3,2,0,1,"ddyaw");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,337);
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
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);

        {
          real_T *c7_ddroll;
          real_T *c7_ddpitch;
          real_T *c7_ddyaw;
          real_T (*c7_P)[4];
          c7_ddyaw = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c7_ddpitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c7_ddroll = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c7_P = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c7_P);
          _SFD_SET_DATA_VALUE_PTR(1U, c7_ddroll);
          _SFD_SET_DATA_VALUE_PTR(2U, c7_ddpitch);
          _SFD_SET_DATA_VALUE_PTR(3U, c7_ddyaw);
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
  return "6R24wC1NieJ1PcJRFzy98B";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 7, "dworkChecksum");
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

static void sf_opaque_initialize_c7_lab2_next_level(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc7_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc7_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c7_lab2_next_level((SFc7_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
  initialize_c7_lab2_next_level((SFc7_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c7_lab2_next_level(void *chartInstanceVar)
{
  enable_c7_lab2_next_level((SFc7_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c7_lab2_next_level(void *chartInstanceVar)
{
  disable_c7_lab2_next_level((SFc7_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c7_lab2_next_level(void *chartInstanceVar)
{
  sf_c7_lab2_next_level((SFc7_lab2_next_levelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c7_lab2_next_level(void *chartInstanceVar)
{
  ext_mode_exec_c7_lab2_next_level((SFc7_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c7_lab2_next_level(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c7_lab2_next_level
    ((SFc7_lab2_next_levelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_lab2_next_level();/* state var info */
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

extern void sf_internal_set_sim_state_c7_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_lab2_next_level();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c7_lab2_next_level((SFc7_lab2_next_levelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c7_lab2_next_level(SimStruct* S)
{
  return sf_internal_get_sim_state_c7_lab2_next_level(S);
}

static void sf_opaque_set_sim_state_c7_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c7_lab2_next_level(S, st);
}

static void sf_opaque_terminate_c7_lab2_next_level(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_lab2_next_levelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c7_lab2_next_level((SFc7_lab2_next_levelInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_lab2_next_level_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_lab2_next_level((SFc7_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_lab2_next_level(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_lab2_next_level((SFc7_lab2_next_levelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c7_lab2_next_level_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c7_lab2_next_level\",T\"is_active_c7_lab2_next_level\"}}"
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

static void mdlSetWorkWidths_c7_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,7,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,3);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1979228051U));
  ssSetChecksum1(S,(2516422497U));
  ssSetChecksum2(S,(865415103U));
  ssSetChecksum3(S,(4024504897U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_lab2_next_level(SimStruct *S)
{
  SFc7_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc7_lab2_next_levelInstanceStruct *)malloc(sizeof
    (SFc7_lab2_next_levelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc7_lab2_next_levelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_lab2_next_level;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c7_lab2_next_level;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c7_lab2_next_level;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_lab2_next_level;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c7_lab2_next_level;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_lab2_next_level;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_lab2_next_level;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_lab2_next_level;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_lab2_next_level;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_lab2_next_level;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_lab2_next_level;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c7_lab2_next_level;
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

void c7_lab2_next_level_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_lab2_next_level(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_lab2_next_level(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_lab2_next_level(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_lab2_next_level_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
