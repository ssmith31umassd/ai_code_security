#include <stdio.h>

int main() {
    int arr[3];
    int count = 0;
    int num = 1;

    while (count < 4) {
        if (num % 2 != 0) {
            arr[count] = num;
            count++;
        }
        num++;
    }

    for (int i = 0; i < 3; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}