#include "Wire.h" // Pour  I2C
#include "LCD.h" // Pour ecran LCD
#include "LiquidCrystal_I2C.h" // Added library*
#include <multiCameraIrControl.h> // Librairie Infra rouge

Canon myCamera(9);

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7); 





#define outputA 6
#define outputB 7
#define switchPin 3
#define VALVE 13

int counter = 0; 
int aState;
int aLastState;  
int count;
int DIAMG1;
int DIAMG2;
int DELAI1;
int DELAI2;


int passFlag; // FLAG COUNTER FOR LCD CLEAR SECTION 1
int passFlag1; // FLAG COUNTER FOR LCD CLEAR SECTION 2
int passFlag2; // FLAG COUNTER FOR LCD CLEAR SECTION 3
int passFlag3; // FLAG COUNTER FOR LCD CLEAR SECTION 4
int val = 0; // variable for reading the pin status
int currentState = 0;
int previousState = 0;


void setup()





{

  
   // Preparation écran lcd
  
   lcd.begin (20,4); // 16 x 2 LCD module
   lcd.setBacklightPin(3,POSITIVE); // BL, BL_POL
   lcd.setBacklight(HIGH);
 

Serial.begin(9600);
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   pinMode (VALVE,OUTPUT);
   pinMode(switchPin, INPUT_PULLUP);
   Serial.begin (9600);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA);   


   
}


void loop() { 






val = digitalRead(switchPin); // read input value
if (val == HIGH) { // check if the input is HIGH (button released)
//digitalWrite(ledPin, HIGH); // turn LED on
currentState = 1;
}
else {
currentState = 0;
}
if(currentState != previousState){
if(currentState == 1){
counter = counter + 1;
 lcd.setCursor(0,0);
lcd.print ("----|| WDC V2 ||----");
 lcd.setCursor(0,1);
lcd.print ("WATER DROP CONTROLER");
 lcd.setCursor(0,2);
lcd.print ("VERS 2.0 BETA");
 lcd.setCursor(0,3);
lcd.print ("JK / 2019");
delay(2000);
lcd.clear();
lcd.setCursor(0,2);


lcd.print("[]");
delay(500);
lcd.print("[]");
delay(500);
lcd.print("[]");
delay(500);
lcd.print("[]");
delay(500);
lcd.print("[]");
delay(500);

lcd.clear();
 lcd.setCursor(0,2);
lcd.print ("PUSH BUTTON TO START");
}
}
previousState = currentState;

// DIAMETRE GOUTTE N1
while (counter == 2) {
  val = digitalRead(switchPin); // read input value
if (val == HIGH) { // check if the input is HIGH (button released)
//digitalWrite(ledPin, HIGH); // turn LED on
currentState = 1;
}
else {
currentState = 0;
}
if(currentState != previousState){
if(currentState == 1){
counter = counter + 1;
 lcd.setCursor(0,0);
lcd.print (counter);
}
}
previousState = currentState;

 if (passFlag == 0) {
  lcd.clear();
  passFlag ++;
 }
   lcd.setCursor(0,0);
   lcd.print ("DIAMETRE GOUTTE 1");




        aState = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       DIAMG1 ++;
     } else {
       DIAMG1 --;
     }
    lcd.setCursor(0,1);
    lcd.print(DIAMG1*10);
    
   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state


   
} 
// DELAI NUMERO 1
while (counter == 3) {

   if (passFlag1 == 0) {
  lcd.clear();
  passFlag1 ++;
 }
  lcd.setCursor(0,0);
lcd.print ("DELAI ENTRE GOUTTES");
 
  val = digitalRead(switchPin); // read input value
if (val == HIGH) { // check if the input is HIGH (button released)
//digitalWrite(ledPin, HIGH); // turn LED on
currentState = 1;
}
else {
currentState = 0;
}
if(currentState != previousState){
if(currentState == 1){
counter = counter + 1;

}
}
previousState = currentState;
 // lcd.setCursor(0,3);
   //lcd.print ("Numero trois");
        aState = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       DELAI1 ++;
     } else {
       DELAI1 --;
     }
    lcd.setCursor(0,1);
    lcd.print(DELAI1*10);
    
   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state
} 

