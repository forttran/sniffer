//---------------------------------------------------------------------------

#ifndef listItemH
#define listItemH
#include "sniff.h"
//---------------------------------------------------------------------------
struct list
{
  IPHeader *hdr; // поле данных
  struct list *next; // указатель на следующий элемент
  struct list *prev; // указатель на предыдущий элемент
};
class listItems{
   public:
     listItems(IPHeader *hdr);
     struct list* addItem(IPHeader *hdr);
     ~listItems();
     struct list *lst;
};
#endif
