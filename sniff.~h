#include <winsock2.h>
#include <stdio.h>
#include "mstcpip.h"
#include "Unit1.h"
#pragma comment(lib, "Ws2_32.lib")
//---------------------------------------------------------------------------
#ifndef sniffH
#define sniffH
#define MAX_PACKET_SIZE		65535
//преобразовния для IP адреса
#define ULONG_BYTE4(u) ((u & 0xFF000000) >> 24) // самый старший байт
#define ULONG_BYTE3(u) ((u & 0xFF0000) >> 16)
#define ULONG_BYTE2(u) ((u & 0xFF00) >> 8)
#define ULONG_BYTE1(u) (u & 0xFF)		// самый младший байт

#define BYTE_L(u) (u & 0xF) //преобразуем стуктуру IP пакета
#define BYTE_H(u) (u >> 4)

#define IP_FLAGS(f) (f >> 13)
#define IP_OFFSET(o) (o & 0x1FFF)

typedef struct _IPHeader{
  unsigned char  ver_len;		// версия и длина заголовка
  unsigned char  tos;			// тип сервиса
  unsigned short length;		// длина всего пакета
  unsigned short id;			// Id
  unsigned short flgs_offset;		// флаги и смещение
  unsigned char  ttl;			// время жизни
  unsigned char  protocol;		// протокол
  unsigned short xsum;			// контрольная сумма
  unsigned long  src;			// IP-адрес отправителя
  unsigned long  dest;			// IP-адрес назначения
  unsigned short *params;		// параметры (до 320 бит)
  unsigned char  *data;			// данные (до 65535 октетов)
}IPHeader;
class listItems;
class TSnif{
   private:
     SOCKET        m_socket;              //собственно слушающий сокет
     HOSTENT*	   hostinfo;              // Информация о хосте.
     char	   hostname[128];         // Имя хоста (компьютера).
     SOCKADDR_IN   socketAddress;         // Адрес хоста
     u_long	   watch_host;            //адрес сервера
     char *nethost2str(u_long h);
     void setPromMode(int flag);
     unsigned int iexp(unsigned int x, unsigned n);
     char *int2bin(unsigned int num, unsigned char bits);
     IPHeader* sniff();

   public:
     listItems *lms;
     TSnif();
     void *printinit();
     void *printlist(IPHeader *iph);
     void *printhex(IPHeader * hdr);
     void *initlms();
     void *iterationlms();
 };
//---------------------------------------------------------------------------
#endif
