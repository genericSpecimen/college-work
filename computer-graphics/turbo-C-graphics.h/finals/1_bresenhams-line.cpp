#include <iostream>
#include <cstdio>
#include <graphics.h>
void bresenham_line_low(int x0, int y0, int x1, int y1, int color) {
	// slope between -1 and 1
	int dx = x1 - x0, dy = y1 - y0;
	int x = x0, y = y0;
	// putpixel(x, y, color);
	//
	std::cout << "dx = " << dx << ", dy = " << dy << "\n";
	int y_inc = 1;
	if(dy < 0) {
		std::cout << "gradient less than 0\n";
		// to cover gradients between 0 and -1,
		// we check whether y needs to increase or decrease
		y_inc = -1;
		dy = -dy;
	}
	
	int d = 2 * dy - dx;
	std::cout << "d = " << d << "\n";
	int deltaE = 2 * dy, deltaNE = 2 * (dy - dx);
	std::cout << "deltaE = " << deltaE << ", deltaNE = " << deltaNE << "\n";
	std::cout << "Start point: (" << x << "," << y << ")\n";
	
	std::cout << "d\tchosen\t(xp+1, yp+1)\t\tdelta\n";
	std::cout << "____________________________________________\n";
	int delta = 0;
	for (x = x0; x < x1;){
		std::cout << d << "\t";
		if(d <= 0) {
			d += deltaE;
			delta = deltaE;
			std::cout << "E\t";
		} else {
			d += deltaNE;
			delta = deltaNE;
			std::cout << "NE\t";
			y += y_inc;
		}
		std::cout << "(" << (++x) << ", " << y << ")\t\t" << delta << "\n";
		// putpixel(x, y, color);
	}
}

void bresenham_line_high(int x0, int y0, int x1, int y1, int color) {
	// +ve or -ve steep gradients
	// switch x and y
	int dx = x1 - x0, dy = y1 - y0;
	int x = x0, y = y0;
	// putpixel(x, y, color);
	std::cout << "dx = " << dx << ", dy = " << dy << "\n";
	
	int x_inc = 1;
	if(dx < 0) {
		x_inc = -1;
		dx = -dx;
	}
	int d = 2 * dx - dy;
	std::cout << "d = " << d << "\n";
	int deltaE = 2 * dx, deltaNE = 2 * (dx - dy);
	std::cout << "deltaE = " << deltaE << ", deltaNE = " << deltaNE << "\n";
	std::cout << "Start point: (" << x << "," << y << ")\n";
	
	std::cout << "d\tchosen\t(xp+1, yp+1)\t\tdelta\n";
	std::cout << "____________________________________________\n";
	int delta = 0;
	for (y = y0; y < y1;){
		std::cout << d << "\t";
		if(d <= 0) {
			d += deltaE;
			delta = deltaE;
			std::cout << "N\t";
		} else {
			d += deltaNE;
			delta = deltaNE;
			std::cout << "NE\t";
			x += x_inc;
		}
		std::cout << "(" << x << ", " << (++y) << ")\t\t" << delta << "\n";
		// putpixel(x, y, color);
	}
}

void bresenham_line(int x0, int y0, int x1, int y1, int color) {
	if(std::abs(y1 - y0) < std::abs(x1 - x0)) {
		if(x0 > x1) bresenham_line_low(x1, y1, x0, y0, color);
		else bresenham_line_low(x0, y0, x1, y1, color);
	} else {
		if(y0 > y1) bresenham_line_high(x1, y1, x0, y0, color);
		else bresenham_line_high(x0, y0, x1, y1, color);
	}
}

int main() {
	//int gd = DETECT, gm;
	int x0, y0, x1, y1;
	std::cin >> x0 >> y0 >> x1 >> y1;
	//initgraph(&gd, &gm, NULL);
	//bresenham_line(0, 0, 300, 400, RED);
	//bresenham_line(300, 0, 200, 400, GREEN);
	bresenham_line(x0, y0, x1, y1, BLUE);
	std::cout << "\n";

	//closegraph();
	return 0;
}

