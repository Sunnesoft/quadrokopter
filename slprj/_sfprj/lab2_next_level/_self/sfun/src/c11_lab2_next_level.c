/* Include files */

#include "blascompat32.h"
#include "lab2_next_level_sfun.h"
#include "c11_lab2_next_level.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lab2_next_level_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c11_debug_family_names[13] = { "x", "y", "z", "ya", "cy",
  "sy", "CZ", "M", "nargin", "nargout", "yaw", "ang_vel", "out" };

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
static void ext_mode_exec_c11_lab2_next_level
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
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_out, const char_T *c11_identifier, real_T
  c11_y[3]);
static void c11_b_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[3]);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_c_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
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
  *chartInstance, const mxArray *c11_is_active_c11_lab2_next_level, const char_T
  *c11_identifier);
static uint8_T c11_g_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void init_dsm_address_info(SFc11_lab2_next_levelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_lab2_next_level(SFc11_lab2_next_levelInstanceStruct
  *chartInstance)
{
  int32_T *c11_sfEvent;
  uint8_T *c11_is_active_c11_lab2_next_level;
  c11_is_active_c11_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c11_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c11_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c11_is_active_c11_lab2_next_level = 0U;
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

static void ext_mode_exec_c11_lab2_next_level
  (SFc11_lab2_next_levelInstanceStruct *chartInstance)
{
  c11_update_debugger_state_c11_lab2_next_level(chartInstance);
}

static const mxArray *get_sim_state_c11_lab2_next_level
  (SFc11_lab2_next_levelInstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  int32_T c11_i0;
  real_T c11_u[3];
  const mxArray *c11_b_y = NULL;
  uint8_T c11_hoistedGlobal;
  uint8_T c11_b_u;
  const mxArray *c11_c_y = NULL;
  uint8_T *c11_is_active_c11_lab2_next_level;
  real_T (*c11_out)[3];
  c11_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_is_active_c11_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellarray(2), FALSE);
  for (c11_i0 = 0; c11_i0 < 3; c11_i0++) {
    c11_u[c11_i0] = (*c11_out)[c11_i0];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_hoistedGlobal = *c11_is_active_c11_lab2_next_level;
  c11_b_u = c11_hoistedGlobal;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c11_y, 1, c11_c_y);
  sf_mex_assign(&c11_st, c11_y, FALSE);
  return c11_st;
}

static void set_sim_state_c11_lab2_next_level
  (SFc11_lab2_next_levelInstanceStruct *chartInstance, const mxArray *c11_st)
{
  const mxArray *c11_u;
  real_T c11_dv0[3];
  int32_T c11_i1;
  boolean_T *c11_doneDoubleBufferReInit;
  uint8_T *c11_is_active_c11_lab2_next_level;
  real_T (*c11_out)[3];
  c11_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_is_active_c11_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c11_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c11_doneDoubleBufferReInit = TRUE;
  c11_u = sf_mex_dup(c11_st);
  c11_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 0)),
                       "out", c11_dv0);
  for (c11_i1 = 0; c11_i1 < 3; c11_i1++) {
    (*c11_out)[c11_i1] = c11_dv0[c11_i1];
  }

  *c11_is_active_c11_lab2_next_level = c11_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 1)), "is_active_c11_lab2_next_level");
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
  int32_T c11_i2;
  int32_T c11_i3;
  int32_T *c11_sfEvent;
  real_T *c11_yaw;
  real_T (*c11_out)[3];
  real_T (*c11_ang_vel)[3];
  c11_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_ang_vel = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c11_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c11_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, *c11_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c11_yaw, 0U);
  for (c11_i2 = 0; c11_i2 < 3; c11_i2++) {
    _SFD_DATA_RANGE_CHECK((*c11_ang_vel)[c11_i2], 1U);
  }

  for (c11_i3 = 0; c11_i3 < 3; c11_i3++) {
    _SFD_DATA_RANGE_CHECK((*c11_out)[c11_i3], 2U);
  }

  *c11_sfEvent = CALL_EVENT;
  c11_chartstep_c11_lab2_next_level(chartInstance);
  sf_debug_check_for_state_inconsistency(_lab2_next_levelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c11_chartstep_c11_lab2_next_level
  (SFc11_lab2_next_levelInstanceStruct *chartInstance)
{
  real_T c11_hoistedGlobal;
  real_T c11_yaw;
  int32_T c11_i4;
  real_T c11_ang_vel[3];
  uint32_T c11_debug_family_var_map[13];
  real_T c11_x;
  real_T c11_y;
  real_T c11_z;
  real_T c11_ya;
  real_T c11_cy;
  real_T c11_sy;
  real_T c11_CZ[9];
  real_T c11_M[3];
  real_T c11_nargin = 2.0;
  real_T c11_nargout = 1.0;
  real_T c11_out[3];
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_d_x;
  real_T c11_e_x;
  int32_T c11_i5;
  int32_T c11_i6;
  static real_T c11_dv1[3] = { 0.0, 0.0, 1.0 };

  int32_T c11_i7;
  int32_T c11_i8;
  int32_T c11_i9;
  int32_T c11_i10;
  real_T c11_a[9];
  real_T c11_b[3];
  int32_T c11_i11;
  int32_T c11_i12;
  int32_T c11_i13;
  real_T c11_C[3];
  int32_T c11_i14;
  int32_T c11_i15;
  int32_T c11_i16;
  int32_T c11_i17;
  int32_T c11_i18;
  int32_T c11_i19;
  int32_T c11_i20;
  int32_T c11_i21;
  real_T *c11_b_yaw;
  real_T (*c11_b_out)[3];
  real_T (*c11_b_ang_vel)[3];
  int32_T *c11_sfEvent;
  c11_b_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_b_ang_vel = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c11_b_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c11_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, *c11_sfEvent);
  c11_hoistedGlobal = *c11_b_yaw;
  c11_yaw = c11_hoistedGlobal;
  for (c11_i4 = 0; c11_i4 < 3; c11_i4++) {
    c11_ang_vel[c11_i4] = (*c11_b_ang_vel)[c11_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c11_debug_family_names,
    c11_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c11_x, 0U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c11_y, 1U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c11_z, 2U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c11_ya, 3U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c11_cy, 4U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c11_sy, 5U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c11_CZ, 6U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c11_M, 7U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c11_nargin, 8U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c11_nargout, 9U,
    c11_b_sf_marshallOut, c11_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c11_yaw, 10U, c11_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c11_ang_vel, 11U, c11_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c11_out, 12U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c11_sfEvent, 5);
  c11_x = c11_ang_vel[0];
  _SFD_EML_CALL(0U, *c11_sfEvent, 6);
  c11_y = c11_ang_vel[1];
  _SFD_EML_CALL(0U, *c11_sfEvent, 7);
  c11_z = c11_ang_vel[2];
  _SFD_EML_CALL(0U, *c11_sfEvent, 8);
  _SFD_EML_CALL(0U, *c11_sfEvent, 10);
  c11_ya = c11_yaw;
  _SFD_EML_CALL(0U, *c11_sfEvent, 11);
  c11_b_x = c11_ya;
  c11_cy = c11_b_x;
  c11_c_x = c11_cy;
  c11_cy = c11_c_x;
  c11_cy = muDoubleScalarCos(c11_cy);
  _SFD_EML_CALL(0U, *c11_sfEvent, 11);
  c11_d_x = c11_ya;
  c11_sy = c11_d_x;
  c11_e_x = c11_sy;
  c11_sy = c11_e_x;
  c11_sy = muDoubleScalarSin(c11_sy);
  _SFD_EML_CALL(0U, *c11_sfEvent, 13);
  c11_CZ[0] = c11_cy;
  c11_CZ[3] = c11_sy;
  c11_CZ[6] = 0.0;
  c11_CZ[1] = -c11_sy;
  c11_CZ[4] = c11_cy;
  c11_CZ[7] = 0.0;
  c11_i5 = 0;
  for (c11_i6 = 0; c11_i6 < 3; c11_i6++) {
    c11_CZ[c11_i5 + 2] = c11_dv1[c11_i6];
    c11_i5 += 3;
  }

  _SFD_EML_CALL(0U, *c11_sfEvent, 15);
  c11_i7 = 0;
  for (c11_i8 = 0; c11_i8 < 3; c11_i8++) {
    c11_i9 = 0;
    for (c11_i10 = 0; c11_i10 < 3; c11_i10++) {
      c11_a[c11_i10 + c11_i7] = c11_CZ[c11_i9 + c11_i8];
      c11_i9 += 3;
    }

    c11_i7 += 3;
  }

  c11_b[0] = c11_x;
  c11_b[1] = c11_y;
  c11_b[2] = c11_z;
  c11_eml_scalar_eg(chartInstance);
  c11_eml_scalar_eg(chartInstance);
  for (c11_i11 = 0; c11_i11 < 3; c11_i11++) {
    c11_M[c11_i11] = 0.0;
  }

  for (c11_i12 = 0; c11_i12 < 3; c11_i12++) {
    c11_M[c11_i12] = 0.0;
  }

  for (c11_i13 = 0; c11_i13 < 3; c11_i13++) {
    c11_C[c11_i13] = c11_M[c11_i13];
  }

  for (c11_i14 = 0; c11_i14 < 3; c11_i14++) {
    c11_M[c11_i14] = c11_C[c11_i14];
  }

  for (c11_i15 = 0; c11_i15 < 3; c11_i15++) {
    c11_C[c11_i15] = c11_M[c11_i15];
  }

  for (c11_i16 = 0; c11_i16 < 3; c11_i16++) {
    c11_M[c11_i16] = c11_C[c11_i16];
  }

  for (c11_i17 = 0; c11_i17 < 3; c11_i17++) {
    c11_M[c11_i17] = 0.0;
    c11_i18 = 0;
    for (c11_i19 = 0; c11_i19 < 3; c11_i19++) {
      c11_M[c11_i17] += c11_a[c11_i18 + c11_i17] * c11_b[c11_i19];
      c11_i18 += 3;
    }
  }

  _SFD_EML_CALL(0U, *c11_sfEvent, 17);
  for (c11_i20 = 0; c11_i20 < 3; c11_i20++) {
    c11_out[c11_i20] = 0.0;
  }

  _SFD_EML_CALL(0U, *c11_sfEvent, 18);
  c11_out[0] = c11_M[0];
  _SFD_EML_CALL(0U, *c11_sfEvent, 19);
  c11_out[1] = c11_M[1];
  _SFD_EML_CALL(0U, *c11_sfEvent, 20);
  c11_out[2] = c11_M[2];
  _SFD_EML_CALL(0U, *c11_sfEvent, -20);
  sf_debug_symbol_scope_pop();
  for (c11_i21 = 0; c11_i21 < 3; c11_i21++) {
    (*c11_b_out)[c11_i21] = c11_out[c11_i21];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, *c11_sfEvent);
}

static void initSimStructsc11_lab2_next_level
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
  int32_T c11_i22;
  real_T c11_b_inData[3];
  int32_T c11_i23;
  real_T c11_u[3];
  const mxArray *c11_y = NULL;
  SFc11_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc11_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i22 = 0; c11_i22 < 3; c11_i22++) {
    c11_b_inData[c11_i22] = (*(real_T (*)[3])c11_inData)[c11_i22];
  }

  for (c11_i23 = 0; c11_i23 < 3; c11_i23++) {
    c11_u[c11_i23] = c11_b_inData[c11_i23];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static void c11_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_out, const char_T *c11_identifier, real_T
  c11_y[3])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_out), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_out);
}

