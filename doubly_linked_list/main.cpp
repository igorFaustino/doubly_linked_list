#include <iostream>
#include "doubly_linked_list.h"

using namespace std;

int main()
{
    List* list = list_create();

    list_insertLast(list, element_create(3, "Goku"));
    list_insertLast(list, element_create(5, "Vegeta"));
    list_insertLast(list, element_create(1, "Picollo"));
    list_insertLast(list, element_create(3, "Gohan"));
    list_print(list);
    list_printReverse(list);

    list_removeLast(list);
    list_removeLast(list);
    list_print(list);
    list_removeLast(list);
    list_removeLast(list);
    list_print(list);

    list_insertSorted(list, element_create(3, "Martha"));
    list_insertSorted(list, element_create(1, "Doctor"));
    list_insertSorted(list, element_create(4, "Rose"));
    list_insertSorted(list, element_create(5, "Amy"));
    list_insertSorted(list, element_create(2, "Roy"));
    list_print(list);

    list_removeById(list, 3);
    list_removeById(list, 2);
    list_print(list);

    list_insertFirst(list, element_create(0,"David Tennant"));
    list_print(list);

    element_print(list_getById(list, 1));

    return 0;
}
