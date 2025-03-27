#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#include "functions.h"
#include "globals.h"


int main() {
    int choice;
    char sideA[NUMLIMIT], sideB[NUMLIMIT], sideC[NUMLIMIT];
    float sideA_float, sideB_float, sideC_float;
    double angle_A ;
    double angle_B ;
    double angle_C ;
    while (1) {
        printf("\nMenu:\n1. Triangle Feature\n2. Rectangle Feature\n3. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);
        if (choice == 1) {
            get_triangle_input(sideA, sideB, sideC);
            sideA_float = (float)atof(sideA);
            sideB_float = (float)atof(sideB);
            sideC_float = (float)atof(sideC);
            if (is_it_triangle(sideA_float, sideB_float, sideC_float) == "This is a triangle") {
                printf("This is a triangle\n");
                calculate_angles(sideA_float, sideB_float, sideC_float, &angle_A, &angle_B, &angle_C);
                printf("The angles of the triangles are %.2f and %.2f and %.2f ", angle_A, angle_B, angle_C);
            }
            else {
                printf("This is not a triangle\n");
                return 1;
            }
        }
        else if (choice == 2) {
            // GetRectangleInput(true); need to debug
            char point1[NUMLIMIT];
            char point2[NUMLIMIT];
            char point3[NUMLIMIT];
            char point4[NUMLIMIT];
            char point5[NUMLIMIT];
            char point6[NUMLIMIT];
            char point7[NUMLIMIT];
            char point8[NUMLIMIT];
           


            float rectangle_coords[8];

            get_rectangle_input(point1, point2, point3, point4, point5, point6, point7, point8);

            float point1_float = (float)atof(point1);
            float point2_float = (float)atof(point2);
            float point3_float = (float)atof(point3);
            float point4_float = (float)atof(point4);
            float point5_float = (float)atof(point5);
            float point6_float = (float)atof(point6);
            float point7_float = (float)atof(point7);
            float point8_float = (float)atof(point8);

            //get_valid_floats(rectangle_coords, 8);


            float corner1[COORD_LIMIT] = { rectangle_coords[0], rectangle_coords[1] };
            float corner2[COORD_LIMIT] = { rectangle_coords[2], rectangle_coords[3] };
            float corner3[COORD_LIMIT] = { rectangle_coords[4], rectangle_coords[5] };
            float corner4[COORD_LIMIT] = { rectangle_coords[6], rectangle_coords[7] };


            float RectangleLines[NUM_OF_SIDES];
            calculate_distances(corner1, corner2, corner3, corner4, RectangleLines);


            int isRectangle = IsitRectangle(RectangleLines);
            if (isRectangle == 0) {
                float length = RectangleLines[2];
                float width = RectangleLines[4];


                float perimeter = calculate_perimeter(length, width);
                printf("The perimeter is %.2f\n", perimeter);

                float area = calculate_area(length, width);
                printf("The area is %.2f\n", area);
            }

            return 0;
        }

        else if (choice == 3) {
            break;
        }
    }
    return 0;
}