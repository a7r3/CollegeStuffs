#include<stdio.h>
#define MAX 10

char x[MAX], y[MAX];

int c[MAX][MAX];
int b[MAX][MAX];

int len(char z[]) {
	int i = 0;
	while(z[i] != '\0')
		i++;
	return i;
}

void apply_lcs() {
	int i, j;
	// For each character in x
	for(i = 1; i <= len(x); i++) {
		// In comparison with character in y
		for(j = 1; j <= len(y); j++) {
			// If previous character was same
			if(x[i-1] == y[j-1]) {
				// Increment current cost
				// And add an diagonal indicator
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 'd';
			// If cost of upper one is greater than the one to the left
			} else if (c[i-1][j] >= c[i][j-1]) {
				c[i][j] = c[i-1][j];
				b[i][j] = 'u';
			} else {
				c[i][j] = c[i][j-1];
				b[i][j] = 'l';
			}
		}
	}
}

void print_lcs(char x[], int len_x, int len_y) {
	// Print the character only if the direction specified in
	// b[][] is 'd' aka Diagonal

	// If either of the strings are empty; do nothing
	if ((len_x == 0) || (len_y == 0)) {
		return;
	// Direction is diagonal, print the character, and go left-up
	} else if (b[len_x][len_y] == 'd') {
		print_lcs(x, len_x - 1, len_y - 1);
		printf("%c ", x[len_x - 1]);
	// Direction is up, do nothing, and go up
	} else if (b[len_x][len_y] == 'u') {
		print_lcs(x, len_x - 1, len_y);
	// Direction is left, do nothing, and go left
	} else if (b[len_x][len_y] == 'l') {
		print_lcs(x, len_x, len_y - 1);
	}
}

void init_table() {
	int i;
	for(i = 0; i < MAX; i++) {
		c[i][0] = 0;
		c[0][i] = 0;
	}
}

void main() {
	printf("Enter String 1 > ");
	scanf("%s", &x);
	printf("Enter String 2 > ");
	scanf("%s", &y);
	init_table();
	apply_lcs();
	print_lcs(x, len(x), len(y));
}
