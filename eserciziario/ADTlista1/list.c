#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

struct node{
    int info;
    struct node *next;
};

struct list{
    struct node *head;
};

List newList(){
    List list=malloc(sizeof(struct list));
    list->head=NULL;
    return list;
}

void insertHead(List list, int val){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->info=val;
    newNode->next=list->head;
    list->head=newNode;
}

void insertTail(List list, int val){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->info=val;
    newNode->next=NULL;
    if (list->head==NULL){
        list->head=newNode;
        return;
    }
    struct node *currentHead=list->head;
    while(currentHead->next != NULL){
        currentHead=currentHead->next;
    }
    currentHead->next=newNode;
}

void insertNode(List list, int val, int pos){
    if (pos==0 || list->head==NULL){
        insertHead(list, val);
        return;
    }

    struct node *newNode=malloc(sizeof(struct node));
    newNode->info=val;
    struct node *currentNode=list->head;
    int i=0;
    while(currentNode->next != NULL && i<pos-1){
        currentNode=currentNode->next;
        i++;
    }
    newNode->next=currentNode->next;
    currentNode->next=newNode;
}

void removeNode(List list, int val){
    if (list->head==NULL) return;

    if (list->head->info == val){
        struct node *temp=list->head;
        list->head=list->head->next;
        free(temp);
        return;
    }

    struct node *currentNode=list->head;
    while(currentNode->next != NULL && currentNode->next->info != val){
        currentNode=currentNode->next;
    }
    if (currentNode->next != NULL){
        struct node *temp=currentNode->next;
        currentNode->next=temp->next;
        free(temp);
    }
}

void printList(List list){
    struct node *currentNode=list->head;
    printf("Lista: ");
    while(currentNode != NULL){
        printf("[%d]-> ", currentNode->info);
        currentNode=currentNode->next;
    }
    printf("NULL\n");
}

void freeList(List list){
    struct node *currentNode=list->head;
    while(currentNode != NULL){
        struct node *temp= currentNode;
        currentNode= currentNode->next;
        free(temp);
    }
    free(list);
}