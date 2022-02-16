#include "z3dConsoleEngine.h"

HWND console = GetConsoleWindow();
HDC dc = GetDC(console);
COLORREF COLOR = RGB(255, 255, 255);

z3dConsoleEngine::z3dConsoleEngine(ConsoleWindowSettings window) {
	ShowScrollBar(console, SB_VERT, 0);

	MoveWindow(console, window.left, window.top, window.width, window.height, TRUE);

	SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

z3dConsoleEngine::~z3dConsoleEngine() {
	// coming soon
}

void z3dConsoleEngine::SetTitleWindow(const char* title) {
	SetConsoleTitle(TEXT("TITLE")); // FIX THIS !!!
}

void z3dConsoleEngine::SetColor(uint8_t R, uint8_t G, uint8_t B) {
	COLOR = RGB(R, G, B);
}

void z3dConsoleEngine::ClearScreen(ConsoleWindowSettings window) {
	system("cls"); // Maybe this will get better
}



Shapes2D::Shapes2D() {
	// for the initialization, z3dEngine must called before. 
}

void Shapes2D::Line(Point2D start, Point2D end) {
	float difX = end.x - start.x;
	float difY = end.y - start.y;

	float step = abs(abs(difX) > abs(difY) ? difX : difY);

	float incX = difX / step;
	float incY = difY / step;

	for (short i = 0; i < step; i++) {
		SetPixel(dc, static_cast<int>(start.x), static_cast<int>(start.y), COLOR);
		start.x += incX;
		start.y += incY;
	}
}

void Shapes2D::Circle(Point2D center, unsigned short radius) {
	for (short angle = 0; angle < 360; angle++) {
		SetPixel(dc,
			static_cast<int>(center.x + radius * cos(angle * RAD)),
			static_cast<int>(center.y + radius * sin(angle * RAD)),
			COLOR);
	}
}



Rect::Rect(short left, short top, unsigned short width, unsigned short height) {
	this->left = left;
	this->top = top;
	this->width = width;
	this->height = height;
}

void Rect::draw() {
	Shapes2D::Line(
		{ static_cast<float>(this->left), static_cast<float>(this->top) },
		{ static_cast<float>(this->left + this->width), static_cast<float>(this->top) }
	);

	Shapes2D::Line(
		{ static_cast<float>(this->left + this->width), static_cast<float>(this->top) },
		{ static_cast<float>(this->left + this->width), static_cast<float>(this->top + this->height) }
	);

	Shapes2D::Line(
		{ static_cast<float>(this->left + this->width), static_cast<float>(this->top + this->height) },
		{ static_cast<float>(this->left), static_cast<float>(this->top + this->height) }
	);

	Shapes2D::Line(
		{ static_cast<float>(this->left), static_cast<float>(this->top + this->height) },
		{ static_cast<float>(this->left), static_cast<float>(this->top) }
	);
}

void Rect::translate(short shiftX, short shiftY) {
	this->top += shiftY;
	this->left += shiftX;
}



Triangle::Triangle(Point2D top, Point2D left, Point2D right) {
	this->top = top;
	this->left = left;
	this->right = right;
}

void Triangle::draw() {
	Shapes2D::Line(
		this->top,
		this->left
	);

	Shapes2D::Line(
		this->left,
		this->right
	);

	Shapes2D::Line(
		this->right,
		this->top
	);

}

void Triangle::translate(short shiftX, short shiftY) {
	this->top.y += shiftY;
	this->left.y += shiftY;
	this->right.y += shiftY;

	this->top.x += shiftX;
	this->left.x += shiftX;
	this->right.x += shiftX;
}
