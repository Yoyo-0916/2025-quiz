#include <stdio.h>
#include <stdlib.h>

/* linked list node */
struct node {
  int data;
  struct node *next;
};

int FuncX(struct node *head, int *data) {
  struct node *node = head;
  for (node = head->next; node && node != head; node = node->next) data++;
  return node - head;
}

struct node *new_node(int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

int main() {
  int count = 0;
  struct node *head = new_node(0);
  head->next = new_node(1);
  head->next->next = new_node(2);
  head->next->next->next = new_node(3);
  head->next->next->next->next = new_node(4);
  printf("K1 >> %s\n", FuncX(head, &count) ? "Yes" : "No");  // expected: Yes
  head->next->next->next->next = head;
  printf("K2 >> %s\n", FuncX(head, &count) ? "Yes" : "No");  // expected: No
  head->next->next->next->next->next = head->next;
  printf("K3 >> %s\n", FuncX(head, &count) ? "Yes" : "No");  // expected: No
  head->next = head->next->next->next->next->next->next->next->next;
  printf("K4 >> %s\n", FuncX(head, &count) ? "Yes" : "No");  // expected: No
  printf("K5 >> %d\n", head->next->data);                    // expected: 0
  printf("count >> %d\n", count);                            // expected: 0
  return 0;
}