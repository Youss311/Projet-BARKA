#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int taille;
/*:::::::::::::::::::::::::::::::::::::::::::::::
  definir deux types de variables : 
  1-type PIECE : QUI PEUT ETRE <LION ELEPHANT SOURIS >
  2-type couleur_piece :qui peu prendre BLANCHE ou NOIRE 
  ::::::::::::::::::::::::::::::::::::::::::::::::*/

typedef enum{ LION , ELEPHANT , SOURIS, RIEN} PIECE; 
typedef enum{ BLANCHE , NOIRE, NEUTRE } couleur_piece; 
/*:::::::::::::::::::::::::::::::::::::::::::::::*/
typedef enum{ point_eau, vide} type_case;
/*typedef enum{blanc ,noir} JOUEURS;*/

typedef struct Pieces
{
  PIECE nom;
  couleur_piece couleur;
} Pieces;

typedef struct plateau_Barca {
  type_case type_cs;
  Pieces piece;
				
}plateau_Barca;

typedef struct joueur
{
  couleur_piece camp;
}joueur;

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
			
void taille_plateau(){

  printf("\t\t\033[33m\033[1mCommencez par choisir la taille du plateau sur lequel vous voulez jouer\033[0m  :\n\t\t  (ex: si vous choisissez 10 ca donne un plateau==> 10x10) :\n\t ");
  printf("\t\t(NB: VOUS NE POUVEZ PAS JOUER SUR UN PLATEAUDE TAILLE INFERIEUR A 6 )\t");
  scanf("%d",&taille);

}

void creation_table_barca(plateau_Barca plateau[taille][taille]){
				
  int i,j;
				
				
  for (i = 0; i < taille; i++)          /*creation et initialisation des cases du plteau*/
    {
      for (j = 0; j < taille; j++)
	{
	  plateau[i][j].type_cs=vide;
	  plateau[i][j].piece.nom =RIEN ;
	  plateau[i][j].piece.couleur =NEUTRE;
	}
    }
}

/* =================================== initialisation points d'eau::::::::::::::::::::::::::::::::::::::*/


void initialisation_points_eau (plateau_Barca plateau[taille][taille]){
  if(taille%2==0){ 
    plateau[((taille-1)/2)-1][((taille-1)/2)-1].type_cs = point_eau;
    plateau[((taille-1)/2)-1][((taille-1)/2)+2].type_cs = point_eau;
    plateau[((taille-1)/2)+2][((taille-1)/2)+2].type_cs = point_eau;
    plateau[((taille-1)/2)+2][((taille-1)/2)-1].type_cs = point_eau;
				 	
  }
  else{
    plateau[((taille-1)/2)-1][((taille-1)/2)-1].type_cs = point_eau;
    plateau[((taille-1)/2)+1][((taille-1)/2)-1].type_cs = point_eau;
    plateau[((taille-1)/2)-1][((taille-1)/2)+1].type_cs = point_eau;
    plateau[((taille-1)/2)+1][((taille-1)/2)+1].type_cs = point_eau;
  }
			 
}
/*========================================initialisation des pions========================================*/


