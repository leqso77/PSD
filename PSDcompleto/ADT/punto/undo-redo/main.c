#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"

Item Azione(char* descrizione){
    Item item;
    strncpy(item.descrizione, descrizione, 100);
    return item;
}

int main (){
    Stack undoStack=createStack();
    Stack redoStack=createStack();


    push(&undoStack, Azione("azione 1"));
    push(&undoStack, Azione("azione 2"));
    push(&undoStack, Azione("azione 3"));

    printItem(top(undoStack));

    printf("Undoing...\n");
    if(!isempty(undoStack)){
        Item undoneAction=pop(&undoStack);
        push(&redoStack, undoneAction);
        printf("Undone action: ");
        printItem(undoneAction);
        printf("Current top of undo stack: ");
        printItem(top(undoStack));
    }

    printf("Redoing...\n");
    if(!isempty(redoStack)){
        Item redoAction=pop(&redoStack);
        push(&undoStack, redoAction);
        printf("Redone action: ");
        printItem(redoAction);
        printf("Current top of undo stack: ");
        printItem(top(undoStack));
    }


    freeStack(&undoStack);
    freeStack(&redoStack);

}