#include <stdio.h>
#include <stdlib.h>
#define max 50
char stack[max];
int top = -1;
int check = 0;
int isempty(){
    if (top==-1)
    {
        return 1;
    }
    return 0;
    
}
int isfull(){
if (top==max-1)
{
    return 1;
}
else
{
    return 0;
}
}
void push(){
    if (!isfull())
    {
        top++;
        stack[top] = '(';
    }
    else
    {
        printf("stack overflow\nplease enter shorter expression;");
    }
}
void pop(){
    if (isempty())
    {
        printf("stack underflow\n");
        check++;
    }
    else
    {
    top--;
    }
}
int match(char exp[50]){
    int i =0;
while (exp[i]!='\0')
{
    if (exp[i]=='(')
    {
        push();
    }
    if(exp[i]==')'){
        pop();
    }
    
    i++;
}
if (isempty())
{
    return 1;
}
else
{
    return 0;
}
}
int main(){
char exp[50];
printf("enter the expression below\n");
scanf("%s",&exp);
int a = match(exp);
if (a==1&&check==0)
{
    printf("parenthesis are matched\n");}
else{
    printf("parenthesis are not matched\n");
}
    return 0;
}