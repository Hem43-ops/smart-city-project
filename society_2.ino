#include <LiquidCrystal_I2C.h>

#include<Wire.h>
#include<LiquidCrystal_I2c.h>
#include<SoftwareSerial.h>

SoftwareSerial gsmSerial(7,8);
LiquidCrystal_I2C lcd(0x27,16,2);

const int fireSensorPin=A0;
const int tiltSensorPin=A1;
const int mq2GasSensorPin=A2;
const int lm35SensorPin=A3;


void setup() {
 Serial.begin(9600);
 gsmSerial.begin(9600);
 lcd.begin(16,2);
 
 lcd.print("under Drainage");
 lcd.setCursor(0,1);
 lcd.print("Monitoring");
 
 delay(2000); 

}

void loop() {
  int fireValue=analogRead(fireSensorPin);
  int tiltValue=digitalRead(tiltSensorPin);
  int gasValue=analogRead (mq2GasSensorPin);
  float Temperature=getTemperature();
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Fire:");
  lcd.print(fireValue);
  lcd.setCursor(0,1);
  lcd.print("Gas");
  lcd.print(gasValue);
  
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("tilt");
  lcd.print(tiltValue);;
  lcd.setCursor(0,1);
  lcd.print("Temp");
  lcd.print("tempearature");
  lcd.print("C");
  
  delay(2000);
  
  if(fireValue>500 || tiltValue==HIGH || gasValue>500)
  {
    sendAlertSMS();
  }
  delay(5000);
}
  float getTemperature()
  {
    int sensorValue=analogRead(lm35SensorPin);
    float voltage= sensorValue*(5.0/1023.0);
    float temperature=(voltage-0.5)*100.0;
    return temperature;

  }
  void sendAlertSMS()
  {
    gsmSerial.println("AT+CMGF=1");
    delay(1000);
    gsmSerial.print("AT+CNMI=\+9779826454543\"");
    delay(1000);
    gsmSerial.print("under Drainage Alert!");
    gsmSerial.write(26);
    delay(1000);
  }
  
  


