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
	int occurences = 0;

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

// matching the hashes of pattern, and of the word
// A portion of word is taken for hash calculation
void rabin_karp() {
	int p_len = len(pattern);
	int w_len = len(word);
	// p - pattern hash
	// w - word hash (with the pattern length)
	// d - radix
	// q - random hashing variable
	int p_hash = 0, w_hash = 0, h = 1, d = 256, q = 11;
	int n = 0;
	int occurences = 0;

	int i, j;

	for(i = 0; i < p_len; i++)
		h = (h * d) % q;

	// Calculate the hashes
	for(j = 0; j < p_len; j++) {
		p_hash = ((d * p_hash) + pattern[j]) % q;
		w_hash = ((d * w_hash) + word[j]) % q;
	}

	for(i = 0; i < w_len - p_len; i++) {
		if(p_hash == w_hash) {
			for(j = 0; j < p_len; j++) {
				if(word[i+j] != pattern[j])
					break;
			}
			if(p_len == j) {
	                        printf("\nPattern %s Found at position %d", pattern, i);
        	                occurences++;
                	}
		}
		if(i < w_len - p_len) {
			w_hash = ((d * (w_hash - (word[i] * h))) + word[i + p_len]) % q;
			if(w_hash < 0)
				w_hash += q;
		}
	}

}

void main() {

	printf("String Matcher\n\n");
	printf("Word > ");
	scanf("%s", word);
	printf("\nPattern > ");
	scanf("%s", pattern);
	printf("\nNaive Matching\n");
	naive_match();
	printf("\nRabin Karp Matching\n");
	rabin_karp();
}
