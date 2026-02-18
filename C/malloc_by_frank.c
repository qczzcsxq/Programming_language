#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#define MAX_SIZE 256
typedef struct Character {
	char* name;
	int level;
	int hp;
}Character;

Character* create_new_character(const char* name, int level, int hp);
void free_character(Character* character);

int main() {
	char name[MAX_SIZE];
	int level = 1;
	int hp = 100;
	puts("请输入角色名称 : ");
	scanf_s("%s", &name, MAX_SIZE);
	Character* new_character = create_new_character(name, level, hp);
	if (new_character == NULL) {
		perror("角色分配失败");
		return EXIT_FAILURE;
	}
	puts("创建成功！");
	free_character(new_character);
	return EXIT_SUCCESS;

}
Character* create_new_character(const char* name, int level, int hp) {
	Character* new_character = (Character*)malloc(sizeof(Character));
	if (new_character == NULL) {
		perror("角色分配失败");
		return NULL;
	}
	new_character->name = (char*)malloc(strlen(name) + 1);  //防止内存泄漏  一定一定注意
	if (new_character->name == NULL) {
		perror("无法分配角色昵称");
		free(new_character);   //防止内存泄漏 ！！！！！！！！！！
		return NULL;
	}
	strcpy_s(new_character->name, strlen(name) + 1, name);
	new_character->level = level;
	new_character->hp = hp;
	return new_character;
}
void free_character(Character* character) {
	if (character != NULL) {
		free(character->name);
		free(character);
	}
}
