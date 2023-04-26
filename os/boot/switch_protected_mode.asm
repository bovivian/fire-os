[bits 16]
switch_to_protected_mode:
    cli ; clear interrupts instruction to disable interrupts
    lgdt [gdt_descriptor] ; instruction to load gdt descriptor
    mov eax, cr0
    or eax, 0x1 ; setting protected mode bit in cr0
    mov cr0, eax
    jmp CODE_SEG:changed_to_protected_mode ; far jump to flush cpu pipelines

[bits 32]
changed_to_protected_mode:
    mov ax, DATA_SEG ; segment registers must be updated
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov ebp, 0x90000 ; updating the stack
    mov esp, ebp

    call PROTECTED_MODE ; calling label from bootsect.asm file
