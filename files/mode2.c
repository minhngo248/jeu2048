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

//----------Module de 2 joueurs-----------------
void Tableau2() {
    int i,j,n = 1;
    for(i=0;i<=24;i++) {
        gotoxy(n,30);
	for(j=0;j<=24;j++) {
            if(((1<=i && i<=5) || (7<=i && i<=11) || (13<=i && i<=17) || (19<=i && i<=23)) && ((1<=j && j<=5) || (7<=j && j<=11) || (13<=j && j<=17) || (19<=j && j<=23))) {
                textcolor(51);
		printf(" ");
            }
            else {
                textcolor(112);
		printf(" ");
            }
	}
        n++;
    }    
}

void newGame2(Valeur Val1[][4],Valeur Val2[][4],int score1,int score2) {
    int i,j;
    int tour = 0;
    Valeur Val3[4][4],Val4[4][4];
    char c;
    while (1) {
        system("cls");
        Tableau();
        Tableau2();
        if (tour%2 == 0) {
            randPos(Val1);
        }
        else {
            randPos(Val2);
        }
        Cou(Val1); //couleur des cases
        Cou(Val2);
        for(i=0;i<4;i++) {
            for(j=0;j<4;j++) {
                Val3[i][j] = Val1[i][j];
            }
        }
        for(i=0;i<4;i++) {
            for(j=0;j<4;j++) {
                Val4[i][j] = Val2[i][j];
            }
        }        
        affiche2(Val1,Val2,&score1,&score2);
        gotoxy(28,1);
        textcolor(4);
        if (tour%2 == 0) {
            printf("Tour du joueur 1");
        }
        else {
            printf("Tour du joueur 2");
        }
        c = _getch();
        if (c == 'b') { //back to Menu
        //    fileSave(Val,score);
            break;
        }
        
        if (tour%2 == 0) {
            getKey(Val1,c,&score1);
        }
        else {
            getKey(Val2,c,&score2);
        }
        
        if (checkGame(Val1,Val3)==0 && checkGame(Val2,Val4)==1) {
            tour = 1;
        }
        else if (checkGame(Val1,Val3)==1 && checkGame(Val2,Val4)==0) {
            tour = 0;
        }
        else if (checkGame(Val1,Val3)==1 && checkGame(Val2,Val4)==1) {
            tour++; //n'en oublie pas
        }
        else { //end game
            system("cls");
            if (score1 > score2) {
                printf("Vainqueur: Joueur 1");
            }
            else if (score2 > score1) {
                printf("Vainqueur: Joueur 2");
            }
            c = _getch();
            break;
        }
    } 
}

void affiche2(Valeur Val1[][4],Valeur Val2[][4],int* score1,int* score2) {
    int i,j;
    for(i=0;i<4;i++) { //affiche des valeurs du 1er joueur
        for(j=0;j<4;j++) {
            if(Val1[i][j].data != 0) {
                gotoxy(6*i+4,6*j+4);
                textcolor(Val1[i][j].cou);
                printf("%d",Val1[i][j].data);
            } 
        }
    }
    for(i=0;i<4;i++) { //affiche des valeurs du 2e joueur
        for(j=0;j<4;j++) {
            if(Val2[i][j].data != 0) {
                gotoxy(6*i+4,29+6*j+4);
                textcolor(Val2[i][j].cou);
                printf("%d",Val2[i][j].data);
            } 
        }
    }
    gotoxy(26,1); textcolor(3);
    printf("Score 1: %d",*score1);
    gotoxy(26,30); textcolor(5);
    printf("Score 2: %d",*score2);
    gotoxy(30,3); textcolor(4);
    printf("Tapez B pour revenir au Menu");
}

void Menu1() { //menu 1 joueur
    int i,j;
    for(i=0;i<13;i++) {
	for(j=0;j<25;j++) {
            if((i==0 || i==4 || i==8||i==12||i==16) || (((1<=i && i<=3) || (5<=i && i<=7) || (9<=i && i<=11)||(13<=i<=15)) &&((0<=j&&j<=5)||(18<j&&j<25)))) {
		textcolor(112);
		printf(" ");
            }
            else {
		textcolor(35);
		printf(" ");
            }
	}
	printf("\n");
    }
    gotoxy(3,9);
    textcolor(32); 
    printf("REPRENDRE");
    gotoxy(7,8); printf("NOUVEAU JEU");
    gotoxy(11,9); printf("CLASSEMENT");
    textcolor(7);
    gotoxy(3,30); printf("Tapez 1 pour reprendre le jeu");
    gotoxy(7,30); printf("Tapez 2 pour nouveau jeu");
    gotoxy(11,30); printf("Tapez 3 pour classement");   
}

