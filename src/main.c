#include "input_output.h"
#include "description_shape.h"

int main()
{
    Circle a, b;
    a = circle_input();
    b = circle_input();
    description_circle(a, b);
    return 0;
}
