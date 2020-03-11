#include <iostream>
#include <graphics.h>

void symmetric_circle_points(int cx, int cy, int px, int py) {
	putpixel(cx + px, cy + py, GREEN);
	putpixel(cx + px, cy - py, GREEN);
	putpixel(cx - px, cy + py, GREEN);
	putpixel(cx - px, cy - py, GREEN);

	putpixel(cx + py, cy + px, GREEN);
	putpixel(cx + py, cy - px, GREEN);
	putpixel(cx - py, cy + px, GREEN);
	putpixel(cx - py, cy - px, GREEN);
}

void mid_point_circle(int cx, int cy, int radius) {
	int x = 0, y = radius;
	int d = 1 - radius;
	std::cout << "x = " << x << ", y = " << y << ", d = " << d << std::endl;
	symmetric_circle_points(cx, cy, x, y);

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
		std::cout << "x = " << x << ", y = " << y << ", d = " << d << std::endl;
		symmetric_circle_points(cx, cy, x, y);
	}
}


int main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	mid_point_circle(250, 250, 150);
	
	getch();
	closegraph();
	return 0;
}

