// adaugare biblioteci
#include <stdio.h>
#include <string.h>

void culori(char culoare[10][10]) 
{   // facem vector de culori
    for(int i=0; i < 6 ; i++)
      scanf("%s", culoare[i]);
}

void output(int matrice[10][10], char culoare[10][10], int x, int y, int ok) 
{   // afisam culorile
    int alfa=matrice[x][y];
    if(ok < 2)
     printf("%s.", culoare[alfa]);
    else
     printf("%s", culoare[alfa]);
}

void afisare(int matrice[10][10], char culoare[10][10]) 
{   int ok;
    // procesam codarea
    for(int i=0 ; i < 3; i++)
    {   ok=0;
        for(int j=0 ; j < 3 ; j++)
            { // facem apel la output pt decodificare
              output(matrice,culoare,i,j,ok);
              ok++;
            }
        printf("\n");
    }

}

// rotim cu 90 de grade ori la stanga ori la dreapta
void rotire(int matrice[10][10], int type) 
{  if(type == 1) // cu type 1 rotim dreapta
    {   int aux[10][10];
        for(int i=0 ; i < 3 ; i++)
            for(int j=0 ; j < 3 ; j++)
                aux[i][j]=matrice[i][j];
        
        for(int i=0 ; i< 3 ; i++)
            for(int j=0 ; j< 3 ; j++)
                matrice[i][j]=aux[2-j][i];
    }
    
   else // cu type 0 rotim stanga
    {   int aux[10][10];
        for(int i=0 ; i < 3 ; i++)
            for(int j=0 ; j < 3 ; j++)
                aux[i][j]=matrice[i][j];

        for(int i=0 ; i< 3 ; i++)
            for(int j=0 ; j< 3 ; j++)
                matrice[2-j][i]=aux[i][j];
    }

}

void schimbU(int m1[10][10], int m2[10][10], int m3[10][10], int m4[10][10], int m5[10][10], int m6[10][10], int type)
{   // facem mutarea U
    int a[10]; // vector auxiliar schimbare culori

    if(type == 1) // cu type 1 facem mutarea U
    {   // aici e interschimbarea culorilor de 4 ori
        for(int i=0 ; i < 3 ; i++) 
            a[i]=m1[0][i];
        for(int i=0 ; i < 3 ; i++)
            m1[0][i]=m6[0][i];
        for(int i=0 ; i < 3 ; i++)
            m6[0][i]=m2[0][i];
        for(int i=0 ; i < 3 ; i++)
            m2[0][i]=m5[0][i];
        for(int i=0 ; i < 3 ; i++)
            m5[0][i]=a[i];
        rotire(m3,type); // rotirea fetei
    }
    else // cu type 0 facem mutarea U'
    {   // interschimbare culori la fiecare fata
        for(int i=0 ; i < 3 ; i++) 
            a[i]=m1[0][i];
        for(int i=0 ; i < 3 ; i++)
            m1[0][i]=m5[0][i];
        for(int i=0 ; i < 3 ; i++)
            m5[0][i]=m2[0][i];
        for(int i=0 ; i < 3 ; i++)
            m2[0][i]=m6[0][i];
        for(int i=0 ; i < 3 ; i++)
            m6[0][i]=a[i];
        rotire(m3,type); // rotirea fetei
    }
}

void schimbF(int m1[10][10], int m2[10][10], int m3[10][10], int m4[10][10], int m5[10][10], int m6[10][10], int type)
{
    int a[10];
    if(type==1) // facem mutarea F
    {   // interschimbare
        for(int i=0 ; i < 3 ; i++) 
            a[i]=m3[2][i];
        for(int i=0 ; i < 3 ; i++)
            m3[2][i]=m5[2-i][2];
        for(int i=0 ; i < 3 ; i++)
            m5[i][2]=m4[0][i];
        for(int i=0 ; i < 3 ; i++)
            m4[0][i]=m6[2-i][0];
        for(int i=0 ; i < 3 ; i++)
            m6[i][0]=a[i];
        rotire(m1,type); // rotire
    }
    else // facem mutare F'
    {   // interschimbare
        for(int i=0 ; i < 3 ; i++) 
            a[i]=m3[2][i];
        for(int i=0 ; i < 3 ; i++)
            m3[2][i]=m6[i][0];
        for(int i=0 ; i < 3 ; i++)
            m6[i][0]=m4[0][2-i];
        for(int i=0 ; i < 3 ; i++)
            m4[0][i]=m5[i][2];
        for(int i=0 ; i < 3 ; i++)
            m5[i][2]=a[2-i];
        rotire(m1,type); // rotire
    }
}

