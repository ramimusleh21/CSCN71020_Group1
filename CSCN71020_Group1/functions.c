#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#include "globals.h"


// TRIANGLE FUNCTIONS

bool validate_triangle_input(char* side) {
    int dot_counter = 0;
    int length = strlen(side);

    if (length == 0) {
        fprintf(stderr, "Invalid Input: Empty input\n");
        return false;
    }
    for (int i = 0; i < length; i++) {
        if (isdigit(side[i])) {
            continue;
        }
        else {
            fprintf(stderr, "Please Enter a Number as Input ");
            return false;
        }
        if (side[i] == '.') {
            dot_counter++;

            if (dot_counter > 1) {
                fprintf(stderr, "Invalid Input: More than one decimal point\n");
                return false;
            }
            continue;
        }

        // *** Is 0 supposed to be allowed as an input?? ***

        fprintf(stderr, "Invalid Input: Non-numeric character\n");
        return false;
    }

    return true;
}


bool get_triangle_input(bool program) {

    char sideA[NUMLIMIT];
    char sideB[NUMLIMIT];
    char sideC[NUMLIMIT];

    printf("Enter the length of the first side: ");
   int SideASymbols = scanf("%s", sideA);
    program = validate_triangle_input(sideA);
    
    if(program == false){
        return program;
    }

    printf("Enter the length of the second side: ");
    int SideBSymbols = scanf("%s", sideB);
    program = validate_triangle_input(sideB);

    if (program == false) {
        return program;
    }

    printf("Enter the length of the third side: ");
    int SideCSymbols = scanf("%s", sideC);
    program = validate_triangle_input(sideC);

    if (program == false) {
        return program;
    }


    int sideA_int = atoi(sideA);
    int sideB_int = atoi(sideB);
    int sideC_int = atoi(sideC);
    
    if (sideA_int + sideB_int > sideC_int && sideB_int + sideC_int > sideA_int && sideA_int + sideC_int > sideB_int) {
        printf("This is a triangle");
    }
    else {
        printf("This is a not triangle");
    }

    return program;
}






// RECTANGLE FUNCTIONS


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


int IsitRectangle(float RectangleLines[NUM_OF_SIDES] ) {
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