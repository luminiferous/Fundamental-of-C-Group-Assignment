#ifndef QUEUE_H_
#define QUEUE_H_

#include "huffman_coding.h"

struct queue
{
    node_t front, back;
    int size, capacity;
    node_t leaves[];
};
typedef struct queue queue_t;

int emptyCheck(queue_t nodeQueue);
int fullCheck(queue_t nodeQueue);


#endif
