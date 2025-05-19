#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void appendNode(struct Node** headref, int data){
    struct Node* newNode = createNode(data);
    if(*headref == NULL){
        *headref = newNode;
        return;
    }
    struct Node* temp = *headref;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void printList(struct Node* head){
    while (head != NULL){
        printf("%d ->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
struct Node* mergeSorted(struct Node* l1, struct Node* l2){
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    struct Node* result = NULL;
    if(l1->data <= l2->data){
        result = l1;
        result->next = mergeSorted(l1->next, l2);
    }else{
        result = l2;
        result->next = mergeSorted(l1, l2->next);
    }
    return result;
}
void freeList(struct Node* head){
    struct Node* temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main(){
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    appendNode(&list1, 1);
    appendNode(&list1, 4);
    appendNode(&list1, 7);
    appendNode(&list2, 2);
    appendNode(&list2, 3);
    appendNode(&list2, 6);
    printf("List 1:");
    printList(list1);
    printf("List 2:");
    printList(list2);
    struct Node* merged = mergeSorted(list1, list2);
    printf("Merged list:");
    printList(merged);
    freeList(merged);
    return 0;
}