// analog pentru celelalte mutari
void schimbD(int m1[10][10], int m2[10][10], int m3[10][10], int m4[10][10], int m5[10][10], int m6[10][10], int type)
{
    int a[10];

    if(type==1)
    {
        for(int i=0 ; i < 3 ; i++)
            a[i]=m1[2][i];
        for(int i=0 ; i < 3 ; i++)
            m1[2][i]=m5[2][i];
        for(int i=0 ; i < 3 ; i++)
            m5[2][i]=m2[2][i];
        for(int i=0 ; i < 3 ; i++)
            m2[2][i]=m6[2][i];
        for(int i=0 ; i < 3 ; i++)
            m6[2][i]=a[i];
        rotire(m4,type);
    }
    else
    {
        for(int i=0 ; i < 3 ; i++)
            a[i]=m1[2][i];
        for(int i=0 ; i < 3 ; i++)
            m1[2][i]=m6[2][i];
        for(int i=0 ; i < 3 ; i++)
            m6[2][i]=m2[2][i];
        for(int i=0 ; i < 3 ; i++)
            m2[2][i]=m5[2][i];
        for(int i=0 ; i < 3 ; i++)
            m5[2][i]=a[i];
        rotire(m4,type);
    }
}

void schimbB(int m1[10][10], int m2[10][10], int m3[10][10], int m4[10][10], int m5[10][10], int m6[10][10], int type)
{
    int a[10];
    if(type==1)
    {
        for(int i=0 ; i < 3 ; i++)
            a[i]=m3[0][i];
        for(int i=0 ; i < 3 ; i++)
            m3[0][i]=m6[i][2];
        for(int i=0 ; i < 3 ; i++)
            m6[i][2]=m4[2][2-i];
        for(int i=0 ; i < 3 ; i++)
            m4[2][i]=m5[i][0];
        for(int i=0 ; i < 3 ; i++)
            m5[i][0]=a[2-i];
        rotire(m2,type);
    }
    else
    {
        for(int i=0 ; i < 3 ; i++)
            a[i]=m3[0][i];
        for(int i=0 ; i < 3 ; i++)
            m3[0][i]=m5[2-i][0];
        for(int i=0 ; i < 3 ; i++)
            m5[i][0]=m4[2][i];
        for(int i=0 ; i < 3 ; i++)
            m4[2][i]=m6[2-i][2];
        for(int i=0 ; i < 3 ; i++)
            m6[i][2]=a[i];
        rotire(m2,type);
    }
}

void schimbR(int m1[10][10], int m2[10][10], int m3[10][10], int m4[10][10], int m5[10][10], int m6[10][10], int type)
{
    int a[10];
    if(type==1)
    {
        for(int i=0 ; i < 3 ; i++)
            a[i]=m1[i][2];
        for(int i=0 ; i < 3 ; i++)
            m1[i][2]=m4[i][2];
        for(int i=0 ; i < 3 ; i++)
            m4[i][2]=m2[2-i][0];
        for(int i=0 ; i < 3 ; i++)
            m2[i][0]=m3[2-i][2];
        for(int i=0 ; i < 3 ; i++)
            m3[i][2]=a[i];
        rotire(m6,type);
    }
    else
    {
        for(int i=0 ; i < 3 ; i++)
            a[i]=m1[i][2];
        for(int i=0 ; i < 3 ; i++)
            m1[i][2]=m3[i][2];
        for(int i=0 ; i < 3 ; i++)
            m3[i][2]=m2[2-i][0];
        for(int i=0 ; i < 3 ; i++)
            m2[i][0]=m4[2-i][2];
        for(int i=0 ; i < 3 ; i++)
            m4[i][2]=a[i];
        rotire(m6,type);
    }
}

void schimbL(int m1[10][10], int m2[10][10], int m3[10][10], int m4[10][10], int m5[10][10], int m6[10][10], int type)
{
    int a[10];
    if(type==1)
    {
        for(int i=0 ; i < 3 ; i++)
            a[i]=m1[i][0];
        for(int i=0 ; i < 3 ; i++)
            m1[i][0]=m3[i][0];
        for(int i=0 ; i < 3 ; i++)
            m3[i][0]=m2[2-i][2];
        for(int i=0 ; i < 3 ; i++)
            m2[i][2]=m4[2-i][0];
        for(int i=0 ; i < 3 ; i++)
            m4[i][0]=a[i];
        rotire(m5,type);
    }
    else
    {
        for(int i=0 ; i < 3 ; i++)
            a[i]=m1[i][0];
        for(int i=0 ; i < 3 ; i++)
            m1[i][0]=m4[i][0];
        for(int i=0 ; i < 3 ; i++)
            m4[i][0]=m2[2-i][2];
        for(int i=0 ; i < 3 ; i++)
            m2[i][2]=m3[2-i][0];
        for(int i=0 ; i < 3 ; i++)
            m3[i][0]=a[i];
        rotire(m5,type);
    }
}

