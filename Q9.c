#include<stdio.h>
#include<string.h>
int main()
{
  char str[50];
  printf("Enter a string(no spaces): ");
  fgets(str, sizeof(str), stdin);
  str[strcspn(str, "\n")] = '\0';
  printf("%s", strrev(str));
  return 0;
}