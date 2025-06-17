#include <stdio.h>
#include <string.h>

#define MAP_SIZE 5

int game(){
    int x = 3;
    int y = 3;
    int map[MAP_SIZE][MAP_SIZE];
        
    int e = 0;

    char input[2];
    while(e < 1){
        printf("\e[1;1H\e[2J");
        for(int iy = 1; iy <= MAP_SIZE; iy++){
            for(int ix = 1; ix <= MAP_SIZE; ix++){
                if(x == ix && y == iy){
                    printf("+");
                }
                else{
                    printf("-");
                }
            }
        printf("\n");
        }
        printf("\n%d, %d\n", x, y);
        fgets(input, sizeof(input), stdin);
        if(strcmp(input, "w") == 0) {
            y--;
        }
        if(strcmp(input, "a") == 0) {
            x--;
        }
        if(strcmp(input, "s") == 0) {
            y++;
        }
        if(strcmp(input, "d") == 0) {
            x++;
        }


        if(strcmp(input, "q") == 0) {
            e = 1;
            return 0;
        }
  }
}

int main(){
    char input[2];
    printf("the silly game demo thingy");
    printf("press enter");
    fgets(input, sizeof(input), stdin);
    game();
    return 0;
}