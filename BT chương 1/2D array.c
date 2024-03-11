#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n; // Số hàng và số cột của mảng
    int **arr; // Con trỏ đến mảng hai chiều

    // Nhập số hàng và số cột từ người dùng
    printf("Nhap so hang: ");
    scanf("%d", &m);
    printf("Nhap so cot: ");
    scanf("%d", &n);

    // Cấp phát bộ nhớ cho mảng hai chiều
    arr = (int **)malloc(m * sizeof(int *));
    if (arr == NULL) {
        printf("Khong du bo nho\n");
        return 1;
    }
    for (int i = 0; i < m; i++) {
        arr[i] = (int *)malloc(n * sizeof(int));
        if (arr[i] == NULL) {
            printf("Khong du bo nho\n");
            return 1;
        }
    }

    // Nhập giá trị cho từng phần tử của mảng
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // In giá trị của mảng
    printf("Mang da nhap:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Giải phóng bộ nhớ đã cấp phát cho mảng
    for (int i = 0; i < m; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
