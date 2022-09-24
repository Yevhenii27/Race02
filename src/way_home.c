#include "way_home.h"

int main(int argc, char *argv[]) {
	if (argc != 6) {
		mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
		return -1;
	}
	int file = open(argv[1], O_RDONLY);
	char c;
	
	if (file == -1) {
		mx_printerr("map does not exist\n");
		return -1;
	}
	
	if (read(file, &c, 1) != 1) {
		mx_printerr("map does not exist\n");
		return -1;
	}
	
	if (c != '#' && c != '.' && c != ',' && c != '\n') {
		mx_printerr("map error\n");
		exit(-1);
	}
	
	if (!mx_isrectangle(file)) {
		mx_printerr("map error\n");
		return -1;
	}
	
	close(file);
	file = open(argv[1], O_RDONLY);
	int x = mx_searchx(file);
	int y = mx_searchy(file);
	
	
	
	close(file);
	file = open(argv[1], O_RDONLY);
	int xy[4];
	for (int i = 0; i < 4; i++)
		xy[i] = mx_atoi(argv[i + 2]);
		
	if ((xy[0] > x && xy[0] < 0)
		|| (xy[1] > y && xy[1] < 0)) {
		mx_printerr("points are out of map range\n");
		exit(-1);
	}
	
	if ((xy[2] > x || xy[2] < 0)
		|| (xy[3] > y || xy[3] < 0)) {
		mx_printerr("points are out of map range\n");
		exit(-1);
	}
	
	mx_short_paths(file, x, y, xy);
}
