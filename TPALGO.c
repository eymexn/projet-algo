#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef struct mtr
{
    float ** A;
    int m, n;
}mtr;


mtr * libererMat(mtr * m);
mtr * allMat(mtr* mat, int n, int m);
mtr * lireMat(mtr *m);
void affMat(mtr * m);
mtr* addMat();
void AOM_menu();
void OAP_menu();
void CLC_menu();
mtr* diffMat();
mtr* mulMat();
mtr* prdMat();
mtr * idMat(mtr * m1);
mtr * invMat(mtr * m);
mtr * echMat(mtr * m1);
mtr * triMat(mtr * m);
mtr * trnsmat();
mtr * transMat(mtr * m1);
bool detNul(mtr * m);
bool linDpt(float *a, float *b, int m);
void Maxligne();
void MaxColonne();
void affvect(float * vect, int n);
void swpVect(float * a, float * b, int n);
void kMat();


void main_menu()
{
    system("cls");
    printf("----------------------------------------------------MENU PRINCIPAL-----------------------------------------------------\n");
    int x;
    printf("\n\n\n\t\t\t\t1. Operations Arithmetiques sur les matrices");
    printf("\n\n\n\t\t\t\t2. Autres operations sur les matrices");
    printf("\n\n\n\t\t\t\t3. Chaine de caracteres et listes chainees");
    printf("\n\n\n\t\t\t\t4. Quitter\n");
    printf("\n\n\n>> Entrer un nombre: ");
    scanf("%i", &x);
    switch(x)
    {
        case 1:
            OAP_menu();
            break;
        case 2:
            AOM_menu();
            break;
        case 3:
            CLC_menu();
            break;
        case 4:
            break;
        default:
            main_menu();
            break;
    }

}

void AOM_menu()
{
    system("cls");
    printf("------------------------------------------AUTRES OPERATIOS SUR LES MATRICES-------------------------------------------\n");
    int x;
    printf("\n\n\n\t\t\t\t\t1. Transposee d'une matrice");
    printf("\n\n\n\t\t\t\t\t2. Tri d'une matrice");
    printf("\n\n\n\t\t\t\t\t3. Calcul du vecteur Maxligne");
    printf("\n\n\n\t\t\t\t\t4. Calcul du vecteur Maxcolonne");
    printf("\n\n\n\t\t\t\t\t5. Extraction de sous-matrices");
    printf("\n\n\n\t\t\t\t\t6. Retour\n");

    printf("\n\n\n>> Entrer un nombre: ");
    scanf("%i", &x);

    mtr * m;

    switch(x)
    {
        case 1:
            m = trnsmat();
            affMat(m);
            m = libererMat(m);
            AOM_menu();
            break;
        case 2:
            m = triMat(m);
            affMat(m);
            m = libererMat(m);
            AOM_menu();
            break;
        case 3:
            Maxligne();
            AOM_menu();
            break;
        case 4:
            MaxColonne();
            AOM_menu();
            break;
        case 5:
            kMat();
            AOM_menu();
            break;
        case 6:
            main_menu();
            break;
        default:
            AOM_menu();
            break;
        
    }

}

void OAP_menu()
{
    system("cls");
    printf("---------------------------------------------OPERATIONS SUR LES MATRICES----------------------------------------------\n");
    printf("\n\n\n\t\t\t\t1. Somme de deux matrices");
    printf("\n\n\n\t\t\t\t2. Difference de deux matrices");
    printf("\n\n\n\t\t\t\t3. Multipliction d'une matrice par un nombre");
    printf("\n\n\n\t\t\t\t4. Produit de deux matrices");
    printf("\n\n\n\t\t\t\t5. Inverse d'une matrice");
    printf("\n\n\n\t\t\t\t6. Retour\n");

    printf("\n\n\n>> Entrer un nombre: ");

    int x;
    mtr * m;
    scanf("%i", &x);
    switch(x)
    {
        case 1:
            m = addMat();
            affMat(m);
            libererMat(m);
            OAP_menu();
            break;
        case 2:
            m = diffMat();
            affMat(m);
            libererMat(m);
            OAP_menu();
            break;
        case 3:
            m = mulMat();
            affMat(m);
            libererMat(m);
            OAP_menu();
            break;
        case 4:
            m = prdMat();
            affMat(m);
            libererMat(m);
            OAP_menu();
            break;
        case 5:
            m = invMat(m);
            affMat(m);
            libererMat(m);
            OAP_menu();
            break;
        case 6:
            main_menu();
            break;
        default:
            OAP_menu();
            break;
    }

}

