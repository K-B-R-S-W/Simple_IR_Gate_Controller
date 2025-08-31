/*
 * Simple Servo Test
 * Use this to test if your servo motor is working
 */

#include <ESP32Servo.h>

#define SERVO_PIN 18

Servo testServo;

void setup() {
  Serial.begin(115200);
  Serial.println("Servo Test Starting...");
  
  testServo.attach(SERVO_PIN);
  Serial.println("Servo attached to pin 18");
  
  // Test servo movement
  Serial.println("Moving to 0 degrees...");
  testServo.write(0);
  delay(1000);
  
  Serial.println("Moving to 90 degrees...");
  testServo.write(90);
  delay(1000);
  
  Serial.println("Moving to 180 degrees...");
  testServo.write(180);
  delay(1000);
  
  Serial.println("Back to 0 degrees...");
  testServo.write(0);
  delay(1000);
  
  Serial.println("Servo test complete!");
}

void loop() {
  // Continuous sweep test
  for (int angle = 0; angle <= 180; angle += 10) {
    testServo.write(angle);
    Serial.print("Angle: ");
    Serial.println(angle);
    delay(200);
  }
  
  for (int angle = 180; angle >= 0; angle -= 10) {
    testServo.write(angle);
    Serial.print("Angle: ");
    Serial.println(angle);
    delay(200);
  }
}