void initialisation_pieces(plateau_Barca plateau[taille][taille]){
  /*=================================les pieces noires=====================================*/
  if (taille%2==0)
    {
      plateau[0][((taille-1)/2)-1].piece.nom =LION ;
      plateau[0][((taille-1)/2)-1].piece.couleur =BLANCHE;
      plateau[0][((taille-1)/2)].piece.nom =ELEPHANT ;
      plateau[0][((taille-1)/2)].piece.couleur =BLANCHE;
      plateau[0][((taille-1)/2)+1].piece.nom =ELEPHANT ;
      plateau[0][((taille-1)/2)+1].piece.couleur =BLANCHE;
      plateau[0][((taille-1)/2)+2].piece.nom =LION ;
      plateau[0][((taille-1)/2)+2].piece.couleur =BLANCHE;
      plateau[1][((taille-1)/2)].piece.nom =SOURIS ;
      plateau[1][((taille-1)/2)].piece.couleur =BLANCHE;
      plateau[1][((taille-1)/2)+1].piece.nom =SOURIS ;
      plateau[1][((taille-1)/2)+1].piece.couleur =BLANCHE;




    }
  else{
    plateau[0][((taille-1)/2)-2].piece.nom =LION ;
    plateau[0][((taille-1)/2)-2].piece.couleur =BLANCHE;
    plateau[0][((taille-1)/2)-1].piece.nom =ELEPHANT ;
    plateau[0][((taille-1)/2)-1].piece.couleur =BLANCHE;
    plateau[0][((taille-1)/2)+1].piece.nom =ELEPHANT ;
    plateau[0][((taille-1)/2)+1].piece.couleur =BLANCHE;
    plateau[0][((taille-1)/2)+2].piece.nom =LION ;
    plateau[0][((taille-1)/2)+2].piece.couleur =BLANCHE;
    plateau[1][((taille-1)/2)-1].piece.nom =SOURIS ;
    plateau[1][((taille-1)/2)-1].piece.couleur =BLANCHE;
    plateau[1][((taille-1)/2)+1].piece.nom =SOURIS ;
    plateau[1][((taille-1)/2)+1].piece.couleur =BLANCHE;
  }
  /*=================================les pieces noires=====================================*/
  if (taille%2==0)
    {
      plateau[taille-1][((taille-1)/2)-1].piece.nom =LION ;
      plateau[taille-1][((taille-1)/2)-1].piece.couleur =NOIRE;
      plateau[taille-1][((taille-1)/2)].piece.nom =ELEPHANT ;
      plateau[taille-1][((taille-1)/2)].piece.couleur =NOIRE;
      plateau[taille-1][((taille-1)/2)+1].piece.nom =ELEPHANT ;
      plateau[taille-1][((taille-1)/2)+1].piece.couleur =NOIRE;
      plateau[taille-1][((taille-1)/2)+2].piece.nom =LION ;
      plateau[taille-1][((taille-1)/2)+2].piece.couleur =NOIRE;
      plateau[taille-2][((taille-1)/2)].piece.nom =SOURIS ;
      plateau[taille-2][((taille-1)/2)].piece.couleur =NOIRE;
      plateau[taille-2][((taille-1)/2)+1].piece.nom =SOURIS ;
      plateau[taille-2][((taille-1)/2)+1].piece.couleur =NOIRE;




    }
  else{
    plateau[taille-1][((taille-1)/2)-2].piece.nom =LION ;
    plateau[taille-1][((taille-1)/2)-2].piece.couleur =NOIRE;
    plateau[taille-1][((taille-1)/2)-1].piece.nom =ELEPHANT ;
    plateau[taille-1][((taille-1)/2)-1].piece.couleur =NOIRE;
    plateau[taille-1][((taille-1)/2)+1].piece.nom =ELEPHANT ;
    plateau[taille-1][((taille-1)/2)+1].piece.couleur =NOIRE;
    plateau[taille-1][((taille-1)/2)+2].piece.nom =LION ;
    plateau[taille-1][((taille-1)/2)+2].piece.couleur =NOIRE;
    plateau[taille-2][((taille-1)/2)-1].piece.nom =SOURIS ;
    plateau[taille-2][((taille-1)/2)-1].piece.couleur =NOIRE;
    plateau[taille-2][((taille-1)/2)+1].piece.nom =SOURIS ;
    plateau[taille-2][((taille-1)/2)+1].piece.couleur =NOIRE;
  }
}
/*========================================================================================================*/

/*========================================gerer les deplacements==========================================

  cette fonction renvoie 1 si le deplacement vers la case souhaité est dans les
  normes sinon elle renvoie 0 et si c'est hors cadre ele renvoie 2*/

int deplacement_normes(plateau_Barca plateau[taille][taille],int i,int j,int i_input,int j_input){
  
  if(i_input>=0 && i_input<taille && j_input>=0 && j_input<taille){
						
					
				
    if (plateau[i][j].piece.nom == SOURIS || plateau[i][j].piece.nom == ELEPHANT ){
      if (((i==i_input && j!= j_input) || (j==j_input && i!= i_input)) && (j_input-j!=i_input-i || j_input-j!=-(i_input-i)))
	{
	  return 1;
	}
    }
    if ((plateau[i][j].piece.nom == LION || plateau[i][j].piece.nom == ELEPHANT) && (i_input!=i && j_input!=j) ){
      if (j_input-j==i_input-i || j_input-j==-(i_input-i))
	{
	  return 1;
	}
    }
					
    return 0;

  }else{ 
    
    return 2;
  }
}		

/*==================================================================================================*/
/*============================fonction qui verifie si le coup est dans le plateau retourne 1 si c =========
									dans le cade ou 0 sinon */
int dans_plateau(int i, int j){  
  if (i <= taille-1 && i >=0  && j<= taille-1 && j>= 0) 
    return 1;
  return 0;


}/*========================================================================================================*/
				

int piece_ou_pas(plateau_Barca plateau[taille][taille], int i, int j){
  if (plateau[i][j].piece.nom == RIEN  )
    {
      return 0;
    }
  if(dans_plateau(i,j)==0)
    return 2;
  return 1;

}

/*======================================pas sauter une autre piece=======================================*/

