#include "header.h"

char *mx_open_file(char *path) {
	int map_file = open(path, O_RDWR);
	
	// Check if map can be used
	if (map_file < 0) {
		mx_printerr("map does not exist\n");
		exit(0);
	}
	char c;
	int ref = 0;
	char *res = mx_strnew(0);
	
	while ((ref = read(map_file, &c, 1)) > 0) {
		if (ref < 0) {
			mx_printerr("map does not exist\n");
			exit(0);
		}
		
		if (c != '#' && c != ',' && c != '.' && c != '\n') {
			mx_printerr("map error\n");
			exit(0);
		}
		else if (c != '\r') res = mx_strappend(res, c);
	}
	
	close(map_file);
	return res;
}

