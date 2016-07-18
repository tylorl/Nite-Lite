/* Dimmer - send data from the computer to the Arduino board 
 *  to control the brightness of an LED.  The data is sent
 *  in individual bytes, each of which ranges from 0 to 255.  Arduino
 *  reads these bytes and uses them to set the brightness of the LED.
 *  
 *  LED attached from digital pin 9 to ground.
 */

const int ledPin = 9;                 // LED 35mA max @ 5V via 150ohm resistor

void setup() {
  Serial.begin(9600);                 // Serial port to Arduino IDE @ 9600 Baud
  pinMode(ledPin, OUTPUT);
}

void loop() {
  byte brightness;

  // check if data has been sent from the computer:
  if (Serial.available()) {
    brightness = Serial.read();       // Read the most recent byte
    analogWrite(ledPin, brightness);  // Set the brightness of the LED
  }
}
