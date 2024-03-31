#include<stdio.h>
#define compare(a,b) ((a)>(b) ? (1) : ((a)==(b) ? (0) : (-1)))
int binary_search(int a[],int key,int n){
    int mid;
    int low=0;
    int high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        switch(compare(a[mid],key)){
            case -1 : low = mid+1;
            break;
            case 1 : high = mid-1;
            break;
            case 0 : return mid;
        }
    }
    return -1;
}
int main(){
    int a[20],i,n,key,result;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be search:\n ");
    scanf("%d",&key);
    result=binary_search(a,key,n);
    if(result == -1)
    printf("Element %d not found",key);
    else
    printf("Element %d found at location %d",key,result);
    
    return 0;
}