#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#include "globals.h"

#define PI 3.14159265358979323846;

// TRIANGLE FUNCTIONS

bool validate_triangle_input(char* side) {
    int dot_counter = 0;
    int length = (int)strlen(side);
    if (length == 0) {
        fprintf(stderr, "Invalid Input: Empty input\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < length; i++) {
        if (isdigit(side[i])) {
            continue;
        }

        if (side[i] == '.') {
            dot_counter++;
            if (dot_counter > 1) {
                fprintf(stderr, "Invalid Input: More than one decimal point\n");
                return false;
            }
            continue;
        }

        fprintf(stderr, "Invalid Input: Non-numeric character\n");
        return false;
    }


    return true;
}

char* get_input(const char* prompt) {
    static char buffer[NUMLIMIT];

    while (1) {
        printf("%s", prompt);
        if (scanf("%s", buffer) != 1) {
            fprintf(stderr, "Error reading input. Please try again.\n");
            continue;
        }

        if (validate_triangle_input(buffer)) {
            return buffer;
        }
        else {
            fprintf(stderr, "Invalid input. Please enter a valid number.\n");
        }
    }
}

void get_triangle_input(char* sideA, char* sideB, char* sideC) {

    strcpy(sideA, get_input("Enter the length of the first side: "));
    strcpy(sideB, get_input("Enter the length of the second side: "));
    strcpy(sideC, get_input("Enter the length of the third side: "));
}

char* is_it_triangle(float sideA_float, float sideB_float, float sideC_float) {
    if (sideA_float + sideB_float > sideC_float && sideB_float + sideC_float > sideA_float && sideA_float + sideC_float > sideB_float) {
        return "This is a triangle";
    }
    else {
        return "This is not a triangle";
    }
}


double clamp(double value, double min, double max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

double calculate_angles(float sideA_float, float sideB_float, float sideC_float, double* angle_A, double* angle_B, double* angle_C) {

    double cos_A = (sideB_float * sideB_float + sideC_float * sideC_float - sideA_float * sideA_float) / (2 * sideB_float * sideC_float);
    double cos_B = (sideA_float * sideA_float + sideC_float * sideC_float - sideB_float * sideB_float) / (2 * sideA_float * sideC_float);
    double cos_C = (sideA_float * sideA_float + sideB_float * sideB_float - sideC_float * sideC_float) / (2 * sideA_float * sideB_float);

    cos_A = clamp(cos_A, -1.0, 1.0);
    cos_B = clamp(cos_B, -1.0, 1.0);
    cos_C = clamp(cos_C, -1.0, 1.0);

    *angle_A = acos(cos_A) * 180.0 / PI;
    *angle_B = acos(cos_B) * 180.0 / PI;
    *angle_C = acos(cos_C) * 180.0 / PI;


    return *angle_A;
    return *angle_B;
    return *angle_C;
}


// RECTANGLE FUNCTIONS

void clear_input_buffer() {
    while (getchar() != '\n');
}

void get_valid_floats(float* inputs, int num_inputs) {
    for (int i = 0; i < num_inputs; i++) {
        while (1) {
            printf("Enter point %d: ", i + 1);
            int result = scanf("%f", &inputs[i]);

            if (result != 1) {
                clear_input_buffer();
                printf("Invalid input. Please enter a valid float.\n");
            }
            else {
                break;
            }
        }
    }
}



int IsitRectangle(float RectangleLines[NUM_OF_SIDES]) {
    if (RectangleLines[0] != RectangleLines[1]) {
        printf("This is Not a Rectangle\n");
        return 1;
    }
    if (RectangleLines[2] != RectangleLines[3]) {
        printf("This is Not a Rectangle\n");
        return 1;
    }
    if (RectangleLines[4] != RectangleLines[5]) {
        printf("This is Not a Rectangle\n");
        return 1;
    }
    if (RectangleLines[2] == RectangleLines[5] && RectangleLines[3] == RectangleLines[4]) {
        printf("This is Not a Rectangle\n");
        printf("This is a square \n");
        return 1;
    }
    printf("This is a Rectangle\n");
    return 0;
}

void calculate_distances(float P1[COORD_LIMIT], float P2[COORD_LIMIT], float P3[COORD_LIMIT], float P4[COORD_LIMIT], float RectangleLines[NUM_OF_SIDES]) {
    float line1x = (P2[x] - P1[x]) * (P2[x] - P1[x]);
    float line1y = (P2[y] - P1[y]) * (P2[y] - P1[y]);

    float line2x = (P3[x] - P1[x]) * (P3[x] - P1[x]);
    float line2y = (P3[y] - P1[y]) * (P3[y] - P1[y]);

    float line3x = (P4[x] - P1[x]) * (P4[x] - P1[x]);
    float line3y = (P4[y] - P1[y]) * (P4[y] - P1[y]);

    float line4x = (P3[x] - P2[x]) * (P3[x] - P2[x]);
    float line4y = (P3[y] - P2[y]) * (P3[y] - P2[y]);

    float line5x = (P4[x] - P2[x]) * (P4[x] - P2[x]);
    float line5y = (P4[y] - P2[y]) * (P4[y] - P2[y]);

    float line6x = (P4[x] - P3[x]) * (P4[x] - P3[x]);
    float line6y = (P4[y] - P3[y]) * (P4[y] - P3[y]);


    float line1 = (float)sqrt(line1x + line1y);
    float line2 = (float)sqrt(line2x + line2y);
    float line3 = (float)sqrt(line3x + line3y);
    float line4 = (float)sqrt(line4x + line4y);
    float line5 = (float)sqrt(line5x + line5y);
    float line6 = (float)sqrt(line6x + line6y);

    RectangleLines[0] = line1;
    RectangleLines[1] = line2;
    RectangleLines[2] = line3;
    RectangleLines[3] = line4;
    RectangleLines[4] = line5;
    RectangleLines[5] = line6;

    float temp = 0;
    for (int i = 0; i < NUM_OF_SIDES - 1; i++) {
        int LowestElement = i;

        for (int j = i + 1; j < NUM_OF_SIDES; j++) {
            {
                if (RectangleLines[j] > RectangleLines[LowestElement]) {
                    LowestElement = j;
                }
            }
        }

        if (LowestElement != i) {

            temp = RectangleLines[i];
            RectangleLines[i] = RectangleLines[LowestElement];
            RectangleLines[LowestElement] = temp;
        }
    }
    printf("%.2f %.2f %.2f %.2f %.2f %.2f\n\n", RectangleLines[0], RectangleLines[1], RectangleLines[2], RectangleLines[3], RectangleLines[4], RectangleLines[5]);
}


float calculate_perimeter(float length, float width) {
    float answer = 2 * (length + width);
    return answer;
}


float calculate_area(float length, float width) {
    return length * width;
}
