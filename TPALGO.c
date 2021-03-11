#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef struct mtr
{
    float ** A;
    int m, n;
}mtr;

typedef struct elt_lc
{
    char mot[30];
    struct elt_lc* svt;
}elt_lc;

typedef struct elt_vect
{
    char c;
    struct elt_lc* L;
}elt_vect;

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
bool methGausse(mtr * m1);
char ** constMatMot(char text[500], int n);
int wordCount(char text[500]);
void affMatMot(char** mat, int n);
void FIFO(elt_lc** tete, char mot[30]);
elt_vect* constVectMot(char ** mat, int n);
void affVectMot(elt_vect* V);
void ajoutMot(elt_vect* V);
void SUPP(elt_lc** tete, elt_lc* p);
elt_lc* RechMot(elt_lc* tete, char mot[30]);
void suppMot(elt_vect* V);
void lireText(char * text);

char ** mat;
char text[500];
int n = 0;
elt_vect* V;


void main_menu()
{
    system("clear");
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
            exit(0);
            break;
        default:
            main_menu();
            break;
    }

}

void AOM_menu()
{
    system("clear");
    printf("------------------------------------------AUTRES OPERATIONS SUR LES MATRICES-------------------------------------------\n");
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
    system("clear");
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
    system("clear");
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
            lireText(text);
            n = wordCount(text);
            CLC_menu();
            break;
        case 2:
            if(n == 0)
            {
                printf("\n\nPas de texte\nAppuyez sur ENTRER pour revenir au menu");
                fflush(stdin);
                getchar();
                CLC_menu();
            }
            mat = constMatMot(text, n);
            affMatMot(mat, n);
            fflush(stdin);
            getchar();
            CLC_menu();

            break;
        case 3:

            if(mat == NULL)
            {
                printf("\n\nLa matrice n'a pas ete construite\nAppuyez sur ENTRER pour revenir au menu");
                fflush(stdin);
                getchar();
                CLC_menu();
            }

            affMatMot(mat, n);
            fflush(stdin);
            getchar();
            CLC_menu();

            break;
        case 4:
            if(mat == NULL)
            {
                printf("\n\nLa matrice n'a pas ete construite\nAppuyez sur ENTRER pour revenir au menu");
                fflush(stdin);
                getchar();
                CLC_menu();
            }

            V = constVectMot(mat, n);
            affVectMot(V);
            fflush(stdin);
            getchar();
            CLC_menu();
            
            break;
        case 5:
            if(V == NULL)
            {
                printf("\n\nLa structure n'a pas ete construite\nAppuyez sur ENTRER pour revenir au menu");
                fflush(stdin);
                getchar();
                CLC_menu();
            }

            affVectMot(V);
            fflush(stdin);
            getchar();
            CLC_menu();

            break;
        case 6:
            if(V == NULL)
            {
                printf("\n\nLa structure n'a pas ete construite\nAppuyez sur ENTRER pour revenir au menu");
                fflush(stdin);
                getchar();
                CLC_menu();
            }
            ajoutMot(V);
            affVectMot(V);
            fflush(stdin);
            getchar();
            CLC_menu();

            break;
        case 7:
            if(V == NULL)
            {
                printf("\n\nLa structure n'a pas ete construite\nAppuyez sur ENTRER pour revenir au menu");
                fflush(stdin);
                getchar();
                CLC_menu();
            }
            suppMot(V);
            affVectMot(V);
            fflush(stdin);
            getchar();
            CLC_menu();

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
    system("clear");
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
    system("clear");
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
    system("clear");
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
    system("clear");
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
            if(linDpt(m->A[i], m->A[j], m->m) || linDpt(m2->A[i], m2->A[j], m2->m) || methGausse(m))
            {
                m2 = libererMat(m2);
                return true;
            }
        }
    }

    return false;
}

