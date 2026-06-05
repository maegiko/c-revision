/*
 * POINTERS EXERCISE 4 - Dynamic Memory Allocation (malloc & free)
 * Reference: https://beej.us/guide/bgc/html/split/manual-memory-allocation.html
 *
 * In OS/161, the kernel manages its own heap using kmalloc() and kfree()
 * which work similarly to malloc() and free(). Understanding these
 * is critical for the assignments.
 *
 * TASK: Complete the functions below so the program compiles
 * and produces the expected output.
 *
 * Compile with: gcc -o pointers_ex4 pointers_ex4.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * TASK 1:
 * Complete this function so that it allocates a new integer
 * on the heap, sets its value to 'val', and returns a pointer to it.
 * The caller is responsible for freeing the memory.
 */
int *create_int(int val) {
    int *num = malloc(sizeof(int));

    *num = val;

    return num;
}

/*
 * TASK 2:
 * Complete this function so that it allocates an array of
 * 'len' integers on the heap, fills it with values 0 to len-1,
 * and returns a pointer to it.
 * The caller is responsible for freeing the memory.
 * Return NULL if allocation fails.
 */
int *create_range(int len) {
    int *arr = malloc(len * sizeof(int));

    for (int i = 0; i < len; i++) {
        arr[i] = i;
    }

    return arr;
}

/*
 * TASK 3:
 * Complete this function so that it allocates a new Student
 * on the heap, initialises its fields, and returns a pointer to it.
 * The caller is responsible for freeing the memory.
 * Return NULL if allocation fails.
 */
typedef struct {
    char *name;  /* note: name is also heap allocated */
    int age;
} Student;

Student *create_student(const char *name, int age) {
    Student *new_student = malloc(sizeof(Student));
    if (new_student == NULL) return NULL;

    new_student->name = malloc(strlen(name) + 1);
    if (new_student->name == NULL) {
        free(new_student);
        return NULL;
    }

    strcpy(new_student->name, name);
    new_student->age = age;

    return new_student;
}

/*
 * TASK 4:
 * Complete this function so that it frees a Student
 * that was created by create_student().
 * Be careful — you need to free both the name AND the struct itself.
 * Freeing in the wrong order will cause problems.
 */
void free_student(Student *s) {
    free(s->name);
    free(s);
}

int main(void) {
    /* TASK 1 test */
    int *p = create_int(42);
    printf("Task 1 - Expected: 42, Got: %d\n", *p);
    free(p);

    /* TASK 2 test */
    int *arr = create_range(5);
    printf("Task 2 - Expected: 0 1 2 3 4, Got: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);

    /* TASK 3 & 4 test */
    Student *s = create_student("Alice", 20);
    printf("Task 3 - Expected: Alice 20, Got: %s %d\n", s->name, s->age);
    free_student(s);
    printf("Task 4 - Student freed successfully\n");

    return 0;
}