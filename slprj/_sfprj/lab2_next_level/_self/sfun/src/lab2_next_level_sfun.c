/* Include files */

#include "lab2_next_level_sfun.h"
#include "lab2_next_level_sfun_debug_macros.h"
#include "c1_lab2_next_level.h"
#include "c2_lab2_next_level.h"
#include "c3_lab2_next_level.h"
#include "c5_lab2_next_level.h"
#include "c6_lab2_next_level.h"
#include "c7_lab2_next_level.h"
#include "c9_lab2_next_level.h"
#include "c10_lab2_next_level.h"
#include "c11_lab2_next_level.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _lab2_next_levelMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void lab2_next_level_initializer(void)
{
}

void lab2_next_level_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_lab2_next_level_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_lab2_next_level_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_lab2_next_level_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_lab2_next_level_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_lab2_next_level_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_lab2_next_level_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_lab2_next_level_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_lab2_next_level_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_lab2_next_level_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_lab2_next_level_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_lab2_next_level_process_testpoint_info_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char machineName[128];
  if (nrhs < 3 || !mxIsChar(prhs[0]) || !mxIsChar(prhs[1]))
    return 0;

  /* Possible call to get testpoint info. */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_testpoint_info"))
    return 0;
  mxGetString(prhs[1], machineName, sizeof(machineName)/sizeof(char));
  machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
  if (!strcmp(machineName, "lab2_next_level")) {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
    switch (chartFileNumber) {
     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }

    return 1;
  }

  return 0;

#else

  return 0;

#endif

}

unsigned int sf_lab2_next_level_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(168256324U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1005122545U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1056983670U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2047361948U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4129118140U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2316186691U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2958912860U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(845706966U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_lab2_next_level_get_check_sum(mxArray *plhs[]);
          sf_c1_lab2_next_level_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_lab2_next_level_get_check_sum(mxArray *plhs[]);
          sf_c2_lab2_next_level_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_lab2_next_level_get_check_sum(mxArray *plhs[]);
          sf_c3_lab2_next_level_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_lab2_next_level_get_check_sum(mxArray *plhs[]);
          sf_c5_lab2_next_level_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_lab2_next_level_get_check_sum(mxArray *plhs[]);
          sf_c6_lab2_next_level_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_lab2_next_level_get_check_sum(mxArray *plhs[]);
          sf_c7_lab2_next_level_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_lab2_next_level_get_check_sum(mxArray *plhs[]);
          sf_c9_lab2_next_level_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_lab2_next_level_get_check_sum(mxArray *plhs[]);
          sf_c10_lab2_next_level_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_lab2_next_level_get_check_sum(mxArray *plhs[]);
          sf_c11_lab2_next_level_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(784597580U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(508478511U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1608615269U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1082679159U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(422756916U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(370060573U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(434173258U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3583086695U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_lab2_next_level_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "OOLtbgBMxZDxDsAB2aWEBB") == 0) {
          extern mxArray *sf_c1_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c1_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "6mSrsiNu4YL5zJGXafkQEB") == 0) {
          extern mxArray *sf_c2_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c2_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "6L2Lu3f77ZJVNKYSJqa1oB") == 0) {
          extern mxArray *sf_c3_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c3_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "AnVFnCfwMgUHeZYC7h6hrE") == 0) {
          extern mxArray *sf_c5_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c5_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "H7wNkk8VbddGJR9ziIB1zF") == 0) {
          extern mxArray *sf_c6_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c6_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "PL2suHQ5QRwWh9lsO0xG1C") == 0) {
          extern mxArray *sf_c7_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c7_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "yhbraJ7lEO6iLmiG4INrKG") == 0) {
          extern mxArray *sf_c9_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c9_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "6NdmcTyIkRJgX9Gsy5GRpB") == 0) {
          extern mxArray *sf_c10_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c10_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "n6nBuPeBY7yju8R7q2K1xE") == 0) {
          extern mxArray *sf_c11_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c11_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_lab2_next_level_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_lab2_next_level_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_lab2_next_level_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_lab2_next_level_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_lab2_next_level_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_lab2_next_level_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_lab2_next_level_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_lab2_next_level_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_lab2_next_level_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_lab2_next_level_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_lab2_next_level_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_lab2_next_level_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_lab2_next_level_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_lab2_next_level_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_lab2_next_level_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_lab2_next_level_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_lab2_next_level_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_lab2_next_level_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_lab2_next_level_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_lab2_next_level_third_party_uses_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "dS1MItcQYiUXcN6aqDyO2") == 0) {
          extern mxArray *sf_c1_lab2_next_level_third_party_uses_info(void);
          plhs[0] = sf_c1_lab2_next_level_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "3z6deUui42H6sqAXuXrVOF") == 0) {
          extern mxArray *sf_c2_lab2_next_level_third_party_uses_info(void);
          plhs[0] = sf_c2_lab2_next_level_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "rWFRKbERwfDZOgznlYi3cE") == 0) {
          extern mxArray *sf_c3_lab2_next_level_third_party_uses_info(void);
          plhs[0] = sf_c3_lab2_next_level_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "7bmB8ztb6GYe0mpdzHGjJ") == 0) {
          extern mxArray *sf_c5_lab2_next_level_third_party_uses_info(void);
          plhs[0] = sf_c5_lab2_next_level_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "v0eaYnYzsLqg1gf5TdThTH") == 0) {
          extern mxArray *sf_c6_lab2_next_level_third_party_uses_info(void);
          plhs[0] = sf_c6_lab2_next_level_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "6R24wC1NieJ1PcJRFzy98B") == 0) {
          extern mxArray *sf_c7_lab2_next_level_third_party_uses_info(void);
          plhs[0] = sf_c7_lab2_next_level_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "XuGHHZuCwjoFxxSKDxlIDC") == 0) {
          extern mxArray *sf_c9_lab2_next_level_third_party_uses_info(void);
          plhs[0] = sf_c9_lab2_next_level_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "S0XB7oGev3JDlWYZIVEjrF") == 0) {
          extern mxArray *sf_c10_lab2_next_level_third_party_uses_info(void);
          plhs[0] = sf_c10_lab2_next_level_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "V7UZcsPFAURUsscbhoFkH") == 0) {
          extern mxArray *sf_c11_lab2_next_level_third_party_uses_info(void);
          plhs[0] = sf_c11_lab2_next_level_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void lab2_next_level_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _lab2_next_levelMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "lab2_next_level","sfun",0,9,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _lab2_next_levelMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _lab2_next_levelMachineNumber_,0);
}

void lab2_next_level_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_lab2_next_level_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("lab2_next_level",
      "lab2_next_level");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_lab2_next_level_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
