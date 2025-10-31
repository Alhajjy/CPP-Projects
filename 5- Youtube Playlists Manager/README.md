# Playlist Manager – A Professional C++ Console Application

## Overview

**Playlist Manager** is a robust, file-based console application written in **modern C++** that enables users to efficiently manage educational or entertainment playlists. Designed with clean architecture principles and user experience in mind, this tool supports full **CRUD operations** (Create, Read, Update, Delete) on playlist records stored persistently in a plain-text file.

Built for developers who value simplicity, maintainability, and performance, this project demonstrates strong command of core C++ features—including file I/O, structured data handling, dynamic containers (`std::vector`), string manipulation, and modular design—making it an excellent showcase of professional-grade systems programming.

---

## 🚀 Key Features

- **Persistent Data Storage**: All playlist records are saved to and loaded from `Playlists.txt` using a custom delimiter (`_~_`) for reliable serialization.
- **Full CRUD Operations**:
  - **Create**: Add new playlists with title, topic, description, video count, URL, channel name, and year.
  - **Read**: View all playlists in a well-formatted table or search by unique playlist number.
  - **Update**: Modify any existing playlist after confirmation.
  - **Delete**: Remove playlists securely with user verification.
- **User-Friendly Interface**:
  - Color-coded menu system using ANSI escape codes for enhanced readability.
  - Input validation and clear prompts guide the user through each operation.
  - Automatic text truncation ensures tabular output remains aligned and readable.
- **Robust Data Handling**:
  - Safe parsing of delimited lines into structured records (`stPlaylist`).
  - Graceful handling of missing or malformed fields during file loading.
  - Use of `cin.ignore()` and `getline()` to prevent input stream issues.

---

## 🛠️ Technical Highlights

- **Language**: C++17 (standard-compliant)
- **Standard Library Usage**:
  - `<vector>` for dynamic storage
  - `<fstream>` for file persistence
  - `<iomanip>` for formatted console output
  - `<string>` and custom parsing logic for data serialization
- **Architecture**:
  - Modular function decomposition (separation of concerns)
  - Single-responsibility functions (e.g., `LoaditemsDataFromFile`, `PrintRecordInLine`)
  - Global constants for configuration (e.g., filename, separator)
- **Error Resilience**:
  - File existence checks before read/write
  - Input sanitization and fallback values (e.g., `-1` for invalid integers)
  - Confirmation prompts before destructive actions

---

## 📁 File Structure

```
PlaylistManager/
├── main.cpp          # Entire application source (self-contained)
├── Playlists.txt     # Auto-generated data file (stores all playlists)
└── README.md         # This documentation
```

> 💡 **Note**: The application is intentionally self-contained in a single `.cpp` file for portability and ease of compilation—ideal for environments without complex build systems.

---

## ▶️ How to Run

1. **Compile** (using any standard C++ compiler):
   ```bash
   g++ -std=c++17 -O2 -Wall main.cpp -o PlaylistManager
   ```

2. **Execute**:
   ```bash
   ./PlaylistManager        # Linux/macOS
   PlaylistManager.exe      # Windows
   ```

3. The program will auto-create `Playlists.txt` if it doesn’t exist and load existing data on startup.

---

## 💼 Why This Project Stands Out

This isn’t just another student exercise—it’s a **production-minded utility** built with discipline:

- **Professional Code Quality**: Consistent naming, clear comments, and logical flow.
- **User-Centric Design**: Thoughtful UX decisions (colors, spacing, confirmations).
- **Scalable Foundation**: Easy to extend (e.g., add filtering by year, export to CSV, or integrate with a database).
- **Real-World Relevance**: Demonstrates how to build reliable, stateful CLI tools—common in DevOps, embedded systems, and backend utilities.

Companies seeking engineers who write **clean, functional, and maintainable C++ code** will recognize the care and craftsmanship embedded in every line.

---

## 📬 Author

Developed with precision by **[Alhajjy](https://github.com/Alhajjy)**  
*Building efficient systems, one line of C++ at a time.*

---

> ✨ **Ready to bring structure to your digital content? Let Playlist Manager organize it—all from the power of the terminal.**