int pas_sauter(plateau_Barca plateau[taille][taille],int i,int j,int i_input,int j_input){
  int r;
 if(deplacement_normes(plateau,i,j,i_input,j_input)==1){ /*on a mis ce if pour que si ce n'est pas dans les 
 															normes de deplacement c'est la 
 															fonction deplacement normes qui 
 															s'en auccupe et qu'il ny ait pas
 														    d'embrouilles dans la fonction joue*/
  /*=================================pas saut souris=========================================*/
  if ((plateau[i][j].piece.nom == SOURIS || plateau[i][j].piece.nom == ELEPHANT) && (i == i_input || j== j_input) ){
    if( j>j_input ){
      for (r= 1; r<=j- j_input ; r++){
	  if (plateau[i][j-r].piece.nom != RIEN   )
	    {						
	      return 1;
	    }
	}
    }
    if(i>i_input){	
	    for (r= 1; r <= i- i_input; r++) {
		  if( plateau[i-r][j].piece.nom != RIEN ){
		    return 1;
		  }
		}
    }

    if( j<j_input){
	      for (r= 1; r <= j_input - j; r++)
		{
		  if (plateau[i][j+r].piece.nom != RIEN ) {						
		      return 1;
		   }
		}
    }
    if(i<i_input ){
      for (r= 1; r <=i_input - i; r++) {
		  if (plateau[i+r][j].piece.nom != RIEN ){
		    return 1;
		  }
		}
    }				
  }
  /*==================================pas saut lion==========================================*/

  if ((plateau[i][j].piece.nom == LION || plateau[i][j].piece.nom == ELEPHANT) && (i != i_input || j!= j_input)  ){
    if (i_input<i && j_input<j ){
		for (r= 1; r <= j- j_input; r++)
		  {
		    if (plateau[i-r][j-r].piece.nom != RIEN )
		      {								
			return 1;
		      }
		  }
      }
    if (i_input>i && j_input>j ) {
		for (r= 1; r <= j_input-j; r++){
		    if (plateau[i+r][j+r].piece.nom != RIEN ){	
			return 1;
		    }
		}
     }
    if (i_input<i && j_input>j) {
		for (r= 1; r <= j_input-j; r++){
		    if (plateau[i-r][j+r].piece.nom != RIEN ){						
			return 1;
		      }
	 	 }
    }
    if (i_input>i && j_input<j) {
		for (r= 1; r <= j- j_input; r++){
	    	if (plateau[i+r][j-r].piece.nom != RIEN ){
			return 1;
	      	}
	  	}
      }
  }
 }
  return 0;
}


/*==================================================================================================*/



/*====================================zone effroi===============================================
  cette fonction retoure 1 si le deplacement est imossible car il y a effroi et 0 sinon  */

int effroi(plateau_Barca plateau[taille][taille],int i,int j,int i_input,int j_input){
  int r,k,z;
 			
	  for (r = -1; r <=1; r++)
	    {
	      for (k = -1; k <= 1; k++)
		 {
		  z=dans_plateau(i_input+r,j_input+k);
		  if(z==1){
		    if(plateau[i][j].piece.nom == LION){
		      if (plateau[i_input+r][j_input+k].piece.nom == ELEPHANT && plateau[i_input+r][j_input+k].piece.couleur !=  plateau[i][j].piece.couleur )
			{
			  return 1;
			}
		    }
		    if(plateau[i][j].piece.nom == SOURIS){
		      if (plateau[i_input+r][j_input+k].piece.nom == LION && plateau[i_input+r][j_input+k].piece.couleur !=  plateau[i][j].piece.couleur )
			{
			  return 1;
			}
		    }
		    if(plateau[i][j].piece.nom == ELEPHANT){
		      if (plateau[i_input+r][j_input+k].piece.nom == SOURIS && plateau[i_input+r][j_input+k].piece.couleur !=  plateau[i][j].piece.couleur )
			{
			  return 1;

			}
		    }
		  }
		 }
	    }
 
  return 0;
}



/*==================================================================================================*/

/*============================================début ==============================================*/
void debut(){
	int i;
	for ( i = 0; i < 13;i++)
	{
		printf("\033[44m//////////\033[00m");
	}
	printf("\n\n");
	
  printf("\t\t\t\t\033[41m _____\033[00m                                                            \n");
  printf("\t\t\t\t\033[41m __\033[00m   \033[41m-__\033[00m          \033[41m_\033[00m          \033[41m_____\033[00m             \033[41m___\033[00m       \033[41m_\033[00m       \n ");
  printf("\t\t\t\t\033[41m__\033[00m    \033[41m__\033[00m         \033[41m_ _\033[00m         \033[41m__\033[00m    \033[41m__\033[00m       \033[41m__\033[00m          \033[41m_ _\033[00m      \n ");
  printf("\t\t\t\t\033[41m__\033[00m   \033[41m__\033[00m         \033[41m_\033[00m   \033[41m_\033[00m        \033[41m__\033[00m     \033[41m__\033[00m    \033[41m__\033[00m           \033[41m_\033[00m   \033[41m_\033[00m     \n");
  printf("\t\t\t\t\033[41m __\033[00m  \033[41m__\033[00m         \033[41m_\033[00m     \033[41m_\033[00m       \033[41m__\033[00m     \033[41m__\033[00m   \033[41m__\033[00m           \033[41m_\033[00m     \033[41m_\033[00m    \n");
  printf("\t\t\t\t\033[41m __\033[00m \033[41m__\033[00m         \033[41m_ _____ _\033[00m      \033[41m__\033[00m  \033[41m___\033[00m    \033[41m__\033[00m           \033[41m_ _____ _\033[00m   \n");
  printf("\t\t\t\t\033[41m __\033[00m   \033[41m__\033[00m       \033[41m_ _____ _\033[00m      \033[41m__\033[00m   \033[41m__\033[00m    \033[41m__\033[00m           \033[41m_ _____ _\033[00m   \n");
  printf("\t\t\t\t\033[41m __\033[00m     \033[41m__\033[00m     \033[41m_\033[00m       \033[41m_\033[00m      \033[41m__\033[00m    \033[41m__\033[00m    \033[41m__\033[00m          \033[41m_\033[00m       \033[41m_\033[00m   \n");
  printf("\t\t\t\t\033[41m __\033[00m     \033[41m__\033[00m     \033[41m_\033[00m       \033[41m_\033[00m      \033[41m__\033[00m     \033[41m__\033[00m    \033[41m__\033[00m         \033[41m_\033[00m       \033[41m_\033[00m   \n");
  printf("\t\t\t\t\033[41m __ __ -\033[00m       \033[41m_\033[00m       \033[41m_\033[00m      \033[41m__\033[00m      \033[41m__\033[00m       \033[41m__\033[00m     \033[41m_\033[00m       \033[41m_\033[00m   \n\n");
  	for ( i = 0; i < 13;i++)
	{
		printf("\033[44m//////////\033[00m");
	}
	printf("\n\n\n\n");
}

