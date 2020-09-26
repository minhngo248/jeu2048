/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "Header files/header.h"
#include "Header files/header1.h"

void resumeGame(Valeur Val[][4],int score) {
    FILE *fp;
    int tour = 0;
    Valeur Val1[4][4];
    char c;
    int i,j;
    fp = fopen("text.txt","r"); //lecture du fichier
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++) {
            fscanf(fp,"%d\t",&Val[i][j].data);
        }
        fscanf(fp,"\n");
    }
    fscanf(fp,"%d",&score);
    fclose(fp);
    
    while (1) {
        system("cls");
        Tableau();
        if (tour != 0) { //attention
            randPos(Val);
        }
        Cou(Val); //couleur des cases
        for(i=0;i<4;i++) {
            for(j=0;j<4;j++) {
                Val1[i][j] = Val[i][j];
            }
        }
        affiche(Val,&score);
        c = _getch();
        tour++;
        if (c == 'b') { //back to Menu
            fileSave(Val,score);
            break;
        }
        getKey(Val,c,&score);
        if (checkGame(Val,Val1) == 0) { //end game, sauvegarde de high score
            fileScore(score);
            system("cls");
            printf("Score: %d",score);
            c = _getch();
            break;
        }
    }
}

void newGame(Valeur Val[][4],int score) { //module 1 joueur
    int i,j;
    Valeur Val1[4][4];
    char c;
    while (1) {
        system("cls");
        Tableau();
        randPos(Val);
        Cou(Val); //couleur des cases
        for(i=0;i<4;i++) {
            for(j=0;j<4;j++) {
                Val1[i][j] = Val[i][j];
            }
        }
        affiche(Val,&score);
        c = _getch();
        if (c == 'b') { //back to Menu
            fileSave(Val,score);
            break;
        }
        getKey(Val,c,&score);
        if (checkGame(Val,Val1) == 0) { //end game, sauvegarde de high score
            fileScore(score);
            system("cls");
            printf("Score: %d",score);
            c = _getch();
            break;
        }
    }
}

void fileSave(Valeur Val[][4],int score) { //Save score to resume game
    int i,j;
    FILE *fp;
    fp = fopen("text.txt","w");
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++) {
            fprintf(fp,"%d\t",Val[i][j].data);
        }
        fprintf(fp,"\n");
    }
    fprintf(fp,"%d",score);
    fclose(fp);
}
