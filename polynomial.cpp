#include "polynomial.h"

void Polynomial::read()
{
	cin>>n;
	coeff=new int[n+1];
	for(int i=0;i<n+1;i++)
		cin>>coeff[i];
}