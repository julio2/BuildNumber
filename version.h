/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

#ifndef XC_VERSION_H
#define	XC_VERSION_H

#include <stdlib.h>
#include <string.h>
#include "GenericTypeDefs.h"


typedef struct _UINT24{
       UINT8 H;
       UINT8 LH;
       UINT8 LL;
   }UINT24; 
   
#define VERSION "v1.08"
#define MODELO  "C226T"   
#define BUILDNUMBER 109

void empaquetarVersion(char* buffer);

#endif	/* XC_VERSION_H */






