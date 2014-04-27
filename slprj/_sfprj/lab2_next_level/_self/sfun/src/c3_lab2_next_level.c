/* Include files */

#include <stddef.h>
#include "blas.h"
#include "lab2_next_level_sfun.h"
#include "c3_lab2_next_level.h"
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
static const char * c3_debug_family_names[14] = { "tr", "bx", "ax", "nargin",
  "nargout", "roll", "pitch", "yaw", "x", "y", "z", "xs", "ys", "zs" };

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
static void registerMessagesc3_lab2_next_level
  (SFc3_lab2_next_levelInstanceStruct *chartInstance);
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
static void c3_d_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[9]);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[13]);
static void c3_eml_scalar_eg(SFc3_lab2_next_levelInstanceStruct *chartInstance);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_e_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_f_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_lab2_next_level, const char_T
  *c3_identifier);
static uint8_T c3_g_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_lab2_next_levelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_lab2_next_level = 0U;
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
  c3_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
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
  c3_d_hoistedGlobal = chartInstance->c3_is_active_c3_lab2_next_level;
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
  real_T *c3_xs;
  real_T *c3_ys;
  real_T *c3_zs;
  c3_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_xs = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
    "xs");
  *c3_ys = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
    "ys");
  *c3_zs = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
    "zs");
  chartInstance->c3_is_active_c3_lab2_next_level = c3_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)),
     "is_active_c3_lab2_next_level");
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
  real_T *c3_roll;
  real_T *c3_pitch;
  real_T *c3_yaw;
  real_T *c3_x;
  real_T *c3_y;
  real_T *c3_z;
  real_T *c3_xs;
  real_T *c3_ys;
  real_T *c3_zs;
  c3_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_roll = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_roll, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_pitch, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_yaw, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_x, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_y, 4U);
  _SFD_DATA_RANGE_CHECK(*c3_z, 5U);
  _SFD_DATA_RANGE_CHECK(*c3_xs, 6U);
  _SFD_DATA_RANGE_CHECK(*c3_ys, 7U);
  _SFD_DATA_RANGE_CHECK(*c3_zs, 8U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_lab2_next_level(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lab2_next_levelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct
  *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_e_hoistedGlobal;
  real_T c3_f_hoistedGlobal;
  real_T c3_roll;
  real_T c3_pitch;
  real_T c3_yaw;
  real_T c3_x;
  real_T c3_y;
  real_T c3_z;
  uint32_T c3_debug_family_var_map[14];
  real_T c3_tr[9];
  real_T c3_bx[3];
  real_T c3_ax[3];
  real_T c3_nargin = 6.0;
  real_T c3_nargout = 3.0;
  real_T c3_xs;
  real_T c3_ys;
  real_T c3_zs;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_a;
  real_T c3_b;
  real_T c3_b_y;
  real_T c3_f_x;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_i_x;
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_c_y;
  real_T c3_j_x;
  real_T c3_k_x;
  real_T c3_c_a;
  real_T c3_c_b;
  real_T c3_d_y;
  real_T c3_l_x;
  real_T c3_m_x;
  real_T c3_n_x;
  real_T c3_o_x;
  real_T c3_d_a;
  real_T c3_d_b;
  real_T c3_e_y;
  real_T c3_p_x;
  real_T c3_q_x;
  real_T c3_r_x;
  real_T c3_s_x;
  real_T c3_e_a;
  real_T c3_e_b;
  real_T c3_f_y;
  real_T c3_t_x;
  real_T c3_u_x;
  real_T c3_f_a;
  real_T c3_f_b;
  real_T c3_g_y;
  real_T c3_v_x;
  real_T c3_w_x;
  real_T c3_x_x;
  real_T c3_y_x;
  real_T c3_g_a;
  real_T c3_g_b;
  real_T c3_h_y;
  real_T c3_ab_x;
  real_T c3_bb_x;
  real_T c3_cb_x;
  real_T c3_db_x;
  real_T c3_eb_x;
  real_T c3_fb_x;
  real_T c3_h_a;
  real_T c3_h_b;
  real_T c3_i_y;
  real_T c3_gb_x;
  real_T c3_hb_x;
  real_T c3_ib_x;
  real_T c3_jb_x;
  real_T c3_i_a;
  real_T c3_i_b;
  real_T c3_j_y;
  real_T c3_kb_x;
  real_T c3_lb_x;
  real_T c3_mb_x;
  real_T c3_nb_x;
  real_T c3_j_a;
  real_T c3_j_b;
  real_T c3_k_y;
  real_T c3_ob_x;
  real_T c3_pb_x;
  real_T c3_qb_x;
  real_T c3_rb_x;
  real_T c3_k_a;
  real_T c3_k_b;
  real_T c3_l_y;
  real_T c3_sb_x;
  real_T c3_tb_x;
  real_T c3_l_a;
  real_T c3_l_b;
  real_T c3_m_y;
  real_T c3_ub_x;
  real_T c3_vb_x;
  real_T c3_wb_x;
  real_T c3_xb_x;
  real_T c3_m_a;
  real_T c3_m_b;
  real_T c3_n_y;
  real_T c3_yb_x;
  real_T c3_ac_x;
  real_T c3_bc_x;
  real_T c3_cc_x;
  real_T c3_n_a;
  real_T c3_n_b;
  real_T c3_o_y;
  real_T c3_dc_x;
  real_T c3_ec_x;
  real_T c3_o_a;
  real_T c3_o_b;
  real_T c3_p_y;
  real_T c3_fc_x;
  real_T c3_gc_x;
  real_T c3_hc_x;
  real_T c3_ic_x;
  real_T c3_p_a;
  real_T c3_p_b;
  real_T c3_q_y;
  int32_T c3_i0;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  real_T c3_q_a[9];
  int32_T c3_i4;
  real_T c3_q_b[3];
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  real_T c3_C[3];
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i13;
  real_T *c3_b_roll;
  real_T *c3_b_pitch;
  real_T *c3_b_yaw;
  real_T *c3_jc_x;
  real_T *c3_r_y;
  real_T *c3_b_z;
  real_T *c3_b_xs;
  real_T *c3_b_ys;
  real_T *c3_b_zs;
  c3_b_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_b_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_r_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_jc_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_b_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_roll = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_b_roll;
  c3_b_hoistedGlobal = *c3_b_pitch;
  c3_c_hoistedGlobal = *c3_b_yaw;
  c3_d_hoistedGlobal = *c3_jc_x;
  c3_e_hoistedGlobal = *c3_r_y;
  c3_f_hoistedGlobal = *c3_b_z;
  c3_roll = c3_hoistedGlobal;
  c3_pitch = c3_b_hoistedGlobal;
  c3_yaw = c3_c_hoistedGlobal;
  c3_x = c3_d_hoistedGlobal;
  c3_y = c3_e_hoistedGlobal;
  c3_z = c3_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tr, 0U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_bx, 1U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_ax, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 4U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_roll, 5U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_pitch, 6U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_yaw, 7U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_x, 8U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_y, 9U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_z, 10U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_xs, 11U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_ys, 12U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_zs, 13U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_b_x = c3_pitch;
  c3_c_x = c3_b_x;
  c3_c_x = muDoubleScalarCos(c3_c_x);
  c3_d_x = c3_yaw;
  c3_e_x = c3_d_x;
  c3_e_x = muDoubleScalarCos(c3_e_x);
  c3_a = c3_c_x;
  c3_b = c3_e_x;
  c3_b_y = c3_a * c3_b;
  c3_f_x = c3_roll;
  c3_g_x = c3_f_x;
  c3_g_x = muDoubleScalarCos(c3_g_x);
  c3_h_x = c3_pitch;
  c3_i_x = c3_h_x;
  c3_i_x = muDoubleScalarSin(c3_i_x);
  c3_b_a = -c3_g_x;
  c3_b_b = c3_i_x;
  c3_c_y = c3_b_a * c3_b_b;
  c3_j_x = c3_yaw;
  c3_k_x = c3_j_x;
  c3_k_x = muDoubleScalarCos(c3_k_x);
  c3_c_a = c3_c_y;
  c3_c_b = c3_k_x;
  c3_d_y = c3_c_a * c3_c_b;
  c3_l_x = c3_roll;
  c3_m_x = c3_l_x;
  c3_m_x = muDoubleScalarSin(c3_m_x);
  c3_n_x = c3_yaw;
  c3_o_x = c3_n_x;
  c3_o_x = muDoubleScalarSin(c3_o_x);
  c3_d_a = c3_m_x;
  c3_d_b = c3_o_x;
  c3_e_y = c3_d_a * c3_d_b;
  c3_p_x = c3_roll;
  c3_q_x = c3_p_x;
  c3_q_x = muDoubleScalarSin(c3_q_x);
  c3_r_x = c3_pitch;
  c3_s_x = c3_r_x;
  c3_s_x = muDoubleScalarSin(c3_s_x);
  c3_e_a = c3_q_x;
  c3_e_b = c3_s_x;
  c3_f_y = c3_e_a * c3_e_b;
  c3_t_x = c3_yaw;
  c3_u_x = c3_t_x;
  c3_u_x = muDoubleScalarCos(c3_u_x);
  c3_f_a = c3_f_y;
  c3_f_b = c3_u_x;
  c3_g_y = c3_f_a * c3_f_b;
  c3_v_x = c3_roll;
  c3_w_x = c3_v_x;
  c3_w_x = muDoubleScalarCos(c3_w_x);
  c3_x_x = c3_yaw;
  c3_y_x = c3_x_x;
  c3_y_x = muDoubleScalarSin(c3_y_x);
  c3_g_a = c3_w_x;
  c3_g_b = c3_y_x;
  c3_h_y = c3_g_a * c3_g_b;
  c3_ab_x = c3_pitch;
  c3_bb_x = c3_ab_x;
  c3_bb_x = muDoubleScalarSin(c3_bb_x);
  c3_cb_x = c3_roll;
  c3_db_x = c3_cb_x;
  c3_db_x = muDoubleScalarCos(c3_db_x);
  c3_eb_x = c3_pitch;
  c3_fb_x = c3_eb_x;
  c3_fb_x = muDoubleScalarCos(c3_fb_x);
  c3_h_a = c3_db_x;
  c3_h_b = c3_fb_x;
  c3_i_y = c3_h_a * c3_h_b;
  c3_gb_x = c3_roll;
  c3_hb_x = c3_gb_x;
  c3_hb_x = muDoubleScalarSin(c3_hb_x);
  c3_ib_x = c3_pitch;
  c3_jb_x = c3_ib_x;
  c3_jb_x = muDoubleScalarCos(c3_jb_x);
  c3_i_a = -c3_hb_x;
  c3_i_b = c3_jb_x;
  c3_j_y = c3_i_a * c3_i_b;
  c3_kb_x = c3_pitch;
  c3_lb_x = c3_kb_x;
  c3_lb_x = muDoubleScalarCos(c3_lb_x);
  c3_mb_x = c3_yaw;
  c3_nb_x = c3_mb_x;
  c3_nb_x = muDoubleScalarSin(c3_nb_x);
  c3_j_a = c3_lb_x;
  c3_j_b = c3_nb_x;
  c3_k_y = c3_j_a * c3_j_b;
  c3_ob_x = c3_roll;
  c3_pb_x = c3_ob_x;
  c3_pb_x = muDoubleScalarCos(c3_pb_x);
  c3_qb_x = c3_pitch;
  c3_rb_x = c3_qb_x;
  c3_rb_x = muDoubleScalarSin(c3_rb_x);
  c3_k_a = -c3_pb_x;
  c3_k_b = c3_rb_x;
  c3_l_y = c3_k_a * c3_k_b;
  c3_sb_x = c3_yaw;
  c3_tb_x = c3_sb_x;
  c3_tb_x = muDoubleScalarSin(c3_tb_x);
  c3_l_a = c3_l_y;
  c3_l_b = c3_tb_x;
  c3_m_y = c3_l_a * c3_l_b;
  c3_ub_x = c3_roll;
  c3_vb_x = c3_ub_x;
  c3_vb_x = muDoubleScalarSin(c3_vb_x);
  c3_wb_x = c3_yaw;
  c3_xb_x = c3_wb_x;
  c3_xb_x = muDoubleScalarCos(c3_xb_x);
  c3_m_a = c3_vb_x;
  c3_m_b = c3_xb_x;
  c3_n_y = c3_m_a * c3_m_b;
  c3_yb_x = c3_roll;
  c3_ac_x = c3_yb_x;
  c3_ac_x = muDoubleScalarSin(c3_ac_x);
  c3_bc_x = c3_pitch;
  c3_cc_x = c3_bc_x;
  c3_cc_x = muDoubleScalarSin(c3_cc_x);
  c3_n_a = c3_ac_x;
  c3_n_b = c3_cc_x;
  c3_o_y = c3_n_a * c3_n_b;
  c3_dc_x = c3_yaw;
  c3_ec_x = c3_dc_x;
  c3_ec_x = muDoubleScalarSin(c3_ec_x);
  c3_o_a = c3_o_y;
  c3_o_b = c3_ec_x;
  c3_p_y = c3_o_a * c3_o_b;
  c3_fc_x = c3_roll;
  c3_gc_x = c3_fc_x;
  c3_gc_x = muDoubleScalarCos(c3_gc_x);
  c3_hc_x = c3_yaw;
  c3_ic_x = c3_hc_x;
  c3_ic_x = muDoubleScalarCos(c3_ic_x);
  c3_p_a = c3_gc_x;
  c3_p_b = c3_ic_x;
  c3_q_y = c3_p_a * c3_p_b;
  c3_tr[0] = c3_b_y;
  c3_tr[3] = c3_d_y - c3_e_y;
  c3_tr[6] = c3_g_y - c3_h_y;
  c3_tr[1] = c3_bb_x;
  c3_tr[4] = c3_i_y;
  c3_tr[7] = c3_j_y;
  c3_tr[2] = c3_k_y;
  c3_tr[5] = c3_m_y + c3_n_y;
  c3_tr[8] = c3_p_y + c3_q_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_bx[0] = c3_x;
  c3_bx[1] = c3_y;
  c3_bx[2] = c3_z;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_i0 = 0;
  for (c3_i1 = 0; c3_i1 < 3; c3_i1++) {
    c3_i2 = 0;
    for (c3_i3 = 0; c3_i3 < 3; c3_i3++) {
      c3_q_a[c3_i3 + c3_i0] = c3_tr[c3_i2 + c3_i1];
      c3_i2 += 3;
    }

    c3_i0 += 3;
  }

  for (c3_i4 = 0; c3_i4 < 3; c3_i4++) {
    c3_q_b[c3_i4] = c3_bx[c3_i4];
  }

  c3_eml_scalar_eg(chartInstance);
  c3_eml_scalar_eg(chartInstance);
  for (c3_i5 = 0; c3_i5 < 3; c3_i5++) {
    c3_ax[c3_i5] = 0.0;
  }

  for (c3_i6 = 0; c3_i6 < 3; c3_i6++) {
    c3_ax[c3_i6] = 0.0;
  }

  for (c3_i7 = 0; c3_i7 < 3; c3_i7++) {
    c3_C[c3_i7] = c3_ax[c3_i7];
  }

  for (c3_i8 = 0; c3_i8 < 3; c3_i8++) {
    c3_ax[c3_i8] = c3_C[c3_i8];
  }

  for (c3_i9 = 0; c3_i9 < 3; c3_i9++) {
    c3_C[c3_i9] = c3_ax[c3_i9];
  }

  for (c3_i10 = 0; c3_i10 < 3; c3_i10++) {
    c3_ax[c3_i10] = c3_C[c3_i10];
  }

  for (c3_i11 = 0; c3_i11 < 3; c3_i11++) {
    c3_ax[c3_i11] = 0.0;
    c3_i12 = 0;
    for (c3_i13 = 0; c3_i13 < 3; c3_i13++) {
      c3_ax[c3_i11] += c3_q_a[c3_i12 + c3_i11] * c3_q_b[c3_i13];
      c3_i12 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
  c3_xs = c3_ax[0];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 11);
  c3_ys = c3_ax[1];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 12);
  c3_zs = c3_ax[2];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  *c3_b_xs = c3_xs;
  *c3_b_ys = c3_ys;
  *c3_b_zs = c3_zs;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_lab2_next_level(SFc3_lab2_next_levelInstanceStruct *
  chartInstance)
{
}

static void registerMessagesc3_lab2_next_level
  (SFc3_lab2_next_levelInstanceStruct *chartInstance)
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
  int32_T c3_i14;
  real_T c3_b_inData[3];
  int32_T c3_i15;
  real_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc3_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i14 = 0; c3_i14 < 3; c3_i14++) {
    c3_b_inData[c3_i14] = (*(real_T (*)[3])c3_inData)[c3_i14];
  }

  for (c3_i15 = 0; c3_i15 < 3; c3_i15++) {
    c3_u[c3_i15] = c3_b_inData[c3_i15];
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
  real_T c3_dv0[3];
  int32_T c3_i16;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv0, 1, 0, 0U, 1, 0U, 1, 3);
  for (c3_i16 = 0; c3_i16 < 3; c3_i16++) {
    c3_y[c3_i16] = c3_dv0[c3_i16];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_ax;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[3];
  int32_T c3_i17;
  SFc3_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc3_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c3_ax = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_ax), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_ax);
  for (c3_i17 = 0; c3_i17 < 3; c3_i17++) {
    (*(real_T (*)[3])c3_outData)[c3_i17] = c3_y[c3_i17];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i20;
  real_T c3_b_inData[9];
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  real_T c3_u[9];
  const mxArray *c3_y = NULL;
  SFc3_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc3_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i18 = 0;
  for (c3_i19 = 0; c3_i19 < 3; c3_i19++) {
    for (c3_i20 = 0; c3_i20 < 3; c3_i20++) {
      c3_b_inData[c3_i20 + c3_i18] = (*(real_T (*)[9])c3_inData)[c3_i20 + c3_i18];
    }

    c3_i18 += 3;
  }

  c3_i21 = 0;
  for (c3_i22 = 0; c3_i22 < 3; c3_i22++) {
    for (c3_i23 = 0; c3_i23 < 3; c3_i23++) {
      c3_u[c3_i23 + c3_i21] = c3_b_inData[c3_i23 + c3_i21];
    }

    c3_i21 += 3;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_d_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[9])
{
  real_T c3_dv1[9];
  int32_T c3_i24;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv1, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c3_i24 = 0; c3_i24 < 9; c3_i24++) {
    c3_y[c3_i24] = c3_dv1[c3_i24];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_tr;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[9];
  int32_T c3_i25;
  int32_T c3_i26;
  int32_T c3_i27;
  SFc3_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc3_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c3_tr = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_tr), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_tr);
  c3_i25 = 0;
  for (c3_i26 = 0; c3_i26 < 3; c3_i26++) {
    for (c3_i27 = 0; c3_i27 < 3; c3_i27++) {
      (*(real_T (*)[9])c3_outData)[c3_i27 + c3_i25] = c3_y[c3_i27 + c3_i25];
    }

    c3_i25 += 3;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_lab2_next_level_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[13];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i28;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 13), FALSE);
  for (c3_i28 = 0; c3_i28 < 13; c3_i28++) {
    c3_r0 = &c3_info[c3_i28];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i28);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i28);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i28);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i28);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i28);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i28);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i28);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i28);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[13])
{
  c3_info[0].context = "";
  c3_info[0].name = "cos";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[0].fileTimeLo = 1343823172U;
  c3_info[0].fileTimeHi = 0U;
  c3_info[0].mFileTimeLo = 0U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[1].name = "eml_scalar_cos";
  c3_info[1].dominantType = "double";
  c3_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c3_info[1].fileTimeLo = 1286811522U;
  c3_info[1].fileTimeHi = 0U;
  c3_info[1].mFileTimeLo = 0U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context = "";
  c3_info[2].name = "mtimes";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[2].fileTimeLo = 1289512492U;
  c3_info[2].fileTimeHi = 0U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context = "";
  c3_info[3].name = "sin";
  c3_info[3].dominantType = "double";
  c3_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[3].fileTimeLo = 1343823186U;
  c3_info[3].fileTimeHi = 0U;
  c3_info[3].mFileTimeLo = 0U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[4].name = "eml_scalar_sin";
  c3_info[4].dominantType = "double";
  c3_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c3_info[4].fileTimeLo = 1286811536U;
  c3_info[4].fileTimeHi = 0U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[5].name = "eml_index_class";
  c3_info[5].dominantType = "";
  c3_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[5].fileTimeLo = 1323163378U;
  c3_info[5].fileTimeHi = 0U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[6].name = "eml_scalar_eg";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[6].fileTimeLo = 1286811596U;
  c3_info[6].fileTimeHi = 0U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[7].name = "eml_xgemm";
  c3_info[7].dominantType = "char";
  c3_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c3_info[7].fileTimeLo = 1299069572U;
  c3_info[7].fileTimeHi = 0U;
  c3_info[7].mFileTimeLo = 0U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c3_info[8].name = "eml_blas_inline";
  c3_info[8].dominantType = "";
  c3_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[8].fileTimeLo = 1299069568U;
  c3_info[8].fileTimeHi = 0U;
  c3_info[8].mFileTimeLo = 0U;
  c3_info[8].mFileTimeHi = 0U;
  c3_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c3_info[9].name = "mtimes";
  c3_info[9].dominantType = "double";
  c3_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[9].fileTimeLo = 1289512492U;
  c3_info[9].fileTimeHi = 0U;
  c3_info[9].mFileTimeLo = 0U;
  c3_info[9].mFileTimeHi = 0U;
  c3_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[10].name = "eml_index_class";
  c3_info[10].dominantType = "";
  c3_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[10].fileTimeLo = 1323163378U;
  c3_info[10].fileTimeHi = 0U;
  c3_info[10].mFileTimeLo = 0U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[11].name = "eml_scalar_eg";
  c3_info[11].dominantType = "double";
  c3_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[11].fileTimeLo = 1286811596U;
  c3_info[11].fileTimeHi = 0U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[12].name = "eml_refblas_xgemm";
  c3_info[12].dominantType = "char";
  c3_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c3_info[12].fileTimeLo = 1299069574U;
  c3_info[12].fileTimeHi = 0U;
  c3_info[12].mFileTimeLo = 0U;
  c3_info[12].mFileTimeHi = 0U;
}

