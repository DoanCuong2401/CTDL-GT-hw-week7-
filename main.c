#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *year;
    int *number;
} Population;

void swap(int *a, int *b) { // Hoán đổi vị trí 2 phần tử
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    Population a;
    int n = 51;
    int number;
    a.year = (int*)malloc(sizeof(int) * n); // Cấp phát động cho mảng năm
    a.number = (int*)malloc(sizeof(int) * n); // Cấp phát động cho mảng số lượng

    printf("Nhap so luong nguoi: ");
    scanf("%d", &number);

    printf("Nhap cac nam:\n");
    for (int i = 0; i < n; i++) {
        printf("Nam thu %d: ", i + 1);
        scanf("%d", &a.year[i]);
    }

    printf("Nhap so luong nguoi sinh ra trong cac nam:\n");
    for (int i = 0; i < n; i++) {
        printf("So luong nguoi sinh nam %d: ", a.year[i]);
        scanf("%d", &a.number[i]);
    }

    printf("\nCac nam co so luong nguoi sinh bang %d:\n", number);
    for (int i = 0; i < n; i++) {
        if (a.number[i] == number) {
            printf("%d ", a.year[i]);
        }
    }
    printf("\n");

    // Tìm năm có số lượng người sinh nhiều nhất và ít nhất
    int max_index = 0;
    int min_index = 0;
    for (int i = 1; i < n; i++) {
        if (a.number[i] > a.number[max_index]) {
            max_index = i;
        }
        if (a.number[i] < a.number[min_index]) {
            min_index = i;
        }
    }

    printf("Nam co so luong nguoi sinh nhieu nhat: %d (So luong: %d)\n", a.year[max_index], a.number[max_index]);
    printf("Nam co so luong nguoi sinh it nhat: %d (So luong: %d)\n", a.year[min_index], a.number[min_index]);

    // Giải phóng bộ nhớ đã cấp phát
    free(a.year);
    free(a.number);

    return 0;
}
