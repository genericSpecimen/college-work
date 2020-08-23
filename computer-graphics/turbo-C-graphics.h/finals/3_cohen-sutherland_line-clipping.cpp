#include <iostream>
#include <graphics.h>

// Outcode: TBRL

const int INSIDE	= 0; // 0000
const int LEFT		= 1; // 0001
const int RIGHT		= 2; // 0010
const int BOTTOM	= 4; // 0100
const int TOP		= 8; // 1000

// clip rectangle

const int x_min = -3;
const int x_max = 2;
const int y_min = 1;
const int y_max = 6;

int compute_outcode(double x, double y) {
	int code = INSIDE;

	if (x < x_min) {
		// point is to the LEFT of the left clip boundary
		code |= LEFT;	//set the last bit
	}
	else if (x > x_max) {
		// point is to the RIGHT of the right clip boundary
		code |= RIGHT;	//set the second last bit
	}
	
	if (y < y_min) {
		// point is to the BOTTOM of the bottm clip boundary
		code |= BOTTOM; // set the second bit
	}
	else if(y > y_max) {
		// point is to the TOP of the top clip boundary
		code |= TOP;	// set the first bit
	}
	return code;
}

void cohen_sutherland_clip(double x0, double y0, double x1, double y1, int color) {
	/*
	 * clip the line segment PQ where P = (x0, y0) and Q = (x1, y1)
	 * against the clip rectangle as defined by x_min, x_max, y_min, y_max
	 */

	// region codes for P and Q
	int oc0 = compute_outcode(x0, y0);
	int oc1 = compute_outcode(x1, y1);

	setcolor(color);

	bool accept = false;

	while (true) {
		std::cout << "\n\n=> LINE SEGMENT (" << x0 << ", " << y0 << ") -> (" << x1 << ", " << y1 << ")\n";
		if(oc0 == 0 && oc1 == 0) {
			/* region codes of both points is 0,
			 * thus both points lie inside the clip rectangle
			 * TRIVIAL ACCEPTANCE
			 */
			std::cout << "TRIVIAL ACCEPTANCE\n";
			accept = true;
			break;
		} else if((oc0 & oc1) != 0) {
			/* logical AND of both points is not 0,
			 * thus, both points lie outside the clip rectangle
			 * TRIVIAL REJECTION
			 */
			std::cout << "TRIVIAL REJECTION\n";
			accept = false;
			break;
		} else {
			/* logical AND is 0,
			 * tests for both trivial acceptance / rejection have failed;
			 * the line segment intersects with some clip boundary
			 * we need to clip against that boundary
			 */

			// pick the outcode of a point which is outside the clip rectangle
			// (there must be one such point)
			int oc_outside = (oc0 != 0) ? oc0 : oc1;
			std::cout << "oc_outside = " << oc_outside << "\n";
			double x, y;

			/*
			 * Find the intersection point using the formulae
			 * y = y0 + m(x - x0)
			 * x = x0 + (1/m)(y - y0)
			 */

			double slope = (y1 - y0) / (x1 - x0);
			std::cout << "slope = " << slope << "\n";

			if (oc_outside & TOP) {
				// intersects with TOP edge (y = y_max)
				y = y_max;
				x = x0 + (1/slope) * (y - y0);
				std::cout << "intersects with TOP edge at (" << x << ", " << y << ")\n";
			} else if (oc_outside & BOTTOM) {
				// intersects with BOTTOM edge (y = y_min)
				y = y_min;
				x = x0 + (1/slope) * (y - y0);
				std::cout << "intersects with BOTTOM edge at (" << x << ", " << y << ")\n";
			} else if (oc_outside & RIGHT) {
				// intersects with RIGHT edge (x = x_max)
				x = x_max;
				y = y0 + slope * (x - x0);
				std::cout << "intersects with RIGHT edge at (" << x << ", " << y << ")\n";
			} else {
				// intersects with LEFT edge (x = x_min)
				x = x_min;
				y = y0 + slope * (x - x0);
				std::cout << "intersects with LEFT edge at (" << x << ", " << y << ")\n";

			}

			if (oc_outside == oc0) {
				x0 = x; y0 = y;
				oc0 = compute_outcode(x0, y0);
				std::cout << "Setting (" << x0 << ", " << y0 << ")'s outcode to: " << oc0 << "\n";
			} else {
				x1 = x; y1 = y;
				oc1 = compute_outcode(x1, y1);
				std::cout << "Setting (" << x1 << ", " << y1 << ")'s outcode to: " << oc1 << "\n";
			}
		}
	}

	if(accept) {
		std::cout << "Line from (" << x0 << ", " << y0 << ") to (" << x1 << ", " << y1 << ") has been accepted.\n\n";
		// display the line
		line(x0, y0, x1, y1);
	} else {
		std::cout << "Line from (" << x0 << ", " << y0 << ") to (" << x1 << ", " << y1 << ") has been rejected.\n\n";
		// display nothing else
	}
}

int main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	
	// display clip rectangle
	// left-top right-bottom
	setcolor(GREEN); rectangle(x_min, y_min, x_max, y_max);

	/*
	// without clipping
	setcolor(RED);		line(50, 10, 100, 40);
	setcolor(WHITE);	line(70, 90, 110, 40);
	setcolor(BLUE);		line(30, 15, 50, 300);
	setcolor(YELLOW);	line(150, 10, 300, 110);
	setcolor(MAGENTA);	line(30, 0, 110, 110);
	setcolor(WHITE);	line(125, 300, 300, 200);
	setcolor(CYAN);		line(0, 125, 300, 125);
	*/

	// /* 
	// with clipping
	/*
	cohen_sutherland_clip(50, 10, 100, 40, RED);
	cohen_sutherland_clip(70, 90, 110, 40, WHITE);
	cohen_sutherland_clip(30, 15, 50, 300, BLUE);
	cohen_sutherland_clip(200, 10, 260, 110, YELLOW);
	cohen_sutherland_clip(30, 0, 110, 110, MAGENTA);
	cohen_sutherland_clip(125, 300, 300, 200, WHITE);
	cohen_sutherland_clip(0, 125, 300, 125, CYAN);
	// */

	//cohen_sutherland_clip(-4, 2, -1, 7, GREEN);
	//cohen_sutherland_clip(-1, 5, 3, 8, GREEN);
	cohen_sutherland_clip(-1, 2, 3, 3, GREEN);
	getch();
	closegraph();
	return 0;
}

