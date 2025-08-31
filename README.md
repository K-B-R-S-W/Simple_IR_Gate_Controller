# 🚗 Simple IR Gate Controller

An automated car entrance detection system using ESP32, IR sensor, and servo motor for smart gate control.

![Project Status](https://img.shields.io/badge/Status-Active-green)
![Platform](https://img.shields.io/badge/Platform-ESP32-blue)
![License](https://img.shields.io/badge/License-MIT-yellow)
![Arduino](https://img.shields.io/badge/Arduino-Compatible-teal)

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
git clone https://github.com/yourusername/Simple_IR_Gate_Controller.git
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

*Add photos/videos of your working system here*

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes, please open an issue first to discuss what you would like to change.

### Development Setup
1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
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

⭐ **Star this repository if you found it helpful!**

## 📞 Support

If you encounter any issues or have questions:
1. Check the [Setup Guide](SETUP_README.md)
2. Review [Hardware Documentation](HARDWARE_README.md)
3. Open an [Issue](https://github.com/yourusername/Simple_IR_Gate_Controller/issues)
4. Join our community discussions

---
*Built with ❤️ for the maker community*
