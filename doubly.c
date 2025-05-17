#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(int data){
    struct Node* newNode = createNode(data);
    if (head == NULL){
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at the beginning.\n", data);
}
void insertAtEnd(int data){
    struct Node* newNode = createNode(data);
    if (head == NULL){
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next !=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %d at the end.\n", data);
}
void deleteFromBeginning(){
    if (head == NULL){
        printf("list is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    printf("deleted %d from the beginning.\n", temp->data);
    free(temp);    
}
void deleteFromEnd(){
    if (head == NULL){
        printf("list is empty.\n");
        return;
    }
    struct Node* temp = head;
    if (temp->next == NULL){
        printf("deleted %d from the end.\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->prev->next =NULL;
    printf("deleted %d from the end.\n", temp->data);
    free(temp);
}
void displayForward(){
    struct Node* temp = head;
    printf("list (forward): ");
    while (temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
            }
            printf("NULL\n"); 
}
void displayBackward(){
    if (head = NULL){
        printf("list is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    printf("list (backward): ");
    while (temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}
int main(){
    int choice, data;
    while(1){
        printf("\n--- Doubly linked list menu ---\n");
        printf("1. Insert at begininning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from end\n" );
        printf("5. Display forward\n");
        printf("6. Display backward\n");
        printf("7. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data:");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;
        case 2:
            printf("Enter data:");
            scanf("%d", &data);
            insertAtEnd(data);    
            break;
        case 3:
            deleteFromBeginning();
            break;
        case 4:
            deleteFromEnd();
            break;
        case 5:
            displayForward();
            break;
        case 6:
            displayBackward();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice!\n");                        
        }
    }
    return 0;
}