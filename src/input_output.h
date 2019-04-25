#ifndef H_INPUT_OUTPUT
#define H_INPUT_OUTPUT
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float x, y;
    float r;
} Circle;

float string_to_float(char* c, int x);
Circle circle_input();
#endif