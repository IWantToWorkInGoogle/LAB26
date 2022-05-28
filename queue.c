//
// Created by usrname on 08.04.2022.
//

#include "queue.h"

queue* create_queue() {
    queue* ptr = (queue*)malloc(sizeof(queue));
    ptr->size = 0;
    ptr->first = NULL;
    ptr->last = NULL;
}

void delete_queue(queue* ptr) {
    while(ptr->size > 0) {
        itemFILO_Queue *temp = ptr->last->prev;
        ptr->last->val = 0;
        ptr->last->next = NULL;
        ptr->last->prev = NULL;
        free(ptr->last);
        ptr->last = temp;
        ptr->size--;
    }
    ptr->size = 0;
    ptr->first = NULL;
    ptr->last = NULL;
    free(ptr);
}

void push_queue(queue* ptr,int val) {
        if(ptr->size == 0) {
            ptr->first = (itemFILO_Queue*)malloc(sizeof(itemFILO_Queue));
            ptr->first->val = val;
            ptr->first->prev = NULL;
            ptr->first->next = NULL;
            ptr->last = ptr->first;
        } else if(ptr->size == 1) {
            itemFILO_Queue* p= (itemFILO_Queue*)malloc(sizeof(itemFILO_Queue));
            p->val = val;
            ptr->first->next = p;
            p->prev = ptr->first;
            p->next = NULL;
            ptr->last = p;
        } else {
            itemFILO_Queue* new_item = (itemFILO_Queue*)malloc(sizeof(itemFILO_Queue));
            new_item->val = val;
            ptr->last->next = new_item;
            new_item->prev = ptr->last;
            new_item->next = NULL;
            ptr->last = new_item;
        }
        ptr->size++;
}

void pop_queue(queue* ptr) {
    if(ptr->size == 1) {
        ptr->first->val = 0;
        ptr->first->prev = NULL;
        ptr->first->next = NULL;
        free(ptr->first);
        ptr->first = NULL;
        ptr->last = ptr->first;
        ptr->size--;
    } else if(ptr->size > 1) {
        itemFILO_Queue* temp = ptr->first->next;
        ptr->first->val = 0;
        ptr->first->next = NULL;
        ptr->first->prev = NULL;
        temp->prev = NULL;
        free(ptr->first);
        ptr->first = temp;
        ptr->size--;
    } else {
        printf("The queue is empty!\n");
    }
}

queueItem front_queue(queue* ptr) {
    if(ptr->size == 0) {
        printf("The queue is empty!\n");
    }
    return ptr->first->val;
}

queueItem back_queue(queue* ptr) {
    if(ptr->size == 0) {
        printf("The queue is empty!\n");
    }
    return ptr->last->val;
}

bool empty_queue(queue* ptr) {
    return ptr->size == 0;
}

int size_queue(queue* ptr) {
    return ptr->size;
}

void clear_queue(queue* ptr) {
    while(ptr->size > 0) {
        pop_queue(ptr);
    }
}

void print_queue(queue* ptr) {
    if(ptr->size == 0) {
        printf("The queue is empty!\n");
    } else {
        itemFILO_Queue *p = ptr->first;
        for (int i = 0; i < ptr->size; i++) {
            printf("%d ", p->val);
            if(i == 0) {
                printf(" <--- front\n");
            } else if(i == ptr->size - 1) {
                printf(" <--- back\n");
            } else {
                printf("\n");
            }
            p = p->next;
        }
    }
}