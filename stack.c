//
// Created by usrname on 07.04.2022.
//

#include "stack.h"

stack* create_stack() {
    stack* ptr = (stack*)malloc(sizeof(stack));
    ptr->size = 0;
    ptr->root = (itemLIFO*)malloc(sizeof(itemLIFO));
    ptr->top = ptr->root;
    return ptr;
}

void delete_stack(stack* ptr) {
    while (ptr->top != ptr->root) {
        itemLIFO* temp = (itemLIFO*)ptr->top->lower;
        ptr->top->val = 0;
        ptr->top->lower = NULL;
        free(ptr->top);
        ptr->top = (itemLIFO*)temp;
    }
    ptr->size = 0;
    ptr->root = NULL;
    free(ptr);
}

void push_stack(stack* ptr,stackItem val) {
    if(ptr->size == 0) {
        ptr->root->val = val;
        ptr->root->lower = NULL;
        ptr->top = ptr->root;
    } else {
        itemLIFO* new_item = (itemLIFO*)malloc(sizeof(itemLIFO));
        new_item->val = val;
        new_item->lower = (struct itemLIFO *)ptr->top;
        ptr->top = new_item;
    }
    ptr->size++;
}

void pop_stack(stack* ptr) {
    if(ptr->size > 0) {
        if(ptr->top == ptr->root) {
            ptr->root->val = 0;
        } else {
            itemLIFO* temp = (itemLIFO *)ptr->top->lower;
            ptr->top->val = 0;
            ptr->top->lower = NULL;
            free(ptr->top);
            ptr->top = temp;
        }
        ptr->size--;
    } else {
        printf("The stack is empty!\n");
    }
}

int size_stack(stack* ptr) {
    return ptr->size;
}

stackItem top_stack(stack* ptr) {
    if(ptr->size == 0) {
        printf("The stack is empty!\n");
    } else {
        return ptr->top->val;
    }
}

bool empty_stack(stack* ptr) {
    return ptr->size == 0;
}

void print_stack(stack* ptr) {
    itemLIFO* p = ptr->top;
    for(int i = 0;i < ptr->size;i++) {
        printf("%d",p->val);
        if(i == 0) {
            printf(" <--- top\n");
        } else if(i == ptr->size - 1) {
            printf(" <--- root\n");
        } else {
            printf("\n");
        }
        p = p->lower;
    }
}