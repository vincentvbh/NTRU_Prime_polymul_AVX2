#ifndef NTT_PARAMS_H
#define NTT_PARAMS_H

#include "params.h"

#define ARRAY_N 1632
#define Q q

#define Qbar (7)
#define sqrt2 (1229)
#define sqrt2inv (2910)

#define BARRETT_BOUND (2881)

#define sqrt2Rmod (-760)
#define sqrt2invRmod (-380)

// R = 65536 below
// R mod Q
#define RmodQ (1262)
// Q^{-1} mod R
#define Qinv (15631)
// R^{-1} mod Q
#define RinvmodQ (-1095)

#define OMEGA17 (1152)
#define OMEGA17INV (-1080)

#define OMEGA3 (-311)
#define OMEGA3INV (310)

#define OMEGA3Rmod (-2247)
#define OMEGA3INVRmod (985)

#define INV4 1148
#define INV8 574

#define INV16 (287)
#define INV17 (-270)
#define INV3 (-1530)
#define INV2 (-2295)

// (17 * 3 * 4)^{-1} R mod Q
#define FINAL_SCALE (-849)
#define FINAL_SCALE_Rmod (-1735)

#endif