/*=============================================================================================*/	

/*==================================affichage===========================================================*/




void affichage(plateau_Barca plateau[taille][taille]){
  int i,j,e,u=0;

  for (i = 0; i < taille; i++)
    printf("   \033[36;01mj_%d\033[00m  ",i);     /*premiere ligne*/
  printf("\n.");

  for (i = 0; i < taille; i++)
    printf("________");     /*premiere ligne*/
  printf("\n|");


  for (j = 0; j < taille; j++)
    {
      if(j%2==0)
	printf("\033[41m       \033[0m|");
      else 
	printf("       |");
    }
  printf("\n");

  for (i = 0; i < taille; i++)
    {
	      for (j = 0; j < taille; j++)
		{

			  if ((i%2==0 && j%2==0) || (i%2!=0 && j%2!=0) )
			    {			
				      if (plateau[i][j].type_cs == point_eau && plateau[i][j].piece.nom ==RIEN)
					{
					  printf("|\033[36m\033[1m\033[5m\033[7m  (O)  \033[0m");
					}else{
										
						if((plateau[i][j].piece.nom ==LION && (plateau[i][j].piece.couleur ==BLANCHE || plateau[i][j].piece.couleur ==NOIRE) )){
						  if (plateau[i][j].piece.couleur ==BLANCHE)
						    {
						      printf("|\033[41m   ★★  \033[0m");
						    }
						  if (plateau[i][j].piece.couleur ==NOIRE)
						    {
						      printf("|\033[41m\033[34m   ★★  \033[0m");
						    }
										
						}else 
						  {
						    if (plateau[i][j].piece.nom ==SOURIS && (plateau[i][j].piece.couleur ==BLANCHE || plateau[i][j].piece.couleur ==NOIRE) ){
						      if (plateau[i][j].piece.couleur ==BLANCHE)
							{
							  printf("|\033[41m  ▼▼   \033[0m");
							}
						      if (plateau[i][j].piece.couleur ==NOIRE)
							{
							  printf("|\033[41m\033[34m  ▲▲   \033[0m");
							}


						    }else{
						      if (plateau[i][j].piece.nom ==ELEPHANT && (plateau[i][j].piece.couleur ==BLANCHE || plateau[i][j].piece.couleur ==NOIRE))
							{
							  if (plateau[i][j].piece.couleur ==BLANCHE)
							    {
							      printf("|\033[41m   ^⭓  \033[0m");
							    }
							  if (plateau[i][j].piece.couleur ==NOIRE)
							    {
							      printf("|\033[41m\033[34m   ^⭓  \033[0m");
							    }
							}
						      else
							printf("|\033[41m       \033[0m");
						    }
						  }
				      }
							
			    }else{
							
			    if (plateau[i][j].type_cs == point_eau && plateau[i][j].piece.nom ==RIEN)
			      {
				printf("|\033[35m\033[1m\033[5m\033[7m  (O)  \033[0m");
			      }else{
									
			      if((plateau[i][j].piece.nom ==LION && (plateau[i][j].piece.couleur ==BLANCHE || plateau[i][j].piece.couleur ==NOIRE) )){
				if (plateau[i][j].piece.couleur ==BLANCHE)
				  {
				    printf("|   ★★  ");
				  }
				if (plateau[i][j].piece.couleur ==NOIRE)
				  {
				    printf("|\033[34m   ★★  \033[0m");
				  }
								
			      }
			      else 
				{
				  if (plateau[i][j].piece.nom ==SOURIS && (plateau[i][j].piece.couleur ==BLANCHE || plateau[i][j].piece.couleur ==NOIRE)){
				    if (plateau[i][j].piece.couleur ==BLANCHE)
				      {
					printf("|  ▼▼   ");
				      }
				    if (plateau[i][j].piece.couleur ==NOIRE)
				      {
					printf("|  \033[34m ▲▲ \033[0m ");
				      }
				  }else{
				    if (plateau[i][j].piece.nom ==ELEPHANT && (plateau[i][j].piece.couleur ==BLANCHE || plateau[i][j].piece.couleur ==NOIRE))
				      {
					if (plateau[i][j].piece.couleur ==BLANCHE)
					  {
					    printf("|   ^⭓  ");
					  }
					if (plateau[i][j].piece.couleur ==NOIRE)
					  {
					    printf("|\033[34m   ^⭓  \033[0m");
					  }
				      }
				    else
												
				      printf("|       ");

				  }
				}
			    }
			  }
		} 


	      if(i<taille-1){
					
				printf("|\033[32;01m i_%d\033[00m\n",u);
				u=u+1;
				for (int k =0; k < taille; k++){
				  if ((k%2==0 && i%2==0)||(k%2!=0 && i%2!=0))
				    {
				      printf("|\033[41m_______\033[0m");
				    }else
				    printf("|_______");
							
				}
				printf("|\n|");
				for ( e =0; e < taille; e++)
				  if ((e%2==0 && i%2!=0)|| (e%2!=0 && i%2==0))
				    {
				      printf("\033[30m\033[41m       \033[0m|" );
				    }else{
				    printf("       |" );
				  }
				printf("\n");
					
	      }
	      if(i==taille-1)
		printf("|\033[32;01m i_%d\033[00m\n",taille-1);

    }
  printf("|");
  for (i = 0; i < taille; i++){
    if((taille-1)%2!=0){
	      if (i%2!=0)
		{
		  printf("\033[41m_______\033[0m|");
		}else
		printf("_______|");
    }else{
	      if (i%2==0)
		{
		  printf("\033[41m_______\033[0m|");
		}else
		printf("_______|");
    }
  }
  printf("\n");
  for (i = 0; i < taille; i++)
    printf("   \033[36;01mj_%d\033[00m  ",i);  
  printf("\n\n");
}


