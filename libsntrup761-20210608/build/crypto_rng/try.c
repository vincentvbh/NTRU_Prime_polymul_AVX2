/*
 * crypto_rng/try.c version 20170708
 * D. J. Bernstein
 * Public domain.
 * Auto-generated by trygen.py; do not edit.
 */

#include "crypto_rng.h"
#include "try.h"

const char *primitiveimplementation = crypto_rng_IMPLEMENTATION;

#define TUNE_BYTES 1536
#ifdef SMALL
#define MAXTEST_BYTES 128
#else
#define MAXTEST_BYTES 4096
#endif
#ifdef SMALL
#define LOOPS 64
#else
#define LOOPS 512
#endif

static unsigned char *k;
static unsigned char *r;
static unsigned char *n;
static unsigned char *k2;
static unsigned char *r2;
static unsigned char *n2;
#define klen crypto_rng_KEYBYTES
#define rlen crypto_rng_OUTPUTBYTES
#define nlen crypto_rng_KEYBYTES

void preallocate(void)
{
}

void allocate(void)
{
  unsigned long long alloclen = 0;
  if (alloclen < TUNE_BYTES) alloclen = TUNE_BYTES;
  if (alloclen < MAXTEST_BYTES) alloclen = MAXTEST_BYTES;
  if (alloclen < crypto_rng_KEYBYTES) alloclen = crypto_rng_KEYBYTES;
  if (alloclen < crypto_rng_OUTPUTBYTES) alloclen = crypto_rng_OUTPUTBYTES;
  if (alloclen < crypto_rng_KEYBYTES) alloclen = crypto_rng_KEYBYTES;
  k = alignedcalloc(alloclen);
  r = alignedcalloc(alloclen);
  n = alignedcalloc(alloclen);
  k2 = alignedcalloc(alloclen);
  r2 = alignedcalloc(alloclen);
  n2 = alignedcalloc(alloclen);
}

void predoit(void)
{
}

void doit(void)
{
  crypto_rng(r,n,k);
}

/*
void test(void)
{
  unsigned long long loop;
  
  for (loop = 0;loop < LOOPS;++loop) {
    
    output_prepare(r2,r,rlen);
    output_prepare(n2,n,nlen);
    input_prepare(k2,k,klen);
    if (crypto_rng(r,n,k) != 0) fail("crypto_rng returns nonzero");
    checksum(r,rlen);
    checksum(n,nlen);
    output_compare(r2,r,rlen,"crypto_rng");
    output_compare(n2,n,nlen,"crypto_rng");
    input_compare(k2,k,klen,"crypto_rng");
    
    double_canary(r2,r,rlen);
    double_canary(n2,n,nlen);
    double_canary(k2,k,klen);
    if (crypto_rng(r2,n2,k2) != 0) fail("crypto_rng returns nonzero");
    if (memcmp(r2,r,rlen) != 0) fail("crypto_rng is nondeterministic");
    if (memcmp(n2,n,nlen) != 0) fail("crypto_rng is nondeterministic");
    
    double_canary(r2,r,rlen);
    double_canary(n2,n,nlen);
    double_canary(k2,k,klen);
    if (crypto_rng(k2,n,k2) != 0) fail("crypto_rng with k=r overlap returns nonzero");
    if (memcmp(k2,r,rlen) != 0) fail("crypto_rng does not handle k=r overlap");
    memcpy(k2,k,klen);
    
    double_canary(r2,r,rlen);
    double_canary(n2,n,nlen);
    double_canary(k2,k,klen);
    if (crypto_rng(r,k2,k2) != 0) fail("crypto_rng with k=n overlap returns nonzero");
    if (memcmp(k2,n,nlen) != 0) fail("crypto_rng does not handle k=n overlap");
    memcpy(k2,k,klen);
  }
}
*/