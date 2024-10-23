#include <stdio.h>

int main(){
    int target;
    int i;
    int arr[] = {1,3,56,78,90,123,342};
    int size = sizeof(arr) / sizeof(arr[0]); 
    printf("Enter the target\n");
    scanf("%d",&target);
    for ( i = 0; i < size; i++) {
        if(target == arr[i]) {
            printf("found at idx:%d\n",i);
            break;
        }
    }
    if(i == size) printf("not found\n");
    
    return 0;
}