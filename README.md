# Mini_Factory — Distributed Automated Production System

https://github.com/user-attachments/assets/67df37b4-28ec-424f-895c-59ac1bf8529d

## About the Project
Developed during an intensive **4-week period by a team of 4**, this 5th-semester technical college project consists of designing and implementing a distributed, automated mini-factory. 

The system orchestrates the transport, weighing, and sorting of blocks based on their mass by coordinating heterogeneous hardware subsystems (8051, STM32, and ESP32 microcontrollers) via a CAN bus network and a Wi-Fi wireless link.

---

## System Architecture & Workflow
1. **Central Processing Unit (DS89C450):** The core orchestrator of the factory, executing the global sequential automation logic and supervising the overall automatic sorting cycle.
2. **Automated Guided Vehicle (AGV - ESP32):** A line-following robot that receives blocks at the starting station, navigates the factory floor autonomously, and delivers the cargo to the robotic arm. For maximum mobility, it communicates wirelessly with the factory network by connecting to a dedicated Wi-Fi access point.
3. **Sorting & Weighing Station (STM32F407):** A robotic arm picks up the block delivered by the vehicle, places it onto a scale to acquire its exact weight, and then sorts and stacks it into the appropriate bay according to configured mass thresholds.
4. **Communication Gateway (STM32F407):** Acts as the central nervous system for wired communications. The STM32 manages arbitration, routing, and packet formatting on the **CAN Bus**, ensuring deterministic and robust data exchanges between all industrial modules.
5. **Main Command Center (C# HMI):** A centralized software interface allowing the operator to remotely control the factory, track the automation cycle in real-time, and monitor peripheral status.

---

## Repository Structure
The codebase is structured according to the distributed hardware architecture of the project:
* `/Command_center`: Source code for the Human-Machine Interface (HMI) developed in C#.
* `/Mini_Factory`: Core automation logic and global sequence management firmware (DS89C450 microcontroller).
* `/Robotic_arm_and_scale`: Embedded firmware for robotic arm kinematics and scale data acquisition (STM32F407).
* `/STM_CAN_control_center`: Packet management, routing, and multiplexing code for the CAN bus network (STM32F407).
* `/Vehicle_main`: Embedded firmware for the autonomous line-following AGV and wireless Wi-Fi stack management (ESP32).

---

## Team & Task Distribution

* [**Shad Boudreault**](https://github.com/ShadossOw)
  * Architected the network layer: defined CAN frame structures, allocated identifier tokens (IDs), and managed bus priorities.
  * Integrated and validated the network layer protocol across all distinct hardware modules.

* [**Harold Malbrouck**](https://github.com/darkyden)
  * Programmed the kinematics and motion control of the sorting robotic arm.
  * Designed and developed the main Command Center graphical user interface in C#.
  * Handled the software integration combining the weighing scale data with the robotic arm maneuvers.

* **MapiMorin**
  * Developed the entire embedded software stack for the autonomous AGV (line-following loop and Wi-Fi network sockets on ESP32).

* [**Alexandre Dionne**](https://github.com/Alexou1209)
  * Developed the complete finite-state machine (FSM) and global automation sequence for the factory layout (DS89C450).
  * Designed, calibrated, and programmed the data acquisition firmware for the sorting scale.
---

## Tech Stack & Tools
* **Languages:** C/C++ (Embedded Microcontrollers), C# (Control Desktop Interface).
* **Network Protocols:** CAN Bus (Controller Area Network), Wi-Fi (UDP sockets).
* **Hardware Platforms:** Maxim Integrated DS89C450 (Ultra-High-Performance 8051 Core), STMicroelectronics STM32F407 (ARM Cortex-M4), Espressif ESP32.
