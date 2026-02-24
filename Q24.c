#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node;
node *createnode(int data)
{ node *newnode = malloc(sizeof(node));
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}
int main()
{
  int i, n, val, key;
  node *list = NULL;
  node *temp = NULL;
  printf("Enter the number of nodes for each list: ");
  scanf("%d", &n);
  printf("List:\n");
  for(i=0; i<n; i++)
  { printf("Enter element %d: ", i + 1);
    scanf("%d", &val);
    node *new_node = createnode(val);
    if(list == NULL)
    { list = new_node;
      temp = list; } 
    else 
    { temp->next = new_node;
      temp = new_node; }
  }
  printf("Enter the key variable: ");
  scanf("%d", &key);
  node print;
  print.next = list;
  node *old = &print;
  node *current = list;
  while(current != NULL)
  { if(current->data == key)
    { old->next = current->next;
      list = print.next; }
    else
    { old = current;
      current = current->next; }
  }
  temp = list;
  printf("%d", list->data);
  temp = temp->next;
  return 0;
}