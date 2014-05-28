/* Include files */

#include "lab2_next_level_sfun.h"
#include "c1_lab2_next_level.h"
#include "c2_lab2_next_level.h"
#include "c3_lab2_next_level.h"
#include "c5_lab2_next_level.h"
#include "c6_lab2_next_level.h"
#include "c7_lab2_next_level.h"
#include "c9_lab2_next_level.h"
#include "c10_lab2_next_level.h"
#include "c11_lab2_next_level.h"
#include "c16_lab2_next_level.h"
#include "c17_lab2_next_level.h"
#include "c18_lab2_next_level.h"
#include "c19_lab2_next_level.h"
#include "c20_lab2_next_level.h"
#include "c21_lab2_next_level.h"
#include "c22_lab2_next_level.h"
#include "c23_lab2_next_level.h"
#include "c24_lab2_next_level.h"

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

  if (chartFileNumber==16) {
    c16_lab2_next_level_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_lab2_next_level_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==18) {
    c18_lab2_next_level_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_lab2_next_level_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_lab2_next_level_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_lab2_next_level_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==22) {
    c22_lab2_next_level_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==23) {
    c23_lab2_next_level_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==24) {
    c24_lab2_next_level_method_dispatcher(simstructPtr, method, data);
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
     case 1:
      {
        extern mxArray *sf_c1_lab2_next_level_get_testpoint_info(void);
        plhs[0] = sf_c1_lab2_next_level_get_testpoint_info();
        break;
      }

     case 2:
      {
        extern mxArray *sf_c2_lab2_next_level_get_testpoint_info(void);
        plhs[0] = sf_c2_lab2_next_level_get_testpoint_info();
        break;
      }

     case 3:
      {
        extern mxArray *sf_c3_lab2_next_level_get_testpoint_info(void);
        plhs[0] = sf_c3_lab2_next_level_get_testpoint_info();
        break;
      }

     case 5:
      {
        extern mxArray *sf_c5_lab2_next_level_get_testpoint_info(void);
        plhs[0] = sf_c5_lab2_next_level_get_testpoint_info();
        break;
      }

     case 6:
      {
        extern mxArray *sf_c6_lab2_next_level_get_testpoint_info(void);
        plhs[0] = sf_c6_lab2_next_level_get_testpoint_info();
        break;
      }

     case 7:
      {
        extern mxArray *sf_c7_lab2_next_level_get_testpoint_info(void);
        plhs[0] = sf_c7_lab2_next_level_get_testpoint_info();
        break;
      }

     case 9:
      {
        extern mxArray *sf_c9_lab2_next_level_get_testpoint_info(void);
        plhs[0] = sf_c9_lab2_next_level_get_testpoint_info();
        break;
      }

     case 10:
      {
        extern mxArray *sf_c10_lab2_next_level_get_testpoint_info(void);
        plhs[0] = sf_c10_lab2_next_level_get_testpoint_info();
        break;
      }

     case 11:
      {
        extern mxArray *sf_c11_lab2_next_level_get_testpoint_info(void);
        plhs[0] = sf_c11_lab2_next_level_get_testpoint_info();
        break;
      }

     case 16:
      {
        extern mxArray *sf_c16_lab2_next_level_get_testpoint_info(void);
        plhs[0] = sf_c16_lab2_next_level_get_testpoint_info();
        break;
      }

     case 17:
      {
        extern mxArray *sf_c17_lab2_next_level_get_testpoint_info(void);
        plhs[0] = sf_c17_lab2_next_level_get_testpoint_info();
        break;
      }

     case 18:
      {
        extern mxArray *sf_c18_lab2_next_level_get_testpoint_info(void);
        plhs[0] = sf_c18_lab2_next_level_get_testpoint_info();
        break;
      }

     case 19:
      {
        extern mxArray *sf_c19_lab2_next_level_get_testpoint_info(void);
        plhs[0] = sf_c19_lab2_next_level_get_testpoint_info();
        break;
      }

     case 20:
      {
        extern mxArray *sf_c20_lab2_next_level_get_testpoint_info(void);
        plhs[0] = sf_c20_lab2_next_level_get_testpoint_info();
        break;
      }

     case 21:
      {
        extern mxArray *sf_c21_lab2_next_level_get_testpoint_info(void);
        plhs[0] = sf_c21_lab2_next_level_get_testpoint_info();
        break;
      }

     case 22:
      {
        extern mxArray *sf_c22_lab2_next_level_get_testpoint_info(void);
        plhs[0] = sf_c22_lab2_next_level_get_testpoint_info();
        break;
      }

     case 23:
      {
        extern mxArray *sf_c23_lab2_next_level_get_testpoint_info(void);
        plhs[0] = sf_c23_lab2_next_level_get_testpoint_info();
        break;
      }

     case 24:
      {
        extern mxArray *sf_c24_lab2_next_level_get_testpoint_info(void);
        plhs[0] = sf_c24_lab2_next_level_get_testpoint_info();
        break;
      }

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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(927504549U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(996580686U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(337100810U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1561762592U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
<<<<<<< HEAD
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1475619435U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4058332884U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2687666632U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2277299222U);
=======
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(159107059U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1179547711U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1128448550U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2942079437U);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
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

       case 16:
        {
          extern void sf_c16_lab2_next_level_get_check_sum(mxArray *plhs[]);
          sf_c16_lab2_next_level_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_lab2_next_level_get_check_sum(mxArray *plhs[]);
          sf_c17_lab2_next_level_get_check_sum(plhs);
          break;
        }

       case 18:
        {
          extern void sf_c18_lab2_next_level_get_check_sum(mxArray *plhs[]);
          sf_c18_lab2_next_level_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_lab2_next_level_get_check_sum(mxArray *plhs[]);
          sf_c19_lab2_next_level_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_lab2_next_level_get_check_sum(mxArray *plhs[]);
          sf_c20_lab2_next_level_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_lab2_next_level_get_check_sum(mxArray *plhs[]);
          sf_c21_lab2_next_level_get_check_sum(plhs);
          break;
        }

       case 22:
        {
          extern void sf_c22_lab2_next_level_get_check_sum(mxArray *plhs[]);
          sf_c22_lab2_next_level_get_check_sum(plhs);
          break;
        }

       case 23:
        {
          extern void sf_c23_lab2_next_level_get_check_sum(mxArray *plhs[]);
          sf_c23_lab2_next_level_get_check_sum(plhs);
          break;
        }

       case 24:
        {
          extern void sf_c24_lab2_next_level_get_check_sum(mxArray *plhs[]);
          sf_c24_lab2_next_level_get_check_sum(plhs);
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
<<<<<<< HEAD
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3211655770U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(912120558U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2343958268U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3232031223U);
=======
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(506169417U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3247393031U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1887996479U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1612455041U);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
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
        if (strcmp(aiChksum, "0GYefm7ACLoVMzw0kmnljF") == 0) {
          extern mxArray *sf_c1_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c1_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
<<<<<<< HEAD
        if (strcmp(aiChksum, "JquTjZK7IzwTTeKVqMBsEF") == 0) {
=======
        if (strcmp(aiChksum, "THIKj7K7i03gxM0Up0KFaD") == 0) {
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
          extern mxArray *sf_c2_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c2_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
<<<<<<< HEAD
        if (strcmp(aiChksum, "WPpaiSKfiARUZrtKyOnfyF") == 0) {
=======
        if (strcmp(aiChksum, "WN7Y08Cew1uRTKAttGwzpG") == 0) {
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
          extern mxArray *sf_c3_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c3_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "GPnlTXCn1y9uoLmp2mbpn") == 0) {
          extern mxArray *sf_c5_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c5_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "pwBb04mR8ycG6TSCT8fUZC") == 0) {
          extern mxArray *sf_c6_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c6_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "UG2SrEtWKDhSOzjxTz5AJG") == 0) {
          extern mxArray *sf_c7_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c7_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "53wnGOOPp6fXV96CxS0OGF") == 0) {
          extern mxArray *sf_c9_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c9_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
<<<<<<< HEAD
        if (strcmp(aiChksum, "V878yxmFC9oe7WGApG5anC") == 0) {
=======
        if (strcmp(aiChksum, "U5P4Et7AQRD2SqdJkLNPJ") == 0) {
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
          extern mxArray *sf_c10_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c10_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "NjkKiHc1lIp9X5V6VaFIFG") == 0) {
          extern mxArray *sf_c11_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c11_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
<<<<<<< HEAD
        if (strcmp(aiChksum, "jXCiqRXtpmKqR30xY9snCE") == 0) {
=======
        if (strcmp(aiChksum, "NXdU5C70GXXJwsBfFPdHSH") == 0) {
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
          extern mxArray *sf_c16_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c16_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "0mvZya5kZsgbBXcVaHzvJ") == 0) {
          extern mxArray *sf_c17_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c17_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 18:
      {
        if (strcmp(aiChksum, "yCEGEkS6FyFUqaAWsbj8L") == 0) {
          extern mxArray *sf_c18_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c18_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 19:
      {
        if (strcmp(aiChksum, "NXdU5C70GXXJwsBfFPdHSH") == 0) {
          extern mxArray *sf_c19_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c19_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "0mvZya5kZsgbBXcVaHzvJ") == 0) {
          extern mxArray *sf_c20_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c20_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 21:
      {
        if (strcmp(aiChksum, "yCEGEkS6FyFUqaAWsbj8L") == 0) {
          extern mxArray *sf_c21_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c21_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 22:
      {
<<<<<<< HEAD
        if (strcmp(aiChksum, "jXCiqRXtpmKqR30xY9snCE") == 0) {
=======
        if (strcmp(aiChksum, "NXdU5C70GXXJwsBfFPdHSH") == 0) {
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
          extern mxArray *sf_c22_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c22_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 23:
      {
<<<<<<< HEAD
        if (strcmp(aiChksum, "LwWzKcNeoaKftINKW0CKOE") == 0) {
=======
        if (strcmp(aiChksum, "0mvZya5kZsgbBXcVaHzvJ") == 0) {
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
          extern mxArray *sf_c23_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c23_lab2_next_level_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 24:
      {
<<<<<<< HEAD
        if (strcmp(aiChksum, "j33284cgAhzVWjnM0ydLmD") == 0) {
=======
        if (strcmp(aiChksum, "yCEGEkS6FyFUqaAWsbj8L") == 0) {
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
          extern mxArray *sf_c24_lab2_next_level_get_autoinheritance_info(void);
          plhs[0] = sf_c24_lab2_next_level_get_autoinheritance_info();
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

     case 16:
      {
        extern const mxArray
          *sf_c16_lab2_next_level_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_lab2_next_level_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_lab2_next_level_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_lab2_next_level_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 18:
      {
        extern const mxArray
          *sf_c18_lab2_next_level_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_lab2_next_level_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray
          *sf_c19_lab2_next_level_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_lab2_next_level_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_lab2_next_level_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_lab2_next_level_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray
          *sf_c21_lab2_next_level_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_lab2_next_level_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 22:
<<<<<<< HEAD
      {
        extern const mxArray
          *sf_c22_lab2_next_level_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_lab2_next_level_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 23:
      {
        extern const mxArray
          *sf_c23_lab2_next_level_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c23_lab2_next_level_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 24:
      {
        extern const mxArray
          *sf_c24_lab2_next_level_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c24_lab2_next_level_get_eml_resolved_functions_info();
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
        if (strcmp(tpChksum, "6HoQ4rMfP620FhYsayQzCG") == 0) {
          extern mxArray *sf_c1_lab2_next_level_third_party_uses_info(void);
          plhs[0] = sf_c1_lab2_next_level_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "cods73WN44Bs2OHeqUGlYE") == 0) {
          extern mxArray *sf_c2_lab2_next_level_third_party_uses_info(void);
          plhs[0] = sf_c2_lab2_next_level_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "rjGLt8apbbdIPjqgtOa4OF") == 0) {
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
        if (strcmp(tpChksum, "lRDewifV1z3vH2XgldyznG") == 0) {
          extern mxArray *sf_c9_lab2_next_level_third_party_uses_info(void);
          plhs[0] = sf_c9_lab2_next_level_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "uMiMxksBgc6vc6nryy9JJD") == 0) {
          extern mxArray *sf_c10_lab2_next_level_third_party_uses_info(void);
          plhs[0] = sf_c10_lab2_next_level_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "t5vqPwHEy8XcMX46aNH3XC") == 0) {
          extern mxArray *sf_c11_lab2_next_level_third_party_uses_info(void);
          plhs[0] = sf_c11_lab2_next_level_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "XJtCwoNhTkrbDVsoVz2uyG") == 0) {
          extern mxArray *sf_c16_lab2_next_level_third_party_uses_info(void);
          plhs[0] = sf_c16_lab2_next_level_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "6iJpylMXH6x4uTmmbhoXQE") == 0) {
          extern mxArray *sf_c17_lab2_next_level_third_party_uses_info(void);
          plhs[0] = sf_c17_lab2_next_level_third_party_uses_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "LmM1Rax0nqu4g4w1eNpScE") == 0) {
          extern mxArray *sf_c18_lab2_next_level_third_party_uses_info(void);
          plhs[0] = sf_c18_lab2_next_level_third_party_uses_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "XJtCwoNhTkrbDVsoVz2uyG") == 0) {
          extern mxArray *sf_c19_lab2_next_level_third_party_uses_info(void);
          plhs[0] = sf_c19_lab2_next_level_third_party_uses_info();
          break;
        }
=======
      {
        extern const mxArray
          *sf_c22_lab2_next_level_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_lab2_next_level_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
      }

     case 23:
      {
        extern const mxArray
          *sf_c23_lab2_next_level_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c23_lab2_next_level_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 24:
      {
        extern const mxArray
          *sf_c24_lab2_next_level_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c24_lab2_next_level_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 22:
      {
        if (strcmp(tpChksum, "XJtCwoNhTkrbDVsoVz2uyG") == 0) {
          extern mxArray *sf_c22_lab2_next_level_third_party_uses_info(void);
          plhs[0] = sf_c22_lab2_next_level_third_party_uses_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "6iJpylMXH6x4uTmmbhoXQE") == 0) {
          extern mxArray *sf_c23_lab2_next_level_third_party_uses_info(void);
          plhs[0] = sf_c23_lab2_next_level_third_party_uses_info();
          break;
        }
      }

     case 24:
      {
        if (strcmp(tpChksum, "LmM1Rax0nqu4g4w1eNpScE") == 0) {
          extern mxArray *sf_c24_lab2_next_level_third_party_uses_info(void);
          plhs[0] = sf_c24_lab2_next_level_third_party_uses_info();
          break;
        }
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

void lab2_next_level_debug_initialize(void)
{
<<<<<<< HEAD
  _lab2_next_levelMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "lab2_next_level","sfun",0,18,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _lab2_next_levelMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _lab2_next_levelMachineNumber_,0);
=======
  _lab2_next_levelMachineNumber_ = sf_debug_initialize_machine("lab2_next_level",
    "sfun",0,18,0,0,0);
  sf_debug_set_machine_event_thresholds(_lab2_next_levelMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_lab2_next_levelMachineNumber_,0);
>>>>>>> 333b1aefea52d20a89beb760782d0f13548f6711
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
