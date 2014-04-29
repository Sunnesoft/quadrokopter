/* Include files */

#include <stddef.h>
#include "blas.h"
#include "lab2_points_sfun.h"
#include "c1_lab2_points.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lab2_points_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[21] = { "roll", "pitch", "yaw", "C_x",
  "C_y", "C_z", "C", "proectP", "P_sum", "k_x", "k_y", "k_z", "m", "g", "nargin",
  "nargout", "P", "angles", "a_x", "a_y", "a_z" };

/* Function Declarations */
static void initialize_c1_lab2_points(SFc1_lab2_pointsInstanceStruct
  *chartInstance);
static void initialize_params_c1_lab2_points(SFc1_lab2_pointsInstanceStruct
  *chartInstance);
static void enable_c1_lab2_points(SFc1_lab2_pointsInstanceStruct *chartInstance);
static void disable_c1_lab2_points(SFc1_lab2_pointsInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_lab2_points
  (SFc1_lab2_pointsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_lab2_points
  (SFc1_lab2_pointsInstanceStruct *chartInstance);
static void set_sim_state_c1_lab2_points(SFc1_lab2_pointsInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_lab2_points(SFc1_lab2_pointsInstanceStruct
  *chartInstance);
static void sf_c1_lab2_points(SFc1_lab2_pointsInstanceStruct *chartInstance);
static void c1_chartstep_c1_lab2_points(SFc1_lab2_pointsInstanceStruct
  *chartInstance);
static void initSimStructsc1_lab2_points(SFc1_lab2_pointsInstanceStruct
  *chartInstance);
static void registerMessagesc1_lab2_points(SFc1_lab2_pointsInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_lab2_pointsInstanceStruct *chartInstance,
  const mxArray *c1_a_z, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_lab2_pointsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_lab2_pointsInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_d_emlrt_marshallIn(SFc1_lab2_pointsInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[9]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[25]);
static void c1_eml_scalar_eg(SFc1_lab2_pointsInstanceStruct *chartInstance);
static void c1_b_eml_scalar_eg(SFc1_lab2_pointsInstanceStruct *chartInstance);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_e_emlrt_marshallIn(SFc1_lab2_pointsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_f_emlrt_marshallIn(SFc1_lab2_pointsInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_lab2_points, const char_T
  *c1_identifier);
static uint8_T c1_g_emlrt_marshallIn(SFc1_lab2_pointsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_lab2_pointsInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_lab2_points(SFc1_lab2_pointsInstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_lab2_points = 0U;
}

static void initialize_params_c1_lab2_points(SFc1_lab2_pointsInstanceStruct
  *chartInstance)
{
}

static void enable_c1_lab2_points(SFc1_lab2_pointsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_lab2_points(SFc1_lab2_pointsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_lab2_points
  (SFc1_lab2_pointsInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_lab2_points
  (SFc1_lab2_pointsInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  uint8_T c1_d_hoistedGlobal;
  uint8_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  real_T *c1_a_x;
  real_T *c1_a_y;
  real_T *c1_a_z;
  c1_a_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_a_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_a_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(4), FALSE);
  c1_hoistedGlobal = *c1_a_x;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_a_y;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *c1_a_z;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = chartInstance->c1_is_active_c1_lab2_points;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_lab2_points(SFc1_lab2_pointsInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_a_x;
  real_T *c1_a_y;
  real_T *c1_a_z;
  c1_a_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_a_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_a_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_a_x = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
    "a_x");
  *c1_a_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "a_y");
  *c1_a_z = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
    "a_z");
  chartInstance->c1_is_active_c1_lab2_points = c1_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
     "is_active_c1_lab2_points");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_lab2_points(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_lab2_points(SFc1_lab2_pointsInstanceStruct
  *chartInstance)
{
}

static void sf_c1_lab2_points(SFc1_lab2_pointsInstanceStruct *chartInstance)
{
  int32_T c1_i0;
  int32_T c1_i1;
  real_T *c1_a_x;
  real_T *c1_a_y;
  real_T *c1_a_z;
  real_T (*c1_angles)[3];
  real_T (*c1_P)[4];
  c1_a_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_a_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_angles = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c1_a_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_P = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i0 = 0; c1_i0 < 4; c1_i0++) {
    _SFD_DATA_RANGE_CHECK((*c1_P)[c1_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_a_x, 1U);
  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    _SFD_DATA_RANGE_CHECK((*c1_angles)[c1_i1], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_a_y, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_a_z, 4U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_lab2_points(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lab2_pointsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_lab2_points(SFc1_lab2_pointsInstanceStruct
  *chartInstance)
{
  int32_T c1_i2;
  real_T c1_P[4];
  int32_T c1_i3;
  real_T c1_angles[3];
  uint32_T c1_debug_family_var_map[21];
  real_T c1_roll;
  real_T c1_pitch;
  real_T c1_yaw;
  real_T c1_C_x[9];
  real_T c1_C_y[9];
  real_T c1_C_z[9];
  real_T c1_C[9];
  real_T c1_proectP[3];
  real_T c1_P_sum;
  real_T c1_k_x;
  real_T c1_k_y;
  real_T c1_k_z;
  real_T c1_m;
  real_T c1_g;
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 3.0;
  real_T c1_a_x;
  real_T c1_a_y;
  real_T c1_a_z;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  int32_T c1_i4;
  int32_T c1_i5;
  static real_T c1_dv0[3] = { 1.0, 0.0, 0.0 };

  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_l_x;
  real_T c1_m_x;
  real_T c1_n_x;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_q_x;
  int32_T c1_i6;
  int32_T c1_i7;
  static real_T c1_dv1[3] = { 0.0, 1.0, 0.0 };

  real_T c1_r_x;
  real_T c1_s_x;
  real_T c1_t_x;
  real_T c1_u_x;
  real_T c1_v_x;
  real_T c1_w_x;
  real_T c1_x_x;
  real_T c1_y_x;
  int32_T c1_i8;
  int32_T c1_i9;
  static real_T c1_dv2[3] = { 0.0, 0.0, 1.0 };

  int32_T c1_i10;
  real_T c1_a[9];
  int32_T c1_i11;
  real_T c1_b[9];
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  real_T c1_y[9];
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  real_T c1_b_C[3];
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  static real_T c1_b_b[3] = { 0.0, 0.0, 1.0 };

  int32_T c1_i39;
  real_T c1_ab_x[4];
  int32_T c1_k;
  int32_T c1_b_k;
  real_T c1_b_a;
  real_T c1_c_b;
  real_T c1_b_y;
  real_T c1_c_a;
  real_T c1_c_y;
  real_T c1_A;
  real_T c1_bb_x;
  real_T c1_cb_x;
  real_T c1_d_a;
  real_T c1_d_b;
  real_T c1_d_y;
  real_T c1_e_a;
  real_T c1_e_y;
  real_T c1_b_A;
  real_T c1_db_x;
  real_T c1_eb_x;
  real_T c1_f_a;
  real_T c1_e_b;
  real_T c1_f_y;
  real_T c1_g_a;
  real_T c1_g_y;
  real_T c1_c_A;
  real_T c1_fb_x;
  real_T c1_gb_x;
  real_T c1_h_y;
  real_T *c1_b_a_x;
  real_T *c1_b_a_y;
  real_T *c1_b_a_z;
  real_T (*c1_b_angles)[3];
  real_T (*c1_b_P)[4];
  c1_b_a_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_a_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_angles = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_a_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_P = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i2 = 0; c1_i2 < 4; c1_i2++) {
    c1_P[c1_i2] = (*c1_b_P)[c1_i2];
  }

  for (c1_i3 = 0; c1_i3 < 3; c1_i3++) {
    c1_angles[c1_i3] = (*c1_b_angles)[c1_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 21U, 21U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_roll, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_pitch, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_yaw, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_C_x, 3U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_C_y, 4U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_C_z, 5U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_C, 6U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_proectP, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_P_sum, 8U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_k_x, 9U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_k_y, 10U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_k_z, 11U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_m, 12U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g, 13U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 14U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 15U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_P, 16U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_angles, 17U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_a_x, 18U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_a_y, 19U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_a_z, 20U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_roll = c1_angles[0];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_pitch = c1_angles[1];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_yaw = c1_angles[2];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_x = c1_roll;
  c1_b_x = c1_x;
  c1_b_x = muDoubleScalarCos(c1_b_x);
  c1_c_x = c1_roll;
  c1_d_x = c1_c_x;
  c1_d_x = muDoubleScalarSin(c1_d_x);
  c1_e_x = c1_roll;
  c1_f_x = c1_e_x;
  c1_f_x = muDoubleScalarSin(c1_f_x);
  c1_g_x = c1_roll;
  c1_h_x = c1_g_x;
  c1_h_x = muDoubleScalarCos(c1_h_x);
  c1_i4 = 0;
  for (c1_i5 = 0; c1_i5 < 3; c1_i5++) {
    c1_C_x[c1_i4] = c1_dv0[c1_i5];
    c1_i4 += 3;
  }

  c1_C_x[1] = 0.0;
  c1_C_x[4] = c1_b_x;
  c1_C_x[7] = c1_d_x;
  c1_C_x[2] = 0.0;
  c1_C_x[5] = -c1_f_x;
  c1_C_x[8] = c1_h_x;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  c1_i_x = c1_pitch;
  c1_j_x = c1_i_x;
  c1_j_x = muDoubleScalarCos(c1_j_x);
  c1_l_x = c1_pitch;
  c1_m_x = c1_l_x;
  c1_m_x = muDoubleScalarSin(c1_m_x);
  c1_n_x = c1_pitch;
  c1_o_x = c1_n_x;
  c1_o_x = muDoubleScalarSin(c1_o_x);
  c1_p_x = c1_pitch;
  c1_q_x = c1_p_x;
  c1_q_x = muDoubleScalarCos(c1_q_x);
  c1_C_y[0] = c1_j_x;
  c1_C_y[3] = 0.0;
  c1_C_y[6] = -c1_m_x;
  c1_i6 = 0;
  for (c1_i7 = 0; c1_i7 < 3; c1_i7++) {
    c1_C_y[c1_i6 + 1] = c1_dv1[c1_i7];
    c1_i6 += 3;
  }

  c1_C_y[2] = c1_o_x;
  c1_C_y[5] = 0.0;
  c1_C_y[8] = c1_q_x;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  c1_r_x = c1_yaw;
  c1_s_x = c1_r_x;
  c1_s_x = muDoubleScalarCos(c1_s_x);
  c1_t_x = c1_yaw;
  c1_u_x = c1_t_x;
  c1_u_x = muDoubleScalarSin(c1_u_x);
  c1_v_x = c1_yaw;
  c1_w_x = c1_v_x;
  c1_w_x = muDoubleScalarSin(c1_w_x);
  c1_x_x = c1_yaw;
  c1_y_x = c1_x_x;
  c1_y_x = muDoubleScalarCos(c1_y_x);
  c1_C_z[0] = c1_s_x;
  c1_C_z[3] = c1_u_x;
  c1_C_z[6] = 0.0;
  c1_C_z[1] = -c1_w_x;
  c1_C_z[4] = c1_y_x;
  c1_C_z[7] = 0.0;
  c1_i8 = 0;
  for (c1_i9 = 0; c1_i9 < 3; c1_i9++) {
    c1_C_z[c1_i8 + 2] = c1_dv2[c1_i9];
    c1_i8 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
  for (c1_i10 = 0; c1_i10 < 9; c1_i10++) {
    c1_a[c1_i10] = c1_C_z[c1_i10];
  }

  for (c1_i11 = 0; c1_i11 < 9; c1_i11++) {
    c1_b[c1_i11] = c1_C_y[c1_i11];
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i12 = 0; c1_i12 < 3; c1_i12++) {
    c1_i13 = 0;
    for (c1_i14 = 0; c1_i14 < 3; c1_i14++) {
      c1_y[c1_i13 + c1_i12] = 0.0;
      c1_i15 = 0;
      for (c1_i16 = 0; c1_i16 < 3; c1_i16++) {
        c1_y[c1_i13 + c1_i12] += c1_a[c1_i15 + c1_i12] * c1_b[c1_i16 + c1_i13];
        c1_i15 += 3;
      }

      c1_i13 += 3;
    }
  }

  for (c1_i17 = 0; c1_i17 < 9; c1_i17++) {
    c1_b[c1_i17] = c1_C_x[c1_i17];
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i18 = 0; c1_i18 < 9; c1_i18++) {
    c1_C[c1_i18] = 0.0;
  }

  for (c1_i19 = 0; c1_i19 < 9; c1_i19++) {
    c1_C[c1_i19] = 0.0;
  }

  for (c1_i20 = 0; c1_i20 < 9; c1_i20++) {
    c1_a[c1_i20] = c1_C[c1_i20];
  }

  for (c1_i21 = 0; c1_i21 < 9; c1_i21++) {
    c1_C[c1_i21] = c1_a[c1_i21];
  }

  for (c1_i22 = 0; c1_i22 < 9; c1_i22++) {
    c1_a[c1_i22] = c1_C[c1_i22];
  }

  for (c1_i23 = 0; c1_i23 < 9; c1_i23++) {
    c1_C[c1_i23] = c1_a[c1_i23];
  }

  for (c1_i24 = 0; c1_i24 < 3; c1_i24++) {
    c1_i25 = 0;
    for (c1_i26 = 0; c1_i26 < 3; c1_i26++) {
      c1_C[c1_i25 + c1_i24] = 0.0;
      c1_i27 = 0;
      for (c1_i28 = 0; c1_i28 < 3; c1_i28++) {
        c1_C[c1_i25 + c1_i24] += c1_y[c1_i27 + c1_i24] * c1_b[c1_i28 + c1_i25];
        c1_i27 += 3;
      }

      c1_i25 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 19);
  for (c1_i29 = 0; c1_i29 < 9; c1_i29++) {
    c1_a[c1_i29] = c1_C[c1_i29];
  }

  c1_b_eml_scalar_eg(chartInstance);
  c1_b_eml_scalar_eg(chartInstance);
  for (c1_i30 = 0; c1_i30 < 3; c1_i30++) {
    c1_proectP[c1_i30] = 0.0;
  }

  for (c1_i31 = 0; c1_i31 < 3; c1_i31++) {
    c1_proectP[c1_i31] = 0.0;
  }

  for (c1_i32 = 0; c1_i32 < 3; c1_i32++) {
    c1_b_C[c1_i32] = c1_proectP[c1_i32];
  }

  for (c1_i33 = 0; c1_i33 < 3; c1_i33++) {
    c1_proectP[c1_i33] = c1_b_C[c1_i33];
  }

  for (c1_i34 = 0; c1_i34 < 3; c1_i34++) {
    c1_b_C[c1_i34] = c1_proectP[c1_i34];
  }

  for (c1_i35 = 0; c1_i35 < 3; c1_i35++) {
    c1_proectP[c1_i35] = c1_b_C[c1_i35];
  }

  for (c1_i36 = 0; c1_i36 < 3; c1_i36++) {
    c1_proectP[c1_i36] = 0.0;
    c1_i37 = 0;
    for (c1_i38 = 0; c1_i38 < 3; c1_i38++) {
      c1_proectP[c1_i36] += c1_a[c1_i37 + c1_i36] * c1_b_b[c1_i38];
      c1_i37 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
  for (c1_i39 = 0; c1_i39 < 4; c1_i39++) {
    c1_ab_x[c1_i39] = c1_P[c1_i39];
  }

  c1_P_sum = c1_ab_x[0];
  for (c1_k = 2; c1_k < 5; c1_k++) {
    c1_b_k = c1_k;
    c1_P_sum += c1_ab_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 4, 1, 0) - 1];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
  c1_k_x = 0.9;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
  c1_k_y = 0.9;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
  c1_k_z = 0.9;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 28);
  c1_m = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 29);
  c1_g = 9.8;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 31);
  c1_b_a = c1_proectP[0];
  c1_c_b = c1_P_sum;
  c1_b_y = c1_b_a * c1_c_b;
  c1_c_a = c1_b_y;
  c1_c_y = c1_c_a * 0.9;
  c1_A = c1_c_y;
  c1_bb_x = c1_A;
  c1_cb_x = c1_bb_x;
  c1_a_x = c1_cb_x / 10.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 33);
  c1_d_a = c1_proectP[1];
  c1_d_b = c1_P_sum;
  c1_d_y = c1_d_a * c1_d_b;
  c1_e_a = c1_d_y;
  c1_e_y = c1_e_a * 0.9;
  c1_b_A = c1_e_y;
  c1_db_x = c1_b_A;
  c1_eb_x = c1_db_x;
  c1_a_y = c1_eb_x / 10.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 35);
  c1_f_a = c1_proectP[2];
  c1_e_b = c1_P_sum;
  c1_f_y = c1_f_a * c1_e_b;
  c1_g_a = c1_f_y;
  c1_g_y = c1_g_a * 0.9;
  c1_c_A = c1_g_y;
  c1_fb_x = c1_c_A;
  c1_gb_x = c1_fb_x;
  c1_h_y = c1_gb_x / 10.0;
  c1_a_z = c1_h_y - c1_g;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -35);
  _SFD_SYMBOL_SCOPE_POP();
  *c1_b_a_x = c1_a_x;
  *c1_b_a_y = c1_a_y;
  *c1_b_a_z = c1_a_z;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_lab2_points(SFc1_lab2_pointsInstanceStruct
  *chartInstance)
{
}

static void registerMessagesc1_lab2_points(SFc1_lab2_pointsInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_lab2_pointsInstanceStruct *chartInstance;
  chartInstance = (SFc1_lab2_pointsInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_lab2_pointsInstanceStruct *chartInstance,
  const mxArray *c1_a_z, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_a_z), &c1_thisId);
  sf_mex_destroy(&c1_a_z);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_lab2_pointsInstanceStruct
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
  const mxArray *c1_a_z;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_lab2_pointsInstanceStruct *chartInstance;
  chartInstance = (SFc1_lab2_pointsInstanceStruct *)chartInstanceVoid;
  c1_a_z = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_a_z), &c1_thisId);
  sf_mex_destroy(&c1_a_z);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i40;
  real_T c1_b_inData[3];
  int32_T c1_i41;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_lab2_pointsInstanceStruct *chartInstance;
  chartInstance = (SFc1_lab2_pointsInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i40 = 0; c1_i40 < 3; c1_i40++) {
    c1_b_inData[c1_i40] = (*(real_T (*)[3])c1_inData)[c1_i40];
  }

  for (c1_i41 = 0; c1_i41 < 3; c1_i41++) {
    c1_u[c1_i41] = c1_b_inData[c1_i41];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i42;
  real_T c1_b_inData[4];
  int32_T c1_i43;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_lab2_pointsInstanceStruct *chartInstance;
  chartInstance = (SFc1_lab2_pointsInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i42 = 0; c1_i42 < 4; c1_i42++) {
    c1_b_inData[c1_i42] = (*(real_T (*)[4])c1_inData)[c1_i42];
  }

  for (c1_i43 = 0; c1_i43 < 4; c1_i43++) {
    c1_u[c1_i43] = c1_b_inData[c1_i43];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_lab2_pointsInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3])
{
  real_T c1_dv3[3];
  int32_T c1_i44;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c1_i44 = 0; c1_i44 < 3; c1_i44++) {
    c1_y[c1_i44] = c1_dv3[c1_i44];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_proectP;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i45;
  SFc1_lab2_pointsInstanceStruct *chartInstance;
  chartInstance = (SFc1_lab2_pointsInstanceStruct *)chartInstanceVoid;
  c1_proectP = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_proectP), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_proectP);
  for (c1_i45 = 0; c1_i45 < 3; c1_i45++) {
    (*(real_T (*)[3])c1_outData)[c1_i45] = c1_y[c1_i45];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  real_T c1_b_inData[9];
  int32_T c1_i49;
  int32_T c1_i50;
  int32_T c1_i51;
  real_T c1_u[9];
  const mxArray *c1_y = NULL;
  SFc1_lab2_pointsInstanceStruct *chartInstance;
  chartInstance = (SFc1_lab2_pointsInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i46 = 0;
  for (c1_i47 = 0; c1_i47 < 3; c1_i47++) {
    for (c1_i48 = 0; c1_i48 < 3; c1_i48++) {
      c1_b_inData[c1_i48 + c1_i46] = (*(real_T (*)[9])c1_inData)[c1_i48 + c1_i46];
    }

    c1_i46 += 3;
  }

  c1_i49 = 0;
  for (c1_i50 = 0; c1_i50 < 3; c1_i50++) {
    for (c1_i51 = 0; c1_i51 < 3; c1_i51++) {
      c1_u[c1_i51 + c1_i49] = c1_b_inData[c1_i51 + c1_i49];
    }

    c1_i49 += 3;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_d_emlrt_marshallIn(SFc1_lab2_pointsInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[9])
{
  real_T c1_dv4[9];
  int32_T c1_i52;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv4, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c1_i52 = 0; c1_i52 < 9; c1_i52++) {
    c1_y[c1_i52] = c1_dv4[c1_i52];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_C;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[9];
  int32_T c1_i53;
  int32_T c1_i54;
  int32_T c1_i55;
  SFc1_lab2_pointsInstanceStruct *chartInstance;
  chartInstance = (SFc1_lab2_pointsInstanceStruct *)chartInstanceVoid;
  c1_C = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_C), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_C);
  c1_i53 = 0;
  for (c1_i54 = 0; c1_i54 < 3; c1_i54++) {
    for (c1_i55 = 0; c1_i55 < 3; c1_i55++) {
      (*(real_T (*)[9])c1_outData)[c1_i55 + c1_i53] = c1_y[c1_i55 + c1_i53];
    }

    c1_i53 += 3;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_lab2_points_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[25];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i56;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 25), FALSE);
  for (c1_i56 = 0; c1_i56 < 25; c1_i56++) {
    c1_r0 = &c1_info[c1_i56];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i56);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i56);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i56);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i56);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i56);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i56);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i56);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i56);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[25])
{
  c1_info[0].context = "";
  c1_info[0].name = "cos";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[0].fileTimeLo = 1343823172U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 0U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[1].name = "eml_scalar_cos";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c1_info[1].fileTimeLo = 1286811522U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context = "";
  c1_info[2].name = "sin";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[2].fileTimeLo = 1343823186U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[3].name = "eml_scalar_sin";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c1_info[3].fileTimeLo = 1286811536U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context = "";
  c1_info[4].name = "mtimes";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[4].fileTimeLo = 1289512492U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[5].name = "eml_index_class";
  c1_info[5].dominantType = "";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[5].fileTimeLo = 1323163378U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[6].name = "eml_scalar_eg";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[6].fileTimeLo = 1286811596U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[7].name = "eml_xgemm";
  c1_info[7].dominantType = "char";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[7].fileTimeLo = 1299069572U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[8].name = "eml_blas_inline";
  c1_info[8].dominantType = "";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[8].fileTimeLo = 1299069568U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c1_info[9].name = "mtimes";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[9].fileTimeLo = 1289512492U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[10].name = "eml_index_class";
  c1_info[10].dominantType = "";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[10].fileTimeLo = 1323163378U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[11].name = "eml_scalar_eg";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[11].fileTimeLo = 1286811596U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[12].name = "eml_refblas_xgemm";
  c1_info[12].dominantType = "char";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[12].fileTimeLo = 1299069574U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context = "";
  c1_info[13].name = "sum";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[13].fileTimeLo = 1314729412U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[14].name = "isequal";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[14].fileTimeLo = 1286811558U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[15].name = "eml_isequal_core";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c1_info[15].fileTimeLo = 1286811586U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 0U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[16].name = "eml_const_nonsingleton_dim";
  c1_info[16].dominantType = "double";
  c1_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c1_info[16].fileTimeLo = 1286811496U;
  c1_info[16].fileTimeHi = 0U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[17].name = "eml_scalar_eg";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[17].fileTimeLo = 1286811596U;
  c1_info[17].fileTimeHi = 0U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
  c1_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[18].name = "eml_index_class";
  c1_info[18].dominantType = "";
  c1_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[18].fileTimeLo = 1323163378U;
  c1_info[18].fileTimeHi = 0U;
  c1_info[18].mFileTimeLo = 0U;
  c1_info[18].mFileTimeHi = 0U;
  c1_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[19].name = "eml_int_forloop_overflow_check";
  c1_info[19].dominantType = "";
  c1_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[19].fileTimeLo = 1346503140U;
  c1_info[19].fileTimeHi = 0U;
  c1_info[19].mFileTimeLo = 0U;
  c1_info[19].mFileTimeHi = 0U;
  c1_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c1_info[20].name = "intmax";
  c1_info[20].dominantType = "char";
  c1_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[20].fileTimeLo = 1311248116U;
  c1_info[20].fileTimeHi = 0U;
  c1_info[20].mFileTimeLo = 0U;
  c1_info[20].mFileTimeHi = 0U;
  c1_info[21].context = "";
  c1_info[21].name = "mrdivide";
  c1_info[21].dominantType = "double";
  c1_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[21].fileTimeLo = 1357944348U;
  c1_info[21].fileTimeHi = 0U;
  c1_info[21].mFileTimeLo = 1319722766U;
  c1_info[21].mFileTimeHi = 0U;
  c1_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[22].name = "rdivide";
  c1_info[22].dominantType = "double";
  c1_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[22].fileTimeLo = 1346503188U;
  c1_info[22].fileTimeHi = 0U;
  c1_info[22].mFileTimeLo = 0U;
  c1_info[22].mFileTimeHi = 0U;
  c1_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[23].name = "eml_scalexp_compatible";
  c1_info[23].dominantType = "double";
  c1_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c1_info[23].fileTimeLo = 1286811596U;
  c1_info[23].fileTimeHi = 0U;
  c1_info[23].mFileTimeLo = 0U;
  c1_info[23].mFileTimeHi = 0U;
  c1_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[24].name = "eml_div";
  c1_info[24].dominantType = "double";
  c1_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[24].fileTimeLo = 1313340610U;
  c1_info[24].fileTimeHi = 0U;
  c1_info[24].mFileTimeLo = 0U;
  c1_info[24].mFileTimeHi = 0U;
}

