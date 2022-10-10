#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compleX.h"

double eps = 1e-12;

compleX* sumC(compleX* a, compleX* b) {
	compleX* res = new compleX;
	res->real = (a->real) + (b->real);
	res->img = (a->img) + (b->img);

	return res;
}

compleX* subtrC(compleX* a, compleX* b) {
	compleX* res = new compleX;
	res->real = (a->real) - (b->real);
	res->img = (a->img) - (b->img);

	return res;
}

compleX* mltC(compleX* a, compleX* b) {
	compleX* res = new compleX;
	res->real = (a->real) * (b->real) - (a->img) * (b->img);
	res->img = (a->real) * (b->img) + (a->img) * (b->real);

	return res;
}

compleX* divC(compleX* a, compleX* b) {
	double x1 = a->real, x2 = b->real,
		y1 = a->img, y2 = b->img;

	double resReal = ((x1 * x2) + (y1 * y2)) / (x2 * x2 + y2 * y2);
	double resImg  = ((y1 * x2) - (x1 * y2)) / (x2 * x2 + y2 * y2);
	/*if (abs(y2) < eps) {
		double u1 = x1, u2 = y1;
		x1 = x2; y1 = y2;
		x2 = u1; y2 = u2;
	}
	if (abs(y1) < eps) {
		resReal = x2 * x1;
		resImg  = y2 * x1;
	}
	*/
	compleX* res = new compleX;
	res->real = resReal;
	res->img  = resImg;

	return res;
}

compleX* neg(compleX* a) {
	double rl = (a->real) * (-1);
	double im = (a->img) * (-1);

	compleX* res = new compleX(rl, im);
	return res;
}