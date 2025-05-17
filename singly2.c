#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int data){
    struct Node* newnode = (struct Node*)malloc (sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
struct Node* createList(int n){
    if (n <= 0) return NULL;
    int value;
    printf("Enter data for node 1:");
    scanf("%d", &value);
    struct Node* head = createNode(value);
    struct Node* temp = head;
    for (int i = 2; i <= n; i++){
        printf("Enter data for node %d:", i);
        scanf("%d", &value);
        temp->next = createNode(value);
        temp = temp->next;
    }
    return head;
}
int countNodes(struct Node* head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}
void printList(struct Node* head){
    while (head){
        printf("%d ->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
struct Node* insertAtBeginning(struct Node* head, int data){
    struct Node* newnode = createNode(data);
    newnode->next = head;
    return newnode;
}
struct Node* insertAtEnd(struct Node* head, int data){
    struct Node* newnode = createNode(data);
    if(head) return newnode;
    struct Node* temp = head;
    while (temp->next){
        temp = temp->next;
        temp->next =newnode;
    }
    return head;
}
struct Node* insertAtK(struct Node* head, int data, int k){
    if (k <= 1)
         return insertAtBeginning(head, data);
    struct Node* newnode = createNode(data);
    struct Node* temp = head;
    for (int i = 1; temp && i < k-1; i++)
        temp = temp->next;
    if (!temp){
        printf("Position out of bounds.\n");
        free(newnode);
        return head;
    }         
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}
struct Node* deleteAtBeginning(struct Node* head){
    if(!head) return NULL;
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}
struct Node* deleteAtEnd(struct Node* head){
    if(!head) return NULL;
    if(!head->next){
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next)
         temp = temp->next;
    free(temp->next);
    temp->next =NULL;
    return head;     
}
struct Node* deleteAtK(struct Node* head, int k){
    if(!head) return NULL;
    if (k <= 1) return deleteAtBeginning(head);
    struct Node* temp = head;
    for (int i = 1; temp->next && i < k -1; i++)
        temp = temp->next;
    if(!temp->next){
        printf("Position out of bounds.\n");
        return head;
    }    
    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
    return head;
}
int searchElement(struct Node* head, int key){
    int position = 1;
    while (head){
        if(head->data== key)
              return position;
        head = head->next;
        position++;      
    }
    return -1;
}
int main(){
    struct Node* head =NULL;
    int choice, value, pos, n;
    printf("Enter number of nodes to create:");
    scanf("%d", &n);
    head = createList(n);
    do{
        printf("\nMenu:\n");
        printf("1. print list\n2. counnt nodes\n3. insert at beginning\n4. insert at end\n");
        printf("5. insert at k\n6. delete at beginning\n7. delete at end\n8. delete at k\n");
        printf("9. search element\n10. exit\nEnter choice:");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                 printList(head);
                 break;
            case 2:
                 printf("Total nodes: %d\n", countNodes(head));
                 break;
            case 3:
                 printf("Enter value:");
                 scanf("%d", &value);
                 head = insertAtBeginning(head, value);
                 break;
            case 4:
                 printf("Enter value:");
                 scanf("%d", &value);
                 head = insertAtEnd(head, value);
                 break;
            case 5:
                 printf("Enter position and value:");
                 scanf("%d %d", &pos, &value);
                 head = insertAtK(head, value, pos);
                 break;
            case 6:
                head = deleteAtBeginning(head);
                break;
            case 7:
                head = deleteAtEnd(head);
                break;
            case 8:
                printf("Enter position:");
                scanf("%d", &pos);
                head = deleteAtK(head, pos);
                break;
            case 9:
                printf("Enter value to search:");
                scanf("%d", &value);
                pos = searchElement(head, value);
                if(pos > 0)
                   printf("Element found at position %d\n", pos);
                else
                   printf("Element not found\n");
                break;
            case 10:
                printf("Exiting...\n");
                break;
            default:
                printf("invalid choice.\n");                                                  
        }
    } while (choice != 10);
    return 0;

}

