#include <iostream>

#include "ppm.h"
#include <cmath>

void dda_line(PPM &ppm, Point &p0, Point &p1, const PixelColor &pc = BLACK) {
	int dx = p1.x - p0.x, dy = p1.y - p0.y;
	double m = dy/static_cast<double>(dx);
	std::cout << "dy: " << dy << ", dx: " << dx << ", m:" << m << "\n";

	int max_steps = (dx >= dy ? dx : dy);
	double x_inc = dx / static_cast<double>(max_steps);
	double y_inc = dy / static_cast<double>(max_steps);

	double x = p0.x, y = p0.y;
	Point pt = {0,0};
	for(int i = 0; i <= std::abs(max_steps); i++) {
		std::cout << "(" << x << ", " << y << ")\n";
		pt.x = std::round(x); pt.y = std::round(y);
		ppm.set_pixel(pt, pc);
		x = x + x_inc;
		y = y + y_inc;
	}
}

void mid_point_line(PPM &ppm, Point &p0, Point &p1, const PixelColor &pc = BLACK) {
	// TODO complete implementation for other slopes
	int dx = p1.x - p0.x, dy = p1.y - p0.y;
	int d = 2 * dy - dx;
	int deltaE = 2 * dy, deltaNE = 2 * (dy - dx);
	int x = p0.x, y = p0.y;
	Point pt = {p0.x, p0.y};
	ppm.set_pixel(pt, pc);
	while(x < p1.x) {
		if(d <= 0) {
			d += deltaE;
			x++;
		} else {
			d += deltaNE;
			x++;
			y++;
		}
		std::cout << "(" << x << ", " << y << ")\n";
		pt.x = x; pt.y = y;
		ppm.set_pixel(pt, pc);
	}
}

void explicit_circle(PPM &ppm, Point &c, unsigned int radius, const PixelColor &pc = BLACK) {
	/*
	double y = 0;
	for(int x=0;x<=radius;x++) {
		y = std::sqrt(radius*radius - x*x);
		ppm.set_pixel(x, std::round(y), pc);
	}
	*/
	double x = 0, y = 0;
	for(int theta = 0; theta <= 360; theta++) {
		x = std::round(radius*cos(theta*M_PI/180));
		y = std::round(radius*sin(theta*M_PI/180));
		ppm.set_pixel(Point{x + c.x, y + c.y}, pc);
	}
}

void symmetric_circle_points(PPM &ppm, Point &c, Point &p, const PixelColor &pc = BLACK) {
	ppm.set_pixel(Point{c.x + p.x,	c.y + p.y},	pc);
	ppm.set_pixel(Point{c.x + p.x,	c.y - p.y},	pc);
	ppm.set_pixel(Point{c.x - p.x,	c.y + p.y},	pc);
	ppm.set_pixel(Point{c.x - p.x,	c.y - p.y},	pc);

	ppm.set_pixel(Point{c.x + p.y,	c.y + p.x},	pc);
	ppm.set_pixel(Point{c.x + p.y,	c.y - p.x},	pc);
	ppm.set_pixel(Point{c.x - p.y,	c.y + p.x},	pc);
	ppm.set_pixel(Point{c.x - p.y,	c.y - p.x},	pc);
}

void mid_point_circle(PPM &ppm, Point &c, unsigned int radius, const PixelColor &pc = BLACK) {
	unsigned int x = 0, y = radius;
	int d = 1 - radius;
	std::cout << "x = " << x << ", y = " << y << ", d = " << d << std::endl;
	Point pt = {x, y};
	symmetric_circle_points(ppm, c, pt, pc);

	while(y > x) {
		if(d < 0) {
			// select E
			d += (2 * x + 3);
		} else {
			// select SE
			d += (2 * (x - y) + 5);
			y--;
		}
		x++;
		pt.x = x; pt.y = y;
		std::cout << "x = " << x << ", y = " << y << ", d = " << d << std::endl;
		symmetric_circle_points(ppm, c, pt, pc);
	}
}

void symmetric_ellipse_points(PPM &ppm, Point &c, Point &p, const PixelColor &pc = BLACK) {
	ppm.set_pixel(Point{c.x + p.x,	c.y + p.y},	pc);
	ppm.set_pixel(Point{c.x + p.x,	c.y - p.y},	pc);
	ppm.set_pixel(Point{c.x - p.x,	c.y + p.y},	pc);
	ppm.set_pixel(Point{c.x - p.x,	c.y - p.y},	pc);
}

void mid_point_ellipse(PPM &ppm, Point &c, unsigned int a, unsigned int b, const PixelColor &pc = BLACK) {
	unsigned int x = 0, y = b;
	double d1 = (b * b) + (a * a) * (0.25 - b); 
	Point pt = {x, y};
	symmetric_ellipse_points(ppm, c, pt, pc);

	while( a*a*(y-0.5) > b*b*(x+1) ) {
		// region 1
		if(d1 < 0) {
			// select E
			d1 += b*b*(2*x + 3);
			x++;
		} else {
			// select SE
			d1 += b*b*(2*x + 3) + a*a*(-2*y + 2);
			x++;
			y--;
		}
		pt.x = x; pt.y = y;
		symmetric_ellipse_points(ppm, c, pt, pc);
	}

	// region 2
	double d2 = b*b*(x+0.5)*(x+0.5) + a*a*(y-1)*(y-1) - a*a*b*b;
	while(y > 0) {
		if(d2 < 0) {
			// select SE
			d2 += b*b*(2*x+2) + a*a*(-2*y + 3);
			x++;
			y--;
		} else {
			// select S
			d2 += a*a*(-2*y + 3);
			y--;
		}
	}
}

int main() {
	unsigned int width = 500, height = 500, max_color_val = 255;
	PPM ppm(width, height, max_color_val, WHITE);

	//unsigned int x0 = 10, y0 = 10;
	//unsigned int x1 = 10, y1 = 100;
	//Point p0 = {10, 10}, p1 = {20, 100};
	Point p0 = {5, 8}, p1 = {9, 11};

	//std::cin >> x0 >> y0 >> x1 >> y1;
	if(p0.x > p1.x) {
		// algorithm draws from left to right, therefore
		// x0 must be less than x1
		std::swap(p0.x, p1.x);
		std::swap(p0.y, p1.y);
	}
	//dda_line(ppm, p0, p1);
	//mid_point_line(ppm, p0, p1);
	//std::cout << M_PI << std::endl;
	
	Point center = {250, 250};
	//explicit_circle(ppm, center, 150);
	
	//Point p = {20, 25};
	//symmetric_circle_points(ppm, center, p);
	unsigned int radius = 150;
	//mid_point_circle(ppm, center, radius);
	
	//symmetric_ellipse_points(ppm, center, p);
	mid_point_ellipse(ppm, center, 50, 40);
	ppm.write_ppm("test.ppm");
	system("gimp test.ppm");
}


