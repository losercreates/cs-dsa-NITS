#include <stdio.h>
#include<string.h>

int main(){
    char input[10000];
    scanf("%[^\n]%*c", input);
    for(int i=0;i<strlen(input);i++){
        printf("%d",input[i]);
    }
}