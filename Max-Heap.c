#include<stdio.h>
#include<stdlib.h>
#define maxsize 25
int heap[maxsize],n=0;

void push(int item){
    int i=++n;
    while((i!=1)&&(item>heap[i/2])){
        heap[i]=heap[i/2];
        i=i/2;
    }
    heap[i]=item;   
}
int pop(){
    int item,temp,parent=1,child=2;
    item=heap[1];
    temp=heap[n--];
    while(child<=n){
        if(child < n&&(heap[child]<heap[child+1]))
        child++;
        if(item>=heap[child])
        break;
        heap[parent]=heap[child];
        parent=child;
        child*=2;
    }
    heap[parent]=temp;
    printf("Element removed is %d\n",item);
}
void display(){
    for(int i=1;i<=n;i++){
        printf("%d\n",heap[i]);
        printf("\n");
    }
}
int main(){
    int choice;
    int x;
    while(1){
        printf("1.insert\n2.delete\n3.display\n4.exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:

            if(n==maxsize){
                printf("Heap is full:");
                exit(1);
            }
                printf("Enter element to insert");
                scanf("%d",&x);
                push(x);
                break;
            
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);

        }
    }
    return 0;

}