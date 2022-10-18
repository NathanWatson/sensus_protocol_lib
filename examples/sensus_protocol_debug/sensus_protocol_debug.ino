
#include <SensusProtocol.h>
//LCD Stuff below
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int clock_pin = 6;
int read_pin = 5;

SensusProtocol SensusProtocol(6,5,true);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(3000);
  Serial.write("setup...\n");
  SensusProtocol.setup();
  Serial.write("setup done...\n");

  //LCD SETUP
  lcd.init();         // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("--------------------");
  lcd.setCursor(6,1);
  lcd.print("WatsonN");
   lcd.setCursor(1,2);
  lcd.print("Arduino IIC Screen");
   lcd.setCursor(0,3);
  lcd.print("--------------------");
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.write("entering loop...\n");
  String data = SensusProtocol.readData();
  Serial.write("data: %i, %s\n");
  Serial.write(data.length());
  Serial.write("\n");
  Serial.write(data.c_str());
  Serial.write("\n");
  lcd.init();
  lcd.setCursor(0,0);
  lcd.print("data: %i, %s\n");
  lcd.setCursor(0,1);
  lcd.print(data.length());
  lcd.setCursor(0,2);
  lcd.print(data.c_str());
  delay(500);
}
