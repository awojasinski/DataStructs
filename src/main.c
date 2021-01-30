#include <stdio.h>
#include "type_name.h"

int main(void) {
    int *x;
    printf("%p is type of %s", x, type_name((void *)x));
}