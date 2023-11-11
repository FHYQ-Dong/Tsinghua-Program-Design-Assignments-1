#include <winsock2.h>
#include <Windows.h>
#include <stdlib.h>
#pragma comment(lib, "ws2_32.lib")

#include "player.h"

static int _BattleResult_delete(BattleResult* this) {
    free(this->name);
    free(this->result);
    free(this);
    return 0;
}

extern BattleResult* newBattleResult(char** name, RESULT* result) {
    BattleResult* battleResult = (BattleResult*)malloc(sizeof(BattleResult));
    battleResult->name = name;
    battleResult->result = result;
    battleResult->delete = _BattleResult_delete;
    return battleResult;
}

static int _Player_delete(Player* this) {
    closesocket(this->socket);
    free(this->name);
    free(this);
    return 0;
}

extern Player* newPlayer(char* name, SOCKET socket) {
    Player* player = (Player*)malloc(sizeof(Player));
    memset(player, 0, sizeof(Player));
    player->name = name;
    player->socket = socket;
    player->delete = _Player_delete;
    return player;
}