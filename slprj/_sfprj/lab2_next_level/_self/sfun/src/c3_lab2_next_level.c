/* Include files */

#include "blascompat32.h"
#include "lab2_next_level_sfun.h"
#include "c3_lab2_next_level.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lab2_next_level_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[15] = { "roll", "pitch", "yaw", "x",
  "y", "z", "P", "M", "nargin", "nargout", "angles", "accel", "xs", "ys", "zs" };

/* Function Declarations */
static void initialize_c3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct
  *chartInstance);
static void initialize_params_c3_lab2_next_level
  (SFc3_lab2_next_levelInstanceStruct *chartInstance);
static void enable_c3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct
  *chartInstance);
static void disable_c3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_lab2_next_level
  (SFc3_lab2_next_levelInstanceStruct *chartInstance);
static void ext_mode_exec_c3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c3_lab2_next_level
  (SFc3_lab2_next_levelInstanceStruct *chartInstance);
static void set_sim_state_c3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct *
  chartInstance, const mxArray *c3_st);
static void finalize_c3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct
  *chartInstance);
static void sf_c3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct
  *chartInstance);
static void c3_chartstep_c3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct
  *chartInstance);
static void initSimStructsc3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_zs, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[3]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_eml_scalar_eg(SFc3_lab2_next_levelInstanceStruct *chartInstance);
static void c3_d_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_rotationMatrix, const char_T *c3_identifier,
  real_T c3_y[9]);
static void c3_e_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[9]);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_f_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_g_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
<<<<<<< HEAD
  *chartInstance, const mxArray *c3_b_is_active_c3_lab2_next_level, const char_T
=======
  *chartInstance, const mxArray *c3_is_active_c3_lab2_next_level, const char_T
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  *c3_identifier);
static uint8_T c3_h_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_lab2_next_levelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct
  *chartInstance)
{
  int32_T *c3_sfEvent;
  uint8_T *c3_is_active_c3_lab2_next_level;
  c3_is_active_c3_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c3_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c3_is_active_c3_lab2_next_level = 0U;
}

static void initialize_params_c3_lab2_next_level
  (SFc3_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void enable_c3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_lab2_next_level
  (SFc3_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct *
  chartInstance)
{
  c3_update_debugger_state_c3_lab2_next_level(chartInstance);
}

static const mxArray *get_sim_state_c3_lab2_next_level
  (SFc3_lab2_next_levelInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  uint8_T c3_d_hoistedGlobal;
  uint8_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  real_T *c3_xs;
  real_T *c3_ys;
  real_T *c3_zs;
<<<<<<< HEAD
  c3_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
=======
  uint8_T *c3_is_active_c3_lab2_next_level;
  c3_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_is_active_c3_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(4), FALSE);
  c3_hoistedGlobal = *c3_xs;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_ys;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *c3_zs;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 2, c3_d_y);
<<<<<<< HEAD
  c3_d_hoistedGlobal = chartInstance->c3_is_active_c3_lab2_next_level;
=======
  c3_d_hoistedGlobal = *c3_is_active_c3_lab2_next_level;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct *
  chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
<<<<<<< HEAD
  real_T *c3_xs;
  real_T *c3_ys;
  real_T *c3_zs;
  c3_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
=======
  boolean_T *c3_doneDoubleBufferReInit;
  real_T *c3_xs;
  real_T *c3_ys;
  real_T *c3_zs;
  uint8_T *c3_is_active_c3_lab2_next_level;
  c3_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_is_active_c3_lab2_next_level = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c3_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c3_doneDoubleBufferReInit = TRUE;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  c3_u = sf_mex_dup(c3_st);
  *c3_xs = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
    "xs");
  *c3_ys = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
    "ys");
  *c3_zs = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
    "zs");
<<<<<<< HEAD
  chartInstance->c3_is_active_c3_lab2_next_level = c3_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)),
     "is_active_c3_lab2_next_level");
