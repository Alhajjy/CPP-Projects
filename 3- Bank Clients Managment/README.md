# Client Management System – C++ Console Application

## Overview

This **Client Management System** is a robust, file-based console application built in **C++** that enables efficient CRUD (Create, Read, Update, Delete) operations for managing client records. Designed with clean architecture principles, structured code organization, and user-friendly interaction, this project demonstrates strong foundational programming skills, attention to detail, and a commitment to maintainable software design.

The system persists data in a plain-text file (`file.txt`) using a custom delimiter (`__||__`), ensuring human-readable storage while supporting seamless data serialization and deserialization.

---

## ✨ Key Features

- **Full CRUD Operations**:  
  - **Create**: Add new clients with validation to prevent duplicate account numbers.  
  - **Read**: View all clients in a formatted table or search for a specific client by account number.  
  - **Update**: Modify existing client details after confirmation.  
  - **Delete**: Remove clients securely with user verification.

- **Data Persistence**:  
  All client records are stored in a structured text file, enabling data retention across sessions without requiring a database.

- **Input Validation & User Experience**:  
  - Prevents duplicate account numbers during creation.  
  - Confirms destructive actions (e.g., deletion, updates).  
  - Clear, intuitive prompts and formatted output for readability.  
  - Pause-and-continue flow for smooth console navigation.

- **Modular & Maintainable Code**:  
  Functions are logically grouped (data loading/saving, UI rendering, business logic), making the codebase easy to extend or refactor.

---

## 🛠️ Technical Highlights

- **Standard C++ Libraries**:  
  Leverages `<iostream>`, `<fstream>`, `<string>`, `<vector>`, and `<iomanip>` for I/O, file handling, dynamic storage, and formatted output.

- **Structured Data Handling**:  
  Uses a `stClient` struct to encapsulate client information, promoting data integrity and clarity.

- **File Format**:  
  Each record is stored as a single line in the format:  
  ```
  AccountNumber__||__PinCode__||__Name__||__Phone__||__AccountBalance
  ```

- **Error Resilience**:  
  Gracefully handles missing files and invalid inputs without crashing.

- **Cross-Platform Ready**:  
  Uses standard C++ with minimal system dependencies (only `system("cls")` for Windows; easily adaptable to Unix with `clear`).

---

## 💼 Why This Project Stands Out

This application goes beyond a basic assignment—it reflects **professional-grade thinking**:
- **User-Centric Design**: Every interaction is intentional, reducing user error and improving experience.
- **Scalable Architecture**: The separation of concerns (data, logic, UI) allows for easy enhancement (e.g., adding encryption, switching to JSON, or integrating a GUI).
- **Production-Ready Practices**: Input sanitization, confirmation prompts, and structured file I/O mirror real-world development standards.

Whether used as a banking prototype, a learning tool, or a foundation for a larger system, this project showcases **problem-solving ability, code craftsmanship, and attention to user needs**.

---

## 🚀 Getting Started

1. **Compile** (using any standard C++ compiler, e.g., g++):  
   ```bash
   g++ -o client_manager main.cpp
   ```

2. **Run**:  
   ```bash
   ./client_manager   # Linux/macOS
   client_manager.exe # Windows
   ```

3. **Data File**:  
   The program automatically creates/reads from `file.txt` in the same directory.

> **Note**: On non-Windows systems, replace `system("cls")` with `system("clear")` for screen clearing.

---

## 📬 Let’s Connect

This project is a testament to clean, functional, and thoughtful software development. I’m passionate about building reliable systems that solve real problems—and I’d love to bring that same dedication to your team.

**Ready to discuss how I can contribute?** Let’s talk!
