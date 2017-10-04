//---------------------------------------------------------------------------
#pragma hdrstop
#include "listItem.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
listItems::listItems(IPHeader *hdr){
  // выделение пам€ти под корень списка
  listItems::lst = (struct list*)malloc(sizeof(struct list));
  listItems::lst->hdr = hdr;
  listItems::lst->next = NULL; // указатель на следующий узел
  listItems::lst->prev = NULL; // указатель на предыдущий узел
}
struct list* listItems::addItem(IPHeader *hdr){
  struct list *temp, *p;
  temp = listItems::lst;
  listItems::lst->next = temp;
  listItems::lst->prev = NULL;
  listItems::lst->hdr = hdr;
  temp->prev = listItems::lst;
}
listItems::~listItems(){
   free(listItems::lst);
}
