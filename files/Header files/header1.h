/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   header1.h
 * Author: Minh NGO
 *
 * Created on June 3, 2020, 5:24 PM
 */

#ifndef HEADER1_H

void Tableau2();
void affiche2(Valeur Val1[][4],Valeur Val2[][4],int* score1,int* score2);

void newGame2(Valeur Val1[][4],Valeur Val2[][4],int score1,int score2); //2 joueurs
void machine2(Valeur Val1[][4],Valeur Val2[][4],int score1,int score2);

void Menu1();
void Menu2();

char minMax(Valeur Val[][4]); //Intelligence Artificielle
void initialTab(Valeur Val[][4],Valeur Val1[][4]);

#endif