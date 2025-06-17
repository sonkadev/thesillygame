#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAP_HEIGHT 6
#define MAP_WIDTH  10
int game(int OpenSave){
    FILE *savefile;

    int x = 3;
    int y = 3;

    if(OpenSave == 1) { 
        savefile = fopen("./saves/save", "r");
        if(savefile != NULL) { 
            if(fscanf(savefile, "%d %d", &x, &y) != 2) { 
                x = 3;
                y = 3;
            }
            fclose(savefile);
        }
    }
    

    int map[MAP_WIDTH][MAP_HEIGHT];

    int e = 0;

    char input[2];
    while(e < 1){
        printf("\e[1;1H\e[2J");
        for(int iy = 1; iy <= MAP_HEIGHT; iy++){
            for(int ix = 1; ix <= MAP_WIDTH; ix++){
                if(x == ix && y == iy){
                    printf("+");
                }
                else{
                    printf("-");
                }
            }
        printf("\n");
        }
        int canMove = 1;
        printf("\n%d, %d\n", x, y);

        scanf("%s", input);

        if(sizeof(input) == 2){
        if(strcmp(input, "q") == 0) {   
            e = 1;
            return 0;
        }
        if(strcmp(input, "w") == 0 && y > 1) {
            y--;
        }
        if (strcmp(input, "a") == 0 && x > 1) {
            x--;
        }
        if(strcmp(input, "s") == 0 && y < MAP_HEIGHT) {
            y++;
        }
        if(strcmp(input, "d") == 0 && x < MAP_WIDTH) {
            x++;
        }
        if(strcmp(input, "v") == 0) {
            savefile = fopen("./saves/save", "w");
            fprintf(savefile, "%d\n%d",x , y);
            fclose(savefile); 
        }
        input == "";
        }     
  }
}

int main(){
    FILE *savefile;
    char input[2];
    printf("the silly game demo thingy\n");
    printf("press enter to start a new game, o to open the save files\n");
    fgets(input, sizeof(input), stdin);
    game(0);
    return 0;
}