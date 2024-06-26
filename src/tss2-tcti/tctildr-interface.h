/* SPDX-License-Identifier: BSD-2-Clause */
/*******************************************************************************
 * Copyright 2017, Fraunhofer SIT sponsored by Infineon Technologies AG
 * All rights reserved.
 *******************************************************************************/
#ifndef     TCTI_INTERFACE_H
#define     TCTI_INTERFACE_H

#include "tss2_common.h"  // for TSS2_RC
#include "tss2_tcti.h"    // for TSS2_TCTI_CONTEXT, TSS2_TCTI_INFO

TSS2_RC
tctildr_get_tcti (const char *name,
                  const char* conf,
                  TSS2_TCTI_CONTEXT **tcti,
                  void **dlhandle);
void tctildr_finalize_data(void **data);
TSS2_RC
tctildr_get_info (const char *name,
                  const TSS2_TCTI_INFO **info,
                  void **data);

#endif
