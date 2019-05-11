#define CTEST_MAIN

#include "../src/description_shape.h"
#include "../src/input_output.h"
#include "../thirdparty/ctest.h"

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}

CTEST(area_circle_test, result_test)
{
    // Given
    Circle circle;
    circle.r = 4.5;

    // When
    const float result = area_circle(circle);

    // Then
    const float expected = 63.617251;
    ASSERT_EQUAL(expected, result);
}

CTEST(p_circle_test, result_test)
{
    // Given
    Circle circle;
    circle.r = 1.5;

    // When
    const float result = p_circle(circle);

    // Then
    const float expected = 9.424778;
    ASSERT_EQUAL(expected, result);
}

CTEST(cross_circle_test, same_center_coordinates_test)
{
    // Given
    Circle c1, c2;
    c1.x = 3.17;
    c2.x = 3.17;
    c1.y = -10;
    c2.y = -10;

    // When
    const float result = cross_circle(c1, c2);

    // Then
    ASSERT_FALSE(result);
}

CTEST(cross_circle_test, intersection_false)
{
    // Given
    Circle c1, c2;
    c1.x = 0;
    c1.y = 6;
    c1.r = 2;
    c2.x = 7;
    c2.y = 6;
    c2.r = 5;

    // When
    const float result = cross_circle(c1, c2);

    // Then
    ASSERT_FALSE(result);
}

CTEST(cross_circle_test, intersection_true)
{
    // Given
    Circle c1, c2;
    c1.x = 0;
    c1.y = 6;
    c1.r = 2;
    c2.x = 7;
    c2.y = 6;
    c2.r = 5.1;

    // When
    const float result = cross_circle(c1, c2);

    // Then
    ASSERT_TRUE(result);
}