#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>


#include <SoftwareSerial.h>
#include <ArduinoJson.h> 


//my network credentials
const char* ssid = "costales2.4ghz";
const char* password = "Costales@0328";

String serverName = "http://192.168.1.15/despro/";


//ESP8266WebServer server(80); //create object on port 80

String page = "";
double data;

int water_level;

  SoftwareSerial Arduino_Serial(D6, D5);
  
void setup() {
          
  
  // put your setup code here, to run once:
  //init serial port
  Serial.begin(9600);
  Arduino_Serial.begin(9600);
  WiFi.begin(ssid, password); //connect to wifi

  //wait for connection
  while (WiFi.status() !=WL_CONNECTED){
    delay(500);
    Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
      Serial.println(WiFi.localIP());
//      server.on("/", [](){
//        page = "<h1>Automatic Aquaponics</h1><h3>Water Level:</h3> <h4>" + String(water_level)+ "</h4>";
//        server.send(200, "text/html", page);
//        });


         // server.begin();
         // Serial.println("Web server started");
        delay(10000);
  while (!Serial) continue;

 //String result = GET_request("soil-data.php?");
  
}

void loop(void) {
  // put your main code here, to run repeatedly:
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& data = jsonBuffer.parseObject(Arduino_Serial);

  if (data == JsonObject::invalid()){
    Serial.println("Invalid Json Object");
    jsonBuffer.clear();
    return;
    }

    Serial.println("JSON object Recieved");
    water_level = data["Water Level"];
    int soil_moisture = data["Soil"];
    int temperature = data["Temperature"];
    float humidity = data["Humidity"];
    float ph_level = data["ph Level"];
  //  server.handleClient();

    GET_request("soil-data.php?soil_value=" + String(soil_moisture)+ "&ph_value=" +String(ph_level)+ "&water_value=" +String(water_level)); 
    delay(2000);
}
