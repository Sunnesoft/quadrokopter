#ifndef __c23_lab2_next_level_h__
#define __c23_lab2_next_level_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c23_ResolvedFunctionInfo
#define typedef_c23_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c23_ResolvedFunctionInfo;

#endif                                 /*typedef_c23_ResolvedFunctionInfo*/

#ifndef typedef_SFc23_lab2_next_levelInstanceStruct
#define typedef_SFc23_lab2_next_levelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
<<<<<<< HEAD
  int32_T c23_sfEvent;
  boolean_T c23_isStable;
  boolean_T c23_doneDoubleBufferReInit;
  uint8_T c23_is_active_c23_lab2_next_level;
=======
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
} SFc23_lab2_next_levelInstanceStruct;

#endif                                 /*typedef_SFc23_lab2_next_levelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c23_lab2_next_level_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c23_lab2_next_level_get_check_sum(mxArray *plhs[]);
extern void c23_lab2_next_level_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
