#include<stdio.h>
#define MAX 60

char word[MAX];
char pattern[MAX];

int len(char x[]) {
	int i;
	for(i = 0; x[i] != '\0'; i++);
	return i;
}

void naive_match() {
	int p_len = len(pattern);
	int w_len = len(word);
	int i, j;
	int occurences;

	for(i = 0; i <= w_len - p_len + 1; i++) {
		for(j = 0; j < p_len; j++) {
			if(word[i+j] != pattern[j])
				break;
		}
		if(p_len == j) {
			printf("\nPattern %s Found at position %d", pattern, i);
			occurences++;
		}
	}

	printf("\n\nNo. of occurences : %d\n", occurences);
}

void main() {

	printf("grepper v0.1\n");
	printf("Word > ");
	scanf("%s", word);
	printf("\nPattern > ");
	scanf("%s", pattern);
	naive_match();
}
