// adaugare biblioteci
#include <stdio.h>
#include <string.h>
#include <math.h>

void reverse (char *s) 
{ // facem inversul la un string
  char x[100];
  strcpy(x,s);
  int c=0;
  for(int i=strlen(x)-1 ; i >=0 ; i--)
    {  s[c]=x[i];
       c++;
    }
    s[c]=0;
}

void dec_to_bin (int n, char *s) 
{   // transformare din sistem decimal in binar
    int i=0;
    if(n == 0) // daca e 0, ramane 0
    { s[i]='0';
      i++;
    }
    else
    // facem procedeul de impartire la 2 si formarea tuturor resturilor e numarul cerut
    while(n != 0) 
    {   if(n%2 == 0)
            s[i]='0'; // bagam in string 0 daca restul e 0
        else
            s[i]='1'; // bagam in string 1 daca restul e 1
        n=n/2;
        i++;
    }
    
    // resturile se iau in ordine inversa, deci facem inversul stringului
    s[i]=0;
    reverse(s); 
}

void transpusa(int a[][100],int A[][100]) // facem transpusa la o matrice
{   for(int i=0 ; i<8 ; i++)
        for(int j=0; j<8 ; j++)
            A[j][i]=a[i][j];
}

void prod(int a[][100], int b[][100], int c[][100]) 
{   // facem produsul la 2 matrici si salvam in matricea C
    int i,j,k;
    for(i=0 ; i < 8 ; i++)
        for(j=0 ; j < 8 ; j++)
            for(k=0 ; k < 8 ; k++)
                // algoritm produs normal
                c[i][j]=c[i][j]+a[i][k]*b[k][j];

    for(int i = 0 ; i < 8 ; i++)
        for(int j = 0 ; j < 8 ; j++)
            if(c[i][j] > 0)
              // pt logica booleana, ce e 0 ramane 0 , ce e >= cu 1 ramane 1
              c[i][j]=1;
}

int sum_X_0(int m[][100]) // calculare scor pe fiecare matrice in parte
{   int scor1=0,scor2=0,scor3=0,scor4=0;
    // facem structura pentru a presupune ca exista 4 linii si 4 coloane complete
    struct ptype 
    {   int x[4] ;
        int y[4] ;
    } linie;

    // facem presupunere ca liniile si coloanele sunt bune
    for(int i=0; i<4 ; i++) 
    {   linie.x[i]=1;
        linie.y[i]=1;
    }

    for(int i=0 ; i < 4 ; i++)
        for(int j=0 ; j < 4 ; j++)
            if(m[i][j] == 0) 
            {   // daca un element e 0 , linia si coloana elementului nu mai sunt complete
                linie.x[i]=0;
                linie.y[j]=0;
            }

    for(int i=0 ; i < 4 ; i++)
        scor1=scor1+linie.x[i]+linie.y[i]; // adaugam scor total linie+coloana

    if(m[0][0]==1&&m[1][1]==1&&m[2][2]==1&&m[3][3]==1) // verificam diagonala 1
        scor1++;

    if(m[0][3]==1&&m[1][2]==1&&m[2][1]==1&&m[3][0]==1) // verificam diagonala 2
        scor1++;

   // analog pentru restul 
    for(int i=0; i<4 ; i++)
    {   linie.x[i]=1;
        linie.y[i]=1;
    }

    for(int i=4 ; i < 8 ; i++)
        for(int j=4 ; j < 8 ; j++)
            if(m[i][j]==0)
            {   linie.x[i-4]=0;
                linie.y[j-4]=0;
            }

    for(int i=0 ; i < 4 ; i++)
        scor2=scor2+linie.x[i]+linie.y[i];

    if(m[4][7]==1&&m[5][6]==1&&m[6][5]==1&&m[7][4]==1)
        scor2++;

    if(m[4][4]==1&&m[5][5]==1&&m[6][6]==1&&m[7][7]==1)
        scor2++;


    for(int i=0; i<4 ; i++)
    {   linie.x[i]=1;
        linie.y[i]=1;
    }

    for(int i=0 ; i < 4 ; i++)
        for(int j=4 ; j < 8 ; j++)
            if(m[i][j]==0)
            {   linie.x[i]=0;
                linie.y[j-4]=0;
            }

    for(int i=0 ; i < 4 ; i++)
        scor3=scor3+linie.x[i]+linie.y[i];

    if(m[0][4]==1&&m[1][5]==1&&m[2][6]==1&&m[3][7]==1)
        scor3++;

    if(m[0][7]==1&&m[1][6]==1&&m[2][5]==1&&m[3][4]==1)
        scor3++;

    for(int i=0; i<4 ; i++)
    {   linie.x[i]=1;
        linie.y[i]=1;
    }

    for(int i=4 ; i < 8 ; i++)
        for(int j=0 ; j < 4 ; j++)
            if(m[i][j]==0)
            {   linie.x[i-4]=0;
                linie.y[j]=0;
            }

    for(int i=0 ; i < 4 ; i++)
        scor4=scor4+linie.x[i]+linie.y[i];

    if(m[4][0]==1&&m[5][1]==1&&m[6][2]==1&&m[7][3]==1)
        scor4++;

    if(m[4][3]==1&&m[5][2]==1&&m[6][1]==1&&m[7][0]==1)
        scor4++;

    int scor=scor1+scor2+scor3+scor4;
    // returnare scor total la matricea mare sectionata in 4
    return scor;
}

