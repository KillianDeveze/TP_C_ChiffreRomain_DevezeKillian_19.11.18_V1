//***************************************************************************************************************
                                            //Algorithme//
//****************************************************************************************************************
/*
BUT :Ecrire un algorithme qui transforme un nombre entier décimal en chiffre romain et inversement
ENTREE : Nombre décimale ou Chiffre Romain
SORTIE : Convertion en Chiffre Romain ou Nombre décimale


//****************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototypes
void Convertion_Romains_Calcul();
void Convertion_Decimal_Calcul();
void affichage();
void verification_saisie_entier(int *NNombre);
void Saisie_ChiffreRomain(char *CChiffre_Romain);
void validation_saisi(char *CChiffre_Romain);
void CSaisiRomain(char *CChiffre_Romain);


int main()
{
    affichage();
    return 0;
}

//**************************************************
//Description : affichage d'un menu qui permet à l'utilisateur de choisir une option
//
//Entrée: Entier
//
//Sortie: appele d'une méthode méthodes en fonction du choix de l'utilisateur
//
//Note
//*************************************************
void affichage(){

    int NChoix=0;

    printf("Bienvenue ! Que souhaitez vous faire ? \n");
    printf("Tapez 1 : Convertion d'un décimale en chiffre Romain \n");
    printf("Tapez 2 : Convertion d'un chiffre romain en nombre décimale \n");
    printf("Tapez 3 : Quittez \n");


    while(NChoix!=3){

                        printf("Votre choix : ");
                        scanf("%d",&NChoix);
                        fflush(stdin);

                        switch(NChoix){

                            case 1 :
                                    Convertion_Romains_Calcul();
                                    break;

                            case 2 :
                                    Convertion_Decimal_Calcul();
                                    break;
                            case 3 :
                                    printf("Aurevoir !");
                                    break;
                            default:
                                    printf("Saisi non valide \n");
                                    break;
                                        }
                  }

}

//**************************************************
//Description: permet de convertir un entier en chiffre romains
//
//Entrée: NNombre
//
//Sortie: CHiffre romains
//
//Note
//*************************************************
void Convertion_Romains_Calcul(){

        int NNombre=10000;
        char CResultat[25];

        verification_saisie_entier(&NNombre);

        while(NNombre>0){

            if(NNombre>=1000){
                strcat(CResultat,"M");
                NNombre=NNombre-1000;}

            if (NNombre>=900 && NNombre<1000){
                strcat(CResultat,"CM");
                NNombre=NNombre-900;}

                if (NNombre>=500 && NNombre<1000){
                    strcat(CResultat,"D");
                    NNombre=NNombre-500;}

                    if (NNombre>=400 && NNombre<500){
                        strcat(CResultat,"CD");
                        NNombre=NNombre-400;}

                        if (NNombre>=100 && NNombre<500){
                            strcat(CResultat,"C");
                             NNombre=NNombre-100;}

                            if (NNombre>=90 && NNombre<100){
                                    strcat(CResultat,"XC");
                                    NNombre=NNombre-90;}

                                    if (NNombre>=50 && NNombre<100){
                                        strcat(CResultat,"L");
                                        NNombre=NNombre-50;}

                                        if (NNombre>=40 && NNombre<50){
                                            strcat(CResultat,"XL");
                                            NNombre=NNombre-40;}

                                            if (NNombre>=10 && NNombre<50){
                                                strcat(CResultat,"X");
                                                NNombre=NNombre-10;}

                                                if (NNombre==9){
                                                       strcat(CResultat,"IX");
                                                        NNombre=NNombre-9;}

                                                        if(NNombre>=5 && NNombre <10){
                                                            strcat(CResultat,"V");
                                                            NNombre=NNombre-5;}

                                                            if (NNombre==4){
                                                                   strcat(CResultat,"IV");
                                                                    NNombre=NNombre-4;}

                                                                    if (NNombre>=1 && NNombre<5){
                                                                       strcat(CResultat,"I");
                                                                        NNombre=NNombre-1;}


       }
    printf("Votre chiffre romain est : %s \n",CResultat);
}

//**************************************************
//Description: permet de vérifier la saisir de l'utilisateur
//
//Entrée: Chaine de caractère (nombre romain)
//
//Sortie:
//
//Note
//*************************************************
void verification_saisie_entier(int *NNombre){



        while (*NNombre>9999 || *NNombre<0){

            printf("Saisir un nombre compris entre 0 et 9999: ");
            scanf("%d",&*NNombre);

                                            }



}

//**************************************************
//Description: permet de convertir un chiffre romain en nombre décimale
//
//Entrée: Chaine de caractère (nombre romain)
//
//Sortie: Nombre décimale
//
//Note
//*************************************************
void Convertion_Decimal_Calcul(){

        char CChiffre_Romain[25];
        int Ncpt=0;
        int NResultat=0;


        Saisie_ChiffreRomain(&CChiffre_Romain);

        validation_saisi(&CChiffre_Romain);

        CSaisiRomain(&CChiffre_Romain);


        while(CChiffre_Romain[Ncpt]!=0){

               if(CChiffre_Romain[Ncpt]=='M' && CChiffre_Romain[Ncpt-1]!='C')

                            {
                                NResultat=NResultat+1000;
                            }


                if(CChiffre_Romain[Ncpt]=='D' && CChiffre_Romain[Ncpt-1]!='C')
                            {
                                NResultat=NResultat+500;
                            }


                if(CChiffre_Romain[Ncpt]=='C' && CChiffre_Romain[Ncpt-1]!='X'){

                        if (CChiffre_Romain[Ncpt+1]=='M')
                            {
                                NResultat=NResultat+900;
                            }

                        else {

                                if (CChiffre_Romain[Ncpt+1]=='D')
                                        {
                                            NResultat=NResultat+400;
                                        }

                                else
                                        {
                                            NResultat=NResultat+100;
                                        }
                                }}



                if(CChiffre_Romain[Ncpt]=='L' && CChiffre_Romain[Ncpt-1]!='X')

                            {
                                NResultat=NResultat+50;
                            }




                if(CChiffre_Romain[Ncpt]=='X' && CChiffre_Romain[Ncpt-1]!='I'){

                         if (CChiffre_Romain[Ncpt+1]=='C')
                            {
                                NResultat=NResultat+90;
                            }

                        else {

                                if (CChiffre_Romain[Ncpt+1]=='L')
                                        {
                                            NResultat=NResultat+40;
                                        }

                                else
                                        {
                                            NResultat=NResultat+10;
                                        }
                                }}

                if(CChiffre_Romain[Ncpt]=='V' && CChiffre_Romain[Ncpt-1]!='I')

                            {
                                NResultat=NResultat+5;
                            }





                if(CChiffre_Romain[Ncpt]=='I'){

                         if (CChiffre_Romain[Ncpt+1]=='X')
                            {
                                NResultat=NResultat+9;
                            }

                        else {

                                if (CChiffre_Romain[Ncpt+1]=='V')
                                        {
                                            NResultat=NResultat+4;
                                        }

                                else
                                        {
                                            NResultat=NResultat+1;
                                        }
                                }}


            Ncpt=Ncpt+1;

    }

    printf("%d \n",NResultat);
}
//**************************************************
//Description: demande à l'utilisateur de saisir son chiffre romain
//
//Entrée: Chaine de caractère (Chiffre romain)
//
//Sortie:
//
//Note
//*************************************************
void Saisie_ChiffreRomain(char *CChiffre_Romain){


        printf("Saisir votre chiffre romain : ");
        scanf("%s",&*CChiffre_Romain);



}

//**************************************************
//Description: permet de verifier que l'utilisateur rentre les bons caractères
//
//Entrée: Chaine de caractère (nombre romain)
//
//Sortie:
//
//Note :
//*************************************************
void validation_saisi(char *CChiffre_Romain){

            int Ncpt=0;
            int Ntest=1;

            while(Ntest==1){

                    Ncpt=0;

                    while (Ncpt<strlen(CChiffre_Romain))
                        {

                            if (CChiffre_Romain[Ncpt]=='M' || CChiffre_Romain[Ncpt]=='D' || CChiffre_Romain[Ncpt]=='C' || CChiffre_Romain[Ncpt]=='L' || CChiffre_Romain[Ncpt]=='X' || CChiffre_Romain[Ncpt]=='V' || CChiffre_Romain[Ncpt]=='I')
                                {
                                   Ntest=0;
                                }
                            else
                                {
                                    Ntest=1;
                                }

                            Ncpt++;
                        }
                    if (Ntest==1)
                        {
                            printf("erreur de saisi , seul des caractères majuscules sont autorises\n");
                            printf("Saisir votre chiffre romain : ");
                            scanf("%s",&*CChiffre_Romain);
                        }

                }
}

//**************************************************
//Description: permet de verifier la saisi du chiffre romain de l'utilisateur et ainsi évité le nombre inexistant tel que XCX
//
//Entrée: Chaine de caractère (nombre romain)
//
//Sortie: 1 (vrai) ou 0 (faux)
//
//Note :
//*************************************************
void CSaisiRomain(char *CChiffre_Romain){


        int Ncpt=0;
        int Ntest=0;

        do{

            Ntest=0;

            if(CChiffre_Romain[Ncpt]=='D' && CChiffre_Romain[Ncpt+1]=='M')
                    {
                        Ntest=1;
                    }

              if(CChiffre_Romain[Ncpt]=='L')
                    {
                        if(CChiffre_Romain[Ncpt+1]=='M' || CChiffre_Romain[Ncpt+1]=='D'){Ntest=1;}
                    }

              if(CChiffre_Romain[Ncpt]=='X')
                    {
                        if(CChiffre_Romain[Ncpt+1]=='M' || CChiffre_Romain[Ncpt+1]=='D'){Ntest=1;}
                    }

              if(CChiffre_Romain[Ncpt]=='V')
                    {
                        if(CChiffre_Romain[Ncpt+1]=='M' || CChiffre_Romain[Ncpt+1]=='D' || CChiffre_Romain[Ncpt+1]=='C' || CChiffre_Romain[Ncpt+1]=='L' || CChiffre_Romain[Ncpt+1]=='X')
                                {
                                    Ntest=1;
                                }
                    }

              if(CChiffre_Romain[Ncpt]=='I')
                    {
                        if(CChiffre_Romain[Ncpt+1]=='M' || CChiffre_Romain[Ncpt+1]=='D' || CChiffre_Romain[Ncpt+1]=='C' || CChiffre_Romain[Ncpt+1]=='L')
                                {
                                    Ntest=1;
                                }
                    }

              if(CChiffre_Romain[Ncpt]=='C' && CChiffre_Romain[Ncpt+1]=='M')
                    {
                        if(CChiffre_Romain[Ncpt+2]=='M' || CChiffre_Romain[Ncpt+2]=='D' || CChiffre_Romain[Ncpt+2]=='C')
                                {
                                    Ntest=1;
                                }
                    }

               if(CChiffre_Romain[Ncpt]=='C' && CChiffre_Romain[Ncpt+1]=='D')
                    {
                        if(CChiffre_Romain[Ncpt+2]=='M' || CChiffre_Romain[Ncpt+2]=='D' || CChiffre_Romain[Ncpt+2]=='C')
                                {
                                    Ntest=1;
                                }
                    }

               if(CChiffre_Romain[Ncpt]=='X' && CChiffre_Romain[Ncpt+1]=='C')
                    {
                        if(CChiffre_Romain[Ncpt+2]=='M' || CChiffre_Romain[Ncpt+2]=='D' || CChiffre_Romain[Ncpt+2]=='C' || CChiffre_Romain[Ncpt+2]=='L' || CChiffre_Romain[Ncpt+2]=='X')
                                {
                                    Ntest=1;
                                }
                    }

                if(CChiffre_Romain[Ncpt]=='X' && CChiffre_Romain[Ncpt+1]=='L')
                    {
                        if(CChiffre_Romain[Ncpt+2]=='M' || CChiffre_Romain[Ncpt+2]=='D' || CChiffre_Romain[Ncpt+2]=='C' || CChiffre_Romain[Ncpt+2]=='L' || CChiffre_Romain[Ncpt+2]=='X')
                                {
                                    Ntest=1;
                                }
                    }

                 if(CChiffre_Romain[Ncpt]=='I' && CChiffre_Romain[Ncpt+1]=='V')
                        {
                            if(CChiffre_Romain[Ncpt+2]=='M' || CChiffre_Romain[Ncpt+2]=='D' || CChiffre_Romain[Ncpt+2]=='C' || CChiffre_Romain[Ncpt+2]=='L' || CChiffre_Romain[Ncpt+2]=='X' || CChiffre_Romain[Ncpt+2]=='V' || CChiffre_Romain[Ncpt+2]=='I')
                                    {
                                        Ntest=1;
                                    }
                        }



                if(Ntest==1)
                    {
                        printf("Erreur ce chiffre romain n'existe pas ! \n");
                        fflush(stdin);
                        printf("Saisir votre chiffre romain : ");
                        scanf("%s",&*CChiffre_Romain);
                    }
        }while(Ntest==1);

}
