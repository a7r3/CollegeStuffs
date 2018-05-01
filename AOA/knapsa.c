/// Program to Implement Fractional Knapsack Algorithm

/*
	Knapsack Problem
	================

	We have n objects, and a Knapsack, with capacity m
	For each object 'i' in 1 <= i <= n have Profit Values 'Pi'
	and weight value 'Wi'

	Spoiler Alert: Remember LPP ?

	Objective: To obtain a filling of the knapsack that maximizes
		   total profit, or since the capacity is m, it should
                   follow constraints

		   maximize (Sum)Pi*Xi, where 1 <= i <= n

		   subject to (Sum)Wi*Xi <= m


	Note: 'Xi' is the fraction of the object to be put in the Knapsack

	We'd be solving this using Greedy strategy.
	Involves finding of fraction values Xi, such that

	(Sum)WiXi <= Capacity of Knapsack, and
	(Sum)PiXi is MAXIMUM

	What we'd do ?
	==============

	Take the P/W ratio for each item, and arrange these ratios in
	descending order.

	Give priority to the higher P/W values, while filling the knapsack

	What happens ?
	==============

	Items with higher P/W are taken as a whole, and this is continued
	until the `occupiedCapacity' is less than the specified Capacity

*/

#include<stdio.h>
#define MAXITEMS 30

struct item {

	float weight;
	float profit;
	float ratio;
	float fraction;

}item[MAXITEMS];

void main() {

	int i, j, n;
	float cap;
	struct item t;
	float tempWeight;
	float gainedProfit = 0;

	printf("Enter the number of items (< 30)\n > ");
	scanf("%d", &n);
	printf("\nEnter the profit and weight values of respective items\n");
	for(i = 0; i < n; i++) {
		printf("\nItem %d\nProfit > ", i+1);
		scanf("%f", &item[i].profit);
		printf("Weight > ");
		scanf("%f", &item[i].weight);
	}

	printf("\nEnter the capacity of the knapsack\n");
	scanf("%f", &cap);

	for(i = 0; i < n; i++)
		item[i].ratio = item[i].profit / item[i].weight;

	// Swap the struct vars, instead of individual swap
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(item[j].ratio < item[j+1].ratio) {
				t = item[j+1];
				item[j+1] = item[j];
				item[j] = t;
			}
		}
	}

	// printf("DEBUG : RATIOS\n");
	// for(i = 0; i < n; i++)
	//	printf("%f ", item[i].ratio);

	tempWeight = cap;

	for(i = 0; i < n; i++) {
		if(item[i].weight > tempWeight)
			break;
		else {
			item[i].fraction = 1;
			gainedProfit += item[i].profit;
			tempWeight -= item[i].weight;
		}
	}
	if(i <= n) {
		item[i].fraction = tempWeight / item[i].weight;
		gainedProfit = item[i].profit * item[i].fraction;
	}

	printf("\nItem | Profit | Weight | Fraction Taken\n");
	for(i = 0; i < n; i++)
		printf("  %d  | %3f | %3f | %3f\n", i, item[i].profit, item[i].weight, item[i].fraction);

	printf("\nOccupied weight = %2f\n", cap - tempWeight);
	printf("\nGained Profit = %2f\n", gainedProfit);
}