static void c11_b_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[3])
{
  real_T c11_dv2[3];
  int32_T c11_i24;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv2, 1, 0, 0U, 1, 0U, 1, 3);
  for (c11_i24 = 0; c11_i24 < 3; c11_i24++) {
    c11_y[c11_i24] = c11_dv2[c11_i24];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_out;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[3];
  int32_T c11_i25;
  SFc11_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc11_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c11_out = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_out), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_out);
  for (c11_i25 = 0; c11_i25 < 3; c11_i25++) {
    (*(real_T (*)[3])c11_outData)[c11_i25] = c11_y[c11_i25];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
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

static real_T c11_c_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d0;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d0, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_nargout;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc11_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c11_nargout = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_nargout),
    &c11_thisId);
  sf_mex_destroy(&c11_nargout);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i26;
  int32_T c11_i27;
  int32_T c11_i28;
  real_T c11_b_inData[9];
  int32_T c11_i29;
  int32_T c11_i30;
  int32_T c11_i31;
  real_T c11_u[9];
  const mxArray *c11_y = NULL;
  SFc11_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc11_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_i26 = 0;
  for (c11_i27 = 0; c11_i27 < 3; c11_i27++) {
    for (c11_i28 = 0; c11_i28 < 3; c11_i28++) {
      c11_b_inData[c11_i28 + c11_i26] = (*(real_T (*)[9])c11_inData)[c11_i28 +
        c11_i26];
    }

    c11_i26 += 3;
  }

  c11_i29 = 0;
  for (c11_i30 = 0; c11_i30 < 3; c11_i30++) {
    for (c11_i31 = 0; c11_i31 < 3; c11_i31++) {
      c11_u[c11_i31 + c11_i29] = c11_b_inData[c11_i31 + c11_i29];
    }

    c11_i29 += 3;
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
  real_T c11_dv3[9];
  int32_T c11_i32;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv3, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c11_i32 = 0; c11_i32 < 9; c11_i32++) {
    c11_y[c11_i32] = c11_dv3[c11_i32];
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
  int32_T c11_i33;
  int32_T c11_i34;
  int32_T c11_i35;
  SFc11_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc11_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c11_CZ = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_CZ), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_CZ);
  c11_i33 = 0;
  for (c11_i34 = 0; c11_i34 < 3; c11_i34++) {
    for (c11_i35 = 0; c11_i35 < 3; c11_i35++) {
      (*(real_T (*)[9])c11_outData)[c11_i35 + c11_i33] = c11_y[c11_i35 + c11_i33];
    }

    c11_i33 += 3;
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

const mxArray *sf_c11_lab2_next_level_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo;
  c11_ResolvedFunctionInfo c11_info[13];
  const mxArray *c11_m0 = NULL;
  int32_T c11_i36;
  c11_ResolvedFunctionInfo *c11_r0;
  c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  c11_info_helper(c11_info);
  sf_mex_assign(&c11_m0, sf_mex_createstruct("nameCaptureInfo", 1, 13), FALSE);
  for (c11_i36 = 0; c11_i36 < 13; c11_i36++) {
    c11_r0 = &c11_info[c11_i36];
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->context)), "context", "nameCaptureInfo",
                    c11_i36);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->name)), "name", "nameCaptureInfo",
                    c11_i36);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      c11_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c11_i36);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->resolved)), "resolved",
                    "nameCaptureInfo", c11_i36);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c11_i36);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c11_i36);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      &c11_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c11_i36);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      &c11_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c11_i36);
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
  c11_info[0].fileTimeLo = 1286811506U;
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
  c11_info[2].fileTimeLo = 1286811550U;
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
  c11_info[4].fileTimeLo = 1289508892U;
  c11_info[4].fileTimeHi = 0U;
  c11_info[4].mFileTimeLo = 0U;
  c11_info[4].mFileTimeHi = 0U;
  c11_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[5].name = "eml_index_class";
  c11_info[5].dominantType = "";
  c11_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[5].fileTimeLo = 1323159778U;
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
  c11_info[7].fileTimeLo = 1299065972U;
  c11_info[7].fileTimeHi = 0U;
  c11_info[7].mFileTimeLo = 0U;
  c11_info[7].mFileTimeHi = 0U;
  c11_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c11_info[8].name = "eml_blas_inline";
  c11_info[8].dominantType = "";
  c11_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c11_info[8].fileTimeLo = 1299065968U;
  c11_info[8].fileTimeHi = 0U;
  c11_info[8].mFileTimeLo = 0U;
  c11_info[8].mFileTimeHi = 0U;
  c11_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c11_info[9].name = "mtimes";
  c11_info[9].dominantType = "double";
  c11_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[9].fileTimeLo = 1289508892U;
  c11_info[9].fileTimeHi = 0U;
  c11_info[9].mFileTimeLo = 0U;
  c11_info[9].mFileTimeHi = 0U;
  c11_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c11_info[10].name = "eml_index_class";
  c11_info[10].dominantType = "";
  c11_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[10].fileTimeLo = 1323159778U;
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
  c11_info[12].fileTimeLo = 1299065974U;
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
  int32_T c11_i37;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i37, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i37;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc11_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c11_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static uint8_T c11_f_emlrt_marshallIn(SFc11_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c11_is_active_c11_lab2_next_level, const char_T
  *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_is_active_c11_lab2_next_level), &c11_thisId);
  sf_mex_destroy(&c11_is_active_c11_lab2_next_level);
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
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c11_lab2_next_level_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(303732612U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1327375136U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(262942713U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1921326969U);
}

