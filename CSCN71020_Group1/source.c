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
    double angle_A, angle_B, angle_C;
    while (1) {
        printf("\nMenu:\n1. Triangle Feature\n2. Rectangle Feature\n3. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);
        if (choice == 1) {
            get_triangle_input(sideA,sideB,sideC);
			sideA_float = (float)atof(sideA);
			sideB_float = (float)atof(sideB);
			sideC_float = (float)atof(sideC);
			if (is_it_triangle(sideA_float, sideB_float, sideC_float) == "This is a triangle") {
				printf("This is a triangle\n");
				calculate_angles(sideA_float, sideB_float, sideC_float, &angle_A, &angle_B, &angle_C);
                }
            else {
				printf("This is not a triangle\n");
				return 1;
            }
        }
        else if (choice == 2) {
            float point1 = get_valid_input("Enter point1 (x): ");
            float point2 = get_valid_input("Enter point2 (y): ");
            float point3 = get_valid_input("Enter point3 (x): ");
            float point4 = get_valid_input("Enter point4 (y): ");
            float point5 = get_valid_input("Enter point5 (x): ");
            float point6 = get_valid_input("Enter point6 (y): ");
            float point7 = get_valid_input("Enter point7 (x): ");
            float point8 = get_valid_input("Enter point8 (y): ");

            float corner1[COORD_LIMIT] = { point1, point2 };
            float corner2[COORD_LIMIT] = { point3, point4 };
            float corner3[COORD_LIMIT] = { point5, point6 };
            float corner4[COORD_LIMIT] = { point7, point8 };

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
