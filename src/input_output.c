#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input_output.h"

float string_to_float(char* c, int x)
{
    int i;
    float n, v;
    for (i = 0; !(c[i] >= '0' && c[i] <= '9'); i++) {
        if (c[i] == '\0') {
            return 0;
        }
    }
    for (n = 0; c[i] >= '0' && c[i] <= '9'; i++) {
        n = n * 10 + c[i] - '0';

        if (c[i] != '.') {
            return n;
        }
        for (i++, v = 0.1; c[i] >= '0' && c[i] <= '9'; i++) {
            n += v * (c[i] - '0');
            v = v / 10;
        }
        return n;
    }
}

Circle circle_input()
{
    Circle shape;
    char string_name[25];
    float circle_xyr[3];
    printf("enter: 'circle(x, y, radius)'\n");
    fgets(string_name, 25, stdin);
    if (strcmp(string_name, "circle(%f, %f, %f)")) { 
    	printf("error\n");
    	return -1;
    }
    for (int i = 0; i < 3; ++i) {
        circle_xyr[i] = string_to_float(string_name, 25);
    }
    shape.x = circle_xyr[0];
    shape.y = circle_xyr[1];
    shape.r = circle_xyr[2];
    return shape;
}