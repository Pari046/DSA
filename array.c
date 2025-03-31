#include<stdio.h>
int main(){
    int n, index;
    printf("enter the number of elements in the array:");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elements:\n",n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("enter the position of the element to retrieve:");
    scanf("%d", &index);
    if (index>0 && index<=n){
        printf("the %dth element is: %d\n", index, arr[index-1]);
    }else{
        printf("invalid!please enter a number between 1 and%d.\n",n);
    }
    return 0;
} 