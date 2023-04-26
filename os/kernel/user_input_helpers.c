#include "../drivers/screen.h"
#include "../libc/string.h"
#include "user_input_helpers.h"

void print_rocket() {
    kprint("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    kprint("            /\\\n");
    kprint("           /  \\\n");
    kprint("          /____\\\n");
    kprint("          |    |\n");
    kprint("          |    |\n");
    kprint("          |@@@@|\n");
    kprint("          |    |\n");
    kprint("          |    |\n");
    kprint("          |____|\n");
    kprint("             *\n");
    kprint("              *\n");
    kprint("              <*>\n");
    
    int i = 0;
    int j = 0;
    
    for (j = 0; j < 15; j++)
    {
	//Delaying the movement
	for(i = 0; i < 10000000; i++)
	{

	}
	//Moves the drawing upward since the cursor is at the end of the console
	kprint("\n");
    }
    
    clear_screen();
}

char *reverse_str(char *input) {
    del_str_part(input, ".");
    reverse(input);
    return input;
}

void calculator(char *input) {
    int num1 = 0;
    int num2 = 0;
    int result = 0;
    int i = 0;

    int flag_if_num2 = 0;

    enum operations op;

    for (i; input[i] != '\0'; ++i) {
        if (input[i] == '+') {
            flag_if_num2 = 1;
            op = PLUS;
            continue;
        }
        if (input[i] == '-') {
            flag_if_num2 = 1;
            op = MINUS;
            continue;
        }
        if (!flag_if_num2) {
            num1 = num1 * 10 + input[i] - '0';
        }
        else {
            num2 = num2 * 10 + input[i] - '0';
        }
    }

    if (op == PLUS) {
        result = num1 + num2;
    }
    if (op == MINUS) {
        result = num1 - num2;
    }

    int_to_ascii(result, input);
}
