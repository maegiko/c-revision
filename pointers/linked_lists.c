/*
 * POINTERS EXERCISE 5 - Linked Lists
 * Reference: https://beej.us/guide/bgc/html/split/structs.html
 *
 * Linked lists are used extensively in OS/161 for managing
 * kernel data structures like thread queues, process lists,
 * and free memory blocks. This exercise builds on everything
 * you've learned so far — structs, pointers, malloc, and free.
 *
 * TASK: Complete the functions below so the program compiles
 * and produces the expected output.
 *
 * Compile with: gcc -o pointers_ex5 pointers_ex5.c
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

/*
 * TASK 1:
 * Complete this function so that it creates a new Node
 * on the heap with the given value and next pointer.
 * Return NULL if allocation fails.
 */
Node *create_node(int value, Node *next) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) return NULL;

    new_node->value = value;
    new_node->next = next;

    return new_node;
}

/*
 * TASK 2:
 * Complete this function so that it inserts a new node
 * at the FRONT of the linked list and returns the new head.
 * Example: insert_front(head, 5) on list [1->2->3]
 *          returns new head of [5->1->2->3]
 */
Node *insert_front(Node *head, int value) {
    Node *new_head = create_node(value, head);

    return new_head;
}

/*
 * TASK 3:
 * Complete this function so that it inserts a new node
 * at the BACK of the linked list and returns the head.
 * Example: insert_back(head, 5) on list [1->2->3]
 *          returns head of [1->2->3->5]
 * Note: if head is NULL, the new node becomes the head.
 */
Node *insert_back(Node *head, int value) {
    if (head == NULL) {
        head = create_node(value, NULL);
        return head;
    }

    Node *curr;
    for (curr = head; curr->next != NULL; curr = curr->next)
    ;
    
    curr->next = create_node(value, NULL);

    return head;
}

/*
 * TASK 4:
 * Complete this function so that it prints all values
 * in the linked list on one line separated by " -> "
 * with a newline at the end.
 * Example output: 1 -> 2 -> 3
 */
void print_list(Node *head) {
    if (head == NULL) {
        printf("\n");
        return;
    }

    for (Node *curr = head; curr != NULL; curr = curr->next) {
        printf("%d", curr->value);

        if (curr->next) {
            printf(" -> ");
        } else {
            printf("\n");
        }
    }
}

/*
 * TASK 5:
 * Complete this function so that it frees all nodes
 * in the linked list.
 * Be careful about the order you free nodes.
 */
void free_list(Node *head) {
    if (head == NULL) return;

    Node *curr = head;
    while (curr != NULL) {
        Node *free_node = curr;
        curr = curr->next;

        free(free_node);
    }
}

int main(void) {
    /* TASK 1 & 2 test */
    Node *head = NULL;
    head = insert_front(head, 3);
    head = insert_front(head, 2);
    head = insert_front(head, 1);
    printf("Task 2 - Expected: 1 -> 2 -> 3\n");
    printf("         Got:      ");
    print_list(head);
    free_list(head);

    /* TASK 3 test */
    head = NULL;
    head = insert_back(head, 1);
    head = insert_back(head, 2);
    head = insert_back(head, 3);
    printf("Task 3 - Expected: 1 -> 2 -> 3\n");
    printf("         Got:      ");
    print_list(head);
    free_list(head);

    /* Mixed test */
    head = NULL;
    head = insert_back(head, 2);
    head = insert_back(head, 3);
    head = insert_front(head, 1);
    printf("Mixed  - Expected: 1 -> 2 -> 3\n");
    printf("         Got:      ");
    print_list(head);
    free_list(head);

    return 0;
}