/*=======================================================================================

  retourne 0 si la piece ne bouge pas et 1 sinon */
int pas_meme_piece(int i,int j,int i_input,int j_input){
  if (i==i_input && j==j_input)
    {
      return 0;
    }
  return 1;
}

/*========================================fonction qui fait le deplacement =============================*/
void deplacements(plateau_Barca plateau[taille][taille], int i,int j,int i_input, int j_input){

  plateau[i_input][j_input].piece.nom=plateau[i][j].piece.nom;
  plateau[i_input][j_input].piece.couleur=plateau[i][j].piece.couleur;
  plateau[i][j].piece.nom=RIEN;
  plateau[i][j].piece.couleur=NEUTRE;
}


/*=============================================================================================*/
int verifier_conditions_deplacement(plateau_Barca plateau[taille][taille], int i,int j,int i_input, int j_input){
  int nor=0,saut=0,eff=0,bouge=0;
					
					
  nor=deplacement_normes(plateau,i,j,i_input,j_input);
  saut=pas_sauter(plateau,i,j,i_input,j_input);
  eff=effroi(plateau,i,j,i_input,j_input);
  bouge=pas_meme_piece(i,j,i_input,j_input);
  if (nor==1 && saut==0 && eff==0 && bouge==1)
    {
      return 0;
    }else{
    if (bouge==0)
      return 5; 
    if (nor==2)  /*cadre*/
      return 11;
    if (saut==1)
      return 2;
    if (eff==1)
      return 3;
				    	
				    	
  }
  return 1;  /*normes de deplacement*/
}

    
/*=============================================================================================*/	
/*====================================== dois jouer si effrayé ========================================*/
/*cette fonction retourne 1 si la piece qui a été choisie 
est effrayé et dans le camp du joueur et 0 si elle ne l'est pas */ 
int effraye_doit_jouer(plateau_Barca plateau[taille][taille] ,int i,int j, joueur jou){
  int r;
					
  r=effroi(plateau,i,j,i,j);
  if(r==1 && jou.camp==plateau[i][j].piece.couleur)
    {
						
      return 1;	
    }
											
  return 0;

}
 /*=============================================================================================*/	

/*cette fonction dit si il y effroi dans le camp du joueur actuelle ou pas si c'est le cas elle retourne 
1 sinon elle retourne 0*/

int ya_effroi(plateau_Barca plateau[taille][taille] , joueur jou){
  int i,j,r=0;
  for (i = 0; i <taille; i++)
    {
      for (j = 0; j<taille; j++)
	{
								
	  if( plateau[i][j].piece.nom !=RIEN && jou.camp==plateau[i][j].piece.couleur)
	    {
	      r=effroi(plateau,i,j,i,j);
	      if (r==1)
		{
		  return 1;
		}
											
	    }
	}
    }
  return 0;

}


/*=========================================fin partie==================================================*/
int fin_partie(plateau_Barca plateau[taille][taille]){
  int i,j,n=0,b=0;

  for ( i = 0; i < taille; i++)
    {
      for (j = 0; j < taille; j++)
		{	
				
		  if(plateau[i][j].type_cs==point_eau && plateau[i][j].piece.couleur!=NEUTRE )
		    {
		      if (plateau[i][j].piece.couleur!=BLANCHE)
			{
			  b++;
			}
		      if (plateau[i][j].piece.couleur!=NOIRE)
			{
			  n++;
			}
			

		    }
		}
    }
    
  if (b==3)
    {
      /* noirs gagnent*/
      return 1;
    }
  if (n==3)
    {
      /*blancs gagnent*/
      return 2;
    }

  /*pas encore fini */
  return 0;
}

