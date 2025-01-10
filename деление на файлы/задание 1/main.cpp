#include <iostream>
#include <cmath>
#include"main.h"
using namespace std;


bool nerav_treugolnika(double a, double b, double c) {
	bool flag = true;
	if (a >= b + c) {
		flag = false;
	}
	if (b >= a + c) {
		flag = false;
	}
	if (c >= a + b) {
		flag = false;
	}
	return flag;
}

double perimetr(double a, double b, double c) {
	return a + b + c;
}


double cooficient_a(double x1, double x2, double y1, double y2) {
	if (x1 == x2) {
		return 1;
	}
	return ((y1 - y2) / (x1 - x2));
}

double cooficient_b(double x1, double x2, double y1, double y2) {
	if (y1 == y2) {
		return 1;
	}
	return (cooficient_a(x1, x2, y1, y2) * (x2 - x1) / (y1 - y2));
}

double cooficient_с(double x1, double x2, double y1, double y2) {
	double a = cooficient_a(x1, x2, y1, y2);
	double b = cooficient_b(x1, x2, y1, y2);
	if (b == 0 || a == 0) {
		return 0;
	}
	return (-(b * (y1 + y2) + a * (x1 + x2)) / 2);
}


double plohad(double a, double b, double c) {
	double poluperimetr = perimetr(a, b, c) / 2;
	return sqrt(poluperimetr * (poluperimetr - a) * (poluperimetr - b) * (poluperimetr - c));
}

double distance_tohca_to_primaia(double x1, double x2, double y1, double y2, double xm, double ym) {
	double a = cooficient_a(x1, x2, y1, y2);
	double b = cooficient_b(x1, x2, y1, y2);
	double c = cooficient_с(x1, x2, y1, y2);
	return fabs(a * xm + b * ym + c) / sqrt(a * a + b * b);
}

double line_storon(double x1, double x2, double y1, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
