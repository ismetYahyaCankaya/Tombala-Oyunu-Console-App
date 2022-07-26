#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <algorithm> 
#include <windows.h>
using namespace std;
int main() {
	int torba_tas[90],sayac=0,sayacIndex=0,oyuncu_sayi,kartIndex_sayac=0,esit_dizi_index_1=0;
	bool kontrol,eslesme=true;
	for(int x=0; x<90; x++){torba_tas[x]=x+1;}				
		srand(time(NULL));	
		random_shuffle(torba_tas,torba_tas+90);
	cout<<"Kac Oyuncu Ile Oynamak Istersiniz: ";
	cin>>oyuncu_sayi;
	cout<<endl;
	int kart_tas[oyuncu_sayi][90];
	int kartIndex[oyuncu_sayi][12];
	int esitDizi[oyuncu_sayi*12][2];
	srand(time(NULL));
	for(int j=0; j<oyuncu_sayi; j++)
	{
		for(int l=0; l<90; l++)
		{
			kart_tas[j][l]=l+1;
		}
		random_shuffle(kart_tas[j],kart_tas[j]+90);
	}
	
	for(int j=0; j<oyuncu_sayi; j++)
	{
		for(int l=0; l<12; l++)
		{
			kartIndex[j][l]=l+1;
		}
		random_shuffle(kartIndex[j],kartIndex[j]+12);
	}
	
		
	for(int p=0; p<90; p++)
	{
	for(int i=0; i<oyuncu_sayi; i++)
	{
		for(int c=0; c<4; c++){if(i!=0){cout<<"\t";}}
		cout<<"Oyuncu "<<i+1<<endl;
		for(int e=0; e<i*4; e++){if(i!=0){cout<<"\t";}}
		for(int a=1; a<=13; a++)
		{	
			cout<<" --"; 
			if(a==13)
			{ 
				cout<<endl;
					if(sayac<3)
					{
						for(int n=0; n<i*4; n++){cout<<"\t";}
							
							for(int h=sayacIndex; h<sayacIndex+4; h++)
								{
								if(kart_tas[kartIndex_sayac][h]==torba_tas[p-1])
								{
									esitDizi[esit_dizi_index_1][0]=kartIndex_sayac;
									esitDizi[esit_dizi_index_1][1]=h;
									esit_dizi_index_1++;
									}
								}
						
						for(int b=0; b<14; b++)
						{				
							kontrol=true;							
							for(int d=sayacIndex; d<sayacIndex+4; d++)
							{
								if(b==kartIndex[kartIndex_sayac][d])
									{
												for(int v=0; v<esit_dizi_index_1; v++)
												{		
													if(esitDizi[v][0]==kartIndex_sayac && esitDizi[v][1]==d)
													{												
													cout<<"| *";
													eslesme=false;
													}	
												}
										if(eslesme)
										{
											if(kart_tas[kartIndex_sayac][d]<10){cout<<"| "<<kart_tas[kartIndex_sayac][d];}
											else{cout<<"|"<<kart_tas[kartIndex_sayac][d];}
										}
											kontrol=false;
											eslesme=true;
									}
							}
							if(kontrol){cout<<"|  ";}
						}
					}
				sayac++;
				if(sayac<4){ a=0; sayacIndex+=4;  cout<<endl; }
				for(int m=0; m<i*4; m++)
				{	cout<<"\t"; }
			}
								
	}
		sayac=0;sayacIndex=0;kartIndex_sayac++;

	}
	cout<<"\n\nTas Cekiliyor..."<<endl;
	Sleep(2000);
	cout<<"Cekilen Tas: "<<torba_tas[p];
	Sleep(1000);
	system("cls");

	kartIndex_sayac=0;	
}

}
