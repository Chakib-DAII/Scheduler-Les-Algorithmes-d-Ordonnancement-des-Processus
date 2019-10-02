#include<iostream>
using namespace std;
//les classe
//classe processus
class proc
{  public:
	string nom;
	int t_arr;
   int t_exe;
  //constructeurs
   proc(){}
   proc(string a,int b,int c)
   {this->nom=a;
   this->t_arr=b;
   this->t_exe=c;}
   //surcharge de l'opérateur de l'affichage <<    
friend ostream& operator<<(ostream&o,const proc &p)
{ o<<"  |    "<<p.nom<<"	  |            "<<p.t_arr<<"              |          "<<p.t_exe<<"           |  "<<endl;
  o<<"  ====================================================================  "<<endl;
   return o;
}
//surcharge de l'opérateur de saisie >>
friend istream& operator>>(istream&i,proc&p)
{   cout<<"Nom : ";i>>p.nom;
	cout<<"Temps d'arrivee : ";i>>p.t_arr;
	cout<<"Temps d'execution : ";i>>p.t_exe;
	return i;
}
//surcharge de l'operateur =
void operator=(const proc &p)
{	nom=p.nom;
   	t_arr=p.t_arr;
      t_exe=p.t_exe;
}
};
//classe cellule
class cell
{public:
 proc pr;
 bool finp;
 cell*suiv;
//constructeurs
cell() {}
cell(const proc &p)
   {  pr=p;
      suiv=NULL;
      finp=(pr.t_exe==0);
   }
cell(string a,int b,int c)
   {  proc k(a,b,c);
      pr=k;
      finp=false;
      suiv=NULL;
	  finp=(pr.t_exe==0);
   }
};
//classe liste
class liste
{  public:
cell *cel;
//constructeurs
   liste()
 {cel=NULL;}
//surcharge de l'opérateur = entre deux listes
void operator=(const liste&l)
{cell *k=l.cel;
      while(k!=NULL)
      {  ajout_fin(k->pr);
         k=k->suiv;}
}
 //methode qui verifie l'existance d'un processus 
bool Exist(proc p)
   {  cell*k=cel;
      while(k!=NULL)
      {  if((k->pr).nom==p.nom)
          return true;
         k=k->suiv;
      }
      return false;
   }
 //methode d'ajout à la fin 
void ajout_fin(proc & p)
   {  cell*k=cel;
      if(k==NULL)
       cel=new cell(p);
      else
      {while(k->suiv!=NULL)
            k=k->suiv;
         k->suiv=new cell(p);}
   }
//methode d'ajout à la fin 
void ajout_premier(proc & p)
   {  cell*k=cel;
      if(k==NULL)
       cel=new cell(p);
      else
      {cell*m=new cell(p);
	  m->suiv=k;
	  m=cel;
	  }
   }
//méthode de remplissage de la liste d'attente
void remplissage_liste(const liste&l,int tmp)
 {cell*k=l.cel;
      while(k!=NULL)
	  {if(k->pr.t_arr<=tmp && k->finp==false && Exist(k->pr)==false)
         {  this->ajout_fin(k->pr);}
         k=k->suiv;}
 }
//méthode qui fait une copie d'une liste
 void copie_liste(const liste&l)
   {cel=NULL;
      if(l.cel!=NULL)
        {cel=new cell(l.cel->pr.nom,l.cel->pr.t_arr,l.cel->pr.t_exe);
         cell*k=cel;
         cell*p=l.cel->suiv;
         while(p!=NULL)
           {k->suiv=new cell(p->pr.nom,p->pr.t_arr,p->pr.t_exe);
            k=k->suiv;
            p=p->suiv;
           }
         }
   }
//methode de calcul de nombre de processus
int Nb_Proc()
   {  int i=0;
      cell*k=cel;
      while(k!=NULL)
      {  i++;
         k=k->suiv;
      }
      return i;
   }
//méthode pour la suppression du premier élément de la liste
void supp_premier()
   {  if(cel!=NULL)
      {  if(cel->suiv==NULL)
              {  delete cel;cel=NULL;}
         else
         {  cell*k=cel;
            cel=cel->suiv;
            delete k;}
      }
   }
//méthode de suppression du dernier élément 
void supp_dernier()
   {  if(cel!=NULL)
      {  if(cel->suiv==NULL)
         {  delete cel;cel=NULL;}
         else
            {  cell*k=cel;
               while(k->suiv->suiv!=NULL)
                      {  k=k->suiv;}
               delete k->suiv->suiv;
               k->suiv->suiv=NULL;}
      }
   }
//méthode de suppression de tous les processus
void supp_tt()
   {  cell*p=cel;
      while(p!=NULL)
      {  cell*k=p;
         p=p->suiv;
         delete k;
      }
      cel=NULL;
   }
//méthode de suppression d'un processus selon son nom
void suppparnom(string s)
   {  if(cel!=NULL)
      {if(cel->pr.nom==s)
         {  if(cel->suiv==NULL)
               {delete cel;
               cel=NULL;}
            else
               {cell*k=cel;
               cel=cel->suiv;
               delete k;}
         }
       else
         {cell*k=cel;
          cell*p=cel->suiv;
          while(cel!=NULL && cel->pr.nom!=s)
              {  k=k->suiv;
               p=p->suiv;
			  }
          if(p->pr.nom==s)
              {k->suiv=p->suiv;
               delete p;}
          }
      }
   }
//méthode qui marque que tous les processus sont finis
  bool tousfinis()
   {  cell*k=cel;
      while(k!=NULL)
      {  if(k->finp==false)
         { return false;}
         k=k->suiv;
	  }
      return true;
   }
//méthode qui marque que tous les processus sont non finis
 void tousnonfinis()
   {  cell*k=cel;
      while(k!=NULL)
         {  k->finp=k->pr.t_exe==0;
            k=k->suiv;
         }
   }
//méthode qui décrémente le temp restant d'exécution d'un processus 
void dec(string &s)
{  cell*k=cel;
      while(k!=NULL)
      {  if(k->finp==false)
         {  if(k->pr.nom==s)
                k->pr.t_exe--;
            if(k->pr.t_exe<=0)
                k->finp=true;
         }
         k=k->suiv;
	  }
}
 //méthode qui retourne le temps d'arrivé d'un processus 
int T_arr(string s)
{  cell*p=cel;
      while(p!=NULL)
      {  if(p->pr.nom==s) return p->pr.t_arr;
         p=p->suiv;
      }
}
//méthode qui retourne le temps d'exe d'un processus 
int T_exe(string s)
{  cell*p=cel;
      while(p!=NULL)
      {  if(p->pr.nom==s) return p->pr.t_exe;
         p=p->suiv;
      }
}
//méthodes de tri de la liste
//méthode de tri de la liste par temps d'arrivé  
void triparTarr()
   {  if(cel!=NULL && cel->suiv!=NULL)
      {  int v;
         do
         {  v=1;
            cell *k=cel;
            cell *m=cel->suiv;
            while(m!=NULL)
			{  if((k->pr.t_arr)>(m->pr.t_arr))
               {  proc aux;
			      aux=k->pr;
                  k->pr=m->pr;
                  m->pr=aux;
                  v=0;
               }
	           k=k->suiv;
               m=m->suiv;
            }
         }while(v==0);
cell *k=cel;
cell *m=cel->suiv;
while(m!=NULL)
 {  if((k->pr).t_arr==(m->pr).t_arr)
        if((k->pr).t_exe>(m->pr).t_exe)        
		       {  proc aux;
			      aux=k->pr;
                  k->pr=m->pr;
                  m->pr=aux;
                }
	           k=k->suiv;
               m=m->suiv;
 }            
}

   }
//méthode de tri de la liste dans l'ordre croissant par temps d'exécution 
void tricparTexe()
   {  if(cel!=NULL && cel->suiv!=NULL)
      {  int v;
         do
         {  v=1;
            cell*k=cel;
            cell*m=cel->suiv;
            while(m!=NULL)
			{  if((k->pr).t_exe>(m->pr).t_exe)
               {  proc aux=k->pr;
                  k->pr=m->pr;
                  m->pr=aux;
                  v=0;
               }
               k=k->suiv;
               m=m->suiv;
            }
         }
         while(v==0);
cell *k=cel;
cell *m=cel->suiv;
while(m!=NULL)
 {  if((k->pr).t_exe==(m->pr).t_exe)
        if((k->pr).t_arr>(m->pr).t_arr)        
		       {  proc aux;
			      aux=k->pr;
                  k->pr=m->pr;
                  m->pr=aux;
                }
	           k=k->suiv;
               m=m->suiv;
 } 
      }
   }
//méthode de tri de la liste dans l'ordre décroissant par temps d'exécution 
void tridecparTexe()
   {  if(cel!=NULL && cel->suiv!=NULL)
      {  int v;
         do
         {  v=1;
            cell*k=cel;
            cell*m=cel->suiv;
            while(m!=NULL)
			{  if((k->pr).t_exe<(m->pr).t_exe)
			   { proc aux=k->pr;
                  k->pr=m->pr;
                  m->pr=aux;
                  v=0;
               }
               k=k->suiv;
               m=m->suiv;
            }
         }
         while(v==0);
      }
   }
//surcharge de l'opérateur d'affichage d'une liste <<
friend ostream& operator<<(ostream&o,liste l)
{  if(l.cel==NULL)
   {  o<<"                   Oups!!   liste est vide!!      "<<endl;}
   else
   {  cell*k=l.cel;
      o<<endl;
      o<<"  ====================================================================  "<<endl;
      o<<"  |      Nom      |     Date d'arrivee        |    Temps d'execution |  "<<endl;
      o<<"  ====================================================================  "<<endl;
      while(k!=NULL)
      {  o<<k->pr;
         k=k->suiv;
      }
   }
   return o;
}
//surcharge de l'opérateur de saisie d'une liste >>
friend istream& operator>>(istream&i,liste&l)
{  int c=1;
   char t='O';
   proc pr;
   cout<<"1er processus :"<<endl;
   i>>pr;
   l.cel=new cell(pr);
   cell *k=l.cel;
   while((t=='O')||(t=='o'))
   {  c++;
      cout<<c<<"eme processus :"<<endl;
      i>>pr;
      if(l.Exist(pr)==false)
	     {k->suiv=new cell(pr);k=k->suiv;}
	  else
	     {cout<<"Procesuss existant! Resaisissez svp ^_^"<<endl;c--;}
      if(c%1==0)
        {cout<<"Voulez-vous ajouter d'autres processus? (O/N)"<<endl;
         cin>>t;
         while((t!='O')&&(t!='N')&&(t!='o')&&(t!='n'))
         {  cout<<"Saisie non valide ('O':oui/'N':non) !"<<endl;
            cin>>t;}
        }
   }
   return i;
}
};
