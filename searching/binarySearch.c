#include <stdio.h>

int binarySearch(int a[],int target,int size){
    int st = 0,end = size - 1;
    while(st<=end){
        int mid = st + (end - st)/2;
        if(a[mid] == target){
            return mid;
        }
        else if(a[mid] > target){
            end = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    return -1;
}

int main(){
    int target;
    int arr[] = {1,3,56,78,90,123,342};//it must be sorted
    int size = sizeof(arr) / sizeof(arr[0]); 
    printf("Enter the target\n");
    scanf("%d",&target);
    int result = binarySearch(arr,target,size);
    if(result!=-1)
        printf("found at idx:%d\n",result);
    else
        printf("not found\n");
    return 0;
}