/*========================================================================================*/


/*=============================================================================================*/	
		/* permet aux joueurs d'entrer les coordonnés des pièces et des deplacements*/
int choix_i_joueur(int j_i){
	int i;
	if(j_i==1)	
      printf(" \ti=\t");
  	if(j_i==2)
  	  printf(" \tj=\t");
    scanf("%d",&i);
    return i;
}
/*=============================================================================================*/	

void jouer(plateau_Barca plateau[taille][taille],joueur jo,int i,int j,int f,int k ,int pc){
  int verif,fin_tour=0,pi=0/*designe si c une piece ou pas */,flag/* permet d'entrer dans la boucle meme si pc=1 dans le 2eme tour*/;
	int cm=0,eff=0,eff_bouge=1,db=0;
  
  while(fin_tour==0){
	    flag=0;										
	    while(pi== 0 || pi == 2 || flag == 0 || cm == 0 || eff_bouge != 1){
				if(pc==0){				
		      		printf("\t\t\tchoisissez la piece à deplacer \n\n"); 
		    		i=choix_i_joueur(1);
		    		j=choix_i_joueur(2);
		   		}
		      eff=ya_effroi(plateau,jo);
		      if (eff==1)
				{
			  eff_bouge=effraye_doit_jouer(plateau,i,j,jo);
							    	
				}				    
		      pi=piece_ou_pas(plateau,i,j);
		      		db=0;
		   if(pi!=1 || plateau[i][j].piece.couleur!=jo.camp ){
			      if (pi==0)
					{
						db=1;
				  printf("\t\t\tcette case est vide , choisissez une piece. \n\n");
					}
			      if (pi==2){
			      		db=1;
				printf("\t\t\tvous n'etes pas dans le cadre , choisissez une piece. \n\n");
			      }
			      if(plateau[i][j].piece.couleur!=jo.camp && pi==1){
				printf("\t\t\tcette piece n'est pas à vous , choisissez une piece de votre camp.\n\n");
					db=1;
			      }
		  }
		      else{
				cm=1;
		       if(eff_bouge==0 && db==0 ){
			   printf("\t\t\tvous ne pouvez deplacer que l'une des pieces effrayés. \n\n");
		      }				    
		      }
		      flag=1;
		      if(pc!=0)
		      	printf(" APPUYEZ SUR ENTREE pour permettre a l'Ordinateur de jouer. \n");
		      getchar();
	    }
	    if(pc==0){
	    printf("\t\t\tou voulez vous la deplacer\n");
	    f=choix_i_joueur(1);
	    k=choix_i_joueur(2);
		}

	    verif=verifier_conditions_deplacement(plateau,i,j,f,k);
	    if (verif==0)
	      {
		deplacements(plateau,i,j,f,k);
		affichage(plateau);
		fin_tour=1;
		if(pc!=0)
			printf("L'Ordinateur a joué APPUYEZ SUR ENTREE pour passer à votre tour \n");
		getchar();
	      }else{
	      if(verif==1)
		printf(" \t\t\tPas dans les normes de deplacement \n On vous rapelle que les lions ne se deplacent qu'en diagonale. \n les souris qu'horizentalement ou verticalement. \n et les elephants dans tous les sens.  \n \n");
	      if (verif==2)
		printf("Je ne peux ni sauter une piece ni prendre sa place.\n\n");
	      if (verif==3)
		printf("\t\t\tJ'ai peur la piece a coté de la case [%d][%d] m'effraie essayez une autre case?  \n\n",f,k);
	      if (verif==5)
		printf("\t\t\tVous ne pouvez pas rester a la meme place. \n\n");
	      if (verif==11)
		printf("\t\t\tVous ne pouvez pas vous deplacer hors du cadre.  \n\n");
							
	    }
				   
  }
}
	




void presentation_pieces(){
  printf("\t\t\t===========\033[33m dans ce jeu il y a des pieces blanches et bleus \033[0m===========\n");
  printf("\t\t\t    ===========\033[33m pour chauqe couleur on a 3 types de pieces\033[0m===========\n");
  printf("\t\t\t\tLES LIONS designés par      ★★  ou  \033[34m★★ \033[0m \n\n ");
  printf("\t\t\t\tLES SOURIS designés par    ▼▼  ou \033[34m ▼▼\033[0m \n\n");
  printf("\t\t\t\tLES ELEPHANTS designés par  ^⭓  ou  \033[34m^⭓ \033[0m\n\n\n\n");

}

/*=============================================================================================*/	

	char *nom_joueurs(){
		char * c =malloc(50*sizeof(char));
		scanf("%s",c);
		return c;
	}
