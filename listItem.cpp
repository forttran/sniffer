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
  p = lst->next; // ���������� ��������� �� ��������� ����
  lst->next = temp; // ���������� ���� ��������� �� �����������
  temp->hdr = hdr; // ���������� ���� ������ ������������ ����
  temp->next = p; // ��������� ���� ��������� �� ��������� ����
  temp->prev = lst; // ��������� ���� ��������� �� ���������� ����
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
