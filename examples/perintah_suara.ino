#include <voice_command_android.h>

 
 

VoiceCommand voiceCommand(10,A2,A1);  // maxreg, A2 BT Rx Pin, Bt Tx Pin

int LampuTeras = 2;
int LampuDepan = 3;
int LampuTengah = 4;
int LampuBelakang = 5;

void LampuDepan_ON(){
    digitalWrite(LampuDepan,HIGH);
  }
void LampuDepan_OFF(){
    digitalWrite(LampuDepan,LOW);
  }
void LampuTeras_ON(){
    digitalWrite(LampuTeras,HIGH);
  }
void LampuTeras_OFF(){
    digitalWrite(LampuTeras,LOW);
  }
  
void setup() {
    pinMode(LampuTeras,OUTPUT);
    pinMode(LampuDepan,OUTPUT);
    pinMode(LampuTengah,OUTPUT);
    pinMode(LampuBelakang,OUTPUT);
  
  Serial.begin(9600);  
  voiceCommand.begin(9600);
  voiceCommand.regCommand(LampuDepan_OFF,"mld"); 
  voiceCommand.regCommand(LampuDepan_ON,"hld");  
  
  voiceCommand.regCommand(LampuTeras_OFF,"mlt"); 
  voiceCommand.regCommand(LampuTeras_ON,"hlt"); 
}

void loop() {  
  
 voiceCommand.call();
  delay(100);
}
