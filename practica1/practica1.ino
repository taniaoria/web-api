#include  <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

const char* ssid     = "INFINITUM697B_2.4"; 
const char* password = "tacosalpastor"; 
String server = "http://192.168.1.68:3000/users";

String estado = "0";



const int s1 = D0;
const int s2 = D1;

int valorS1 = LOW;
int valorS2 = LOW;


void setup() {
  Serial.begin(9600);

  pinMode(s1, INPUT);
  pinMode(s2, INPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); 
  delay(1000); 
}

void loop() {
 post(estado);
  valorS1 = digitalRead(s1);
  valorS2 = digitalRead(s2);

    if(valorS1 == HIGH && valorS2 == LOW){
       estado = "1";
       
        

    }else
    if(valorS2 == HIGH && valorS1 == LOW){
       estado = "2";
         

        
    }else
    if(valorS1 == LOW && valorS2 == LOW){
       estado = "0";
       

       
    }
    delayMicroseconds(1000);
}


void post(String estado) {
   HTTPClient http;
  String json;
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["estado"] = estado;
  root.printTo(json);
  Serial.println(""); // salto de linea para http.writeToStream(&Serial);
  http.begin(server);
  http.addHeader("Content-Type", "application/json");
  http.POST(json);
  http.writeToStream(&Serial);
  http.end();
}
