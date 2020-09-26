/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   header.h
 * Author: Minh NGO
 *
 * Created on May 11, 2020, 2:47 PM
 */

#ifndef HEADER_H

typedef struct Valeur Valeur;
struct Valeur { //case
    int cou;
    int data;
};

void resizeConsole(int width,int height);
void textcolor(int x);
void gotoxy(int x,int y);
void Tableau(); //tableau du jeu
void initialVal(Valeur Val[][4]); //initialiser les Valeurs 4x4
void Cou(Valeur Val[][4]);
void Menu(); //menu principal
void affiche(Valeur Val[][4],int* score);
int checkTour(Valeur Val[][4],Valeur Val1[][4]);
int checkGame(Valeur Val[][4],Valeur Val1[][4]); //condition de fin du jeu
void getKey(Valeur Val[][4],char c,int* score);
//4 directions (utiliser les fleches)
void goDown(Valeur Val[][4],int* score); 
void goUp(Valeur Val[][4],int* score); 
void turnLeft(Valeur Val[][4],int* score); 
void turnRight(Valeur Val[][4],int* score);

void randPos(Valeur Val[][4]);
void randValeur(Valeur Val[][4],int i,int j);

void fileScore(int score);
void rankScore(); //classement des 10 meilleurs scores

void resumeGame(Valeur Val[][4],int score);
void newGame(Valeur Val[][4],int score);

void fileSave(Valeur Val[][4],int score); //Save score to resume game

#endif /* HEADER_H */