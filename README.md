# temperature-monitoring-system
Embedded system for automatic temperature control using ESP8266

Digital Temperature Monitoring and Fan Control System

Overview

This project is an embedded system that monitors environmental temperature and automatically activates a cooling fan when a threshold is exceeded.

Features

- Real-time temperature and humidity monitoring using DHT11 sensor
- Automatic fan activation at 33°C threshold
- LCD display for live data output
- Microcontroller-based control using ESP8266

Technologies Used

- ESP8266 Microcontroller
- C++
- DHT11 Sensor
- I2C LCD Display
- Transistor Switching Circuit

System Design

The system follows a closed-loop structure:
Sensor → Microcontroller → Decision Logic → Actuator (Fan)

How It Works

The ESP8266 reads temperature data from the DHT11 sensor.
If temperature ≥ 33°C, the system activates a fan using a transistor switch.
Otherwise, the fan remains off.

Challenges & Improvements

- Observed voltage drop due to emitter-follower transistor configuration
- Proposed using low-side switching for improved performance

Future Improvements

- Add IoT dashboard using ESP8266 Wi-Fi
- Implement hysteresis control
- Improve power efficiency
