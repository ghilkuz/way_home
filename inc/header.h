#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>

typedef struct s_map{                                                    
	int width;
	int height;
	int **dots;
}	           t_map;

int main(int argc, char *argv[]);

long long mx_atoi(const char *s);
bool mx_isdigit(int c);
bool mx_isspace(char c);
void mx_printchar(char c);
void mx_printerr(char *str);
int mx_strlen(const char *s);
void mx_printstr(const char *s);
void mx_printint(int n);
char *mx_strnew(const int size);

char *mx_open_file(char *path);
t_map *mx_build_map(char **map_text);
char *mx_strappend(char *str, char symb);
int mx_most_distant(t_map *map);
int mx_exit_distance(t_map *map, int x, int y);
bool mx_is_path_building(t_map *src, t_map **dist, int x, int y, int n);
char *mx_parse_map(t_map *map, int x1, int y1, int x2, int y2);
char **mx_parse_text(char *text);
void mx_wave_func(t_map **map, int x, int y, int n);
void mx_printres(t_map map, int x2, int y2, char *path, char *res);

#endif
