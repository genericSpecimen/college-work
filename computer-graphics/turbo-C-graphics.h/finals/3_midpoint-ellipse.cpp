#include <iostream>

void midpoint_ellipse(int a, int b) {
	// Region 1
	// first point in region 1
	int x = 0, y = b;
	std::cout << "Start point: (" << x << ", " << y << ")\n";
	int twob2 = 2 * b*b;
	int twoa2 = 2 * a*a;
	std::cout << "2a2 = " << twoa2 << ", 2b2 = " << twob2 << "\n";
	std::cout << "\nREGION 1\n";
	// decision parameter for region 1
	int d1 = b*b + (a*a)/4 - a*a*b;
	std::cout << "intial d1 = " << d1 << "\n";
	
	std::cout << "d1\tchosen\t(xp+1, yp+1)\t\t2b2.xp+1\t2a2.yp+1\tdelta\n";
	std::cout << "____________________________________________________\n";
	int delta = 0;
	while((twob2 * x) < (twoa2 * y)) {
		std::cout << d1 << "\t";
		x++;
		if(d1 < 0) {
			// choose E
			std::cout << "E\t";
			delta = (twob2 * x) + (b*b);
			d1 += delta;
		} else {
			// choose SE
			std::cout << "SE\t";
			y--;
			delta = (twob2 * x) - (twoa2 * y) + (b*b);
			d1 += delta;
		}
		std::cout << "(" << x << ", " << y << ")\t\t";
		std::cout << twob2 * x << "\t" << twoa2 * y << "\t" << delta << "\n";
	}

	// Region 2
	std::cout << "\n\nREGION 2\n";
	std::cout << "Initial point: (" << x << ", " << y << ")\n";
	int d2 = b*b*(x+0.5)*(x+0.5) + a*a*(y-1)*(y-1) - a*a*b*b;
	std::cout << "Initial decision parameter, d2 = " << d2 << "\n";
	
	std::cout << "d2\tchosen\t(xp+1, yp+1)\t\t2b2.xp+1\t2a2.yp+1\tdelta\n";
	std::cout << "____________________________________________________\n";
	delta = 0;
	while(y > 0) {
		std::cout << d2 << "\t";
		y--;
		if(d2 > 0) {
			// choose S
			std::cout << "S\t";
			delta = -(twoa2 * y) + (a*a);
			d2 += delta;
		} else {
			// choose SE
			std::cout << "SE\t";
			x++;
			delta = (twob2 * x) - (twoa2 * y) + (a*a);
			d2 += delta;
		}
		std::cout << "(" << x << ", " << y << ")\t\t";
		std::cout << twob2 * x << "\t" << twoa2 * y << "\t" << delta << "\n";
	}

}

int main() {
	// 2a = major axis
	// 2b = minor axis
	int a, b; std::cin >> a >> b;
	midpoint_ellipse(a, b);
}
