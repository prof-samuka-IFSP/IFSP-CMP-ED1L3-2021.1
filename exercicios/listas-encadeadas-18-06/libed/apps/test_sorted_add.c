#include "list.h"

int main() {
    List *L = List_create();

    List_sorted_add(L, 7);  // insere na lista vazia
    List_sorted_add(L, 4);  // insere na cabeça
    List_sorted_add(L, 9);  // insere no final
    List_sorted_add(L, 6);  // insere no meio
    List_sorted_add(L, 6);

    List_print(L);
    List_inverted_print(L);

    List_destroy(&L);

    return 0;
}