=======
  *c3_is_active_c3_lab2_next_level = c3_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 3)), "is_active_c3_lab2_next_level");
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_lab2_next_level(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

static void sf_c3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct
  *chartInstance)
{
  int32_T c3_i0;
  int32_T c3_i1;
<<<<<<< HEAD
=======
  int32_T *c3_sfEvent;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  real_T *c3_xs;
  real_T *c3_ys;
  real_T *c3_zs;
  real_T (*c3_accel)[3];
  real_T (*c3_angles)[3];
  c3_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_accel = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c3_angles = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
<<<<<<< HEAD
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i0 = 0; c3_i0 < 3; c3_i0++) {
    _SFD_DATA_RANGE_CHECK((*c3_angles)[c3_i0], 0U);
  }

  for (c3_i1 = 0; c3_i1 < 3; c3_i1++) {
    _SFD_DATA_RANGE_CHECK((*c3_accel)[c3_i1], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_xs, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_ys, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_zs, 4U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_lab2_next_level(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lab2_next_levelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct
  *chartInstance)
{
  int32_T c3_i2;
  real_T c3_angles[3];
  int32_T c3_i3;
  real_T c3_accel[3];
  uint32_T c3_debug_family_var_map[15];
  real_T c3_roll;
  real_T c3_pitch;
  real_T c3_yaw;
  real_T c3_x;
  real_T c3_y;
  real_T c3_z;
  real_T c3_P[9];
  real_T c3_M[3];
  real_T c3_nargin = 2.0;
  real_T c3_nargout = 3.0;
  real_T c3_xs;
  real_T c3_ys;
  real_T c3_zs;
  int32_T c3_i4;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_dv0[9];
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  real_T c3_a[9];
  real_T c3_b[3];
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  real_T c3_C[3];
  int32_T c3_i13;
  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  real_T *c3_b_xs;
  real_T *c3_b_ys;
  real_T *c3_b_zs;
  real_T (*c3_b_accel)[3];
  real_T (*c3_b_angles)[3];
  c3_b_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_b_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_accel = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_angles = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i2 = 0; c3_i2 < 3; c3_i2++) {
    c3_angles[c3_i2] = (*c3_b_angles)[c3_i2];
  }

  for (c3_i3 = 0; c3_i3 < 3; c3_i3++) {
    c3_accel[c3_i3] = (*c3_b_accel)[c3_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_roll, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_pitch, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_yaw, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_x, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_y, 4U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_z, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_P, 6U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_M, 7U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 8U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 9U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_angles, 10U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_accel, 11U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_xs, 12U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_ys, 13U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_zs, 14U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  c3_roll = c3_angles[0];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_pitch = c3_angles[0];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_yaw = c3_angles[2];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_x = c3_accel[0];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
  c3_y = c3_accel[1];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 11);
  c3_z = c3_accel[2];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 13);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 15);
=======
  c3_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, *c3_sfEvent);
  for (c3_i0 = 0; c3_i0 < 3; c3_i0++) {
    _SFD_DATA_RANGE_CHECK((*c3_angles)[c3_i0], 0U);
  }

  for (c3_i1 = 0; c3_i1 < 3; c3_i1++) {
    _SFD_DATA_RANGE_CHECK((*c3_accel)[c3_i1], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_xs, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_ys, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_zs, 4U);
  *c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_lab2_next_level(chartInstance);
  sf_debug_check_for_state_inconsistency(_lab2_next_levelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct
  *chartInstance)
{
  int32_T c3_i2;
  real_T c3_angles[3];
  int32_T c3_i3;
  real_T c3_accel[3];
  uint32_T c3_debug_family_var_map[15];
  real_T c3_roll;
  real_T c3_pitch;
  real_T c3_yaw;
  real_T c3_x;
  real_T c3_y;
  real_T c3_z;
  real_T c3_P[9];
  real_T c3_M[3];
  real_T c3_nargin = 2.0;
  real_T c3_nargout = 3.0;
  real_T c3_xs;
  real_T c3_ys;
  real_T c3_zs;
  int32_T c3_i4;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_dv0[9];
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  real_T c3_a[9];
  real_T c3_b[3];
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  real_T c3_C[3];
  int32_T c3_i13;
  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  real_T *c3_b_xs;
  real_T *c3_b_ys;
  real_T *c3_b_zs;
  real_T (*c3_b_accel)[3];
  real_T (*c3_b_angles)[3];
  int32_T *c3_sfEvent;
  c3_b_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_b_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_accel = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_angles = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c3_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, *c3_sfEvent);
  for (c3_i2 = 0; c3_i2 < 3; c3_i2++) {
    c3_angles[c3_i2] = (*c3_b_angles)[c3_i2];
  }

  for (c3_i3 = 0; c3_i3 < 3; c3_i3++) {
    c3_accel[c3_i3] = (*c3_b_accel)[c3_i3];
  }

  sf_debug_symbol_scope_push_eml(0U, 15U, 15U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c3_roll, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_pitch, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_yaw, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_x, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_y, 4U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_z, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_P, 6U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_M, 7U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 8U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 9U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c3_angles, 10U, c3_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_accel, 11U, c3_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_xs, 12U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_ys, 13U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_zs, 14U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c3_sfEvent, 5);
  c3_roll = c3_angles[0];
  _SFD_EML_CALL(0U, *c3_sfEvent, 6);
  c3_pitch = c3_angles[0];
  _SFD_EML_CALL(0U, *c3_sfEvent, 7);
  c3_yaw = c3_angles[2];
  _SFD_EML_CALL(0U, *c3_sfEvent, 9);
  c3_x = c3_accel[0];
  _SFD_EML_CALL(0U, *c3_sfEvent, 10);
  c3_y = c3_accel[1];
  _SFD_EML_CALL(0U, *c3_sfEvent, 11);
  c3_z = c3_accel[2];
  _SFD_EML_CALL(0U, *c3_sfEvent, 13);
  _SFD_EML_CALL(0U, *c3_sfEvent, 15);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  for (c3_i4 = 0; c3_i4 < 9; c3_i4++) {
    c3_P[c3_i4] = 0.0;
  }

<<<<<<< HEAD
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 16);
=======
  _SFD_EML_CALL(0U, *c3_sfEvent, 16);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  c3_u = c3_roll;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  c3_b_u = c3_pitch;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  c3_c_u = c3_yaw;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_call_debug("rotationMatrix", 1U,
    3U, 14, c3_b_y, 14, c3_c_y, 14, c3_d_y), "rotationMatrix", c3_dv0);
  for (c3_i5 = 0; c3_i5 < 9; c3_i5++) {
    c3_P[c3_i5] = c3_dv0[c3_i5];
  }

