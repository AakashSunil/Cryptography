/*
*
*	Diffie-Hellman Implementation
*
*	Created by Aakash Sunil and Peter Hudson
* 
*/

#include<iostream>
#include<cmath>
using namespace std;
class DiffieHellman
{
	public:
			int calc_mod(int,int,int);
			int calc_pri_root(int);
};
int DiffieHellman::calc_mod(int x,int y,int z)
{
	long long int a,w;
	a=(pow(x,y));
	w=a%z;
	return (w);
}
int DiffieHellman::calc_pri_root(int a)
{
	int b[a];
	int i,j,k,ch=0;
	for(i=2;i<a-1;i++)
	{
		for(j=0;j<a-1;j++)
		{
			b[j]=calc_mod(i,j+1,a);
		}
		for(k=0;k<a-1;k++)
		{	
			ch=0;
			for(j=k+1;j<=a-1;j++)
			{
				ch=0;
				if(b[k]==b[j])
				{
					ch=1;	
					break;
				}
				
			}
			if(ch==1)
				break;
		}
		
		if(ch==0)
			cout<<i<<"\t";
	}
}
int main()
{
	DiffieHellman d;
	int k,p,q,a,b,x,y,k1,k2;
	cout<<"Enter Values for prime p: ";
	cin>>p;
	cout<<"Possible Primitive Roots:"<<endl;
	d.calc_pri_root(p);
	cout<<endl<<"Choose any of the primitive roots above : ";
	cin>>q;
	cout<<"Enter values for a,b (privately known numbers):";
	cin>>a>>b;
	x=d.calc_mod(q,a,p);
	y=d.calc_mod(q,b,p);
	k1=d.calc_mod(y,a,p);
	k2=d.calc_mod(x,b,p);
	if(k1!=k2)
		if(k1<0)
			cout<<k2<<" is the shared key"<<endl;
		else
			cout<<k2<<" is the shared key"<<endl;
	else
	{
		k=k1=k2;
		cout<<k<<" is the shared key";
	}
}
