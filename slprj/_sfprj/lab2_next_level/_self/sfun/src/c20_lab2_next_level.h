#ifndef __c20_lab2_next_level_h__
#define __c20_lab2_next_level_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c20_ResolvedFunctionInfo
#define typedef_c20_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c20_ResolvedFunctionInfo;

#endif                                 /*typedef_c20_ResolvedFunctionInfo*/

#ifndef typedef_SFc20_lab2_next_levelInstanceStruct
#define typedef_SFc20_lab2_next_levelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c20_sfEvent;
  boolean_T c20_isStable;
  boolean_T c20_doneDoubleBufferReInit;
  uint8_T c20_is_active_c20_lab2_next_level;
} SFc20_lab2_next_levelInstanceStruct;

#endif                                 /*typedef_SFc20_lab2_next_levelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c20_lab2_next_level_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c20_lab2_next_level_get_check_sum(mxArray *plhs[]);
extern void c20_lab2_next_level_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
