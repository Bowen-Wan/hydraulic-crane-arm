# hydraulic-crane-arm
Arduino-controlled crane arm with syringe-hydraulic lift joint and string gripper.

# Hydraulic Popsicle-Stick Crane Arm

A popsicle-stick crane with a syringe-hydraulic lift joint and a string-actuated gripper controlled by an Arduino UNO. Built at the UBC Mechatronics Senior Camp, July 2026.

<img width="1184" height="896" alt="b1b03dd3-c12a-4e52-af1d-bc06f7482945" src="https://github.com/user-attachments/assets/cb4668f6-0c27-4f65-8c01-6df6eba2c5bf" />


## Overview

The crane has two independently controlled motions:

1. **Base rotation** — a stepper motor mounted on a popsicle-stick platform at the top of the tower rotates the main arm clockwise or counterclockwise.
2. **Arm lift** — a syringe fixed to the tower is connected by flexible tubing to a second syringe mounted at the arm's pivot joint. Pushing the plunger on the fixed syringe forces fluid through the tubing, extending the second syringe and lifting the arm. Releasing it lowers the arm back down.

A second, independent gripper mechanism sits at the end of the arm:

- Four popsicle-stick "fingers" are pulled closed by a length of string connected to a separate control syringe.
- A rubber band wrapped around the fingers holds them in the closed (relaxed) position by default.
- Pulling the string against the rubber band's tension opens the fingers to release or reposition an object.

## Controls

- **Button 1** — rotates the arm clockwise, lights LED 1
- **Button 2** — rotates the arm counterclockwise, lights LED 2
- The LEDs give a simple visual confirmation of which direction is active

## Hardware

| Component | Role |
|---|---|
| Arduino UNO | Main controller |
| Stepper motor | Base rotation of the arm |
| 4x syringes + flexible tubing | Hydraulic actuation of the lift joint |
| String + rubber band | Gripper open/close mechanism |
| 2x pushbuttons | Manual rotation control |
| 2x LEDs | Direction indicators |
| Popsicle sticks, hot glue, string | Structural frame |

## Code

`crane_control.ino` — reads the two buttons and drives the stepper motor clockwise/counterclockwise accordingly, with LED indicators for each direction.

## Notes

- Built as a hands-on introduction to mechanical actuation methods (hydraulic vs. motor-driven) and basic Arduino control logic.
- The hydraulic lift and the string-based gripper were both designed and assembled independently within the camp session — no kit or pre-built gripper was used.
- Photos show the build in its working camp setup.

## Media

<img width="4032" height="3024" alt="d8ede0e9-7ab0-448d-b3d1-767175427831" src="https://github.com/user-attachments/assets/1e125a1d-77e0-49d6-88e4-fca9fe6d0dda" />
<img width="5712" height="4284" alt="IMG_1659" src="https://github.com/user-attachments/assets/e527cb5f-0ce3-435c-b618-e6516fa5ac9a" />
