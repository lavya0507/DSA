#include<stdio.h>
int fibo(int num){
  int F;
  if(num == 0)
  return 0;
  if(num == 1)
  return 1;
  F = fibo(num-1) + fibo(num-2);
  return F;
}
int main()
{
    int i, n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("%d", fibo(n));
    return 0; 
}