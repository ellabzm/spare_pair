#include <iostream>
#include<string.h>
#include<string>
/* Două șiruri distincte de caractere formează o pereche rezervă dacă unul dintre ele se poate obține
din celălalt, prin împărțirea lui în două secvențe/subșiruri și apoi interschimbarea acestora.
Exemplu: oricare două dintre șirurile stea, aste, east, teas pot forma o pereche rezervă (dacă
stea se împarte în st și ea se obține east, dacă se împarte în s și tea se obține teas etc.).
Subprogramul rezerva are doi parametri, s1 și s2, prin care primește câte un șir de cel mult 100
de caractere, numai litere mici ale alfabetului englez. Subprogramul returnează valoarea 1, dacă cele
două șiruri formează o pereche rezervă, sau valoarea 0 în caz contrar.
Scrieți un program Pascal/C/C++ care citește de la tastatură un text format din maximum 100 de
caractere, în care cuvintele sunt formate din litere mici ale alfabetului englez și sunt separate prin
unul sau mai multe spații. Programul afișează pe ecran toate perechile rezervă formate din cuvinte
din text. Fiecare pereche este afișată pe câte o linie a ecranului, între paranteze rotunde, iar
cuvintele care o formează se afișează într-o ordine oarecare, separate prin caracterul #. Dacă nu
există nicio astfel de pereche, se afișează pe ecran mesajul nu exista. Programul cuprinde
definiția completă a subprogramului precizat mai sus, precum și apeluri utile ale acestuia.
Exemplu: dacă se citește textul
in aste nopti o stea numita seta ni se arata in est
se afișează pe ecran perechile de mai jos, nu neapărat în această ordine
(aste#stea)
(in#ni)
(in#ni)*/
using namespace std;
/******impartirea cuvantului in doua subiruri si reconstruirea lui prin interschimbarea acestora.******/
char *split_rev(const char *c, int n)
{
    int l=strlen(c), lst=n, ldr=l-lst;
    char cuv[l], c_s[lst+1], c_dr[ldr+1];
    strncpy(c_s, c, lst); c_s[lst]='\0';
    strcpy(c_dr, c+lst);c_dr[ldr]='\0';
    strcpy(cuv,c_dr);
    strcat(cuv,c_s);
    return cuv;
}
/******determina daca doua cuvinte formeaza o pereche rezerva******/
int rezerva(char *s1, char *s2)
{
    int l1=strlen(s1),l2=strlen(s2), i=1;
    char x[l1];strcpy(x,split_rev(s1,i));
    if(l1==l2)
        while(i<l2)
        {
            if(strcmp(x,s2)==0)
            {
                cout<<endl<<"("<<s1<<"#"<<s2<<")";
                return 1;
            }
            else
            {
                i++;
                strcpy(x,split_rev(s1,i));
            }
        }
    return 0;
}

int main()
{
    char text[101],cuvinte[101][40],*p;
    int t=0, nr=0;
    cin.getline(text,101);
/******separarea textului in cuvinte******/
    p=strtok(text," ");
    while(p)
    {
        strcpy(cuvinte[t],p);
        p=strtok(NULL," ");
        t++;
    }
/******parcurgerea vectorului de cuvinte si cautarea perechilor rezerva******/
    for(int i=0;i<t;i++)
        for(int j=i+1;j<=t;j++)
        {
            if(rezerva(cuvinte[i],cuvinte[j])&&(i!=j))
                nr++;
        }
    if(nr==0)
        cout<<"nu exista!";

    //cout<<endl<<nr<<endl;
    return 0;
}
