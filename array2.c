#include<stdio.h>
#define SIZE 10
void findEvenPosition(int arr[], int size){
    printf("positions of even numbers in the array:\n ");
    for(int i= 0; i<size; i++){
        if (arr[i] % 2== 0){
            printf("%d", i);
        }
    }
    printf("\n");
}
int main(){
    int arr[SIZE];
    int num=3;
    for(int i=0; i<SIZE; i++){
        arr[i]=num;
        num+=3;
    }
    printf("Array elements:\n");
    for (int i =0; i<SIZE; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
    findEvenPosition(arr, SIZE);
    return 0;
    }