#include <stdio.h>

void bubble_sort(int t[], int n) {
    int i, z, tmp;

    for (i = 0; i < n - 1; i++) { // 配列をn-1回繰り返す
        for (z = n - 1; z > i; z--) { // 配列の末尾からi+1まで比較
            if (t[z - 1] > t[z]) {  // 隣り合う要素を比較して、逆順なら交換
                tmp = t[z - 1];    // 一時変数に保存
                t[z - 1] = t[z];   // 値を交換
                t[z] = tmp;        // 保存した値を代入
            }
        }
    }
}


int main() {
    int arr[] = {5, 3, 6, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    bubble_sort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
