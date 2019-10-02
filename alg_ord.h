#include<iostream>
using namespace std;
void FIFO(liste l)
{liste ll;
ll.copie_liste(l);
	ll.triparTarr();
cell*k=ll.cel;
bool test=false;
   int tmp=0;
   int i=0;
   string nom[50];
   int t_att[50];
   int t_trai[50];
  cout<<"_____________________________Diagramme de GANTT________________________________"<<endl<<endl;
cout<<".*"<<tmp<<"*.";
  while(k!=NULL)
   {	if((k->pr).t_arr<=tmp)
       {for(int j=tmp;j<tmp+(k->pr.t_exe);j++)
			cout<<"("<<k->pr.nom<<").";
   tmp+=k->pr.t_exe;
   cout<<"*"<<tmp<<"*.";
   nom[i]=k->pr.nom;
   t_att[i]=tmp-k->pr.t_arr-k->pr.t_exe;
   t_trai[i]=tmp-k->pr.t_arr;
   i++;
   
   }
      else
	  {   for(int j=tmp;j<tmp+(k->pr.t_arr);j++)
			   cout<<"__.";
               test=true;
		  for(int j=(k->pr.t_arr);j<(k->pr.t_arr)+(k->pr.t_exe);j++)
               cout<<"("<<k->pr.nom<<").";
	    tmp=k->pr.t_arr+k->pr.t_exe;
		cout<<"*"<<tmp<<"*.";
	    nom[i]=k->pr.nom;
        t_att[i]=tmp-k->pr.t_arr-k->pr.t_exe;
        t_trai[i]=tmp-k->pr.t_arr;
        i++;
      }
      k=k->suiv;
   }
   cout<<endl<<"_______________________________________________________________________________"<<endl;
   cout<<"RQ: Chaque .(proc). est une unitee de temps executee par ce processus "<<endl<<"  Chaque .*inst*. est l'instant courant"<<endl;
   if(test)cout<<"  Chaque .__. est une unitee de temps non executee "<<endl;
  cout<<"_______________________________________________________________________________"<<endl<<endl;  
   cout<<"  ====================================================================  "<<endl;
      cout<<"  |      Nom      |      Temps d'attente      |  Temps de traitement |  "<<endl;
      cout<<"  ====================================================================  "<<endl;
int j=0;
k=l.cel;
while(k!=NULL)
{j=0; 
	while(k->pr.nom!=nom[j])
	     j++;
cout<<"  |    "<<nom[j]<<"	  |            "<<t_att[j]<<"              |          "<<t_trai[j]<<"           |  "<<endl;
  cout<<"  ====================================================================  "<<endl;
  k=k->suiv;}
float tam=0;
for(int k=0;k<i;k++)
tam+=(float)t_att[k];
tam=tam/i;
  cout<<endl<<"Temps d'attente moyen = "<<tam<<" ut"<<endl;
float ttm=0;
for(int k=0;k<i;k++)
ttm+=(float)t_trai[k];
ttm=ttm/i;
  cout<<"Temps de traitement moyen = "<<ttm<<" ut"<<endl;

 
}
//L'algorithme SJF
void SJF(liste ll)
{  liste l;
   l.copie_liste(ll);
   l.triparTarr();
   bool test=false;
   int tmp=0;
   liste wt;
   cell*k;
   cell*m;
 cout<<"_____________________________Diagramme de GANTT________________________________"<<endl<<endl;
	cout<<".*"<<tmp<<"*.";
       liste LS1;
	   int t[50];
	   int u=0;
	   int tmp1=tmp;
   while(l.tousfinis()==false)
   {k=l.cel;
   while(k!=NULL)
      {if((k->pr).t_arr<=tmp1)
	   {wt.ajout_fin(k->pr);k=k->suiv;l.supp_premier();}
	  else {k=k->suiv;}
	  }
	   wt.tricparTexe();
	   m=wt.cel;
while(m!=NULL)
   { if((m->pr).t_arr<=tmp)
	   {for(int j=tmp;j<tmp+(m->pr.t_exe);j++)
			cout<<"("<<m->pr.nom<<").";
	LS1.ajout_fin(m->pr);
         		tmp+=m->pr.t_exe;
				cout<<"*"<<tmp<<"*.";
				t[u]=tmp;u++;
		}
     else
	  {for(int j=tmp;j<tmp+(m->pr.t_arr);j++)
			cout<<"__.";
           test=true;
       for(int j=(m->pr.t_arr);j<(m->pr.t_arr)+(m->pr.t_exe);j++)
			cout<<"("<<m->pr.nom<<").";
	   LS1.ajout_fin(m->pr);
		tmp=m->pr.t_arr+m->pr.t_exe;
		cout<<"*"<<tmp<<"*.";
		t[u]=tmp;u++;
}
if(m->suiv!=NULL)
{m=m->suiv;
wt.supp_premier();}
else{wt.supp_premier();
m=NULL;}
k=l.cel;
	 while(k!=NULL)
      {if((k->pr).t_arr<=tmp)
	 {wt.ajout_fin(k->pr);k=k->suiv;l.supp_premier();}
	   else k=k->suiv;}
	  wt.tricparTexe();
   }
tmp1++;
  }
  cout<<endl<<"_______________________________________________________________________________"<<endl;
  cout<<"RQ: Chaque .(proc). est une unitee de temps executee par ce processus "<<endl<<"  Chaque .*inst*. est l'instant courant"<<endl;
  if(test)cout<<"  Chaque .__. est une unitee de temps non executee "<<endl;
cout<<"_______________________________________________________________________________"<<endl<<endl; 
      cout<<"  ====================================================================  "<<endl;
      cout<<"  |      Nom      |      Temps d'attente      |  Temps de traitement |  "<<endl;
      cout<<"  ====================================================================  "<<endl;
   cell* s=ll.cel;
   cell* s1=NULL;
   int fin_exe;
   int i;
   float j=0.0;
   int tot_exe=0;
   int tot_att=0;
   while(s!=NULL)
   {
	   fin_exe=0;
	   i=0;
	   s1=LS1.cel;
	   while(s1!=NULL)
	   {
		   if((s->pr.nom)==(s1->pr.nom))
			{
				fin_exe=t[i];
			}
		   s1=s1->suiv;
		   i++;
	   }
	    cout<<"  |    "<<s->pr.nom<<"	  |            "<<fin_exe-(s->pr.t_arr)-(s->pr.t_exe)<<"              |          "<<fin_exe-(s->pr.t_arr)<<"           |  "<<endl;
  cout<<"  ====================================================================  "<<endl;
	   tot_exe+=((fin_exe)-(s->pr.t_arr));
	   tot_att+=((fin_exe)-(s->pr.t_arr)-(s->pr.t_exe));
	   s=s->suiv;
	   j=j+1.0;	   
   }
   cout<<endl;
     cout<<"Temps de traitement moyen = "<<tot_exe/j<<" ut"<<endl;
	 cout<<"Temps d'attente moyen = "<<tot_att/j<<" ut"<<endl;
}
//L'algorithme RR
int RR(liste lll)
{ cell* s=NULL;
   s=lll.cel;
   liste ll;
   while(s!=NULL )
   {	
	   ll.ajout_fin(s->pr);
	   s=s->suiv;
   }
	cout<<"Donner le quintome du temps"<<endl;
	int q;
   cin>>q;
   while(q<1)
   {	cout<<"Saisie non valide !!!"<<endl;
   	cin>>q;
   }
   s=NULL;
   s=ll.cel;
   liste LS;
   while(s!=NULL )
   {	
	   LS.ajout_fin(s->pr);
	   s=s->suiv;
   }
   ll.triparTarr();
   bool test=false;
   int tmp=0;
   int tab_fin_exe [50];
   int f=0;
   liste wt;
  cout<<"_____________________________Diagramme de GANTT________________________________"<<endl<<"                                ( Q= "<<q<<"Ut )"<<endl<<endl;
 cout<<".*"<<tmp<<"*.";
  while(ll.cel!=NULL )
   {	wt.ajout_fin(ll.cel->pr);
   ll.supp_premier();
   }
   liste LS1;
   while(ll.tousfinis()==false || wt.tousfinis()==false)
   {
	if(wt.tousfinis()==false)
	{if(wt.cel->pr.t_arr<=tmp)
	    {if(wt.cel->pr.t_exe>q)
	   {	for(int j=tmp;j<tmp+q;j++)
			cout<<"("<<wt.cel->pr.nom<<").";
			LS1.ajout_fin(wt.cel->pr);
			for(int i=0;i<q;i++)
			{	
				wt.dec(wt.cel->pr.nom);
			}
				wt.ajout_fin(wt.cel->pr);
				wt.cel=wt.cel->suiv;
				tmp=tmp+q;
				cout<<"*"<<tmp<<"*.";}
         else
		 {
			 for(int j=tmp;j<tmp+(wt.cel->pr.t_exe);j++)
			 cout<<"("<<wt.cel->pr.nom<<").";  
			 LS1.ajout_fin(wt.cel->pr);
 			 tmp=tmp+wt.cel->pr.t_exe;
			 wt.cel=wt.cel->suiv;
			 cout<<"*"<<tmp<<"*.";
	}}
	else{for(int j=tmp;j<(wt.cel->pr.t_arr);j++)
		     cout<<"__.";
	test=true;
	tmp+=wt.cel->pr.t_arr;
		if(wt.cel->pr.t_exe>q)
	   {	for(int j=tmp;j<tmp+q;j++)
			cout<<"("<<wt.cel->pr.nom<<").";
			LS1.ajout_fin(wt.cel->pr);
			for(int i=0;i<q;i++)
			{	
				wt.dec(wt.cel->pr.nom);
			}
				wt.ajout_fin(wt.cel->pr);
				wt.cel=wt.cel->suiv;
				tmp=tmp+q;
				cout<<"*"<<tmp<<"*.";}
         else
		 {
			 for(int j=tmp;j<tmp+(wt.cel->pr.t_exe);j++)
			 cout<<"("<<wt.cel->pr.nom<<").";  
			 LS1.ajout_fin(wt.cel->pr);
 			 tmp=tmp+wt.cel->pr.t_exe;
			 wt.cel=wt.cel->suiv;
			 cout<<"*"<<tmp<<"*.";
	}}
	  tab_fin_exe[f]=tmp;
	  f++;
      }
      else
      {tmp++;}
   }
	cout<<endl<<"_______________________________________________________________________________"<<endl;
 cout<<"RQ: Chaque .(proc). est une unitee de temps executee par ce processus "<<endl<<"  Chaque .*inst*. est l'instant courant"<<endl;
 if(test)cout<<"  Chaque .__. est une unitee de temps non executee "<<endl;
cout<<"_______________________________________________________________________________"<<endl<<endl; 
      cout<<"  ====================================================================  "<<endl;
      cout<<"  |      Nom      |      Temps d'attente      |  Temps de traitement |  "<<endl;
      cout<<"  ====================================================================  "<<endl;
   s=LS.cel;
   cell* s1=NULL;
   int fin_exe;
   int i;
   float j=0.0;
   int tot_exe=0;
   int tot_att=0;
   while(s!=NULL)
   {
	   fin_exe=0;
	   i=0;
	   s1=LS1.cel;
	   while(s1!=NULL)
	   {
		   if((s->pr.nom)==(s1->pr.nom))
			{
				fin_exe=tab_fin_exe[i];
			}
		   s1=s1->suiv;
		   i++;
	   }
	   cout<<"  |    "<<s->pr.nom<<"	  |            "<<fin_exe-(s->pr.t_arr)-(s->pr.t_exe)<<"              |          "<<fin_exe-(s->pr.t_arr)<<"           |  "<<endl;
  cout<<"  ====================================================================  "<<endl;
	      tot_exe+=((fin_exe)-(s->pr.t_arr));
	   tot_att+=((fin_exe)-(s->pr.t_arr)-(s->pr.t_exe));
	   s=s->suiv;
	   j=j+1.0;	   
   }
     cout<<endl;
	 cout<<"Temps de traitement moyen = "<<tot_exe/j<<" ut"<<endl;
	 cout<<"Temps d'attente moyen = "<<tot_att/j<<" ut"<<endl;
return q;
}
//L'algorithme SRT
void SRT(liste lll)
{liste ll;
ll.copie_liste(lll);
	ll.triparTarr();
   liste l;
   l.copie_liste(ll);
   bool test=false;
   int tmp=0;
   int tmp1=tmp;
   int i=0;
   string nom[50];
   int t_att[50];
   int t_trai[50];
   liste wt;
   cell*k;
   cell*m;
  string t;
   cout<<"_____________________________Diagramme de GANTT________________________________"<<endl<<endl;
 cout<<".*"<<tmp<<"*.";
   while(l.tousfinis()==false)
   {k=l.cel;
	 while(k!=NULL)
      {if((k->pr).t_arr<=tmp1)
	      {wt.ajout_fin(k->pr);k=k->suiv;l.supp_premier();}
	  else k=k->suiv;}
	   wt.tricparTexe();
	   m=wt.cel;
while(m!=NULL)
{   m=wt.cel;
    t=m->pr.nom;
    m->finp=false;
	   if((m->pr).t_arr<=tmp)
	   {cout<<"("<<m->pr.nom<<").";
         		tmp+=1;
		}
     else
	  {for(int j=tmp;j<tmp+(m->pr.t_arr);j++)
			cout<<"__.";

	   test=true;
			cout<<"("<<m->pr.nom<<").";
		tmp=m->pr.t_arr+1;
       }
wt.dec(m->pr.nom);
if(m->suiv!=NULL)
{if(m->finp==true)
{ k=ll.cel;

while((k!=NULL)&&(k->pr.nom!=m->pr.nom))
	k=k->suiv;
	nom[i]=m->pr.nom;
   t_att[i]=tmp-m->pr.t_arr-k->pr.t_exe;
   t_trai[i]=tmp-m->pr.t_arr;
   i++;
m=m->suiv;
wt.supp_premier();}
else m=m->suiv;
}
else{if(m->finp==true)
{
	k=ll.cel;
while((k!=NULL)&&(k->pr.nom!=m->pr.nom))
	k=k->suiv;
nom[i]=m->pr.nom;
   t_att[i]=tmp-m->pr.t_arr-k->pr.t_exe;
   t_trai[i]=tmp-m->pr.t_arr;
   i++;
wt.supp_premier();
m=NULL;}}
k=l.cel;
	 while(k!=NULL)
      {if((k->pr).t_arr<=tmp)
	 {wt.ajout_fin(k->pr);k=k->suiv;l.supp_premier();}
	   else k=k->suiv;}
	  wt.tricparTexe();
	  if((wt.cel!=NULL)&&((wt.cel->pr.nom)!=t))cout<<"*"<<tmp<<"*.";
   }
tmp1++;
  }
   cout<<"*"<<tmp<<"*.";
cout<<endl<<"_______________________________________________________________________________"<<endl;
 cout<<"RQ: Chaque .(proc). est une unitee de temps executee par ce processus "<<endl<<"  Chaque .*inst*. est l'instant courant"<<endl;
 if(test)cout<<"  Chaque .__. est une unitee de temps non executee "<<endl;
 cout<<"_______________________________________________________________________________"<<endl<<endl; 
   cout<<"  ====================================================================  "<<endl;
      cout<<"  |      Nom      |      Temps d'attente      |  Temps de traitement |  "<<endl;
      cout<<"  ====================================================================  "<<endl;
int j=0;
k=lll.cel;
while(k!=NULL)
{j=0; 
	while(k->pr.nom!=nom[j])
	     j++;
cout<<"  |    "<<nom[j]<<"	  |            "<<t_att[j]<<"              |          "<<t_trai[j]<<"           |  "<<endl;
  cout<<"  ====================================================================  "<<endl;
  k=k->suiv;}
float tam=0;
for(int k=0;k<i;k++)
tam+=(float)t_att[k];
tam=tam/i;
cout<<endl;
  cout<<"Temps d'attente moyen = "<<tam<<" ut"<<endl;
float ttm=0;
for(int k=0;k<i;k++)
ttm+=(float)t_trai[k];
ttm=ttm/i;
  cout<<"Temps de traitement moyen = "<<ttm<<" ut"<<endl;

}
