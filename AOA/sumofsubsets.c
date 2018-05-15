/// Program to demonstrate the Sum of Subsets Problem
#include<stdio.h>

// We try to find a subset in the provided set
//  For which, sum of all the elements in the subset
//  equals the 'sum' provided as an argument
// There are two possibilities
//  Either the number is added to the subset, or it is not
// If the subset's sum exceeds 'sum', then the solution
//  is dropped and we backtrack to the last valid subset
//  (whose sum was less than 'sum') and follow the alternate path(s)
int isSubsetSum(int set[], int n, int sum) {

	// If this is zero, we were successful
	// in obtaining a subset, whose sum equals 'sum'
	if (sum == 0)
		return 0;
	// If there are no elements in the set
	// And 'sum' is still not zero
	// There's no subset satisfying the criteria
	if(n == 0 && sum != 0)
		return 1;

	// If the number itself is greater than sum
	// then Ignore it
	if(set[n-1] > sum)
		return isSubsetSum(set, n-1, sum);

	// We split here with two possible cases
	// We add this number and move on
	// We ignore this number and move on
	// This is done for every other element in the set
	return isSubsetSum(set, n-1, sum) ||
		isSubsetSum(set, n-1, sum - set[n-1]);
}

void main() {
	int set[] = {3, 4, 4, 5, 6};
	int sum = 10;
	int n = sizeof(set)/sizeof(set[0]);
	if(isSubsetSum(set, n, sum))
		printf("Subset Exists");
	else
		printf("No Subset Exists");
}
