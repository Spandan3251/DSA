#include<stdio.h>
#include<string.h>
#define N 50
int stack[N];
int top=-1;
char infix[N],postfix[N];

void push(char x){
if(top==N-1){
printf("\nStack overflow");
}else{
top++;
stack[top]=x;
}
}
char pop(){
if(top==-1){
return '\0';
}else{
char ch=stack[top];
top--;
return ch;
}
}
int isempty(){
return top==-1;
}
int precedence(char symbol){
switch(symbol){
case '^':
return 5;
case '/':
case '*':
return 3;
case '+':
case '-':
return 1;
default:
return 0;
}
}
int isOperator(char c){
return c=='^'||c=='/'||c=='*'||c=='+'||c=='-';}

void intopost(){
int i=0,j=0;
char symbol,next;
for(i=0;i<strlen(infix);i++){
symbol=infix[i];
if(symbol=='('){
push(symbol);
}
else if(symbol==')'){
while(!isempty() && (next=pop())!='('){
postfix[j++]=next;
}
}
else if(isOperator(symbol)){
while(!isempty()&& precedence(symbol)<=precedence(stack[top])){
postfix[j++]=pop();
}
push(symbol);
}else{
postfix[j++]=symbol;
}
}
while(!isempty()){
postfix[j++]=pop();
}
postfix[j]='\0';
}
int main(){
printf("\n enter the infix expression");
scanf("%s",infix);
intopost();
printf("\n the postfix expression is");
printf("%s\n",postfix);
return 0;
}
