#include <stdio.h>
#include<stdbool.h>
#include<string.h>

#define MAX 10000
bool isFloat(char number[MAX]){
    int n=strlen(number);
    if(number[n-1]=='.')
        return false;
    for(int i=0;i<n-1;i++){
        if(number[i]=='.')
            return true;
    }
    return false;
}
int main(){
    char number[MAX];
    scanf("%s",&number);
    (isFloat(number)) ? printf("valid") : printf("invalid");
}