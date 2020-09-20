#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#define ssid "YourWiFiSSID"
#define password "YourWifiPassword"

int butts[4] = {0,14,12,13};
// GPIO pins   D3,D5,D6,D7
const byte ip[4] = {192, 168, 20, 114}; \\ use the python script to find out the IP and port number
const int port = 55443;

void setup() {
  for(int i = 0; i < 4; i++)
  {
    pinMode(butts[i],INPUT_PULLUP);
  }
  //Serial.begin(115200);
  //while(!Serial) { }
  //Serial.println(" ");    
  //Serial.println("Waking up");
  //Serial.println(" ");
  connectToWifi(); 
}

void connectToWifi() {
  //Serial.print("Connecting to: ");
  //Serial.print(ssid); 
  WiFi.begin(ssid, password);  
  //Serial.println(" ");
  //Serial.print("Attempting to connect: ");

  //try to connect for 10 seconds
  int i = 10;
  while(WiFi.status() != WL_CONNECTED && i >=0) {
    delay(1000);
    //Serial.print(i);
    //Serial.print(", ");
    i--;
  }
  //Serial.println(" ");

  //print connection result
  if(WiFi.status() == WL_CONNECTED){
    //Serial.print("Connected."); 
    //Serial.println(" ");// print an empty line
    //Serial.print("NodeMCU ip address: "); 
    //Serial.println(WiFi.localIP());
  }
  else {
    //Serial.println("Connection failed - check your credentials or connection");
  }
}

void loop() {

  for(int i = 0; i < 4; i++)
  {
    if(!digitalRead(butts[i]))
    {
      WiFiClient client;
      switch(i)
      {
        case 0 :
        {
          //Serial.println("Shutting down lights");
          //Serial.println("connecting to host");
          if (!client.connect(ip, port))
          {
            //Serial.println("connection failed");
            return;
          }
          //Serial.println("connection to host established");
          String payload = "{\"id\":1,\"method\":\"set_power\",\"params\":[\"off\"]}";
          client.println(payload);
          break;
        }
        
        case 1 :
        {
          //Serial.println("Low lights");
          //Serial.println("connecting to host");
          if (!client.connect(ip, port))
          {
            //Serial.println("connection failed");
            return;
          }
          //Serial.println("connection to host established");
          String payload = "{\"id\":2,\"method\":\"set_scene\",\"params\":[\"color\",16726528,1]}";
          client.println(payload);
          break;
        }

        case 2 :
        {
          //Serial.println("Mid lights");
          //Serial.println("connecting to host");
          if (!client.connect(ip, port))
          {
            //Serial.println("connection failed");
            return;
          }
          //Serial.println("connection to host established");
          String payload = "{\"id\":3,\"method\":\"set_scene\",\"params\":[\"color\",16736256,100]}";
          client.println(payload);
          break;
        }

        case 3 :
        {
          //Serial.println("Full lights");
          //Serial.println("connecting to host");
          if (!client.connect(ip, port))
          {
            //Serial.println("connection failed");
            return;
          }
          //Serial.println("connection to host established");
          String payload = "{\"id\":3,\"method\":\"set_scene\",\"params\":[\"ct\",3200,100]}";
          client.println(payload);
          break;
        }
      }
      delay(300);
    }
  }
}
