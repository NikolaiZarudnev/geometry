#include "description_shape.h"
#include "input_output.h"

int cross_circle(Circle shape1, Circle shape2)
{
    if ((sqrt(pow((shape1.x - shape2.x), 2) + pow((shape1.y - shape2.y), 2))
         < shape1.r + shape2.r)
        && (sqrt(pow((shape1.x - shape2.x), 2) + pow((shape1.y - shape2.y), 2))
            > abs(shape1.r - shape2.r)))
        return 1;
    else
        return 0;
}

float area_circle(Circle circle)
{
    float area;
    area = M_PI * circle.r * circle.r;
    return area;
}

float p_circle(Circle circle)
{
    float p;
    p = 2.0 * M_PI * circle.r;
    return p;
}

void description_circle(Circle shape1, Circle shape2)
{
    float p;
    float area;
    area = area_circle(shape1);
    printf("1.Circle \narea: %.2f\n", area);
    p = p_circle(shape1);
    printf("perimeter: %.2f\n", p);
    area = area_circle(shape2);
    printf("2.Circle \narea: %.2f\n", area);
    p = p_circle(shape2);
    printf("perimeter: %.2f\n", p);

    if (cross_circle(shape1, shape2)) {
        printf("intersects\n");
    } else {
        printf("no intersects\n");
    }
}