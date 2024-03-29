#include<stdio.h>
#include<string.h>
int failure[20];

void fail(char *sub){
    int i,j;
    int n=strlen(sub);
    failure[0]=-1;
    for(j=1;j<n;j++){
        i=failure[j-1];
        while((sub[j]!=sub[i+1])&&(i>0)){
            i=failure[i];
        }
        if(sub[j]==sub[i+1]){
            failure[j]=i+1;
        }
        else{
            failure[j]=-1;
        }
    }
}
int match(char *str,char *sub){
    int i=0,j=0;
    int m=strlen(str);
    int n=strlen(sub);
    while(i<m&&j<n){
        if(str[i]==sub[j]){
            i++;
            j++;
        }
        else if(j==0){
            i++;
        }
        else{
            j=failure[j-1]+1;
        }
        
    }
    return((j==n)?(i-n):-1);
}
int main(){
    int results;
    char str[30];
    char sub[30];
    printf("Enter the string:\n");
    scanf("%s",str);
    printf("Enter the sub string:\n");
    scanf("%s",sub);
    fail(sub);
    results=match(str,sub);
    if(results==-1){
        printf("Pattern %s not found",sub);
    }else{
        printf("Patter %s found at %d",sub,results+1);
    }
    return 0;
}