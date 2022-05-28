//
// Created by usrname on 08.04.2022.
//

#include "vector.h"

vector* create_vector(int n) {
    vector* ptr = (vector*)malloc(sizeof(vector));
    ptr->size = n;
    ptr->capacity = 1;
    while(ptr->size >= ptr->capacity) {
        ptr->capacity *= 2;
    }
    ptr->data = (vectorItem*)malloc(ptr->capacity * sizeof(vectorItem));
}

void delete_vector(vector* ptr) {
    while(ptr->size) {
        ptr->data[ptr->size - 1] = 0;
        ptr->size--;
    }
    free(ptr->data);
    ptr->capacity = 0;
    free(ptr);
}

int size_vector(vector* ptr) {
    return ptr->size;
}

int capacity_vector(vector* ptr) {
    return ptr->capacity;
}

bool empty_vector(vector* ptr) {
    return ptr->size == 0;
}

void resize_vector(vector* ptr,int n) {
    int capacity = 1;
    while(n >= capacity) {
        capacity *= 2;
    }
    vectorItem* new_data = (vectorItem*)malloc(capacity * sizeof(vectorItem));
    int min_size = ptr->size < n ? ptr->size : n;
    for(int i = 0;i < min_size;i++) {
        new_data[i] = ptr->data[i];
        ptr->data[i] = 0;
    }
    for(int i = min_size;i < n;i++) {
        new_data[i] = 0;
    }
    free(ptr->data);
    ptr->size = n;
    ptr->capacity = capacity;
    ptr->data = new_data;
}

void push_back_vector(vector* ptr,vectorItem val) {
    if(ptr->size == ptr->capacity) {
        resize_vector(ptr, ptr->size);
    }
    ptr->data[ptr->size] = val;
    ptr->size++;
}

void pop_back_vector(vector* ptr) {
    if(ptr->size == 0) {
        printf("The vector is empty!\n");
    }
    else if(ptr->size == ptr->capacity / 2) {
        resize_vector(ptr,ptr->size - 1);
    } else {
        ptr->data[ptr->size - 1] = 0;
        ptr->size--;
    }
}

vectorItem get_elem_vector(vector* ptr,int index) {
    return ptr->data[index];
}

void clear_vector(vector* ptr) {
    while(ptr->size) {
        ptr->data[ptr->size - 1] = 0;
        ptr->size--;
    }
    resize_vector(ptr,0);
}

void print_vector(vector* ptr) {
    for(int i = 0; i < ptr->size;i++) {
        printf("%d",ptr->data[i]);
        if(i == 0) {
            printf(" <--- begin\n");
        } else if(i == ptr->size - 1) {
            printf(" <--- end\n");
        } else {
            printf("\n");
        }
    }
}