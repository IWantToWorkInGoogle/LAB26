//
// Created by usrname on 08.04.2022.
//

#include "deque.h"

deque* create_deque() {
    deque* ptr = (deque*)malloc(sizeof(deque));
    ptr->size = 0;
    ptr->first = NULL;
    ptr->last = NULL;
}

void delete_deque(deque* ptr) {
    while(ptr->size > 0) {
        itemFILO_Deque* temp = (itemFILO_Deque*)ptr->last->prev;
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

void push_front_deque(deque* ptr,dequeItem val) {
    if(ptr->size == 0) {
        ptr->last = (itemFILO_Deque*)malloc(sizeof(itemFILO_Deque));
        ptr->last->val = val;
        ptr->last->next = NULL;
        ptr->last->prev = NULL;
        ptr->first = ptr->last;
    } else if(ptr->size == 1){
        itemFILO_Deque* p = (itemFILO_Deque*) malloc(sizeof(itemFILO_Deque));
        p->val = val;
        ptr->last->prev = p;
        p->prev = NULL;
        p->next = ptr->last;
        ptr->first = p;
    } else {
        itemFILO_Deque* new_item = (itemFILO_Deque*)malloc(sizeof(itemFILO_Deque));
        new_item->val = val;
        ptr->first->prev = new_item;
        new_item->next = ptr->first;
        new_item->prev = NULL;
        ptr->first = new_item;
    }
    ptr->size++;
}

void push_back_deque(deque* ptr,dequeItem val) {
    if(ptr->size == 0) {
        ptr->first = (itemFILO_Deque*)malloc(sizeof(itemFILO_Deque));
        ptr->first->val = val;
        ptr->first->next = NULL;
        ptr->first->prev = NULL;
        ptr->last = ptr->first;
    } else if(ptr->size == 1) {
        itemFILO_Deque* p = (itemFILO_Deque*)malloc(sizeof(itemFILO_Deque));
        p->val = val;
        ptr->first->next = p;
        p->prev = ptr->first;
        p->next = NULL;
        ptr->last = p;
    } else {
        itemFILO_Deque* new_item = (itemFILO_Deque*)malloc(sizeof(itemFILO_Deque));
        new_item->val = val;
        ptr->last->next = new_item;
        new_item->prev = ptr->last;
        new_item->next = NULL;
        ptr->last = new_item;

    }
    ptr->size++;
}

void pop_front_deque(deque* ptr) {
    if(ptr->size == 1) {
        ptr->first->val = 0;
        ptr->first->next = NULL;
        ptr->first->prev = NULL;
        free(ptr->first);
        ptr->first = NULL;
        ptr->last = ptr->first;
        ptr->size--;
    } else if(ptr->size > 1) {
        itemFILO_Deque* temp = ptr->first->next;
        ptr->first->val = 0;
        ptr->first->next = NULL;
        ptr->first->prev = NULL;
        temp->prev = NULL;
        free(ptr->first);
        ptr->first = temp;
        ptr->size--;
    } else {
        printf("The deque is empty!\n");
    }
}

void pop_back_deque(deque* ptr) {
    if(ptr->size == 1) {
        ptr->last->val = 0;
        ptr->last->prev = NULL;
        ptr->last->next = NULL;
        free(ptr->last);
        ptr->last = NULL;
        ptr->first = ptr->last;
        ptr->size--;
    } else if(ptr->size > 1) {
        itemFILO_Deque* temp = ptr->last->prev;
        ptr->last->val = 0;
        ptr->last->prev = NULL;
        temp->next = NULL;
        free(ptr->last);
        ptr->last = temp;
        ptr->size--;
    } else {
        printf("The deque is empty!\n");
    }
}

void clear_deque(deque* ptr) {
    while(ptr->size > 0) {
        pop_back_deque(ptr);
    }
}

int size_deque(deque* ptr) {
    return ptr->size;
}

bool empty_deque(deque* ptr) {
    return ptr->size == 0;
}

int front_deque(deque* ptr) {
    if(ptr->size == 0) {
        printf("The deque is empty!\n");
    }
    return ptr->first->val;
}

int back_deque(deque* ptr) {
    if(ptr->size == 0) {
        printf("The deque is empty!\n");
    }
    return ptr->last->val;
}

void print_deque(deque* ptr) {
    if(ptr->size == 0) {
        printf("The deque is empty!\n");
    } else {
        itemFILO_Deque *p = ptr->first;
        for(int i = 0;i < ptr->size;i++) {
            printf("%d",p->val);
            if(i == 0) {
                printf(" <--- front\n");
            } else if(i == ptr->size - 1) {
                printf(" <--- back\n");
            } else {
                printf("\n");
            }
        }
    }
}