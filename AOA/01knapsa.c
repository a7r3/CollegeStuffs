/// Program to demonstrate 0/1 Knapsack Algorithm
#include<stdio.h>
// Indicates the maximum number of items
#define MAX 40
// Indicates the maximum capacity of Knapsack
#define MAX_WEIGHT 100

int max(int x,int y) {
	if(x>y)
    	return x;
	return y;
}

void main() {
    // n -> No. Of Items
    // m -> Capacity of Knapsack
	int i, n, j, m;
    // p -> Profits of each Item
    // w -> Weights of each Item
    // v -> The Table!
    //   -> No. of Rows    = No. of Items         = MAX (But we're taking it to be MAX_WEIGHT anyways, simplicity)
    //   -> No. of Columns = Capacity of Knapsack = MAX_WEIGHT
	int p[MAX], w[MAX], v[MAX_WEIGHT + 1][MAX_WEIGHT + 1];

    // Initializing all the Cells in First Row and First Column to 0
	for(i = 0; i <= MAX_WEIGHT; i++) {
        v[i][0] = 0;
        v[0][i] = 0;
    }

    printf("\nNumber of Elements > ");
	scanf("%d",&n);

    printf("\nSpecify the Profits for each Item\n\n");
	for(i = 1; i <= n; i++) {
        printf("\nProfit of %d > ", i);
    	scanf("%d", &p[i]);
    }

    printf("\nSpecify the Weights for each Item\n\n");
    for(i = 1; i <= n; i++) {
        printf("\nWeight of %d > ", i);
        scanf("%d", &w[i]);
    }

	printf("\nKnapsack Capacity > ");
	scanf("%d",&m);

	for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            if (j < w[i]) {
                v[i][j] = v[i-1][j];
            } else {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
            }
        }
    }

    // Maximum Profit is at the Bottom-Right of the Table, which would be printed next
    printf("\n\nMaximum Profit > %d\n", v[n][m]);

    printf("\nTable : \n");
    for(i = 0; i <= n; i++) {
        for(j = 0; j <= m; j++)
            printf("%5d",v[i][j]);
        printf("\n");
    }

    printf("\n\nObjects Included > ");

    // Starting off from the Bottom-Right corner of the Table
    i = n;
    j = m;

    // While we don't reach either of the table's top or left corner
    while((i > 0) && (j > 0)) {
        // If the "Current Weight" and the "Weight Above It" are not equal
        if(v[i][j] != v[i - 1][j]) {
            // Indicates that the "Current Object" was added to the Knapsack
            printf("%d ",i);
            // Go Behind according to the weight
            j = j - w[i];
            // Go behind and check the same for next item
            i = i - 1;
        }
    }
    printf("\n");
}
