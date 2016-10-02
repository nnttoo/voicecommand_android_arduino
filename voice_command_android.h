#ifndef voice_command_android_H
#define voice_command_android_H

#include <Arduino.h>
#include <SoftwareSerial.h> 

/*
Voice Command Android for Arduino.

*/

class VoiceCommandItem{
	public :
	String val;
	void (*callback)();
};

class VoiceCommand{
	VoiceCommandItem *item;
	SoftwareSerial *bt;
	int _pos = 0;  
	int _maxitem;
	public :
			VoiceCommand(int maxitem, int btRx, int bttx){
				 item =  new VoiceCommandItem[maxitem];
				 _maxitem = maxitem;
				 bt = new SoftwareSerial(bttx,btRx);
			}
			void begin(int baudrate){
				bt->begin(baudrate);
			}
			void regCommand(void (*callbackIn)(),String val){
				item[_pos].callback = callbackIn;
				item[_pos].val = val;
				_pos++;
			}
			
			void call(){
				String val = "";
				while(bt->available()){
					val += (char) bt->read();
				}
			
				val.trim(); 
				if(val == "") return;
				
				Serial.println(val);
				for(int i=0;i < _maxitem;i++){
					if(item[i].val == "") continue;
					
					if(item[i].val == val) item[i].callback();
				}
			}
};

#endif
