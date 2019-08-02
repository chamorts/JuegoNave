#include<stdio.h>
#include<windows.h>
#include<conio.h>

void gotoxy(int x, int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;

    SetConsoleCursorPosition(hCon, dwPos);

}
void OcultalCursor(){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;

    SetConsoleCursorInfo(hCon,&cci);

}

class NAVE{
    int x,y;
public:
    NAVE(int _x, int _y): x(_x),y(_y){}
    void pintar();
    void borrar();
    void mover();
};



void NAVE::pintar(){
    gotoxy(x,y); printf("  %c",30);
    gotoxy(x,y+1); printf("  %c%c%c",40,207,41);
    gotoxy(x,y+2); printf("%c%c  %c%c",30,190,190,30);

}

void NAVE::borrar(){
    gotoxy(x,y); printf("     ");
    gotoxy(x,y+1); printf("     ");
    gotoxy(x,y+2); printf("     ");


}

void NAVE::mover(){
    if(kbhit()){
            char tecla = getch();
            borrar();
            if(tecla== 'a')x--;
            if(tecla== 'd')x++;
            if(tecla== 'w')y--;
            if(tecla== 's')y++;
            pintar();
        }


}

int main(){

   OcultalCursor();
   NAVE N(7,7);
   N.pintar();
   bool game_over=false;
   while(!game_over){



        N.mover();
        Sleep(30);

   }
    return 0;

}
