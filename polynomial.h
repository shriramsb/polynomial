#include<iostream>
class Polynomial
{	
	private:
		int n;	//degree of polynomial
		float *coeff;
	public:
		void read();
		Polynomial operator+(const Polynomial &) const;
		Polynomial operator-(const Polynomial &) const;
		Polynomial operator*(const Polynomial &) const;
		Polynomial operator/(const Polynomial &) const;
		Polynomial operator%(const Polynomial &) const;
		float value(const float) const;
		void print() const;
		 

};
