
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

![Screenshot 2026-10-18 203529](https://halflife.hackclub-assets.com/hackclub-half-life/sessions/lRMIp8aqG3JiBzrQDmvJD3ywxhJGQtjw/10911c6fc90fd641bfeddca447af5613e97caa1102432db787c4ee6e9213cfcd.png)

![Screenshot 2026-10-18 203533](https://halflife.hackclub-assets.com/hackclub-half-life/sessions/lRMIp8aqG3JiBzrQDmvJD3ywxhJGQtjw/3e827c95f7d6e53c3f6c991bd48aef812940a5088cc5b1706294b7e848653a3d.png)

![Screenshot 2026-10-18 202913](https://halflife.hackclub-assets.com/hackclub-half-life/sessions/lRMIp8aqG3JiBzrQDmvJD3ywxhJGQtjw/17b112bc7e69b35bbb811f48b8ba2e0938613a6b15e6a5eb9dd077071c1d2d23.png)

![Screenshot 2026-10-18 202919](https://halflife.hackclub-assets.com/hackclub-half-life/sessions/lRMIp8aqG3JiBzrQDmvJD3ywxhJGQtjw/dc81507edaaf87f4c3c6c29b8697dce7418559601bd10d2a2ccac685bec0c385.png)

![Screenshot 2026-10-18 202926](https://halflife.hackclub-assets.com/hackclub-half-life/sessions/lRMIp8aqG3JiBzrQDmvJD3ywxhJGQtjw/c1bd079edafd943f4ff488b7bc4aad34887e9ca1c4e758512ae8d44388b031fb.png)<img width="1160" height="857" alt="Screenshot 2026-10-18 202919" src="https://github.com/user-attachments/assets/6e3153dc-a1bc-4f50-823f-e0384624e80b" />
<img width="1189" height="951" alt="Screenshot 2026-10-18 203529" src="https://github.com/user-attachments/assets/4a6f8299-10c5-4f23-b7ca-1957d525dba5" />
<img width="1312" height="1068" alt="Screenshot 2026-10-18 202926" src="https://github.com/user-attachments/assets/4cddcd48-5294-4b7f-873d-293733f074d9" />
<img width="1291" height="947" alt="Screenshot 2026-10-18 204023" src="https://github.com/user-attachments/assets/bbbbc359-6f71-4eb8-8cf1-dad2282f5d3a" />
<img width="1212" height="1066" alt="Screenshot 2026-10-18 203533" src="https://github.com/user-attachments/assets/6f5931eb-561b-4b71-93d7-d99bfa71a63b" />

