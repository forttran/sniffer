//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "sniff.h"
#include "ThreadSnif.h"
#include "listItem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define MAX_PACKET_SIZE		65535

TForm1 *Form1;
TSnif *sniffer;
ThreadSnif *TS;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner){
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender){
  sniffer = new TSnif();
  sniffer->printinit();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender){
  TS = new ThreadSnif(true, sniffer);
  TS->Resume();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender){
  if(TS!=NULL) TS->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action){
  if(TS!=NULL) TS->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y){
  int ACol, ARow;
  StringGrid1->MouseToCell(X, Y, ACol, ARow);
  if(ARow>0){
    IPHeader * hdr = sniffer->lms->StringItem(ARow);
    sniffer->printhex(hdr);
  }
}
//---------------------------------------------------------------------------