static void c1_eml_scalar_eg(SFc1_lab2_pointsInstanceStruct *chartInstance)
{
}

static void c1_b_eml_scalar_eg(SFc1_lab2_pointsInstanceStruct *chartInstance)
{
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_lab2_pointsInstanceStruct *chartInstance;
  chartInstance = (SFc1_lab2_pointsInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_e_emlrt_marshallIn(SFc1_lab2_pointsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i57;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i57, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i57;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_lab2_pointsInstanceStruct *chartInstance;
  chartInstance = (SFc1_lab2_pointsInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_lab2_pointsInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_lab2_points, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_lab2_points), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_lab2_points);
  return c1_y;
}

static uint8_T c1_g_emlrt_marshallIn(SFc1_lab2_pointsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_lab2_pointsInstanceStruct *chartInstance)
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

void sf_c1_lab2_points_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3906401006U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2603035138U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1244556827U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1908989229U);
}

mxArray *sf_c1_lab2_points_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("uOrIdcZ5CBwXUysrNfs4IG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

mxArray *sf_c1_lab2_points_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_lab2_points(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"a_x\",},{M[1],M[7],T\"a_y\",},{M[1],M[8],T\"a_z\",},{M[8],M[0],T\"is_active_c1_lab2_points\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_lab2_points_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_lab2_pointsInstanceStruct *chartInstance;
    chartInstance = (SFc1_lab2_pointsInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _lab2_pointsMachineNumber_,
           1,
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
          init_script_number_translation(_lab2_pointsMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_lab2_pointsMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _lab2_pointsMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"P");
          _SFD_SET_DATA_PROPS(1,2,0,1,"a_x");
          _SFD_SET_DATA_PROPS(2,1,1,0,"angles");
          _SFD_SET_DATA_PROPS(3,2,0,1,"a_y");
          _SFD_SET_DATA_PROPS(4,2,0,1,"a_z");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,561);
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
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_a_x;
          real_T *c1_a_y;
          real_T *c1_a_z;
          real_T (*c1_P)[4];
          real_T (*c1_angles)[3];
          c1_a_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_a_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_angles = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c1_a_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_P = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_P);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_a_x);
          _SFD_SET_DATA_VALUE_PTR(2U, *c1_angles);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_a_y);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_a_z);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _lab2_pointsMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "3lCG3IemFv2YmeHAGSK1rF";
}

