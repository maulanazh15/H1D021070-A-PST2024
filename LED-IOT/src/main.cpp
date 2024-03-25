#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266WiFi.h>

// put function declarations here:

const char *ssid = "TEKNIK UNSOED D3";
const char *password = "";

String website;
AsyncWebServer server(80);

int redLED = D2;
int yellowLED = D0;
int greenLED = D1;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  Serial.begin(9600);
  delay(10);
  // setting access poin
  // WiFi.mode(WIFI_AP);
  // WiFi.softAP(ssid, password);
  // Serial.print("Wifi: ");
  // Serial.println(ssid);
  // Serial.print("IP Address : ");
  // Serial.println(WiFi.softAPIP());
  // setting mode station
Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(300);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  website+= "<h1> Web Control ESP8266</h1>";
  website+= "<p>LED 1: ";
  website+= "<a href=\"LED1ON\"\"><button>ON</button></a><a     href=\"LED1OFF\"\"><button>OFF</button></a></p><br>";
  website+= "<p>LED 2: ";
  website+= "<a href=\"LED2ON\"\"><button>ON</button></a><a href=\"LED2OFF\"\"><button>OFF</button></a></p><br>";
  website+= "<p>LED 3: ";
  website+= "<a href=\"LED3ON\"\"><button>ON</button></a><a href=\"LED3OFF\"\"><button>OFF</button></a></p>";

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", website);
  });
  
  server.on("/LED1ON", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(redLED, HIGH);
    request->send(200, "text/html", website);
  });
  
  server.on("/LED2ON", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(yellowLED, HIGH);
    request->send(200, "text/html", website);
  });

  server.on("/LED3ON", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(greenLED, HIGH);
    request->send(200, "text/html", website);
  });

  server.on("/LED1OFF", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(redLED, LOW);
    request->send(200, "text/html", website);
  });
  
  server.on("/LED2OFF", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(yellowLED, LOW);
    request->send(200, "text/html", website);
  });

  server.on("/LED3OFF", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(greenLED, LOW);
    request->send(200, "text/html", website);
  });

  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
}

