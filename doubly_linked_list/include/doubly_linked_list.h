#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <string>

using namespace std;

struct Element {
	int id;
	string info;
	Element* next;
	Element* prev;
};

Element* element_create(int id, string info);
void element_print(Element* e);
void element_destroy(Element* e);

////////////////////////////////////////////////

struct List {
	Element* first;
	int size;
};

List* list_create();
void list_destroy(List* list);

void list_insertFirst(List* list, Element* e);
void list_insertLast(List* list, Element* e);
void list_insertSorted(List* list, Element* e);

int list_removeById(List* list, int id);
int list_removeLast(List* list);

void list_print(List* list);
void list_printReverse(List* list);
Element* list_getById(List* list, int id);

#endif // DOUBLY_LINKED_LIST_H
