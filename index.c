#include <stdio.h>
#include <stdlib.h>
struct node_ {
  int data;
  struct node_ *next;
} node_;
typedef struct node_ Node;
Node * initializeNode(int value) {
  Node *nod = malloc(sizeof(Node));
  nod->data = value; 
  nod->next = NULL;
  return nod;
}
void printList(Node *node) {
  printf("\n\n=========mostrando==============\n"); 
    Node *nodeAux = node;
    while (nodeAux != NULL) {
      printf("%d\n", nodeAux->data);
      nodeAux = nodeAux->next;
    }
    printf("======================="); 
}
void insertFirst(Node **node, int value) {
  Node *newNode = initializeNode(value);
  newNode->next = *node; 
  *node = newNode;
}
void insertLast(Node **node, int value) {
  Node *auxNode = *node; 
  while (auxNode->next != NULL) {
    auxNode = auxNode->next;
  }
   auxNode->next = initializeNode(value);

}

void removeFirst(Node **node) {
  printf("\nREMOVENDO: %d\n", (*node)->data);
  Node *auxNode = (*node)->next;
  *node = auxNode;
}

void removeLast(Node **node) {
  Node *auxNode = *node; 
  while (auxNode->next->next != NULL) {
    auxNode = auxNode->next;
  }
   free(auxNode->next);
   auxNode->next = NULL;
}


int main() {
  Node *node = initializeNode(5);
  insertFirst(&node,8);
 
  insertFirst(&node,80);
  insertLast(&node, 6);
printList(node);


  removeLast(&node);
  printList(node);

}
