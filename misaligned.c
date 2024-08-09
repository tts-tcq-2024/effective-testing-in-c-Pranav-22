#include <stdio.h>
#include <assert.h>

int printcount = 0;
char messagebuffer[1024] = {0};

void testprint(const char *format, ...) {
    va_list args;
    va_start(args, format);
    strcpy();
}


int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    assert(result == 30);
    printf("All is well (maybe!)\n");
    return 0;
}
