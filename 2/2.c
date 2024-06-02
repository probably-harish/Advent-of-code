#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void line_to_dim(char * line, int * arr);
int minimum (int a, int b, int c);

int main() {
	FILE * file;
	file = fopen("data.txt", "r");
	char curr_line[100];
	int total_ribbon = 0;
	int a, b, c;
	int dim[3];

	while (fgets(curr_line, sizeof(curr_line), file) != NULL) {
		line_to_dim(curr_line, dim);
		a = dim[0];
		b = dim[1];
		c = dim[2];
	
		int pr1 = 2*(a+b);
		int pr2 = 2*(c+b);
		int pr3 = 2*(a+c);
		
		int min = minimum(pr1,pr2,pr3);
		total_ribbon += min + a*b*c;
	}
	printf("The total ribbon required in ft is: %d\n", total_ribbon);
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
