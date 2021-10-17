#include<stdio.h>
#include<string.h>
 
#define MAX 10000

int digit(char c){
 
    int value=0;
 
    switch(c){
         case 'I': value = 1; break;
         case 'V': value = 5; break;
         case 'X': value = 10; break;
         case 'L': value = 50; break;
         case 'C': value = 100; break;
         case 'D': value = 500; break;
         case 'M': value = 1000; break;
         case '\0': value = 0; break;
         default: value = -1; 
    }
 
    return value;
}
 
int romantodec(char roman_Number[]){
    int i = 0;
    int number = 0;
 
    while(roman_Number[i]){
 
         if(digit(roman_Number[i]) < 0){
             printf("Invalid roman digit : %c",roman_Number[i]);
             return 0;
         }
 
         if((strlen(roman_Number) -i) > 2){
             if(digit(roman_Number[i]) < digit(roman_Number[i+2])){
                 printf("Invalid roman number");
                 return 0;
             }
         }
 
         if(digit(roman_Number[i]) >= digit(roman_Number[i+1]))
             number = number + digit(roman_Number[i]);
         else{
             number = number + (digit(roman_Number[i+1]) - digit(roman_Number[i]));
             i++;
         }
         i++;
    }
 
    return number;
 
}

void dectoroman(int num)  
{  
    while(num)  
    {  
        if(num >= 1000)  
        {  
            printf("M");  
            num = num - 1000;  
        }  
        else if(num >= 500)  
        {  
            printf("D");  
            num = num - 500;  
        }  
        else if(num >= 100)  
        {  
            printf("C");  
            num = num - 100;  
        }  
        else if(num >= 50)  
        {  
            printf("L");  
            num = num - 50;  
        }  
        else if(num >= 10)  
        {  
            printf("X");  
            num = num - 10;  
        }  
        else if(num >= 5)  
        {  
            printf("V");  
            num = num - 5;  
        }  
        else if(num >= 1)  
        {  
            printf("I");  
            num = num - 1;  
        }  
    }  
  
}

int main(){
    char num1[MAX], num2[MAX];
    printf("Roman System\n\n");
    printf("Enter the first number:\n");
    scanf("%s",&num1);    
    printf("Enter the second number:\n");   
    scanf("%s",&num2);
    int n1=romantodec(num1);
    int n2=romantodec(num2);
    printf("Result of Addition: ");
    dectoroman(n1+n2);
    printf("\n");
    printf("Result of Multiplication: ");
    dectoroman(n1*n2);
}