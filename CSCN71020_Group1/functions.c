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
                exit(EXIT_FAILURE);
            }
            continue;
        }
        printf("Invalid Input: Non-numeric character\n");
        exit(EXIT_FAILURE);
    }

    return true;
}


char* get_input(const char* prompt) {
    static char input[NUMLIMIT];
    printf("%s", prompt);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character
    return input;
}

float get_valid_input(char* prompt) {
    char input[NUMLIMIT];
    float value = 0;
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

    // ***
    printf("\nP1: (%f,%f)\n", P1[x], P1[y]);
    printf("\nP2: (%f,%f)\n", P2[x], P2[y]);
    printf("\nP3: (%f,%f)\n", P3[x], P3[y]);
    printf("\nP4: (%f,%f)\n", P4[x], P4[y]);


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


    float line1 = sqrt(line1x + line1y);
    float line2 = sqrt(line2x + line2y);
    float line3 = sqrt(line3x + line3y);
    float line4 = sqrt(line4x + line4y);
    float line5 = sqrt(line5x + line5y);
    float line6 = sqrt(line6x + line6y);

    float RectangleLines[NUM_OF_SIDES] = { line1, line2, line3, line4, line5, line6 };


    printf("%f %f %f %f %f %f\n\n", RectangleLines[0], RectangleLines[1], RectangleLines[2], RectangleLines[3], RectangleLines[4], RectangleLines[5]);

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
            RectangleLines[LowestElement] =temp;
        }
    }
    printf("%f %f %f %f %f %f\n\n", RectangleLines[0], RectangleLines[1], RectangleLines[2], RectangleLines[3], RectangleLines[4], RectangleLines[5]);
    
   IsitRectangle(RectangleLines);

   //Add logic that only runs these functions if it is
   // a rectangle

   float length = RectangleLines[2];
   float width = RectangleLines[4];


       float perimeter = 2 * (length + width);

       printf("The perimeter is %f\n", perimeter);

       float area = length * width;
       printf("The area is %f\n", area);
    
    // ***



    //float Q1[COORD_LIMIT] = { P1[x],P1[y] };
    //float Q2[COORD_LIMIT] = { P2[x],P2[y] };
    //float Q3[COORD_LIMIT] = { P3[x],P3[y] };
    //float Q4[COORD_LIMIT] = { P4[x],P4[y] };


    //// Largest Y Value 
    //float LargestY = Q1[y];

    //if (LargestY < Q2[y]) {
    //    LargestY = Q2[y];
    //}

    //if (LargestY < Q3[y]) {
    //    LargestY = Q3[y];
    //}

    //if (LargestY < Q4[y]) {
    //    LargestY = Q4[y];
    //}

    //printf("The largest y is: %f\n", LargestY);


    //// Lowest Y Value 
    //float LowestY = Q1[y];

    //if (LowestY > Q2[y]) {
    //    LowestY = Q2[y];
    //}

    //if (LowestY > Q3[y]) {
    //    LowestY = Q3[y];
    //}

    //if (LowestY > Q4[y]) {
    //    LowestY = Q4[y];
    //}

    //printf("The Lowest y is: %f\n", LowestY);

 
    //// Largest X Value 
    //float LargestX = Q1[x];

    //if (LargestX < Q2[x]) {
    //    LargestX = Q2[x];
    //}

    //if (LargestX < Q3[x]) {
    //    LargestX = Q3[x];
    //}

    //if (LargestX < Q4[x]) {
    //    LargestX = Q4[x];
    //}

    //printf("The largest x is: %f\n", LargestX);

    //// Lowest X Value 
    //float LowestX = Q1[x];

    //if (LowestX > Q2[x]) {
    //    LowestX = Q2[x];
    //}

    //if (LowestX > Q3[x]) {
    //    LowestX = Q3[x];
    //}

    //if (LowestX > Q4[x]) {
    //    LowestX = Q4[x];
    //}

    //printf("The largest x is: %f\n", LowestX);


    //float BL[2] = { LowestX, LowestY };
    //float TL[2] = { LowestX, LargestY };
    //float BR[2] = { LargestX, LowestY };
    //float TR[2] = { LargestX, LargestY };

    //// BL and TL Share x values
    //// BL and BR Share y values
    //// BR and TR share x values
    //// TR and TL share y values

    //printf("Bottom Left: %f, %f\n", LowestX, LowestY);
    //printf("Top Left: %f, %f\n", LowestX, LargestY);
    //printf("Bottom Right: %f, %f\n", LargestX, LargestY);
    //printf("Top Right: %f, %f\n", LargestX, LowestY);

    //if (BL[x] == TL[x] && BL[y] == TL[y]) {
    //    printf("This is not a triangle\n");
    //}
    //else if (BL[x] == BR[x] && BL[y] == BR[y]) {
    //    printf("This is not a triangle\n");
    //}
    //else if (TR[x] == BR[x] && TR[y] == BR[y]) {
    //    printf("This is not a triangle\n");
    //}
    //else if (TR[x] == TL[x] && TR[y] == BR[y]) {
    //    printf("This is not a triangle\n");
    //}
    //else {

    //    if (BL[x] == TL[x] && BL[y] == BR[y] && BR[x] == TR[x] && TR[y] == TL[y]) {

    //        printf("This is a rectangle\n");
    //    }

    //    else {

    //        printf("This is not a triangle\n");
    //    }
    //}

    //
    //float squareOfLengthTLX = (BL[x] - TL[x]) * (BL[x] - TL[x]);
    //float squareOfLengthBLY = (BL[y] - TL[y]) * (BL[y] - TL[y]);
    //float squareOfWidthBRX = (BR[x] - BL[x]) * (BR[x] - BL[x]);
    //float squareOfWidthBRY = (BR[y] - BL[y]) * (BR[y] - BL[y]);


    //float length = sqrt(squareOfLengthTLX + squareOfLengthBLY);

    //float width = sqrt(squareOfWidthBRX + squareOfWidthBRY);

    //