static void c3_eml_scalar_eg(SFc3_lab2_next_levelInstanceStruct *chartInstance)
{
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

static int32_T c3_e_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i29;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i29, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i29;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_lab2_next_levelInstanceStruct *chartInstance;
  chartInstance = (SFc3_lab2_next_levelInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_lab2_next_level, const char_T
  *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_lab2_next_level), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_lab2_next_level);
  return c3_y;
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_lab2_next_levelInstanceStruct
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

void sf_c3_lab2_next_level_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4247066756U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3006131345U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(966386036U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2777620536U);
}

mxArray *sf_c3_lab2_next_level_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("6L2Lu3f77ZJVNKYSJqa1oB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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

mxArray *sf_c3_lab2_next_level_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
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
          (sfGlobalDebugInstanceStruct,
           _lab2_next_levelMachineNumber_,
           3,
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
            (sfGlobalDebugInstanceStruct,_lab2_next_levelMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _lab2_next_levelMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"roll");
          _SFD_SET_DATA_PROPS(1,1,1,0,"pitch");
          _SFD_SET_DATA_PROPS(2,1,1,0,"yaw");
          _SFD_SET_DATA_PROPS(3,1,1,0,"x");
          _SFD_SET_DATA_PROPS(4,1,1,0,"y");
          _SFD_SET_DATA_PROPS(5,1,1,0,"z");
          _SFD_SET_DATA_PROPS(6,2,0,1,"xs");
          _SFD_SET_DATA_PROPS(7,2,0,1,"ys");
          _SFD_SET_DATA_PROPS(8,2,0,1,"zs");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,505);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          real_T *c3_roll;
          real_T *c3_pitch;
          real_T *c3_yaw;
          real_T *c3_x;
          real_T *c3_y;
          real_T *c3_z;
          real_T *c3_xs;
          real_T *c3_ys;
          real_T *c3_zs;
          c3_zs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c3_ys = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_xs = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c3_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c3_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_roll = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_roll);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_pitch);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_yaw);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_x);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_y);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_z);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_xs);
          _SFD_SET_DATA_VALUE_PTR(7U, c3_ys);
          _SFD_SET_DATA_VALUE_PTR(8U, c3_zs);
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
  return "rWFRKbERwfDZOgznlYi3cE";
}

static void sf_opaque_initialize_c3_lab2_next_level(void *chartInstanceVar)
{
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
      unload_lab2_next_level_optimization_info();
    }

    finalize_c3_lab2_next_level((SFc3_lab2_next_levelInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
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
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1596694328U));
  ssSetChecksum1(S,(3679896997U));
  ssSetChecksum2(S,(4130215834U));
  ssSetChecksum3(S,(1577412146U));
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
  chartInstance = (SFc3_lab2_next_levelInstanceStruct *)utMalloc(sizeof
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
