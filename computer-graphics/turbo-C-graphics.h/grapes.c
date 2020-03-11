#include <stdio.h>
#include <graphics.h>

int main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	int l = 200, b = 30;
	line(0, 0, l, 0);
	line(0, 0, 0, b);
	line(l, 0, l, b);
	line(0, b, l, b);

	int n = 10;
	int r = l/(n*2);

//	for(int i=0;i<n-0;i++) {
//		circle(1*r + 2*i*r, b+r+0*50, r);
//	}
//	for(int i=0;i<n-1;i++) {
//		circle(2*r + 2*i*r, b+r+1*43.301, r);
//	}
//	for(int i=0;i<n-2;i++) {
//		circle(3*r + 2*i*r, b+r+2*43.301, r);
//	}
//	for(int i=0;i<n-3;i++) {
//		circle(4*r + 2*i*r, b+r+3*43.301, r);
//	}

	for(int i=0;i<n;i++) {
		for(int j=0;j<n-i;j++) {
			circle((i+1)*r + 2*j*r, b+r+i*(2*r), r);
		}
	}
	getch();
	closegraph();
	return 0;
}
