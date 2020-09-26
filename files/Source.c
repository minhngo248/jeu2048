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

void resizeConsole(int width, int height) {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);    
}

void textcolor(int x) {
    HANDLE cou;
    cou=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(cou,x);
}

void gotoxy(int x, int y) { //x : ligne , y : colonne
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {y-1,x-1};   
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
    SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

void Tableau() { //tableau du jeu
    int i,j;
    for(i=0;i<=24;i++) {
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
	printf("\n");
    }
}

void Menu() {
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
    gotoxy(3,9);
    textcolor(32); 
    printf("1 JOUEUR");
    gotoxy(7,9); printf("2 JOUEURS");
    textcolor(7);
    gotoxy(3,30); printf("Tapez 1 pour module 1 joueur");
    gotoxy(7,30); printf("Tapez 2 pour module 2 joueur");
    gotoxy(11,30); printf("Tapez X pour sortir");
}

void initialVal(Valeur Val[][4]) { //initial valeur Taille 4x4
    int i,j;
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++) {
            Val[i][j].data = 0;
        }
    }  
}

void affiche(Valeur Val[][4],int* score) {
    int i,j;
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++) {
            if(Val[i][j].data != 0) {
                gotoxy(6*i+4,6*j+4);
                textcolor(Val[i][j].cou);
                printf("%d",Val[i][j].data);
            } 
        }
    }
    gotoxy(1,30); textcolor(3);
    printf("Score: %d",*score);
    gotoxy(3,30); textcolor(4);
    printf("Tapez B pour revenir au Menu");
}

void Cou(Valeur Val[][4]) { //affectation de couleur
    int i,j;
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++) {
            switch (Val[i][j].data) {
                case 0:
                {Val[i][j].cou = 0; break;}
                case 2:
                {Val[i][j].cou = 63;
                break;}
                case 4:
                {Val[i][j].cou = 62;
                break;}
                case 8:
                {Val[i][j].cou = 61;
                break;}
                case 16:
                {Val[i][j].cou = 60;
                break;}
                case 32:
                {Val[i][j].cou = 59;
                break;}
                case 64:
                {Val[i][j].cou = 58;
                break;}
                case 128:
                {Val[i][j].cou = 53;
                break;}
                case 256:
                {Val[i][j].cou = 49;
                break;}
                case 512:
                {Val[i][j].cou = 50;
                break;}
                case 1024:
                {Val[i][j].cou = 52;
                break;}
                default:
                {Val[i][j].cou = 48;
                break;}
            }      
        }
    } 
}

void turnLeft(Valeur Val[][4],int *score) {
    int ligne,i,j;
    for(ligne=0;ligne<4;ligne++) {
	for(j=1;j<4;j++) {
            for(i=j-1;i>=0;i--) {
		if(Val[ligne][i].data==0) {
                    Val[ligne][i] = Val[ligne][i+1];
                    Val[ligne][i+1].data=0;
                }
            }
	}
    }

    for(ligne=0;ligne<4;ligne++) {
	for(j=0;j<4;j++) {
            if(Val[ligne][j].data == Val[ligne][j+1].data) {
		Val[ligne][j].data+=Val[ligne][j+1].data;
		*score+=Val[ligne][j].data;
		Val[ligne][j+1].data=0;
		}
            }
	}
  
    for(ligne=0;ligne<4;ligne++){
        for(j=1;j<4;j++) {
            for(int i=j-1;i>=0;i--) {
                if(Val[ligne][i].data==0) {
                    Val[ligne][i] = Val[ligne][i+1];
                    Val[ligne][i+1].data = 0;
                }
            }
        }
    }
}

void turnRight(Valeur Val[][4],int* score) {
    int ligne,i,j;
    for(ligne=0;ligne<4;ligne++){
	for(j=2;j>=0;j--) {
            for(i=j+1;i<=3;i++) {
                if(Val[ligne][i].data==0) {
                    Val[ligne][i]=Val[ligne][i-1];
                    Val[ligne][i-1].data=0;
                }
            }
	}
    }

    for(i=0;i<=3;i++) {
	for(int j=2;j>=0;j--) {
            if (Val[i][j].data==Val[i][j+1].data) {
		Val[i][j+1].data+=Val[i][j].data;
		*score+=Val[i][j+1].data;
                Val[i][j].data=0; 
            }
	}
    }
    for(ligne=0;ligne<4;ligne++){
	for(j=2;j>=0;j--) {
            for(i=j+1;i<=3;i++) {
		if(Val[ligne][i].data==0){
                    Val[ligne][i]=Val[ligne][i-1];
                    Val[ligne][i-1].data=0;
		}
            }
	}
    }	
}

