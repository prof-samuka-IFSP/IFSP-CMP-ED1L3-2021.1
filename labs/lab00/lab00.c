#include <stdio.h>  // possui as funções scanf, printf, puts


int fatorial(int x) {
    int fat = 1;

    for (int i = x; i >= 1; i--) {
        fat *= i;
    }

    return fat;
}


int main() {
    // ler a entrada do laboratório
    int x, y;

    scanf("%d %d", &x, &y);

    int fat_x = fatorial(x);
    int fat_y = fatorial(y);
    int soma = fat_x + fat_y;

    printf("%d\n", fat_x);
    printf("%d\n", fat_y);
    printf("%d\n", soma);

    return 0;
}
