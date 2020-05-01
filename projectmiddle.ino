#include<SoftwareSerial.h>
SoftwareSerial gsm(2,3);//Tx,Rx;
//pinmode declarations//
#define irswitch A0
#define shock A1
#define led 4
/////contact number credentials/////
char contactnumber="7795330913";

int i=0;
int s=0;
int ii=0;
int var;
void setup(){
  pinMode(irswitch,INPUT);
  pinMode(shock,OUTPUT);
  Serial.begin(9600);
  gsm.begin(9600);
  Serial.println("initialising...");
  gsm.println("AT");//checking handshake
  updateSerial();
  gsm.println("AT+CSQ");//signal quality test value range 0 to 31
  updateSerial();
  gsm.println("AT+CCID");//read sim information to confirm wheather the sim is plugged...
  updateSerial();
  gsm.println("AT+CREG?");//check weather it has registered in the network
  updateSerial();
  gsm.print("ATE0");
  gsm.print("\r");
  delay(300);
  gsm.print("ATS0=1");
  gsm.print("\r");
  delay(300);
  
}
void loop(){
  maine();
  
  }
void updateSerial(){
  delay(500);
  while(Serial.available())
  {
    gsm.write(Serial.read());
  }
  while(gsm.available())
  {
    Serial.write(gsm.read());
  }
}
void pisms(){
  gsm.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();

  gsm.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  gsm.println("AT+CMGS=\"+917795330913\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  gsm.print("ALERT!!!someone tried to open your shop."); //text content
  //Serial.print("ALERT!!!someone tried to open your shop."); //text content
  updateSerial();
  gsm.println("ATD+917795330913;");//automatic call dialing
   updateSerial();
  gsm.write(26);
  updateSerial();
  delay(3000);
}
void pulse_shock(){
  if(i==0)
  pisms();
 // Serial.println("shock");
  digitalWrite(led , HIGH);
  digitalWrite(shock,HIGH);
  delay(50);
  digitalWrite(shock,LOW);
  delay(100);
  reset();
  while((digitalRead(irswitch))==0)
  {
    prgm1();
  }
  i=4;
 }
void prgm1(){
 while(1){ ii=0;
i=0;
s=0;
if(s==0)
sisms();
s=4;
 digitalWrite(shock,LOW);
  while((digitalRead(irswitch))==1){
 pulse_shock();
 }
 reset();
 }
 }
void prgm2(){
  owsms();
  while(1)
  {
    digitalWrite(shock,LOW);
     reset();
  }
}
void owsms(){
  gsm.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  gsm.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  gsm.println("AT+CMGS=\"+917795330913\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  gsm.print("HURRAY!!!security suspended."); //text content
  //Serial.print("ALERT!!!someone tried to open your shop."); //text content
  updateSerial();
  gsm.write(26);
  updateSerial();
  delay(3000);
}
void reset(){
  if(Serial.available())
 { 
  var=Serial.read();
  while(var==51){
    Serial.println("reset");
    maine();
  }
 }
}
void maine(){
  while(1){
    digitalWrite(led , LOW);
  while(Serial.available()>0)
{
   var=Serial.read();
   Serial.println(var);
}
 switch(var)
 {
  case 49:
    Serial.println("one");
    while(var==49)
    {
      var=Serial.read();
      prgm1();
    }
    break;
    case 50:
    Serial.println("two");
    while(1)
    {
      prgm2();
    }
    break;
 }
 
}
}
void sisms(){
   gsm.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();

  gsm.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  gsm.println("AT+CMGS=\"+917795330913\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  gsm.print("Security system ACTIVATED"); //text content
  //Serial.print("ALERT!!!someone tried to open your shop."); //text content
  updateSerial();
  gsm.write(26);
  updateSerial();
  delay(2000);
}
