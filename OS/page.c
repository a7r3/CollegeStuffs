#include<stdio.h>
#define MAX 10
#include<stdbool.h>

int current_time = 0;
int n;
int p;
int page_seq[MAX];

struct block {
    int hit_count;
    int time;
} b[MAX];

bool is_page_present(int page_stack[], int page) {
    int i;
    for(i = 0; i < n; i++)
        if(page_stack[i] == page)
            return true;
    return false;
}

int gib_page(int page_stack[], int page) {
    int i;
    for(i = 0; i < n; i++)
        if(page_stack[i] == -1)
            return i;
    return -1;
}

void fifo() {
    int start = -1;
    int fault_count = 0;
    int hit_count = 0;
    int miss_count = 0;
    int page_stack[MAX];
    int i;

    for(i = 0; i < MAX; i++) {
        page_stack[i] = -1;
    }

    for(i = 0; i < p; i++) {
        printf("\n\nPage %d", page_seq[i]);
        int index = gib_page(page_stack, page_seq[i]);
        if(index != -1) {
            page_stack[index] = page_seq[i];
	    printf("Miss #%d", ++miss_count);
        } else {
            if(is_page_present(page_stack, page_seq[i])) {
                printf("\nHit #%d", ++hit_count);
            } else {
                printf("\nPage Fault #%d", ++fault_count);
                page_stack[++start] = page_seq[i];
            }
            printf("\n[");
            for(int j = 0; j < n; j++) {
                printf("%d | ", page_stack[j]);
            }
            printf("]\n");
        }
    }

    printf("\nFIFO Summary\n");
    printf("Page Hits : %d\nPage Misses : %d\nPage Faults : %d\n", hit_count, miss_count, fault_count);
}

void lru() {
	int hit_count = 0, miss_count = 0, fault_count = 0;
	int page_stack[MAX];
	int time_stack[MAX];

        for(i = 0; i < MAX; i++) {
    		page_stack[i] = -1;
		time_stack[i] = 0;
    	}

	for(int i = 0; i < p; i++) {
		int index = gib_page(page_stack, page_seq[i]);
		if(index != -1) {
			printf("Miss #%d", ++miss_count);
			page_stack[index] = page_seq[i];
			time_stack[index] = 0;
		} else {
			if(is_page_present(page_stack, page_seq[i])) {
				printf("\nHit #%d\n", i);
				time_stack[i] = 0;
			} else {
				
			}
		}
	}
}

// void optimal() {
//     char page_stack[MAX];

// }

void main() {
    int i;
    printf("\n\nNo. of pages > ");
    scanf("%d", &n);
    printf("\n\nPage Sequence Count > ");
    scanf("%d", &p);
    printf("\n\nPage Sequence > ");
    for(i = 0; i < p; i++) {
        scanf("%d", &page_seq[i]);
    }
    fifo();
    // lru();
    // optimal();
}
