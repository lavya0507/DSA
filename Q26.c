#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  int data;
  struct node *next;
} node;
node *createnode(int data) { 
  node *newnode = malloc(sizeof(node));
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}
node *count_key(node *head, int key) {
  node *curr = head;
  int count=0;
  while(curr != NULL)
  { if(curr->data == key)
    { count++; }
    curr = curr->next; 
  }
  printf("%d", count);
  free(curr);
}
void *Traverse(node *head) {
  node *print = head;
  while(print != NULL)
  { printf("%d ", print->data);
   print = print->next; }
  free(print);   
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
  Traverse(list);
  printf("\nThe number of times %d occurs in the list is ", key);
  count_key(list, key);
  return 0;
}