/*=============================================================================================*/
	char *presentation_joueur(int num_jo,int print){  /*num_jo c'est le numero du jueur*/
			char *Joueur;                               /*print c'est un flag qui dit quand 
														faire un print et quant ne pas le faire*/
		    if(print==0){
			  printf("\t\033[37m Joueur %d s'il vous plait entrez votre nom \033[0m\t",num_jo);
			}
			  if (print==0){
			  	Joueur=nom_joueurs();
			  	if(num_jo==2)
			  		 printf("\n\t\tBONJOUR \033[33m%s\033[0m VOICI VOS PIECES \n\t\t\t\t\t\t \033[34m★★ \n\t\t\t\t\t\t ▼▼  \n\t\t\t\t\t\t  ^⭓\033[0m \n\n \n",Joueur);
			  }
			 if(print==1 && num_jo==1)
			  printf("\n\t\tBONJOUR \033[33m%s\033[0m VOICI VOS PIECES \n\t\t\t\t\t\t ★★ \n\t\t\t\t\t\t ▼▼  \n\t\t\t\t\t\t  ^⭓ \n\n \n",Joueur);
			 
			 return Joueur;
			
			
		  getchar();
	}
/*=============================================================================================*/
						/*cette fonction permet a jouer a tour de role pour le mode 1 vs 1 */
void tour_de_role(plateau_Barca plateau[taille][taille]  ){
   int commencer;	
  int fin=0,sw=-1;
  char *joueur1,*joueur2;
  joueur jo;
  
  joueur1=presentation_joueur(1,0);
  joueur1=presentation_joueur(1,1);
  joueur2=presentation_joueur(2,0);
  joueur2=presentation_joueur(2,1);

  printf("\t\t\tTAPEZ 1 POUR COMMENCER A JOUER .\t");
  scanf("%d",&commencer);
  if(commencer==1)
  	affichage(plateau);	
  while(fin==0 )
    {        
				
	      if(sw==1 && fin==0 ){ /*on a mis fin ici pour eviter quela boucle rentre au dernier coup*/
			printf("\033[33m C'EST A  %s DE JOUER\033[0m\n\n",joueur1);
			jo.camp=BLANCHE;
			sw=-sw;
			jouer(plateau,jo,0,0,0,0,0);
			fin=fin_partie(plateau);
	      }
	      if(sw==-1 && fin==0 ){

			printf(" \033[33m C'EST A %s DE JOUER\033[0m\n\n",joueur2);
			jo.camp=NOIRE;
			sw=-sw;
			jouer(plateau,jo,0,0,0,0,0);
			fin=fin_partie(plateau);
	      }

	      fin=fin_partie(plateau);

    }
  if (jo.camp==NOIRE )
    {
      printf("\t\t\t\033[35m★★★★★★★★ bravo %s tu as gagné ★★★★★★★★\033[0m \n",joueur2 );
    }
  if (jo.camp==BLANCHE ){
    printf("\t\t\t\033[35m★★★★★★★★ bravo %s tu as gagné ★★★★★★★★\033[0m \n",joueur1 );
  }
  free(joueur1);
  free(joueur2);
}
/*=============================================================================================*/



/*=========================genere choix des pieces et deplacements de l'ordinateur==============================
                                 et ne donne que des combinaisons i j qui 
                                     sont dans les normes  de deplacement*/	
                      
                     
void i_j_pc(plateau_Barca plateau[taille][taille]){  
	 joueur jo;
	 jo.camp=NOIRE; 
	 int i,j,yaeff,eff_bouge,verif=1,f,k; 
        srand(time(NULL));
       	i=0;
		j=0;
		f=rand()%(taille);
		k=rand()%(taille);
		while(plateau[i][j].piece.nom==RIEN || plateau[i][j].piece.couleur==BLANCHE ){

			i=rand()%(taille);
			j=rand()%(taille);
			yaeff=ya_effroi(plateau,jo);
			if (yaeff==1){
				eff_bouge=effraye_doit_jouer(plateau,i,j,jo);
				while(plateau[i][j].piece.nom==RIEN || plateau[i][j].piece.couleur==BLANCHE || eff_bouge==0){
					i=rand()%(taille);
					j=rand()%(taille);
					eff_bouge=effraye_doit_jouer(plateau,i,j,jo);
				}
			}
		}
		/*deplacement*/

		while(verif!=0){
			f=rand()%(taille);
			k=rand()%(taille);
			verif = verifier_conditions_deplacement(plateau,i,j,f,k);
		}
		jouer(plateau,jo,i,j,f,k,1);
  }
