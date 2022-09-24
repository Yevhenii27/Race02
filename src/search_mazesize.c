#include "way_home.h"

int mx_searchx(int file) {
	int count = 0;
	char c[2] = {'q', 'q'};
	
	while (c[1] != '\n') {
		read(file, &c, 2);
		count++;
	}
	return count;
}

int mx_searchy(int file) {
	int count = 1;
	char c;
	
	while (read(file, &c, 1) != 0) {
		if (c == '\n')
			count++;
	}
	return count;
}
