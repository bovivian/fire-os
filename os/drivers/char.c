#include "char.h"

char get_ascii_char(u8 key_code, u16 upperCase)
{
    switch(key_code){
        case KEY_A : if(upperCase) {return 'A';} else{return 'a';};
        case KEY_B : if(upperCase) {return 'B';} else{return 'b';};
        case KEY_C : if(upperCase) {return 'C';} else{return 'c';};
        case KEY_D : if(upperCase) {return 'D';} else{return 'd';};
        case KEY_E : if(upperCase) {return 'E';} else{return 'e';};
        case KEY_F : if(upperCase) {return 'F';} else{return 'f';};
        case KEY_G : if(upperCase) {return 'G';} else{return 'g';};
        case KEY_H : if(upperCase) {return 'H';} else{return 'h';};
        case KEY_I : if(upperCase) {return 'I';} else{return 'i';};
        case KEY_J : if(upperCase) {return 'J';} else{return 'j';};
        case KEY_K : if(upperCase) {return 'K';} else{return 'k';};
        case KEY_L : if(upperCase) {return 'L';} else{return 'l';};
        case KEY_M : if(upperCase) {return 'M';} else{return 'm';};
        case KEY_N : if(upperCase) {return 'N';} else{return 'n';};
        case KEY_O : if(upperCase) {return 'O';} else{return 'o';};
        case KEY_P : if(upperCase) {return 'P';} else{return 'p';};
        case KEY_Q : if(upperCase) {return 'Q';} else{return 'q';};
        case KEY_R : if(upperCase) {return 'R';} else{return 'r';};
        case KEY_S : if(upperCase) {return 'S';} else{return 's';};
        case KEY_T : if(upperCase) {return 'T';} else{return 't';};
        case KEY_U : if(upperCase) {return 'U';} else{return 'u';};
        case KEY_V : if(upperCase) {return 'V';} else{return 'v';};
        case KEY_W : if(upperCase) {return 'W';} else{return 'w';};
        case KEY_X : if(upperCase) {return 'X';} else{return 'x';};
        case KEY_Y : if(upperCase) {return 'Y';} else{return 'y';};
        case KEY_Z : if(upperCase) {return 'Z';} else{return 'z';};
        case KEY_1 : return '1';
        case KEY_2 : return '2';
        case KEY_3 : return '3';
        case KEY_4 : return '4';
        case KEY_5 : return '5';
        case KEY_6 : return '6';
        case KEY_7 : return '7';
        case KEY_8 : return '8';
        case KEY_9 : return '9';
        case KEY_0 : return '0';
        case KEY_MINUS : return '-';
        case KEY_PLUS : return '+';
        case KEY_SQUARE_OPEN_BRACKET : return '[';
        case KEY_SQUARE_CLOSE_BRACKET : return ']';
        case KEY_SEMICOLON : return ';';
        case KEY_BACKSLASH : return '\\';
        case KEY_COMMA : return ',';
        case KEY_DOT : return '.';
        case KEY_FORESLHASH : return '/';
        case KEY_SPACE : return ' ';
        default : return 0;
    }
}
