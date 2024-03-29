#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxsize 100
int stack[maxsize];
int top = -1;
int pop(){
    return stack[top--];
}
void push(int n){
    stack[++top]=n;
}
int results(int a,int b,char operator){
    switch(operator){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }
}
int postfix(char *str){
    int a,b,i;
    for(i=0;i<strlen(str);i++){
        if(isdigit(str[i])){
            push(str[i]-'0');
        }
        else{
            
            b=pop();
            a=pop();
            push(results(a,b,str[i]));
        }
    }
    return pop();
}
int main() {
    char expression[maxsize];
    printf("Enter the postfix expression: ");
    scanf("%s", expression); 
    int result = postfix(expression);
    printf("Result: %d\n", result);
    return 0;
}
