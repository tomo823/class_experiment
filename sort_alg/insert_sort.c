#include <stdio.h>

void insert_sort(int t[], int n) {
    int i, z, tmp;
    for (i = 1; i <= n - 1; i++) {  // 配列の2番目から最後まで繰り返す
        for (z = i; z >= 1; z--) {  // ソート済み部分に挿入する位置を探す
            if (t[z - 1] > t[z]) {  // 隣り合う要素を比較し、逆順の場合交換
                tmp = t[z - 1];
                t[z - 1] = t[z];
                t[z] = tmp;
            } else break;  // 適切な位置が見つかったら終了
        }
    }
}


int main() {
    int arr[] = {5, 3, 6, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    insert_sort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
