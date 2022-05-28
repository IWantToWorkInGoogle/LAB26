//
// Created by usrname on 08.04.2022.
//

#include "list.h"

list* create_list() {
    list* ptr = (list*)malloc(sizeof(list));
    ptr->size = 0;
    ptr->head = NULL;
    ptr->end = NULL;
    return ptr;
}

void delete_list(list* ptr) {
    listItem* p = ptr->head;
    int n = ptr->size;
    for(int i = 0;i < n;i++) {
        listItem* t = p->next;
        p->prev = NULL;
        p->val = NULL;
        p->next = NULL;
        free(p);
        p = t;
    }
    ptr->size = 0;
    free(ptr);
}

void append_list(list* ptr,value val) {
    if(ptr->size == 0) {
        ptr->head = (listItem*)malloc(sizeof(listItem));
        ptr->head->val = val;
        ptr->head->prev = NULL;
        ptr->head->next = NULL;
        ptr->end = ptr->head;
    } else if(ptr->size == 1) {
        listItem* new_item = (listItem*)malloc(sizeof(listItem));
        new_item->val = val;
        new_item->prev = ptr->head;
        new_item->next = NULL;
        ptr->head->next = new_item;
        ptr->end = new_item;
    } else {
        listItem* new_item = (listItem*) malloc(sizeof(listItem));
        new_item->val = val;
        new_item->prev = ptr->end;
        new_item->next = NULL;
        ptr->end->next = new_item;
        ptr->end = new_item;
    }
    ptr->size++;
}

void pop_list(list* ptr) {
    if(ptr->size == 0) {
        printf("The list is empty!\n");
    } else if(ptr->size == 1) {
        ptr->head->val = 0;
        ptr->head->next = NULL;
        ptr->head->prev = NULL;
        free(ptr->head);
    } else {
        listItem* p = ptr->end->prev;
        ptr->end->val = 0;
        ptr->end->prev = NULL;
        ptr->end->next = NULL;
        free(ptr->end);
        ptr->end = p;
    }
}

void clear_list(list* ptr) {
    while(ptr->size > 0) {
        pop_list(ptr);
    }
}

void erase_list(list* ptr,int index) {
    if(index < 0 || index >= ptr->size) {
        printf("The index is out of border\n");
    }
}

void print_vertical_list(list* ptr) {
    listItem* p = ptr->head;
    for(int i = 0;i < ptr->size;i++) {
        printf("%d\t",p->val);
        if(i == 0) {
            printf("<--- head");
        } else if(i == ptr->size - 1) {
            printf("<--- end");
        }
        printf("\n");
        p = p->next;
    }
}

void print_horisontal_list(list* ptr) {
    listItem* p = ptr->head;
    printf("head ---> ");
    for(int i = 0;i < ptr->size;i++) {
        printf("%d ",p->val);
        p = p->next;
    }
    printf("<--- end\n");
}

void insert_list(list* ptr,int index,value val) {
    if(index < 0 || index >= ptr->size) {
        printf("The index is out of border\n");
    } else {
        listItem* new_item = (listItem*)malloc(sizeof(listItem));
        new_item->val = val;
        if(index == 0) {
            new_item->next = ptr->head;
            ptr->head->prev = new_item;
            ptr->head = new_item;
        } else if(index == ptr->size - 1) {
            new_item->prev = ptr->head;
            ptr->head->next = new_item;
            ptr->head = new_item;
        } else {
            listItem* n = ptr->head;
            for(int i = 0;i < index;i++) {
                n = n->next;
            }
            listItem* p = n->prev;
            p->next = new_item;
            new_item->prev = p;
            n->prev = new_item;
            new_item->next = n;
        }
        ptr->size++;
    }
}