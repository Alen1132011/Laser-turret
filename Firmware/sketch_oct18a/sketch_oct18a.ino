#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

const char* ssid = "LaserTurret-AP";
const char* password = "password123";

WebServer server(80);

Servo panServo;
Servo tiltServo;

int panPin = 1;
int tiltPin = 2;
int laserPin = 3;

int panAngle = 90;
int tiltAngle = 90;
bool laserState = false;

const char HTML_PAGE[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Turret Control</title>
  <style>
    body { font-family: sans-serif; text-align: center; background: #121212; color: white; margin: 0; padding: 20px; }
    h1 { color: #00adb5; font-size: 20px; }
    .grid { display: grid; grid-template-columns: repeat(3, 80px); gap: 10px; justify-content: center; margin: 20px auto; }
    .btn { background: #393e46; color: #eee; border: none; padding: 20px; font-size: 20px; border-radius: 10px; cursor: pointer; }
    .btn:active { background: #00adb5; }
    .laser { background: #d9534f; grid-column: span 3; }
    .laser.on { background: #5cb85c; }
    .info { font-size: 16px; margin: 10px; color: #00adb5; }
  </style>
</head>
<body>
  <h1>Laser Turret</h1>
  <div class="info">Pan: <span id="pan">90</span> | Tilt: <span id="tilt">90</span></div>
  
  <div class="grid">
    <div></div>
    <button class="btn" onclick="send(0, 5)">▲</button>
    <div></div>
    <button class="btn" onclick="send(-5, 0)">◀</button>
    <button class="btn laser" id="lBtn" onclick="toggleLaser()">Laser OFF</button>
    <button class="btn" onclick="send(5, 0)">▶</button>
    <div></div>
    <button class="btn" onclick="send(0, -5)">▼</button>
    <div></div>
  </div>

  <script>
    let lOn = false;

    function send(p, t) {
      fetch('/move?pan=' + p + '&tilt=' + t)
        .then(res => res.json())
        .then(data => {
          document.getElementById('pan').innerText = data.pan;
          document.getElementById('tilt').innerText = data.tilt;
        });
    }

    function toggleLaser() {
      lOn = !lOn;
      fetch('/laser?state=' + (lOn ? 1 : 0))
        .then(res => res.text())
        .then(val => {
          let b = document.getElementById('lBtn');
          if (val == "1") {
            b.innerText = "Laser ON";
            b.classList.add("on");
          } else {
            b.innerText = "Laser OFF";
            b.classList.remove("on");
          }
        });
    }
  </script>
</body>
</html>
)rawliteral";

void handleRoot() {
  server.send(200, "text/html", HTML_PAGE);
}

void handleMove() {
  if (server.hasArg("pan") && server.hasArg("tilt")) {
    panAngle += server.arg("pan").toInt();
    tiltAngle += server.arg("tilt").toInt();

    panAngle = constrain(panAngle, 0, 180);
    tiltAngle = constrain(tiltAngle, 0, 180);

    panServo.write(panAngle);
    tiltServo.write(tiltAngle);

    String json = "{\"pan\":" + String(panAngle) + ",\"tilt\":" + String(tiltAngle) + "}";
    server.send(200, "application/json", json);
  } else {
    server.send(400, "text/plain", "OK");
  }
}

void handleLaser() {
  if (server.hasArg("state")) {
    laserState = (server.arg("state").toInt() == 1);
    digitalWrite(laserPin, laserState ? HIGH : LOW);
    server.send(200, "text/plain", String(laserState ? 1 : 0));
  } else {
    server.send(400, "text/plain", "OK");
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(laserPin, OUTPUT);
  digitalWrite(laserPin, LOW);

  panServo.attach(panPin, 500, 2400);
  tiltServo.attach(tiltPin, 500, 2400);
  
  panServo.write(panAngle);
  tiltServo.write(tiltAngle);

  WiFi.softAP(ssid, password);

  server.on("/", handleRoot);
  server.on("/move", handleMove);
  server.on("/laser", handleLaser);
  server.begin();
}

void loop() {
  server.handleClient();
}