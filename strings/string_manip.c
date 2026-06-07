/*
 * STRING MANIPULATION EXERCISE
 * Reference: https://beej.us/guide/bgc/html/split/strings.html
 *
 * In OS/161, strings are used for things like process names,
 * file paths, and kernel messages. You won't have access to
 * all the usual string library functions, so understanding
 * how strings work at a low level is important.
 *
 * IMPORTANT: strings in C are just char arrays terminated
 * by a null byte '\0'. That's it.
 *
 * TASK: Complete the functions below WITHOUT using any
 * string library functions (no strlen, strcpy, strcat etc.)
 * unless the task explicitly says you can.
 *
 * Compile with: gcc -o strings_ex strings_ex.c
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * TASK 1:
 * Implement your own version of strlen.
 * Count the number of characters before the null terminator.
 */
int my_strlen(const char *s) {
    int len = 0;

    for (const char *c = s; *c != '\0'; c++) {
        len++;
    }

    return len;
}

/*
 * TASK 2:
 * Implement your own version of strcpy.
 * Copy string src into dst including the null terminator.
 * Assume dst is large enough.
 */
void my_strcpy(char *dst, const char *src) {
    for (const char *s = src; *s != '\0'; s++) {
        *dst = *s;
        dst++;
    }

    *dst = '\0';
}

/*
 * TASK 3:
 * Implement your own version of strcat.
 * Append src onto the end of dst.
 * Assume dst is large enough.
 */
void my_strcat(char *dst, const char *src) {
    char *d;
    for (d = dst; *d != '\0'; d++) {}

    for (const char *s = src; *s != '\0'; s++) {
        *d = *s;
        d++;
    }

    *d = '\0';
}

/*
 * TASK 4:
 * Implement your own version of strcmp.
 * Return 0 if strings are equal.
 * Return a negative number if s1 < s2.
 * Return a positive number if s1 > s2.
 */
int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}

/*
 * TASK 5:
 * Implement a function that reverses a string IN PLACE.
 * Example: "hello" becomes "olleh"
 */
void reverse_string(char *s) {
    int len = my_strlen(s);
    char *tail = s + (len - 1);

    while (s < tail) {
        char temp = *s;
        
        *s = *tail;
        *tail = temp;

        s++;
        tail--;
    }
}

/*
 * TASK 6:
 * Implement a function that allocates a new string on the heap
 * that is a copy of s, and returns a pointer to it.
 * This is your own version of strdup.
 * The caller is responsible for freeing the memory.
 * You MAY use my_strlen and my_strcpy here.
 */
char *my_strdup(const char *s) {
    int len = my_strlen(s);

    char *copy = malloc(len + 1);
    if (copy == NULL) return NULL;

    my_strcpy(copy, s);

    return copy;
}

int main(void) {
    /* TASK 1 test */
    printf("Task 1 - Expected: 5, Got: %d\n", my_strlen("hello"));
    printf("Task 1 - Expected: 0, Got: %d\n", my_strlen(""));

    /* TASK 2 test */
    char dst[64];
    my_strcpy(dst, "hello");
    printf("Task 2 - Expected: hello, Got: %s\n", dst);

    /* TASK 3 test */
    char buf[64] = "hello";
    my_strcat(buf, " world");
    printf("Task 3 - Expected: hello world, Got: %s\n", buf);

    /* TASK 4 test */
    printf("Task 4 - Expected: 0, Got: %d\n", my_strcmp("abc", "abc"));
    printf("Task 4 - Expected: negative, Got: %d\n", my_strcmp("abc", "abd"));
    printf("Task 4 - Expected: positive, Got: %d\n", my_strcmp("abd", "abc"));

    /* TASK 5 test */
    char rev[] = "hello";
    reverse_string(rev);
    printf("Task 5 - Expected: olleh, Got: %s\n", rev);

    /* TASK 6 test */
    char *dup = my_strdup("hello");
    printf("Task 6 - Expected: hello, Got: %s\n", dup);
    free(dup);

    return 0;
}