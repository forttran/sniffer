//---------------------------------------------------------------------------

#ifndef listItemH
#define listItemH
#include "sniff.h"
//---------------------------------------------------------------------------
struct list
{
  IPHeader *hdr; // ���� ������
  struct list *next; // ��������� �� ��������� �������
  struct list *prev; // ��������� �� ���������� �������
};
class listItems{
   public:
     listItems(IPHeader *hdr);
     struct list *addItem(IPHeader *hdr);
     IPHeader *StringItem(int index);
     ~listItems();
     struct list *lst;//��� ������
     struct list *head;//��������� �� ������ ������
     struct list *tail;//��������� �� ����� ������
};
#endif
