#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data1;
  int data2;
  struct node *next;
} node;
node *createnode(int val1, int val2) {
  node *new_node = malloc(sizeof(node));
  new_node->data1 = val1;
  new_node->data2 = val2;
  new_node->next = NULL;
  return new_node;
}
node *createlinkedlist(int num) {
  int i, val1, val2;
  node *head = NULL;
  node *tail = NULL;
  for(i=0; i<num; i++)
  { printf("Enter the coefficient at node %d: ", i+1);
    scanf("%d", &val1);
    printf("Enter the power at node %d: ", i+1);
    scanf("%d", &val2);
    node *temp = createnode(val1, val2);
    if(head == NULL)
    { head = temp;
      tail = head; }
    else
    { tail->next = temp;
      tail = temp; }
  }
  return head;
}
void Traverse(node *head) {
  node *temp = head;
  printf("\nLinked List:\n");
  while(temp != NULL)
  { printf("%d ", temp->data1);
    printf("%d\n", temp->data2);
    temp = temp->next; }
}
void polynomial(node *head) {
  node *poly = head;
  printf("The polynomial is: ");
  while(poly != NULL)
  { if(poly->data2 == 0)
    { printf(" %d", poly->data1); }
    else
    { printf("%dx^%d +", poly->data1, poly->data2); }
    poly = poly->next;
  }
}
int main()
{
  int i, n, k;
  printf("Enter number of nodes: ");
  scanf("%d", &n);
  node *link_list = createlinkedlist(n);
  polynomial(link_list);
  return 0;
}