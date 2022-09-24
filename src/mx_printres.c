#include "header.h"

void mx_printres(t_map map, int x2, int y2, char *path, char *res) {
    mx_printstr("dist=");
	mx_printint(mx_most_distant(&map));
	mx_printchar('\n');
	mx_printstr("exit=");
	mx_printint(mx_exit_distance(&map, x2, y2));
	mx_printchar('\n');
	
	int path_file = open(path, O_RDONLY);
	
	path_file = open(path, O_WRONLY | O_CREAT);
	write(path_file, res, mx_strlen(res));
    close(path_file);
}

