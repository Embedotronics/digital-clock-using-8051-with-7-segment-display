#include <reg51.h>
#define msec 1
unsigned int arr[10]={0x40,0xF9,0x24,0x30,0x19,0x12,0x02,0xF8,0x00,0x10};
sbit d4=P1^0;
sbit d3=P1^1;
sbit d2=P1^2;
sbit d1=P1^3;
sbit d0=P1^4;
sbit d= P1^5;
unsigned int v1,v2,v3,v4,v0,v5,v6;
void delay(unsigned int count)
{
unsigned int j,k;
for (j=0;j<=count;j++)
for (k=0;k<=5;k++);
}
void main()
{
 v1=v2=v3=v4=v0=v5=v6=0;
 while(1)
{   
{
     v0=v0+1;
	if(v0==130)
	{
	v0=0;
	v1=v1+1;
	}
    P2=0xFF;
	d = 1;
	d3 = d2 = d4 = d0 = d1= 0;
	P2 = arr[v1];
	delay(msec);
	
    if(v1==10)
	{
	v1=0;
	v2=v2+1;
	}
	P2=0xFF;
	d0 = 1;
	d4 = d3 = d1 =d=d2= 0;
	P2 = arr[v2];
	delay(msec);

    if(v2==6)
	{
	v2=0;
	v3=v3+1;
	}
	P2=0xFF;
	d1 = 1;
	d2 = d4 = d3 =d=d0= 0;
	P2 = arr[v3];
	delay(msec);

    if(v3==10)
	{
	v3=0;
	v4=v4+1;
	}
	P2=0xFF;
	d2 = 1;
	d3 = d4 = d1 =d=d0= 0;
	P2 = arr[v4];
	delay(msec);

	if(v4==6)
	{
	v4=0;
	v5=v5+1;
	}
	P2=0xFF;
	d3 = 1;
	d0 = d2 = d1 =d=d4= 0;
	P2 = arr[v5];
	delay(msec);
	
	if(v5==10)
	{
	v5=0;
	v6=v6+1;
	}
	P2=0xFF;
	d4 = 1;
	d3 = d2 = d1 =d=d0= 0;
	P2 = arr[v6];
	delay(msec);
	if(v6==1&&v5==2)
	{
	v1=0;
	v2=0;
	v3=0;
	v4=0;
    v5=0;
	v6=0;
    }
delay(msec);
P2=0xFF;
}
}
}