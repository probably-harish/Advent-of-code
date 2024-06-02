#include <stdio.h>

int main() {
	FILE * file;
	file = fopen("data.txt","r");
	int character;

	if (file == NULL) {
		printf("Failed to open the data file. Exiting");
		return 1;

	}
	
	int floor = 0;

	while ((character = fgetc(file)) != EOF) {
		if (character == '(') {
			floor++;
		}
		else if (character == ')') {
			floor--;
		}
	}

	fclose(file);

	printf("The final floor Santa ends up in is: %d", floor);
}
