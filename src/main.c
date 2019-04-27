#include "description_shape.h"
#include "input_output.h"

int main()
{
    Circle a, b;
    a = circle_input();
    b = circle_input();
    description_circle(a, b);
    return 0;
}
