[org 0x7c00] ; set bootsector address to avoid having to count the offset manually
KERNEL_ADDR equ 0x1000 ; the address is the same that in makefile when linking the kernel
    ; BIOS sets us the boot drive in 'dl' on boot, since 'dl' may be overwritten, we store it in the constant
    mov [BOOT], dl
    mov bp, 0x9000
    mov sp, bp

    call load_kernel ; reading kernel from disk
    call switch_to_protected_mode ; switching to 32 bit mode
    jmp $

%include "boot/print.asm"
%include "boot/print_hex.asm"
%include "boot/disk_loading.asm"
%include "boot/gdt.asm"
%include "boot/switch_protected_mode.asm"

[bits 16]
load_kernel:
    mov bx, KERNEL_ADDR ; read from disk and store in 0x1000
    mov dh, 16 ; make a lot of place for kernel
    mov dl, [BOOT]
    call disk_load
    ret

[bits 32]
PROTECTED_MODE:
    call KERNEL_ADDR ; give control to kernel
    jmp $

BOOT db 0

; magic number
times 510 - ($-$$) db 0
dw 0xaa55
