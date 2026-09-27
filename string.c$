#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[100];
    int i, j;

    printf("Enter a string:\n");
    scanf("%s", a);

    int len = strlen(a); // get the length of the string

    for (i = 0, j = len - 1; i < len; i++, j--) {
        b[i] = a[j];  // copy characters in reverse order
    }

    b[i] = '\0'; // null-terminate the reversed string

    printf("Reversed string: %s\n", b);

    return 0;
}
