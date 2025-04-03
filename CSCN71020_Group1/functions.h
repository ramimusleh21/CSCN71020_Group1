#pragma once
#include "globals.h"


// MENU FUNCTION



// TRIANGLE FUNCTIONS
void get_triangle_input(char* sideA, char* sideB, char* sideC);
char* get_input(const char* prompt);
bool validate_triangle_input(char* side);
char* is_it_triangle(float sideA_float, float sideB_float, float sideC_float);
double clamp(double value, double min, double max);
double calculate_angles(float sideA_float, float sideB_float, float sideC_float, double* angle_A, double* angle_B, double* angle_C);

// RECTANGLE FUNCTIONS

void clear_input_buffer();
void get_rectangle_input(char* point1, char* point2, char* point3, char* point4, char* point5, char* point6, char* point7, char* point8);
//void get_valid_floats(float* inputs, int num_inputs);
int IsitRectangle(float RectangleLines[NUM_OF_SIDES]);
void calculate_distances(float P1[COORD_LIMIT], float P2[COORD_LIMIT], float P3[COORD_LIMIT], float P4[COORD_LIMIT], float RectangleLines[NUM_OF_SIDES]);
float calculate_perimeter(float length, float width);
float calculate_area(float length, float width);
