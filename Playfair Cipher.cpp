/*
*
*	PlayFair Cipher Implementation
*
*	Done by Aakash Sunil and Peter Hudson 
*
*/

#include<iostream>
#include<string.h>
using namespace std;
class playfaircipher
{
	string key,message;
	char a[26];
	int e;
	public:
			char matrix[5][5];
			void read();
			void creategrid(string);
			void displaygrid();
			void encrypt(string);
			void decrypt(string);
};
void playfaircipher::read()
{
	cout<<"Encrypt(1) or Decrypt(0)"<<endl;
	cin>>e;
	if(e==1)
	{
		cout<<"Enter the Plain Text"<<endl;
		cin>>message;
		encrypt(message);
	}
	else
	{
		cout<<"Enter the Cipher Text"<<endl;
		cin>>message;
		decrypt(message);
	}
}
void playfaircipher::creategrid(string k)
{
	for(int i=0;i<25;i++)
	{
		a[i]='\0';
	}
	int l,d=0,check=0;
	l=k.length();
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<25;j++)
		{
			if(k[i]==a[j])
			{
				check=1;	
				break;
			}
			else
				check=0;
		}
		if(check==0)
		{
			a[d]=k[i];
			d++;
		}
		else
			continue;		
	}
	char b='a';
	check=0;
	int s=0;
	for(int i=0;i<26;i++)
	{
		i=s;
		if(a[i]=='\0')
		{
			for(int j=0;j<i;j++)
			{
				if(b=='j')
				{
					b='i';
					b+=2;
				}
				if(b==a[j])
				{
					s=i;
					check=1;
					break;
				}
				else
					check=0;				
			}
			if(check==0)
			
				a[i]=b;
			b++;	
			check=0;
		}
		else
		{
			s++;
			continue;
		}
	}
	int p=0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			matrix[i][j]=a[p];
			p++;
		}
	}
}
void playfaircipher::displaygrid()
{
	cout<<endl<<"Key Matrix"<<endl;
	cout<<"---------------------"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"| ";
		for(int j=0;j<5;j++)
		{
			cout<<matrix[i][j]<<" | ";
		}
		cout<<endl<<"---------------------"<<endl;
	}
	cout<<endl<<endl;
}
void playfaircipher::encrypt(string msg)
{
	int l,l1,i=0,count=0,j=0;
	l=msg.length();
	string temp;
	for(int i=0;i<=l;i++)
	{
		if(msg[i]=='j')
			msg[i]='i';
	}
	for(i=0;i<l;)
	{
		if(msg[i]==msg[i+1])
		{
			count++;
			temp[j]=msg[i];
			temp[j+1]='x';
			j+=2;i++;
		}
		else
		{
			temp[j]=msg[i];
			temp[j+1]=msg[i+1];
			i+=2;j+=2;
		}
	}
	if((l+count)%2!=0)
		j--;
	l1=j;
	if(j%2!=0)
	{
		temp[j]='x';
		temp[j+1]='\0';
		j++;
	}
	l1=j;
	cout<<endl<<"The Plain Text is : ";
	for(int i=0;i<l1;i++)
	{
		if(i%2==0)
			if(i==0)
				i=0;
			else
				cout<<" ";
		cout<<temp[i];
	}
	char ct[l1];
	int r1,r2,c1,c2;
	int k1;
	for(k1=0;k1<l1;++k1)
	{
		for(int i=0;i<5;++i)
		{
			for(int j=0;j<5;++j)
			{
				if(matrix[i][j]==temp[k1])
				{
					r1=i;
					c1=j;
				}
				else
				if(matrix[i][j]==temp[k1+1])
				{
					r2=i;
					c2=j;
				}
			}
		}
	if(r1==r2)
	{
		ct[k1]=matrix[r1][(c1+1)%5];
		ct[k1+1]=matrix[r1][(c2+1)%5];
	}
	else
	if(c1==c2)
	{
		ct[k1]=matrix[(r1+1)%5][c1];
		ct[k1+1]=matrix[(r2+1)%5][c1];
	}
	else
	{
		ct[k1]=matrix[r1][c2];
		ct[k1+1]=matrix[r2][c1];
	}
	k1=k1+1;
	}
	cout<<endl<<"The Cipher text is: ";
	for(i=0;i<l1;i++)
	{
		if(i%2==0)
			if(i==0)
				i=0;
			else
				cout<<" ";
		cout<<ct[i];
	}	
	exit(0);
}
void playfaircipher::decrypt(string msg)
{
	int l,l1,i=0,count=0,j=0;
	l=msg.length();
	string msg1,temp;
	for(int i=0;i<=l;i++)
	{
		if(msg[i]=='j')
			msg[i]='i';
	}
	for(i=0;i<l;)
	{
		if(msg[i]==msg[i+1])
		{
			temp[j]=msg[i];
			temp[j+1]='x';
			j+=2;i++;
		}
		else
		{
			temp[j]=msg[i];
			temp[j+1]=msg[i+1];
			i+=2;j+=2;
		}
		
	}
	j--;l1=j;
	if(j%2!=0)
	{
		temp[j+1]='x';
		temp[j+2]='\0';
	}
	j++;l1=j;
	cout<<endl<<"The Cipher Text is:";
	for(int i=0;i<l1;i++)
	{
		if(i%2==0)
			if(i==0)
				i=0;
			else
				cout<<" ";
		cout<<temp[i];
	}
	char pt[l1];
	int r1,r2,c1,c2;
	int k1;
	for(k1=0;k1<l1;++k1)
	{
		for(int i=0;i<5;++i)
		{
			for(int j=0;j<5;++j)
			{
				if(matrix[i][j]==temp[k1])
				{
					r1=i;
					c1=j;
				}
				else
				if(matrix[i][j]==temp[k1+1])
				{
					r2=i;
					c2=j;
				}
			}
		}
	if(r1==r2)
	{
		if((c1-1)<0)
		c1=5;
		if((c2-1)<0)
		c2=5;
		pt[k1]=matrix[r1][(c1-1)%5];
		pt[k1+1]=matrix[r1][(c2-1)%5];
	}
	else
	if(c1==c2)
	{
		if((r1-1)<0)
			r1=5;
		if((r2-1)<0)
			r2=5;
		pt[k1]=matrix[(r1-1)%5][c1];
		pt[k1+1]=matrix[(r2-1)%5][c1];
	}
	else
	{
		pt[k1]=matrix[r1][c2];
		pt[k1+1]=matrix[r2][c1];
	}
	k1=k1+1;
	}
	cout<<endl<<"The Plain text is: ";
	for(int i=0;i<l1;++i)
	{
		if(i%2==0)
			if(i==0)
				i=0;
			else
				cout<<" ";
		cout<<pt[i];
	}
	exit(0);
}
int main()
{
	int w;
	playfaircipher a;
	string k,msg;
	cout<<"Enter Key"<<endl;
	cin>>k;
	a.creategrid(k);
	a.displaygrid();
	a.read();
}