void bin_to_dec(char *s) // transformam din binar in zecimal
{   int v[8];
    for(int i=0 ; i < strlen(s) ; i++)
        if(s[i]=='0') 
            // facem transformare in int pentru calculul numarului in zecimal
            v[i]=0;
        else
            v[i]=1;
    int x=strlen(s)-1;
    int numar=0;
    for(int i = 0 ; i < strlen(s) ; i++)
    { // facem 2 la puterea x unde x e pozitia unui 1
      numar=numar+v[i]*pow(2,x);
      x--;
    }
    printf("%d\n", numar);
}

int main()
{   int c=0;
    int x;
    int n,a[100][100];
    int A[100][100];
    int m2[100][100];
    int m3[100][100];
    char s[100];
    for(int i = 0 ; i < 8 ; i++) // facem scanarea numerelor
    {   scanf("%d", &n);
        dec_to_bin(n, s); // transformare binar
        c=strlen(s)-1;
        x=7-strlen(s);
        for(int j = 7 ; j > x ; j--) // formare matrice
        {
            if(s[c]=='0')
                a[i][j]=0;
            else if(s[c]=='1')
                a[i][j]=1;
            if(c>=0)
                c--;
        }
        for(int j= 7-strlen(s); j >= 0 ; j--)
            // completare cu 0 daca numarul nu are 8 biti
            a[i][j]=0;
    }

transpusa(a,A); // facem transpusa
prod(a,A,m2); // aflam matricea A ori A transpus
prod(a,a,m3); // aflam matricea A la 2 a

int rang; // aflam scorul maxim dintre cele 3
if(sum_X_0(a)<=sum_X_0(m2)&&sum_X_0(m2)<=sum_X_0(m3))
    rang=3;
if(sum_X_0(m2)<=sum_X_0(a)&&sum_X_0(a)<=sum_X_0(m3))
    rang=3;
if(sum_X_0(a)<=sum_X_0(m3)&&sum_X_0(m3)<=sum_X_0(m2))
    rang=2;
if(sum_X_0(m3)<=sum_X_0(a)&&sum_X_0(a)<=sum_X_0(m2))
    rang=2;
if(sum_X_0(m3)<=sum_X_0(m2)&&sum_X_0(m2)<=sum_X_0(a))
    rang=1;
if(sum_X_0(m2)<=sum_X_0(m3)&&sum_X_0(m3)<=sum_X_0(a))
    rang=1;

if(rang==3) // afisam matricea in caz de scor egal dar in ordinea ceruta
{ if(sum_X_0(m2)==sum_X_0(m3))
      rang=2;
  if(sum_X_0(m2)==sum_X_0(a))
      rang=1;
}

if(rang==2)
if(sum_X_0(a)==sum_X_0(m2))
      rang=1;

int ok;
int contor;

if(rang==1) // formam matricea 1
{ for(int i = 0 ; i < 8 ; i++)
   {  ok=1;
     contor=0;
     for(int j=0 ; j < 8 ; j++)
     {   if(ok==1)
          if(a[i][j]!=0)
            ok=0;

         if(ok==0)
           { if(a[i][j]==0)
               s[contor]='0';
               else
               s[contor]='1';
               contor++;
           }\
     }
     s[contor]=0;
     bin_to_dec(s);
      // printf("stringuri : %s \n", s);
    }
}

if(rang==2) // formam matricea 2
{for(int i = 0 ; i < 8 ; i++)
 {  ok=1;
    contor=0;
    for(int j=0 ; j < 8 ; j++)
    {   if(ok==1)
          if(m2[i][j]!=0)
            ok=0;
         if(ok==0)
           { if(m2[i][j]==0)
               s[contor]='0';
               else
               s[contor]='1';
               contor++;
           }
    }
    s[contor]=0;
    bin_to_dec(s);
   // printf("stringuri : %s \n", s);
}
}

if(rang==3) // formam matricea 3
{   for(int i = 0 ; i < 8 ; i++)
    {  ok=1;
       contor=0;
       for(int j=0 ; j < 8 ; j++)
       {   if(ok==1)
            if(m3[i][j]!=0)
             ok=0;
           if(ok==0)
           { if(m3[i][j]==0)
               s[contor]='0';
               else
               s[contor]='1';
               contor++;
           }
        }
     s[contor]=0;
     bin_to_dec(s);
   } 
}

return 0;
}