void goUp(Valeur Val[][4],int* score) {
    int col,i,j;
    for(col=0;col<4;col++){
	for(i=1;i<4;i++) {
            for(int j=i-1;j>=0;j--){
		if(Val[j][col].data==0) {
                    Val[j][col]=Val[j+1][col];
                    Val[j+1][col].data=0;
		}
            }
	}
    }
    
    for(j=0;j<4;j++) {
	for(i=1;i<4;i++) {
            if(Val[i][j].data==Val[i-1][j].data) {
		Val[i-1][j].data+=Val[i][j].data;
		*score=*score + Val[i-1][j].data;
		Val[i][j].data=0;
            }
	}
    }
    for(col=0;col<4;col++){
	for(i=1;i<4;i++){
            for(j=i-1;j>=0;j--) {
		if(Val[j][col].data==0){
                    Val[j][col]=Val[j+1][col];
                    Val[j+1][col].data=0;
		}
            }
	}
    }
}

void goDown(Valeur Val[][4],int *score) {
    int col,i,j;
    for(col=0;col<4;col++){
	for(int j=2;j>=0;j--) {
            for(int i=j+1;i<=3;i++){
		if(Val[i][col].data==0){
                    Val[i][col]=Val[i-1][col];
                    Val[i-1][col].data=0;
                }
            }
        }
    }
    
    for(j=0;j<4;j++){
        for(i=3;i>=0;i--){
            if(Val[i][j].data==Val[i-1][j].data){
		Val[i][j].data+=Val[i-1][j].data;
		*score=*score + Val[i][j].data;
		Val[i-1][j].data=0;
            }
	}
    }
    for(col=0;col<4;col++){
	for(int j=2;j>=0;j--){
            for(int i=j+1;i<=3;i++){
		if(Val[i][col].data==0) {
                    Val[i][col]=Val[i-1][col];
                    Val[i-1][col].data=0;
		}
            }
	}
    }
}

void getKey(Valeur Val[][4],char c,int *score) {	
    switch (c) {
        case 'w': {goUp(Val,score); break; }
        case 'd': {turnRight(Val,score); break; }
        case 's': {goDown(Val,score); break; }
        case 'a': {turnLeft(Val,score); break; }
    }
}

int checkTour(Valeur Val[][4],Valeur Val1[][4]) {
    int i,j;
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++) {
            if (Val[i][j].data != Val1[i][j].data) return 1;
        }
    }
    return 0;
}

int checkGame(Valeur Val[][4],Valeur Val1[][4]) { //condition de fin
    int i,j;
    for(i=0;i<4;i++) {
	for(j=0;j<4;j++) {
            if(Val[i][j].data == 0) return 1;
	}
    }
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++) {
            if (checkTour(Val,Val1) == 0) return 0;
            else return 1;
        }
    } 
}

void randPos(Valeur Val[][4]) {
    int i,j;
    srand(time(NULL));
    do {
        i = rand()%(4);
	j = rand()%(4);
    } while(Val[i][j].data != 0);
    randValeur(Val,i,j);
}

void randValeur(Valeur Val[][4],int i,int j) {
    srand(time(NULL));
    do {
        Val[i][j].data = 2 + rand()%3;
    } while (Val[i][j].data != 2 && Val[i][j].data != 4);
}

void rankScore() { //extraire fichier "Score.txt"
    int A[10],i,j;
    FILE *fp;
    for(i=0;i<23;i++) {
	for(j=0;j<25;j++) {
            textcolor(112);
            printf(" ");
	}
	printf("\n");
    }
    fp = fopen("Score.txt","r");
    for(i=0;i<10;i++) {
        fscanf(fp,"%d\n",&A[i]);
    }
    fclose(fp);
    gotoxy(3,5); textcolor(112);printf("1. %d",A[0]);
    gotoxy(5,5); textcolor(112);printf("2. %d",A[1]);
    gotoxy(7,5); textcolor(112);printf("3. %d",A[2]);
    gotoxy(9,5); textcolor(112);printf("4. %d",A[3]);
    gotoxy(11,5); textcolor(112);printf("5. %d",A[4]);
    gotoxy(13,5); textcolor(112);printf("6. %d",A[5]);
    gotoxy(15,5); textcolor(112);printf("7. %d",A[6]);
    gotoxy(17,5); textcolor(112);printf("8. %d",A[7]);
    gotoxy(19,5); textcolor(112);printf("9. %d",A[8]);
    gotoxy(21,5); textcolor(112);printf("10. %d",A[9]);
    gotoxy(23,30); textcolor(15);printf("Tapez un bouton pour retourner au Menu");
}

void fileScore(int score) { //tri selection
    FILE *fp;
    int A[10],i,j;
    fp = fopen("Score.txt","r");
    for(i=0;i<10;i++) {
	fscanf(fp,"%d\n",&A[i]);
    }
    for(i=0;i<10;i++) {
	if(score > A[i]) {
            for(j=9;j>i;j--) {
		A[j] = A[j-1];
            }
            A[i] = score;
            break;
	}
    }
    fclose(fp);
    fp = fopen("Score.txt","w");
    for(i=0;i<10;i++) {
        fprintf(fp,"%d\n",A[i]);
    }
    fclose(fp);
}
