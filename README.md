# 🚗 Simple IR Gate Controller

**An automated car entrance detection system using ESP32, IR sensor, and servo motor for smart gate control.**

<p align="center">
  <img src="https://img.shields.io/badge/Status-Active-green"/>
  <img src="https://img.shields.io/badge/Platform-ESP32-blue"/>
  <img src="https://img.shields.io/badge/License-MIT-yellow"/>
  <img src="https://img.shields.io/badge/Arduino-Compatible-teal"/>
</p>

## 📋 Overview

This project implements an intelligent gate control system that automatically opens when a vehicle is detected by an IR sensor and closes after a configurable delay. Perfect for driveways, parking garages, or any automated entrance system.

### ✨ Key Features

- 🔍 **Automatic Detection**: IR sensor detects vehicles/objects within 2-30cm range
- 🚪 **Smart Gate Control**: Servo-driven gate opens instantly upon detection
- ⏱️ **Auto-Close**: Configurable delay before automatic gate closure
- 🛡️ **Debounce Protection**: Prevents false triggers from sensor noise
- 📊 **Real-time Monitoring**: Serial output for system status and debugging
- ⚙️ **Configurable**: Easy adjustment of timings and gate angles
- 🔧 **Robust Design**: Handles power fluctuations and mechanical variations

## 🛠️ Hardware Components

| Component | Quantity | Purpose |
|-----------|----------|---------|
| ESP32 Development Board (38-pin) | 1 | Main microcontroller |
| IR Sensor Module | 1 | Vehicle/object detection |
| Tower Pro Micro Servo 9g (SG90) | 1 | Gate actuator |
| Jumper Wires | Several | Connections |
| Breadboard (optional) | 1 | Prototyping |

## 🔌 Wiring Diagram

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

## 🚀 Quick Start

### 1. Prerequisites
- Arduino IDE 2.0+
- ESP32 Board Package
- ESP32Servo Library

### 2. Installation
```bash
git clone https://github.com/K-B-R-S-W/Simple_IR_Gate_Controller.git
cd Simple_IR_Gate_Controller
```

### 3. Setup
1. Wire components according to the diagram above
2. Open `Main/Main.ino` in Arduino IDE
3. Select ESP32 board and appropriate COM port
4. Upload the code

### 4. Configuration
Adjust these parameters in the code as needed:
```cpp
#define GATE_CLOSED_ANGLE 0    // Gate closed position
#define GATE_OPEN_ANGLE 90     // Gate open position  
#define CLOSE_DELAY 3000       // Auto-close delay (ms)
#define SENSOR_DEBOUNCE 100    // Sensor debounce time (ms)
```

## 📖 Documentation

- **[Hardware Guide](HARDWARE_README.md)** - Detailed component specifications and wiring
- **[Setup Instructions](SETUP_README.md)** - Step-by-step installation and configuration
- **[Code Documentation](Main/Main.ino)** - Inline comments explaining functionality

## 🎯 How It Works

1. **Detection Phase**: IR sensor continuously monitors for objects
2. **Gate Opening**: When object detected, servo rotates to open position
3. **Monitoring**: System tracks detection status and timing
4. **Auto-Close**: After no detection for set period, gate closes automatically
5. **Status Reporting**: Real-time status updates via Serial Monitor

## ⚙️ Configuration Options

### Detection Settings
- **Sensitivity**: Adjust IR sensor potentiometer for detection range
- **Debounce**: Modify `SENSOR_DEBOUNCE` for sensor stability
- **Detection Logic**: Invert detection logic if needed

### Gate Control
- **Angles**: Customize `GATE_CLOSED_ANGLE` and `GATE_OPEN_ANGLE`
- **Speed**: Enable smooth movement code for gradual operation
- **Timing**: Adjust `CLOSE_DELAY` for auto-close behavior

## 📊 Performance Specifications

| Parameter | Value | Unit |
|-----------|-------|------|
| Detection Range | 2-30 | cm |
| Response Time | <200 | ms |
| Auto-close Delay | 3 (configurable) | seconds |
| Operating Voltage | 5 | V |
| Current Consumption | 200-650 | mA |
| Gate Rotation | 0-90° (configurable) | degrees |

## 🔧 Troubleshooting

### Common Issues

**Servo Not Moving**
- Check 5V power connection
- Verify servo wire connections
- Ensure mechanical clearance

**False Detections**
- Adjust IR sensor sensitivity
- Check for ambient IR interference
- Verify sensor mounting position

**System Instability**
- Verify power supply capacity
- Check all ground connections
- Consider external power for servo

## 🛡️ Safety Considerations

- ⚠️ Ensure gate movement area is clear
- ⚠️ Test thoroughly before permanent installation  
- ⚠️ Consider emergency stop for safety-critical applications
- ⚠️ Use weatherproof enclosures for outdoor installations

## 🔮 Future Enhancements

- [ ] Web interface for remote monitoring
- [ ] WiFi connectivity for IoT integration
- [ ] Multiple sensor support
- [ ] RFID/Bluetooth access control
- [ ] Mobile app integration
- [ ] Data logging and analytics
- [ ] Voice control integration

## 📷 Demo

### 1. System

<img src="https://github.com/user-attachments/assets/9f303027-4f05-4997-ba2e-1cf6da88ee01" alt="1" width="350" height="450">

### 2. Gate Closed

<img src="https://github.com/user-attachments/assets/f9de3283-5a70-4ebf-a291-c932ac823b02" alt="1" width="350" height="250">

### 3. Gate Open

<img src="https://github.com/user-attachments/assets/19e6e481-d740-442f-ad71-f63ebed60e0b" alt="1" width="350" height="250">

### 4. Code Output

<img width="677" height="162" alt="Screenshot 2025-08-31 235854" src="https://github.com/user-attachments/assets/885cdfa9-ff5b-473a-b233-826863182b98" />


## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes, please open an issue first to discuss what you would like to change.

### Development Setup
1. Fork the repository
2. Create your feature branch (`git checkout -b `)
3. Commit your changes (`git commit -m `)
4. Push to the branch (`git push origin feature/`)
5. Open a Pull Request

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- ESP32 community for excellent documentation
- Arduino libraries contributors
- Open source hardware community

## 📚 Resources

- [ESP32 Official Documentation](https://docs.espressif.com/projects/esp32/en/latest/)
- [Arduino ESP32 Guide](https://github.com/espressif/arduino-esp32)
- [ESP32Servo Library](https://github.com/madhephaestus/ESP32Servo)

---

## 📮 Support

**📧 Email:** [k.b.ravindusankalpaac@gmail.com](mailto:k.b.ravindusankalpaac@gmail.com)  
**🐞 Bug Reports:** [GitHub Issues](https://github.com/K-B-R-S-W/Simple_IR_Gate_Controller/issues)  
**📚 Documentation:** [Project Wiki](https://github.com/K-B-R-S-W/Simple_IR_Gate_Controller/wiki)  
**💭 Discussions:** [GitHub Discussions](https://github.com/K-B-R-S-W/Simple_IR_Gate_Controller/discussions)  

---

## ⭐ Support This Project
If you find this project helpful, please give it a **⭐ star** on GitHub — it motivates me to keep improving! 🚀


