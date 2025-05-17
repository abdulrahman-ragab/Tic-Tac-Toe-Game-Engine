#include "raylib.h"
#include <iostream>
#include <map>
#include <utility>

class Board {
public:
    char boardGrid[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    void Board_Display();
    bool isFull();
    bool isWinner(char& winner);
    void reset();
};

void Board::Board_Display() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "[" << boardGrid[i][j] << "]";
        }
        std::cout << std::endl;
    }
}

bool Board::isFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (boardGrid[i][j] != 'X' && boardGrid[i][j] != 'O')
                return false;
        }
    }
    return true;
}

bool Board::isWinner(char& winner) {
    char symbols[] = {'X', 'O'};
    for (char symbol : symbols) {
        if ((boardGrid[0][0] == symbol && boardGrid[0][1] == symbol && boardGrid[0][2] == symbol) ||
            (boardGrid[1][0] == symbol && boardGrid[1][1] == symbol && boardGrid[1][2] == symbol) ||
            (boardGrid[2][0] == symbol && boardGrid[2][1] == symbol && boardGrid[2][2] == symbol) ||
            (boardGrid[0][0] == symbol && boardGrid[1][0] == symbol && boardGrid[2][0] == symbol) ||
            (boardGrid[0][1] == symbol && boardGrid[1][1] == symbol && boardGrid[2][1] == symbol) ||
            (boardGrid[0][2] == symbol && boardGrid[1][2] == symbol && boardGrid[2][2] == symbol) ||
            (boardGrid[0][0] == symbol && boardGrid[1][1] == symbol && boardGrid[2][2] == symbol) ||
            (boardGrid[2][0] == symbol && boardGrid[1][1] == symbol && boardGrid[0][2] == symbol)) {
                winner = symbol;
                return true;
        }
    }
    return false;
}

void Board::reset() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            boardGrid[i][j] = ' ';
}

int main() {
    const int screenWidth = 600;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Tic Tac Toe - Raylib");

    Board board;
    int currentPlayer = 0; // 0: X, 1: O
    bool gameOver = false;
    char winner = ' ';

    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !gameOver) {
            Vector2 mouse = GetMousePosition();
            int row = mouse.y / 200;
            int col = mouse.x / 200;

            if (board.boardGrid[row][col] != 'X' && board.boardGrid[row][col] != 'O') {
                board.boardGrid[row][col] = currentPlayer == 0 ? 'X' : 'O';
                if (board.isWinner(winner) || board.isFull())
                    gameOver = true;
                else
                    currentPlayer = 1 - currentPlayer;
            }
        }

        if (IsKeyPressed(KEY_R)) {
            board.reset();
            gameOver = false;
            currentPlayer = 0;
            winner = ' ';
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw grid lines
        for (int i = 1; i < 3; i++) {
            DrawLine(0, i * 200, screenWidth, i * 200, BLACK);
            DrawLine(i * 200, 0, i * 200, screenHeight, BLACK);
        }

        // Draw pieces
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int x = j * 200 + 100;
                int y = i * 200 + 100;
                if (board.boardGrid[i][j] == 'X')
                    DrawText("X", x - 20, y - 40, 80, BLUE);
                else if (board.boardGrid[i][j] == 'O')
                    DrawText("O", x - 20, y - 40, 80, RED);
            }
        }

        if (gameOver) {
            if (winner != ' ')
                DrawText(TextFormat("Player %c Wins! Press R to restart", winner), 50, 550, 20, GREEN);
            else
                DrawText("Draw! Press R to restart", 170, 550, 20, DARKGRAY);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}


/*g++ tic_tac_toe_GUI.cpp -o tictactoe.exe -I"C:\raylib\raylib\src" -L"C:\raylib\raylib\src" -lraylib -lopengl32 -lgdi32 -lwinmm*/
