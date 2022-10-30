#include <stdio.h>
#include <stdlib.h>

///// Fonction Pour Simplifer
void AffichageMat(int *mat, int taille)
{
  for (int j = 0; j < taille; j++)
    {
      printf("|%d|", mat[j]);
    }
  printf("\n");
}
void AffichageMat2D(int **mat, int taille)
{
  printf("\n");
  for (int j = 0; j < taille; j++)
    {
      AffichageMat(mat[j], taille);
    }
  printf("\n");
}
/////





int * chemin(int ** M, int N,int posX,int posY,int * longueur)
{
  int longueurActuelle = *longueur;
  *longueur += 1;
  int * resultatD;
  int posD = *longueur;
  int * resultatB;
  int posB = *longueur;
  int passageDroite = 0;
  int passageBas = 0;

  if (posX+1 < N && (M[posX+1][posY] >= M[posX][posY] -1 &&  M[posX+1][posY] <= M[posX][posY] +1))
    {
      resultatB = chemin(M,N,posX+1,posY,&posB);
      passageBas = 1;
    }
  if (posY+1 < N && (M[posX][posY+1] >= M[posX][posY] -1 && M[posX][posY+1] <= M[posX][posY] +1))
    {
      resultatD =  chemin(M,N,posX,posY+1,&posD);
      passageDroite = 1;
    }
  if(passageDroite && passageBas)
    {
      if(posB > posD)
	{
	  resultatB[longueurActuelle] = M[posX][posY];
	  *longueur = posB;
	  free(resultatD);	
	  return resultatB;
	}
      else
	{
	  resultatD[longueurActuelle] = M[posX][posY];
	  *longueur = posD;
	  free(resultatB);
	  return resultatD;
	}
    }
  else if (passageDroite)
    {
      resultatD[longueurActuelle] = M[posX][posY];
      *longueur = posD;
      return resultatD;
    }
  else if (passageBas)
    {
      resultatB[longueurActuelle] = M[posX][posY];
      *longueur = posB;
      return resultatB;
    }
  else
    {
      int * resultat = malloc(sizeof(int) * (*longueur));
      resultat[longueurActuelle] = M[posX][posY];
      return resultat;
    }
}


int * RechercheSuite(int ** M,int N)
{
  int * resultat = NULL;
  int tailleResultat = 0;
  int  tailleActuelle = 0;
  int * cheminActuelle;
  int i;
  
  for (i = 0; i <N ;i++)
    {
      cheminActuelle = chemin(M,N,0,i,&tailleActuelle);
      
      if(tailleActuelle > tailleResultat)
	{
	  if(resultat != NULL)
	    {
	   free(resultat);
	    }
	  resultat = cheminActuelle;
	  tailleResultat = tailleActuelle;
	}
      else
	{
	  free(cheminActuelle);
	}
      tailleActuelle = 0;
      cheminActuelle = NULL;
    }

  AffichageMat(resultat,tailleResultat);
  return resultat;
  
}


int main()
{
  int N;
  printf("taille du tableau :");
  scanf("%d",&N);
  int ** M = malloc(N*sizeof(int*));
  
  for (int i = 0; i < N;i++)
    {
      M[i] = malloc(N*sizeof(int));
    }
  
  for (int i = 0;i< N;i++)
    {
      for(int j = 0; j <N;j++)
	{
	  printf("\nValeur pour la case[i][j] :");
	  scanf("%d",&M[i][j]);
	}
    }
  
  AffichageMat2D(M,N);
  int * suite = RechercheSuite(M,N);
  free(suite);
  return 0;
}
