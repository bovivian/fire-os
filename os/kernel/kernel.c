#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include "../libc/string.h"
#include "user_input_helpers.h"

void main() {
    isr_install();
    irq_install();

    clear_screen();
    kprint("Hello, you're in FireOS\n");

    kprint("You are now in a simple CLI. Type something!\n"
        "Type end to finish\n>");
}

void user_input(char *input) {
    if (strcmp(input, "END") == 0 || strcmp(input, "end") == 0) {
        kprint("Halting the CPU.\n");
        asm volatile("hlt");
    }
    if (strcmp(input, "clear") == 0) {
	   clear_screen();
    }
    if (strcmp(input, "ROCKET") == 0 || strcmp(input, "rocket") == 0) {
	   print_rocket();
    }
    if (strstr(".REVERSE", input) || strstr(".reverse", input)) {
        reverse_str(input);
    }
    // TODO: add better validation for this
    if (strstr("+", input) || strstr("-", input)) {
        calculator(input);
    }
    kprint("Result: ");
    kprint(input);
    kprint("\n> ");
}
