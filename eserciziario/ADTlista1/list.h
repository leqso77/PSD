#ifndef LIST_H
#define LIST_H


typedef struct list *List;

List newList();
void insertHead(List list, int val);
void insertTail(List list, int val);
void insertNode(List list, int val, int pos);
void removeNode(List list, int val);
void printList(List list);
void freeList(List list);


#endif


