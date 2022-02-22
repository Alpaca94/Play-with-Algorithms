#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct stack {
	int *data;
	int top;
	int size;
}stack;

stack* init(int n) {
	stack *s = (stack*)malloc(sizeof(stack));
	s->data = (int*)malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++) {
		s->data[i] = 0;
	}
	s->top = -1;
	s->size = n;
}

int deinit(stack *s) {
	if(s == NULL) return 0;
	free(s->data);
	free(s);
	return 1;
}

int top(stack *s) {
	return s->data[s->top];
}

int is_empty(stack *s) {
	return s->top == -1;
}

int push(stack *s, int val) {
	if(s == NULL) return 0;
	if(s->top + 1 == s->size) return 0;

	s->top++;
	s->data[s->top] = val;
	return 1;
}

int pop(stack *s) {
	if(s == NULL) return 0;
	if(is_empty(s)) return 0;

	s->top--;
	return 1;
}

void show(stack *s) {
	if(s == NULL) return;

	printf("stack[%d] = { ", s->size);
	for(int i = s->top; i >= 0; i--) {
		printf("%d ", s->data[i]);
	}
	printf("}\n\n");

}

#define MAX_OP 20
int main(int argc, char** argv) {
	stack *s = init(MAX_OP);
	printf("stack init success!\n");
	show(s);
	srand(time(0));

	for(int i = 0; i < MAX_OP; i++) {
		int val = rand() % 100;
		int op = rand() % 2;

		switch(op) {
			case 0: {
				int ret = push(s, val);
				printf("push %d to stack = %d\n",val, ret);
			} break;
			case 1: {
				int val = top(s);
				int ret = pop(s);
				if(ret)
					printf("pop %d from stack = %d\n",val, ret);
			} break;
		}
		show(s);
	}
	return 0;
}