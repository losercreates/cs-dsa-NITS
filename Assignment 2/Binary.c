#include<stdio.h>
#include<math.h>

int bintodec(long long n) {
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}

long long dectobin(int n) {
  long long bin = 0;
  int rem, i = 1;

  while (n!=0) {
    rem = n % 2;
    n /= 2;
    bin += rem * i;
    i *= 10;
  }

  return bin;
}

int main(){
    long long num1,num2;
    printf("Binary System\n\n");
    printf("Enter the first number:\n");
    scanf("%lld",&num1);    
    printf("Enter the second number:\n");   
    scanf("%lld",&num2);
    printf("Result of Addition: %lld\n",dectobin(bintodec(num1)+bintodec(num2)));
    printf("Result of Multiplication: %lld",dectobin(bintodec(num1)*bintodec(num2)));
}