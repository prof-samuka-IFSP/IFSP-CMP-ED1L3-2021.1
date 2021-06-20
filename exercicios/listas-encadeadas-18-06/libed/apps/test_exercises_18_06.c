#include "linked_list.h"
#include <stdio.h>


int main() {
    LinkedList *L = LinkedList_create();

    LinkedList_add_last(L, 10);
    LinkedList_add_last(L, 2);
    LinkedList_add_last(L, 4);
    LinkedList_add_last(L, 5);
    LinkedList_add_last(L, 7);

    puts("printing L");
    LinkedList_print(L);

    puts("printing sum(L)");
    int sum = LinkedList_sum(L);
    printf("sum(L) = %d\n\n", sum);

    LinkedList *Lc = LinkedList_copy(L);

    puts("printing Lc");
    LinkedList_print(Lc);

    puts("erasing Lc");
    LinkedList_erase(Lc);
    LinkedList_print(Lc);


    LinkedList_destroy(&L);
    LinkedList_destroy(&Lc);
    void LinkedList_destroy(LinkedList **L_ref);

    return 0;
}
