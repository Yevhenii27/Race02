#include "way_home.h"

void mx_pathmarking(int x2, int y2, int x, int y, t_maze map[x][y], int dist) {
	map[y2][x2].ch = '*';
	
	while (true) {
		if (map[y2][x2].length == 1)
			break;

		int tmp = map[y2][x2].length - 1;
		if (map[y2][x2 - 1].length == tmp && x2 > 0) {
            		map[y2][x2 - 1].ch = '*';
            		x2--;
        	}
        	if (map[y2][x2 + 1].length == tmp) {
            		map[y2][x2 + 1].ch = '*';
            		x2++;
        	}
        	if (map[y2 - 1][x2].length == tmp && y2 > 0) {
        	    map[y2 - 1][x2].ch = '*';
            		y2--;
        	}
        	if (map[y2 + 1][x2].length == tmp) {
            		map[y2 + 1][x2].ch = '*';
            		y2++;
        	}
        }
        
        for (int k = 0; k < x; k++) {
        	for (int m = 0; m < y; m++) {
        		if (map[k][m].length == dist + 1 && map[k][m].ch == '*')
        			map[k][m].ch = 'X';
        		if (map[k][m].length == dist + 1 && map[k][m].ch == '.')
        			map[k][m].ch = 'D';
        	}
        }
        mx_create_pathfile(x, y, map);
}
