#ifndef LIBFORNBERG_H
#define LIBFORNBERG_H

#include<stdio.h>
#include<stdlib.h>

float get_weight(int N, int m, int n, int v,float *vector);

void fornberg_weights(int M,int p,int *alpha,float *delta);
#endif
