#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include<conio.h>


float x[100], y[100];
int s[100], sOpt[100], nKota,i;  float e, eOpt;
using namespace std;
// Membangkitkan data kota
// dan koordinatnya secara acak
void BangkitkanDataKota(){
  cout << "Jumlah kota = "; cin >> nKota;
  for(i=0;i<nKota;i++){
     x[i]=(float)(10*rand()/RAND_MAX);
     y[i]=(float)(10*rand()/RAND_MAX);
  }
}
float hitungEnergi(){
  float jarak=0;// inisiasi variabel jarak bernilai nol
  int i;//variabel i dengan tipe integer
  for(i=0;i<nKota-1;i++){//perulangan sebanyak jumlah kota
     float dx=pow(x[s[i]]-x[s[i+1]], 2);//rumus x lalu pow berfungsi untuk dipangkatkan
     float dy=pow(y[s[i]]-y[s[i+1]], 2);//rumus meghitung y sama dengan
     float d=sqrt(dx+dy);//sqrt berfungsi menhitung dari akar x dan y
     jarak=jarak+d;//rumus dan menjadi hasil akhir jarak
   }
 return jarak;//megembalika nilai jarak ke fungsi main
}
// Membangkitkan state awal
// dengan mengurutkan langsung
void BangkitkanStateAwal(){
  for(int i=0;i<nKota;i++) s[i]=i;
      e=hitungEnergi();
}
// State Optimal
void StateOptimal() {
   for(int i=0;i<nKota;i++) sOpt[i]=s[i];
   eOpt=e;
}
// Menampilkan State
void TampilkanState() {
  for(int i=0;i<nKota;i++) cout << sOpt[i] << " ";  cout << "	energi = " << eOpt << endl;
}
// Update state
void UpdateState(){
int k1,k2,i;
for(i=0;i<nKota;i++) s[i]=sOpt[i];
k1=int((nKota-1)*(float)rand()/RAND_MAX);
k2=int((nKota-1-k1)*(float)rand()/RAND_MAX)+k1+1;
int index = 0;

for(i=k1;i<k2;i++){
   s[i]=sOpt[k2-index];
   index++;
}
e=hitungEnergi();
}
int main(){
    int z=1;
    while(z==1){
    system("cls");
	int i, maxIter;  float p, To, Tn, T;
	cout << "jumlah iterasi max = ";
	cin >> maxIter;
	To=0.1; Tn=0.0001;
	BangkitkanDataKota();
	BangkitkanStateAwal();
	StateOptimal();
	TampilkanState();

	for(i=1;i<maxIter;i++){
		UpdateState();
		p=rand();
		if(p<exp(-(e-eOpt)/T)) StateOptimal();
		TampilkanState();
		T=To*(float)pow(Tn/To,(float)i/(float)nKota);
	}
	getch();
    }
}
