# 🎮 Tic-Tac-Toe Game (C++ with Raylib)

A simple **Tic-Tac-Toe** game built in C++ using the **Raylib** library for graphics.

![Tic-Tac-Toe Screenshot](screenshot.png) 

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
