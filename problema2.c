// adaugare biblioteca
#include <stdio.h>

// completare diagonale ocupate (locuri atacate)
void parcurgere(int x, int y, int matrice[][101], int n)
{   int x1,y1;
    matrice[x][y]=0;
    for(int i=0 ; i < n ; i++)
        for(int j=0 ; j < n ; j++)
            // dezvoltam toate cele 4 diagonale pe care se afla un nebun
            if(matrice[i][j] == 1) 
            {   x1=i;
                y1=j;
                
                while(x1 > 0 && y1 > 0) // diagonala stanga sus
                {   x1--;
                    y1--;
                    matrice[x1][y1]=2;
                }
                x1=i;
                y1=j;

                while(x1 > 0 && y1 < n-1) // diagonala dreapta sus
                {   x1--;
                    y1++;
                    matrice[x1][y1]=2;
                }
                x1=i;
                y1=j;

                while(x1 < n-1 && y1 > 0) // diagonala stanga jos
                {   x1++;
                    y1--;
                    matrice[x1][y1]=2;
                }
                x1=i;
                y1=j;

                while(x1 < n-1 && y1 < n-1) // diagonala dreapta jos
                {   x1++;
                    y1++;
                    matrice[x1][y1]=2;
                }

            }
}


void init(int n, int m, int *alfa, int *beta, int *alfa2, int *beta2, int matrice[][101], int *contor)
{   int ok=1;
    int x,y;
    int x1,y1;
    int x2,y2;
    int x3,y3;
    int x4,y4;
    *contor=0;

    for(int i=0; i < n ; i++)
    {   // citim coordonate nebuni
        scanf("%d%d", &x, &y);
        matrice[x][y]=1;
        // facem copie pt ca parcurgem cu while
        x1=x; 
        x2=x;
        x3=x;
        x4=x;
        y1=y;
        y2=y;
        y3=y;
        y4=y;
        
        while(x1 > 0 && y1 > 0) // diagonala stanga sus
        {   x1--;
            y1--;
            if(matrice[x1][y1] == 1)
            {   *contor=*contor+1; // numaram o pereche care se ataca
                if(*contor == 1)
                {   // daca avem o pereche si presupunem ca e singura, salvam coordonatele
                    *alfa2=x1;
                    *beta2=y1;
                }
            }
        }

        if(*contor == 1 && ok==1) // salvam si coordonatele la celalalt nebun
        {    ok=0;
            *alfa=x;
            *beta=y;
        }

        // analog si pentru celelalte diagonale

        while(x2 > 0 && y2 < m-1) // diagonala dreapta sus
        {   x2--;
            y2++;
            if(matrice[x2][y2] == 1)
            {   *contor=*contor+1;
                if(*contor == 1)
                {   *alfa2=x2;
                    *beta2=y2;
                }
            }
        }

        if(*contor == 1 && ok == 1)
        {   ok=0;
            *alfa=x;
            *beta=y;
        }

        while(x3 < m-1 && y3 > 0) // diagonala stanga jos
        {   x3++;
            y3--;
            if(matrice[x3][y3]==1)
            {   *contor=*contor+1;
                if(*contor == 1)
                {   *alfa2=x3;
                    *beta2=y3;
                }
            }
        }

        if(*contor == 1 && ok == 1)
        {   ok=0;
            *alfa=x;
            *beta=y;
        }

        while(x4 < m-1 && y4 < m-1) // diagonala dreapta jos
        {   x4++;
            y4++;
            if(matrice[x4][y4]==1)
            {   *contor=*contor+1;
                if(*contor == 1)
                {
                    *alfa2=x4;
                    *beta2=y4;
                }
            }
        }

        if(*contor == 1 && ok == 1)
        {    ok=0;
            *alfa=x;
            *beta=y;
        }

    }

}

int main()
{   // pozitia x si y la cei 2 nebuni care se ataca, daca exista o sg pereche
    int alfa,beta,alfa2,beta2;
    int contor=0;
    int test=0;
    int m;

    scanf("%d",&m); // citim dimensiune matrice
    int matrice[101][101]; // matrice in care pozitionam nebuni
    int matrix[101][101]; // matrice in care facem transformari pt a afisa locurile libere
    
    // initializare cu 0 a matricilor
    for(int i=0 ; i < m ; i++) 
        for(int j=0 ; j < m ; j++)
        {   matrice[i][j]=0;
            matrix[i][j]=0;
        }
    
    // citire cati nebuni avem
    int n;
    scanf("%d",&n); 
    // pozitionare nebuni + aflare coordonate
    init(n,m,&alfa,&beta,&alfa2,&beta2,matrice,&contor);

    for(int i=0 ; i < m ; i++)
      for(int j=0 ; j< m ; j++)
        // copiem matricea de pozitii in matrix pt aflare locuri libere
        matrix[i][j]=matrice[i][j]; 
    
    // facem transformare pt a afla locurile libere pt primul nebun
    parcurgere(alfa,beta,matrice,m); 
    // facem transformare pt a afla locurile libere pt 2 lea nebun
    parcurgere(alfa2,beta2,matrix,m);

     for(int i=0 ; i < m ; i++)
    {  for(int j=0 ; j< m ; j++)
        {  if(matrice[i][j] == 0) 
            // verificam daca avem locuri libere pt primul nebun
            test=1;
        }
    }

    for(int i=0 ; i < m ; i++)
    {  for(int j=0 ; j< m ; j++)
        {  if(matrix[i][j] == 0) 
            // verificam daca avem locuri libere pt al doilea nebun
            test=1;
        }
    }

    printf("%d\n", contor); // afisam nr de nebuni

    if(contor > 1)
         printf("NU\n"); // afisam ca NU
    else
         {  // verificam daca exista locuri libere
            if(test == 1) 
            printf("DA\n");
            else
            printf("NU\n");
         }

    return 0;
}
