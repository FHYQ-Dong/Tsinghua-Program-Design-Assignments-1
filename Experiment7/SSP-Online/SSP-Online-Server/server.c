#include "./include/player.h"
#include "./include/judge.h"
#include "./include/bool.h"
#include <stdio.h>

extern void judge(Player *player1, Player *player2, Player *player3);

int main() {
    bool x;
    Player *player1 = newPlayer("player1", 1);
    scanf("%c", &x);
    printf("%c\n", x);
    return 0;
}