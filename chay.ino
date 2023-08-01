int cbt=A1;
int cbp=A2;
int cbtt=A4;
int cbpt=A3;

int enA= 2;
int in1 = 5;
int in2 = 6;
int in3 = 9;
int in4 = 10;
int enB = 3;
int maxspeed=30;
int gtcbt;
int gtcbp;
int gtcbtt;
int gtcbpt;

void dithang();
void dithangg();
void disangtrai();
void disangphai();
void dilui();
void dunglai();
void setup(){
  pinMode(cbt,INPUT);
  pinMode(cbp,INPUT);
  pinMode(cbtt,INPUT);
  pinMode(cbpt,INPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
  Serial.begin(9600);
  delay(500);
  Serial.println("Started !!");
  delay(1000);
}
void loop()
{
  gtcbt=digitalRead(cbt);
  gtcbp=digitalRead(cbp);
  gtcbtt=digitalRead(cbtt);
  gtcbpt=digitalRead(cbpt);

  if(gtcbt == 0 && gtcbtt== 1 && gtcbpt== 0 && gtcbp==0)
  {
    dithang();
  }
  else if(gtcbt == 0 && gtcbtt==0 && gtcbpt==1 && gtcbp==0)
  {
    dithang();
  }
  else if(gtcbt == 0 && gtcbtt==1 && gtcbpt==1 && gtcbp==0)
  {
    dithang();
  }
  else if(gtcbt == 1 && gtcbtt==0 && gtcbpt==0 && gtcbp==0)
  {
    disangphai();
  }
  else if(gtcbt == 1 && gtcbtt == 1 && gtcbpt==0 && gtcbp==0)
  {
    disangphai();
  }
  else if( gtcbt==0 && gtcbtt==0 && gtcbpt==0 && gtcbp==1)
  {
    disangtrai();
    }
  else if( gtcbt==0 && gtcbtt==0 && gtcbpt==1 && gtcbp==1)
  {
    disangtrai();
    }
  else if( gtcbt==0 && gtcbtt==0 && gtcbpt==0 && gtcbp==0)
  {
    dunglai();
    }
    else if( gtcbt==1 && gtcbtt==1 && gtcbpt==1 && gtcbp==1)
    {
      dunglai();
      }
}
void dithang()
{
  analogWrite(enA,150);
  analogWrite(enB, 70);
  digitalWrite(in1, 1);
  digitalWrite(in2,0);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
}
void dithangg()
{
  analogWrite(enA, 130);
  analogWrite(enB,130);
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
  
}
void dunglai(){
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
  }
void disangphai()
{
  analogWrite(enA, 60);
  analogWrite(enB, 70);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}
void disangtrai()
{
  analogWrite(enA, 70);
  analogWrite(enB, 60);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}
void dilui()
{
  analogWrite(enA, 70);
  analogWrite(enB, 70);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}
void xoay()
{
  analogWrite(enA, 80);
  analogWrite(enB, 80);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}
