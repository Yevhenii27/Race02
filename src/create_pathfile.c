#include "way_home.h"

void mx_create_pathfile(int x, int y, t_maze map[x][y]) {
	int fd = open("path.txt", O_RDONLY);
	fd = open("path.txt", O_WRONLY | O_CREAT);

	for (int a = 0; a < y - 1; a++) {
		for (int b = 0; b < x; b++) {
			write(fd, &map[a][b].ch, 1);
		}
		write(fd, "\n", 1);
	}
	if (close(fd) < 0) {
		mx_printerr("error\n");
		exit(-1);
	}
	close(fd);
}
