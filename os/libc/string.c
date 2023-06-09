#include "string.h"

/**
 * official implementation
 */
void int_to_ascii(int n, char str[]) {
    int i, sign;
    if ((sign = n) < 0) n = -n;
    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) str[i++] = '-';
    str[i] = '\0';

    reverse(str);
}

/* official implementation */
void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* official implementation */
int strlen(char s[]) {
    int i = 0;
    while (s[i] != '\0') ++i;
    return i;
}

void append(char s[], char n) {
    int len = strlen(s);
    s[len] = n;
    s[len+1] = '\0';
}

void backspace(char s[]) {
    int len = strlen(s);
    s[len-1] = '\0';
}

/* official implementation
 * Returns <0 if s1<s2, 0 if s1==s2, >0 if s1>s2 */
int strcmp(char s1[], char s2[]) {
    int i;
    for (i = 0; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0') return 0;
    }
    return s1[i] - s2[i];
}

/*
 * returns 0 if s1 is not a substring of s2 and 1 otherwise
*/
int strstr(char s1[], char s2[]) {
   char *p1, *p2, *p3;
   int i = 0;
   int j = 0;

   p1 = s2;
   p2 = s1;

  for(i = 0; i < strlen(s2); i++)
  {
    if(*p1 == *p2)
      {
          p3 = p1;
          for(j = 0;j<strlen(s1);j++)
          {
            if(*p3 == *p2)
            {
              p3++;p2++;
            } 
            else
              break;
          }
          p2 = s1;
          if(j == strlen(s1))
          {
             return 1;
          }
      }
    p1++; 
  }
    return 0;
}

void del_str_part(char * s, char * c) {
    char *del = &s[strlen(s)];

    while (del > s && *del != *c)
        del--;

    if (*del == *c)
        *del = '\0';

    return;
}
