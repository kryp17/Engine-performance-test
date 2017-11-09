#include <LiquidCrystal.h>                                          
LiquidCrystal lcd(2,3,7,6,5,4);
//char in[3],out[3],tof[4];
String str1,str2,str3;
int count=1;


void setup() {
  Serial.begin(9600);
  lcd.begin(20,4);
  lcd.clear(); 
  lcd.setCursor(0,0);
  lcd.print("hi");
  lcd.clear(); 
}

void loop() {
  
    if(count=1)
    {
    str1=Serial.read();
    str2=Serial.read();
    str3=Serial.read();

    Serial.println(str1);
    Serial.println(str2);
    Serial.println(str3);
    lcd.setCursor(0,0);
    lcd.print("Initial=");
    lcd.print(str1);
    lcd.println(" mm");
    lcd.setCursor(0,1);
    lcd.print("Final=" );
    lcd.print(str2);
    lcd.println(" mm");
    lcd.setCursor(0,2);
    lcd.print("Time=");
    lcd.print(str3);
    lcd.print(" Sec");
    count=0;
    }
}
