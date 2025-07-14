#include <stdio.h>
#include <stdlib.h>

/* doubly-linked list node */
struct node {
  int data;
  struct node *prev, *next;
};

/**
 * FuncA() - Insert a value node into the circular list
 * @start: 
 * @value:
 */
void FuncA(struct node **start, int value) {
  if (!*start) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->prev = new_node->next = new_node;
    *start = new_node;
    return;
  }
  struct node *last = (*start)->prev;
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = value;

  /* insert new_node into middle of last and start */
  new_node->next = *start;
  (*start)->prev = new_node;
  new_node->prev = last;
  last->next = new_node;
}


/**
 * FuncB() - Insert a value node and change start pointer
 * @start:
 * @value:
 */
void FuncB(struct node **start, int value) {
  struct node *last = (*start)->prev;
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = value;
  new_node->next = *start;
  new_node->prev = last;
  last->next = (*start)->prev = new_node;
  *start = new_node;
}


/**
 * FuncC() - Insert a value node after another value node
 * @start:
 * @value:
 */
void FuncC(struct node **start, int value1, int value2) {
  struct node *new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = value1;

  struct node *temp = *start;
  while (temp->data != value2)
    temp = temp->next;
  struct node *next = temp->next;
  temp->next = new_node;
  new_node->prev = temp;
  new_node->next = next;
  next->prev = new_node;
}


/**
 * display() - print all element in the circular list
 * @start:
 */
void display(struct node *start) {
  if (!start) return;

  /* display the circular queue */
  struct node *last = start->prev;
  struct node *curr = start;
  printf("traversal in forward direction\n");
  while (curr != last) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("%d\n", last->data);

  curr = last;
  printf("traversal in reverse direction\n");
  while (curr != start) {
    printf("%d ", curr->data);
    curr = curr->prev;
  }
  printf("%d\n", start->data);
}

void test_FuncA() {
  struct node *start = NULL;
  printf("[-= Test FuncA\n");
  FuncA(&start, 1);
  FuncA(&start, 2);
  FuncA(&start, 3);
  FuncA(&start, 4);
  display(start);
  // expected output
  // traversal in forward direction
  // 1 2 3 4
  // traversal in reverse direction
  // 4 3 2 1
}

void test_FuncB() {
  struct node *start = NULL;
  printf("[-= Test FuncB\n");
  FuncA(&start, 1);
  FuncB(&start, 2);
  FuncB(&start, 3);
  FuncB(&start, 4);
  display(start);
  // expected output
  // traversal in forward direction
  // 4 3 2 1
  // traversal in reverse direction
  // 1 2 3 4
}

void test_FuncC() {
  struct node *start = NULL;
  printf("[-= Test FuncC\n");
  FuncA(&start, 1);
  FuncA(&start, 2);
  FuncA(&start, 3);
  FuncA(&start, 4);
  FuncC(&start, 5, 3);
  display(start);
  // expected output
  // traversal in forward direction
  // 1 2 3 5 4
  // traversal in reverse direction
  // 4 5 3 2 1
}

void test_FuncABC() {
  struct node *start = NULL;
  printf("[-= Test FuncABC\n");
  FuncA(&start, 51); 
  FuncB(&start, 48);
  FuncA(&start, 72);
  FuncA(&start, 86);
  FuncC(&start, 63, 51);
  display(start);
  // expected output
  // traversal in forward direction
  // 48 51 63 72 86 
  // traversal in reverse direction
  // 86 72 63 51 48
}

int main() {
  test_FuncA();
  test_FuncA();
  test_FuncB();
  test_FuncB();
  test_FuncC();
  test_FuncC();
  test_FuncABC();
  test_FuncABC();
  return 0;
}