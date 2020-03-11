#include <iostream>
#include <graphics.h>

void bresenham_line_low(int x0, int y0, int x1, int y1) {
	// slope between -1 and 1
	int dx = x1 - x0, dy = y1 - y0;
	int x = x0, y = y0;
	putpixel(x, y, RED);
	
	int y_inc = 1;
	if(dy < 0) {
		std::cout << "gradient less than 0\n";
		// to cover gradients between 0 and -1,
		// we check whether y needs to increase or decrease
		y_inc = -1;
		dy = -dy;
	}
	int d = 2 * dy - dx;
	int deltaE = 2 * dy, deltaNE = 2 * (dy - dx);
	for (x = x0; x <= x1; x++){
		if(d <= 0) {
			d += deltaE;
		} else {
			d += deltaNE;
			y += y_inc;
		}
		std::cout << "(" << x << "," << y << ")" << std::endl;
		putpixel(x, y, RED);
	}
}

void bresenham_line_high(int x0, int y0, int x1, int y1) {
	// +ve or -ve steep gradients
	// switch x and y
	int dx = x1 - x0, dy = y1 - y0;
	int x = x0, y = y0;
	putpixel(x, y, RED);
	
	int x_inc = 1;
	if(dx < 0) {
		x_inc = -1;
		dx = -dx;
	}
	int d = 2 * dx - dy;
	int deltaE = 2 * dx, deltaNE = 2 * (dx - dy);
	for (y = y0; y <= y1; y++){
		if(d <= 0) {
			d += deltaE;
		} else {
			d += deltaNE;
			x += x_inc;
		}
		std::cout << "(" << x << "," << y << ")" << std::endl;
		putpixel(x, y, RED);
	}
}

void bresenham_line(int x0, int y0, int x1, int y1) {
	if(std::abs(y1 - y0) < std::abs(x1 - x0)) {
		if(x0 > x1) bresenham_line_low(x1, y1, x0, y0);
		else bresenham_line_low(x0, y0, x1, y1);
	} else {
		if(y0 > y1) bresenham_line_high(x1, y1, x0, y0);
		else bresenham_line_high(x0, y0, x1, y1);
	}
}

int main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	bresenham_line(0, 0, 10, 100);
	getch();
	closegraph();
	return 0;
}