void CLC_menu()
{
    system("cls");
    printf("----------------------------------------CHAINE DE CARACTERES ET LISTES CHAINEES-----------------------------------------\n");
    int x;
    printf("\n\n\t\t\t\t\t1. Saisie de texte");
    printf("\n\n\n\t\t\t\t\t2. Creation de la marice de mots");
    printf("\n\n\n\t\t\t\t\t3. Affichage de la matrice");
    printf("\n\n\n\t\t\t\t\t4. Creation de la stucture des listes");
    printf("\n\n\n\t\t\t\t\t5. Afficahge de la structure");
    printf("\n\n\n\t\t\t\t\t6. Ajout d'un mot");
    printf("\n\n\n\t\t\t\t\t7. Suppression d'un mot");
    printf("\n\n\n\t\t\t\t\t8. Retour\n");

    printf("\n\n\n>> Entrer un nombre: ");
    scanf("%i", &x);
    switch(x)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            main_menu();
            break;
        default:
            CLC_menu();
            break;
        
    }

}

mtr * lireMat(mtr *mat)
{
    int m, n;
    do
    {
        printf("\n>> Entrez n: ");
        scanf("%i", &n);
    } while (n<0 || n > 30);
    
    do
    {
        printf(">> Entrez m: ");
        scanf("%i", &m);
    } while (m<0 || m > 30);

    mat = allMat(mat, n, m);

    printf("\n");
    for(int i =0; i < mat->n; i++)
    {
        printf(">> Entrez les elements de la ligne %i:\n", i+1);
        for(int j = 0; j < mat->m; j++)
        {
            scanf("%f", &mat->A[i][j]);
        }
    }
    return mat;
    
}

void affMat(mtr * m)
{
    printf("\n\t\t\t\t\tRESULTAT:\n");
    printf("\n");
    for(int i = 0 ; i<m->n; i++)
    {
        printf("\t\t\t\t\t");
        for(int j = 0; j< m->m; j++)
        {
            printf("%.2f\t\t", m->A[i][j]);
        }
        printf("\n\n");
    }
    printf("\n\n\n\n\n\n");
    printf("\nAppuyez sur ENTRER pour revenir au menu");
    fflush(stdin);
    getchar();
}

mtr * allMat(mtr* mat, int n, int m)
{
    mat = (mtr*)malloc(sizeof(mtr));
    mat->m = m;
    mat->n = n;
    mat->A = (float**)malloc(mat->n*sizeof(float*));
    for(int i = 0; i<mat->n; i++)
    {
        mat->A[i] = (float*)malloc(mat->m*sizeof(float));
    }

    return mat;
}

mtr * libererMat(mtr * m)
{
    if(m->A == NULL)
    {
        return m;
    }
    for(int i = 0; i< m->m ; i++)
    {
        free(m->A[i]);
    }
    free(m->A);
    m->A = NULL;
    m->n = 0;
    m->m = 0;
    free(m);
    return m;
}

mtr* addMat()
{
    system("cls");
    printf("----------------------------------------------ADDITION DE DEUX MATRICES-----------------------------------------------\n");
    printf("\n\n>> Entrez les deux matrices a additionner:\n");
    mtr * m1;
    mtr * m2;
    mtr * m3;
    do
    {

        printf("\n>> 1ERE MATRICE: ");
        m1 = lireMat(m1);
        printf("\n>> 2EME MATRICE: ");
        m2 = lireMat(m2);
        
    } while (m1->m != m2->m || m1->n != m2->n);

    m3 = allMat(m3, m1->n, m1->m);
    for(int i = 0; i < m1->n ; i++)
    {
        for(int j = 0; j < m1->m ; j++)
        {
            m3->A[i][j] = m1->A[i][j] + m2->A[i][j];
        }
    }
    libererMat(m1);
    libererMat(m2);
    return m3;
}

mtr* mulMat()
{
    system("cls");
    printf("----------------------------------------------MULTIPLICATION DE MATRICE----------------------------------------------\n");
    printf("\n>>Entrez la matrice:\n");
    mtr * m1;
    m1 = lireMat(m1);
    
    int x;
    printf("\n\n>> Entrez un nombre:\n");
    scanf("%i", &x);
    for(int i = 0; i < m1->n ; i++)
    {
        for(int j = 0; j < m1->m ; j++)
        {
            m1->A[i][j] = x * m1->A[i][j];
        }
    }
    return m1;
}

