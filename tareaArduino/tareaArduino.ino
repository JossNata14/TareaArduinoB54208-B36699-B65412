#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

const int switchPin=6;
int switchState=6;
int prevSwitchState=0;
int reply;
long pulsador= 0;
long pulsador2=0;
long numero=0;

void setup(){
  lcd.begin(16,2);
   Serial.begin(9600);
  
  pinMode(7,OUTPUT);        //declaramos el pin 2 como salida
  pinMode(8,INPUT); 
  pinMode(13,INPUT);
  pinMode(switchPin, INPUT);
  
         
           pulsador = digitalRead(8);
  pulsador2=digitalRead(13);
   
   
}

void loop(){
  
 
  //lee el estado del bot�n
  if(digitalRead(8)==HIGH) {//si el estado es pulsado
      // Three=Three+"1";
       
       numero = numero * 10 + 1;
       lcd.setCursor(1,1);
       lcd.print(numero); 
       
          
       digitalWrite(7,HIGH);       //se enciende el led
       delay(1000);
       //Serial.println(Three);
     

       long k=binaryToDecimal(numero);

       //       lcd.print(k);
        //lcd.setCursor(0,1);
      // Serial.println(k);
     
  }
else if(digitalRead(13)==HIGH){//si el estado es no pulsado
   
        numero = numero * 10 + 0;
       lcd.setCursor(1,1);
       lcd.print(numero); 
       
          
       digitalWrite(7,HIGH);       //se enciende el led
       delay(1000);
       //Serial.println(Three);
     

       long k=binaryToDecimal(numero);

       // lcd.setCursor(0,1);
   //se apaga el led
  }     
  else{
     digitalWrite(7,LOW);
  }
 // lcd.noDisplay();
  //delay(500);
  // Turn on the display:
  //lcd.display();
  //delay(500);
   
}
int binaryToDecimal(long binaryNumber) {
   
       
      long decimal = 0;
  long temp;
    long p = 0;
    while(binaryNumber!=0){
      if(p<2||p>=6){
           temp=binaryNumber%10;
     decimal+=temp*pow(2,p);
     

     binaryNumber=binaryNumber/10;
       p++;
      }else{
    temp=binaryNumber%10;
     decimal+=temp*pow(2,p)+1;
     binaryNumber=binaryNumber/10;
     p++;
      }
  }
     lcd.setCursor(0,0);
 lcd.print(decimal, DEC );
  
 delay(1500);
      return decimal;
}


