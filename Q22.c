#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *next;
} node;
node *createnode(int data){
  node *newnode = malloc(sizeof(node));
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}
int main()
{
  int i, n, count=0, val;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);
  node *head = NULL;
  node *temp = NULL;
  for(i=0; i<n; i++)
  { printf("Enter element at node %d: ", i+1);
    scanf("%d", &val);
    node *link = createnode(val);
    if(head == NULL)
    { head = link;
      temp = head; }
    else
    { temp->next = link;
      temp = link; }
  }
  node *print = head;
  printf("Linked List:\n");
  for(i=0; i<n; i++)
  { printf("%d ", print->data);
    print = print->next;
    count++;
  }
  printf("\nNumber of elements: %d", count);
  return 0;
}