void Menu2() { //menu 2 joueurs
    int i,j;
    for(i=0;i<9;i++) {
	for(j=0;j<25;j++) {
            if((i==0 || i==4 || i==8) || (((1<=i && i<=3) || (5<=i && i<=7)) &&((0<=j&&j<=5)||(18<j&&j<25)))) {
		textcolor(112);
		printf(" ");
            }
            else {
		textcolor(35);
		printf(" ");
            }
	}
	printf("\n");
    }
    gotoxy(3,11);
    textcolor(32); 
    printf("CONTRE");
    gotoxy(4,10); printf("MACHINE");
    gotoxy(7,9); printf("2 JOUEURS");
    textcolor(7);
    gotoxy(3,30); printf("Tapez 1 pour jouer avec la machine");
    gotoxy(7,30); printf("Tapez 2 pour module 2 joueur");  
}

void machine2(Valeur Val1[][4],Valeur Val2[][4],int score1,int score2) {
    int i,j;
    int tour = 0;
    Valeur Val3[4][4],Val4[4][4];
    char c;
    while (1) {
        system("cls");
        Tableau();
        Tableau2();
        if (tour%2 == 0) { //joueur
            randPos(Val1);
        }
        else { //machine
            randPos(Val2);
        }
        Cou(Val1); //couleur des cases
        Cou(Val2);
        for(i=0;i<4;i++) {
            for(j=0;j<4;j++) {
                Val3[i][j] = Val1[i][j];
            }
        }
        for(i=0;i<4;i++) {
            for(j=0;j<4;j++) {
                Val4[i][j] = Val2[i][j];
            }
        }        
        affiche2(Val1,Val2,&score1,&score2);
        gotoxy(28,1);
        textcolor(4);
        if (tour%2 == 0) {
            printf("Votre tour");
            c = _getch();
        }
        
        if (c == 'b') { //back to Menu
        //    fileSave(Val,score);
            break;
        }
        
        if (tour%2 == 0) {
            getKey(Val1,c,&score1);
        }
        else {
            c = minMax(Val2);
            getKey(Val2,c,&score2);
        }
        
        if (checkGame(Val1,Val3)==0 && checkGame(Val2,Val4)==1) {
            tour = 1;
        }
        else if (checkGame(Val1,Val3)==1 && checkGame(Val2,Val4)==0) {
            tour = 0;
        }
        else if (checkGame(Val1,Val3)==1 && checkGame(Val2,Val4)==1) {
            tour++; //n'en oublie pas
        }
        else { //end game
            system("cls");
            if (score1 > score2) {
                printf("Felicitation");
            }
            else if (score2 > score1) {
                printf("Vainqueur: machine");
            }
            c = _getch();
            break;
        }
    } 
}

char minMax(Valeur Val[][4]) { //Intelligence Artificielle
    int i=0,max;
    struct Tab {
        Valeur Val1[4][4];
        int score;
    }Ta[4];
    while(i<4) {
        initialTab(Val,Ta[i].Val1);
        Ta[i].score = 0;
        i++;
    }
    getKey(Ta[1].Val1,72,&Ta[1].score);
    getKey(Ta[2].Val1,80,&Ta[2].score);
    getKey(Ta[3].Val1,75,&Ta[3].score);
    getKey(Ta[4].Val1,77,&Ta[4].score);
    max = Ta[1].score;
    if (Ta[2].score > max) {
        max = Ta[2].score;
    }
    if (Ta[3].score > max) {
        max = Ta[3].score;
    }
    if (Ta[4].score > max) {
        max = Ta[4].score;
    }
    
    if (max == Ta[1].score) {
        return 72;
    }
    else if (max == Ta[2].score) {
        return 75;
    }
    else if (max == Ta[3].score) {
        return 80;
    }
    else if (max == Ta[4].score) {
        return 77;
    }
}

void initialTab(Valeur Val[][4],Valeur Val1[][4]) {
    int i,j;
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++) {
            Val1[i][j] = Val[i][j];
        }
    }
}
