#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"

struct node { Item item; struct node *next; };
struct list { int size; struct node *head; };

List newList() {
    List list = malloc(sizeof(struct list));
    list->size = 0; list->head = NULL;
    return list;
}

int isEmpty(List list) { return (list->size == 0); }

void addHead(List list, Item item) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->item = item; new_node->next = list->head;
    list->head = new_node; list->size++;
}

Item removeHead(List list) {
    if (isEmpty(list)) return NULL;
    struct node *temp = list->head;
    list->head = temp->next;
    Item item = temp->item;
    free(temp); list->size--;
    return item;
}

int sizeList(List list) { return list->size; }

int addListTail(List list, Item item) {
    if (isEmpty(list)) { addHead(list, item); return 1; }
    struct node *p = list->head;
    while (p->next != NULL) p = p->next;
    struct node *new_node = malloc(sizeof(struct node));
    new_node->item = item; new_node->next = NULL;
    p->next = new_node; list->size++;
    return 1;
}

Item getListItemPos(List list, int pos) {
    if (pos < 0 || pos >= list->size) return NULL;
    struct node *p = list->head;
    for (int i = 0; i < pos; i++) p = p->next;
    return p->item;
}

void setListItemPos(List list, int pos, Item item) {
    if (pos < 0 || pos >= list->size) return;
    struct node *p = list->head;
    for (int i = 0; i < pos; i++) p = p->next;
    p->item = item;
}

void printList(List list) {
    struct node *p = list->head;
    while (p != NULL) { outputItem(p->item); p = p->next; }
    printf("\n");
}