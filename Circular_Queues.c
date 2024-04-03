#include<stdio.h>
#include<stdlib.h>
int *queue;
int front,rear,capacity;

int pop(){
    front=(front+1)%capacity;
    return queue[front];
}
int push(int data){
    int i,*newqueue;
    if((rear+1)%capacity == front%capacity){
        printf("Extending Queue:",2*capacity);
        newqueue = (int*)malloc(capacity*2*sizeof(int*));
        for(i=1;front!=rear;i++){
            newqueue[i]=pop();
        }
        rear=i-1;
        front=0;
        capacity*=2;
        free(queue);
        queue = newqueue;
    }
    rear = (rear+1)%capacity;
    return queue[rear] = data;
}
void display(){
    printf("Elements:\n");
    if(front==rear){
        printf("Queue is empty:");
    }
    for(int i=(front+1)%capacity;i!=(rear+1)%capacity;i=(i+1)%capacity){
        printf("%d\n",queue[i]);
    }
}
int main(){
    rear=0;
    front=0;
    capacity=2;
    queue = (int*)malloc(capacity*sizeof(int*));
    int choice = 4;
    int num;
    do{
        printf("1.push()\n2.pop()\n3.display()\n4.exit()\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            scanf("%d",&num);
            push(num);
            break;

            case 2:
            if(front==rear){
                printf("Empty:");
            }
            else{
                printf("Element %d popped()",pop());
            }
            break;

            case 3:
            display();
            break;

            case 4:
            break;
        }
    }
    while(choice!=4);
    return 0;
}