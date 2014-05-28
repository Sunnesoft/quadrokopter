#ifndef __c24_lab2_next_level_h__
#define __c24_lab2_next_level_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c24_ResolvedFunctionInfo
#define typedef_c24_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c24_ResolvedFunctionInfo;

#endif                                 /*typedef_c24_ResolvedFunctionInfo*/

#ifndef typedef_SFc24_lab2_next_levelInstanceStruct
#define typedef_SFc24_lab2_next_levelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
<<<<<<< HEAD
  int32_T c24_sfEvent;
  boolean_T c24_isStable;
  boolean_T c24_doneDoubleBufferReInit;
  uint8_T c24_is_active_c24_lab2_next_level;
=======
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
} SFc24_lab2_next_levelInstanceStruct;

#endif                                 /*typedef_SFc24_lab2_next_levelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c24_lab2_next_level_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c24_lab2_next_level_get_check_sum(mxArray *plhs[]);
extern void c24_lab2_next_level_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
