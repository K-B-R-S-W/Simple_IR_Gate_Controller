#include <ESP32Servo.h>

// Pin definitions
#define IR_SENSOR_PIN 2    // Digital pin for IR sensor output
#define SERVO_PIN 18       // PWM pin for servo control

// Servo object
Servo gateServo;

// Gate positions (adjust these values based on your gate setup)
#define GATE_CLOSED_ANGLE 0    // Angle when gate is closed
#define GATE_OPEN_ANGLE 90     // Angle when gate is open

// Timing variables
#define CLOSE_DELAY 3000       // Delay before closing gate (3 seconds)
#define SENSOR_DEBOUNCE 100    // Debounce delay for sensor reading

// System variables
bool gateOpen = false;
bool objectDetected = false;
unsigned long lastDetectionTime = 0;
unsigned long lastSensorRead = 0;

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  Serial.println("Car Entrance Detection System Starting...");
  
  // Initialize pins
  pinMode(IR_SENSOR_PIN, INPUT);
  
  // Initialize servo
  gateServo.attach(SERVO_PIN);
  gateServo.write(GATE_CLOSED_ANGLE); // Start with gate closed
  
  Serial.println("System initialized. Gate closed.");
  Serial.println("Waiting for car detection...");
}

void loop() {
  // Read IR sensor with debouncing
  if (millis() - lastSensorRead >= SENSOR_DEBOUNCE) {
    bool currentDetection = digitalRead(IR_SENSOR_PIN);
    
    // IR sensor module typically outputs LOW when object is detected
    // Adjust this logic if your sensor works differently
    objectDetected = !currentDetection; // Invert if needed
    
    lastSensorRead = millis();
  }
  
  // Handle gate control based on detection
  if (objectDetected) {
    // Object detected - open gate if not already open
    if (!gateOpen) {
      openGate();
    }
    // Update last detection time
    lastDetectionTime = millis();
  } else {
    // No object detected
    
    // Close gate after delay if it's currently open
    if (gateOpen && (millis() - lastDetectionTime >= CLOSE_DELAY)) {
      closeGate();
    }
  }
  
  // Print status every 2 seconds for debugging
  static unsigned long lastStatusPrint = 0;
  if (millis() - lastStatusPrint >= 2000) {
    printStatus();
    lastStatusPrint = millis();
  }
  
  delay(50); // Small delay to prevent excessive processing
}

void openGate() {
  Serial.println("Car detected! Opening gate...");
  gateServo.write(GATE_OPEN_ANGLE);
  gateOpen = true;
  
  // Optional: Add smooth movement
  /*
  for (int angle = GATE_CLOSED_ANGLE; angle <= GATE_OPEN_ANGLE; angle += 5) {
    gateServo.write(angle);
    delay(50);
  }
  */
}

void closeGate() {
  Serial.println("No car detected. Closing gate...");
  gateServo.write(GATE_CLOSED_ANGLE);
  gateOpen = false;
  
  // Optional: Add smooth movement
  /*
  for (int angle = GATE_OPEN_ANGLE; angle >= GATE_CLOSED_ANGLE; angle -= 5) {
    gateServo.write(angle);
    delay(50);
  }
  */
}

void printStatus() {
  Serial.print("Status - Object: ");
  Serial.print(objectDetected ? "DETECTED" : "NOT DETECTED");
  Serial.print(" | Gate: ");
  Serial.print(gateOpen ? "OPEN" : "CLOSED");
  Serial.print(" | IR Sensor Reading: ");
  Serial.println(digitalRead(IR_SENSOR_PIN));
}

/*
 * WIRING CONNECTIONS:
 * 
 * IR Sensor Module:
 * - VCC  → ESP32 5V (or 3.3V depending on your module)
 * - GND  → ESP32 GND
 * - OUT  → ESP32 GPIO2 (IR_SENSOR_PIN)
 * 
 * Tower Pro Micro Servo 9g:
 * - Red Wire (VCC)    → ESP32 5V
 * - Black Wire (GND)  → ESP32 GND  
 * - Orange Wire (PWM) → ESP32 GPIO18 (SERVO_PIN)
 * 
 * IMPORTANT NOTES:
 * 1. Make sure your ESP32 can provide enough current for the servo
 * 2. Consider using external 5V power supply for servo if needed
 * 3. Adjust GATE_CLOSED_ANGLE and GATE_OPEN_ANGLE based on your gate mechanism
 * 4. Test the IR sensor detection logic - some modules output HIGH when detecting, others LOW
 * 5. Adjust CLOSE_DELAY timing as needed for your application
 */