void transformare(char matrice[30][30][30], int matrix[10][10], int x, char culoare[10][10])
{   // fac codificarea culorilor pentru a lucra mai usor dupa
    int contor=0;
    int nr1=0;
    int nr2=0;

    for(int i=0 ; i < 3 ; i++)
    {   char s[10];
        contor=0;
        for(int j=0 ; j < strlen(matrice[x][i]) ; j++)
        {   // adaug litere ( 46 e codul ASCII pt punct)
            if(matrice[x][i][j] != 46) 
            {   s[contor]=matrice[x][i][j];
                contor++;
            }

            if(matrice[x][i][j] == 46) // ma opresc
            {   s[contor]=0;
                contor=0;
                for(int k=0 ; k < 6 ; k++) // verific in vector ce index are culoarea
                    if(strcmp(s,culoare[k])==0)
                    {   // fac atribuire de index
                        matrix[nr1][nr2]=k;
                        nr2++;
                    }
            }

            if(j==strlen(matrice[x][i])-1) // oprire finala
            {   s[contor]=0;
                contor=0;
                for(int k=0 ; k < 6 ; k++)
                    if(strcmp(s,culoare[k])==0)
                    {   matrix[nr1][nr2]=k;
                        nr2++;
                    }
            }

        }
        nr1++;
        nr2=0; // bagam in matrice
    }

}
int main()
{
    char C[10][10];
    culori(C); // citire culori

    char A[30][30][30];
    for(int i=0 ; i < 6; i++)
        for(int j=0 ; j < 3 ; j++)
            scanf("%s", A[i][j]);

    int m1[10][10]; // initializare fete (6 matrici)
    int m2[10][10]; // analog pentru restul
    int m3[10][10];
    int m4[10][10];
    int m5[10][10];
    int m6[10][10];

    for(int i=0 ; i < 3; i++)
        for(int j=0 ; j < 3 ; j++)
        {   m1[i][j]=0;
            m2[i][j]=0;
            m3[i][j]=0;
            m4[i][j]=0;
            m5[i][j]=0;
            m6[i][j]=0;
        }

    transformare(A,m1,0,C); // codificare fiecare matrice (fata a cubului)
    transformare(A,m2,1,C);
    transformare(A,m3,2,C);
    transformare(A,m4,3,C);
    transformare(A,m5,4,C);
    transformare(A,m6,5,C);

    int m;
    char p[10][100]; // citire mutari
    scanf("%d",&m); // nr mutari

    for(int i=0 ; i < m ; i++)
    {   // executare mutari
        scanf("%s",p[i]);
        if(strcmp("F", p[i])==0)
            schimbF(m1,m2,m3,m4,m5,m6,1);
        if(strcmp("F'", p[i])==0)
            schimbF(m1,m2,m3,m4,m5,m6,0);
        if(strcmp("L", p[i])==0)
            schimbL(m1,m2,m3,m4,m5,m6,1);
        if(strcmp("L'", p[i])==0)
            schimbL(m1,m2,m3,m4,m5,m6,0);
        if(strcmp("R", p[i])==0)
            schimbR(m1,m2,m3,m4,m5,m6,1);
        if(strcmp("R'", p[i])==0)
            schimbR(m1,m2,m3,m4,m5,m6,0);
        if(strcmp("B", p[i])==0)
            schimbB(m1,m2,m3,m4,m5,m6,1);
        if(strcmp("B'", p[i])==0)
            schimbB(m1,m2,m3,m4,m5,m6,0);
        if(strcmp("D", p[i])==0)
            schimbD(m1,m2,m3,m4,m5,m6,1);
        if(strcmp("D'", p[i])==0)
            schimbD(m1,m2,m3,m4,m5,m6,0);
        if(strcmp("U", p[i])==0)
            schimbU(m1,m2,m3,m4,m5,m6,1);
        if(strcmp("U'", p[i])==0)
            schimbU(m1,m2,m3,m4,m5,m6,0);
    }

      afisare(m1,C); // afisare configuratie finala
      afisare(m2,C);
      afisare(m3,C);
      afisare(m4,C);
      afisare(m5,C);
      afisare(m6,C);

    return 0;
}
