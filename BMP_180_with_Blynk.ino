#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

Adafruit_BMP085 bmp;

float temp, pressure, Altitude, Sealevel;

char auth[] = "8LU16RepIbHVm0gt7-9-XMz9l-rwXjsS";

char ssid[] = "Dlink";
char pass[] = "Pabitra1999";



void setup() 
{
  
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  Serial.print("Connecting.....");

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print("Waiting to connect WiFi\n");
  }
  Serial.print("WiFi is connected \n");
  Serial.print(WiFi.localIP());

  Blynk.begin(auth, ssid, pass);
  
  if (!bmp.begin())
  {
  Serial.println("Could not find a valid BMP085 sensor, check wiring!");
  while (1)
  {
    
  }
  }
 
}

void loop()
{
    Blynk.run();


    temp = bmp.readTemperature();
    pressure = bmp.readPressure();
    Sealevel = bmp.readSealevelPressure();
    Altitude = bmp.readAltitude();


    Blynk.virtualWrite(V6, temp);
    Blynk.virtualWrite(V7, pressure);
    Blynk.virtualWrite(V8, Sealevel);
    Blynk.virtualWrite(V9, Altitude);
    
    
    Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");

    Serial.print("Altitude = ");
    Serial.print(bmp.readAltitude());
    Serial.println(" meters");

    Serial.print("Pressure at sealevel (calculated) = ");
    Serial.print(bmp.readSealevelPressure());
    Serial.println(" Pa");

    

    Serial.println();
   
}