mtr* diffMat()
{
    system("cls");
    printf("----------------------------------------------DIFFERENCE DE DEUX MATRICES-----------------------------------------------\n");
    printf("\n>> Entrez les deux matrices a soustraire:\n");
    mtr * m1;
    mtr * m2;
    mtr * m3;
    do
    {
        printf("\n>> 1ERE MATRICE: ");
        m1 = lireMat(m1);
        printf("\n>> 2EME MATRICE: ");
        m2 = lireMat(m2);
        
    } while (m1->m != m2->m || m1->n != m2->n);

    m3 = allMat(m3, m1->n, m1->m);
    
    for(int i = 0; i < m1->n ; i++)
    {
        for(int j = 0; j < m1->m ; j++)
        {
            m3->A[i][j] = m1->A[i][j] - m2->A[i][j];
        }
    }
    libererMat(m1);
    libererMat(m2);
    return m3;
}

mtr* prdMat()
{
    system("cls");
    printf("----------------------------------------------PRODUIT DE DEUX MATRICES----------------------------------------------\n");
    printf("\n>> Entrez les deux matrices a multiplier:\n");

     mtr * m1;
    mtr * m2;
    do
    {
        printf("\n>> 1ERE MATRICE: ");
        m1 = lireMat(m1);
        printf("\n>> 2EME MATRICE: ");
        m2 = lireMat(m2);
        
    } while (m1->m != m2->n);

   mtr * m3;
   m3 = allMat(m3, m1->n, m2->m);
    
    for(int i = 0; i < m3->n ; i++)
    {
        for(int j = 0; j < m3->m ; j++)
        {
            m3->A[i][j] = 0;
            for(int k = 0; k < m1->m; k++)
            {
                m3->A[i][j] += m1->A[i][k] * m2->A[k][j];
            }
        }
    }
    return m3;
    libererMat(m1);
    libererMat(m2);
    return m3;
}

bool linDpt(float *a, float *b, int m)
{
    bool dpt = true;
    int i;

    for(i = 0; i<m; i++)
    {
        if(a[i] != 0)
        {
            dpt = false;
            break;
        }
    }

    if(i == m && dpt)
    {
        return true;
    }

    dpt = true;
    for(i = 0; i<m; i++)
    {
        if(b[i] != 0)
        {
            dpt = false;
            break;
        }
    }
    if(i == m && dpt)
    {
        return true;
    }

    dpt = true;
    float div;
    bool first = false;
    for(i=0; i<m; i++)
    {
        if(a[i]==0 && b[i] != 0)
        {
            return false;
        }
        else if(b[i]==0 && a[i] != 0)
        {
            return false;
        }
        else if(b[i] == 0 && a[i] == 0)
        {
            continue;
        }

        if(!first)
        {
            div = a[i] / b[i];
            first = true;
            continue;
        }
        else
        {
            if( a[i] / b[i] != div)
            {
                return false;
            }
        }
        
    }
    
    return true;
}

bool detNul(mtr * m)
{
    mtr * m2;
    m2 = (mtr*)malloc(sizeof(mtr));
    m2 = transMat(m);

    for(int i = 0; i<m->n-1; i++)
    {
        for(int j = i+1; j<m->n; j++)
        {
            if(linDpt(m->A[i], m->A[j], m->m) || linDpt(m2->A[i], m2->A[j], m2->m))
            {
                m2 = libererMat(m2);
                return true;
            }
        }
    }

    return false;
}

mtr * transMat(mtr * m1)
{
    mtr * m2;
    m2 = allMat(m2, m1->m, m1->n);

    for(int i = 0; i < m2->n ; i++)
    {
        for(int j = 0; j < m2->m ; j++)
        {
            m2->A[i][j] = m1->A[j][i];
        }
    }
    
    return m2;
}

mtr * trnsmat()
{
    system("cls");
    printf("----------------------------------------------TRANSPOSEE DE MATRICE---------------------------------------------\n");
    printf("\n>> Entrez la matrice:\n");
    mtr * m1;
    m1 = lireMat(m1);
    mtr * m2;
    m2 = transMat(m1);
    m1 = libererMat(m1);
    return m2;
}

void swpVect(float * a, float * b, int n)
{
    float temp;
    for(int i = 0; i<n; i++)
    {
        temp = a[i] ;
        a[i] = b[i];
        b[i] = temp;
    }
}

