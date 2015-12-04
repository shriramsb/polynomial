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