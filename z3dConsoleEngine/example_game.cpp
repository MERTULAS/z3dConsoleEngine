#include "z3dConsoleEngine.h"

ConsoleWindowSettings window = { 100, 50, 1024, 768 };

z3dConsoleEngine zed(window);

int game(Rect& rect, Triangle& triangle);

int main(int argc, char* argv[]) {
    zed.SetColor(255, 0, 0);

    Rect rect(150, 200, 150, 80);
    Triangle triangle({ 500, 500 }, { 450, 550 }, { 550, 550 });

    while (game(rect, triangle));

    ReleaseDC(console, dc);
    std::cin.ignore();
    return 0;
}

int game(Rect& rect, Triangle& triangle) {
    zed.ClearScreen(window);

    if (GetKeyState('A') & 0x8000)
    {
        rect.translate(-10, 0);
    }

    if (GetKeyState('D') & 0x8000)
    {
        rect.translate(10, 0);
    }

    if (GetKeyState('W') & 0x8000)
    {
        rect.translate(0, -10);
    }

    if (GetKeyState('S') & 0x8000)
    {
        rect.translate(0, 10);
    }

    if (GetKeyState(VK_ESCAPE) & 0x8000)
    {
        std::cout << "Canceled the game!" << std::endl;
        return 0;
    }

    Shapes2D::Circle({ 250, 350 }, 100);
    Shapes2D::Line({ 300, 400 }, { 250, 10 });

    rect.draw();
    triangle.draw();

    return 1;
}

