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
    bool program = true;;

    while (program) {
       
        program = MainMenu(program);
    }

    return 0;
}

  