bool methGausse(mtr * m)
{

    mtr * m1;
    m1 = allMat(m1, m->n, m->m);

    for(int i = 0; i< m1->m; i++)
    {
        for(int j = 0; j<m1->m; j++)
        {
            m1->A[i][j] = m->A[i][j];
        }
    }



    float x, y;

    for(int i = 0; i< m1->n -1 ; i++)
    {
        if(m1->A[i][i] == 0)
        {
            for(int j = i+1; j<m1->m; j++)
            {
                if(m1->A[j][i] == 0)
                {
                    continue;
                }
                else
                {
                    swpVect(m1->A[j], m1->A[i], m1->m);
                    break;
                }
            }
        }
        x = m1->A[i][i];

        if(x==0)
        {
            continue;
        }

        for(int f = 0; f<m1->n; f++)
        {
            m1->A[i][f] = m1->A[i][f] / x;
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
            }

            for(int f = 0; f<m1->n; f++)
            {
                m1->A[j][f] -= m1->A[i][f];
                
            }
            for(int f = 0; f<m1->n; f++)
            {
                m1->A[i][f] = m1->A[i][f] / y;
            }
        }
    }

    x = 1;
    for(int i = 0; i< m1->m; i++)
    {
        x = x * m1->A[i][i];
    }

    m1 = libererMat(m1);

    if(x == 0)
    {
        return true;
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
    system("clear");
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


    float x,y,z;

    for(int i = 0; i< m1->n -1 ; i++)
    {
        if(m1->A[i][i] == 0)
        {
            for(int j = i+1; j<m1->m; j++)
            {
                if(m1->A[j][i] == 0)
                {
                    continue;
                }
                else
                {
                    swpVect(m1->A[j], m1->A[i], m1->m);
                    swpVect(m2->A[j], m2->A[i], m2->m);
                    break;
                }
            }

        }

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
    system("clear");
    printf("------------------------------------------------INVERSE DE MATRICE-----------------------------------------------\n");
    printf("\n>> Entrez la matrice:\n");

    m = lireMat(m);

    if(detNul(m) || m->m != m->n)
    {
        printf("\n>> la matrice n'est pas inversible");
        m = libererMat(m);
        printf("\nAppuyez sur ENTRER pour continuer");
        fflush(stdin);
        getchar();
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

    system("clear");
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
    system("clear");
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
    system("clear");
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

void kMat()
{
    system("clear");
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

void lireText(char * text)
{
    system("clear");
    printf("\nEntrez le texte:\n");
    fflush(stdin);
    gets(text);
}

bool ischar(char c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

char ** constMatMot(char text[500], int n)
{
    char** mat;
    char x[30];
    int j, k= 0, m;

    mat = (char**)malloc((n)*sizeof(char*));

    for(int i=0; i<strlen(text); i++)
    {
        if(!ischar(text[i]))
        {
            continue;
        }

        j = 0;
        m = i;

        while(text[i] != ' ' && i<strlen(text))
        {
            j++;
            i++;
        }

        while(!ischar(text[m+j-1]))
        {
            j--;
        }

        mat[k] = (char*)malloc((j+1)*sizeof(char));

        i = m;
        for(int n=0; n<j; n++)
        {
            mat[k][n]  = text[i];
            i++;
        }
        mat[k][j] = '\0';
        
        k++;
    }
    printf("\nMatrice construite.\nAppuyez sur ENTRER por continuer");
    fflush(stdin);
    getchar();
    return(mat);

}

int wordCount(char text[500])
{
    int count = 1;
    for (int i = 0;text[i] != '\0';i++)
    {
        if (text[i] == ' ' && text[i+1] != ' ')
        {
            count++;
        }
    }

    return count;
}

void affMatMot(char** mat, int n)
{
    system("clear");
    printf("\n\nAffichage de la matrice de mots:\n\n");
    for(int i =0; i<n; i++)
    {
        puts(mat[i]);
    }
    printf("/\n\nAffichage termine\nApuuyez sur ENTRER por continuer\n");
    
}

void FIFO(elt_lc** tete, char mot[30])
{
    elt_lc* p, *q;
    p = (elt_lc*)malloc(sizeof(elt_lc));
    strcpy(p->mot, mot);
    p->svt = NULL;

    if(*tete == NULL)
    {
        *tete = p;
    }
    else
    {
        q = *tete;

        while(q->svt != NULL)
        {
            q = q->svt;
        }

        q->svt = p;
    }
}

elt_vect* constVectMot(char ** mat, int n)
{
    elt_vect* V;
    V = (elt_vect*)malloc(26*sizeof(elt_vect));
    char c = 'a';
    for(int i = 0; i<26; i++)
    {
        V[i].c = c;
        V[i].L = NULL;
        c++;
    }

    for(int i = 0; i<26; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if((int)mat[j][0] == (int)V[i].c || (int)mat[j][0] + 32 == (int)V[i].c)
            {
                FIFO(&(V[i].L), mat[j]);
            }
        }
    }
    printf("\n\nStructure Construite\nApuuywz sur ENTRER pour continuer\n");
    return(V);
}

void affVectMot(elt_vect* V)
{
    elt_lc* p;
    system("clear");
    printf("\n\nAffichage de la structure de mots:\n\n");

    for(int i = 0; i<26; i++)
    {
        if(V[i].L != NULL)
        {
            printf("\n%c: ", V[i].c - 32);
            p = V[i].L;
            while(p!=NULL)
            {
                puts(p->mot);
                p = p->svt;
            }

        }
    }
    printf("\n\nAffichage termine\nAppuyez sur ENTRER pour continuer");
}

void ajoutMot(elt_vect* V)
{
    char x[30];
    system("clear");
    printf("\n\nDonner le mot a ajouter:");
    fflush(stdin);
    gets(x);

    for(int i = 0; i<26; i++)
    {
        if((int)V[i].c == (int)x[0] || (int)V[i].c - 32 == (int)x[0])
        {
            FIFO(&(V[i].L), x);
        }
    }
    printf("\n\nMOT AJOUTE\nApuuyez sur ENTRER por continuer\n");
}

void SUPP(elt_lc** tete, elt_lc* p)
{
    elt_lc *q;

    if(*tete == p)
    {
        *tete = p->svt;
        free(p);
    }
    else
    {
        q = *tete;

        while(q->svt != p)
        {
            q = q->svt;
        }

        q->svt = p->svt;
        free(p);
    }
}

elt_lc* RechMot(elt_lc* tete, char mot[30])
{
    elt_lc* p;
    p = tete;
    while(p!= NULL)
    {
        if(strlen(p->mot) == strlen(mot))
        {
            bool ident = true;
            int i = 0;

            while(ident && i < strlen(p->mot))
            {
                if((int)p->mot[i] != (int)mot[i])
                {
                    ident = false;
                }
                i++;
            }

            if(ident)
            {
                return p;
            }
        }
        p = p->svt;
    }
    return p;
}

void suppMot(elt_vect* V)
{
    char x[30];
    int y;
    system("clear");
    printf("\n\nDonner le mot a supprimer:");
    fflush(stdin);
    gets(x);

    bool find = false;
    for(int i = 0; i<26; i++)
    {
        if((int)V[i].c == (int)x[0] || (int)V[i].c -32 == (int)x[0])
        {
            if(RechMot(V[i].L, x) != NULL);
            {
                find = true;
                SUPP(&(V[i].L), RechMot(V[i].L, x));
            }
        }
    }

    if(find)
    {
        printf("\n\nMOT SUPPRIME\nAppuyez sur ENTRER pour continuer");
    }
    else
    {
        printf("\n\nLe mot n'existe pas dans la structure.\nAppuyez sur ENTRER pour continuer");
    }
}

int main()
{
    
    main_menu();

    return 0;
}