<<<<<<< HEAD
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 18);
=======
  _SFD_EML_CALL(0U, *c3_sfEvent, 18);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  c3_i6 = 0;
  for (c3_i7 = 0; c3_i7 < 3; c3_i7++) {
    c3_i8 = 0;
    for (c3_i9 = 0; c3_i9 < 3; c3_i9++) {
      c3_a[c3_i9 + c3_i6] = c3_P[c3_i8 + c3_i7];
      c3_i8 += 3;
    }

    c3_i6 += 3;
<<<<<<< HEAD
  }

  c3_b[0] = c3_x;
  c3_b[1] = c3_y;
  c3_b[2] = c3_z;
  c3_eml_scalar_eg(chartInstance);
  c3_eml_scalar_eg(chartInstance);
  for (c3_i10 = 0; c3_i10 < 3; c3_i10++) {
    c3_M[c3_i10] = 0.0;
  }

  for (c3_i11 = 0; c3_i11 < 3; c3_i11++) {
    c3_M[c3_i11] = 0.0;
  }

=======
  }

  c3_b[0] = c3_x;
  c3_b[1] = c3_y;
  c3_b[2] = c3_z;
  c3_eml_scalar_eg(chartInstance);
  c3_eml_scalar_eg(chartInstance);
  for (c3_i10 = 0; c3_i10 < 3; c3_i10++) {
    c3_M[c3_i10] = 0.0;
  }

  for (c3_i11 = 0; c3_i11 < 3; c3_i11++) {
    c3_M[c3_i11] = 0.0;
  }

>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  for (c3_i12 = 0; c3_i12 < 3; c3_i12++) {
    c3_C[c3_i12] = c3_M[c3_i12];
  }

  for (c3_i13 = 0; c3_i13 < 3; c3_i13++) {
    c3_M[c3_i13] = c3_C[c3_i13];
  }

  for (c3_i14 = 0; c3_i14 < 3; c3_i14++) {
    c3_C[c3_i14] = c3_M[c3_i14];
  }

  for (c3_i15 = 0; c3_i15 < 3; c3_i15++) {
    c3_M[c3_i15] = c3_C[c3_i15];
  }

  for (c3_i16 = 0; c3_i16 < 3; c3_i16++) {
    c3_M[c3_i16] = 0.0;
    c3_i17 = 0;
    for (c3_i18 = 0; c3_i18 < 3; c3_i18++) {
      c3_M[c3_i16] += c3_a[c3_i17 + c3_i16] * c3_b[c3_i18];
      c3_i17 += 3;
    }
  }

