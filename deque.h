//
// Created by usrname on 08.04.2022.
//

#ifndef LAB26_DEQUE_H
#define LAB26_DEQUE_H

#endif //LAB26_DEQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int dequeItem;

typedef struct _itemFILO_Deque {
    dequeItem val;
    struct itemFILO_Deque* prev;
    struct itemFILO_Deque* next;
} itemFILO_Deque;

typedef struct _deque {
    int size;
    itemFILO_Deque* first;
    itemFILO_Deque* last;
} deque;

deque* create_deque();
void delete_deque(deque* ptr);
void push_front_deque(deque* ptr,dequeItem val);
void push_back_deque(deque* ptr,dequeItem val);
void pop_front_deque(deque* ptr);
void pop_back_deque(deque* ptr);
void clear_deque(deque* ptr);
int size_deque(deque* ptr);
bool empty_deque(deque* ptr);
int front_deque(deque* ptr);
int back_deque(deque* ptr);
void print_deque(deque* ptr);