static void sf_opaque_initialize_c1_lab2_points(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_lab2_pointsInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c1_lab2_points((SFc1_lab2_pointsInstanceStruct*)
    chartInstanceVar);
  initialize_c1_lab2_points((SFc1_lab2_pointsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_lab2_points(void *chartInstanceVar)
{
  enable_c1_lab2_points((SFc1_lab2_pointsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_lab2_points(void *chartInstanceVar)
{
  disable_c1_lab2_points((SFc1_lab2_pointsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_lab2_points(void *chartInstanceVar)
{
  sf_c1_lab2_points((SFc1_lab2_pointsInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_lab2_points(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_lab2_points
    ((SFc1_lab2_pointsInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_lab2_points();/* state var info */
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

extern void sf_internal_set_sim_state_c1_lab2_points(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_lab2_points();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_lab2_points((SFc1_lab2_pointsInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_lab2_points(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_lab2_points(S);
}

static void sf_opaque_set_sim_state_c1_lab2_points(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c1_lab2_points(S, st);
}

static void sf_opaque_terminate_c1_lab2_points(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_lab2_pointsInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_lab2_points_optimization_info();
    }

    finalize_c1_lab2_points((SFc1_lab2_pointsInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_lab2_points((SFc1_lab2_pointsInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_lab2_points(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_lab2_points((SFc1_lab2_pointsInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_lab2_points(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lab2_points_optimization_info();
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
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
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
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2149721426U));
  ssSetChecksum1(S,(2972086978U));
  ssSetChecksum2(S,(2188379296U));
  ssSetChecksum3(S,(3269808832U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_lab2_points(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_lab2_points(SimStruct *S)
{
  SFc1_lab2_pointsInstanceStruct *chartInstance;
  chartInstance = (SFc1_lab2_pointsInstanceStruct *)utMalloc(sizeof
    (SFc1_lab2_pointsInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_lab2_pointsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_lab2_points;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_lab2_points;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_lab2_points;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_lab2_points;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_lab2_points;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_lab2_points;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_lab2_points;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_lab2_points;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_lab2_points;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_lab2_points;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_lab2_points;
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

void c1_lab2_points_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_lab2_points(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_lab2_points(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_lab2_points(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_lab2_points_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