<<<<<<< HEAD
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 20);
  c3_xs = c3_M[0];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 21);
  c3_ys = c3_M[1];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 22);
  c3_zs = c3_M[2];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -22);
  _SFD_SYMBOL_SCOPE_POP();
  *c3_b_xs = c3_xs;
  *c3_b_ys = c3_ys;
  *c3_b_zs = c3_zs;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
=======
  _SFD_EML_CALL(0U, *c3_sfEvent, 20);
  c3_xs = c3_M[0];
  _SFD_EML_CALL(0U, *c3_sfEvent, 21);
  c3_ys = c3_M[1];
  _SFD_EML_CALL(0U, *c3_sfEvent, 22);
  c3_zs = c3_M[2];
  _SFD_EML_CALL(0U, *c3_sfEvent, -22);
  sf_debug_symbol_scope_pop();
  *c3_b_xs = c3_xs;
  *c3_b_ys = c3_ys;
  *c3_b_zs = c3_zs;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *c3_sfEvent);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
}

static void initSimStructsc3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct *
  chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc3_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_zs, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_zs), &c3_thisId);
  sf_mex_destroy(&c3_zs);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_zs;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc3_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c3_zs = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_zs), &c3_thisId);
  sf_mex_destroy(&c3_zs);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i19;
  real_T c3_b_inData[3];
  int32_T c3_i20;
  real_T c3_u[3];
