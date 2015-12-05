#include<iostream>
class Polynomial
{
	private:
		int n;	//degree of polynomial
		float *coeff;
	public:
		Polynomial();
		Polynomial(const int);
		Polynomial(const Polynomial &);
		~Polynomial();
		Polynomial operator=(const Polynomial &);
		Polynomial derivative() const;
		Polynomial integral() const;
		Polynomial operator+(const Polynomial &) const;
		Polynomial operator-(const Polynomial &) const;
		Polynomial operator*(const Polynomial &) const;
		Polynomial operator/(const Polynomial &) const;
		Polynomial operator%(const Polynomial &) const;
		float value(const float) const;
		void print() const;
		int getn();
		void read();
};
