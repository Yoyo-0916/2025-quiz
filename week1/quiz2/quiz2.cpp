#include <stdio.h>
#include <stdlib.h>

/* singly linked list node */
typedef struct __list {
  int data;
  struct __list *next;
} list;

/**
 * sort() - Sort the elements in ascending order
 * @start:
 */
list *sort(list *start) {
  if (!start || !start->next) return start;
  list *left = start;
  list *right = left->next;
  left->next = NULL;

  left = sort(left);
  right = sort(right);

  for (list *merge = NULL; left || right;) {
    if (!right || left && left->data < right->data) {
      if (!merge) {
        start = merge = left;
      } else {
        merge->next = left;
        merge = merge->next;
      }
      left = left->next;
    } else {
      if (!merge) {
        start = merge = right;
      } else {
        merge->next = right;
        merge = merge->next;
      }
      right = right->next;
    }
  }
  return start;
}

list *new_node(int value) {
  list *new_node = (list *)malloc(sizeof(list));
  new_node->data = value;
  new_node->next = NULL;
  return new_node;
}

void display(list *head) {
  list *temp = head;
  printf("output\n");
  while (temp->next != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("%d\n", temp->data);
}

void test_sort() {
  /* create dummy data */
  list *head = new_node(4);
  head->next = new_node(2);
  head->next->next = new_node(3);
  head->next->next->next = new_node(1);

  /* sort in ascending order */
  display(head);
  list *sorted_list = sort(head);
  display(sorted_list);
  // expected
  // output
  // 4 2 3 1
  // output
  // 1 2 3 4
}

int main() {
  test_sort();
  return 0;
}