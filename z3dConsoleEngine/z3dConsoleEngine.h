#pragma once

#pragma region PREFACE
/*
* Firstly, why am I developing this library, I literally don't know...
*
* Author: Mert ULAS <h.mert.ulas@gmail.com>
*/
#pragma endregion


#pragma region std_libs

#define _WIN32_WINNT 0x0500
#define _USE_MATH_DEFINES

#include <Windows.h>
#include <math.h>
#include <iostream>

#pragma endregion

#define _T(a)  L ## a

#pragma region globals

#define RAD (M_PI / 180)

extern HWND console;
extern HDC dc;
extern COLORREF COLOR;

struct ConsoleWindowSettings {
	short left;
	short top;
	short width;
	short height;
};

#pragma endregion

struct Player {
	float x = 0.0f;
	float y = 0.0f;
	float dirAngle = 0.0f;
};

#pragma region points

struct Point2D {
	float x = 0.0f;
	float y = 0.0f;
};

struct Point3D {
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

#pragma endregion


class z3dConsoleEngine
{
public:
	z3dConsoleEngine(ConsoleWindowSettings window);

	~z3dConsoleEngine();

	void SetTitleWindow(const char* title);

	void SetColor(uint8_t R, uint8_t G, uint8_t B);

	void ClearScreen(ConsoleWindowSettings window);
};


class Shapes2D
{
public:
	Shapes2D();

	static void Line(Point2D start, Point2D end);
	static void Circle(Point2D center, unsigned short radius);
};


class Rect
{
private:
	short left, top;
	unsigned short width, height;
public:
	Rect(short left, short top, unsigned short width, unsigned short height);

	void draw();
	void rotate(float deg);
	void translate(short shiftX, short shiftY);
	void shearX(float amount);
	void shearY(float amount);
};


class Triangle
{
private:
	Point2D top, left, right;
public:
	Triangle(Point2D top, Point2D left, Point2D right);

	void draw();
	void rotate(float deg);
	void translate(short shiftX, short shiftY);
	void shearX(float amount);
	void shearY(float amount);
};


class Math
{};