#include <reg52.h>
#include <absacc.h>        
#define uint unsigned int 
#define uchar unsigned char 
#define lenth 16
void delay( )
{
	uchar i,j;
	for(i=0;i<255;i++)
	for(j=0;j<255;j++);
}
void main()
{
  int i,d;
	uint d_addr=0x4000,s_addr=0x60;
	d=0x04;
	for(i=0;i<lenth;i++,d++)
	{
		DBYTE[0x60]=d;  
		XBYTE[0x4000]=DBYTE [0x60];  
		P1=XBYTE[0x4000]; 
		delay();
	}
}
