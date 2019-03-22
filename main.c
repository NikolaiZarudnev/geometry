#include <stdio.h>
#define M_PI 3.14

typedef struct {
	float x, y;
	float r;
}circle;

circle circle_input(circle shape)
{
	printf("Enter x and y:\n");
	scanf("%f %f", &shape.x, &shape.y);
	printf("Enter radius\n");
	scanf("%f", &shape.r);

	return shape;
}

void description_circle(circle shape)
{
	printf("perimeter: %.2f\n", (2.0 * M_PI * shape.r));
	printf("area: %.2f\n", (M_PI * shape.r * shape.r));
}

int main()
{
	circle a;
	
	a = circle_input(a);
	description_circle(a);
	return 0;
}