mtr * echMat(mtr * m1)
{
    mtr * m2;
    m2 = idMat(m1);
    float * p;
    p = (float*)malloc(m1->n*sizeof(float));
    float x,y,z;
    
    for(int i = 0; i< m1->m; i++)
    {
        if(m1->A[i][i] == 0)
        {
            for(int j = i+1; j<m1->m; j++)
            {
                if(m1->A[i+j][i] == 0)
                {
                    continue;
                }
                else
                {
                    swpVect(m1->A[i+j], m1->A[i], m1->m);
                    swpVect(m2->A[i+j], m2->A[i], m2->m);
                    break;
                }
            }

        }

    }


    for(int i = 0; i< m1->n -1 ; i++)
    {
        x = m1->A[i][i];
        for(int f = 0; f<m1->n; f++)
        {
            m1->A[i][f] = m1->A[i][f] / x;
            m2->A[i][f] = m2->A[i][f] / x;
        }

        x = m1->A[i][i];
        for(int j = i+1 ; j<m1->n; j++)
        {
            y = m1->A[j][i];
            if(y == 0)
            {
                continue;
            }

            for(int f = 0; f<m1->n; f++)
            {
                m1->A[i][f] = m1->A[i][f] * y;
                m2->A[i][f] = m2->A[i][f] * y;
            }

            for(int f = 0; f<m1->n; f++)
            {
                m1->A[j][f] -= m1->A[i][f];
                m2->A[j][f] -= m2->A[i][f];
                
            }
            for(int f = 0; f<m1->n; f++)
            {
                m1->A[i][f] = m1->A[i][f] / y;
                m2->A[i][f] = m2->A[i][f] / y;
            }

        }
    }

    for(int i = 0; i< m1->n -1 ; i++)
    {
        x = m1->A[m1->n -1- i][m1->n -1- i];

        for(int f = 0; f<m1->n; f++)
        {
            m1->A[m1->n -1-i][m1->n -1-f] = m1->A[m1->n -1-i][m1->n -1-f] / x;
            m2->A[m2->n -1-i][m2->n -1-f] = m2->A[m2->n -1-i][m2->n -1-f] / x;
        }
        x = m1->A[m1->n -1-i][m1->n -1-i];

        for(int j = i+1 ; j<m1->n; j++)
        {
            y = m1->A[m1->n -1-j][m1->n -1-i];
            if(y == 0)
            {
                continue;
            }

            for(int f = 0; f<m1->n; f++)
            {
                m1->A[m1->n -1-i][f] = m1->A[m1->n -1-i][f] * y;
                m2->A[m2->n -1-i][f] = m2->A[m2->n -1-i][f] * y;
            }

            for(int f = 0; f<m1->n; f++)
            {
                m1->A[m1->n -1-j][f] -= m1->A[m1->n -1-i][f];
                m2->A[m1->n -1-j][f] -= m2->A[m2->n -1-i][f];
                
            }
            for(int f = 0; f<m1->n; f++)
            {
                m1->A[m1->n -1-i][f] = m1->A[m1->n -1-i][f] / y;
                m2->A[m2->n -1-i][f] = m2->A[m2->n -1-i][f] / y;
            }

        }
    }
    
    return m2;
}

mtr * idMat(mtr * m1)
{
    mtr * m2;
    m2 = allMat(m2, m1->n, m1->m);

    for(int i = 0; i < m2->n; i++)
    {
        for(int j = 0; j < m2->m; j++)
    {
        m2->A[i][j] = 0;
    }
    }

    for(int i = 0; i < MIN(m2->m, m2->n); i++)
    {
        m2->A[i][i] = 1;
    }
    return m2;
}

mtr * invMat(mtr * m)
{
    system("cls");
    printf("------------------------------------------------INVERSE DE MATRICE-----------------------------------------------\n");
    printf("\n>> Entrez la matrice:\n");

    m = lireMat(m);

    if(detNul(m) || m->m != m->n)
    {
        printf("\n>> la matrice n'est pas inversible:\n");
        m = libererMat(m);
        sleep(3);
        m = invMat(m);
    }

    mtr * m2;
    m2 = allMat(m2, m->n, m->m);
    m2 = echMat(m);
    m = libererMat(m);
    return m2;

}

