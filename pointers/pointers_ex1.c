/*
 * POINTERS EXERCISE 1 - Basic Pointers
 * Reference: https://beej.us/guide/bgc/html/split/pointers.html
 *
 * TASK: Complete the functions below so the program compiles
 * and produces the expected output.
 *
 * Compile with: gcc -o pointers_ex1 pointers_ex1.c
 */

#include <stdio.h>

/*
 * TASK 1:
 * Complete this function so that it doubles the value
 * stored at the memory address pointed to by 'n'.
 * It should NOT return anything — it must modify the
 * original variable directly via the pointer.
 */
void double_value(int *n) {
    /* YOUR CODE HERE */
    *n = *n * 2;
}

/*
 * TASK 2:
 * Complete this function so that it swaps the values
 * of the two integers pointed to by 'a' and 'b'.
 */
void swap(int *a, int *b) {
    /* YOUR CODE HERE */
    int temp = *a;

    *a = *b;
    *b = temp;
}

/*
 * TASK 3:
 * Complete this function so that it stores the sum
 * and product of x and y into the locations pointed
 * to by 'sum' and 'product'.
 */
void sum_and_product(int x, int y, int *sum, int *product) {
    /* YOUR CODE HERE */
    *sum = x + y;
    *product = x * y;
}

int main(void) {
    /* TASK 1 test */
    int a = 5;
    double_value(&a);
    printf("Task 1 - Expected: 10, Got: %d\n", a);

    /* TASK 2 test */
    int x = 3, y = 7;
    swap(&x, &y);
    printf("Task 2 - Expected: x=7 y=3, Got: x=%d y=%d\n", x, y);

    /* TASK 3 test */
    int s, p;
    sum_and_product(4, 5, &s, &p);
    printf("Task 3 - Expected: sum=9 product=20, Got: sum=%d product=%d\n", s, p);

    return 0;
}
