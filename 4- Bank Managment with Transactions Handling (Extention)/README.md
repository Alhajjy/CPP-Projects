# Bank Client Management System

A robust, console-based **Bank Client Management System** built in C++ that enables seamless handling of client records, account operations, and financial transactions — all while demonstrating clean architecture, defensive programming, and user-centric design.

---

## 🚀 Overview

This application simulates a simplified banking backend where administrators can:
- **View** all client records in a structured table
- **Add**, **update**, or **delete** client accounts
- **Search** for clients by unique account number
- Perform core **banking transactions**: deposit, withdraw, and view total system balance

Data is persistently stored in a plain-text file (`file.txt`) using a custom delimiter (`__||__`), ensuring portability and ease of maintenance without external dependencies.

---

## ✨ Key Features

### 🔒 Secure & Unique Account Handling
- Enforces **unique account numbers** during client creation
- Prevents accidental duplication with real-time validation

### 💳 Full Transaction Support
- **Deposit** and **withdraw** funds with confirmation prompts
- View **total balance** across all accounts
- Real-time balance updates with visual feedback

### 📊 Intuitive Console Interface
- Clean, tabular display of client data using `std::setw`
- Context-aware menus with clear navigation
- Input sanitization and error recovery (e.g., retry on invalid search)

### 🛠️ Maintainable & Extensible Design
- Modular functions with single responsibilities
- Strong separation between **data logic**, **file I/O**, and **user interaction**
- Enum-based menu systems for readability and scalability

### 💾 Reliable Data Persistence
- All operations sync immediately to `file.txt`
- Safe file writing with newline handling and overwrite protection
- Robust parsing with delimiter-based record splitting

---

## 🧱 Technical Highlights

- **Language**: C++11 (Standard Library only — no external frameworks)
- **Data Structures**: `std::vector`, `std::string`, custom `struct`
- **File I/O**: `fstream` with error checking
- **Memory Safety**: Stack-allocated objects, no raw pointers
- **User Experience**: Input validation, confirmation dialogs, pause prompts

---

## 📁 File Structure

```
project/
├── main.cpp          # Entire application source
└── file.txt          # Persistent storage (auto-created if missing)
```

> No build tools or dependencies required — compiles with any standard C++ compiler (e.g., `g++ main.cpp -o bank`).

---

## 💡 Why This Stands Out

This project goes beyond a basic CRUD app by emphasizing:
- **User trust** through confirmation steps and clear feedback
- **Data integrity** via validation and atomic file updates
- **Professional polish** in formatting, error handling, and flow control

It reflects disciplined software engineering principles — ideal for real-world embedded or utility applications where reliability and simplicity are paramount.

---

## 📬 Ready for Integration

Whether as a learning showcase or a foundation for a larger system, this codebase is:
- **Well-commented** and logically organized
- **Easy to extend** (e.g., add PIN validation, transaction logs, or encryption)
- **Production-ready** for controlled environments

---

**Developed with precision. Built to last.**  
*— A testament to clean, functional C++ craftsmanship.*