<<<<<<< HEAD
=======
  const mxArray *c3_y = NULL;
  SFc3_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc3_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i19 = 0; c3_i19 < 3; c3_i19++) {
    c3_b_inData[c3_i19] = (*(real_T (*)[3])c3_inData)[c3_i19];
  }

  for (c3_i20 = 0; c3_i20 < 3; c3_i20++) {
    c3_u[c3_i20] = c3_b_inData[c3_i20];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[3])
{
  real_T c3_dv1[3];
  int32_T c3_i21;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c3_i21 = 0; c3_i21 < 3; c3_i21++) {
    c3_y[c3_i21] = c3_dv1[c3_i21];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_M;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[3];
  int32_T c3_i22;
  SFc3_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc3_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c3_M = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_M), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_M);
  for (c3_i22 = 0; c3_i22 < 3; c3_i22++) {
    (*(real_T (*)[3])c3_outData)[c3_i22] = c3_y[c3_i22];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  real_T c3_b_inData[9];
  int32_T c3_i26;
  int32_T c3_i27;
  int32_T c3_i28;
  real_T c3_u[9];
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  const mxArray *c3_y = NULL;
  SFc3_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc3_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
<<<<<<< HEAD
  for (c3_i19 = 0; c3_i19 < 3; c3_i19++) {
    c3_b_inData[c3_i19] = (*(real_T (*)[3])c3_inData)[c3_i19];
  }

  for (c3_i20 = 0; c3_i20 < 3; c3_i20++) {
    c3_u[c3_i20] = c3_b_inData[c3_i20];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
=======
  c3_i23 = 0;
  for (c3_i24 = 0; c3_i24 < 3; c3_i24++) {
    for (c3_i25 = 0; c3_i25 < 3; c3_i25++) {
      c3_b_inData[c3_i25 + c3_i23] = (*(real_T (*)[9])c3_inData)[c3_i25 + c3_i23];
    }

    c3_i23 += 3;
  }

  c3_i26 = 0;
  for (c3_i27 = 0; c3_i27 < 3; c3_i27++) {
    for (c3_i28 = 0; c3_i28 < 3; c3_i28++) {
      c3_u[c3_i28 + c3_i26] = c3_b_inData[c3_i28 + c3_i26];
    }

    c3_i26 += 3;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

<<<<<<< HEAD
static void c3_c_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[3])
{
  real_T c3_dv1[3];
  int32_T c3_i21;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c3_i21 = 0; c3_i21 < 3; c3_i21++) {
    c3_y[c3_i21] = c3_dv1[c3_i21];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_M;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[3];
  int32_T c3_i22;
  SFc3_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc3_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c3_M = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_M), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_M);
  for (c3_i22 = 0; c3_i22 < 3; c3_i22++) {
    (*(real_T (*)[3])c3_outData)[c3_i22] = c3_y[c3_i22];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  real_T c3_b_inData[9];
  int32_T c3_i26;
  int32_T c3_i27;
  int32_T c3_i28;
  real_T c3_u[9];
  const mxArray *c3_y = NULL;
  SFc3_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc3_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i23 = 0;
  for (c3_i24 = 0; c3_i24 < 3; c3_i24++) {
    for (c3_i25 = 0; c3_i25 < 3; c3_i25++) {
      c3_b_inData[c3_i25 + c3_i23] = (*(real_T (*)[9])c3_inData)[c3_i25 + c3_i23];
    }

    c3_i23 += 3;
  }

  c3_i26 = 0;
  for (c3_i27 = 0; c3_i27 < 3; c3_i27++) {
    for (c3_i28 = 0; c3_i28 < 3; c3_i28++) {
      c3_u[c3_i28 + c3_i26] = c3_b_inData[c3_i28 + c3_i26];
    }

    c3_i26 += 3;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

=======
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_rotationMatrix;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[9];
  int32_T c3_i29;
  int32_T c3_i30;
  int32_T c3_i31;
  SFc3_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc3_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c3_rotationMatrix = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_rotationMatrix), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_rotationMatrix);
  c3_i29 = 0;
  for (c3_i30 = 0; c3_i30 < 3; c3_i30++) {
    for (c3_i31 = 0; c3_i31 < 3; c3_i31++) {
      (*(real_T (*)[9])c3_outData)[c3_i31 + c3_i29] = c3_y[c3_i31 + c3_i29];
    }

    c3_i29 += 3;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_lab2_next_level_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[9];
  c3_ResolvedFunctionInfo (*c3_b_info)[9];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i32;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_b_info = (c3_ResolvedFunctionInfo (*)[9])c3_info;
  (*c3_b_info)[0].context = "";
  (*c3_b_info)[0].name = "mtimes";
  (*c3_b_info)[0].dominantType = "double";
  (*c3_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
<<<<<<< HEAD
  (*c3_b_info)[0].fileTimeLo = 1289512492U;
=======
  (*c3_b_info)[0].fileTimeLo = 1289508892U;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  (*c3_b_info)[0].fileTimeHi = 0U;
  (*c3_b_info)[0].mFileTimeLo = 0U;
  (*c3_b_info)[0].mFileTimeHi = 0U;
  (*c3_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c3_b_info)[1].name = "eml_index_class";
  (*c3_b_info)[1].dominantType = "";
  (*c3_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
<<<<<<< HEAD
  (*c3_b_info)[1].fileTimeLo = 1323163378U;
=======
  (*c3_b_info)[1].fileTimeLo = 1323159778U;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  (*c3_b_info)[1].fileTimeHi = 0U;
  (*c3_b_info)[1].mFileTimeLo = 0U;
  (*c3_b_info)[1].mFileTimeHi = 0U;
  (*c3_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c3_b_info)[2].name = "eml_scalar_eg";
  (*c3_b_info)[2].dominantType = "double";
  (*c3_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c3_b_info)[2].fileTimeLo = 1286811596U;
  (*c3_b_info)[2].fileTimeHi = 0U;
  (*c3_b_info)[2].mFileTimeLo = 0U;
  (*c3_b_info)[2].mFileTimeHi = 0U;
  (*c3_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c3_b_info)[3].name = "eml_xgemm";
  (*c3_b_info)[3].dominantType = "char";
  (*c3_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
<<<<<<< HEAD
  (*c3_b_info)[3].fileTimeLo = 1299069572U;
=======
  (*c3_b_info)[3].fileTimeLo = 1299065972U;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  (*c3_b_info)[3].fileTimeHi = 0U;
  (*c3_b_info)[3].mFileTimeLo = 0U;
  (*c3_b_info)[3].mFileTimeHi = 0U;
  (*c3_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c3_b_info)[4].name = "eml_blas_inline";
  (*c3_b_info)[4].dominantType = "";
  (*c3_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
<<<<<<< HEAD
  (*c3_b_info)[4].fileTimeLo = 1299069568U;
=======
  (*c3_b_info)[4].fileTimeLo = 1299065968U;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  (*c3_b_info)[4].fileTimeHi = 0U;
  (*c3_b_info)[4].mFileTimeLo = 0U;
  (*c3_b_info)[4].mFileTimeHi = 0U;
  (*c3_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  (*c3_b_info)[5].name = "mtimes";
  (*c3_b_info)[5].dominantType = "double";
  (*c3_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
<<<<<<< HEAD
  (*c3_b_info)[5].fileTimeLo = 1289512492U;
=======
  (*c3_b_info)[5].fileTimeLo = 1289508892U;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  (*c3_b_info)[5].fileTimeHi = 0U;
  (*c3_b_info)[5].mFileTimeLo = 0U;
  (*c3_b_info)[5].mFileTimeHi = 0U;
  (*c3_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c3_b_info)[6].name = "eml_index_class";
  (*c3_b_info)[6].dominantType = "";
  (*c3_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
<<<<<<< HEAD
  (*c3_b_info)[6].fileTimeLo = 1323163378U;
=======
  (*c3_b_info)[6].fileTimeLo = 1323159778U;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  (*c3_b_info)[6].fileTimeHi = 0U;
  (*c3_b_info)[6].mFileTimeLo = 0U;
  (*c3_b_info)[6].mFileTimeHi = 0U;
  (*c3_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c3_b_info)[7].name = "eml_scalar_eg";
  (*c3_b_info)[7].dominantType = "double";
  (*c3_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c3_b_info)[7].fileTimeLo = 1286811596U;
  (*c3_b_info)[7].fileTimeHi = 0U;
  (*c3_b_info)[7].mFileTimeLo = 0U;
  (*c3_b_info)[7].mFileTimeHi = 0U;
  (*c3_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c3_b_info)[8].name = "eml_refblas_xgemm";
  (*c3_b_info)[8].dominantType = "char";
  (*c3_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
<<<<<<< HEAD
  (*c3_b_info)[8].fileTimeLo = 1299069574U;
=======
  (*c3_b_info)[8].fileTimeLo = 1299065974U;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  (*c3_b_info)[8].fileTimeHi = 0U;
  (*c3_b_info)[8].mFileTimeLo = 0U;
  (*c3_b_info)[8].mFileTimeHi = 0U;
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 9), FALSE);
  for (c3_i32 = 0; c3_i32 < 9; c3_i32++) {
    c3_r0 = &c3_info[c3_i32];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i32);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i32);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i32);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i32);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i32);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i32);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i32);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i32);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_eml_scalar_eg(SFc3_lab2_next_levelInstanceStruct *chartInstance)
{
}

static void c3_d_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_rotationMatrix, const char_T *c3_identifier,
  real_T c3_y[9])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_rotationMatrix), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_rotationMatrix);
}

