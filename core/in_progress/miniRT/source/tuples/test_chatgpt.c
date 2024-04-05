// cc -lm test_chatgpt.c tuples_a.c tuples_b.c tuples_c.c -o test_tuples && ./test_tuples      



#include <stdio.h>
#include <math.h>
#include "../../include/tuples.h"

void test_do_point() {
    t_point p = do_point(1.0, 2.0, 3.0);
    if (p.x != 1.0 || p.y != 2.0 || p.z != 3.0 || p.w != 1.0) {
        printf("Test for do_point failed\n");
    } else {
        printf("Test for do_point passed\n");
    }
}

void test_do_vector() {
    t_vector v = do_vector(1.0, 2.0, 3.0);
    if (v.x != 1.0 || v.y != 2.0 || v.z != 3.0 || v.w != 0.0) {
        printf("Test for do_vector failed\n");
    } else {
        printf("Test for do_vector passed\n");
    }
}

void test_add_tuple_tuple() {
    t_tuple a = {1.0, 2.0, 3.0, 4.0};
    t_tuple b = {2.0, 3.0, 4.0, 5.0};
    t_tuple result = add_tuple_tuple(a, b);
    if (result.x != 3.0 || result.y != 5.0 || result.z != 7.0 || result.w != 9.0) {
        printf("Test for add_tuple_tuple failed\n");
    } else {
        printf("Test for add_tuple_tuple passed\n");
    }
}

void test_subtract_point_point() {
    t_point a = {3.0, 2.0, 1.0, 1.0};
    t_point b = {1.0, 2.0, 3.0, 1.0};
    t_vector result = subtract_point_point(a, b);
    if (result.x != 2.0 || result.y != 0.0 || result.z != -2.0 || result.w != 0.0) {
        printf("Test for subtract_point_point failed\n");
    } else {
        printf("Test for subtract_point_point passed\n");
    }
}

void test_subtract_point_vector() {
    t_point a = {3.0, 2.0, 1.0, 1.0};
    t_vector b = {1.0, 2.0, 3.0, 0.0};
    t_point result = subtract_point_vector(a, b);
    if (result.x != 2.0 || result.y != 0.0 || result.z != -2.0 || result.w != 1.0) {
        printf("Test for subtract_point_vector failed\n");
    } else {
        printf("Test for subtract_point_vector passed\n");
    }
}

void test_subtract_vector_vector() {
    t_vector a = {3.0, 2.0, 1.0, 0.0};
    t_vector b = {1.0, 2.0, 3.0, 0.0};
    t_vector result = subtract_vector_vector(a, b);
    if (result.x != 2.0 || result.y != 0.0 || result.z != -2.0 || result.w != 0.0) {
        printf("Test for subtract_vector_vector failed\n");
    } else {
        printf("Test for subtract_vector_vector passed\n");
    }
}

void test_negating_tuple() {
    t_tuple a = {1.0, -2.0, 3.0, -4.0};
    t_tuple result = negating_tuple(a);
    if (result.x != -1.0 || result.y != 2.0 || result.z != -3.0 || result.w != 4.0) {
        printf("Test for negating_tuple failed\n");
    } else {
        printf("Test for negating_tuple passed\n");
    }
}

void test_multiply_tuple_double() {
    t_tuple a = {1.0, -2.0, 3.0, -4.0};
    double b = 2.0;
    t_tuple result = multiply_tuple_double(a, b);
    if (result.x != 2.0 || result.y != -4.0 || result.z != 6.0 || result.w != -8.0) {
        printf("Test for multiply_tuple_double failed\n");
    } else {
        printf("Test for multiply_tuple_double passed\n");
    }
}

void test_magnitude() {
    t_tuple a = {1.0, 2.0, 3.0, 0.0}; // This is a vector
    double mag = magnitude(a);
    if (mag != sqrt(14.0)) {
        printf("Test for magnitude failed\n");
    } else {
        printf("Test for magnitude passed\n");
    }
}

void test_normalize() {
    t_tuple a = {1.0, 2.0, 3.0, 0.0}; // This is a vector
    t_tuple result = normalize(a);
    double mag = magnitude(result);
    if (mag != 1.0) {
        printf("Test for normalize failed\n");
    } else {
        printf("Test for normalize passed\n");
    }
}

void test_dot_product() {
    t_tuple a = {1.0, 2.0, 3.0, 0.0};
    t_tuple b = {3.0, 2.0, 1.0, 0.0};
    double dot = dot_product(a, b);
    if (dot != 10.0) {
        printf("Test for dot_product failed\n");
    } else {
        printf("Test for dot_product passed\n");
    }
}

void test_cross_product() {
    t_vector v1 = {1.0, 0.0, 0.0, 0.0};
    t_vector v2 = {0.0, 1.0, 0.0, 0.0};
    t_vector result = cross_product(v1, v2);
    if (result.x != 0.0 || result.y != 0.0 || result.z != 1.0 || result.w != 0.0) {
        printf("Test for cross_product failed\n");
    } else {
        printf("Test for cross_product passed\n");
    }
}

int main() {
    test_do_point();
    test_do_vector();
    test_add_tuple_tuple();
    test_subtract_point_point();
    test_subtract_point_vector();
    test_subtract_vector_vector();
    test_negating_tuple();
    test_multiply_tuple_double();
    test_magnitude();
    test_normalize();
    test_dot_product();
    test_cross_product();
    return 0;
}
