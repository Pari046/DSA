#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void concatenate(struct Node* head1, struct Node* head2){
    if (head1 == NULL){
        head1 = head2;
        return;
    }
    struct Node* temp = head1;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head2;
}
void printList(struct Node* head){
    struct Node* temp = head;
    while (temp != NULL){
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){
    struct Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    struct Node* head2 = createNode(4);
    head2->next = createNode(5);
    printf("List 1 before concatenation:");
    printList(head1);
    printf("List 2:");
    printList(head2);
    concatenate(head1, head2);
    printf("List 1 after concatenation:");
    printList(head1);
    return 0;
}