static void c3_e_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[9])
{
  real_T c3_dv2[9];
  int32_T c3_i33;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv2, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c3_i33 = 0; c3_i33 < 9; c3_i33++) {
    c3_y[c3_i33] = c3_dv2[c3_i33];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc3_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_f_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i34;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i34, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i34;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc3_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c3_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
<<<<<<< HEAD
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
=======
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_sfEvent), &c3_thisId);
  sf_mex_destroy(&c3_sfEvent);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
<<<<<<< HEAD
  *chartInstance, const mxArray *c3_b_is_active_c3_lab2_next_level, const char_T
=======
  *chartInstance, const mxArray *c3_is_active_c3_lab2_next_level, const char_T
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup
<<<<<<< HEAD
    (c3_b_is_active_c3_lab2_next_level), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_lab2_next_level);
=======
    (c3_is_active_c3_lab2_next_level), &c3_thisId);
  sf_mex_destroy(&c3_is_active_c3_lab2_next_level);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  return c3_y;
}

static uint8_T c3_h_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_lab2_next_levelInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c3_lab2_next_level_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1786295294U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1909421055U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1443661428U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3307325561U);
}

mxArray *sf_c3_lab2_next_level_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
<<<<<<< HEAD
    mxArray *mxChecksum = mxCreateString("WPpaiSKfiARUZrtKyOnfyF");
