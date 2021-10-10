#include <stdio.h>
#include<stdbool.h>
#include<string.h>

#define MAX 50

bool isChar(char c){
    return ((c >= 'a' && c <= 'z')|| (c >= 'A' && c <= 'Z'));
}

bool isValidEmail(char email[]){
    if (!isChar(email[0])) 
        return false;
    int n=strlen(email);
    if (!isChar(email[n-1])) 
        return false;
    int At = -1, Dot = -1;
    for (int i = 0;i < strlen(email); i++) {
  
        if (email[i] == '@') {
  
            At = i;
        }
        else if (email[i] == '.') {
            Dot = i;
        }
    }
    if (At == -1 || Dot == -1)
        return false;
    if (At > Dot || Dot - At == 1)
        return false;
    return true;
}

int main(){
    char email[MAX];
    scanf("%s",email);
    isValidEmail(email) ? printf("valid") : printf("invalid");
    
}