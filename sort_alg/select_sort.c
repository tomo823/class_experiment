#include <stdio.h>

void select_sort(int *t, int n) {
    int i, z, tmp, x, y; 
    for (i = 0; i < n - 1; i++) {
        x = t[i];
        y = i;
        for (z = i + 1; z < n; z++) {
            if (x > t[z]) {
                x = t[z];
                y = z;
            }
        }
        tmp = t[i];
        t[i] = t[y];
        t[y] = tmp;
    }
}

int main() {
    int arr[] = {5, 3, 6, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    select_sort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
