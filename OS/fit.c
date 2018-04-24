#include<stdio.h>
#define MAX_PARTITIONS 10

int memory[MAX_PARTITIONS];
int memory_copy[MAX_PARTITIONS];
int process[MAX_PARTITIONS];

int n = MAX_PARTITIONS;
int p = MAX_PARTITIONS;

void restore_memory() {
	for(int i = 0; i < n; i++) {
		memory[i] = memory_copy[i];
	}
}
void first_fit(){
	int i, j;
	printf("\n\n=== First Fit ===\n");
	// For Each Process
	for(j = 0; j < n; j++) {
		// Among Each Memory Partition
		for(i = 0; i < p; i++) {
			// If current partition can satisfy the memory
			// requirements of this process
			if(process[j] <= memory[i]) {
				// Deduct the process memory from the Partition
				// And Show that it has been allocated
				memory[i] -= process[j];
				printf("\nP%d (%dK) -> Block %d", j, process[j], i+1);
				break;
			}
		}
		// If we still didn't get a partition with sufficient space, it can't be
		// Allocated. Show the same
		if(i == p)
			printf("\nP%d (%dK) -> Unallocated", j, process[j]);
	}
}

void best_fit(){
	int i, j;
	printf("\n\n=== Best Fit ===\n");
	for(i = 0; i < n; i++) {
		int min = -1;
		for(j = 0; j < p; j++) {
			int current = memory[j] - process[i];
			if(current >= 0)
				if((min == -1) || (current < memory[min] - process[i]))
					min = j;
		}
		if(min == -1)
			printf("\nP%d (%dK) -> Unallocated", i, process[i], min+1);
		else {
			memory[min] -= process[i];
			printf("\nP%d (%dK) -> Block %d", i, process[i], min+1);
		}
	}
}

void worst_fit(){
        int i, j;
        printf("\n\n=== Worst Fit ===\n");
        for(i = 0; i < n; i++) {
                int max = -1;
                for(j = 0; j < p; j++) {
                        int current = memory[j] - process[i];
                        if(current >= 0)
                                if((max == -1) || (current > memory[max] - process[i]))
                                        max = j;
                }
                if(max == -1)
                        printf("\nP%d (%dK) -> Unallocated", i, process[i], max+1);
                else {
                        memory[max] -= process[i];
                        printf("\nP%d (%dK) -> Block %d", i, process[i], max+1);
                }
        }
}

void next_fit() {
	int i, j = 0;
	printf("\n\n=== Next Fit ===\n");
	for (int i = 0; i < n; i++) { 
		while (j < p) {
			int current = memory[j] - process[i];
			if(current >= 0) {
				memory[j] -= process[i];
				printf("\nP%d (%dK) -> Block %d", i, process[i], j+1);
				break;
			}
			j++;
		}
	}
}

void main(){
	int i;
	printf("No. of partitions > ");
	scanf("%d", &p);
	for(i = 0; i < p; i++) {
		printf("M%d -> ", i);
		scanf("%d", &memory[i]);
		memory_copy[i] = memory[i];
	}
	printf("No. of processes > ");
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		printf("P%d -> ", i);
		scanf("%d", &process[i]);
	}
	first_fit();
	restore_memory();
	best_fit();
	restore_memory();
	worst_fit();
	restore_memory();
	next_fit();
	// Cuz sweg :P
	restore_memory();
}
