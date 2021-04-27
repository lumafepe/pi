#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

// Static queues 

void SinitQueue (SQueue q){
	q->length = 0;
    q->front = 0;
}

int  SisEmptyQ (SQueue q){
    return q->length == 0;
}

int  Senqueue (SQueue q, int x){
    int r = 0;
    if (q->length < Max) q->values[(q->front + q->length++) % Max] =x;
    else r=1;
	return r;
}

int  Sdequeue (SQueue q, int *x) {
	int r=0;
    if (!SisEmptyQ(q)){
        *x=q->values[q->front++];
        q->length--;
        q->front = q->front%Max;
    }
    else r=1;
	return r;
}

int  Sfront (SQueue q, int *x) {
    int r=0;
    if (!SisEmptyQ(q)) *x=q->values[q->front++];
    else r=1;
	return r;
}

void ShowSQueue (SQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%Max;
    }
    putchar ('\n');
}
// Queues with dynamic arrays

int dupQueue (DQueue q) {
	int r = 0, i;
	int *t = malloc (2*q->size*sizeof(int));

	if (t == NULL) r = 1;
	else {
		for (i=0; i<q->size; i++) 
			t[i] = q->values[i];
		free (q->values);
		q->values = t;
		q->size*=2;
	}
	return r;
}

void DinitQueue (DQueue q) {
	q->front=0;
    q->size=Max;
    q->length=0;
    q->values=(int *) malloc(sizeof(int)*q->size);
}

int  DisEmptyQ (DQueue s) {
	return s->length == 0;
}

int  Denqueue (DQueue q, int x){
	int r = 0;
    if (q->length == q->size) r=dupQueue(q);
    if (!r) q->values[(q->front + q->length++) % q->size] =x;
	return r;
}

int  Ddequeue (DQueue q, int *x){
	int r=0;
    if (!DisEmptyQ(q)){
        *x=q->values[q->front++];
        q->length--;
        q->front = q->front%Max;
    }
    else r=1;
	return r;
}


int  Dfront (DQueue q, int *x){
	int r=0;
    if (!DisEmptyQ(q)) *x=q->values[q->front];
    else r=1;
	return r;
}

void ShowDQueue (DQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%q->size;
    }
    putchar ('\n');
}