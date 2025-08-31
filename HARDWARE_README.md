# Hardware Documentation - IR Gate Controller

## Components Required

### 1. ESP32 Development Board
- **Model**: ESP32 (38-pin version)
- **Features**: 
  - Dual voltage rails (3.3V and 5V)
  - WiFi and Bluetooth capability
  - Multiple GPIO pins with PWM support
- **Power Requirements**: 5V via USB or external power supply

### 2. IR Sensor Module
- **Type**: IR Obstacle Avoidance Sensor
- **Detection Range**: 2-30cm (adjustable via potentiometer)
- **Output**: Digital signal (HIGH/LOW)
- **Operating Voltage**: 3.3V - 5V
- **Current Consumption**: ~20mA
- **Features**:
  - Onboard IR LED transmitter
  - IR photodiode receiver
  - LM393 comparator for digital output
  - Sensitivity adjustment potentiometer

### 3. Tower Pro Micro Servo 9g (SG90)
- **Type**: Micro servo motor
- **Operating Voltage**: 4.8V - 6V
- **Current Draw**: 
  - Idle: ~10mA
  - Operating: ~100-200mA
  - Stall: ~300-600mA
- **Torque**: 1.8kg/cm (4.8V)
- **Speed**: 0.1s/60° (4.8V)
- **Control Signal**: PWM (50Hz, 1-2ms pulse width)

## Pin Configuration

### ESP32 Pin Assignments
```
GPIO2  → IR Sensor OUT pin (Digital Input)
GPIO18 → Servo PWM pin (PWM Output)
5V     → Servo VCC (Red wire)
5V     → IR Sensor VCC 
GND    → Common ground for both components
```

### Detailed Wiring Connections

#### IR Sensor Module
| IR Sensor Pin | ESP32 Pin | Wire Color | Function |
|---------------|-----------|------------|----------|
| VCC           | 3.3V      | Red        | Power supply |
| GND           | GND       | Black      | Ground |
| OUT           | GPIO2     | Yellow/White | Digital signal output |

#### Tower Pro Micro Servo 9g
| Servo Wire | ESP32 Pin | Function |
|------------|-----------|----------|
| Red        | 5V        | Power supply |
| Black/Brown| GND       | Ground |
| Orange/Yellow | GPIO18 | PWM control signal |

## Circuit Diagram Description

```
ESP32                    IR Sensor Module
┌─────────────┐         ┌─────────────┐
│     3.3V    │────────→│    VCC      │
│     GND     │────────→│    GND      │
│     GPIO2   │←────────│    OUT      │
│             │         └─────────────┘
│             │
│             │         Tower Pro Servo
│             │         ┌─────────────┐
│     5V      │────────→│  Red Wire   │
│     GND     │────────→│ Black Wire  │
│     GPIO18  │────────→│Orange Wire  │
└─────────────┘         └─────────────┘
```

## Hardware Considerations

### Power Requirements
- **Total Current**: ~200-650mA (depending on servo load)
- **ESP32 5V Rail**: Can typically provide up to 500mA
- **Recommendation**: For reliable operation, consider external 5V power supply if using multiple servos or high-torque applications

### Mounting Considerations
1. **IR Sensor Placement**:
   - Mount at appropriate height for vehicle detection
   - Ensure clear line of sight
   - Protect from weather if used outdoors
   - Adjust sensitivity potentiometer for optimal range

2. **Servo Mounting**:
   - Secure mounting to prevent vibration
   - Ensure adequate torque for gate weight
   - Consider gear reduction for heavier gates
   - Protect servo from weather exposure

### Performance Specifications
- **Detection Range**: 2-30cm (adjustable)
- **Response Time**: <200ms from detection to gate movement
- **Gate Operation**: 0° to 90° rotation
- **Auto-close Delay**: 3 seconds (configurable in software)

## Troubleshooting Hardware Issues

### IR Sensor Issues
- **No Detection**: 
  - Check wiring connections
  - Adjust sensitivity potentiometer
  - Verify 5V power supply
  - Clean IR LED and photodiode

- **False Triggers**: 
  - Reduce sensitivity
  - Shield from ambient IR sources
  - Check for loose connections

### Servo Issues
- **No Movement**: 
  - Verify 5V power connection
  - Check PWM signal on GPIO18
  - Ensure servo isn't mechanically jammed

- **Jittery Movement**: 
  - Check power supply stability
  - Add capacitor across servo power lines
  - Ensure proper grounding

### ESP32 Issues
- **System Instability**: 
  - Check power supply capacity
  - Verify all ground connections
  - Consider external power for servo

## Safety Considerations
1. **Electrical Safety**:
   - Double-check all connections before powering on
   - Use appropriate wire gauges for current requirements
   - Ensure proper grounding

2. **Mechanical Safety**:
   - Test gate movement area is clear
   - Implement emergency stop if needed
   - Consider soft-start for servo movement

3. **Environmental Protection**:
   - Use weatherproof enclosures for outdoor installations
   - Protect connections from moisture
   - Consider temperature operating ranges

## Recommended Tools
- Soldering iron and solder
- Wire strippers
- Multimeter for testing
- Breadboard for prototyping
- Jumper wires (male-to-male, male-to-female)
- Screwdriver set for mounting
