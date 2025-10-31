# Rock, Paper, Scissors – Console Game in C++

## Overview

This project is a clean, well-structured implementation of the classic **Rock, Paper, Scissors** game built entirely in **C++** using standard libraries. Designed with clarity, modularity, and user experience in mind, it demonstrates solid programming fundamentals, including:

- **Proper use of enums** for semantic clarity and type safety  
- **Modular function design** following the single-responsibility principle  
- **Input validation** to ensure robust user interaction  
- **Game state tracking** using a simple yet effective integer array  
- **Randomized computer decisions** with proper seeding  

The game supports multiple rounds, tracks wins/losses/draws in real time, and presents a polished summary at the end—making it both functional and engaging.

---

## Features

- 🎮 **Interactive Gameplay**: Users select their move (1–3) per round while the computer responds randomly.
- 🔁 **Multi-Round Support**: Play as many rounds as desired in a single session.
- 📊 **Comprehensive Results**: After each game, a detailed scoreboard shows:
  - Total rounds played  
  - Player wins  
  - Computer wins  
  - Draws  
  - Final winner declaration  
- ♻️ **Replay Option**: Easily restart a new match without relaunching the program.
- ✅ **Input Validation**: Prevents invalid entries (e.g., non-positive numbers or out-of-range choices).

---

## Technical Highlights

- **Enums for Readability**:  
  ```cpp
  enum enStuff { Stone = 1, Paper = 2, Scissor = 3 };
  enum enResult { Win = 1, Lose = -1, Draw = 0 };
  ```
  These improve code maintainability and reduce magic numbers.

- **State Management via Array**:  
  The `Info[4]` array efficiently tracks:
  - `[0]`: Total rounds  
  - `[1]`: Player wins  
  - `[2]`: Computer wins  
  - `[3]`: Draws  

- **Deterministic Randomness**:  
  Proper seeding with `srand((unsigned)time(NULL))` ensures varied gameplay across sessions.

- **User-Centric Design**: Clear prompts, visual separators, and intuitive flow enhance UX—even in a console environment.

---

## Why This Matters

This project reflects a disciplined approach to software development:
- **Clean architecture** with separated concerns (input, logic, output)
- **Defensive programming** through input validation
- **Scalable design**—easy to extend (e.g., add AI strategies, GUI, or network play)

It’s a testament to writing **production-ready C++ code** that balances correctness, readability, and user engagement—qualities essential in professional software engineering.

---

## How to Run

1. Compile with any standard C++ compiler (e.g., `g++`):
   ```bash
   g++ -o rps main.cpp
   ```
2. Execute:
   ```bash
   ./rps
   ```
3. Follow on-screen prompts to play!

---

> **Built with passion, precision, and a love for clean code.**  
> Ready to bring this same rigor to enterprise-grade applications.
