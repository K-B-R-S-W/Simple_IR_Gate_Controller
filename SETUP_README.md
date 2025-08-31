# Setup Guide - IR Gate Controller

## Prerequisites

### Required Software
1. **Arduino IDE** (version 2.0 or later)
   - Download from: https://www.arduino.cc/en/software
2. **ESP32 Board Package** for Arduino IDE
3. **ESP32Servo Library**

### Required Hardware
- ESP32 Development Board (38-pin)
- IR Sensor Module
- Tower Pro Micro Servo 9g (SG90)
- Jumper wires
- Breadboard (for prototyping)
- USB cable (for ESP32 programming)

## Step-by-Step Setup Instructions

### 1. Arduino IDE Configuration

#### Install ESP32 Board Package
1. Open Arduino IDE
2. Go to **File → Preferences**
3. In "Additional Board Manager URLs", add:
   ```
   https://dl.espressif.com/dl/package_esp32_index.json
   ```
4. Go to **Tools → Board → Boards Manager**
5. Search for "ESP32" and install "ESP32 by Espressif Systems"

#### Install Required Libraries
1. Go to **Tools → Manage Libraries** (or press Ctrl+Shift+I)
2. Search and install:
   - **ESP32Servo** by Kevin Harrington
   
**Important**: If you get compilation error "ESP32Servo.h: No such file or directory":
- Make sure the ESP32Servo library is properly installed
- Restart Arduino IDE after installation
- Verify the library appears in Sketch → Include Library menu

### 2. Hardware Assembly

#### Wiring Connections
Follow the wiring diagram below:

```
ESP32 Pin    →    Component
────────────────────────────────
3.3V           →    IR Sensor VCC
5V           →    Servo Red Wire
GND          →    IR Sensor GND
GND          →    Servo Black Wire
GPIO2        →    IR Sensor OUT
GPIO18       →    Servo Orange Wire
```

#### Physical Assembly Steps
1. **Connect IR Sensor**:
   - Red wire (VCC) to ESP32 5V pin
   - Black wire (GND) to ESP32 GND pin
   - Signal wire (OUT) to ESP32 GPIO2

2. **Connect Servo**:
   - Red wire to ESP32 5V pin
   - Black/Brown wire to ESP32 GND pin
   - Orange/Yellow wire to ESP32 GPIO18

3. **Double-check all connections** before powering on

### 3. Software Configuration

#### Board Selection
1. Connect ESP32 to computer via USB
2. In Arduino IDE, select:
   - **Board**: "ESP32 Dev Module"
   - **Port**: Select the COM port for your ESP32
   - **Upload Speed**: 115200

#### Code Configuration Options
Open `Main.ino` and adjust these parameters if needed:

```cpp
// Pin definitions (change if using different pins)
#define IR_SENSOR_PIN 2    
#define SERVO_PIN 18       

// Gate positions (adjust for your gate mechanism)
#define GATE_CLOSED_ANGLE 0    
#define GATE_OPEN_ANGLE 90     

// Timing settings (in milliseconds)
#define CLOSE_DELAY 3000       // Time before auto-close
#define SENSOR_DEBOUNCE 100    // Sensor reading stability
```

### 4. Upload and Test

#### Upload Code
1. Connect ESP32 to computer
2. Select correct board and port
3. Click **Upload** button
4. Wait for "Hard resetting via RTS pin..." message

#### Initial Testing
1. Open **Serial Monitor** (Tools → Serial Monitor)
2. Set baud rate to **115200**
3. You should see startup messages:
   ```
   Car Entrance Detection System Starting...
   System initialized. Gate closed.
   Waiting for car detection...
   ```

### 5. Calibration and Testing

#### IR Sensor Calibration
1. **Sensitivity Adjustment**:
   - Locate potentiometer on IR sensor module
   - Turn clockwise to increase sensitivity
   - Turn counter-clockwise to decrease sensitivity
   - Test with objects at desired detection distance

2. **Detection Logic Verification**:
   - Monitor Serial output while testing
   - Some IR modules output LOW when detecting, others HIGH
   - If detection logic is inverted, change this line in code:
   ```cpp
   objectDetected = !currentDetection;
   ```

#### Servo Calibration
1. **Angle Adjustment**:
   - Verify gate closes completely at 0°
   - Verify gate opens fully at 90°
   - Adjust `GATE_CLOSED_ANGLE` and `GATE_OPEN_ANGLE` as needed

2. **Mechanical Testing**:
   - Ensure servo has enough torque for gate
   - Check for smooth operation
   - Test auto-close timing

### 6. Advanced Configuration

#### Smooth Gate Movement (Optional)
Uncomment the smooth movement code in `openGate()` and `closeGate()` functions for gradual movement:

```cpp
// In openGate() function
for (int angle = GATE_CLOSED_ANGLE; angle <= GATE_OPEN_ANGLE; angle += 5) {
  gateServo.write(angle);
  delay(50);
}
```

#### Timing Adjustments
- **CLOSE_DELAY**: Adjust auto-close timing (default: 3000ms)
- **SENSOR_DEBOUNCE**: Adjust sensor stability (default: 100ms)

### 7. Troubleshooting

#### Common Issues and Solutions

**ESP32 Not Detected**:
- Check USB cable connection
- Install ESP32 drivers if needed
- Try different USB port
- Hold BOOT button while connecting

**Upload Errors**:
- Check board and port selection
- Close Serial Monitor before uploading
- Try lower upload speed (921600 → 115200)
- Press BOOT button during upload if needed

**Compilation Errors**:
- **"ESP32Servo.h: No such file or directory"**:
  - Install ESP32Servo library via Tools → Manage Libraries
  - Search for "ESP32Servo by Kevin Harrington" and install
  - Restart Arduino IDE after installation
- **ESP32 board not found**:
  - Install ESP32 board package via Tools → Board → Boards Manager
  - Add ESP32 URL in File → Preferences → Additional Board Manager URLs

**Servo Not Moving**:
- Verify 5V power connection
- Check servo wire connections
- Test with simple servo sweep code
- Ensure servo isn't mechanically blocked

**IR Sensor Issues**:
- Check detection logic (HIGH vs LOW)
- Adjust sensitivity potentiometer
- Verify 5V power supply
- Test sensor with LED indicator

**Serial Monitor Shows No Output**:
- Check baud rate (should be 115200)
- Verify USB connection
- Check if correct port is selected

### 8. Performance Optimization

#### Power Considerations
- For battery operation, consider sleep modes
- Monitor current consumption
- Use external power supply for high-load applications

#### Response Time Optimization
- Reduce `SENSOR_DEBOUNCE` for faster response
- Adjust loop delay for balance between responsiveness and power

#### Reliability Improvements
- Add watchdog timer for system stability
- Implement error handling for sensor failures
- Consider backup power for critical applications

## Testing Checklist

Before final deployment, verify:
- [ ] All connections secure
- [ ] IR sensor detects at desired range
- [ ] Servo opens gate fully
- [ ] Servo closes gate completely
- [ ] Auto-close timing appropriate
- [ ] No false triggers
- [ ] Serial output shows correct status
- [ ] System stable over extended operation

## Maintenance

### Regular Checks
- Clean IR sensor lens periodically
- Check all wire connections
- Verify servo operation smoothness
- Monitor power supply stability

### Troubleshooting Log
Keep a record of any issues and solutions for future reference.

## Safety Notes
⚠️ **Important Safety Considerations**:
- Always disconnect power when making wiring changes
- Test system thoroughly before permanent installation
- Ensure gate movement area is clear of obstacles
- Consider emergency stop mechanism for safety-critical applications
