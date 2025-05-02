# 🎮 Tic-Tac-Toe Game (C++ with Raylib)

A simple **Tic-Tac-Toe** game built in C++ using the **Raylib** library for graphics.

<img src="Screenshot%202025-05-02%20222145.png" width="400">

## 🚀 Features
- **2-player mode** (X and O)
- **Mouse-click controls**
- **Win/draw detection**
- **Press `R` to reset** the game

## 🔧 Installation & Running
### **Windows (MinGW)**
1. Install **Raylib** for MinGW: [Download Here](https://www.raylib.com)
2. Compile & run:
   ```powershell
   g++ tictactoe.cpp -o tictactoe.exe -I"path\to\raylib\raylib\src" -L"path\to\raylib\raylib\src" -lraylib -lopengl32 -lgdi32 -lwinmm
   .\tictactoe.exe
