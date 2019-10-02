//les fonctions du programme
#include"liste.h"
#include"alg_ord.h"
#include<iostream>
#include<conio.h>
using namespace std;
//fonction de repture de l'execution
void sleep(unsigned long int n)
{unsigned i = 0;
 unsigned long int max = n * 100000;
 do{i++;} while(i <= max);
}
//fonction remplissage de la liste
void remplissage(liste&l)
{	cout<<endl<<"Saisissez la liste de vos processus :"<<endl;
   cin>>l;
}
//debut de programme
void debut()
{system("color 79");
cout<<"                                  BIENVENUE";
sleep(3000);
system("color 72");
cout<<endl<<endl<<endl<<endl<<endl<<"      Projet Systeme d'exploitation I ";
sleep(1000);
system("color 7c");
cout<<endl<<endl<<"                       Les Algorithmes d'Ordonnancement des Processus";
sleep(500);
system("color 7e");
cout<<endl<<endl<<"                                                                     V 1.0"<<endl;
sleep(1000);
system("color 7c");
cout<<endl<<endl<<endl<<endl<<"                                          Realise par:";	
sleep(1000);
system("color 72");
cout<<endl<<endl<<"                                                   DAII Chakib";
sleep(100);
cout<<endl<<endl<<"                                                   MAAROUFI Fares";
sleep(1000);
system("color 7c");
cout<<endl<<endl<<endl<<"                                                             PREPA-A2-02";
sleep(500);
system("color 7e");
sleep(500);
system("color 7f");
sleep(500);
system("color 79");
sleep(500);
system("color 79");
sleep(500);
system("color 7f");
sleep(500);
system("color 7e");
sleep(500);
system("color 7c");
sleep(500);
system("color 72");
sleep(500);
system("color 7c");
sleep(500);
system("color 72");
sleep(500);
system("color 7c");
sleep(500);
system("color 72");
sleep(500);
system("color 7c");
sleep(500);
system("color 7e");
cout<<endl<<endl<<endl<<"                                     Appuyer sur une touche pour continuer ^_^";
getch();
system("cls");
for(int i=0;i<=100;i++)
{system("color 7c");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                                               Loading  "<<i<<"%";
	i++;
	system("cls");
	sleep(100);
}
sleep(500);
system("cls");
system("color 7f");
}
//corp du programme
void corp()
{system("MODE CON: COLS=80 LINES=80");
system("color 70");
saisie:system("cls");
liste l;
remplissage(l);
debut:system("cls");
int c=1;
while(c==1)
{cout<<endl<<"Choisissez l'algorithme d'ordonnancement ou une autre option:(1-2-3-4-5-6)"<<endl<<endl<<endl<<"   1.FIFO (First In First Out)"<<endl<<"   2.SJF(Short Job First)"<<endl<<"   3.RR(Round Robin)"<<endl<<"   4.SRT(Short Remining Time)"<<endl<<"   5.Resaisir la liste"<<endl<<"   6.Quitter"<<endl;
sleep(5000);
cin>>c;
while((c<1)&&(c>6))
{system("cls");
cout<<"Saisissez un nombres compris entre 1 et 6 selon les choix svp"<<endl;
cout<<"1.FIFO (First In First Out)"<<endl<<"2.SJF(Short Job First)"<<endl<<"3.RR(Round Robin)"<<endl<<"4.SRT(Short Remining Time)"<<endl<<"5.Resaisir la liste"<<endl<<"6.Quitter"<<endl;
cin>>c;
};
if(c==6)goto quit;
else if(c==5)goto saisie;
system("cls");
cout<<"la liste saisie:"<<endl;
cout<<l;
cout<<endl<<endl<<endl<<"                                     Appuyer sur une touche pour continuer ^_^";
getch();
system("cls");
cout<<"la liste saisie:"<<endl;
cout<<l;
switch(c)
{case 1:{cout<<endl<<"FIFO (First In First Out) :"<<endl;FIFO(l);}break;
case 2:{cout<<endl<<"SJF(Short Job First) :"<<endl;SJF(l);}break;
case 3:{cout<<endl<<"RR(Round Robin) :"<<endl;int a=RR(l);}break;
case 4:{cout<<endl<<"SRT(Short Remining Time) :"<<endl;SRT(l);}break;
case 5:{goto saisie;}break;
case 6:{goto quit;}break;
}
char c1;
cout<<endl<<"Voulez-vous tester un autre algorithme ? (O/N)"<<endl;
cin>>c1;
while((c1!='O')&&(c1!='N')&&(c1!='o')&&(c1!='n'))
{cout<<"Saisie non valide ('O': Oui/'N': Non) !"<<endl;
cin>>c1;};
if((c1=='o')||(c1=='O'))goto debut;
else{cout<<endl<<"Voulez-vous resaisir la liste ? (O/N)"<<endl;
cin>>c1;
while((c1!='O')&&(c1!='N')&&(c1!='o')&&(c1!='n'))
{cout<<"Saisie non valide ('O': Oui/'N': Non) !"<<endl;
cin>>c1;};
if((c1=='o')||(c1=='O'))goto saisie;
else if((c1=='n')||(c1=='N')){ cout<<endl<<"Donc vous voulez quitter ^_^";sleep(1000);goto quit;}}
}
quit:system("cls");
}
//fin programme
void fin()
{cout<<endl<<endl<<"                                ^_^ MERCI ^_^";
	system("color 79");sleep(75);system("cls");
cout<<endl<<endl<<endl<<"                                ^_^ MERCI ^_^";
	system("color 72");sleep(75);system("cls");
cout<<endl<<endl<<endl<<endl<<"                                ^_^ MERCI ^_^";
	system("color 7c");sleep(75);system("cls");
cout<<endl<<endl<<endl<<endl<<endl<<"                                ^_^ MERCI ^_^";
	system("color 7e");sleep(75);system("cls");
cout<<endl<<endl<<endl<<endl<<endl<<endl<<"                                ^_^ MERCI ^_^";
	system("color 7c");sleep(75);system("cls");
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                ^_^ MERCI ^_^";
	system("color 7c");sleep(75);system("cls");
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                ^_^ MERCI ^_^";
	system("color 7e");sleep(75);system("cls");
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                ^_^ MERCI ^_^";
	system("color 7c");sleep(75);system("cls");
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                ^_^ MERCI ^_^";
	sleep(3000);
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                 A bientot";
	system("color 72");sleep(75);system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                 A bientot";
	system("color 7c");sleep(75);system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                 A bientot";
	system("color 7e");sleep(75);system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                 A bientot";
	system("color 7e");sleep(75);system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                 A bientot";
	system("color 7e");sleep(75);system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                 A bientot";
	system("color 7c");sleep(75);system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                 A bientot";
	system("color 72");sleep(75);system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                 A bientot";
	system("color 79");sleep(75);system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                 A bientot";
	system("color 7f");sleep(75);system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                 A bientot";
	system("color 79");sleep(75);system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                 A bientot";
	sleep(100);
	exit (-1);
}