/// Program to implement insertion sort

#include<stdio.h>

void insertSort(int array[], int n) {

	int i, position, key;
	for(i=1; i<n; i++) {
		// The element to be picked and inserted
		key = array[i];

		// Position where the key would be inserted
		// Starts with position which is just behind key element
		position = i-1;

		// While we don't reach the end
		// && While element at 'position' is greater than key
		while(position >= 0 && array[position] > key) {
			// Move the element at 'position' ahead by 1
			array[position + 1] = array[position];
			// Go behind
			position--;
		}

		// We got 'position' of the element which is just less than the key
		// So, place the Key element just ahead of that element
		array[position + 1] = key;
	}
}

void main() {

	int someArray[10] = {5,2,1,6,8,3,9,7,4,0};

	printf("\nElements before Insertion sort\n");
	int i;
	printf("|");
	for(i=0;i<10;i++) {
		printf(" %d |",someArray[i]);
	}

	printf("\n");

	insertSort(someArray, 10);

	printf("\nElements after insertion sort\n");
	printf("|");
        for(i=0;i<10;i++) {
                printf(" %d |",someArray[i]);
        }

	printf("\n\n");
}
