#include <stdio.h>

int main() {
	FILE * file;
	int character;
	int floor = 0;
	int position = 1;

	file = fopen("data.txt","r");
	
	while ((character = fgetc(file)) != EOF) {
		if (character == '(') {
			floor++;
		}
		else if (character == ')') {
			floor--;
		}
		
		if (floor < 0) {
			break;
		}

		position++;
	}

	printf("The position at which santa enters basement is: %d",position);

		

	fclose(file);		
}
