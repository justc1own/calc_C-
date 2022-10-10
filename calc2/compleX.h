#pragma once
struct compleX {
	double real;
	double img;

	compleX(double real = 0, double img = 0) : real(real), img(img){}
};

compleX *sumC(compleX* a, compleX* b);
compleX* subtrC(compleX* a, compleX* b);
compleX* mltC(compleX* a, compleX* b);
compleX* divC(compleX* a, compleX* b);
compleX* neg(compleX* a);