#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LcdBarGraphRobojax.h>
int offset =20;

byte lcdNumCols = 16; // -- number of columns in the LCD
byte lcdLine = 2; // -- number of line in the LCD
byte sensorPin = 0; // -- value for this example


LiquidCrystal_I2C lcd(0x27, 16, 2); // -- creating LCD instance
LcdBarGraphRobojax lbg(&lcd, 16, 0, 0);  // -- creating 16 character long bargraph starting at char 0 of line 0 
        
void setup(){
  // -- initializing the LCD
  lbg.begin();
  lcd.begin();
  lcd.clear();
  lcd.print("Battery Voltage"); 
  lcd.setCursor (0,1); //  
  lcd.print("Level Indicator"); 
  delay(2000);
  lcd.clear();
}

void loop()
{
  lbg.clearLine(1);// clear line 1 to display fresh voltage value

  
  int inpuValue = analogRead(A0);
  int volt = analogRead(A0);
  double voltage = map(volt,0,1023, 0, 2500) + offset;// map 0-1023 to 0-2500 and add correction offset
  voltage /=7.4;// divide by 100 to get the decimal values
  // -- draw bar graph from the analog value read
  lbg.drawValue( inpuValue, 520);
  // -- do some delay: frequent draw may cause broken visualization
  lcd.setCursor (0,1); //
  lcd.print("Bat Charge:"); 
  lcd.setCursor (11,1); //
  lcd.print(voltage); // print
  lcd.setCursor (15,1); //  
  lcd.print("%");   
 
  delay(100);
}
