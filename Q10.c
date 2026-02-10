#include<stdio.h>
#include<string.h>
int palindrome(char *str) {
  char *str1 = str;
  char *str2 = str;
  int i, found = 0;
  for(int i=0; i<strlen(str)/2; i++)
  { if(str1[i] != str2[strlen(str)-1-i])
    { found = 1;
      break; }
  }
  if(found == 1)
  { printf("The string is not a palindrome!"); }
  else
  { printf("The string is a palindrome!"); }
  return 0;
}
int main()
{
  char str[50];
  printf("Enter a string(no spaces): ");
  fgets(str, sizeof(str), stdin);
  str[strcspn(str, "\n")] = '\0';
  palindrome(str);
  return 0;
}