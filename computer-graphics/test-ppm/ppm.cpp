#include <iostream>
#include <fstream>
#include "ppm.h"

PPM::PPM(unsigned int width, unsigned int height, unsigned int max_color_val, const PixelColor &pc) {
	this->width = width;
	this->height = height;
	this->max_color_val = max_color_val;
	this->img_size = width*height;
	pixmap.resize(img_size);
	for(int i=0;i<img_size;i++) {
		pixmap[i] = new PixelColor();
		*pixmap[i] = pc; // white, initially
	}
	std::cout << "Initialised a PPM image with\n"
		<< "\twidth 		= " << width
		<< "\n\theight		= " << height
		<< "\n\tmax_color_val	= " << max_color_val
		<< "\n\tsize		= " << img_size
		<< "\n";
}

unsigned int PPM::map_xy(unsigned int x, unsigned int y) {
	return (x + this->width * y);
}

void PPM::set_pixel(unsigned int x, unsigned int y, const PixelColor &pc) {
	unsigned int idx = map_xy(x,y);
	if(idx < img_size) {
		*pixmap[idx] = pc;
	} else std::cout << "x and y out of range.\n";
}

void PPM::write_ppm(const std::string &filename) {
	std::ofstream out_img(filename.c_str());
	if(!out_img.is_open()) {
		std::cout << "Failed to open " << filename << "\n";
		return;
	}
	out_img << magic_number << "\n";
	out_img << width << " " << height << "\n";
	out_img << max_color_val << "\n";
	for(auto &x:pixmap) {
		out_img << x->r << " " << x->g << " " << x->b << "\n";
	}
	out_img.close();
}
