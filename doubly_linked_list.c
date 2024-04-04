#include<stdio.h>
#include<stdlib.h>
typedef struct node *nodeptr;
typedef struct node{
    nodeptr llink;
    int data;
    nodeptr rlink;
}node;
nodeptr head;
void dinsert(){
    int n;
    nodeptr temp;
    printf("Enter new node info\n");
    scanf("%d",&n);
    temp = (nodeptr)malloc(sizeof(node));
    temp->data=n;
    temp->llink = head;
    temp->rlink = head->rlink;
    head->llink->rlink = temp;
    head->rlink=temp;
    
}
void ddelete(){
    nodeptr temp=head->rlink;
    if(head->rlink == head){
        printf("Deletion of node is not permitted:");
    }
    else{
        head->rlink = temp->rlink;
        temp->rlink->llink = head;
        printf("Deleted node %d\n",temp->data);
        free(temp);
    }
}
void displayright(){
    nodeptr temp;
    if(head->rlink == head){
        printf("List is empty:");
    }
    else{
        for(temp = head->rlink;temp->rlink!=head;temp=temp->rlink)
        printf("%d\n",temp->data);
        printf("%d\n",temp->data);
        
    }
}
void displayleft(){
    nodeptr temp;
    if(head->llink == head){
        printf("List is empty");
    }
    else{
        for(temp=head->llink;temp->llink!=head;temp=temp->llink)
            printf("%d\n",temp->data);
            printf("%d\n",temp->data);
        
    }
}
int main(){
    nodeptr temp;
    int choice;
    head = (nodeptr)malloc(sizeof(node));
    head->rlink=head;
    head->llink=head;

    while(1){
        printf("1.insert()\n2.delete()\n3.displayrigth()\n4.displayleft()\n.5.exit()\n");
        scanf("%d",&choice);
        switch((choice)){
            case 1:dinsert();
            break;
            case 2:ddelete();
            break;
            case 3:displayright();
            break;
            case 4:displayleft();
            break;
            case 5:
            exit(0);

        }
    }
}