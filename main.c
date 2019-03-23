#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define M_PI 3.14

typedef struct {
	float x, y;
	float r;
}Circle;

 float string_to_float(char* c, int x)
 {
	int i;
	float n,v;
	for (i = 0; !(c[i] >= '0' && c[i] <= '9'); i++) {
		if (c[i] == '\0'){
			return 0;
		}
	}
	for (n = 0; c[i] >= '0' && c[i] <= '9'; i++) {
			n = n * 10 + c[i] - '0';
	}
	if (c[i] != '.') {
		return n;
	}
	for (i++, v = 0.1; c[i] >= '0' && c[i] <= '9'; i++) {
		n += v * (c[i] - '0');
		v = v / 10;                      
	}
	return n;
}

Circle circle_input()
{
	Circle shape;
	char stringNAME[25];
	float circlexyr[3];
	printf("enter circle(x, y, radius)\n");
	fgets(stringNAME, 25, stdin);
	if (strcmp(stringNAME, "circle(%f, %f, %f")) {                     //входные данные???
		printf("error\n");
	}
	for (int i = 0; i < 3; ++i) {
		circlexyr[i] = string_to_float(stringNAME, 25);
	}
	shape.x = circlexyr[0];
	shape.y = circlexyr[1];
	shape.r = circlexyr[2];
	return shape;
}

int cross_circle(Circle shape1, Circle shape2)
{
	if ((sqrt(pow((shape1.x - shape2.x), 2) + pow((shape1.y - shape2.y), 2)) < shape1.r + shape2.r) && 
		(sqrt(pow((shape1.x - shape2.x), 2) + pow((shape1.y - shape2.y), 2)) > abs(shape1.r - shape2.r)))
        return 1;
    else
        return 0;
}

void description_circle(Circle shape1, Circle shape2)   
{
	printf("perimeter: %.2f\n", (2.0 * M_PI * shape1.r));
	printf("area: %.2f\n", (M_PI * shape1.r * shape1.r));

	if(cross_circle(shape1, shape2)) {
		printf("intersects with 2. circle\n");
		printf("  \n");                                         //оформление вывода???
	}else{
		printf("no intersects\n");
	}
}

int main()
{
	Circle a, b;
	a = circle_input();
	b = circle_input();
	description_circle(a, b);
	return 0;
}