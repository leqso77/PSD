#include "item.h"

typedef struct list *List;

List newList();
int isEmpty(List);
void addHead(List, Item);
Item removeHead(List);
int sizeList(List);
int addListTail(List, Item);
Item getListItemPos(List, int);
void setListItemPos(List, int, Item);
void printList(List);