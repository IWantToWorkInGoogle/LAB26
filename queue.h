//
// Created by usrname on 08.04.2022.
//

#ifndef LAB26_QUEUE_H
#define LAB26_QUEUE_H
#endif //LAB26_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef int queueItem;

typedef struct _itemFILO_Queue {
    queueItem val;
    struct itemFILO_Queue* prev;
    struct itemFILO_Queue* next;
} itemFILO_Queue;

typedef struct {
    size_t size;
    itemFILO_Queue* first;
    itemFILO_Queue* last;
} queue;

queue* create_queue();
void delete_queue(queue* ptr);
void push_queue(queue* ptr,int val);
void pop_queue(queue* ptr);
queueItem front_queue(queue* ptr);
queueItem back_queue(queue* ptr);
bool empty_queue(queue* ptr);
int size_queue(queue* ptr);
void clear_queue(queue* ptr);
void print_queue(queue* ptr);