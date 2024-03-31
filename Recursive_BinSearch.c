#include<stdio.h>
#define compare(a,b) ((a)>(b) ? (1) : ((a)==(b) ? (0) : (-1)))
int binary_search(int a[],int key,int low,int high){
    int mid;
    if(low<=high){
        mid=(low+high)/2;
        switch(compare(a[mid],key)){
            case -1:
            return binary_search(a,key,mid+1,low);
            case 1:
            return binary_search(a,key,high,mid-1);
            case 0:
            return mid;
        }
    }
    else{
        return -1;
    }
}
int main(){
    int a[20],key,n,i;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the key element:\n");
    scanf("%d",&key);
    int result = binary_search(a,key,0,n-1);
    if(result==-1)
    printf("Element %d not found:",key);
    else
    printf("Element %d found at location %d",key,result+1);
    return 0;
}