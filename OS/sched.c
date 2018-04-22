// Shortest Job Pehle (SJF) scheduling

#include<stdio.h>
#define MAX 5

struct process {
	int id;
	int burst_time;
	int arrival_time;
} p[MAX];

void main() {
	int i, j, n;
	struct process t;
	printf("No. of Processes > ");
	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		printf("P%d Burst Time : ", i);
		scanf("%d", &p[i].burst_time);
		printf("P%d Arrival Time : ", i);
		scanf("%d", &p[i].arrival_time);
		printf("\n");
		p[i].id = i;
	}

	for(i = 1; i < n; i++) {
		for(j = 0; j < n-1; j++) {
			if(p[j+1].burst_time < p[j].burst_time) {
				t = p[j+1];
				p[j+1] = p[j];
				p[j] = t;
			}
		}
	}

	for(i = 0; i < n; i++)
		printf("P%d | ",p[i].id);
}
