#include <Servo.h>

// Define the IR sensor input pin and the servo output pin
const int sensorPin = 6;
const int servoPin = 7;

// Create a Servo object to control the servo motor
Servo servo;

// Flag to indicate whether the servo has already been activated
bool servoActivated = false;

void setup() {
  // Attach the servo to its pin
  servo.attach(servoPin);
      servo.write(180); // Set the servo to 90 degrees

  // Set up the serial monitor
  Serial.begin(9600);
}

void loop() {
  // If the servo has already been activated, do nothing
  if (servoActivated) {
    return;
  }

  // Read the input from the IR sensor
  int sensorValue = digitalRead(sensorPin);

  // If the sensor input is HIGH, activate the servo motor
  if (sensorValue == HIGH) {
    Serial.println("Sensor input received, activating servo.");
    servo.write(0); // Set the servo to 90 degrees
    delay(1000);     // Wait 1 second before resetting the servo
    servo.detach();  // Set the servo back to 0 degrees
    servoActivated = true; // Set the flag to indicate that the servo has been activated
  }

  // Wait for a short time before checking the sensor input again
  delay(100);
}