return true;
}

float perimeter(float length, float width) {
    printf("%f %f\n", length, width);

    float perimeter = 2 * (length + width);

    printf("The perimeter is %f\n", perimeter);
    return perimeter;

}


float area(float length, float width) {
    printf("%f %f\n", length, width);

    float area = length * width;
    printf("The area is %f\n", area);
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


*/


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

char* get_input_rec(const char* prompt) {
    static char input[NUMLIMIT];
    printf("%s", prompt);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character
    return input;
}

float get_valid_input(const char* prompt) {
    char* input;
    float value = 0;
    while (1) {
        input = get_input(prompt);
        if (is_valid_input((char*)input)) {
            value = (float)atof(input);
            return value; // Return immediately if valid
        }
        else {
            printf("Invalid input. Please enter a valid number.\n");
        }
    }
}


int IsitRectangle(float RectangleLines[NUM_OF_SIDES]) {

    if (RectangleLines[0] != RectangleLines[3]) {
        printf("This is Not a Rectangle: Opposite sides are not equal\n");
        return 1;
    }
    if (RectangleLines[1] != RectangleLines[4]) {
        printf("This is Not a Rectangle: Opposite sides are not equal\n");
        return 1;
    }
    if (RectangleLines[2] != RectangleLines[5]) {
        printf("This is Not a Rectangle: Opposite sides are not equal\n");
        return 1;
    }

    float diagonal1 = (float)sqrt(pow(RectangleLines[0], 2) + pow(RectangleLines[1], 2));  
    float diagonal2 = (float)sqrt(pow(RectangleLines[2], 2) + pow(RectangleLines[3], 2));  

    if (fabs(diagonal1 - diagonal2) > 0.0001) { 
        printf("This is Not a Rectangle: Diagonals are not equal\n");
        return 1;
    }

    printf("This is a Rectangle\n");
    return 0;
}

void calculate_distances(float P1[COORD_LIMIT], float P2[COORD_LIMIT], float P3[COORD_LIMIT], float P4[COORD_LIMIT], float RectangleLines[NUM_OF_SIDES]) {
    RectangleLines[0] = (float)sqrt(pow(P2[0] - P1[0], 2) + pow(P2[1] - P1[1], 2));
    RectangleLines[1] = (float)sqrt(pow(P3[0] - P1[0], 2) + pow(P3[1] - P1[1], 2)); 
    RectangleLines[2] = (float)sqrt(pow(P4[0] - P1[0], 2) + pow(P4[1] - P1[1], 2)); 
    RectangleLines[3] = (float)sqrt(pow(P3[0] - P2[0], 2) + pow(P3[1] - P2[1], 2)); 
    RectangleLines[4] = (float)sqrt(pow(P4[0] - P2[0], 2) + pow(P4[1] - P2[1], 2)); 
    RectangleLines[5] = (float)sqrt(pow(P4[0] - P3[0], 2) + pow(P4[1] - P3[1], 2)); 
}


float calculate_perimeter(float length, float width) {
    return 2 * (length + width);
}


float calculate_area(float length, float width) {
    return length * width;
}






