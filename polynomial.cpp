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
Polynomial::Polynomial(const int a)
{
	n=a;
	if(n>=0)
	{
		coeff=new float[a+1];
		for(int i=0;i<a+1;i++)
			coeff[i]=0;
	}
	if(n=-1)
	{
		coeff=new float[1];
		coeff[0]=0;
	}
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
Polynomial Polynomial::operator+(const Polynomial &q) const
{
	Polynomial r;
	int i;
	if(n==q.n)
	{
		for(i=n;i>=0;i--)
			if((coeff[i]+q.coeff[i])!=0)
				break;
		r.n=i;
		if(r.n!=-1)
		{
			r.coeff=new float[r.n+1];
			for(int j=0;j<r.n+1;j++)
				r.coeff[j]=coeff[j]+q.coeff[j];
		}
		else
		{
			r.coeff=new float[1];
			r.coeff[0]=0;
		}
	}
	else if(n>q.n)
	{
		r.n=n;
		r.coeff=new float[r.n+1];
		for(i=0;i<q.n+1;i++)
			r.coeff[i]=coeff[i]+q.coeff[i];
		for(;i<n+1;i++)
			r.coeff[i]=coeff[i];
	}
	else
	{
		r.n=q.n;
		r.coeff=new float[r.n+1];
		for(i=0;i<n+1;i++)
			r.coeff[i]=coeff[i]+q.coeff[i];
		for(;i<q.n+1;i++)
			r.coeff[i]=q.coeff[i];
	}
	
	return r;
}
Polynomial Polynomial::operator-(const Polynomial &q) const
{
	Polynomial r(q);
	for(int i=0;i<r.n+1;i++)
		r.coeff[i]=-r.coeff[i];
	return p+r;
}
Polynomial Polynomial::operator*(const Polynomial &q) const
{
	if(n==-1 || q.n==-1)
	{
		Polynomial r(-1);
		return r;
	}
	else
	{
		Polynomial r(n+q.n);
		for(int i=0;i<n+1;i++)
			for(int j=0;j<q.n+1;j++)
				r.coeff[i+j]+=coeff[i]*q.coeff[j];
		return r;
	}
}
Polynomial Polynomial::operator/(const Polynomial &q) const
{
	if(q.n==-1)
	{
		Polynomial r(-1);
		return r;	//returns zero polynomial if division is not defined
	}
	else if(n<q.n)
	{
		Polynomial r(-1);
		return r;
	}
	else
	{
		Polynomial r(n-q.n);
		r.coeff[r.n]=coeff[n]/q.coeff[q.n];
		return (r+(*this-(r*q))/q);
	}
}
Polynomial Polynomial::operator%(const Polynomial &q) const
{
	return (*this-((*this)/q)*q);	//returns zero polynomial if division is not defined
}
int Polynomial::getn()
{
	return n;
}
Polynomial Polynomial::operator=(const Polynomial &c)
{
	n=c.n;
	delete [] coeff;
	if(c.n==-1)
	{
		coeff=new float[1];
		coeff[0]=0;
	}
	else
	{
		coeff=new float[n+1];
		for(int i=0;i<n+1;i++)
			coeff[i]=c.coeff[i];
	}
	return c;

}
Polynomial Polynomial::derivative() const
{
	if(n==-1)
		Polynomial r(-1);
	else
	{
		Polynomial r(n-1);
		for(int i=0;i<n;i++)
			r.coeff[i]=coeff[i+1]*(i+1);
	}
	return r;
}
Polynomial Polynomial::integral() const
{
	if(n==-1)
	{
		Polynimial r(-1);
		return r;
	}
	else
	{
		Polynomial r(n+1);	//constant of integration is zero always
		for(int i=0;i<n+1;i++)
			r.coeff[i+1]=coeff[i]/(i+1);
		return r;
	}
}
float Polynomial::value(const float a) const
{
	float b=0,expa=1;
	for(int i=0;i<n+1;i++)
	{
		b+=coeff[i]*expa;
		expa*=a;
	}
	return b;
}
void Polynomial::print() const
{
	if(n==-1)
		cout<<0;
	else
	{
		cout<<coeff[0];
		for(int i=1;i<n+1;i++)
			if(coeff[1]!=0)
				cout<<" + "<<coeff[i]<<"*x^"<<i;
	}
}
