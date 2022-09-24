#include "way_home.h"

bool mx_isrectangle(int file) {
	char c = '#';
	int count = 0;
	int countn = 0;
	
	while (c != '\n') {
		read(file, &c, 1);
		if (c != '#' && c != '.'
		&& c != ',' && c != '\n') {
			mx_printerr("map error\n");
			exit(-1);
		}
		
		count++;
	}
	
	while (read(file, &c, 1) != 0) {
		while (c != '\n') {
			read(file, &c, 1);
			if (c != '#' && c != '.'
			&& c != ',' && c != '\n') {
				mx_printerr("map error\n");
				exit(-1);
			}
			
			countn++;
		}
		
		if (countn != count)
			return false;

		countn = 0;
	}
	
	return true;
}

