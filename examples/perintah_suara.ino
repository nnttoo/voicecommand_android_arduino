#include <voice_command_android.h>

 
 

VoiceCommand voiceCommand(10,A2,A1);  // maxreg, A2 BT Rx Pin, Bt Tx Pin

int LampuTeras = 2;
int LampuDepan = 3;
int LampuTengah = 4;
int LampuBelakang = 5;


void LampuTeras_ON(){
    digitalWrite(LampuTeras,HIGH);
  }
void LampuTeras_OFF(){
    digitalWrite(LampuTeras,LOW);
  }

  

void LampuDepan_ON(){
    digitalWrite(LampuDepan,HIGH);
  }
void LampuDepan_OFF(){
    digitalWrite(LampuDepan,LOW);
  }

void LampuTengah_ON(){
    digitalWrite(LampuTengah,HIGH);
  }
void LampuTengah_OFF(){
    digitalWrite(LampuTengah,LOW);
  }



void LampuBelakang_ON(){
    digitalWrite(LampuBelakang,HIGH);
  }
void LampuBelakang_OFF(){
    digitalWrite(LampuBelakang,LOW);
  }

void matikanSemuaLampu(){
    
    digitalWrite(LampuTeras,LOW);
    digitalWrite(LampuDepan,LOW);
    digitalWrite(LampuTengah,LOW);
    digitalWrite(LampuBelakang,LOW);
  }
  
void setup() {
    pinMode(LampuTeras,OUTPUT);
    pinMode(LampuDepan,OUTPUT);
    pinMode(LampuTengah,OUTPUT);
    pinMode(LampuBelakang,OUTPUT);
  
  Serial.begin(9600);  
  voiceCommand.begin(9600);

  voiceCommand.regCommand(LampuTeras_OFF,"lton"); 
  voiceCommand.regCommand(LampuTeras_ON,"ltof"); 
  
  voiceCommand.regCommand(LampuDepan_OFF,"ldon"); 
  voiceCommand.regCommand(LampuDepan_ON,"ldoff");  
  
  voiceCommand.regCommand(LampuTengah_ON,"ltengahon"); 
  voiceCommand.regCommand(LampuTengah_OFF,"ltengahoff");  
  
  voiceCommand.regCommand(LampuBelakang_ON,"lbon"); 
  voiceCommand.regCommand(LampuBelakang_OFF,"lboff");  

  
  voiceCommand.regCommand(matikanSemuaLampu,"alloff");  
}

void loop() {  
  
 voiceCommand.call();
  delay(100);
}