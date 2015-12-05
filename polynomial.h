#include<iostream>

class Polynomial
{
	Polynomial();
	Polynomial(const int);
	Polynomial(const Polynomial &);
	~Polynomial();
	int getn();
	Polynomial operator=(const Polynomial &);
	Polynomial derivative() const;
	Polynomial integral() const;
};
