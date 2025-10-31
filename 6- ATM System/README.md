# Bank ATM Console Application

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Console Application](https://img.shields.io/badge/Console_Application-000000?style=for-the-badge)
![File-Based Storage](https://img.shields.io/badge/File_Based_Storage-339933?style=for-the-badge)

A professional, secure, and user-friendly **ATM simulation system** built entirely in **C++**, designed to demonstrate robust software engineering principles, clean architecture, and real-world banking operations—all within a command-line interface.

---

## 🚀 Overview

This project simulates a fully functional **Automated Teller Machine (ATM)** system that allows authenticated users to:

- **Log in** securely using account number and PIN
- **Check account balance**
- **Withdraw funds** (custom or quick options)
- **Deposit funds**
- **Log out** safely

All client data is persisted in a structured text file (`clients.txt`) using a custom delimiter-based format, ensuring data integrity and portability without external dependencies.

---

## 🏗️ Architecture & Design Principles

- **Modular Design**: Code is cleanly separated into logical components:
  - `global.h` – Shared constants and data structures
  - `inputLib.h` – Input validation and utility functions
  - `most_used.h` – Core business logic, file I/O, and data transformation
  - `operations.h` – Banking transaction handlers
  - `main.cpp` – Application flow and user interaction

- **Encapsulation**: Each namespace (`Inputs`, `MostUsed`, `Operations`, `GlobalVars`) encapsulates related functionality, promoting maintainability and readability.

- **Data Persistence**: Uses plain-text file storage with a custom `__||__` delimiter, enabling easy debugging and manual inspection while maintaining structure.

- **User-Centric UX**: Clear menus, input validation, confirmation prompts, and formatted output ensure a smooth and intuitive user experience—even in a terminal environment.

---

## 🔐 Security Considerations

- **Authentication**: Users must provide a valid **account number** and **PIN** to access services.
- **Session Management**: The `CurrentClient` global variable tracks the authenticated user throughout the session.
- **Input Validation**: All numeric inputs are validated to be positive; menu selections are range-checked.

> *Note: In a production environment, PINs should be hashed and stored securely. This educational implementation uses plaintext for simplicity.*

---

## 💡 Key Features

| Feature | Description |
|--------|-------------|
| **Quick Withdraw** | One-click withdrawal of common amounts (5, 10, 50, ..., 1000) |
| **Custom Withdraw/Deposit** | Flexible amount entry with validation |
| **Balance Inquiry** | Instant display of current account balance |
| **File-Based Storage** | No database required—data saved in `clients.txt` |
| **Reusable Components** | Functions like `SplitString`, `ConvertLineToRecord`, and `SaveVectorDataToFile` are highly reusable |

---

## 📁 File Format (`clients.txt`)

Each line represents one client in the following format:

```
AccountNumber__||__PinCode__||__Name__||__Phone__||__AccountBalance
```

Example:
```
A12345__||__1234__||__Ahmad Alhajj__||__+963912345678__||__2500
```

This human-readable format simplifies testing, debugging, and data migration.

---

## ▶️ How to Run

1. Compile with a C++17-compliant compiler:
   ```bash
   g++ -std=c++17 main.cpp -o atm
   ```
2. Ensure `clients.txt` exists in the working directory (or the app will start with an empty client list).
3. Run the executable:
   ```bash
   ./atm
   ```

---

## 🛠️ Future Enhancements (Roadmap)

- Add **transaction history logging**
- Implement **PIN change** functionality
- Introduce **multi-user concurrency** (file locking)
- Migrate to **SQLite** or **SQL Server** for enterprise-grade persistence
- Add **unit tests** using Google Test

---

## 👨‍💻 Developed By

**Ahmad Alhajj**  
GitHub: [@Alhajjy](https://github.com/Alhajjy)  
*Passionate C++ Developer | Clean Code Advocate | Problem Solver*

---

> This project reflects a deep understanding of **software structure**, **user experience**, and **real-world system constraints**—all delivered with professionalism and attention to detail.  

**Ready to bring this level of quality to your team?** Let’s connect. 💼
