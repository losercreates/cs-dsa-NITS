#include<stdio.h>
#include<string.h>

#define MAX 10000

int unarytodecimal(char num[]){
    int len=strlen(num);
    return len;
}

int main(){
    char num1[MAX], num2[MAX];
    printf("Unary System\n\n");
    printf("Enter the first number:\n");
    scanf("%s",&num1);    
    printf("Enter the second number:\n");   
    scanf("%s",&num2);
    printf("Result of Addition: ");
    for(int i=1;i<=unarytodecimal(num1)+unarytodecimal(num2);i++)
        printf("1");
    printf("\n");
    printf("Result of Multiplication: ");
    for(int i=1;i<=unarytodecimal(num1)*unarytodecimal(num2);i++)
        printf("1");
}