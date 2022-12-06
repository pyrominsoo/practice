#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "dbg.h"

int heap_insert(Heap* heap,int new_val) {
    if (heap->pos == heap->capacity) {
        debug("expanding capacity");
        if (!heap_cap_inc(heap)) {
            printf("at function heap_insert: failed to heap_cap_int");
            return 0;
        }
    }

    heap->ar[heap->pos] = new_val;
    heap->pos++;
    heapifyUp(heap);
    debug("heap_insert: pos %d", heap->pos);
    debug("heap_insert: new_val %d", new_val);
    debug("heap_insert: heap_head %d", heap->ar[0]);
    return 1;
}

int heap_pop(Heap* heap) {
    int result;

    result = heap->ar[0];
    heap->pos--;
    heap->ar[0] = heap->ar[heap->pos];
    heapifyDown(heap);
    return result;
}

int heap_empty(Heap* heap) {
    if (heap->pos == 0) {
        return 1;
    } else {
        return 0;
    }
}


int heap_cap_inc(Heap* heap) {
    int i;
    int* temp_ar;
   
    unsigned int new_cap;

    new_cap = heap->capacity + heap->cap_unit;
    temp_ar = (int*)malloc( new_cap * sizeof(int) );

    if (temp_ar == NULL) {
        printf("at function heap_cap_inc: failed to malloc new array");
        return 0;
    }

    for (i = 0; i < heap->capacity; i++) {
        temp_ar[i] = heap->ar[i];    
    }

    free(heap->ar);
    heap->ar = temp_ar;
    heap->capacity = new_cap;
    return 1;
}

void heapifyUp(Heap* heap) {
    int p_pos;
    int cur_pos;
    int temp_val;
  
    cur_pos = heap->pos - 1;
    p_pos =  (cur_pos - 1) / 2;
    while (p_pos >= 0 ) {
        if (heap->ar[cur_pos] < heap->ar[p_pos]) {
            temp_val = heap->ar[p_pos];
            heap->ar[p_pos] = heap->ar[cur_pos];
            heap->ar[cur_pos] = temp_val;
            
            cur_pos = p_pos;
            p_pos = (cur_pos - 1) / 2 ;
        } else {
            break;
        }
    }
}

void heapifyDown(Heap* heap) {
    int left_c_pos;
    int right_c_pos;
    int smaller_c_pos;
    int cur_pos;
    int left_c_val;
    int right_c_val;
    int smaller_c_val;
    int cur_val;
    int temp_val;

    cur_pos = 0;
    left_c_pos = cur_pos * 2 + 1;
    right_c_pos = cur_pos * 2 + 2;

    while (left_c_pos < heap->pos) {
        left_c_val = heap->ar[left_c_pos];
        if (right_c_pos < heap->pos) {
            right_c_val = heap->ar[right_c_pos];    
            if (left_c_val <= right_c_val) {
                smaller_c_val = left_c_val;
                smaller_c_pos = left_c_pos;
            } else {
                smaller_c_val = right_c_val;
                smaller_c_pos = right_c_pos;
            }
        } else {
            smaller_c_val = left_c_val;
            smaller_c_pos = left_c_pos;
        }

        cur_val = heap->ar[cur_pos];
        if (cur_val > smaller_c_val) {
            temp_val = cur_val;
            heap->ar[cur_pos] = heap->ar[smaller_c_pos];
            heap->ar[smaller_c_pos] = temp_val;

            cur_pos = smaller_c_pos;
            left_c_pos = cur_pos * 2 + 1;
            right_c_pos = cur_pos * 2 + 2;
        } else {
            break;
        }
    }
}

