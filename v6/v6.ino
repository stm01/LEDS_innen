/*
  
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

//#define triggerval 940


#include <LiquidCrystal.h>                                              // include the library code:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);                                  // initialize the library with the numbers of the interface pins

int sensorPin = A0;                    // Helligkeitssensor
int sensorPinPot = A1;              // Poti für Trigger  
int out0 = 13; 
int out1 = 10;                      // select the pin for the LED
int sensorValue = 0; 
int Pot;                                // variable to store the value coming from the sensor
int triggerval = 1023;
//long randnumber;
unsigned long time;
unsigned long timenew;
unsigned long randNumber;
long einschaltzeit = 21600000; // 1000msec*60sec*60min*6h
bool hell;
bool dunkel;                                 // Wenn Dunkel dann an bis ca 23 Uhr plus minus 30 Minuten
                                                    // Einschalten ab Schwelle Trigger für einschaltzeit
                                                    
void setup() {
  // set up the LCD's number of columns and rows:
     pinMode(out0, OUTPUT);
     pinMode(out1, OUTPUT);
     pinMode(sensorPin, INPUT);
     pinMode(sensorPinPot, INPUT);
     // TODO: adcs deklarieren
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("V7 - 9.10.2016");
  delay(2000);
  lcd.clear();
  lcd.print("Testing Outputs");
   digitalWrite(out0, HIGH);
   digitalWrite(out1, HIGH);
   delay(500);
   digitalWrite(out0, LOW);
   digitalWrite(out1, LOW);
   delay(500);
   digitalWrite(out0, HIGH);
   digitalWrite(out1, HIGH);
   delay(1000);
   lcd.setCursor(0,0);
   lcd.print("leicht bewoelkt =");
   lcd.setCursor(0,1);
   lcd.print("@114");
   delay(3000);
   
  lcd.setCursor(0,0);
  lcd.print("hoeherer wert ");
   
   lcd.setCursor(0,1);
   lcd.print("= heller");
   delay(3000);
   
  lcd.clear();
   
   lcd.clear();  
   lcd.setCursor(0,0);
   lcd.print(analogRead(sensorPin));
   delay(500);
   lcd.clear();  
   lcd.setCursor(0,0);
   lcd.print(analogRead(sensorPin));
   delay(500);
   lcd.clear();  
   lcd.setCursor(0,0);
   lcd.print(analogRead(sensorPin));
   delay(500);
   lcd.clear();  
   lcd.setCursor(0,0);
   lcd.print(analogRead(sensorPin));
   
   Serial.begin(9600); 
   delay(1000);
   
}

void loop() {
  time = millis();
  randNumber = random(1800000); // 1000msec*60sec*30min => max 30 Minuten.
  Serial.println(randNumber); 
                                                                                                                                                
   //lcd.print(millis() / 1000);
   sensorValue = analogRead(sensorPin);
   Pot = analogRead(sensorPinPot);
   lcd.setCursor(0,1);
   lcd.print("Trg ");
   lcd.print(Pot);
   
   lcd.setCursor(10, 1);
   lcd.print(sensorValue,10);
   
    if (sensorValue >= Pot - 30)
      {
        digitalWrite(out0, LOW);
        lcd.setCursor(0,0);
        lcd.print("Hell genug..."); 
        //lcd.clear();
        //timenew = 0;
        //hell = true;
        //dunkel = false; 
              }
    else {
            /* digitalWrite(out0, HIGH);
             delay(500);
             digitalWrite(out0, LOW);
             delay(500);
             digitalWrite(out0, HIGH);
             delay(500);
             digitalWrite(out0, LOW);
             delay(500);
             digitalWrite(out0, HIGH);
             delay(500);
             digitalWrite(out0, LOW);
             delay(500);        */
             digitalWrite(out0, HIGH);
            lcd.setCursor(0,0);
            lcd.print("Dunkel");
            lcd.setCursor(7,0); 
            lcd.print("Out 0 an");
            //lcd.clear();
            //time = timenew;
            //hell = false;
            //dunkel = true;   
            /*timenew ++;
               if (timenew >= einschaltzeit + randNumber)
                      {
                        digitalWrite(out0, LOW);
                        lcd.setCursor(0,0);
                        lcd.print("tmax-lim"); 
                        
                      }
                    else{
                                digitalWrite(out0, HIGH);
                                lcd.setCursor(0,0);
                                lcd.print("Dunkel!"); 
                                //lcd.clear();
                                
                                //time = timenew;
                                hell = false;
                               dunkel = true;                                         
                        }*/                                               
       }
  
  if (sensorValue >= Pot)
      {
        digitalWrite(out1, LOW);
        lcd.setCursor(0,0);
        lcd.print("Hell genug..."); 
        //lcd.clear();
        //timenew = 0;
        //hell = true;
        //dunkel = false; 
        
      }
  else {
             /*digitalWrite(out1, HIGH);
             delay(500);
             digitalWrite(out1, LOW);
             delay(500);
             digitalWrite(out1, HIGH);
             delay(500);
             digitalWrite(out1, LOW);
             delay(500);
             digitalWrite(out1, HIGH);
             delay(500);
             digitalWrite(out1, LOW);
             delay(500);*/        
             digitalWrite(out1, HIGH);
             lcd.setCursor(0,0);
             lcd.print("Dunkel");
             lcd.setCursor(6,0); 
             lcd.print("Out 0+1 an");
                                
                                //lcd.clear();
                                
                                //time = timenew;
                                //hell = false;
                                //dunkel = true;   
               
                   /*timenew ++;
                    if (timenew >= einschaltzeit + randNumber)
                      {
                        digitalWrite(out0, LOW);
                        lcd.setCursor(0,0);
                        lcd.print("tmax-lim"); 
                        
                      }
                    else 
          
                      {
                                digitalWrite(out0, HIGH);
                                lcd.setCursor(0,0);
                                lcd.print("Dunkel!"); 
                                //lcd.clear();
                                
                                //time = timenew;
                                hell = false;
                                dunkel = true;
                  
                        
                        }*/                 
                              
       }
      
  delay(1800000); //3 Minuten warten
  lcd.clear();
  
}

