#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "dbg.h"

int main(void) {

    int num_testcase;

    scanf("%d", &num_testcase);
    debug("num_testcase: %d\n",num_testcase);  

    while (num_testcase--) {
        Heap* priority_queue;
        int N, K;
        int* input_array;
        int input;
        int i;

        priority_queue = (Heap*)malloc(sizeof(Heap));
        priority_queue->pos = 0;
        priority_queue->cap_unit = 500;
        priority_queue->capacity = priority_queue->cap_unit;
        priority_queue->ar = (int*)malloc(sizeof(int) * priority_queue->capacity);

        scanf("%d", &N);
        scanf("%d", &K);
        debug("N: %d, K: %d", N, K);
        input_array = (int*)malloc(sizeof(int) * N);
        for (i = 0; i < N; i++) {
            scanf("%d", &input);
            input_array[i] = input;
            debug("new input: %d", input);
        }

        debug("start iteration");
        debug("heap pos: %d", priority_queue->pos);
        for (i = 0; i < K; i++) {
            debug("insert");
            heap_insert(priority_queue, input_array[i]);
        }
        for (i = K; i < N; i++) {
            input_array[i-K] = heap_pop(priority_queue);
            debug("popped1 on %d: %d", i-K, input_array[i-K]);
            heap_insert(priority_queue, input_array[i]);
        }
        for (i = N-K; i < N; i++) {
            input_array[i] = heap_pop(priority_queue);
            debug("popped2 on %d: %d", i, input_array[i]);
        }
       
        for (i = 0; i < N; i++) {
            printf("%d ", input_array[i]);
        }
        printf("\n");
        
        free(input_array);
        free(priority_queue->ar);
        free(priority_queue);
    }



    return 0;
}
