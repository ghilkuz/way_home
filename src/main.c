#include "header.h"

int main(int argc, char *argv[]) {
	// Invalid number of arguments error handling
	if (argc != 6) {
		mx_printerr("usage: ");
		mx_printerr(argv[0]);
		mx_printerr(" [file_name] [x1] [y1] [x2] [y2]\n");
		exit(0);
	}
	int x1 = mx_atoi(argv[2]);
	int y1 = mx_atoi(argv[3]);
	int x2 = mx_atoi(argv[4]);
	int y2 = mx_atoi(argv[5]);
	char *map_file = mx_open_file(argv[1]);
	char **process_text = mx_parse_text(map_file);
	t_map *map = mx_build_map(process_text);
	
	// Other errors handlings
	if (x1 < 0 || x1 >= map->width || y1 < 0 || y1 >= map->height 
	    || x2 < 0 || x2 >= map->width || y2 < 0 || y2 >= map->height) {
		mx_printerr("points are out of map range\n");
		exit(0);
	}
	if (map->dots[y1][x1] == -2) {
		mx_printerr("entry point cannot be an obstacle\n");
		exit(0);
    }
	if (map->dots[y2][x2] == -2) {
		mx_printerr("exit point cannot be an obstacle\n");
		exit(0);
	}
	char *res = mx_parse_map(map, x1, y1, x2, y2);
	
	if (res == NULL) {
		mx_printerr("route not found\n");
		exit(0);
	}
	
	// Call function that prints result
	mx_printres(*map, x2, y2, "path.txt", res);
	return 0;
}
