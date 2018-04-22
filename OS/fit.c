#include<stdio.h>
#define MAX_PARTITIONS 10

int mem_array[MAX_PARTITIONS];

int process_mem[MAX_PARTITIONS];

int n = MAX_PARTITIONS;
int p = MAX_PARTITIONS;

void first_fit(){
	int i, j;
	printf("\n\n== First Fit ==\n");
	for(j = 0; j < n; j++) {
		for(i = 0; i < p; i++) {
			if(process_mem[j] <= mem_array[i]) {
				mem_array[i] -= process_mem[j];
				printf("\nP%d (%dK) -> Block %d", j, process_mem[j], i+1);
				break;
			}
		}
		if(i == p)
			printf("\nP%d (%dK) -> Unallocated", j, process_mem[j]);
	}
}

void best_fit(){
	int i, j;
	printf("\n\n== Best Fit ==\n");
	for(i = 0; i < n; i++) {
		int min = -1;
		for(j = 0; j < p; j++) {
			int current = mem_array[j] - process_mem[i];
			if(current >= 0)
				if((min == -1) || (current < mem_array[min] - process_mem[i]))
					min = j;
		}
		if(min == -1)
			printf("\nP%d(%dK) -> Unallocated", i, process_mem[i], min+1);
		else {
			mem_array[min] -= process_mem[i];
			printf("\nP%d (%dK) -> Block %d", i, process_mem[i], min+1);
		}
	}
}

void worst_fit(){
        int i, j;
        printf("\n\n== Worst Fit ==\n");
        for(i = 0; i < n; i++) {
                int max = -1;
                for(j = 0; j < p; j++) {
                        int current = mem_array[j] - process_mem[i];
                        if(current >= 0)
                                if((max == -1) || (current > mem_array[max] - process_mem[i]))
                                        max = j;
                }
                if(max == -1)
                        printf("\nP%d(%dK) -> Unallocated", i, process_mem[i], max+1);
                else {
                        mem_array[max] -= process_mem[i];
                        printf("\nP%d (%dK) -> Block %d", i, process_mem[i], max+1);
                }
        }
}

void next_fit() {
	int i, j = 0;
	while (j <= n) {
		for(i = 0; i < n; i++) {
			int current = mem_array[j] - process_mem[i];
			if(current >= 0) {
				mem_array[j] -= process_mem[i];
				printf("P%d(%dK) -> Block %d", i, process_mem[i], j+1);
				j++;
				continue;
			}
		}
	}
}

void main(){
	int i;
	printf("No. of partitions > ");
	scanf("%d", &p);
	for(i = 0; i < p; i++) {
		printf("M%d -> ", i);
		scanf("%d", &mem_array[i]);
	}
	printf("No. of processes > ");
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		printf("P%d -> ", i);
		scanf("%d", &process_mem[i]);
	}
//	first_fit();
//	best_fit();
	worst_fit();
}
