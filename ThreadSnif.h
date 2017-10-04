//---------------------------------------------------------------------------

#ifndef ThreadSnifH
#define ThreadSnifH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "sniff.h"
//---------------------------------------------------------------------------
class ThreadSnif : public TThread
{            
private:
protected:
        void __fastcall Execute();
public:
        __fastcall ThreadSnif(bool CreateSuspended, TSnif *sniffer);
        TSnif *sniffer;
};
//---------------------------------------------------------------------------
#endif
