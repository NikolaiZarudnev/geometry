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

void description_circle(Circle shape1, Circle shape2)
{
    printf("perimeter: %.2f\n", (2.0 * M_PI * shape1.r));
    printf("area: %.2f\n", (M_PI * shape1.r * shape1.r));

    if (cross_circle(shape1, shape2)) {
        printf("intersects with 2. circle\n");
        printf("  \n");
    } else {
        printf("no intersects\n");
    }
}