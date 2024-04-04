#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define compare(x,y) ((x)<(y) ? -1: ((x)==(y) ? 0 : (1)))
typedef struct polynode *polyptr;
typedef struct polynode{
    int  coef;
    int expon;
    polyptr link;
}polynode;
polyptr headA,headB,headC;
void attach(int c,int e,polyptr *ptr){
    polyptr temp;
    temp = (polyptr)malloc(sizeof(polynode));
    temp->coef=c;
    temp->expon=e;
    (*ptr)->link=temp;
     *ptr = temp;
}
void padd(polyptr a,polyptr b){
    int sum,DONE = FALSE;
    polyptr startA,lastC;
    startA = a;
    a=a->link;
    b=b->link;
    headC = (polyptr)malloc(sizeof(polynode));
    headC->expon=-1;
    lastC = headC;
    do{
        switch(compare(a->expon,b->expon)){
            case -1:
            attach(b->coef,b->expon,&lastC);
            b=b->link;
            break;
            case 0:if(startA==a) DONE=TRUE;
            else{
            sum=a->expon+b->expon;
            if(sum) attach(sum,a->expon,&lastC);
            a=a->link;
            b=b->link;
            }
            break;
            case 1:
            attach(a->coef,a->expon,&lastC);
            a=a->link;
            break;
        }
    }
    while(!DONE);
    lastC->link=headC;
}
int main(){
    polyptr lastA,lastB,temp,start;
    int c,e,i,n;
    headA = (polyptr)malloc(sizeof(polynode));
    headB = (polyptr)malloc(sizeof(polynode));
    headA->expon=-1;
    headB->expon=-1;
    lastA=headA;
    lastB=headB;

    printf("Enter the number in A:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the coef and expon:");
        scanf("%d%d",&c,&e);
        attach(c,e,&lastA);
    }
    lastA->link=headA;
    printf("Enter the number in B:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the coef and expon:");
        scanf("%d%d",&c,&e);
        attach(c,e,&lastB);
    }
    lastB->link = headB;
    padd(headA,headB);
    printf("Sum is:");
    for(start = headC->link;start!=headC;start = start->link)
        printf("%d * x%d +",start->coef,start->expon);
        printf("\n\n");
    for(start=headC->link;start!=headC;start=start->link)
        free(start);
        free(headC);
    
    return 0;

}