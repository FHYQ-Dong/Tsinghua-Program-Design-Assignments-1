#include "judge.h"
#include "player.c"

static RESULT _battle(OPTION x, OPTION y) {
    if (x == y) return DRAW;
    if (x == STONE && y == SCISSORS) return WIN;
    if (x == STONE && y == PAPER) return LOSE;
    if (x == PAPER && y == STONE) return WIN;
    if (x == PAPER && y == SCISSORS) return LOSE;
    if (x == SCISSORS && y == PAPER) return WIN;
    if (x == SCISSORS && y == STONE) return LOSE;
}

extern void judge(Player* player1, Player* player2, Player *player3) {
    OPTION option1 = player1->option, option2 = player2->option, option3 = player3->option;
    
    char **opponent1 = malloc(sizeof(char*) * 2); opponent1[0] = player2->name; opponent1[1] = player3->name;
    RESULT  *result1 = malloc(sizeof(RESULT) * 2); result1[0] = _battle(option1, option2); result1[1] = _battle(option1, option3);
    player1->result = *newBattleResult(opponent1, result1);
    char **opponent2 = malloc(sizeof(char*) * 2); opponent2[0] = player1->name; opponent2[1] = player3->name;
    RESULT  *result2 = malloc(sizeof(RESULT) * 2); result2[0] = _battle(option2, option1); result2[1] = _battle(option2, option3);
    player2->result = *newBattleResult(opponent2, result2);
    char **opponent3 = malloc(sizeof(char*) * 2); opponent3[0] = player1->name; opponent3[1] = player2->name;
    RESULT  *result3 = malloc(sizeof(RESULT) * 2); result3[0] = _battle(option3, option1); result3[1] = _battle(option3, option2);
    player3->result = *newBattleResult(opponent3, result3);
}