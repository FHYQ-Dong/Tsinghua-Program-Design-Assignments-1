#ifndef _PLAYER_H
#define _PLAYER_H
#include <winsock2.h>
#include <Windows.h>

#pragma comment(lib, "ws2_32.lib")

#define STONE 1
#define PAPER 2
#define SCISSORS 3
#define NONE 0
typedef int OPTION;

#define WIN 4
#define LOSE 5
#define DRAW 6
typedef int RESULT;

typedef struct BattleResult {
    char** name; // 2
    RESULT* result; // 2
    int (*delete)(struct BattleResult* this);
} BattleResult;

typedef struct Player {
    char* name;
    int score;
    OPTION option;
    BattleResult result;
    SOCKET socket;
    int (*delete)(struct Player* this);
} Player;

extern Player* newPlayer(char* name, SOCKET socket);

extern BattleResult* newBattleResult(char** name, RESULT* result); // 2

#endif // !_PLAYER_H