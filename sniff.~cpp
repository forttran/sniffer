//---------------------------------------------------------------------------
#pragma hdrstop
#include "sniff.h"
#include "mstcpip.h"
#include "Unit1.h"
#include "listItem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TSnif::TSnif(){
        WSADATA wsaData;                                   //инициализация winSock
        WSAStartup(MAKEWORD(2,2), &wsaData);               //выполняем инициализацию winSosk
        m_socket = socket(AF_INET, SOCK_RAW, IPPROTO_IP);  //Создаем сырой сокет
        gethostname(hostname, sizeof(hostname));           //имя узла компьютера
        hostinfo = gethostbyname(hostname);                //информация о хосте
        ZeroMemory(&socketAddress, sizeof(socketAddress)); //обнуление структуры адреса
        socketAddress.sin_family = AF_INET;
        socketAddress.sin_addr.s_addr = ((struct in_addr *)hostinfo->h_addr_list[0])->s_addr;
        bind(m_socket, (SOCKADDR *)&socketAddress, sizeof(SOCKADDR));   //биндимся
        watch_host  = inet_addr("10.21.133.155");
        setPromMode(1);
}

char* TSnif::nethost2str(u_long h){//перевод IPшника в строку
	const int __BUF_SIZE = 16;
	char *r = (char*)malloc(__BUF_SIZE);
	memset((void*)r, 0, __BUF_SIZE);
	h = ntohl(h);
	sprintf(r, "%d.%d.%d.%d", ULONG_BYTE4(h), ULONG_BYTE3(h), ULONG_BYTE2(h), ULONG_BYTE1(h));
	return r;
}

void TSnif::setPromMode(int flag){
	DWORD flag1 = TRUE;
	ioctlsocket(m_socket, SIO_RCVALL, &flag1);
}

unsigned int TSnif::iexp(unsigned int x, unsigned n)
{
	int p, y;
	y = 1;
	p = x;
	while(1)
	{
		if (n & 1) y *= p;
		n = n >> 1;
		if (n == 0)
			return y;
		p *= p;
	}
}
char* TSnif::int2bin(unsigned int num, unsigned char bits){
	char *str_bin = (char*)malloc(bits+1);
	unsigned char i = 0;
        unsigned char m = iexp(2, bits-1);
	for(i = 0; m > 0; i++){
		m /=2;
		str_bin[i] = (num & m) ? '1' : '0';
	}
	str_bin[bits] = 0;
	return str_bin;
}

IPHeader* TSnif::sniff(){  //функция захвата одного пакета
        typedef   IPHeader FAR * LPIPHeader;
        BYTE      buff[MAX_PACKET_SIZE];
	IPHeader  *hdr;
	int count = 0;
	count = recv(m_socket, (char *) &buff, MAX_PACKET_SIZE, 0);
	if(count >= sizeof(IPHeader)){
		hdr = (LPIPHeader)malloc(MAX_PACKET_SIZE);
		memcpy(hdr, buff, MAX_PACKET_SIZE);
		return hdr;
	}else{
		return 0;
	}
}
void* TSnif::printlist(IPHeader *hdr){
      //if((hdr->src == sniffer.watch_host) || (hdr->dest == sniffer.watch_host )){
      Form1->StringGrid1->RowCount++;
      Form1->StringGrid1->FixedRows = 1;
      int cnt = Form1->StringGrid1->RowCount-1;
      Form1->StringGrid1->Cells[0][cnt]=BYTE_H(hdr->ver_len);
      Form1->StringGrid1->Cells[1][cnt]=BYTE_L(hdr->ver_len)*4;
      Form1->StringGrid1->Cells[2][cnt]=int2bin(hdr->tos, 8);
      Form1->StringGrid1->Cells[3][cnt]=ntohs(hdr->length);
      Form1->StringGrid1->Cells[4][cnt]=ntohs(hdr->id);
      Form1->StringGrid1->Cells[5][cnt]=int2bin(IP_FLAGS(ntohs(hdr->flgs_offset)), 3);
      Form1->StringGrid1->Cells[6][cnt]=IP_OFFSET(ntohs(hdr->flgs_offset));
      Form1->StringGrid1->Cells[7][cnt]=hdr->ttl;
      Form1->StringGrid1->Cells[8][cnt]=hdr->protocol;
      Form1->StringGrid1->Cells[9][cnt]=ntohs(hdr->xsum);
      Form1->StringGrid1->Cells[10][cnt]=nethost2str(hdr->src);
      Form1->StringGrid1->Cells[11][cnt]=nethost2str(hdr->dest);
      Form1->StringGrid1->Cells[12][cnt]=(char *)&(hdr->data);


      Form1->Memo1->Lines->Add((char)(&(hdr->data)+1));
      Form1->Memo1->Lines->Add("_______________________");
    //}
}

void *TSnif::printinit(){
  Form1->Edit1->Text=m_socket;
  Form1->Edit2->Text=hostname;
  Form1->Edit3->Text=nethost2str(socketAddress.sin_addr.s_addr);
  Form1->Edit4->Text=nethost2str(watch_host);
}

void *TSnif::initlms(){
   lms = new listItems(sniff());
}
void *TSnif::iterationlms(){
  lms->addItem(sniff());
}
