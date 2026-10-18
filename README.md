# Laser-turret
# Laser Turret

This is my two-axis (pan-tilt) laser turret controlled via an ESP32-C3 Wi-Fi web server. I built this for Hack Club to combine mechatronics with web programming, allowing everything to be controlled directly from a phone or computer.

This is currently a BETA version! The code and hardware are still being developed and tested, so the code is not fully finalized yet, but the core logic and controls are already working great.

### Features
* ESP32-C3 SuperMini as the main brain with built-in Wi-Fi
* Two SG90 servos for horizontal and vertical movement
* 5V laser diode module (KY-008 type with built-in resistor)
* Web interface with arrow buttons and a laser toggle switch, hosted on a Wi-Fi network created by the ESP32 itself

### How the Software Works
The ESP32 creates its own Access Point. Once you connect to the network and open the IP address in a browser, you get a clean control interface. Tapping the arrows sends asynchronous requests that move the servos step-by-step, while the laser button instantly toggles the diode state.

### Bill of Materials (BOM)

| Component | Quantity | Description |
| :--- | :--- | :--- |
| ESP32-C3 SuperMini | 1 | Microcontroller with Wi-Fi support |
| SG90 Micro Servo | 2 | Servos for Pan and Tilt movement |
| KY-008 Laser Module | 1 | 5V laser diode with built-in resistor |
| Jumper Wires | Multiple | For connecting components |
| USB-C Cable | 1 | For power supply and code uploading |

I plan to add more features soon and finalize the physical 3D enclosure. That is all for now!
