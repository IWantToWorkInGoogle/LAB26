//
// Created by usrname on 08.04.2022.
//

#ifndef LAB26_LIST_H
#define LAB26_LIST_H

#endif //LAB26_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int value;

typedef struct listItem{
    value val;
    struct listItem* next;
    struct listItem* prev;
} listItem;

typedef struct {
    int size;
    listItem* head;
    listItem* end;
} list;

list* create_list();
void delete_list(list* ptr);
void append_list(list* ptr,value val);
void pop_list(list* ptr);
void clear_list(list* ptr);
void print_vertical_list(list* ptr);
void print_horisontal_list(list* ptr);
void insert_list(list* ptr,int index,value val);
