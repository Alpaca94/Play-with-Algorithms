#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct Vector {
	int *data;
	int size;
	int length;
}Vector;

Vector* init(int n) {
	Vector *vec = (Vector*)malloc(sizeof(Vector));
	vec->data = (int*)malloc(sizeof(int)*n);
	vec->size = n;
	vec->length = 0;
}

void clear(Vector *v) {
	if(v != NULL) {
		free(v->data);
		free(v);
	}
}

int insert(Vector *v,int index,int val) {
	if(v == NULL) {
		printf("Vector is NULL!\n");
		return 0;
	}
	if(v->length == v->size) {
		printf("Vector is full\n");
		return 0;
	}
	if(index < 0 || index > v->length ) {
		printf("the index is error\n");
		return 0;
	}

	for(int i = v->length; i > index; i-- ) {
		v->data[i] = v->data[i-1];
	}
	v->data[index] = val;
	v->length++;
	return 1;
}

int erase(Vector *v,int index) {
	if(v == NULL) {
		printf("Vector is NULL!\n");
		return 0;
	}
	if(v->length == 0) {
		printf("Vector is empty!\n");
		return 0;
	}
	if(index < 0 || index >= v->length ) {
		printf("the index is error\n");
		return 0;
	}
	for(int i = index; i < v->length-1; i++) {
		v->data[i] = v->data[i+1];
	}
	v->length--;
	return 1;
}

void show(Vector *v) {
	if(v != NULL) {
		printf("Vector(%d) = [",v->length);
		for(int i = 0; i < v->length; i++) {
			if(i != 0)
				printf(", ");
			printf("%d ",v->data[i]);
		}
		printf("]");
	}
	printf("\n");
}

#define MAX_SIZE 20
int main(int argc, char *argv[]) {
	int op;
	int index;
	int val;

	srand(time(0));
	Vector *v = init(MAX_SIZE);
	for(int i = 0; i < MAX_SIZE; i++) {
		op = rand() % 2;
		index = rand() % (v->length + 1);
		int val = rand() % 10 + 1;
		switch (op) {
			case 0: {
    			printf("insert %d at %d to vector,res = %d\n",val,index,insert(v,index,val));
			}break;
			case 1: {
				printf("delete item at %d to vector,res = %d\n",index,erase(v,index));
			}
			break;
			default:
				break;
		}
		show(v);
	}

	return 0;
}