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
                exit(EXIT_FAILURE);
            }
            continue;
        }

        fprintf(stderr, "Invalid Input: Non-numeric character\n");
        exit(EXIT_FAILURE);
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

char * is_it_triangle(float sideA_float,float sideB_float,float sideC_float) {
    if (sideA_float + sideB_float > sideC_float && sideB_float + sideC_float > sideA_float && sideA_float + sideC_float > sideB_float) {
        return "This is a triangle";
    }
    else {
        return "This is a not triangle";
    }
}


double clamp(double value, double min, double max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

void calculate_angles(float sideA_float, float sideB_float, float sideC_float, double* angle_A, double* angle_B, double* angle_C) {
  
    double cos_A = (sideB_float * sideB_float + sideC_float * sideC_float - sideA_float * sideA_float) / (2 * sideB_float * sideC_float);
    double cos_B = (sideA_float * sideA_float + sideC_float * sideC_float - sideB_float * sideB_float) / (2 * sideA_float * sideC_float);
    double cos_C = (sideA_float * sideA_float + sideB_float * sideB_float - sideC_float * sideC_float) / (2 * sideA_float * sideB_float);

    cos_A = clamp(cos_A, -1.0, 1.0);
    cos_B = clamp(cos_B, -1.0, 1.0);
    cos_C = clamp(cos_C, -1.0, 1.0);

    *angle_A = acos(cos_A) * 180.0 / PI;
    *angle_B = acos(cos_B) * 180.0 / PI;
    *angle_C = acos(cos_C) * 180.0 / PI;


    printf("The angles of the triangle are: A = %.2f, B = %.2f, C = %.2f\n", *angle_A, *angle_B, *angle_C);
}



// RECTANGLE FUNCTIONS

/*
bool is_valid_input(char* input) {
    int dot_counter = 0;
    int length = strlen(input);


    if (length == 0) {
        printf("Invalid Input: Empty input\n");
        return false;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < length; i++) {
        if (isdigit(input[i])) {
            continue;
        }
        if ((i == 0) && (input[i] == '+' || input[i] == '-')) {
            continue;
        }
        if (input[i] == '.') {
            dot_counter++;
            if (dot_counter > 1) {
                printf("Invalid Input: More than one decimal point\n");
                return false;
                exit(EXIT_FAILURE);
            }
            continue;
        }
        printf("Invalid Input: Non-numeric character\n");
        return false;
        exit(EXIT_FAILURE);
    }

    return true;
}
float get_valid_input(char* prompt) {
    char input[NUMLIMIT];
    float value;
    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        if (is_valid_input(input)) {
            value = (float)atof(input);
            break;
        }
        else {
            printf("Invalid input. Please enter a valid number.\n");
        }
    }
    return value;
}



void RectangleFunction(float P1[COORD_LIMIT], float P2[COORD_LIMIT], float P3[COORD_LIMIT], float P4[COORD_LIMIT]) {
    // THIS FUNCTION NEEDS TO BE FIXED

    printf("\nP1: (%f,%f)\n", P1[x], P1[y]);
    printf("\nP2: (%f,%f)\n", P2[x], P2[y]);
    printf("\nP3: (%f,%f)\n", P3[x], P3[y]);
    printf("\nP4: (%f,%f)\n", P4[x], P4[y]);



    float line1 = P1[x] - P2[x];
    if ((P2[x] - P1[x]) > line1) {
        line1 = P2[x] - P1[x];
    }
    else if ((P2[y] - P1[y]) > line1) {
        line1 = P2[y] - P1[y];
    }


    printf("Line 1: %f\n\n", line1);


    float line2 = P1[x] - P3[x];
    if ((P3[x] - P1[x]) > line2) {
        line2 = P3[x] - P1[x];
    }

    else if ((P3[y] - P1[y]) > line2) {
        line2 = P3[y] - P1[y];
    }
    else if ((P1[y] - P3[y]) > line2) {
        line2 = P1[y] - P3[y];
    }

    printf("Line 2: %f\n\n", line2);


    float line3 = P4[x] - P1[x];
    if ((P1[x] - P4[x]) > line3) {
        line3 = P1[x] - P4[x];
    }
    else if ((P1[y] - P4[y]) > line3) {
        line3 = P1[y] - P4[y];
    }
    else if ((P4[y] - P1[y]) > line3) {
        line3 = P4[y] - P1[y];
    }
    printf("Line 3: %f\n\n", line3);


    float line4 = P2[x] - P3[x];
    if ((P3[x] - P2[x]) > line4) {
        line4 = P3[x] - P2[x];
    }
    else if ((P3[y] - P2[y]) > line4) {
        line4 = P3[y] - P2[y];
    }
    else if ((P2[y] - P3[y]) > line4) {
        line4 = P2[y] - P3[y];
    }


    printf("Line 4: %f\n\n", line4);


    float line5 = P2[x] - P4[x];
    if ((P4[x] - P2[x]) > line5) {
        line5 = P4[x] - P2[x];
    }
    else if ((P4[y] - P2[y]) > line5) {
        line5 = P4[y] - P2[y];
    }
    else if ((P2[y] - P4[y]) > line5) {
        line5 = P2[y] - P4[y];
    }
    printf("Line 5: %f\n\n", line5);


    float line6 = P3[x] - P4[x];
    if ((P4[x] - P3[x]) > line6) {
        line6 = P4[x] - P3[x];
    }
    else if ((P4[y] - P3[y]) > line6) {
        line6 = P4[y] - P3[y];
    }
    else if ((P3[y] - P4[y]) > line6) {
        line6 = P3[y] - P4[y];
    }
    printf("Line 6: %f\n\n", line6);

    int lines[MAX_LINES] = { line1, line2, line3, line4, line5, line6 };



    return true;




    float Q1[COORD_LIMIT] = { P1[x],P1[y] };
    float Q2[COORD_LIMIT] = { P2[x],P2[y] };
    float Q3[COORD_LIMIT] = { P3[x],P3[y] };
    float Q4[COORD_LIMIT] = { P4[x],P4[y] };


    // Largest Y Value 
    float LargestY = Q1[y];

    if (LargestY < Q2[y]) {
        LargestY = Q2[y];
    }

    if (LargestY < Q3[y]) {
        LargestY = Q3[y];
    }

    if (LargestY < Q4[y]) {
        LargestY = Q4[y];
    }

    printf("The largest y is: %f\n", LargestY);


    // Lowest Y Value 
    float LowestY = Q1[y];

    if (LowestY > Q2[y]) {
        LowestY = Q2[y];
    }

    if (LowestY > Q3[y]) {
        LowestY = Q3[y];
    }

    if (LowestY > Q4[y]) {
        LowestY = Q4[y];
    }

    printf("The Lowest y is: %f\n", LowestY);

 
    // Largest X Value 
    float LargestX = Q1[x];

    if (LargestX < Q2[x]) {
        LargestX = Q2[x];
    }

    if (LargestX < Q3[x]) {
        LargestX = Q3[x];
    }

    if (LargestX < Q4[x]) {
        LargestX = Q4[x];
    }

    printf("The largest x is: %f\n", LargestX);

    // Lowest X Value 
    float LowestX = Q1[x];

    if (LowestX > Q2[x]) {
        LowestX = Q2[x];
    }

    if (LowestX > Q3[x]) {
        LowestX = Q3[x];
    }

    if (LowestX > Q4[x]) {
        LowestX = Q4[x];
    }

    printf("The largest x is: %f\n", LowestX);


    float BL[2] = { LowestX, LowestY };
    float TL[2] = { LowestX, LargestY };
    float BR[2] = { LargestX, LowestY };
    float TR[2] = { LargestX, LargestY };

    // BL and TL Share x values
    // BL and BR Share y values
    // BR and TR share x values
    // TR and TL share y values

    printf("Bottom Left: %f, %f\n", LowestX, LowestY);
    printf("Top Left: %f, %f\n", LowestX, LargestY);
    printf("Bottom Right: %f, %f\n", LargestX, LargestY);
    printf("Top Right: %f, %f\n", LargestX, LowestY);

    if (BL[x] == TL[x] && BL[y] == TL[y]) {
        printf("This is not a triangle\n");
    }
    else if (BL[x] == BR[x] && BL[y] == BR[y]) {
        printf("This is not a triangle\n");
    }
    else if (TR[x] == BR[x] && TR[y] == BR[y]) {
        printf("This is not a triangle\n");
    }
    else if (TR[x] == TL[x] && TR[y] == BR[y]) {
        printf("This is not a triangle\n");
    }
    else {

        if (BL[x] == TL[x] && BL[y] == BR[y] && BR[x] == TR[x] && TR[y] == TL[y]) {

            printf("This is a rectangle\n");
        }

        else {

            printf("This is not a triangle\n");
        }
    }

    
    float squareOfLengthTLX = (BL[0] - TL[0]) * (BL[0] - TL[0]);
    float squareOfLengthBLY = (BL[1] - TL[1]) * (BL[1] - TL[1]);
    float squareOfWidthBRX = (BR[0] - BL[0]) * (BR[0] - BL[0]);
    float squareOfWidthBRY = (BR[1] - BL[1]) * (BR[1] - BL[1]);


    float length = sqrt(squareOfLengthTLX + squareOfLengthBLY);

    float width = sqrt(squareOfWidthBRX + squareOfWidthBRY);

    

}

float perimeter(float length, float width) {

    float perimeter = 2 * (length + width);
    return perimeter;

}


float area(float length, float width) {

    float area = length * width;
    return area;

}


bool GetRectangleInput(bool program) {

    float point1 = get_valid_input("Enter point1 (x): ");
    float point2 = get_valid_input("Enter point2 (y): ");
    float point3 = get_valid_input("Enter point3 (x): ");
    float point4 = get_valid_input("Enter point4 (y): ");
    float point5 = get_valid_input("Enter point5 (x): ");
    float point6 = get_valid_input("Enter point6 (y): ");
    float point7 = get_valid_input("Enter point7 (x): ");
    float point8 = get_valid_input("Enter point8 (y): ");
    
    float corner1[2] = { point1, point2 };
    float corner2[2] = { point3, point4 };
    float corner3[2] = { point5, point6 };
    float corner4[2] = { point7, point8 };
    
    RectangleFunction(corner1, corner2, corner3, corner4);
}



// MENU FUNCTION

bool MainMenu(bool program) {

    // Initialize
    int choice = 0;

    // Get Input
    printf("\nMenu:\n1. Triangle Feature\n2. Rectangle Feature\n3. Exit\n");
    printf("Enter your choice: ");
    int userChoice = scanf("%d", &choice);




    // MENU FUNCTION
    switch (choice)
    {
    case 1:
        printf("Tri\n\n");
        program = get_triangle_input(program);
        return program;
    case 2:
        program = GetRectangleInput(program);
        return program;
    case 3:
        program = false;
        return program;

    default:
        printf("Invalid choice. Try again.\n");
        program = false;
        return program;
    }
}
*/