/*=============================================================================================*/	

  				/*cette fonction permet a jouer a tour de role pour le mode 1 vs pc */
  void tour_de_role_pc(plateau_Barca plateau[taille][taille]  ){
				
   int commencer;	
  int fin=0,sw=-1;
  char *joueur1;
  joueur jo;
  
  joueur1=presentation_joueur(1,0);
  joueur1=presentation_joueur(1,1);
  printf("\t\t\t TAPEZ 1 POUR COMMENCER A JOUER. \t");
  scanf("%d",&commencer);
  if(commencer==1)
  	affichage(plateau);		
  while(fin==0 )
    {
				
	      if(sw==1 && fin==0){
			printf("\033[33m C'EST A  %s DE JOUER\033[0m\n",joueur1);
			jo.camp=BLANCHE;
			sw=-sw;
			jouer(plateau,jo,0,0,0,0,0);
			fin=fin_partie(plateau);
	      }
	      if(sw==-1 && fin==0){
			jo.camp=NOIRE;
			sw=-sw;
			i_j_pc(plateau);
			fin=fin_partie(plateau);
	      }
	      fin=fin_partie(plateau);
    }
  if (jo.camp==NOIRE )
    {
     	 printf("\t\t\t\033[35m★★★★★★★★GAME OVER you lose ★★★★★★★★\033[0m \n" );
    }
  if (jo.camp==BLANCHE )
  	{
   		 printf("\t\t\t\033[35m★★★★★★★★ bravo %s tu as gagné ★★★★★★★★\033[0m \n",joueur1 );
  	}
  free(joueur1);
}
/*=============================================================================================*/	

void choix_options(plateau_Barca plateau[taille][taille]){
  
			int choix;	
  
  printf(" \t\t\t\t SUPEEER ALONS Y  \n\n \t\t\t MODE DE JEU : \n\n \t\t\t \033[31m\033[1m1-joueur1 VS joueur2 .(tapez 1) \n \t\t\t 2-joueur 1 VS Ordinateur. (tapez 2)\033[0m \n");
  scanf("%d",&choix);
  if (choix==1)
  {
  	 tour_de_role(plateau);
  }else{
  	tour_de_role_pc(plateau);
  }
 
}
void regle_du_jeu(){
		printf("\t\t\t\033[35m\033[1m\033[4mREGLES DU JEU :\033[0m \n\n ");
			printf("Chaque pion peut etre deplacé d’un nombre arbitraire de cases  dans  une  meme  direction, à condition  qu’il  ne  passe  au  dessus  d’aucun autre pion, ami ou ennemi.\n");
			printf("\t\t\t -Les SOURIS ne peuvent se deplacer qu’horizontalement ou verticalement.\n");
			printf("\t\t\t -Les LIONS ne peuvent se deplacer qu’en diagonale.\n");
			printf("\t\t\t -Les ELEPHANTS peuvent se deplacer dans toutes les directions..\n\n\n");
			printf("Il est interdit `a une piece de se deplacer vers une case ou elle deviendrait effrayee en partant d’une case ou elle ne l’est pas. Les pieces d’un meme camp ne peuvent s’effrayer entre elles, mais :\n");
			printf("\t\t\t Les LIONS effraient les SOURIS adverses.\n");
			printf("\t\t\t Les ELEPHANTS effraient les LIONS adverses.\n");
			printf("\t\t\t Les SOURIS effraient les ELEPHANTS adverses.\n");
			printf("Lorsqu’une ou plusieurs pieces sont ou deviennent effrayees apres le coup de l’un des deux joueurs: \n");
			printf("Le joueur suivant ne peut deplacer que l’une de ses pieces effrayees.\n\n");
			printf("\t\t\t\033[1m\033[4mFIN DE PARTIE :\033[0m \n LA PARTIE SE TERMINE QUAND UN JOUEUR RÉUSSIT A PLACER 3 DE CES PIECES DANS LES POINT D'EAU (QUI SONT LES 4 CASES QUI CLIGNOTENT AU CENTRE DU PLATEAU.\n\n\n\n\n");
			printf("\t\t\t Aussi si vous n'arrivez plus a deplacer aucune piece.c'est le joueur qui a bloqué lautre qui est le gagnant .\n");
			printf("\t\t\t EXEMPLE : sur un plateau 8X8 si un lion est en [7,0] et un elephant adverse en [6,1] le jeu est bloqué \n\n");
			
		
}
		void initialisaton_plateau(){
	 		  taille_plateau();
			  plateau_Barca plateau[taille][taille];
			  creation_table_barca(plateau);
			  initialisation_points_eau(plateau);
			  initialisation_pieces(plateau);
			  affichage(plateau);
			  choix_options(plateau);
}

		void choix(){
			int c,d=1;
			while(d==1){
				debut();
				printf(" \t\t Bonjour et bien venu dans BARCA. \n\n");
				printf(" \t\t\t1-# \033[32m\033[1mPour voir la presentation des pièces et les regles du jeu tapez 1\033[0m. \n\n");
				printf(" \t\t\t2-# \033[32m\033[1mPour commencer à jouer tapez 2\033[0m .\n\n");
				scanf("%d",&c);
				switch(c){
					case 1 : 
					presentation_pieces();
					regle_du_jeu();
					printf("\tPour revenir au menu principale tapez 1 .\n\n");
					printf("\tPour quiter tappez 2 .\n");
					scanf("%d",&d);
					break;

					case 2:
					
					  initialisaton_plateau();					
					  printf("\tPour revenir au menu principale tapez 1. \n\n");
				      printf("\tPour quiter tappez 2 .\n");

					  scanf("%d",&d);
				}
			}
		}

int main(){  
  choix();
  return 0;
}
