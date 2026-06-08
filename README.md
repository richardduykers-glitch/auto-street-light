# Auto Street Light System

An automatic street lighting system developed using ESP32, LDR Sensor, RTC Module, and Relay Module. The system automatically controls street lights based on ambient light conditions and scheduled operating hours.

## Features

* Automatic street light control
* Ambient light detection using LDR
* Real-time scheduling using RTC module
* Energy-efficient operation
* ESP32-based control system

## Components Used

* ESP32
* LDR Sensor
* RTC Module (DS3231)
* Relay Module
* LED / Street Light Simulation

## System Architecture

### Block Diagram

![Block Diagram](block-diagram.svg)

### Wiring Diagram

![Wiring Diagram](wiring.jpg)

## System Workflow

1. Read ambient light level from the LDR sensor.
2. Read current time from the RTC module.
3. ESP32 processes sensor and time data.
4. Relay module controls the street light.
5. Street light turns ON or OFF automatically based on predefined conditions.

## Project Structure

```text
Auto-Street-Light
│
├── auto_street_light.ino
├── wiring.jpg
├── block-diagram.svg
└── README.md
```

## Future Improvements

* Remote monitoring via IoT platform
* Energy consumption tracking
* Weather-based automation
* Smart city integration

## Developer

Richard D'Angelo Duykers
IoT Engineer | Robotics & Educational Technology Developer
