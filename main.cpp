#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

string ZliczbyNaSlowa(int);
int znajdzK(int); 
int main(int argc, char *argv[])
{
	
	int n=atoi(argv[1]);
	cout<<n<<" ( "<<ZliczbyNaSlowa(n)<<" ) * k = "<<znajdzK(n)<<" ( "<<ZliczbyNaSlowa(znajdzK(n))<<" ) = "<<n*znajdzK(n)<<" ( "<<ZliczbyNaSlowa(n*znajdzK(n))<<" )."<<endl;

}

string ZliczbyNaSlowa(int n)
{
	int x=n;
	string jednosci[]={"jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec"};
	string wyjatki[]={"jedenascie", "dwanascie", "trzynascie", "czternascie", "pietnascie", "szesnascie", "siedemnascie", "osiemnascie", "dziewietnascie"};
	string dziesiatki[]={"dziesiec", "dwadziescia", "trzydziesci", "czterdziesci", "piecdziesiat", "szescdziesiat", "siedemdziesiat", "osiemdziesiat", "dziewiecdziesiat"} ;
	string setki[]={"sto", "dwiescie", "trzysta", "czterysta", "piecset", "szescset", "siedemset", "osiemset", "dziewiecset"};
	string tysiace[]={"tysiac", "tysiecy", "tysiace"};
	string wynik;
	int tab[6];
	
	for(int i=5;i>=0;i--)
		{
		tab[i]=n%10;
		n=n/10;
		}
	if( tab[0]==0 && tab[1]==0 && tab[2]==0 && tab[3]==0 && tab[4]==0 && tab[5]==0 )
		return "zero";
	if( tab[0] > 0 )
		wynik=setki[tab[0]-1]+" ";
	if( tab[0] != 0 && tab[1] == 0 && tab[2] == 0)
		wynik+=tysiace[1]+" ";
	if( tab[1] == 1 && tab[2] != 0)
		wynik+=wyjatki[tab[1]-1]+" "+tysiace[1]+" ";
	else if( tab[1] >= 1 )
	{
		wynik+=dziesiatki[tab[1]-1]+" ";
		if( tab[2] == 0 )
			{
			if( tab[1] == 1 || tab[1] == 5 || tab[1] == 6 || tab[1]== 7 || tab[1] == 8 || tab[1] == 9)
				wynik+=tysiace[1]+" ";
			else
				wynik+=tysiace[2]+" ";
			}
		else if( tab[2] == 1 || tab[2] == 5 || tab[2] == 6 || tab[2] == 7 || tab[2] == 8 || tab[2] == 9)
			wynik+=jednosci[tab[2]-1]+" "+tysiace[1]+" ";
		else
			wynik+=jednosci[tab[2]-1]+" "+tysiace[2]+" ";
		
	}	
	else if( tab[1] == 0 && tab[2] != 0)
	{
		if( tab[2] == 1 && tab[0] == 0 )
			wynik+=tysiace[0]+" ";
		else if( tab[2] == 1 || tab[2] == 5 || tab[2] == 6 || tab[2] == 7 || tab[2] == 8 || tab[2] == 9)
			wynik+=jednosci[tab[2]-1]+" "+tysiace[1]+" ";
		else
			wynik+=jednosci[tab[2]-1]+" "+tysiace[2]+" ";
		
	}

	if( tab[3] != 0 )
		wynik+=setki[tab[3]-1]+" ";

	if( tab[4] == 1 && tab[5]>=1)
		wynik+=wyjatki[tab[5]-1];
	else if( tab[4] == 0 && tab[5]!=0 )
		wynik+=jednosci[tab[5]-1];
	else if(tab[4]!=0)
		{
		wynik+=dziesiatki[tab[4]-1]+" ";
		if(tab[5]!= 0)
			wynik+=jednosci[tab[5]-1];
		}
	
	return wynik;
}

int znajdzK(int n)
{	
int wynik=0;
int tab[64];
tab[0]=1;

for(int i=2;i<=6;i++)
	{
		for(int k=pow(2,i-1);k<pow(2,i);k=k+2)
		{
			tab[k-1]=tab[(k/2)-1]*10;
			tab[k]=tab[(k/2)-1]*10+1;
			if(tab[k-1]%n==0)
				return tab[k-1]/n;
			if(tab[k]%n==0)
				return tab[k]/n;
			
		}
	
	}
	
return wynik;	
	
}
