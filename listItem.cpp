//---------------------------------------------------------------------------
#pragma hdrstop
#include <vcl.h>
#include "listItem.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
listItems::listItems(IPHeader *hdr){
  listItems::lst =(struct list*)malloc(sizeof(struct list));
  lst->hdr = hdr;
  lst->next = NULL;
  lst->prev = NULL;

  listItems::head = listItems::lst;
  listItems::tail = listItems::lst;
}
struct list *listItems::addItem(IPHeader *hdr){
  struct list *temp, *p;
  temp = (struct list*)malloc(sizeof(list));
  p = lst->next; // сохранение указателя на следующий узел
  lst->next = temp; // предыдущий узел указывает на создаваемый
  temp->hdr = hdr; // сохранение поля данных добавляемого узла
  temp->next = p; // созданный узел указывает на следующий узел
  temp->prev = lst; // созданный узел указывает на предыдущий узел
  if (p != NULL)
    p->prev = temp;
  lst = temp;
  listItems::tail = lst;
  return listItems::tail;
}
IPHeader *listItems::StringItem(int index){
  struct list *temp=head;
  int i = 1;
  while(1){
    if(i == index) return temp->hdr;
    temp=temp->next;
    i++;
  }
}
listItems::~listItems(){
   free(listItems::head);
}
