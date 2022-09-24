#include "header.h"

void mx_wave_func(t_map **map, int x, int y, int n) {
    if (x < 0 || x >= (*map)->width || y < 0 || y >= (*map)->height) return;
    
    if ((*map)->dots[y][x] == -2) return;
    else if ((*map)->dots[y][x] == -1) (*map)->dots[y][x] = n;
  
    // x-variable handling
    if (x - 1 >= 0 && ((*map)->dots[y][x - 1] == -1 
        || (*map)->dots[y][x - 1] > n + 1))
        (*map)->dots[y][x - 1] = n + 1;  
    
    if (x + 1 < (*map)->width && ((*map)->dots[y][x + 1] == -1 
        || (*map)->dots[y][x + 1] > n + 1))
        (*map)->dots[y][x + 1] = n + 1;
    
    // y-variable handling
    if (y - 1 >= 0 && ((*map)->dots[y - 1][x] == -1 
        || (*map)->dots[y - 1][x] > n + 1))
        (*map)->dots[y - 1][x] = n + 1;
    
    if (y + 1 < (*map)->height && ((*map)->dots[y + 1][x] == -1 
        || (*map)->dots[y + 1][x] > n + 1))
        (*map)->dots[y + 1][x] = n + 1;
    
    // Recursive function call on values of x-variable  
    if (x - 1 >= 0 && ((*map)->dots[y][x - 1] >= n + 1))
        mx_wave_func(map, x - 1, y, n + 1);
      
    if (x + 1 < (*map)->width && ((*map)->dots[y][x + 1] >= n + 1))
        mx_wave_func(map, x + 1, y, n + 1);
    
    // Recursive function call on values of y-variable
    if (y - 1 >= 0 && ((*map)->dots[y - 1][x] >= n + 1))
        mx_wave_func(map, x, y - 1, n + 1);
      
    if (y + 1 < (*map)->height && ((*map)->dots[y + 1][x] >= n + 1))
        mx_wave_func(map, x, y + 1, n + 1);
}

