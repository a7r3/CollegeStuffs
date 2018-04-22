#include<stdio.h>
#include<stdbool.h>
#define MAX 64

int abs(int x) {
	if(x < 0)
		return (-1) * x;
	return x;
}

int n = MAX;
int x[MAX];

int count = 0;

void init_x() {
	int i;
	for(i = 0; i < n; i++)
		x[i] = -1;
}

int is_placeable(int k, int i) {
	int j;
	for(j = 0; j < k; j++)
		if((x[j] == i) || (abs(x[j] - i) == abs(k - j)))
			return false;
	return true;
}

void nq(int k, int n) {
	int i, j;
	for(i = 0; i < n; i++) {
		if(is_placeable(k, i)) {
			x[k] = i;
			if(k == n - 1) {
				count++;
		                for(j = 0; j < n; j++)
                		        printf("%d |  ", x[j], j);
				printf("\n\n");
			} else
				nq(k + 1, n);
		}
	}
}

void main() {
	printf("\nGrid Size > ");
	scanf("%d", &n);
	printf("\nN(%d) Queens Grid\n", n);
	init_x();
	nq(0, n);
	printf("Count : %d", count);
}
