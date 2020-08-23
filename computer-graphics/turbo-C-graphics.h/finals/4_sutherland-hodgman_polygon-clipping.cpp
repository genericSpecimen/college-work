#include <iostream>
#include <vector>
#include <graphics.h>

struct Point {
	double x, y;
};

struct Edge {
	Point p, q;
};

Point compute_intersection(Point &p, Point &q, Edge &e) {
	/*
	 * calculates intersection of subject polygon edge from
	 * vertex p to q with the clipping polygon edge e
	 */
	double x1 = p.x, y1 = p.y;
	double x2 = q.x, y2 = q.y;

	double x3 = e.p.x, y3 = e.p.y;
	double x4 = e.q.x, y4 = e.q.y;

	// s = subject 
	double s_dx = x1 - x2, s_dy = y1 - y2;
	// c = clipping
	double c_dx = x3 - x4, c_dy = y3 - y4;

	double den = (s_dx) * (c_dy) - (s_dy) * (c_dx);

	double det_12 = x1 * y2 - y1 * x2;
	double det_34 = x3 * y4 - y3 * x4;

	Point intersection;
	intersection.x = (det_12 * c_dx - s_dx * det_34) / den;
	intersection.y = (det_12 * c_dy - s_dy * det_34) / den;
	
	return intersection;
}

bool inside(Point &p, Edge &e) {
	/*
	 * returns true if vertex is on the 
	 * inside of the clip boundary edge e.
	 * "inside" means to the left of the clip boundary when one looks
	 * from the first vertex to the second vertex of the clip boundary
	 */
	double x = p.x, y = p.y;
	double x1 = e.p.x, y1 = e.p.y;
	double x2 = e.q.x, y2 = e.q.y;
	double d = (x - x1) * (y2 - y1) - (y - y1) * (x2 - x1);
	return d < 0;
}

std::vector<Point> sutherland_hodgman_clip(std::vector<Point> &clipping_polygon, std::vector<Point> &subject_polygon) {
	
	// ---- store the edges in clipping_polygon_edges --------------
	std::vector<Edge> clipping_polygon_edges;
	Point p, q;
	for (int i=0;i<clipping_polygon.size();i++) {
		p = clipping_polygon[i];
		q = clipping_polygon[(i + 1) % clipping_polygon.size()];
		clipping_polygon_edges.push_back({p, q});
	}
	//--------------------------------------------------------------

	std::vector<Point> output_vertices = subject_polygon;
	std::vector<Point> input_vertices;
	std::cout << "Clipping the subject polygon against the edges of the clipping polygon:\n";
	for(Edge &edge : clipping_polygon_edges) {
		std::cout << "\n=> Clipping against edge (" << edge.p.x << ", " << edge.p.y << ") -> (" << edge.q.x << ", " << edge.q.y << ")\n";
		
		// the output of an interation becomes the input of the next iteration
		input_vertices = output_vertices;
		// make way for the output of this iteration
		output_vertices.clear();

		// check all subject polygon vertices against this edge
		Point current_point, prev_point, intersection;
		for (int i=0; i<input_vertices.size(); i++) {
			current_point = input_vertices[i];
			prev_point = input_vertices[(i + input_vertices.size() - 1) % input_vertices.size()];
			intersection = compute_intersection(prev_point, current_point, edge);
			std::cout << "\tChecking subject polygon edge (" << current_point.x << ", " << current_point.y << ") -> ";
			std::cout << "(" << prev_point.x << ", " << prev_point.y << ")\n";
			std::cout << "\tIntersection: (" << intersection.x << ", " << intersection.y << ")\n";
			if (inside(current_point, edge)) {
				if(!inside(prev_point, edge)) {
					output_vertices.push_back(intersection);
				}
				output_vertices.push_back(current_point);
			} else if(inside(prev_point, edge)) {
				output_vertices.push_back(intersection);
			}
			std::cout << "\tOutput vertices: [";
			for(Point &p : output_vertices) std::cout << "(" << p.x << ", " << p.y << "), ";
			std::cout << "]\n\n";
		}
	}
	return output_vertices;
}

void draw_polygon(const std::vector<Point> &polygon) {
	std::vector<int> values;
	for(const Point &p : polygon) {
		values.push_back(p.x);
		values.push_back(p.y);
	}
	// push the first point again
	values.push_back(polygon[0].x);
	values.push_back(polygon[0].y);

	int *arr = &values[0];
	drawpoly(values.size()/2, arr);
}

int main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	// vertices are listed in a counter-clockwise direction

	/*
	std::vector<Point> clipping_polygon = {
		{200/2, 400/2}, {200/2, 200/2}, {400/2, 200/2}, {400/2, 400/2}
	};
	std::vector<Point> subject_polygon = {
		{100/2, 300/2}, {400/2, 100/2}, {300/2, 300/2}, {400/2, 500/2}
	};
	*/
	

	/*
	std::vector<Point> clipping_polygon = {
		{150, 200}, {150, 150}, {200, 150}, {200, 200} 
	};
	
	std::vector<Point> subject_polygon = {
		{100, 150}, {300, 200}, {200, 250}  
	};
	*/

	/*
	std::vector<Point> clipping_polygon = {
		{, }, {, }, {, }, {, }
	};
	std::vector<Point> subject_polygon = {
		{, }, {, }, {, }, {, }
	};
	*/


	std::vector<Point> clipping_polygon = {
		{5, 15}, {5, 5}, {15, 5}, {15, 15}
	};
	std::vector<Point> subject_polygon = {
		{10, 17}, {3, 8}, {13, 12}
	};
	


	std::cout << "Clipping Polygon:\n";
	for(Point &v : clipping_polygon) std::cout << "(" << v.x << ", " << v.y << ")\n";
	
	std::cout << "Subject Polygon:\n";
	for(Point &v : subject_polygon) std::cout << "(" << v.x << ", " << v.y << ")\n";

	std::vector<Point> output_vertices = sutherland_hodgman_clip(clipping_polygon, subject_polygon);
	std::cout << "Clipped polygon vertices: [";
	for(Point &p : output_vertices) std::cout << "(" << p.x << ", " << p.y << "), ";
	std::cout << "]\n";

	draw_polygon(clipping_polygon);
	draw_polygon(subject_polygon);	

	// draw the clipped diagram 200 pixels to the right
	for (Point &p : clipping_polygon) p.x += 200;
	for (Point &p : output_vertices) p.x += 200;
	draw_polygon(clipping_polygon);
	draw_polygon(output_vertices);	

	getch();
	closegraph();
	return 0;
}

