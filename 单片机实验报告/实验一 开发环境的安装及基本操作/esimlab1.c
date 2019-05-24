#include <reg52.h>
#define uchar unsigned char
void delay(){
	uchar i,j;
	for(i=0;i<255;i++)
	for(j=0;j<255;j++);
}
void main(){
	while(1){
		uchar temp;
		P1=0xff;
		temp=P1&0xf0;
		temp=temp>>4;
		P1=temp;
		delay();
	}
}
