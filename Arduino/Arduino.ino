#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);
String cadenaAux;
String cadena;
int ledPINTrue=8;
int ledPINFalse=9;
const byte pinBuzzer = 10;
byte salida = 10;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(ledPINTrue , OUTPUT);
  pinMode(ledPINFalse , OUTPUT);
  cadena=cadenaAux;

}



void loop() {
   if (Serial.available()) 
   {  
    cadena= Serial.readString();
    if(cadena!=cadenaAux){
      writeLcd();
    }

    if(cadena=="yes"){
yesMode();
      
    }
    if(cadena=="no"){
      noMode();
    }
    if(cadena=="end"){

      endMode();
    }
    
    }    
    cadena=cadenaAux;

}

void yesMode(){
      digitalWrite(ledPINTrue , HIGH);
      digitalWrite(ledPINFalse , LOW); 
      analogWrite(pinBuzzer, salida);
  
}

void noMode(){
        digitalWrite(ledPINFalse , HIGH);
      digitalWrite(ledPINTrue , LOW);
  analogWrite(pinBuzzer, LOW);
  
  }

  void endMode(){
          digitalWrite(ledPINTrue , HIGH);
      delay(100);
      digitalWrite(ledPINTrue , LOW);
      delay(100);
      digitalWrite(ledPINFalse , HIGH);
      delay(100);
      digitalWrite(ledPINFalse , LOW);
       analogWrite(pinBuzzer, LOW);
    }

void writeLcd(){
     lcd.clear();
     lcd.setCursor(0,0);          
     lcd.print(cadena); 
}
