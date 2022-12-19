// MY BINARY TO DECIMAL Convertor 

//Serial Monitor Output - touchPins Input - Arduino for programming

#include <bits/stdc++.h>
int v_1;
int v_0;
int v_read;

int result=0;
int input=0;
int count=0;
void setup()
{
  pinMode(4,INPUT);        //to input binary 0 from PIN 4 in the Lower Right part of ESP32 
  pinMode(13,INPUT);       //to input binary 1 from PIN 13 in the Lower Left part of ESP32
  pinMode(33,INPUT);       //to display result - converted decimal number through the input touch confirm at PIN 33 in the Upper Left part of ESP32
  pinMode(2,OUTPUT);       //activation of PIN 2 as OUTPUT as it is connected with LED 
  Serial.begin(115200);    //serial monitor initialization with appropriate BAUD RATE

  Serial.println("Welcome to MY Binary to Decimal Convertor! Press PIN 33 to see INSTRUCTIONS... ");        //welcome display for my binary to decimal convertor
  v_read=touchRead(33);
  if(v_read<80)
  {
    Serial.println(" Instructions-\n 1)To input binary ZERO - Touch PIN 4 (Lower Right) \n 2)To input binary ONE - Touch PIN 13 (Lower Left) \n 3)Touch PIN 33 to see the result");
  }
}

//INSTRUCTION - for every input by touchpin the LED glows to ensure proper entry

void loop()
{
  v_1=touchRead(4);
  v_0=touchRead(13);
  v_read=touchRead(33);
  
  if(v_1<80)
  {
    result=2*result+1;
    input=10*input+1;
    digitalWrite(2,HIGH);
    Serial.println(input);
    Serial.println(++count);
  }
  digitalWrite(2,LOW);  

  if(v_0<80)
  {
    result=2*result;
    input=10*input;
    digitalWrite(2,HIGH);
    delay(1000);
    Serial.println(input);
    Serial.println(++count);
  }
  digitalWrite(2,LOW);
  
  if(v_read<80)
  {
    Serial.println(result);
    result=0;
    input=0;
    Serial.println(++count);
    Serial.println("Thank You!");
    count=0;                                  //reset count to 0
  }
}

