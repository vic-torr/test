#include <cstdint>
#include <iostream>
using namespace std;

typedef struct node {
  int value;
  struct node *next;
} Node;

Node *list_reversal(Node *linked_list) {
  Node *reversed_list;
  Node *aux = linked_list;
  reversed_list = nullptr;
  while (linked_list != nullptr) {
    aux = linked_list;
    linked_list = linked_list->next;
    aux->next = reversed_list;
    reversed_list = aux;
  }
  return reversed_list;
}
int main(int argc, char *argv[]) {
  Node node_array[10];
  int i;
  for (i = 0; i < 9; i++) {
    node_array[i].next = &node_array[i + 1];
    node_array[i].value = i;
  }
  node_array[i].next = nullptr;
  node_array[i].value = -1;
  Node *linked_list;
  linked_list = node_array;
  cout << endl << "Let list:" << endl;
  for (Node *iter = linked_list; iter != nullptr; iter = iter->next) {
    cout << iter->value << ' ';
  }

  Node *reversed_list = list_reversal(linked_list);

  cout << endl << "Let reversed list:" << endl;
  for (Node *iter = reversed_list; iter != nullptr; iter = iter->next) {
    cout << iter->value << ' ';
  }
  cout << endl;

  return 0;
}
