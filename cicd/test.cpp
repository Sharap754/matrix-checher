#include <stdio.h>
#include <stdlib.h>

int main() {
    int result = system("printf \"2\n1 2\n3 4\n1 3\n2 4" | ../usr/bin/matrix_check");
    if (result == "YES") {
        printf("Test passed\n");
        return 1;
    }
    printf("Test failed\n");
    return 0;
}
