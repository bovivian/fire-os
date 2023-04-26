#include "keyboard.h"
#include "../cpu/ports.h"
#include "../cpu/isr.h"
#include "screen.h"
#include "../libc/string.h"
#include "../libc/function.h"
#include "../kernel/kernel.h"

// Implementation upper and lower case 
u16 capslock_on = 0;
// Delete only what the user has written
u32 cmd_start = 0;

static char key_buffer[256];

#define SC_MAX 57

static void keyboard_callback(registers_t regs) {
    /* The PIC leaves us the scancode in port 0x60 */
    u8 scancode = port_byte_in(0x60);
    
    if (scancode > SC_MAX) return;
    if (scancode == KEY_BACKSPACE) {
        if(cmd_start > 0){
            backspace(key_buffer);
            kprint_backspace();
            cmd_start--;
        }
    } else if (scancode == KEY_ENTER) {
        cmd_start = 0;
        kprint("\n");
        user_input(key_buffer); /* kernel-controlled function */
        key_buffer[0] = '\0';
    } else if (scancode == KEY_LSHIFT) { // CAPSLOCK dont work ???
        if (capslock_on) {
            capslock_on = 0;
        } else {
            capslock_on = 1;
        }
        /* TODO: upper case print with shift or capslock */
    } else {
        char letter = get_ascii_char(scancode, capslock_on);
        /* Remember that kprint only accepts char[] */
        char str[2] = {letter, '\0'};
        append(key_buffer, letter);
        kprint(str);
        cmd_start++;
    }
    UNUSED(regs);
}

void init_keyboard() {
   register_interrupt_handler(IRQ1, keyboard_callback); 
}
