// Nikhil Agans
// This project's goal is to be able create a password-based door locked system with a remote controller
// 11/07/25
#include <LiquidCrystal.h>
#include <IRremote.hpp>


int receiver = 11; // This is the digital pin 11 that the IR is connected to
uint32_t IRcodes[4]={}; 
int check = 0;
const int rs = 12, en = 10, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
Serial.begin(9600); // this starts serial communication between Arduino and computer
IrReceiver.begin(receiver, ENABLE_LED_FEEDBACK); // IR reciever object listens for infared singals with LED Feedback from Arduino LED
Serial.println("IR Receiver ready"); //prints to the serial monitor with a line break

lcd.begin(16, 2); // set up the LCD's number of columns and rows:

}

void loop() {

lcd.setCursor(5, 0); //set the cursor to print statment in the middle top of the LCD
lcd.print("LOCKED");


// A for loop to receive the IR signals and to check if the password is right if not keep in the loop!
while(check != 1){
for (int i = 0; i < 4; i++){
 while (!IrReceiver.decode()) { // if there is a valid signal decode and store into receiver
  // way to wait for the code. This means if no code recieved then it is true and keep looping until there is a code then move
 }

 uint32_t code = IrReceiver.decodedIRData.decodedRawData; // put into variable 'code' with the data type of an unsigned 32 bit long

if (code == 0){  
IrReceiver.resume();
i = i - 1;
} //if I get a bad signal dont store it so we will deincrement the i value to redo the loop until we get a good signal 
 
IRcodes[i] = code; // this allows us to store the bits recieved into an array throughout the loop
Serial.println(IRcodes[i], HEX ); //way for me to see if the code in the serial monitor to check this loop was working
Serial.println(i, DEC);
IrReceiver.resume();   //resumes detecting new signals and keep looping until 4 iterations
delay(800); //stops the singal from receiving a button hold 
// increased the delay which helped from button holds messing up as human reaction is not that fast on average so delay it by half a second
 } // loop to gather the four IR signals 

//analyze the array to decode whether it is the combination we need
if (IRcodes[0] == 0xF30CFF00 && IRcodes[1] == 0xE718FF00 && IRcodes[2] == 0xA15EFF00 && IRcodes[3] == 0xF708FF00 ){
check = 1; // checking if we have the correct password in the array
} else if (IRcodes[0] != 0xF30CFF00 && IRcodes[1] != 0xE718FF00 && IRcodes[2] != 0xA15EFF00 && IRcodes[3] != 0xF708FF00) {
Serial.println("Password entered is wrong!");
}
}// this ends the outer while loop



// if we dont have the correct combination we stay in the loop if we do then we can go and use the LCD and motor
// LCD code 
Serial.println("Password entered is correct!");
lcd.clear();
lcd.setCursor(4, 0); //set the cursor to print statment in the middle top of the LCD
lcd.print("UNLOCKED");
delay(3000); //holds the UNLOCKED statement for 3 seconds/3000ms
}// end of void loop
