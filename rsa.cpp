/*
*	RSA Algorithm Implementation
*
*	Done by Aakas Sunil and Peter Hudson
*
*/

#include<iostream>
#include<string>
using namespace std;
class RSA
{
	public:
			int pr,m,n,e,d,c;
			int check();
			void encrypt();
			void decrypt();
			int gcd(int,int);
};
int RSA::gcd(int a,int b)
{
	int gcd,i;
	for(i=1;i<=a&&i<=b;++i)
	{
		if(a%i==0&&b%i==0)
		{
			gcd=i;
		}
	}
	return gcd;
}
int RSA::check()
{
	int g,i,j,ch=1;
	for(i=2;i<pr;i++)
	{
		ch=1;
		g=gcd(pr,i);
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				ch=0;
				break;
			}
		}
		if(g==1&&ch==1)
			cout<<i<<"\t";
	}
	cout<<endl;
}
void RSA::encrypt()
{
	int i;
	c=1;
	for(i=0;i<e;i++)
		c=c*m%n;
	c=c%n;
	cout<<"Encryted value: "<<c<<endl;
}
void RSA::decrypt()
{
	int i;
	m=1;
	for(i=0;i<d;i++)
		m=m*c%n;
	m=m%n;
	cout<<"Decrypted Value: "<<m<<endl;
}
int main()
{
	RSA ob;
	int p,q,r;
	cout<<"Enter two primes"<<endl;
	cin>>p>>q;
	ob.n=p*q;
	ob.pr=(p-1)*(q-1);
	cout<<"e value possibilities"<<endl;
	ob.check();
	cout<<endl<<endl<<"Choose any of the above as e Value:";
	cin>>ob.e;
	ob.d=1;
	do
	{
		r=(ob.d*ob.e)%ob.pr;
		ob.d++;
	}while(r!=1);
	ob.d=ob.d-1;
	cout<<"Public Key - ("<<ob.e<<" , "<<ob.n<<")"<<endl;
	cout<<"Private Key - ("<<ob.d<<" , "<<ob.n<<")"<<endl;
	cout<<"Enter PlainText:";
	cin>>ob.m;
	ob.encrypt();
	cout<<endl;
	cout<<"Enter Cipher Text:";
	cin>>ob.c;
	ob.decrypt();
	cout<<endl;
}
