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
    char sideA[NUMLIMIT], sideB[NUMLIMIT], sideC[NUMLIMIT];
    float sideA_float, sideB_float, sideC_float;
    double angle_A, angle_B, angle_C;

    int choice;
    while (1) {
        printf("\nMenu:\n1. Triangle Feature\n2. Rectangle Feature\n3. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        if (choice == 1) {
            get_triangle_input(sideA, sideB, sideC);

int main() {
    bool program = true;;

    while (program) {
       
        program = MainMenu(program);
    }

    return 0;
}