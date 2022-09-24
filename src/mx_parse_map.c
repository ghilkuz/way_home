#include "header.h"

char *mx_parse_map(t_map *map, int x1, int y1, int x2, int y2) {
	mx_wave_func(&map, x1, y1, 0);
	t_map *path = NULL;
	
	if(!mx_is_path_building(map, &path, x2, y2, 0)) return NULL;
	int dist = mx_most_distant(map);
	char *res = mx_strnew(0);
	
	for (int i = 0; i < map->height; i++) {
		for (int j = 0; j < map->width; j++)
		    if (map->dots[i][j] == -2) res = mx_strappend(res, '#');
			else if (map->dots[i][j] == -1) res = mx_strappend(res, '.');
			else
				if (map->dots[i][j] == dist)
					if (path->dots[i][j] == 1) res = mx_strappend(res, 'X');
					else res = mx_strappend(res, 'D');
				else
					if (path->dots[i][j] == 1) res = mx_strappend(res, '*');
					else res = mx_strappend(res, '.');
			
		res = mx_strappend(res, '\n');
	}
	return res;
}

