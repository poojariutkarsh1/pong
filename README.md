# 🏓 Arduino OLED Pong

A classic Pong game built on Arduino using a 128×64 OLED display, push buttons, and a buzzer. This project was created as a learning exercise in embedded systems, game logic, collision detection, state management, and hardware interfacing.

The game features:

- Player-controlled paddle
- AI-controlled opponent
- Ball physics and collision detection
- Score tracking
- Win/Loss screens
- Sound effects using a buzzer
- Modular testing sketches for individual components

---

## 📸 Features

### Gameplay

- Control the left paddle using two buttons.
- Compete against a simple AI paddle.
- First player to reach **3 points** wins.
- Ball bounces off paddles and screen boundaries.

### Audio Feedback

- Paddle hit sound
- Wall bounce sound
- Scoring sounds
- Win melody
- Loss melody

### Game States

- Active gameplay
- Player victory screen
- CPU victory screen
- Restart system

---

## 🛠 Hardware Used

| Component | Quantity |
|------------|----------|
| Arduino Uno/Nano | 1 |
| SSD1306 OLED Display (128×64, I2C) | 1 |
| Push Buttons | 2 |
| Buzzer | 1 |
| Breadboard & Jumper Wires | As needed |

---

## 🔌 Wiring

### OLED Display

| OLED | Arduino |
|--------|----------|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

### Buttons

| Button | Arduino Pin |
|---------|-------------|
| UP | D2 |
| DOWN | D3 |

Buttons use `INPUT_PULLUP`, so connect the other side of each button to **GND**.

### Buzzer

| Buzzer | Arduino Pin |
|---------|-------------|
| Positive | D8 |
| Negative | GND |

---

## 🎮 Controls

| Action | Button |
|----------|---------|
| Move Up | D2 |
| Move Down | D3 |
| Restart After Game Over | D2 |

---

## 📚 Concepts Practiced

This project helped explore:

- OLED graphics rendering
- Real-time game loops
- Collision detection
- State machines
- Basic AI behavior
- Sound generation with `tone()`
- Embedded debugging and testing
- Hardware-software integration

---

## 📂 Repository Structure

```text
Pong/
│
├── Pong.ino
│
├── oled_test/
│   ├── ball_collision.ino
│   ├── inputpaddle_with_ball.ino
│   ├── oled_screensaver_collision.ino
│   ├── oled_test.ino
│   ├── paddle-input.ino
│   └── twoface.ino
│
└── README.md
```

### Development Test Sketches

The `oled_test` folder contains standalone sketches created during development to test individual subsystems before integrating them into the final game.

| File | Purpose |
|--------|----------|
| `oled_test.ino` | Initial OLED display verification |
| `paddle-input.ino` | Testing button-controlled paddle movement |
| `ball_collision.ino` | Verifying collision detection logic |
| `inputpaddle_with_ball.ino` | Testing paddle movement alongside ball physics |
| `oled_screensaver_collision.ino` | Experimenting with ball movement and boundary collisions |
| `twoface.ino` | OLED rendering experiments and display testing |

Developing and validating components independently before integration helped simplify debugging and ensured each subsystem functioned correctly before being combined into the final game.

---

## 📦 Libraries Required

Install the following libraries through the Arduino Library Manager:

```text
Adafruit GFX Library
Adafruit SSD1306 Library
```

Also used:

```cpp
#include <Wire.h>
```

---

## 🚀 Future Improvements

Potential upgrades for future versions:

- Adjustable difficulty levels
- Dynamic ball speed increase
- Improved paddle bounce physics
- Main menu screen
- Pause functionality
- EEPROM high-score storage
- Two-player mode
- Animated startup screen
- Sound settings menu

---

## 🎯 Learning Outcomes

This project provided hands-on experience with:

- Embedded systems programming
- Real-time game development
- Display interfacing
- User input handling
- Collision detection
- State management
- Audio feedback systems
- Structured testing and debugging workflows

Although Pong is a simple game, it combines many core concepts that appear in larger embedded and robotics projects.

---

## 👨‍💻 Author

**Utkarsh Poojari**

Built as part of an ongoing embedded systems and robotics learning journey involving Arduino, ESP32, sensors, control systems, and low-level programming.

---

## 🏆 Version

**v1.0 — Fully Playable OLED Pong with AI Opponent and Sound Effects**
