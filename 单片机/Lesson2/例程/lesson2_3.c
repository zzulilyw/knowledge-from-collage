#include<reg52.h>
#include <intrins.h>
#define uint unsigned int 
#define uchar unsigned char 
uchar temp,num,num1;
sbit beep=P2^3;
void delay(uint);

void main()
{
		
        temp=0xfe;
	while(1)
	{	
	for(num1=0;num1<3;num1++)
		{	
		for(num=0;num<8;num++)
		{
			P1=temp;
			beep=0;
			delay(100);
			temp=_crol_(temp,1);
			P1=0xff;
			beep=1;
			delay(100);	
		}
		}
for(num1=0;num1<3;num1++)
		{	
		for(num=0;num<8;num++)
		{
			P1=temp;
			beep=0;
			delay(100);
			temp=_cror_(temp,1);
			P1=0xff;
			beep=1;
			delay(100);	
		}
		}
		while(1);
	}
}

void delay(uint z)
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);	
}