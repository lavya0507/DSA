#include <stdio.h>
#include <string.h>
#include <ctype.h>

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}
void infixToPostfix(char* infix) {
    char stack[100];
    int top = -1;
    for (int i=0; infix[i] != '\0'; i++)
    { char c = infix[i];
      if(isalnum(c))
      { printf("%c", c); }
      else if(c == '(')
      { stack[++top] = c; }
      else if(c == ')')
      { while(top != -1 && stack[top] != '(')
        { printf("%c", stack[top--]); }
        top--;
      } 
      else
      { while(top != -1 && precedence(stack[top]) >= precedence(c))
        { printf("%c", stack[top--]); }
        stack[++top] = c;
      }
    }
    while (top != -1)
    { printf("%c", stack[top--]); }
    printf("\n");
}
int main() {
    char infix[100];
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}
