#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *next;
} node;
node *createnode(int val) {
  node *new_node = malloc(sizeof(node));
  new_node->data = val;
  new_node->next = NULL;
  return new_node;
}
node *createlinkedlist(int num) {
  int i, val;
  node *head = NULL;
  node *tail = NULL;
  for(i=0; i<num; i++)
  { printf("Enter the value at node %d: ", i+1);
    scanf("%d", &val);
    node *temp = createnode(val);
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
  printf("\nLinked List: ");
  while(temp != NULL)
  { printf("%d ", temp->data);
    temp = temp->next; }
}
node *Rotate(node *head, int k){
  node *curr = head;
  node *temp = head;
  int i, count;
  while(curr != NULL)
  { count++;
    curr = curr->next; }
  curr = head;
  k = k % count;
  for(i=1; i<k; i++)
  { temp = temp->next; }
  node *new_head = temp->next;
  temp->next = NULL;
  return new_head;
}
int main()
{
  int i, n, k;
  printf("Enter number of nodes: ");
  scanf("%d", &n);
  node *link_list = createlinkedlist(n);
  Traverse(link_list);
  printf("\nEnter number of times you want to rotate the list: ");
  scanf("%d", &k);
  link_list = Rotate(link_list, k);
  Traverse(link_list);
  return 0;

}
