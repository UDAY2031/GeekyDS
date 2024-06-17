#include<stdio.h>
#include<stdlib.h>

void merge(int a[], int left, int mid, int right){
int n1 = mid - left + 1;
int n2 = right - mid;

int l[n1],r[n2];

for(int i=0;i<n1;i++)
l[i] = a[left+i];
for(int j=0;j<n2;j++)
r[j] = a[mid+1+j];

int i=0,j=0,k=left;
while(i<n1 && j<n2){
if(l[i]<r[j]){
a[k] = l[i];
i++;
k++;
}else{
a[k] = r[j];
j++;
}
k++;
}
while(i<n1){
a[k]=l[i];
i++;
k++;
}
while(j<n2){
a[k]=r[j];
j++;
k++;
}
}

void mergesort(int a[],int left, int right){
if(left<right){
int mid = left + (right - left) / 2;
mergesort(a,left,mid);
mergesort(a,mid+1,right);
merge(a,left,mid,right);
}
}

int main(){
int n;
printf("Enter the size\n");
scanf("%d",&n);
int a[n];
printf("Enter the elements\n");
for(int i=0;i<n;i++){
scanf("%d",&a[i]);
}
mergesort(a,0,n-1);
printf("Sorted elements\n");
for(int i=0;i<n;i++){
printf("%d\n",a[i]);
}
return 0;
}
