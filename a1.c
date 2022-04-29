//Rewritten by Maksud chowdhury, CSE, East West University, Dhaka, Bangladesh 
#include <reg51.h>
unsigned int arr[10] = { //common annode hex for 0-9 with DP turned off
  0xC0, //0
  0xF9,	//1
  0xA4, //2
  0xB0, //3
  0x99, //4
  0x92, //5
  0x82, //6
  0xF8, //7
  0x80, //8
  0x90  //9
};
unsigned int arrWithDP[10] = { //common annode hex for 0-9 with DP turned on
  0x40, //0
  0x79,	//1
  0x24, //2
  0x30, //3
  0x19, //4
  0x12, //5
  0x02, //6
  0x78, //7
  0x00, //8
  0x10  //9
};

sbit d6 = P1 ^ 0;
sbit d5 = P1 ^ 1;
sbit d4 = P1 ^ 2;
sbit d3 = P1 ^ 3;
sbit d2 = P1 ^ 4;
sbit d1 = P1 ^ 5;

unsigned int v1, v2, v3, v4, v5, v6, timer;

void main() {
  v1 = v2 = v3 = v4 = v5 = v6 = 0;
	
  while (1) {
    {
      // loop variable to simulate the clock timing function
      if (timer == 7000) { //the loop  runs 7000 times for 1 sec in my machine you can tweak if needed
        timer = 0;
        v1 = v1 + 1;
      }

      P2 = 0xFF; //initialize the port to take input from array value and ready to display			
      d1 = 1; //activating the rightmost 7segment Unit
      d2 = d3 = d4 = d5 = d6 = 0;
      P2 = arr[v1];
   

      if (v1 == 10) {
        v1 = 0;
        v2 = v2 + 1;
      }
      P2 = 0xFF;
      d2 = 1; //activating the 2nd Unit from right
      d1 = d3 = d4 = d5 = d6 = 0;
      P2 = arr[v2];


      if (v2 == 6) {
        v2 = 0;
        v3 = v3 + 1;
      }
      P2 = 0xFF;
      d3 = 1; //activating the 3rd Unit from right
      d1 = d2 = d4 = d5 = d6 = 0;
      P2 = arrWithDP[v3];
   

      if (v3 == 10) {
        v3 = 0;
        v4 = v4 + 1;
      }
      P2 = 0xFF;
      d4 = 1; //activating the 4th Unit from right
      d1 = d2 = d3 = d5 = d6 = 0;
      P2 = arr[v4];
 

      if (v4 == 6) {
        v4 = 0;
        v5 = v5 + 1;
      }
      P2 = 0xFF;
      d5 = 1; //activating the 5th Unit from right
      d1 = d2 = d3 = d4 = d6 = 0;
      P2 = arrWithDP[v5];

      if (v5 == 10) {
        v5 = 0;
        v6 = v6 + 1;
      }

      P2 = 0xFF;
      d6 = 1; //activating the 6th Unit from right
      d1 = d2 = d3 = d4 = d5 = 0;
      P2 = arr[v6];

      if (v6 == 1 && v5 == 3) { //IN 12HR FORMAT
        v1 = 0;
        v2 = 0;
        v3 = 0;
        v4 = 0;
        v5 = 1;
        v6 = 0;
      }

      timer++;
    }
  }
}
