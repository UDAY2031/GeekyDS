#include<stdio.h>
#include<stdlib.h>
#define maxstack 3
typedef struct {
    int key;
}element;
typedef struct stacknode *stacknodeptr;
typedef struct stacknode {
    element data;
    stacknodeptr link;
}stacknode;
stacknodeptr top[maxstack];
void push(int num,int item){
    stacknodeptr newnode = (stacknodeptr)malloc(sizeof(stacknode));
    if(newnode==NULL){
        printf("Memory allocation failed:");
        return;
    }
    newnode->data.key=item;
    newnode->link = top[num];
    top[num]=newnode;
}
int pop(int num){
    if(top[num]==NULL){
        printf("Stack is empty:",num);
    }
    stacknodeptr temp = top[num];
    int item = temp->data.key;
    top[num] = temp->link;
    free(temp);
    return item;
}
void display(){
    for(int i=0;i<maxstack;i++){
        printf("Stack %d\n",i);
        stacknodeptr current = top[i];
        while(current!=NULL){
            printf("%d",current->data.key);
            current=current->link;
        }
        printf("\n");
    }
}
int main(){
    int num,item,choice;
    for(int i=0;i<maxstack;i++){
        top[i]==NULL;
    }
    while(1){
        printf("1.push()\n2.pop()\n3.display()\n4.exit():\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the no and item:",maxstack-1);
            scanf("%d%d",&num,&item);
            push(num,item);
            break;
            case 2:
            printf("Enter the element to be popped:",maxstack-1);
            scanf("%d",&num);
            printf("Elemnt %d popped",pop(num));
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