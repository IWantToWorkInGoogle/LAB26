//
// Created by usrname on 08.04.2022.
//

#ifndef LAB26_VECTOR_H
#define LAB26_VECTOR_H

#endif //LAB26_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int vectorItem;

typedef struct {
    int size;
    int capacity;
    vectorItem* data;
} vector;

vector* create_vector(int n);
void delete_vector(vector* ptr);
int size_vector(vector* ptr);
int capacity_vector(vector* ptr);
bool empty_vector(vector* ptr);
void resize_vector(vector* ptr,int n);
void push_back_vector(vector* ptr,vectorItem val);
void pop_back_vector(vector* ptr);
vectorItem get_elem_vector(vector* ptr,int index);
void clear_vector(vector* ptr);
void print_vector(vector* ptr);