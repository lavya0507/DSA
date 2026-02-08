#include<stdio.h>
int power(int num, int size) {
  if(size == 0)
  { return 1; }
  return num * power(num, size-1);
}
int main()
{
  int n, s;
  printf("Enter a number: ");
  scanf("%d", &n);
  printf("Enter power: ");
  scanf("%d", &s);
  if(s < 0)
  { printf("Invalid power!\nExiting...");
    return 0; }
  printf("%d", power(n, s));
  return 0; 
}