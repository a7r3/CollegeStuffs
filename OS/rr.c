/// Program to demonstrate Round Robin Scheduling

#include<stdio.h>
#define MAX 5

void main() {
	int i, j;
	// No. of processes
	int n;
	// No. of completely executed process
	int complete = 0;
	// The time-frame given to a process, to make use of CPU
	int quantum;
	// Array containing a series of burst_times of processes
	int burst_time[MAX];

	printf("\nQuantum > ");
	scanf("%d", &quantum);

	printf("\nNo. of Processes > ");
	scanf("%d", &n);

	printf("\n");

	for(i = 0; i < n; i++) {
		printf("P%d Burst Time : ", i);
		scanf("%d", &burst_time[i]);
		printf("\n");
	}

	// While the world rotates around its axis
	while(1) {
		// Provide a quantum to each process, one-by-one
		for(i = 0; i < n; i++) {
			// If burst_time is lesser than quantum
			// And is greater than 0
			// The Process would get completely executed
			if((burst_time[i] <= quantum) && (burst_time[i] > 0)) {
				// Reset the burst time to 0
				burst_time[i] = 0;
				// Report usage of quantum by the process, to teh user
				printf("P%d | ", i);
				// If all processes are complete, then we're done!
				if(++complete == n)
					return;
			}
			// If burst_time is greater than quantum (implicitly checked above)
			// And is a positive integer (checked here)
			else if (burst_time[i] > 0) {
				// Deduct the quantum from the burst_time
				burst_time[i] = burst_time[i] - quantum;
				// Report usage of this quantum, to teh user
				printf("P%d | ", i);
			}
		}
	}

}
