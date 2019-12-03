#include "fastpbkdf2.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>


typedef void (*pbkdf2_fn)(const uint8_t *pw, size_t npw,
                          const uint8_t *salt, size_t nsalt,
                          uint32_t iterations,
                          uint8_t *out, size_t nout);


void dump(const char *label, const uint8_t *data, size_t n)
{
  printf("%s: ", label);
  for (size_t i = 0; i < n; i++)
    printf("%02x", data[i]);
  printf("\n");
}

void Seed(const void *pw, size_t npw,const void *salt, size_t nsalt,unsigned iterations, size_t nexpect)
{
  uint8_t out[128];
  assert(nexpect < sizeof(out));

  fastpbkdf2_hmac_sha256(pw, npw,salt, nsalt,iterations,out, nexpect);

  dump("\n\nSeed  ", out, nexpect);
}