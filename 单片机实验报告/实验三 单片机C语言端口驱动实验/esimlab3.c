#include<reg52.h>
#include<intrins.h>  //����ѭ��������λ������ͷ�ļ���_crol_, _cror_��
sbit S1=P1^0;
sbit S2=P1^1;
sbit S3=P1^2;
unsigned char keyval;    
void key_scan(void);    //����ɨ�裬ȡ��ֵ
void operation1();       //���ϵ�����˸
void operation2();         //���µ�����˸
void operation3();      //���м䵽���ߣ��ٴ����ߵ��м�
void delay10ms(void);   //����ɨ����ʱ��������
void initial();
void led_delay();
void main(void)
{
    keyval=0;
    while(1)
    {
        key_scan();
        switch(keyval)
        {
            case 1:
								operation1();
                break;
            case 2:
								operation2();
								break;
						case 3:
								operation3();	
        }
    }
}
void key_scan(void)
{
    P1=0xff;
    if((P1&0x0f)==0x0e)
    {
        delay10ms();
        if(S1==0)
        keyval=1;
    }
		else if((P1&0x0f)==0x0d){
				delay10ms();
        if(S2==0)
        keyval=2;
		}
		else if((P1&0x0f)==0x0b){
				delay10ms();
        if(S3==0)
        keyval=3;
		}
}
void operation1()
{
		P2 = 0xfe;
		keyval=0;
    while(1){
		key_scan();
		if(keyval>0){
			initial();
			return;
		}
		P2 = _crol_(P2, 1);
		led_delay();
	}
}

void operation2()
{
	P2 = 0xfe;
		keyval=0;
    while(1){
		key_scan();
		if(keyval>0){
			initial();
			return;
		}
		P2 = _cror_(P2, 1);
		led_delay();
	}
}

void operation3()//���ߵ��м�
{
	P2 = 0xfe;
	keyval=0;
	while(1){
		key_scan();
		if(keyval>0){
			initial();
			return;
		}
		led_delay();
		P2 = 0x7e;
		key_scan();
		if(keyval>0){
			initial();
			return;
		}
		led_delay();
		P2 = 0xbd;
		key_scan();
		if(keyval>0){
			initial();
			return;
		}
		led_delay();
		P2 = 0xdb;
		key_scan();
		if(keyval>0){
			initial();
			return;
		}
		led_delay();
		P2 = 0xe7;
	}
}
void led_delay(void)
{
    unsigned char i,j;
    for(i=0;i<220;i++)
    for(j=0;j<220;j++);
}
  
void delay10ms(void)
{   
    unsigned char i,j;
    for(i=0;i<100;i++)
    for(j=0;j<100;j++);
}
void initial(){
	unsigned char i;
	P2 = 0xff;
}