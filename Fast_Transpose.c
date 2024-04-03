#include<stdio.h>
#include<string.h>
typedef struct {
    int r,v,c;
}term;
void transpose(term a[],term t[]){
    int i,j;
    int numcols = a[0].c;
    int numvalues = a[0].v;
    t[0].c=numcols;
    t[0].v=numvalues;
    t[0].c=a[0].r;
    if(numvalues>0){
        int rt[10],sp[10];
        for(i=0;i<numcols;i++){
            rt[i]=0;
        }
        for(i=1;i<=numvalues;i++){
            rt[a[i].c]++;
            sp[0]=1;
        }
        for(i=1;i<=numcols;i++){
            sp[i] = sp[i-1]+rt[i-1];
        }
        for(i=1;i<=numvalues;i++){
            j=sp[a[i].c]++;
            t[j].r=a[i].c;
            t[j].v=a[i].v;
            t[j].c=a[i].r;
        }
    }

}
int main(){
    term a[30],t[30];
    printf("Enter the size of number of row and column:");
    scanf("%d%d",&a[0].r,&a[0].c);
    printf("Enter the number of value:");
    scanf("%d",&a[0].v);
    for(int i=1;i<=a[0].v;i++){
        printf("Enter the row,column,value:");
        scanf("%d%d%d",&a[i].r,&a[i].c,&a[i].v);
    }
    printf("Original matrix:\n");
    for(int i=1;i<=a[0].v;i++){
        printf("%d\t%d\t%d\n",a[i].r,a[i].c,a[i].v);
    }
    transpose(a,t);
    printf("Transpose Matrix:\n");
    for(int i=1;i<=a[0].v;i++){
        printf("%d\t%d\t%d\n",t[i].r,t[i].c,t[i].v);
    }
}