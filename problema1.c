// adaugare biblioteci necesare
#include <stdio.h>
#include <string.h>
#include <math.h>

// verifica daca 2 cuvinte sunt anagrame
int is_anagram(char *s1, char *s2)
{   // e obligatoriu ca ambele sa fie egale in lungime
    if(strlen(s1) != strlen(s2)) 
        return 0;
    // creare vector caracteristic
    int i;
    int v[26]= {0};
    
    // in codul ASCII alfabetul incepe de la 97, asa ca scad 97 pozitii
    for(i=0 ; i<strlen(s1) ; i++)
    // adaug de cate ori apare fiecare litera din cuvantul 1
        v[s1[i]-97]++; 
    
    for(i=0 ; i<strlen(s2) ; i++)
    // scad de cate ori apare fiecare litera din cuvantul 2
        v[s2[i]-97]--; 

    for(i=0 ; i<25 ; i++)
    // daca vectorul nu ramane intact, inseamna ca nu sunt anagrame
        if(v[i] != 0) 
        break;
    
    // daca s a parcursul tot forul inseamna ca sunt anagrame    
    if(i == 25)
        return 1;
    else
        // daca nu, nu sunt
        return 0;
}

double compute_grade(char *s1, char *s2) // verificam gradul
{   double litera=0;
    // numaram de cate ori apare o litera pe aceeasi pozitie
    for(int i=0 ; i < strlen(s1) ; i++) 
        if(s1[i] != s2[i])
            litera++;
    
    double x;
    x=litera/strlen(s1); // aflam gradul
    return x;
}

int aproximare(double x, double y)
{   // functie egalitate a 2 nr reale cu aproximare
    if(fabs(x-y) < 0.1)
        return 1;
    else
        return 0;
}

void sortare(int n, double v[], int cv[]) //sortare grad
{   double maxim=-2;
    int ok=1;
    int contor=0;
    int pozitie,nr;

    while(ok!=0) // incepem sortarea 
    {   nr=0;
        maxim=-2;
        // gasim cel mai mare grad
        for(int i=0 ; i<n ; i++)
        {   if(maxim < v[i] && v[i] != 2)
            {   maxim=v[i];
                pozitie=i;
            }
        }
        // bagam ordinea pozitiilor
        cv[contor]=pozitie;
        contor++;
        // marcam vectorul ca sa nu reluam aceeasi valoare
        v[pozitie]=2;

        // cautam maximi egali daca exista
        for(int i=0 ; i<n ; i++) 
            if(maxim == v[i])
            { cv[contor]=i; 
              contor++;
              v[i]=2;
            }
        // verificam nr elemente sortate
        for(int i=0 ; i<n ; i++)
            if(v[i] == 2)
              nr++;
        // terminam sortarea  
        if(nr == n)
         ok=0;
    }
}

int main()
{
    int n;
    scanf("%d",&n); // primim n ul 
    char matrice[5000][3][51]; // facem matrice de siruri 
    double grad[n+1]; // vectorul de grade

    for(int i=0 ; i < n ; i++)
    {   for(int j=0 ; j < 2 ; j++)
            // citim cuvinte
            scanf("%s", matrice[i][j]);
        
        // verificam daca sunt anagrame
        if(is_anagram(matrice[i][0],matrice[i][1]) == 1)
            // facem gradul
            grad[i]=compute_grade(matrice[i][0],matrice[i][1]); 
        else
            // nu mai facem gradul ca nu sunt anagrame
            grad[i]=-1;
    }

    int cv[n+2]; // facem ordinea pozitiilor dupa grad
    double cgrad[n+2]; // facem copie la vector
    for (int i=0; i<n ; i++)
        cgrad[i]=grad[i];

    sortare(n,grad,cv); // facem sortarea
    char A[5000][51];

    for(int i=0 ; i<n ; i++)
    // copiem primul cuvantul pentru ordinea lexico-grafica
    strcpy(A[i],matrice[i][0]); 
    
    int aux;
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
        { int f,g;
          f=cv[j];
          g=cv[j+1];
            // verificam daca cuvintele au acelasi grad pt sortare alfabetica
            if (cgrad[f] == cgrad[g]) 
            {   // facem sortare in ordine descrescatoare alfabetic
                if(strcmp( A[f] , A[g]) < 0) 
                { aux=cv[j];
                  cv[j]=cv[j+1];
                  cv[j+1]=aux;
                }
            }
        }
    
    // afisam ordinea ceruta
    int g1;
    for(int i=0 ; i < n ; i++) 
    {  g1=cv[i];
       printf("%s %s\n", matrice[g1][0] , matrice[g1][1]);
    }

    return 0;
}
