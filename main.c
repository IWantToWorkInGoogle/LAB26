#include "vector.h"
#include "sorting.h"
#include "queue.h"
#include "list.h"


int main() {
    bool programStatus = true;
    stack* s = create_stack();
    while(programStatus) {
        printf("Main menu:\n1)Push\n2)Pop\n3)Size of the stack\n4)Top of the stack\n5)Is empty?\n6)Print the stack\n7)Sort the stack\n8)Exit\n");
        printf("Choose the option: ");
        char* input = (char*)malloc(sizeof(char));
        scanf("%s",input);
        int command = atoi(input);
        switch (command) {
            case 1:
                printf("Insert the value: ");
                scanf("%s",input);
                int val = atoi(input);
                push_stack(s,val);
                break;
            case 2:
                pop_stack(s);
                printf("The value was poped!\n");
                break;
            case 3:
                printf("The size of the stack: %d\n", size_stack(s));
                break;
            case 4:
                printf("The top of the stack: %d\n", top_stack(s));
                break;
            case 5:
                printf("Is empty? ");
                if(empty_stack(s)) {
                    printf("YES\n");
                } else {
                    printf("NO\n");
                }
                break;
            case 6:
                printf("The stack:\n");
                print_stack(s);
                break;
            case 7:
                s = mergeSort_stack(s);
                printf("The stack was sorted!\n");
                break;
            case 8:
                programStatus = false;
                break;
            default:
                printf("Invalid value!\n");
                break;
        }
    }
    delete_stack(s);
    return 0;
}
