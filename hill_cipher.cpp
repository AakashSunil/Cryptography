/*
*
*	Hill Cipher Implementation - Encryption Only
*
*	Created by Peter Hudson and Aakash Sunil
*
*/

#include<iostream>
#include<cstring>
 using namespace std;
 int main(void)
 {
 	enum alphabet{A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};
 	char PT[30],CT[30];
 	char arr[26];
 	int k,i,j,l,len;
 	for(k=65,i=0;k<=90;k++,i++)
 		arr[i]=char(k);
 	cout<<"Enter the number of letters grouped: ";
 	cin>>j;
 	int key[j][j],ciphertext[j],plaintext[j];
 	cout<<"Enter the key matrix: "<<endl;
 	for(i=0;i<j;i++)
 		for(k=0;k<j;k++)
 			cin>>key[i][k];		
 	cout<<"\tMenu\n1. Encrypt\t2.Decrypt"<<endl;
 	cout<<"Enter your choice: ";
 	cin>>k;
 	switch(k)
 	{
 		case 1: cout<<"Encryption "<<endl;
 				fflush(stdin);
 				cout<<"Enter the Plain text: ";
 				cin.getline(PT,30);
 				len=strlen(PT);
 				//cout<<len<<endl;
 				if((len%j)>0)
 				{
 					cout<<"Hi";
 					k=j-(len%j);
					for(i=len;i<len+k;i++)
						PT[i]='X';	
					PT[i]='\0';
				}
				len=strlen(PT);
 				//cout<<len<<endl;
				i=0;
 				while(PT[i]!='\0')
 				{
 					for(k=0;k<j;k++)
 						ciphertext[k]=plaintext[k]=0;
 					for(k=i,l=0;k<i+j;k++,l++)
 						{
						 plaintext[l]=(int)(PT[k])-65;
						 //cout<<plaintext[l]<<" ";
						}
 					for(k=0;k<j;k++)
 						for(l=0;l<j;l++)
						 	{
							 ciphertext[k]+=(key[k][l]*plaintext[l]);
							 //cout<<ciphertext[k]<<" ";
							}
					for(k=0;k<j;k++)
						{
							ciphertext[k]%=26;
							//cout<<ciphertext[k]<<" ";
						}
					for(k=i,l=0;k<i+j;k++,l++)
 						CT[k]=arr[ciphertext[l]];
					i+=j;
				}
				CT[i]='\0';
				cout<<"Ciphered Text: "<<CT<<endl;
 				break;
 		/*case 2: cout<<"Decryption "<<endl;
 				fflush(stdin);
 				cout<<"Enter the Cipher text: ";
 				cin.getline(CT,30);
				cout<<"Deciphered text: "<<PT<<endl;
 				break;*/
 		default: cout<<"Wrong Choice!!! Try again."<<endl;
 				break;
 	}
}
