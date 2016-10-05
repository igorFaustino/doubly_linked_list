#include "doubly_linked_list.h"

Element* element_create(int id, string info)
{
    Element* e = new Element;
    e->id = id;
    e->info = info;
    e->next = NULL;
    e->prev = NULL;

    return e;
}

void element_print(Element* e)
{
    cout << "{ " << e->id << ", " << e->info << " }" << endl;
}

void element_destroy(Element* e)
{
    if (e){
        delete e;
    }
}

List* list_create()
{
    List* list = new List;
    list->first = 0;
    list->size = 0;

    return list;
}

void list_destroy(List* list)
{
    Element* p = list->first;
    Element* prev = NULL;
    while (p){
        prev = p;
        p = p->next;
        element_destroy(prev);
    }
    delete list;
}

void list_insertFirst(List* list, Element* e)
{
    if (list->first){
        e->next = list->first;
        list->first->prev = e;
    }
    list->first = e;
    list->size++;
}

void list_insertLast(List* list, Element* e)
{
    Element* p = list->first;
    Element* prev = NULL;
    while (p){
        prev = p;
        p = p->next;
    }
    if (!prev) {
        list->first = e;
    } else {
        prev->next = e;
        e->prev = prev;
    }
    list->size++;
}

void list_insertSorted(List* list, Element* e)
{
    Element* p = list->first;
    Element* prev = NULL;
    while (p && p->id < e->id){
        prev = p;
        p = p->next;
    }
    if (prev) {
        prev->next = e;
    } else {
        list->first = e;
    }
    if (p){
        p->prev = e;
    }
    e->prev = prev;
    e->next = p;
    list->size++;
}

int list_removeById(List* list, int id)
{
    Element* p = list->first;
    Element* prev = NULL;
    while (p && p->id != id){
        prev = p;
        p = p->next;
    }
    if (!p){
        return -1;
    }
    if(prev){
        prev->next = p->next;
    } else {
        list->first = p->next;
    }
    if (p->next){
        p->next->prev = prev;
    }
    element_destroy(p);
    list->size--;
    return 0;
}

int list_removeLast(List* list)
{
    Element* p = list->first;
    Element* prev = NULL;
    while(p){
        prev = p;
        p = p->next;
    }
    p = prev;
    if (!p){
        return -1;
    }
    if (p->prev){
        p->prev->next = NULL;
    } else {
        list->first = NULL;
    }
    element_destroy(p);
    list->size--;
}

void list_print(List* list)
{
    cout << "Doubly Linked List \nsize: " << list->size <<"\n[" << endl;
    Element* p = list->first;
    while (p){
        element_print(p);
        p = p->next;
    }
    cout << "]" << endl;
}

void list_printReverse(List* list)
{
    cout << "Doubly Linked List (reverse print) \nsize: " << list->size <<"\n[" << endl;
    Element* p = list->first;
    Element* prev = NULL;
    while (p){
        prev = p;
        p = p->next;
    }
    while (prev){
        element_print(prev);
        prev = prev->prev;
    }
    cout << "]" << endl;
}

Element* list_getById(List* list, int id)
{
    Element* p = list->first;
    while (p && p->id != id){
        p = p->next;
    }
    return p;
}
