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
            // GetRectangleInput(true); need to debug
        }

        else if (choice == 3) {
            break;
        }
    }
    return 0;
}
