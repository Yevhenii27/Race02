#include "way_home.h"

int mx_calc_dist(int x, int y, t_maze map[x][y]) {
	int count = 1;

	while (true) {
        	int check = 1;
        	count++;
        	for (int j = 0; j < x; j++) {
            		for (int i = 0; i < y; i++) {
                		if (map[i][j].length == count - 1) {
                    			check = 0;
                    			if (j < y && map[i][j + 1].length == 0)
                        			map[i][j + 1].length = count;
                    			if (j > 0 && map[i][j - 1].length == 0)
                        			map[i][j - 1].length = count;
                    			if (i < x && map[i + 1][j].length == 0)
                        			map[i + 1][j].length = count;
                    			if (i > 0 && map[i - 1][j].length == 0)
                    				map[i - 1][j].length = count;
                		}
            		}
        	}

        	if (check == 1) return count - 3;
    	}
    	
    	return 0;
}
