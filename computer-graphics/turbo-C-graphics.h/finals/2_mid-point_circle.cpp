#include <iostream>
#include <graphics.h>

/*
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
*/

/*
void symmetric_circle_points(int cx, int cy, int px, int py) {
	int sign[2] = {-1, 1};
	int x, y, x1, y1;
	for(int i=0;i<4;i++) {
		x = cx + sign[i/2%2] * px;
		y = cy + sign[i%2] * py;

		x1 = cx + sign[i/2%2] * py;
		y1 = cy + sign[i%2] * px;
		// std::cout << "cx " << sign[i/2%2]  << " px" << ", cy " << sign[i%2] << " py"<< "\n";
		if(!(x < 0 || y < 0)) putpixel(x, y, GREEN);
		if(!(x1 < 0 || y1 < 0)) putpixel(x1, y1, GREEN);
	}
}
*/

/*
void mid_point_circle(int cx, int cy, int radius) {
	int x = 0, y = radius;
	int d = 1 - radius;
	std::cout << "x = " << x << ", y = " << y << ", d = " << d << std::endl;
	//symmetric_circle_points(cx, cy, x, y);

	while(y > x) {
		std::cout << "------------------------\n";
		std::cout << "d = " << d << "\n";
		if(d < 0) {
			std::cout << "d < 0, thus, choose E\n";
			// select E
			d += (2 * x + 3);
		} else {
			std::cout << "d >= 0, thus, choose SE\n";
			// select SE
			d += (2 * (x - y) + 5);
			y--;
		}
		x++;
		std::cout << "(" << x << ", " << y << ")\n";
		//symmetric_circle_points(cx, cy, x, y);
		std::cout << "------------------------\n";
	}
}
*/

void mid_point_circle(int cx, int cy, int radius) {
	int x = 0, y = radius;
	int d = 1 - radius;
	std::cout << "x = " << x << ", y = " << y << ", d = " << d << std::endl;
	//symmetric_circle_points(cx, cy, x, y);
	std::cout << "d\tchosen\t(xp+1, yp+1)\t2xp+1\t2yp+1\tdelta\n";
	std::cout << "____________________________________________________\n";
	while(y > x) {
		std::cout << d << "\t";
		x++;
		int delta = 0;
		if(d < 0) {
			std::cout << "E\t";
			// select E
			delta = (2 * x + 1);
			d += delta;
		} else {
			std::cout << "SE\t";
			y--;
			// select SE
			delta = (2 * (x - y) + 1);
			d += delta;
		}
		std::cout << "(" << x << ", " << y << ")\t\t";
		std::cout << 2*x << "\t" << 2*y << "\t" << delta << "\n";
		//symmetric_circle_points(cx, cy, x, y);
		//std::cout << "------------------------\n";
	}
}

int main() {
	//int gd = DETECT, gm;
	//initgraph(&gd, &gm, NULL);
	int cx, cy, r;
	std::cin >> cx >> cy >> r;
	mid_point_circle(cx, cy, r);
	
	//getch();
	//closegraph();
	return 0;
}

