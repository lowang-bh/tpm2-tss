/* SPDX-License-Identifier: BSD-2-Clause */
/*******************************************************************************
 * Copyright 2017-2018, Fraunhofer SIT sponsored by Infineon Technologies AG
 * All rights reserved.
 *******************************************************************************/

#ifdef HAVE_CONFIG_H
#include "config.h" // IWYU pragma: keep
#endif

#include <stdlib.h>           // for EXIT_FAILURE, EXIT_SUCCESS

#include "tss2_common.h"      // for UINT32, TSS2_RC
#include "tss2_esys.h"        // for ESYS_TR_NONE, Esys_GetCapability, ESYS_...
#include "tss2_tpm2_types.h"  // for TPM2_CAP, TPM2_CAP_TPM_PROPERTIES, TPM2...

#define LOGMODULE test
#include "util/log.h"         // for SAFE_FREE, goto_if_error

/** This test is intended to test the ESYS get capability command.
 *
 * Tested ESYS commands:
 *  - Esys_GetCapability() (M)
 *
 * @param[in,out] esys_context The ESYS_CONTEXT.
 * @retval EXIT_FAILURE
 * @retval EXIT_SUCCESS
 */

int
test_esys_get_capability(ESYS_CONTEXT * esys_context)
{
    TSS2_RC r;
    TPM2_CAP                       capability = TPM2_CAP_TPM_PROPERTIES;
    UINT32                         property = TPM2_PT_LOCKOUT_COUNTER;
    UINT32                         propertyCount = 1;
    TPMS_CAPABILITY_DATA           *capabilityData;
    TPMI_YES_NO                    moreData;


    r = Esys_GetCapability(esys_context,
                           ESYS_TR_NONE, ESYS_TR_NONE, ESYS_TR_NONE,
                           capability, property, propertyCount,
                           &moreData, &capabilityData);

    goto_if_error(r, "Error esys get capability", error);

    SAFE_FREE(capabilityData);

    return EXIT_SUCCESS;

 error:
    SAFE_FREE(capabilityData);

    return EXIT_FAILURE;
}

int
test_invoke_esys(ESYS_CONTEXT * esys_context) {
    return test_esys_get_capability(esys_context);
}
