#include "header.h"

// Function to check if the path can be built
bool mx_is_path_building(t_map *src, t_map **dist, int x, int y, int n) {
	if (*dist == NULL) {
		*dist = malloc(sizeof(t_map));
		(*dist)->width = src->width;
		(*dist)->height = src->height;
		(*dist)->dots = malloc(sizeof(int*)*src->height);
		
		for (int i = 0; i < src->height; i++) {
			(*dist)->dots[i] = malloc(sizeof(int)*src->width);
			for (int j = 0; j < src->width; j++) (*dist)->dots[i][j] = 0;
		}
		n = src->dots[y][x];
		if (src->dots[y][x] < 0) return false;
		(*dist)->dots[y][x] = 1;
	}
	
	if (src->dots[y][x] == 0) {
		(*dist)->dots[y][x] = 1;
		return true;
	}
	
	// x-variable handling
	if (x - 1 >= 0 && src->dots[y][x - 1] == n - 1) {
		(*dist)->dots[y][x - 1] = 1;
		return mx_is_path_building(src, dist, x - 1, y, n - 1);
	}
	
	if (x + 1 < src->width && src->dots[y][x + 1] == n - 1) {
		(*dist)->dots[y][x + 1] = 1;
		return mx_is_path_building(src, dist, x + 1, y, n - 1);
	}
	
	// y-variable handling
	if (y - 1 >= 0 && src->dots[y - 1][x] == n - 1) {
		(*dist)->dots[y - 1][x] = 1;
		return mx_is_path_building(src, dist, x, y - 1, n - 1);
	}
	    
	if (y + 1 < src->height && src->dots[y + 1][x] == n - 1) {
		(*dist)->dots[y + 1][x] = 1;
		return mx_is_path_building(src, dist, x, y + 1, n - 1);
	}
	
	return false;
}

