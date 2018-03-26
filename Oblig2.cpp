//  Fil:  FRODEH \ ALG_MET \ EKSEMPEL \ EKS_06.CPP

//        Eksemplet viser bruk av rekursjon for permutering av en array.
//        Egen forklaring p� filen PERMUTERING.HTML.


#include <iostream>
using namespace std;


const int N = 6;                       //  Arrayens lengde.

char arr[N];                            //  Global array av int'er.


bool erKonsonant(char a)
{

char konsonanter[9]={'A', 'E', 'I', 'O', 'U', 'Y','Æ', 'Ø','Å'};
for (int i =0; i<20 ; i++)
  {
    if( a ==konsonanter[i] ) return true;
  }
  return false;
}

bool navnOK(char a[], int len)
{

if (a[0] == a[1]) return false;  //to like i starten

for( int i=1; i < N; i++)   // går igjenom hele arrayen  
 if (!erKonsonant(a[i-1]) && !erKonsonant(a[i]))  // hvis begge er vokaler
  { 
    if(a[i-1]==a[i]) 
       {
         return false;
       }                // hvis de er like return false
    if (i >= 2 && !erKonsonant(a[i-2])             //hvis det er mer enn 2 tidligere og den 3. er vokal return false
       {
         return false;
       }
  }
return true;




}

void display(char a[])  {               //  Viser arrayens innhold.
  cout << "\n";
  for (int i = 0;  i < N;  i ++)
    cout << a[i] << ' ';
}


void bytt(char & a1, char & a2)  {       //  Bytter om to array-elementer.
  int aa = a1;
      a1 = a2;
      a2 = aa;
}


void roterVenstre(char a[], char i)  {   //  Roterer elementer mot venstre.
  int x, k;
  x = a[i];                            //  Tar vare p� f�rste.
  for (k = i+1;  k < N;  k++)          //  Roterer:
    a[k-1] = a[k];
  a[N-1] = x;                          //  Legger f�rst inn bakerst.
}


void perm(int i)  {
  int t;
  if (i == N-1)                        //  N�dd en ny permutasjon:
     display(arr);                     //  Skriver ut arrayens innhold.
  else {                               //  Skal permutere:
     perm(i+1);                        //  Beholder n�v�rende nr.'i'.
	 			                       //    Permuterer resten.
     for (t = i+1; t < N; t++)  {
	     bytt(arr[i], arr[t]);         //  Bytter nr.'i' etter tur med alle
				                       //    de andre etterf�lgende.
	     perm(i+1);                    //  For hver av ombyttene: permuterer
     }                                 //    resten av de N� etterf�lgende.
     roterVenstre(arr, i);             //  Gjenoppretter opprinnelig array.
  } 
}


int main()  {
 // for (int i = 0;  i < N;  i++)        //  Fyller array med: 1, 2, 3, ..., N
 //     arr[i] = 'a'+i;
 cout << "Skriv inn array: ";
  cin >> arr;  



  perm(0);                             //  Lager/skriver permutasjon av ALLE
				                       //    sifrene/arrayelementene.
  cout << '\n';
  display(arr);                        //  Skriver array etter at ferdig (for
  cout << "\n\n";                      //   � se om orginal er gjenopprettet).
  return 0;      
}
