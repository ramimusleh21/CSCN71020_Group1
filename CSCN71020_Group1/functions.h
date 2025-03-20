#pragma once
#include "globals.h"


// MENU FUNCTION
bool MainMenu(bool program);



// TRIANGLE FUNCTIONS
bool validate_triangle_input(char* side);

bool get_triangle_input(bool program);

bool is_valid_input(char* input);

float get_valid_input(char* prompt);




// RECTANGLE FUNCTIONS

bool GetRectangleInput(bool program);

void RectangleFunction(float P1[COORD_LIMIT], float P2[COORD_LIMIT], 
    float P3[COORD_LIMIT], float P4[COORD_LIMIT]);

int IsitRectangle(float RectangleLines[NUM_OF_SIDES]);

float perimeter(float length, float width);
float area(float length, float width);
