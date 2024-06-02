#include <stdio.h>
#include <stdbool.h>

int main() {
	FILE * file;
	file = fopen("data.txt", "r");
	
	bool grid[1000][1000] = { false };
	int x = 500;
	int y = 500;

	bool * curr = &grid[x][y];
	char ch;
	while((ch = fgetc(file)) != EOF) {
		*curr = true;
		if(ch == 'v') x++;
		else if (ch == '^') x--;
		else if (ch == '<') y--;
		else if (ch == '>') y++;
		curr = &grid[x][y]; 
	}

	int count = 0;	
	for(int i = 0; i < 1000; i++) {
		for(int j = 0; j < 1000; j++) {
			if(grid[i][j] == true) {
				count++;
			}
		}
	}
	printf("%d", count);
	fclose(file);
}
