#include "header.h"

t_map *mx_build_map(char **map_text) {
	t_map *map = malloc(sizeof(t_map));
	map->width = 0;
	map->height = 0;
	
	// Map error handling
	for (char **i = map_text; *i != NULL; i++) {
		if (map->width == 0) map->width = mx_strlen(*i);
		else
			if (map->width != mx_strlen(*i)) {
				mx_printerr("map error\n");
				exit(0);
			}
		map->height++;
	}
	map->dots = malloc(sizeof(int*)*map->height);
	
	for (int j = 0; j < map->height; j++) {
		map->dots[j] = malloc(sizeof(int)*map->width);
		
		for (int k = 0; k < map->width; k++)
		    if (map_text[j][k] == '#') map->dots[j][k] = -2;
			else if (map_text[j][k] == '.') map->dots[j][k] = -1;
	}
	
	return map;
}

