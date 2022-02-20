#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct Queue {
	int *data;
	int head;
	int tail;
	int length;
}Queue;

Queue *init_queue(int n) {
	Queue *q = (Queue*)malloc(sizeof(Queue));
	q->data = (int*)malloc(sizeof(int) * n);
	q->head = q->tail = 0;
	q->length = n;
	return q;
}

void clear_queue(Queue *q) {
	if(q == NULL) return;
	free(q->data);
	free(q);
}

bool is_empty(Queue *q) {
	if(q != NULL) {
		return q->tail == q->head;
		printf("the queue is empty");
	}
}

int front(Queue *q) {
	printf("front(%d) = %d\n",q->head, q->data[q->head]);
	return q->data[q->head];
}

int back(Queue *q) {
	return q->data[q->tail];
}

int push(Queue *q, int val) {
	if(q == NULL) return 0;
	if(q->tail == q->length) return 0;

	q->data[q->tail++] = val;
	return 1;
}

int pop(Queue *q) {
	if(q == NULL) return 0;
	if(is_empty(q)) return 0;
	q->head++;
	return 1;
}

void show(Queue *q) {
	printf("queue[ ");
	for(int i = q->head; i < q->tail; i++) {
		printf("%d ",q->data[i]);
	}
	printf("]\n");
}

#define MAX_OP 20
int main(int argc, char** argv) {
	srand(time(0));
	Queue *q = init_queue(MAX_OP);
	for(int i = 0; i < MAX_OP; i++) {
		int op = rand() % 2;
		int val = rand() % 100;
		switch(op) {
			case 0:
				printf("push %d to queue = %d\n",val, push(q, val));
				front(q);
				break;
			case 1:
				printf("pop %d from queue = %d\n",front(q), pop(q));
				break;
			default:
				break;
		}
		show(q);
	}
	return 0;
}