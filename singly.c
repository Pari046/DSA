#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* CreateNode(int data){
    struct Node* NewNode= (struct Node*)malloc(sizeof(struct Node));
    NewNode->data = data;
    NewNode->next = NULL;
    return NewNode;
}
void insertAtBeginning (struct Node** head, int data){
    struct Node* NewNode= CreateNode(data);
    NewNode->next= *head;
    *head= NewNode;
}
void insertAtEnd (struct Node** head, int data){
    struct Node* NewNode = CreateNode(data);
    if (*head == NULL){
        *head = NewNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next !=NULL)
    temp = temp->next;
    temp->next =NewNode;
}
void insertAtPosition(struct Node** head,int data,int position){
    if (position == 1){
        insertAtBeginning(head, data);
        return;
    }
    struct Node* NewNode = CreateNode(data);
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++){
        temp = temp->next;
    }
    if (temp == NULL){
        printf("position out of bounds.\n");
        free(NewNode);
        return;
    }
    NewNode->next = temp->next;
    temp->next = NewNode;
}
void printlist(struct Node* head){
    while (head != NULL){
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main(){
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtPosition(&head, 15, 2);
    insertAtEnd(&head, 25);

    printlist(head);
    return 0;
}