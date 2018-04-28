
#include<SoftwareSerial.h>
#include<string.h>
SoftwareSerial Genotronex(5,6);  // rx, tx
int BluetoothData;
String voice; 
int room_light=2;
int fan=3;
int switch1=4;
int tv=8;
void setup() {
  Serial.begin(9600);
  Genotronex.begin(9600);
  pinMode(room_light,OUTPUT);
   pinMode(fan,OUTPUT);
    pinMode(switch1,OUTPUT);
     pinMode(tv,OUTPUT);
 }
void loop()
{
  while (Genotronex.available())
  {
    delay(10); 
    char c = Genotronex.read(); 
    if (c == '#') 
    {break;
    }
    voice += c; 
  } 
  if (voice.length() > 0)
  {
   
    Serial.println(voice);   
  }
  if(voice=="Turn on the light" || voice == "Turn on the lights" || voice == "Turn on the room light" || voice == "Lights on")
  {
    digitalWrite(room_light,HIGH);
    Serial.println("Room Lights on");
  }
  else if(voice=="Turn off the light" || voice == "Turn off the lights" || voice == "Turn off the room light" || voice == "Lights off")
  {
    digitalWrite(room_light,LOW);
    Serial.println("Room Lights off");
  }
  else if(voice == "Turn on the tv" || voice == "Turn on the television" || voice == "On the tv" || voice == "Switch on the tv" || voice == "Tv on")
  { 
    digitalWrite(tv,HIGH);
    Serial.println("Tv on");
  }
  else if(voice == "Turn on the tv" || voice == "Turn on the television" || voice == "On the tv" || voice == "Switch on the tv" || voice == "Tv on")
  { 
    digitalWrite(tv,LOW);
    Serial.println("Tv off");
  }
  else if(voice == "Turn on the fan" || voice == "On the fan" || voice == "Switch on the fan" || voice == "fan on" || voice == "On fan")
  { 
    digitalWrite(fan,HIGH);
    Serial.println("fan on");
  }
  else if(voice == "Turn off the fan" || voice == "off the fan" || voice == "Switch off the fan" || voice == "fan off" || voice == "off fan")
  { 
    digitalWrite(fan,LOW);
    Serial.println("fan on");
  }
  else if(voice == "Turn on the Switch" || voice == "On the Switch" || voice == "Switch on")
  {
    digitalWrite(switch1,HIGH);
    Serial.println("Switch on");
  }
  else if(voice == "Turn off the Switch" || voice == "Off the Switch" || voice == "Switch off")
  {
    digitalWrite(switch1,LOW);
    Serial.println("Switch off");
  }
  else if(voice == "All on" || voice == "Switch on everything")
  {
    digitalWrite(switch1,HIGH);
    digitalWrite(fan,HIGH);
    digitalWrite(tv,HIGH);
    digitalWrite(room_light,HIGH);
    Serial.println("All Switches on");
  }
  else if(voice == "Turn off all" || voice == "Off all")
  {
    digitalWrite(switch1,LOW);
    digitalWrite(fan,LOW);
    digitalWrite(tv,LOW);
    digitalWrite(room_light,LOW);
    Serial.println("All Switches off");
  }
  else
  {
    digitalWrite(switch1,LOW);
    digitalWrite(fan,LOW);
    digitalWrite(tv,LOW);
    digitalWrite(room_light,LOW);
  }

voice="";
} 
