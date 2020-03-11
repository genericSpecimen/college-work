#include <fstream>

int main() {
	int width = 1920, height = 1080;
	std::ofstream img("picture.ppm");
	img << "P3" << std::endl;
	img << width << " " << height << std::endl;
	img << "255" << std::endl;

	int r, g, b;
	for(int i=0;i<height;i++) {
		for(int j=0;j<width;j++) {
			r = j % 255;
			g = i % 255;
			b = i * j % 255;

			img << r << " " << g << " " << b << std::endl;
		}
	}
	return 0;
}
