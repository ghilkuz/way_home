#include "header.h"

char *mx_strappend(char *str, char symb) {
	int size = mx_strlen(str) + 1;
	char *s = mx_strnew(size);
	
	for (int i = 0; i < size; i++) {
		if(i == size - 1)
			s[i] = symb;
		else 
			s[i] = str[i];
	}
	
	return s;
}

