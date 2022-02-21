#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct queue {
	int *data;
	int head;
	int tail;
	int length;
	int cnt;
}queue;

queue *init(int n) {
	queue *q = (queue*)malloc(sizeof(queue));
	q->data = (int*)malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++) {
		q->data[i] = 0;
	}
	q->head = 0;
	q->tail = 0;
	q->length = n;
	q->cnt = 0;
	return q;
}

int clear(queue *q) {
	if(q == NULL) return 0;
	free(q->data);
	free(q);
	return 1;
}

int is_empty(queue *q) {
	return q->cnt == 0;
}

int front(queue *q) {
	return q->data[q->head];
}

int push(queue *q, int val) {
	if(q == NULL) {
		printf("the queue is NULL!\n");
		return 0;
	}
	if(q->cnt == q->length) {
		printf("the queue is full!\n");
		return 0;
	}

	q->data[q->tail++] = val;
	q->tail %= q->length;
	q->cnt++;
	return 1;
}

int pop(queue *q) {
	if(q == NULL) {
		printf("the queue is NULL!\n");
		return 0;
	}
	if(is_empty(q)) {
		printf(" the queue is empty!\n");
		return 0;
	}

	q->head++;
	q->head %= q->length;
	q->cnt--;
	return 1;
}

void show(queue *q) {
	printf("queue[ ");
	for(int i = q->head, j = 0; j < q->cnt; j++) {
		int index = (i + j) % q->length;
		printf("%d ", q->data[index]);
	}
	printf("]\n\n");
}

#define MAX_OP 20
int main(int argc, char** argv) {

	srand(time(0));

	queue *q = init(MAX_OP);

	for(int i = 0; i < 10; i++) {
		int val = rand() % 100;
		int op = rand() % 2;
		switch(op) {
			case 0: {
				printf("push %d to queue = %d\n",val, push(q, val));
			} break;
			case 1: {
				printf("pop %d from queue\n",front(q));
				pop(q);

			} break;
		}
		show(q);
	}

	printf("head : %d, tail : %d, count = %d \n\n",q->head, q->tail, q->cnt);

	for(int i = 0; i < MAX_OP; i++) {
		int val = rand() % 100;
		printf("push %d to queue = %d\n",val, push(q, val));
	}
	show(q);
	printf("head : %d, tail : %d, count = %d \n\n",q->head, q->tail, q->cnt);
	return 0;
}