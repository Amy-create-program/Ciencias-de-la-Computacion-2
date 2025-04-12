#include <ncurses.h>

bool puzzleResuelto(int (*matriz)[3]) {
    int contador = 1;
    for(int (*p)[3] = matriz; p < matriz + 3; p++) {
        for(int *q = *p; q < (p == matriz+2 ? *p + 3 : *(p+1)); q++) {
            if(q == *(matriz+2)+2) return (*q == 0);
            if(*q != contador++) return false;
        }
    }
    return true;
}
void imprimirMatriz(int (*matriz)[3], int vacioY, int vacioX) {
    int y = 0;
    for(int (*p)[3] = matriz; p < matriz + 3; p++, y++) {
        int x = 0;
        for(int *q = *p; q < (p == matriz+2 ? *p + 3 : *(p+1)); q++, x++) {
            if(*q == 0) {
                printw("    ");
            } else {
                printw(" %2d ", *q);
            }
            printw("|");
        }
        printw("\n-----------------\n");
    }
}

int main() {
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);

    int matriz[3][3] = {{4, 2, 6}, {1, 3, 7}, {8, 5, 0}};
    int vacioY = 2, vacioX = 2;

    while(true) {
        clear();
        
        if(puzzleResuelto(matriz)) {
            printw("\n¡Felicidades! Resolviste el puzzle.\n");
            refresh();
            getch();
            break;
        }
    
        imprimirMatriz(matriz, vacioY, vacioX);
        printw("\nUsa las flechas para mover los números");
        refresh();
        
        int tecla = getch();
        int nuevaY = vacioY, nuevaX = vacioX;
        
        switch(tecla) {
            case KEY_UP: nuevaY++; break;
            case KEY_DOWN: nuevaY--; break;
            case KEY_LEFT: nuevaX++; break;
            case KEY_RIGHT: nuevaX--; break;
        }
        
        if(nuevaY >= 0 && nuevaY < 3 && nuevaX >= 0 && nuevaX < 3) {
            int *actual = *(matriz + vacioY) + vacioX;
            int *objetivo = *(matriz + nuevaY) + nuevaX;
            
            *actual = *objetivo;
            *objetivo = 0;
            vacioY = nuevaY;
            vacioX = nuevaX;
        }
    }
    
    endwin();
    return 0;
}
