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
  int i, n, val;
  node *list1 = NULL, *temp1 = NULL;
  node *list2 = NULL, *temp2 = NULL;
  printf("Enter the number of nodes for each list: ");
  scanf("%d", &n);
  printf("List 1:\n");
  for(i=0; i<n; i++)
  { printf("Enter element %d: ", i + 1);
    scanf("%d", &val);
    node *new_node = createnode(val);
    if(list1 == NULL)
    { list1 = new_node;
      temp1 = list1; } 
    else 
    { temp1->next = new_node;
      temp1 = new_node; }
    }
    printf("\nList 2 (Enter in sorted order):\n");
    for(i=0; i<n; i++)
    { printf("Enter element %d: ", i + 1);
      scanf("%d", &val);
      node *new_node = createnode(val);
      if(list2 == NULL)
      { list2 = new_node;
        temp2 = list2; }
      else
      { temp2->next = new_node;
        temp2 = new_node; }
    }
    node dummy;
    dummy.next = NULL;
    node *tail = &dummy;
    temp1 = list1;
    temp2 = list2;
    while(temp1 != NULL && temp2 != NULL)
    { if(temp1->data <= temp2->data)
      { tail->next = temp1;
        temp1 = temp1->next; }
      else
      { tail->next = temp2;
        temp2 = temp2->next; }
      tail = tail->next;
    }
    if(temp1 != NULL)
    { tail->next = temp1; }
    else
    { tail->next = temp2; }
    node *sorted_head = dummy.next;
    printf("\nMerged Sorted List:\n");
    node *current = sorted_head;
    while(current != NULL)
    { printf("%d ", current->data);
      current = current->next; }
    printf("\n");
    return 0;
}
