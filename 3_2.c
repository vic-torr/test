#include <stdlib.h>
#include <stdio.h>
typedef struct List {
  int *data;
  struct List *next;
} listT;
void cleanList(listT *myListP);
void doSth();
int condition();
void main() {
  listT *myListP = (listT*) malloc(sizeof(listT));
//  if (condition()) {
//    cleanList(myListP);
//  }
//  if (myListP != NULL) {
//    doSth();
//  }
cleanList(myListP);
}
void cleanList(listT *myListP) {
  while (myListP != NULL) {
    free(myListP);              //Bug! Freeing this node will make next ones loose
    printf("%d",myListP);
    myListP = myListP->next;    //Error: myListP was dealocated
  }
}
