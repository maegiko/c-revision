/*
 * POINTERS EXERCISE 3 - Pointers to Structs & Arrow Operator
 * Reference: https://beej.us/guide/bgc/html/split/structs.html
 *
 * This is very relevant to OS/161 — kernel data structures like
 * threads, processes, and linked lists are all structs accessed
 * via pointers.
 *
 * TASK: Complete the functions below so the program compiles
 * and produces the expected output.
 *
 * Compile with: gcc -o pointers_ex3 pointers_ex3.c
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[64];
    int age;
    int student_id;
} Student;

/*
 * TASK 1:
 * Complete this function so that it prints a student's details.
 * You MUST use the arrow operator (->) to access fields.
 * Expected output format:
 *   Name: Alice, Age: 20, ID: 1234
 */
void print_student(Student *s) {
    /* YOUR CODE HERE */
    printf("Name: %s, Age: %d, ID: %d \n", s->name, s->age, s->student_id);
}

/*
 * TASK 2:
 * Complete this function so that it sets the fields of
 * the student pointed to by 's'.
 * You MUST use the arrow operator (->) to set fields.
 * Use strcpy() to set the name.
 */
void init_student(Student *s, const char *name, int age, int id) {
    /* YOUR CODE HERE */
    strcpy(s->name, name);
    s->age = age;
    s->student_id = id;
}

/*
 * TASK 3:
 * Complete this function so that it finds and returns a pointer
 * to the oldest student in the array.
 * If the array is empty (len == 0), return NULL.
 */
Student *find_oldest(Student *arr, int len) {
    /* YOUR CODE HERE */
    if (len == 0) return NULL;
    
    Student *oldest = arr;
    int oldestAge = arr->age;

    for (int i = 0; i < len; i++) {
        if (arr->age > oldestAge) {
            oldestAge = arr->age;
            oldest = arr;
        }

        arr++;
    }

    return oldest;
}

int main(void) {
    /* TASK 1 & 2 test */
    Student s1;
    init_student(&s1, "Alice", 20, 1234);
    print_student(&s1);
    /* Expected: Name: Alice, Age: 20, ID: 1234 */

    Student s2;
    init_student(&s2, "Bob", 25, 5678);
    print_student(&s2);
    /* Expected: Name: Bob, Age: 25, ID: 5678 */

    /* TASK 3 test */
    Student students[3];
    init_student(&students[0], "Carol", 22, 1111);
    init_student(&students[1], "Dave", 28, 2222);
    init_student(&students[2], "Eve", 19, 3333);

    Student *oldest = find_oldest(students, 3);
    if (oldest != NULL) {
        printf("Oldest - Expected: Dave, Got: %s\n", oldest->name);
    }

    /* Edge case */
    Student *none = find_oldest(students, 0);
    printf("Empty - Expected: NULL, Got: %s\n", none == NULL ? "NULL" : "not NULL");

    return 0;
}