mxArray *sf_c11_lab2_next_level_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("NjkKiHc1lIp9X5V6VaFIFG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c11_lab2_next_level(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[10],T\"out\",},{M[8],M[0],T\"is_active_c11_lab2_next_level\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
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
          (_lab2_next_levelMachineNumber_,
           11,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"yaw");
          _SFD_SET_DATA_PROPS(1,1,1,0,"ang_vel");
          _SFD_SET_DATA_PROPS(2,2,0,1,"out");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,349);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        {
          real_T *c11_yaw;
          real_T (*c11_ang_vel)[3];
          real_T (*c11_out)[3];
          c11_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c11_ang_vel = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c11_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c11_yaw);
          _SFD_SET_DATA_VALUE_PTR(1U, *c11_ang_vel);
          _SFD_SET_DATA_VALUE_PTR(2U, *c11_out);
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
  return "t5vqPwHEy8XcMX46aNH3XC";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 11, "dworkChecksum");
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

static void sf_opaque_initialize_c11_lab2_next_level(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc11_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S);
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

static void sf_opaque_ext_mode_exec_c11_lab2_next_level(void *chartInstanceVar)
{
  ext_mode_exec_c11_lab2_next_level((SFc11_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
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
    }

    finalize_c11_lab2_next_level((SFc11_lab2_next_levelInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_lab2_next_level_optimization_info();
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

mxArray *sf_c11_lab2_next_level_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c11_lab2_next_level\",T\"is_active_c11_lab2_next_level\"}}"
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
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,11,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(610799334U));
  ssSetChecksum1(S,(3769076410U));
  ssSetChecksum2(S,(3261634465U));
  ssSetChecksum3(S,(1837382922U));
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
  chartInstance = (SFc11_lab2_next_levelInstanceStruct *)malloc(sizeof
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
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c11_lab2_next_level;
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
