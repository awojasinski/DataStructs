#include <stdio.h>
#include "type_name.h"
#include "linked_list.h"

int main(void) {
    int y = 5;
    int *x = &y;
    printf("%p is type of %s", x, type_name((void *)x));
}