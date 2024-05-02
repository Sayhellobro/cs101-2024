#include <stdio.h>

typedef struct {
    int used[10];
} my_mm_t;

int g_mm[10];
my_mm_t mms;

void print_calloc_array(int flag) {
    for (int i = 0; i < 10; i++) {
        printf("%d", mms.used[i]);
    }

    if (flag) {
        printf(" <- Out of space\n");
    } else {
        printf("\n");
    }
}

int *my_calloc(int size) {
    int start = -1;

    for (int i = 0; i <= 10 - size; i++) {
        int found = 1;
        for (int j = 0; j < size; j++) {
            if (mms.used[i + j] != 0) {
                found = 0;
                break;
            }
        }
        if (found) {
            start = i;
            break;
        }
    }

    if (start == -1) {
        print_calloc_array(1);
        return NULL;
    }

    for (int i = start; i < start + size; i++) {
        mms.used[i] = 1;
    }

    print_calloc_array(0);
    return &g_mm[start];
}

void my_free(int *p) {
    if (p == NULL) {
        return;
    }

    int index = p - g_mm;

    if (index >= 0 && index < 10) {
        mms.used[index] = 0;

        if (index >= 6 && index <= 9) {
            for (int i = index + 1; i < 10; i++) {
                mms.used[i] = 0;
            }
        }
    }

    print_calloc_array(0);
}

int main() {
    int *np1 = my_calloc(1);
    int *np2 = my_calloc(2);
    int *np3 = my_calloc(3);
    int *np4 = my_calloc(4);
    my_free(np1);
    my_free(np4);
    int *np5 = my_calloc(5);
    int *np6 = my_calloc(1);

    return 0;
}


