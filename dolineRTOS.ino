//Khai bao thu vien RTOS
#include <Arduino_FreeRTOS.h>
//Khai bao cac chan 
#define in1 13
#define in2 12
#define in3 11
#define in4 10
#define cambien1 A1   // cam bien ben trai *o ngoai*
#define cambien2 A0   // cam bien ben phai *o ngoai*
//#define cambien3 A3   // cam bien ben phai
//#define cambien4 A4   // cam bien ben trai




void setup() 
{
   xTaskCreate(cb1task, " cb1",128 ,NULL, 1, NULL);
   xTaskCreate(cb2task, " cb2",128 ,NULL, 1, NULL);
   xTaskCreate(tientask, " cb2",128 ,NULL, 1, NULL);
//   xTaskCreate(tien1task, " cb2",128 ,NULL, 1, NULL);




}
//cac chuong trinh con
void loop() 
{}
//cam bien trai
void cb1task(void *pvParameters)
{
  pinMode(cambien1,INPUT);
  Serial.begin(9600);
  while(1)
  {
    if(digitalRead(cambien1)==1 && digitalRead(cambien2)==0)
    {
     digitalWrite(in1,HIGH);
     digitalWrite(in2,LOW);
     digitalWrite(in3,HIGH);
     digitalWrite(in4,LOW);
     
    }
  }
}
//cam bien phai
void cb2task(void *pvParameters)
{
  pinMode(cambien2,INPUT);
  Serial.begin(9600);
  while(1)
  {
    if(digitalRead(cambien2)==1 && digitalRead(cambien1)==0)
    {
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
    }
  }
  
}
// chuong trinh tien
void tientask(void *pvParameters)
{
  pinMode(cambien1,INPUT);
  pinMode(cambien2,INPUT);
  //pinMode(cambien3,INPUT);
  //pinMode(cambien4,INPUT);
  Serial.begin(9600);
  while(1)
  {
    if(digitalRead(cambien1)==0 && digitalRead(cambien2)==0)
    {
       analogWrite(in1,50);
       digitalWrite(in2,LOW);
       digitalWrite(in3,LOW);
       analogWrite(in4,50);
    }
    if(digitalRead(cambien1)==1 && digitalRead(cambien2)==1)
    {
       digitalWrite(in1,HIGH);
       digitalWrite(in2,LOW);
       digitalWrite(in3,LOW);
       digitalWrite(in4,HIGH);
       
    }
  }
  
}

/*void tien1task(void *pvParameters)
{
  pinMode(cambien1,INPUT);
  pinMode(cambien2,INPUT);
  //pinMode(cambien3,INPUT);
  //pinMode(cambien4,INPUT);
  Serial.begin(9600);
  while(1)
  {
    if(digitalRead(cambien1)==1 && digitalRead(cambien2)==1)
    {
       digitalWrite(in1,HIGH);
       digitalWrite(in2,LOW);
       digitalWrite(in3,LOW);
       digitalWrite(in4,HIGH);
    }
  }
  
} */

// cam bien phai
/*void cb3task(void *pvParameters)
{
  pinMode(cambien3,INPUT);
  Serial.begin(9600);
  while(1)
  {
    if(digitalRead(cambien1)==0 && digitalRead(cambien2)==0 && digitalRead(cambien3)==1 && digitalRead(cambien4)==0)
    {
      digitalWrite(in1,LOW);
      analogWrite(in2,180);
      digitalWrite(in3,LOW);
      analogWrite(in4,180);
    }
  }
  
}*/

/*void cb4task(void *pvParameters)
{
  pinMode(cambien4,INPUT);
  Serial.begin(9600);
  while(1)
  {
    if(digitalRead(cambien1)==0 && digitalRead(cambien2)==0 && digitalRead(cambien3)==0 && digitalRead(cambien4)==1)
    {
       analogWrite(in1,180);
       digitalWrite(in2,LOW);
       digitalWrite(in3,HIGH);
       analogWrite(in4,180);
     
    }
  }
} */
