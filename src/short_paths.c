#include "way_home.h"

void mx_short_paths(int file, int x, int y, int *xy) {
	char c;
	t_maze map[x][y];
	int i = 0;
    	int j = 0;

    	while (read(file, &c, 1)) {
        	if (c == ',') 
        		continue;
        	if (c == '\n') {
            		i++;
            		j = 0;
            		continue;
        	}
        	
        	map[i][j].ch = c;
        	
        	if (c == '.') 
        		map[i][j].length = 0;
        	else if (c == '#') 
        		map[i][j].length = -1;
        		
        	map[i][j].state = false;
        	j++;
    	}
    	
    	if (map[xy[1]][xy[0]].ch != '.') {
        	mx_printerr("entry point cannot be an obstacle\n");
        	exit(-1);
    	}

    	if (map[xy[3]][xy[2]].ch != '.') {
        	mx_printerr("exit point cannot be an obstacle\n");
        	exit(-1);
    	}
    	    	
    	map[xy[0]][xy[1]].length = 1;
    	    	
    	int dist = mx_calc_dist(x, y, map);
    	
    	if (map[xy[3]][xy[2]].length - 1 < 0) {
    		mx_printerr("route not found\n");
    		exit(-1);
    	}
    	else {
    		mx_printstr("dist=");
    		mx_printint(dist);
    		mx_printchar('\n');
    		mx_printstr("exit=");
    		mx_printint(map[xy[3]][xy[2]].length - 1);
    		mx_printchar('\n');
    	}
    	
    	mx_pathmarking(xy[2], xy[3], x, y, map, dist);
}
