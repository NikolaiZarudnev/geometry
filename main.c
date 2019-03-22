#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define M_PI 3.14

typedef struct {
	float x, y;
	float r;
}Circle;

Circle circle_input()
{
	Circle shape;
	printf("Enter x and y:\n");
	scanf("%f %f", &shape.x, &shape.y);
	printf("Enter radius\n");
	scanf("%f", &shape.r);
	return shape;
}

int cross_circle(Circle shape1, Circle shape2)
{
	if ((sqrt(pow((shape1.x - shape2.x), 2) + pow((shape1.y - shape2.y), 2)) < shape1.r + shape2.r) && 
		(sqrt(pow((shape1.x - shape2.x), 2) + pow((shape1.y - shape2.y), 2)) > abs(shape1.r - shape2.r))) {
        return 1;
    } else {
        return 0;
    }
}

void description_circle(Circle shape1, Circle shape2)   
{
	printf("perimeter: %.2f\n", (2.0 * M_PI * shape1.r));
	printf("area: %.2f\n", (M_PI * shape1.r * shape1.r));

	if(cross_circle(shape1, shape2)) {
		printf("intersects:\n");
		printf("  \n");                                         //оформление вывода???
	} else {
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