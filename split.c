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
void printList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void splitList(struct Node* head, int k, struct Node** first, struct Node** second){
    *first = head;
    if (k == 0 || head == NULL){
        *second = head;
        *first = NULL;
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < k && temp !=NULL; i++){
        temp = temp->next;
    }
    if (temp == NULL){
        *second = NULL;
        return;
    }
    *second = temp->next;
    temp->next = NULL;
}
int main(){
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);
    int k;
    printf("Enter the position k to split after:");
    scanf("%d", &k);
    struct Node* firstPart = NULL;
    struct Node* secondPart = NULL;
    splitList(head, k, &firstPart, &secondPart);
    printf("First part:");
    printList(firstPart);
    printf("second part:");
    printList(secondPart);
    return 0;
}