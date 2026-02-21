#include <stdio.h>
#include <stdlib.h>
#define TIME_STRING_SIZE 26
typedef struct Player{
	int id;
	char name[30];
}Player;

void update_players(Player** players,int* current_size,int new_size,Player new_player);
void printplayers(Player* players, int size);
void log_message(const char* level,const char* message);
int main() {
	Player P1 = { 1,"Playone" };
	int current_size = 0;
	Player* players = NULL;   //*players就是玩家列表，是数组

	update_players(&players, &current_size, current_size + 1,P1);
	printplayers(players,current_size);
	free(players);

	return 0;
}  
void update_players(Player** players, int* current_size, int new_size, Player new_player) {
	Player* temp = (Player*)realloc(*players, new_size * sizeof(Player));
	if (temp != NULL) {
		*players = temp;
		if (new_size > *current_size) {
			(*players)[*current_size] = new_player; //*players 就是Player了
		}
		*current_size = new_size;
	}
	else {
		perror("Error reallocating memory!\n");
	}
}
void printplayers(Player* players,int size) {
	puts("Current players: ");
	for (size_t i = 0; i < size; ++i) {
		printf("Player's id : %d , Player's name : %s\n", players[i].id, players[i].name);
	}
}
void log_message(const char* level,const char* message){ //简单引入日志相关内容
	time_t now = time(NULL);
	char* time_str[TIME_STRING_SIZE];
	if(ctime_s(time_str,sizeof(time_str),&now) == 0){  
	time_str[24] = '\0'; // 不同系统需要找最后一个，用指针
	fprintf(stderr,"[%s] %s: %s\n",time_str,level,message);
}
	else {
	fprintf(stderr,"[ERROR] Failed to get current time\n");
}
}
