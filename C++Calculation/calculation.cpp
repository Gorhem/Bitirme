#include <iostream>
#include <stdio.h>
#include<cstdlib>
#include <cctype>
#include <string.h>
#include <sstream> 
#include <algorithm>
using std::cout;
using std::cin;
using namespace std;

int asal2 (int a)
{
 int b;
while(a%2==0){

b=a/2;
a=b;
}
if(a==1){
	a=0;
}
else{
	a=1;
}
  return a;
}



int asal3 (int a)
{
 int b;
while(a%3==0){

b=a/3;
a=b;
}
if(a==1||asal2(a)==0){
	a=0;
}
else{
	a=1;
}
  return a;
}


int main(){
	int x=0;
	cout<<"Enter function number: ";
	cin>>x;
	
	
	
	
	int cases=0;
	cases = x;
	switch (cases){
		
		
		
		case 1: {
			
			
			
		int integer;
		cout<<"Enter digits: ";
		cin>>integer;

		int x=integer;
int u=0;
    	while(x>0){
		x=x/10;
		u++;	}
	

int array[u];
int temmuz;
x=integer;
    
    for(int j=0;j<u;j++){
		
		temmuz=x%10;
		array[j]=temmuz;
		
		
		x=x/10;
		
	}
	
	
		int i;
		int j;
	
		int temp;
	int a=0;
	int ilkkucuk;
	int p=0;
	while(p<(u-1)&&(a!=1)){
		if(array[p]>array[p+1]){
		a=1;
		ilkkucuk=array[p+1];
		int i;
		
		for(int o = p; o > -1; o--)
		{	
		i=p;			
      j = i;
      temp = array[i];
     				
	while (j > 0 && temp >= array[j-1])
      { 
					
         array[j] = array[j-1];
         
         j--;
      }
     
      array[j] = temp;
   }
		
		
		array[p+1]=array[p];
		array[p]=ilkkucuk;
		
		
}
p++;

	}
	
	while(u>0){
   
   cout<<array[u-1];
   u--;
}
    
	
	
		
		break;
	}
			case 2:{
				
			
			
					int a= 0;
				cout<<"Enter a positive integer: ";
		
				cin>>a;
		
		
				cout<<"Factors of "<<a<<" are: ";
							int i=1;
						while(i<=a){
		
					if( a%i==0){
				
						cout<<"\n"<<i;
				
							}
			
							i++;}
		
		
					
					break;
						}
			case 3: {
					
					
					
					
					for(int a=2;;a++){
	if(asal2(a)==0||asal3(a)==0){
		cout<<a<<" ";
		
	}
	
	
	
	
	
	
	}
		
		break;
	}
		
		
			case 4: {
				char kelime[5000];
				char kelime2[5000];
				cout<<"Enter string and substring respectively: ";
				cin>>kelime;
				cin>>kelime2;
				
				
				char *a;
			string var="True!";
			string yok="False!";
			a= strstr(kelime,kelime2);
			if (a!=NULL)
			cout<<var;
			else
			cout<<yok;
				
				
			
				
				
				
 
				
				
				
				
				
				
				break;
			}
			
		
		
		
		
			case 5: {
			
			
				char array[5];
				int f= 0;
				int k=1;
				string str;
				cout<<"Enter a string of five distinct characters: ";
				cin >>str;
				
				int x=str.length();
				
				
				for(int i=0;i<5;i++){
					while(k<5){
					
					if(array[i]==array[k]){
					
					f++;
					}
					k++;
				}
				}
				if (x!=5){
				
   				cout<<"Please try with five distinct characters.";
   			}
   				
   			else if (f>=1)
   				cout<<"Please try with five distinct characters.";
   				
				else{
				
					cout<<"This is end.";
		}
			
			
			
			
				break;
			}
		
		
		
		
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	return 0;
}











