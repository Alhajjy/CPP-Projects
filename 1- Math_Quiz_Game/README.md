# Math Quiz Challenge – A C++ Console-Based Educational Game

## Overview

**Math Quiz Challenge** is a dynamic, console-based arithmetic quiz application developed in **C++**, designed to test and improve users' mental math skills across varying difficulty levels and operation types. The program offers a structured, interactive experience that adapts to user preferences—making it ideal for learners, educators, or anyone looking to sharpen their calculation speed and accuracy.

Built with clean architecture, strong data modeling, and user-centric design principles, this project demonstrates solid command of core C++ concepts including **enums**, **structs**, **modular functions**, **randomization**, and **input validation**.

---

## Key Features

- **Customizable Difficulty Levels**  
  Choose from **Easy (1–10)**, **Medium (10–50)**, **Hard (50–100)**, or a **Mixed** mode that randomly selects levels per question.

- **Flexible Operation Types**  
  Practice **Addition (+)**, **Subtraction (–)**, **Multiplication (×)**, **Division (÷)**, or enable **Mixed Operations** for a randomized challenge.

- **Adaptive Question Generation**  
  Each question is dynamically generated based on selected settings using a robust randomization engine seeded with system time for true variability.

- **Real-Time Feedback & Scoring**  
  After each answer, the user receives immediate feedback—showing whether their response was correct and displaying the right answer if needed.

- **Comprehensive Results Summary**  
  At the end of each quiz, the application presents a detailed performance report:
  - Total questions
  - Difficulty level & operation type used
  - Number of correct vs. incorrect answers
  - Pass/Fail status (pass = correct ≥ incorrect)

- **Replayability**  
  Users can restart the quiz instantly with new settings or the same configuration—perfect for iterative learning.

---

## Technical Highlights

- **Structured Data Design**:  
  Uses `struct`s (`stQuestion`, `stQuez`) to encapsulate quiz state and question metadata cleanly.

- **Modular Architecture**:  
  Every responsibility is isolated into single-purpose functions (e.g., `CreateQuestion`, `CurrectTheQuestionAnswer`, `PrintQuezResults`), enhancing readability and maintainability.

- **Input Safety & Validation**:  
  Robust input handling with loops to ensure only valid choices are accepted (e.g., level selection between 1–4).

- **Extensible Logic**:  
  Easy to extend—adding new operations, levels, or features (e.g., timers, score history) requires minimal refactoring.

- **Cross-Platform Compatibility**:  
  Written in standard C++ with only `<iostream>` and `<cstdlib>`, ensuring portability across compilers and operating systems (note: `system("cls")` is Windows-specific but easily replaceable).

---

## Why This Project Stands Out

This isn’t just another calculator—it’s a **thoughtfully engineered educational tool** that balances technical rigor with user experience. It reflects a deep understanding of:

- Problem decomposition
- State management in procedural programming
- User interaction design in constrained environments (console)
- Performance feedback loops for learning

Whether used in classrooms, tutoring apps, or as a foundation for a larger learning platform, **Math Quiz Challenge** proves that even simple console applications can deliver powerful, engaging value when built with care and precision.

---

## How to Run

1. Compile with any standard C++ compiler (e.g., `g++ main.cpp -o quiz`)
2. Execute the binary
3. Follow on-screen prompts to configure and play!

> **Note**: On non-Windows systems, replace `system("cls")` with `system("clear")` for screen clearing.

---

## Author

Developed with passion for clean code and effective learning tools.  
*Open to collaboration, feedback, and opportunities to build impactful software.*
