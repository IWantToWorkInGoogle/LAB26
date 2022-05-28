//
// Created by usrname on 15.04.22.
//

#include "sorting.h"

stack* reverse_stack(stack* ptr) {
    stack* new_ptr = create_stack();
    while(ptr->size > 0) {
        push_stack(new_ptr, top_stack(ptr));
        pop_stack(ptr);
    }
    delete_stack(ptr);
    return new_ptr;
}

stack* merge_stack(stack* s1,stack* s2) {
    stack* s3 = create_stack();
    while(s1->size > 0 || s2->size > 0) {
        if(s1->size == 0) {
            push_stack(s3, top_stack(s2));
            pop_stack(s2);
        } else if(s2->size == 0) {
            push_stack(s3, top_stack(s1));
            pop_stack(s1);
        } else {
            if(top_stack(s1) > top_stack(s2)) {
                push_stack(s3, top_stack(s1));
                pop_stack(s1);
            } else {
                push_stack(s3, top_stack(s2));
                pop_stack(s2);
            }
        }
    }
    delete_stack(s1);
    delete_stack(s2);
    return s3;
}

stack* mergeSort_stack(stack* s) {
    if(s->size <= 1) {
        return s;
    } else if(s->size == 2){
        stackItem s1 = top_stack(s);
        pop_stack(s);
        stackItem s2 = top_stack(s);
        pop_stack(s);
        if(s1 > s2) {
            push_stack(s,s1);
            push_stack(s,s2);
        } else {
            push_stack(s,s2);
            push_stack(s,s1);
        }
        return s;
    } else {
        int n = s->size / 2;
        stack* s1 = create_stack();
        for(int i = 0;i < n;i++) {
            push_stack(s1, top_stack(s));
            pop_stack(s);
        }
        stack* s2 = create_stack();
        while(s->size > 0) {
            push_stack(s2, top_stack(s));
            pop_stack(s);
        }
        s1 = reverse_stack(mergeSort_stack(s1));
        s2 = reverse_stack(mergeSort_stack(s2));

        return merge_stack(s1,s2);
    }
}