#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define structure for stack node
struct Node {
    int data;
    struct Node* next;
};

// Stack operations
void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap Overflow\n");
        return;
    }
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

// Function to evaluate postfix expression
int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;
    int i = 0;

    while (exp[i] != '\0') {
        // Skip spaces
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // If character is an operand (digit), push to stack
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(&stack, num);
        }
        // If character is an operator, pop two operands
        else {
            int val1 = pop(&stack);
            int val2 = pop(&stack);

            switch (exp[i]) {
                case '+': push(&stack, val2 + val1); break;
                case '-': push(&stack, val2 - val1); break;
                case '*': push(&stack, val2 * val1); break;
                case '/': push(&stack, val2 / val1); break;
            }
            i++;
        }
    }
    return pop(&stack);
}

int main() {
    char exp[] = "2 3 1 * + 9 -";
    printf("%d\n", evaluatePostfix(exp));
    return 0;
}
