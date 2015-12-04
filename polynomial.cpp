#include "polynomial.h"

void Polynomial::read()
{
	cin>>n;
	coeff=new float[n+1];
	for(int i=0;i<n+1;i++)
		cin>>coeff[i];
}

Polynomial::Polynomial()
{
	n=0;
	coeff=NULL;
}
Polynomial::Polynomial(int a)
{
	n=a;
	coeff=new float[a+1];
	for(int i=0;i<a+1;i++)
		coeff[i]=0;
}
Polynomial::Polynomial(const Polynomial & q)
{
	n=q.n;
	coeff=new float[n+1];
	for(int i=0;i<n+1;i++)
		coeff[i]=q.coeff[i];
}
Polynomial::~Polynomial()
{
	delete [] coeff;
}
Polynomial::operator+(const Polynomial &q) const
{
	Polynomial r;
	int i;
	if(n==q.n)
	{
		for(i=n;i>=0;i--)
			if((coeff[i]+q.coeff[i])!=0)
				break;
		r.n=i;
	}
	else
		r.n=(n>q.n)?n:q.n;
	
	for(int j=0;j<r.n+1;j++)
			r.coeff[j]=coeff[j]+q.coeff[j];

	return r;
}
Polynomial::operator-(const Polynomial &q) const
{
	Polynomial r(q);
	for(int i=0;i<r.n+1;i++)
		r.coeff[i]=-r.coeff[i];
	return p+r;
}
Polynomial::operator*(const Polynomial &q) const
{
	Polynomial r(n+q.n);
	for(int i=0;i<n+1;i++)
		for(int j=0;j<q.n+1;j++)
			r.coeff[i+j]+=coeff[i]*q.coeff[j];
	return r;
}

Polynomial::operator/(const Polynomial &q) const
{
	if(n<q.n)
	{
		Polynomial r(0);
		return r;
	}
	else
	{
		Polynomial r(n-q.n);
		r.coeff[r.n]=coeff[n]/q.coeff[q.n];
		return (r+(*this-(r*q))/q);
	}
}
