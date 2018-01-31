#include<ESP8266WiFi.h>
#include<WiFiUdp.h>
WiFiUDP UDP;

char* ssid="Qazi";
char* password="Irise@1234";

int portnumber=5555;
char msg[20];
String s;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(LED_BUILTIN,OUTPUT);
WiFi.begin(ssid,password);
delay(1000);

while(WiFi.status()!=WL_CONNECTED)
{
  delay(1000);
  Serial.println("Wait for sometime");
}

Serial.println("Connected");

Serial.println(WiFi.localIP());


UDP.begin(portnumber);
}

void loop() 
{
  // put your main code here, to run repeatedly:
int a=UDP.parsePacket();

UDP.read(msg,20);

s=String(msg);
Serial.println(msg);
if(s.equals("ON"))

{
 Serial.println("on hyeche");
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
  
}
else if(s.equals("OFF"))
{
  
 Serial.println("off hyeche");
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
}
}

/*if(a>0)
{
  
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
  
}
else
{
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
  }*/
