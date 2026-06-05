/*
 * POINTERS EXERCISE 2 - Pointer Arithmetic & Arrays
 * Reference: https://beej.us/guide/bgc/html/split/pointers2.html
 *
 * TASK: Complete the functions below so the program compiles
 * and produces the expected output.
 *
 * Compile with: gcc -o pointers_ex2 pointers_ex2.c
 */

#include <stdio.h>

/*
 * TASK 1:
 * Complete this function so that it returns the sum of
 * all elements in the array using POINTER ARITHMETIC only.
 * You must NOT use array indexing syntax (e.g. arr[i]).
 * Use pointer increment instead.
 */
int sum_array(int *arr, int len) {
    int sum = 0;
    /* YOUR CODE HERE */

    for (int i = 0; i < len; i++) {
        sum += *arr;

        arr++;
    }

    return sum;
}

/*
 * TASK 2:
 * Complete this function so that it reverses the array
 * IN PLACE using pointers.
 * Hint: use two pointers, one at the start and one at the end.
 */
void reverse_array(int *arr, int len) {
    /* YOUR CODE HERE */
    int *tail = arr + len - 1;

    while (tail > arr) {
        int temp = *arr;

        *arr = *tail;
        *tail = temp;

        arr++;
        tail--;
    }

}

/*
 * TASK 3:
 * Complete this function so that it finds and returns
 * a pointer to the first occurrence of 'target' in the array.
 * Return NULL if target is not found.
 * You must use pointer arithmetic, not array indexing.
 */
int *find_first(int *arr, int len, int target) {
    /* YOUR CODE HERE */
    for (int i = 0; i < len; i++) {
        if (*arr == target) {
            return arr;
        } 

        arr++;
    }

    return NULL;
}

int main(void) {
    int arr1[] = {1, 2, 3, 4, 5};
    int len = 5;

    /* TASK 1 test */
    int result = sum_array(arr1, len);
    printf("Task 1 - Expected: 15, Got: %d\n", result);

    /* TASK 2 test */
    int arr2[] = {1, 2, 3, 4, 5};
    reverse_array(arr2, len);
    printf("Task 2 - Expected: 5 4 3 2 1, Got: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    /* TASK 3 test */
    int arr3[] = {10, 20, 30, 40, 50};
    int *ptr = find_first(arr3, 5, 30);
    if (ptr != NULL) {
        printf("Task 3 - Expected: 30, Got: %d\n", *ptr);
    } else {
        printf("Task 3 - Got NULL, expected to find 30\n");
    }

    int *ptr2 = find_first(arr3, 5, 99);
    printf("Task 3 - Expected: NULL, Got: %s\n", ptr2 == NULL ? "NULL" : "not NULL");

    return 0;
}
