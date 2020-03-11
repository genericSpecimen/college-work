#include <iostream>

#include "ppm.h"
#include <cmath>

void dda_line(PPM &ppm, unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1, const PixelColor &pc = BLACK) {
	int dx = x1 - x0, dy = y1 - y0;
	double m = dy/static_cast<double>(dx);
	std::cout << "dy: " << dy << ", dx: " << dx << ", m:" << m << "\n";

	int max_steps = (dx >= dy ? dx : dy);
	double x_inc = dx / static_cast<double>(max_steps);
	double y_inc = dy / static_cast<double>(max_steps);

	double x = x0, y = y0;
	for(int i = 0; i <= std::abs(max_steps); i++) {
		std::cout << "(" << x << ", " << y << ")\n";
		ppm.set_pixel(std::round(x), std::round(y), pc);
		x = x + x_inc;
		y = y + y_inc;
	}
}

void mid_point_line(PPM &ppm, unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1, const PixelColor &pc = BLACK) {
	int dx = x1 - x0, dy = y1 - y0;
	int d = 2 * dy - dx;
	int deltaE = 2 * dy, deltaNE = 2 * (dy - dx);
	int x = x0, y = y0;
	ppm.set_pixel(x, y, pc);
	while(x < x1) {
		if(d <= 0) {
			d += deltaE;
			x++;
		} else {
			d += deltaNE;
			x++;
			y++;
		}
		std::cout << "(" << x << ", " << y << ")\n";
		ppm.set_pixel(x, y, pc);
	}
}

void symmetric_circle_points(PPM &ppm, unsigned int x, unsigned int y, const PixelColor &pc = BLACK) {
	int ox = 20, oy = 20;
	ppm.set_pixel(ox + x,	oy + y,	pc);
	ppm.set_pixel(ox + x,	oy - y,	pc);
	ppm.set_pixel(ox - x,	oy + y,	pc);
	ppm.set_pixel(ox - x,	oy - y,	pc);

	ppm.set_pixel(oy + y,	ox + x,	pc);
	ppm.set_pixel(oy + y,	ox - x,	pc);
	ppm.set_pixel(oy - y,	ox + x,	pc);
	ppm.set_pixel(oy - y,	ox - x,	pc);
}

void explicit_circle(PPM &ppm, unsigned int radius, const PixelColor &pc = BLACK) {
	/*
	double y = 0;
	for(int x=0;x<=radius;x++) {
		y = std::sqrt(radius*radius - x*x);
		ppm.set_pixel(x, std::round(y), pc);
	}
	*/
	double x = 0, y = 0;
	int ox = 250, oy = 250; // origin
	for(int theta = 0; theta <= 360; theta++) {
		x = std::round(radius*cos(theta*M_PI/180));
		y = std::round(radius*sin(theta*M_PI/180));
		ppm.set_pixel(x + ox, y + oy, pc);
	}
}

int main() {
	unsigned int width = 500, height = 500, max_color_val = 255;
	PPM ppm(width, height, max_color_val, WHITE);

	unsigned int x0 = 10, y0 = 10;
	unsigned int x1 = 10, y1 = 100;
	//std::cin >> x0 >> y0 >> x1 >> y1;
	if(x0 > x1) {
		// algorithm draws from left to right, therefore
		// x0 must be less than x1
		std::swap(x0, x1);
		std::swap(y0, y1);
	}
	//dda_line(ppm, x0, y0, x1, y1);
	//mid_point_line(ppm, x0, y0, x1, y1);
	//std::cout << M_PI << std::endl;
	//explicit_circle(ppm, 150);
	symmetric_circle_points(ppm, 2,3);
	ppm.write_ppm("test.ppm");
	system("gimp test.ppm");
}


