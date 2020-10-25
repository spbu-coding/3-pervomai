#include <stdio.h>
#include <math.h>
#define MAX_DEVIATION 0.000001
#define RESULTF 2.0f
#define RESULT 2.0

void solution_floats(void) {
    float delta = 0.0001f;
    float x1 = 0.0f, x2 = 0.0f, x1_0 = 1.0f, x2_0 = 1.0f;
    x2 = (2.0001f - 2.0f + delta) / 0.0001f;
    x1 = 2.0f - x2;
    float deviation = sqrtf((x1 - x1_0) * (x1 - x1_0) + (x2 - x2_0) * (x2 - x2_0));
    int count = 1;
    float previous_result = 0.0f;
    while (deviation > MAX_DEVIATION ) {
        x2 = (2.0001f - 2.0f + delta) / 0.0001f;
        x1 = 2.0f - x2;
        float new_result = x1 + 1.0001f * x2;
        float difference_results = new_result - RESULTF;
        deviation = sqrtf((x1 - x1_0) * (x1 - x1_0) + (x2 - x2_0) * (x2 - x2_0));
        printf ("%d  x1: %.20f x2: %.20f \n", count, x1, x2);
        printf ("Deviation: %.20f \n", deviation);
        printf ("Difference between results in (1)equation x1 + x2 = 2 and in (2)equation x1 + 1.0001 * x2 = %.20f : %.20f \n\n", new_result, difference_results);
        delta = delta/2.0f;
        if (previous_result == new_result) {
            printf("Infinity loop.\n");
            break;
        }
        previous_result = new_result;
        count++;
    }

}

void solution_doubles(void) {
    double delta = 0.0001;
    double x1 = 0.0, x2 = 0.0, x1_0 = 1.0, x2_0 = 1.0;
    x2 = (2.0001 - 2.0 + delta)/0.0001;
    x1 = 2.0 - x2;
    double deviation = sqrt((x1 - x1_0) * (x1 - x1_0) + (x2 - x2_0) * (x2 - x2_0));
    int count = 1;
    double previous_result = 0.0;
    while (deviation > MAX_DEVIATION ) {
        x2 = (2.0001 - 2.0 + delta) / 0.0001;
        x1 = 2.0f - x2;
        double new_result = x1 + 1.0001 * x2;
        double difference_results = new_result - RESULT;
        deviation = sqrt((x1 - x1_0) * (x1 - x1_0) + (x2 - x2_0) * (x2 - x2_0));
        printf ("%d  x1: %.20lf x2: %.20lf \n", count, x1, x2);
        printf ("Deviation: %.20lf \n", deviation);
        printf ("Difference between results in (1)equation x1 + x2 = 2 and in (2)equation x1 + 1.0001 * x2 = %.20lf : %.20lf \n\n", new_result, difference_results);
        delta = delta/2.0;
        if (previous_result == new_result) {
            printf("Infinity loop.\n");
            break;
        }
        previous_result = new_result;
        count++;
    }

}

int main() {

    printf ("IN DOUBLE\n");
    solution_doubles();
    printf ("IN FLOAT\n");
    solution_floats();

    return 0;
}
