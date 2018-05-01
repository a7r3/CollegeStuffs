/// Program to implement merge sort

#include<stdio.h>

void merge(int array[], int leftIndex, int midIndex, int rightIndex) {

        // Indices for left and right subArray respectively
        int i,j;

        int leftArraySize = midIndex - leftIndex + 1;
        int rightArraySize = rightIndex - midIndex;

        int leftArray[leftArraySize], rightArray[rightArraySize];

        for(i=0; i<leftArraySize; i++) {
                leftArray[i] = array[leftIndex + i];
        }

        for(i=0; i<rightArraySize; i++) {
                rightArray[i] = array[midIndex + 1 + i];
        }

        i=0;
        j=0;

        // Resultant Array's starting index
        int k = leftIndex;

        // While there are comparisons available in left and right subarray
        while(i < leftArraySize && j < rightArraySize) {

                // Compare the i'th element of leftArray
                // with j'th element of rightArray
                if(leftArray[i] <= rightArray[j]) {
                        // Put leftArray's i-th element first
                        array[k] = leftArray[i];
                        // Increment the index of leftArray
                        // Now comparison would be between i+1'th element
                        // and j'th element of leftArray and rightArray respectively
                        i++;
                } else {
                        // Put rightArray's j'th element first
                        array[k] = rightArray[j];
                        j++;
                }
                k++;
        }

        // After comparisons have been done
        // There might be elements in either of the array
        // which have no element to compare with in the other array
        //
        // Move such elements directly to the merged array
        // One of the arrays would be empty, another would have some elements

        while(i < leftArraySize) {
                array[k] = leftArray[i];
                i++;
                k++;
        }

        while(j < rightArraySize) {
                array[k] = rightArray[j];
                j++;
                k++;
        }

}

// function to perform the divide-and-conquer method
// mergeSort performs the divide
// merge performs the conquer, based on the numeric-order
void mergeSort(int array[], int leftIndex, int rightIndex) {

        // Until we reach a scenario where splitting is done upto
        // 1 element per array i.e leftIndex = rightIndex
        // Execute the statements inside
        if(leftIndex < rightIndex) {
                // Calculate midIndex, splitting (into left and right subarrays)
                //  would occur at this point
                int midIndex = leftIndex + (rightIndex - leftIndex)/2;

                // Perform further splitting of the leftSubArray
                mergeSort(array, leftIndex, midIndex);

                // Perform further splitting of the rightSubArray
                mergeSort(array, midIndex + 1, rightIndex);

                // Once splitting is done upto 1 per array
                // conquer 'em all
                merge(array, leftIndex, midIndex, rightIndex);
        }
}

void main() {
        int array[10] = {6,5,9,3,1,8,7,0,4,2};
        int i;
        int arr_size = sizeof(array)/sizeof(array[0]);

        printf("\nElements before MergeSort\n");
        printf("| ");
        for(i=0; i<arr_size; i++) {
                printf("%d | ", array[i]);
        }

        printf("\n");

        mergeSort(array, 0, arr_size - 1);

        printf("\nElements after MergeSort\n");
        printf("| ");
        for(i=0; i<arr_size; i++)
                printf("%d | ", array[i]);
        printf("\n\n");
}
