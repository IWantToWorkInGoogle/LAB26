//
// Created by usrname on 07.04.2022.
//

#ifndef LAB26_UDT_H
#define LAB26_UDT_H
#endif //LAB26_UDT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef int stackItem;

typedef struct _itemLIFO {
    stackItem val;
    struct itemLIFO* lower;
} itemLIFO;

typedef struct {
    int size;
    itemLIFO* root;
    itemLIFO* top;
} stack;

stack* create_stack();
void delete_stack(stack* ptr);
void push_stack(stack* ptr,stackItem val);
void pop_stack(stack* ptr);
int size_stack(stack* ptr);
stackItem top_stack(stack* ptr);
bool empty_stack(stack* ptr);
void print_stack(stack* ptr);