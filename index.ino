#include <Servo.h>

// Define the IR sensor input pin and the servo output pin
const int sensorPin = 6;
const int servoPin = 7;

// Create a Servo object to control the servo motor
Servo servo;

// Flag to indicate whether the servo has already been activated
bool trapActivated = false;

void setup() {
    Serial.begin(9600);

    pinMode(sensorPin, INPUT); // Set the sensor pin as input
  // Attach the servo to its pin
  servo.attach(servoPin);
    servo.write(180);
delay(1000);
  // Set up the serial monitor
}

void loop() {
  // If the servo has already been activated, do nothing
  if(trapActivated == true ) { 
    return;
  }


  // Read the input from the IR sensor
  int sensorValue = digitalRead(sensorPin);

  // If the sensor input is HIGH, activate the servo motor
    if (sensorValue == HIGH) {
      Serial.println("Sensor input received, activating servo.");
            servo.write(0);    // Wait 1 second before resetting the servo
            delay(1000);

      servo.detach();
 // Set the servo to 90 degrees
      //servo.detach();  // Set the servo back to 0 degrees
      trapActivated = true; // Set the flag to indicate that the servo has been activated
      
    }
  


  // Wait for a short time before checking the sensor input again
}
