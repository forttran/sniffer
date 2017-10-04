//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "ThreadSnif.h"
#include "listItem.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall ThreadSnif::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall ThreadSnif::ThreadSnif(bool CreateSuspended, TSnif *sniff)
        : TThread(CreateSuspended){
        sniffer = sniff;
}
//---------------------------------------------------------------------------
void __fastcall ThreadSnif::Execute(){
  sniffer->initlms();
  while(!Terminated){
    sniffer->iterationlms();
    sniffer->printlist(sniffer->lms->lst->hdr);
  }
}
//---------------------------------------------------------------------------
