/*
*
* 	Caeser Cipher Implementation
*
* 	Created by Peter Hudson and Aakash Sunil
*
*/

#include<iostream>
 using namespace std;
 int main(void)
 {
 	char PT[30],CT[30];
 	char arr[26];
 	int k,i,j;
 	for(k=65,i=0;k<=90;k++,i++)
 		arr[i]=char(k);
 	cout<<"\tMenu\n1. Encrypt\t2.Decrypt"<<endl;
 	cout<<"Enter your choice: ";
 	cin>>k;
 	switch(k)
 	{
 		case 1: cout<<"Encryption "<<endl;
 				fflush(stdin);
 				cout<<"Enter the Plain text(All Capital Letters): ";
 				cin.getline(PT,30);
 				cout<<"Enter the number of places skipped(3 for Caesar): ";
 				cin>>k;
 				i=0;
 				while(PT[i]!='\0')
 				{
 					for(j=0;j<26;j++)
 						if(arr[j]==PT[i])
 							break;
 					j+=k;
 					if(j>25)
 						j%=26;
 					CT[i]=arr[j];
 					i++;
				}
				CT[i]='\0';
				cout<<"Ciphered Text: "<<CT<<endl;
 				break;
 		case 2: cout<<"Decryption "<<endl;
 				fflush(stdin);
 				cout<<"Enter the Cipher text(All Capital Letters): ";
 				cin.getline(CT,30);
 				cout<<"Enter the number of places skipped(3 for Caesar): ";
 				cin>>k;
 				i=0;
 				while(CT[i]!='\0')
 				{
 					for(j=0;j<26;j++)
 						if(arr[j]==CT[i])
 							break;
 					j-=k;
 					if(j<0)
 						j+=26;
 					PT[i]=arr[j];
 					i++;
				}
				PT[i]='\0';
				cout<<"Deciphered text: "<<PT<<endl;
 				break;
 		default: cout<<"Wrong Choice!!! Try again."<<endl;
 				break;
 	}
}
