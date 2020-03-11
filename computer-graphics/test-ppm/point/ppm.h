#ifndef PPM_H
#define PPM_H

#include <iostream>
#include <string>
#include <vector>

struct Point {
	unsigned int x, y;
};

struct PixelColor {
	unsigned int r, g, b;
};

const PixelColor RED	= {255,	0,	0};
const PixelColor GREEN	= {0,	255,	0};
const PixelColor BLUE	= {0,	0,	255};
const PixelColor BLACK	= {0,	0,	0};
const PixelColor WHITE	= {255,	255,	255};

class PPM {
	std::string magic_number = "P3";

	/* width  = no. of columns
	 * height = no. of rows
	 * size = width*height; there will be *size* number of pixels
	 */
	unsigned int width, height, img_size;

	unsigned int max_color_val;
public:
	// vector that stores rgb values for each pixel
	std::vector<PixelColor*> pixmap;

	PPM(unsigned int width, unsigned int height, unsigned int max_color_val, const PixelColor &pc = WHITE);
	void set_pixel(const Point &p, const PixelColor &pc = BLACK);

	void write_ppm(const std::string &filename);

	// maps a point (x,y) to an index in pixmap
	unsigned int map_xy(const Point &p);

};

#endif // PPM_H
