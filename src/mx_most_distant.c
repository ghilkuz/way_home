#include "header.h"

int mx_most_distant(t_map *map) {
	int dist = -1;
	
	for (int i = 0; i < map->height; i++)
		for (int j = 0; j < map->width; j++)
			if (map->dots[i][j] > dist)
				dist = map->dots[i][j];
				
	return dist;
}