mtr * triMat(mtr * m)
{

    system("cls");
    printf("-------------------------------------------------TRI DE MATRICE------------------------------------------------\n");
    printf("\n>> Entrez la matrice:\n");
    m = lireMat(m);

    int x;
    printf("\n1. Ordre Croissant");
    printf("\n2. Ordre Decroissant");
    printf("\n\n Entrez un nombre: ");

    scanf("%i", &x);
    switch(x)
    {
        case 1:
            break;
        case 2:
            break;
        default:
            scanf("%i", &x);
            break;
    }


    float temp;
    for(int i = 0; i<m->n; i++)
    {
        for(int j = 0; j <m->m; j++)
        {
            for(int k =0; k< m->n; k++)
            {
                for(int c =0; c< m->m; c++)
                {
                    if(x == 1)
                    {
                        if(m->A[i][j] < m->A[k][c])
                        {
                            if(c==j && k ==i)
                            {
                                continue;
                            }

                            temp = m->A[i][j];
                            m->A[i][j] = m->A[k][c];
                            m->A[k][c] = temp; 
                        }
                    }
                    else
                    {
                        if(m->A[i][j] > m->A[k][c])
                        {
                            if(c==j && k ==i)
                            {
                                continue;
                            }

                            temp = m->A[i][j];
                            m->A[i][j] = m->A[k][c];
                            m->A[k][c] = temp; 
                        }                        
                    }
                    
                }
            }
        }
    }
    return m;
}

void affvect(float * vect, int n)
{

    printf("\n\t\t\t\t\tRESULTAT:");
    printf("\n\t\t\t\t\t");
    for(int i = 0; i< n; i++)
    {
        printf("%.2f\t", vect[i]);
    }

    printf("\n\n\n\n\n\n");
    printf("\nAppuyez sur ENTRER pour revenir au menu");
    fflush(stdin);
    getchar();
}

void Maxligne()
{
    system("cls");
    printf("-------------------------------------------------VECTEUR MAXLIGNE-----------------------------------------------\n");
    printf("\n>> Entrez la matrice:\n");

    mtr * m;
    m = lireMat(m);


    float * vect;
    vect = (float *)malloc(m->n* sizeof(float));
    float max;

    for(int i = 0; i< m->n; i++)
    {
        max = m->A[i][0];
        for(int j = 0; j< m->m; j++)
        {
            if(m->A[i][j] >max)
            {
                max = m->A[i][j];
            }
        }
        vect[i] =  max;
    }
    
    affvect(vect, m->n);
    m = libererMat(m);

}

void MaxColonne()
{
    system("cls");
    printf("------------------------------------------------VECTEUR MAXCOLONNE-----------------------------------------------\n");
    printf("\n>> Entrez la matrice:\n");

    mtr * m;
    m = lireMat(m);
    m = transMat(m);

    float * vect;
    vect = (float *)malloc(m->n* sizeof(float));
    float max;

    for(int i = 0; i< m->n; i++)
    {
        max = m->A[i][0];
        for(int j = 0; j< m->m; j++)
        {
            if(m->A[i][j] >max)
            {
                max = m->A[i][j];
            }
        }
        vect[i] =  max;
    }
    
    affvect(vect, m->n);
    m = libererMat(m);

}

void slow_type(char string[100])
{
    long  d = 100000;
    for(int i=0; i<strlen(string); i++)
    {
        printf("%c", string[i]);
        usleep(d);
    }
    printf("\n");
}

void intro()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t");
    slow_type("PROJET TP ALGO");
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t");
    slow_type("Par:");
    printf("\t\t\t\t\t\t\t\t\t\t");
    slow_type("- ZITOUNI AYMEN ABDESSALEM");
    printf("\t\t\t\t\t\t\t\t\t\t");
    slow_type("- EL FECIH SARAH");
    printf("\n\nAppuyez sur ENTRER pour continuer");
    getchar();
}

void kMat()
{
    system("cls");
    printf("--------------------------------------------EXTRACTION DE SOUS MATRICES----------------------------------------------\n");
    printf("\n\n>> Entrez la matrice:\n");
    mtr * m;
    m = lireMat(m);
    printf(">> Le nombre de sous matrices: %d", (m->m*(m->m+1)*m->n*(m->n+1))/4);
    printf("\n>> Appuyez sur ENTRER pour les afficher\n\n\n");
    fflush(stdin);
    getchar();


    int count = 1;

    for(int i = 0; i< m->n; i++)
    {
        for(int j = 0; j< m->m; j++)
        {
            for(int x = 0; x < m->n - i ; x++)
            {
                for(int y = 0; y < m->m - j; y++)
                {
                    
                    printf("\t\t\t\t\tMATRICE n%i (%ix%i):\n\n", count, x+1, y+1);
                    for(int k = i ; k < x+i+1; k++)
                    {
                        printf("\t\t\t\t\t");
                        for(int l = j; l< y+j+1 ; l++)
                        {
                            printf("%.1f\t", m->A[k][l]);
                        }
                        printf("\n\n");
                    }
                    printf("\n\n\n");
                    count++;
                }
            }
        }
    }
    
    fflush(stdin);
    getchar();
    m = libererMat(m);

}
int main()
{

    main_menu();

    return 0;
}