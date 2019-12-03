#include "fastpbkdf2.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

void dump(const char *label, const uint8_t *data, size_t n);
void Seed(const void *pw, size_t npw,const void *salt, size_t nsalt,unsigned iterations, size_t nexpect);