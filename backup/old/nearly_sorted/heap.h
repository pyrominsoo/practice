#ifndef _HEAP_
#define _HEAP_


typedef struct Heap {
    int* ar;
    unsigned int pos;
    unsigned int capacity;
    unsigned int cap_unit;
} Heap;

int heap_insert(Heap* heap,int new_val);

int heap_pop(Heap* heap);

int heap_empty(Heap* heap);

int heap_cap_inc(Heap* heap) ;

void heapifyUp(Heap* heap) ;

void heapifyDown(Heap* heap) ;

#endif
