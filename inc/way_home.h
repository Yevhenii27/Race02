#ifndef WAY_HOME_H
#define WAY_HOME_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>

typedef struct s_maze {
    char ch;
    int length;
    bool state;
}              t_maze;

void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
int mx_strlen(const char *s);
void mx_printerr(const char *s);

int mx_atoi(const char *str);
bool mx_isdigit(int c);
bool mx_isspace(char c);

bool mx_isrectangle(int file);
int mx_searchx(int file);
int mx_searchy(int file);
void mx_short_paths(int file, int x, int y, int *xy);
int mx_calc_dist(int x, int y, t_maze map[x][y]);
void mx_pathmarking(int x2, int y2, int x, int y, t_maze map[x][y], int dist);
void mx_create_pathfile(int x, int y, t_maze map[x][y]);

#endif