while (counter == 4) {

     if (passFlag2 == 0) {
  lcd.clear();
  passFlag2 ++;
 }
  lcd.setCursor(0,0);
lcd.print ("DIAMETRE GOUTTE 2");

    val = digitalRead(switchPin); // read input value
if (val == HIGH) { // check if the input is HIGH (button released)
//digitalWrite(ledPin, HIGH); // turn LED on
currentState = 1;
}
else {
currentState = 0;
}
if(currentState != previousState){
if(currentState == 1){
counter = counter + 1;
 //lcd.setCursor(0,0);
//lcd.print (counter);
}
}
previousState = currentState;

     aState = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       DIAMG2 ++;
     } else {
       DIAMG2 --;
     }
    lcd.setCursor(0,1);
    lcd.print(DIAMG2*10);
    
   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state
} 





// DELAI NUMERO 2
while (counter == 5) {

   if (passFlag2 == 0) {
  lcd.clear();
  passFlag2 ++;
 }
  lcd.setCursor(0,0);
lcd.print ("DELAI AVANT FLASH");
 
  val = digitalRead(switchPin); // read input value
if (val == HIGH) { // check if the input is HIGH (button released)
//digitalWrite(ledPin, HIGH); // turn LED on
currentState = 1;
}
else {
currentState = 0;
}
if(currentState != previousState){
if(currentState == 1){
counter = counter + 1;

}
}
previousState = currentState;
 // lcd.setCursor(0,3);
   //lcd.print ("Numero trois");
        aState = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       DELAI2 ++;
     } else {
       DELAI2 --;
     }
    lcd.setCursor(0,1);
    lcd.print(DELAI2*10);
    
   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state
} 








while (counter == 6) {

  val = digitalRead(switchPin); // read input value
if (val == HIGH) { // check if the input is HIGH (button released)
//digitalWrite(ledPin, HIGH); // turn LED on
currentState = 1;
}
else {
currentState = 0;
}
if(currentState != previousState){
if(currentState == 1){
counter = counter + 1;

}
}
previousState = currentState;

   if (passFlag3 == 0) {
  lcd.clear();
  delay(1000);
  if (DIAMG1< 0) { DIAMG1 = DIAMG1 * -1;}
  if (DIAMG2< 0) { DIAMG2 = DIAMG2 * -1;}
  if (DELAI1< 0) { DELAI1 = DELAI1 * -1;}
  if (DELAI2< 0) { DELAI2 = DELAI2 * -1;}
  
DIAMG1 = DIAMG1 *10;
DIAMG2 = DIAMG2 *10;
DELAI1 = DELAI1*10;
DELAI2 = DELAI2*10;

lcd.setCursor(0,0);
lcd.print (DIAMG1);
lcd.setCursor(0,1);
lcd.print (DELAI1);
lcd.setCursor(0,2);
lcd.print (DIAMG2);
lcd.setCursor(0,3);
lcd.print (DELAI2);



Serial.println(DIAMG1);
Serial.println(DIAMG2);
Serial.println(DELAI1);
Serial.println(DELAI2);

  passFlag3 ++;
 }
  



  
     
} 




// ACTIVATION VALVE + FLASH

while (counter == 7) {

lcd.clear();

// DIAMETRE GOUTTE 1
 digitalWrite(VALVE, HIGH);
 delay (DIAMG1);
 digitalWrite(VALVE, LOW);

// DELAI 1
 delay (DELAI1);


   // DIAMETRE GOUTTE 1
 digitalWrite(VALVE, HIGH);
 delay (DIAMG2);
 digitalWrite(VALVE, LOW);

   
   // DELAI POUR ACTIVATION FLASH
   delay(DELAI2);
   myCamera.shutterNow();
   
   
   delay(10000);
} 


 
 }
 
