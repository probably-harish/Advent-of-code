#include <stdio.h>
#include <stdbool.h>

int main() {
	FILE * file;
	file = fopen("data.txt", "r");
	
	bool grid[1000][1000] = { false };
	int x1 = 500;
	int y1 = 500;

	int x2 = 500;
	int y2 = 500;

	bool * curr1 = &grid[x1][y1];
	bool * curr2 = &grid[x2][y2];
	
	int instruction = 0;
	char ch;
	while((ch = fgetc(file)) != EOF) {
		
		if(instruction % 2 == 0){
			*curr1 = true;
			if(ch == 'v') x1++;
			else if (ch == '^') x1--;
			else if (ch == '<') y1--;
			else if (ch == '>') y1++;
			curr1 = &grid[x1][y1]; 
		}

		else{
			*curr2 = true;
			if(ch == 'v') x2++;
			else if (ch == '^') x2--;
			else if (ch == '<') y2--;
			else if (ch == '>') y2++;
			curr2 = &grid[x2][y2]; 
		}
		instruction++;
		
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
