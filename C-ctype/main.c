#include <stdio.h>
#include <ctype.h>

int main() {
    char ch[10] = {"12345s"};
    int lenth = sizeof(ch) / sizeof(ch[0]);
    for (int i = 0; i < lenth; ++i) {
        printf_s("ch[%d],value:%c\n", i, ch[i]);
    }
    if (isalnum(ch[5])) {
        printf(" contain number\n");
    } else {
        printf("not number");
    }
    printf("Hello, World!\n");

    char space[1] = {' '};

    return 0;
}
