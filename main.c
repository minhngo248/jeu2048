/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Minh NGO
 *
 * Created on May 11, 2020, 2:45 PM
 */

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "files/Header files/header.h"
#include "files/Header files/header1.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Valeur Val[4][4];
    Valeur Val2[4][4];
    int score,score1;
    int i,j;
    char c;
    resizeConsole(900,800);
    while (1) {
        system("cls"); 
        Menu();
        do {
            c = _getch();
        }while (c!='1' && c!='2'&&c!='x');
        
        if (c == 'x') { //sortir
            break;
        }
        else if (c == '1') { //Mode 1 joueur
            system("cls");
            Menu1();
            do{
                c = _getch();
            }while(c!='1'&&c!='2'&&c!='3');
            
            if (c == '1') {
                resumeGame(Val,score);
            }
            else if (c == '2') {
                score = 0;
                initialVal(Val);
                newGame(Val,score);
            }
            else {
                system("cls");
                rankScore();
                c = _getch();            
            }
        }
        else { //module 2 joueur
            system("cls");
            Menu2();
            do{
                c = _getch();
            }while(c!='1'&&c!='2');
            
            if (c == '1') { //contre la machine
                score = 0;
                score1 = 0;
                initialVal(Val);
                initialVal(Val2);
                machine2(Val,Val2,score,score1);                
            }
            else { //2 joueurs
                score = 0;
                score1 = 0;
                initialVal(Val);
                initialVal(Val2);
                newGame2(Val,Val2,score,score1);
            }           
        }
    }
    return (EXIT_SUCCESS);
}
