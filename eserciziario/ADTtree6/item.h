typedef struct item *Item;

Item createItem(int valore);
int getValore(Item item);
void printItem(Item item);
void freeItem(Item item);