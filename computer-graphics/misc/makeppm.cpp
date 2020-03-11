#include <fstream>

int main() {
	int width = 500, height = 500;
	std::ofstream img("random.ppm");
	img << "P3" << std::endl;
	img << width << " " << height << std::endl;
	img << "255" << std::endl;

	int r = 0, g = 0, b = 0;
	for(int i=0;i<height;i++) {
		for(int j=0;j<width;j++) {
			img << (r++ % 255) << " " << (g++ % 255) << " " << (b++ % 255) << std::endl;
		}
	}
	return 0;
}
