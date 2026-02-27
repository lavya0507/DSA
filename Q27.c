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
node *createlinkedlist(int num) {
  node *curr = NULL;
  node *temp = NULL;
  int i, val;
  for(i=0; i<num; i++)
  { printf("Enter the value: ");
    scanf("%d", &val);
    node *new_list = createnode(val);
    if(curr == NULL)
    { curr = new_list;
      temp = curr; }
    else
    { temp->next = new_list;
      temp = new_list; }
    }
    return curr;
}
node *intersection(node *head1, node *head2) {
  node *temp1 = head1;
  while(temp1 != NULL)
  { node *temp2 = head2;
    while(temp2 != NULL)
    { if(temp1->data == temp2->data)
      { return temp2; }
      temp2 = temp2->next;
    }
    temp1 = temp1->next;
  }
  return NULL;
}
void *Traverse(node *head) {
  node *print = head;
  while(print != NULL)
  { printf("%d ", print->data);
   print = print->next; }
}
int main()
{
  int i, num, val, key;
  printf("Enter the number of nodes for each list: ");
  scanf("%d", &num);
  node *list1 = createlinkedlist(num);
  printf("Enter the number of nodes for each list: ");
  scanf("%d", &num);
  node *list2 = createlinkedlist(num);
  node *temp = intersection(list1, list2);
  printf("The first point of intersection is: %d", temp->data);
  return 0;
}