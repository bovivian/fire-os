disk_load:
    pusha
    ; reading from disk requires setting specific values in all registers

    push dx ; saving value from dx since it will be overwritten

    mov ah, 0x02 ; ah <- int 0x13 function. 0x02 = 'read'
    mov al, dh   ; al <- number of sectors to read (0x01 .. 0x80)
    mov cl, 0x02 ; cl <- sector (0x01 .. 0x11)
                 ; 0x01 is our boot sector, 0x02 is the first 'available' sector
    mov ch, 0x00 ; ch <- cylinder
    ; dl <- drive number. Set in bootsect.asm and got from BIOS
    ; (0 = floppy, 1 = floppy2, 0x80 = hdd, 0x81 = hdd2)
    mov dh, 0x00 ; dh <- head number

    ; [es:bx] <- pointer to buffer where the data will be stored
    int 0x13      ; BIOS interrupt for reading the disk
    jc disk_error ; if error (error is stored in the carry bit)

    pop dx
    cmp al, dh    ; BIOS also sets 'al' to the number of sectors that were read so we can compare it
    jne sectors_error ; and check for error
    popa
    ret

disk_error:
    mov bx, DISK_ERROR_MSG
    call print
    call print_nl
    mov dh, ah ; ah = error code, dl = disk drive that dropped the error
    call print_hex ; http://stanislavs.org/helppc/int_13-1.html
    jmp disk_loop

sectors_error:
    mov bx, SECTORS_ERROR_MSG
    call print

disk_loop:
    jmp $

DISK_ERROR_MSG: db "Reading the disk error", 0
SECTORS_ERROR_MSG: db "Wrong number of sectors read error", 0
