#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void line_to_dim(char * line, int * arr);
int minimum (int a, int b, int c);

int main() {
	FILE * file;
	FILE * file_write;
	file = fopen("data.txt", "r");
	file_write = fopen("my_answer.txt", "w");
	char curr_line[100];
	int total_area = 0;
	int a, b, c;
	int dim[3];
	int count = 0;

	while (fgets(curr_line, sizeof(curr_line), file) != NULL) {
		line_to_dim(curr_line, dim);
		count++;
		a = dim[0];
		b = dim[1];
		c = dim[2];
	
		int ar1 = a*b;
		int ar2 = b*c;
		int ar3 = c*a;
		int min = minimum(ar1,ar2,ar3);

		total_area += 2*ar1 + 2*ar2 + 2*ar3 + min;
		fprintf(file_write, "%d\n", total_area);
	
	}
	printf("The total area of wrapping paper required in sq.ft is: %d\n", total_area);
	fclose(file_write);
	fclose(file);
}

void line_to_dim(char * line, int * arr) {
	char str_arr[3][50] = {"","",""};
	int i = 0;
	int j = 0;
	char ch;

	while ((ch = line[j]) != '\0') {
		if (ch == 'x') {
			i++;
			j++;
			continue;
		}
		char character[] = {ch, '\0'};
		strcat(str_arr[i], character);
		j++;
	}


	for (int k = 0; k < 3; k++) {
		arr[k] = atoi(str_arr[k]);
	}
}

int minimum(int a, int b, int c) {
	int ans = a;
	if(b<a) ans = b;
	if(c<ans) ans = c;
	return ans;
}
