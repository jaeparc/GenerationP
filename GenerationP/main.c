//
//  main.c
//  GenerationP
//
//  Created by Theo Garnon on 08/02/2021.
//

#include <stdio.h>

typedef struct{
    int entree1;
    int entree2;
    int derniereEntreeUtilisee;
}piece;

int main(int argc, const char * argv[]) {
    piece pieces[20];
    int i = 0, y = 0, entree1test, entree2test, pieceDeDepart, numTabDepart;
    pieces[0].entree1 = 41;
    pieces[0].entree2 = 31;
    pieces[1].entree1 = 42;
    pieces[1].entree2 = 31;
    pieces[2].entree1 = 22;
    pieces[2].entree2 = 31;
    pieces[3].entree1 = 21;
    pieces[3].entree2 = 31;
    pieces[4].entree1 = 11;
    pieces[4].entree2 = 31;
    pieces[5].entree1 = 21;
    pieces[5].entree2 = 32;
    pieces[6].entree1 = 22;
    pieces[6].entree2 = 32;
    pieces[7].entree1 = 42;
    pieces[7].entree2 = 32;
    pieces[8].entree1 = 41;
    pieces[8].entree2 = 32;
    pieces[9].entree1 = 12;
    pieces[9].entree2 = 32;
    pieces[10].entree1 = 42;
    pieces[10].entree2 = 22;
    pieces[11].entree1 = 42;
    pieces[11].entree2 = 12;
    pieces[12].entree1 = 42;
    pieces[12].entree2 = 11;
    pieces[13].entree1 = 41;
    pieces[13].entree2 = 21;
    pieces[14].entree1 = 41;
    pieces[14].entree2 = 12;
    pieces[15].entree1 = 41;
    pieces[15].entree2 = 11;
    pieces[16].entree1 = 12;
    pieces[16].entree2 = 21;
    pieces[17].entree1 = 12;
    pieces[17].entree2 = 22;
    pieces[18].entree1 = 11;
    pieces[18].entree2 = 21;
    pieces[19].entree1 = 11;
    pieces[19].entree2 = 22;
    do{
        printf("Entrez un numero de piece compris en 0 et 19 : ");
        scanf("%d",&pieceDeDepart);
    } while(pieceDeDepart < 0 || pieceDeDepart > 19);
    
    printf("\nCherchons une piece correspondant a la piece %d ... \n",pieceDeDepart);
    
    numTabDepart = pieceDeDepart;
    while(i < 20){
        if(pieces[numTabDepart].entree1 > 30){
            entree1test = pieces[numTabDepart].entree1-20;
        } else {
            entree1test = pieces[numTabDepart].entree1+20;
        }
        if(pieces[numTabDepart].entree2 > 30){
            entree2test = pieces[numTabDepart].entree2-20;
        } else {
            entree2test = pieces[numTabDepart].entree2+20;
        }
        if(pieces[i].entree1 == entree1test || pieces[i].entree1 == entree2test){
            if(i != numTabDepart){
                pieces[i].derniereEntreeUtilisee = 1;
                break;
            } else {
                i++;
            }
        } else if(pieces[i].entree2 == entree1test || pieces[i].entree2 == entree2test){
            if(i != numTabDepart){
                pieces[i].derniereEntreeUtilisee = 2;
                break;
            } else {
                i++;
            }
        } else {
            i++;
        }
        printf("Piece %d non-compatible \n",i-1);
    }
    
    printf("La piece %d correspond a la piece %d! \n\n",i,pieceDeDepart);
    printf("Cherchons une piece correspondant a la piece %d ... \n",i);
    
    while(y < 20){
        if(pieces[i].entree1 > 30){
            entree1test = pieces[i].entree1-20;
        } else {
            entree1test = pieces[i].entree1+20;
        }
        if(pieces[i].entree2 > 30){
            entree2test = pieces[i].entree2-20;
        } else {
            entree2test = pieces[i].entree2+20;
        }
        if(pieces[y].entree1 == entree1test || pieces[y].entree2 == entree1test){
            if(y != i && pieces[i].derniereEntreeUtilisee != 1){
                pieces[y].derniereEntreeUtilisee = 1;
                break;
            } else {
                y++;
            }
        } else if(pieces[y].entree1 == entree2test || pieces[y].entree2 == entree2test){
            if(y != i && pieces[i].derniereEntreeUtilisee != 2){
                pieces[y].derniereEntreeUtilisee = 2;
                break;
            } else {
                y++;
            }
        } else {
            y++;
        }
        printf("Piece %d non-compatible \n",y-1);
    }
    printf("La piece %d correspond a la piece %d! \n\n",y,i);
    printf("Votre sequence est : %d - %d - %d\n",pieceDeDepart,i,y);
    return 0;
}