=======
    mxArray *mxChecksum = mxCreateString("WN7Y08Cew1uRTKAttGwzpG");
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

static const mxArray *sf_get_sim_state_info_c3_lab2_next_level(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[10],T\"xs\",},{M[1],M[11],T\"ys\",},{M[1],M[12],T\"zs\",},{M[8],M[0],T\"is_active_c3_lab2_next_level\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_lab2_next_level_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_lab2_next_levelInstanceStruct *chartInstance;
    chartInstance = (SFc3_lab2_next_levelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_lab2_next_levelMachineNumber_,
           3,
           1,
           1,
           5,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"angles");
          _SFD_SET_DATA_PROPS(1,1,1,0,"accel");
          _SFD_SET_DATA_PROPS(2,2,0,1,"xs");
          _SFD_SET_DATA_PROPS(3,2,0,1,"ys");
          _SFD_SET_DATA_PROPS(4,2,0,1,"zs");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,352);
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
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          real_T *c3_xs;
          real_T *c3_ys;
          real_T *c3_zs;
          real_T (*c3_angles)[3];
          real_T (*c3_accel)[3];
          c3_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c3_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_accel = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c3_angles = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c3_angles);
          _SFD_SET_DATA_VALUE_PTR(1U, *c3_accel);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_xs);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_ys);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_zs);
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
  return "rjGLt8apbbdIPjqgtOa4OF";
<<<<<<< HEAD
=======
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 3, "dworkChecksum");
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

static void sf_opaque_initialize_c3_lab2_next_level(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc3_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc3_lab2_next_levelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_lab2_next_level((SFc3_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
  initialize_c3_lab2_next_level((SFc3_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_lab2_next_level(void *chartInstanceVar)
{
  enable_c3_lab2_next_level((SFc3_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_lab2_next_level(void *chartInstanceVar)
{
  disable_c3_lab2_next_level((SFc3_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_lab2_next_level(void *chartInstanceVar)
{
  sf_c3_lab2_next_level((SFc3_lab2_next_levelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c3_lab2_next_level(void *chartInstanceVar)
{
  ext_mode_exec_c3_lab2_next_level((SFc3_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_lab2_next_level(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_lab2_next_level
    ((SFc3_lab2_next_levelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_lab2_next_level();/* state var info */
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

extern void sf_internal_set_sim_state_c3_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_lab2_next_level();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_lab2_next_level((SFc3_lab2_next_levelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_lab2_next_level(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_lab2_next_level(S);
}

static void sf_opaque_set_sim_state_c3_lab2_next_level(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c3_lab2_next_level(S, st);
}

static void sf_opaque_terminate_c3_lab2_next_level(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_lab2_next_levelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_lab2_next_level((SFc3_lab2_next_levelInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_lab2_next_level_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_lab2_next_level((SFc3_lab2_next_levelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_lab2_next_level(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_lab2_next_level((SFc3_lab2_next_levelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c3_lab2_next_level_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c3_lab2_next_level\",T\"is_active_c3_lab2_next_level\"}}"
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

static void mdlSetWorkWidths_c3_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lab2_next_level_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,3);
<<<<<<< HEAD
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
=======
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
<<<<<<< HEAD
  ssSetChecksum0(S,(820876594U));
  ssSetChecksum1(S,(3730698488U));
  ssSetChecksum2(S,(697994663U));
  ssSetChecksum3(S,(1469188737U));
=======
  ssSetChecksum0(S,(2293832894U));
  ssSetChecksum1(S,(3071480954U));
  ssSetChecksum2(S,(105403781U));
  ssSetChecksum3(S,(2976814619U));
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_lab2_next_level(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_lab2_next_level(SimStruct *S)
{
  SFc3_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc3_lab2_next_levelInstanceStruct *)malloc(sizeof
    (SFc3_lab2_next_levelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_lab2_next_levelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_lab2_next_level;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_lab2_next_level;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_lab2_next_level;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_lab2_next_level;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_lab2_next_level;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_lab2_next_level;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_lab2_next_level;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_lab2_next_level;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_lab2_next_level;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_lab2_next_level;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_lab2_next_level;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c3_lab2_next_level;
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

void c3_lab2_next_level_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_lab2_next_level(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_lab2_next_level(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_lab2_next_level(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_lab2_next_level_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
