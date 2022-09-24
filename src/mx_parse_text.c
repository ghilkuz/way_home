#include "header.h"

char **mx_parse_text(char *text){
	int height = 0;
	for (char *i = text; *i != '\0'; i++)
		if (*i == '\n') height++;
    
    char *s = mx_strnew(0);
	char **ps = malloc(sizeof(char*)*(height + 1));
	int k = 0;
	
	for (char *j = text; *j != '\0'; j++) {
		if (*j == '\n') {
			ps[k++] = s; 
			s = mx_strnew(0);
		}
		else if (*j == '#' || *j == '.')
		    s = mx_strappend(s, *j);
	}
	ps[k] = NULL;
	return ps;
}

