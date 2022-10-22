
#include <SensusProtocol.h>
//LCD Stuff below
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int clock_pin = 6; //Black wire
int read_pin = 5; //Green Wire
//Red wire is 3.3v

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
  lcd.print("Register #1");
  lcd.setCursor(0,1);
  lcd.print("Serial: "+data.substring(13,22));
  lcd.setCursor(0,2);
  lcd.print("Reading: "+data.substring(4,10));
  lcd.setCursor(0,3);
  lcd.print("Other: "+data.substring(24,99));
  delay(500);
}

//Sample LCD OUTPUT
//  Register #1
//  Serial: 221008072
//  Reading: 000002
//  Other: 0302?!
//Sample Serial OUTPUT
//  entering loop...
//  data: %i, %s
//  
//  V;RB000002;IB221008072;M0302?!

// Register Pin Diagram
//
//    GREEN    RED
//      *       *
//
//          *
//        BLACK
