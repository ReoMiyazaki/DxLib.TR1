#pragma once
#include "Global.h"
#include "Player.h"
#include "Weapon.h"

class Enemy {

public:
	//�R���X�g���N�^�̐錾
	Enemy(int enemyType);
	Enemy(EnemyStruct enemy);

	//�f�X�g���N�^�̐錾
	~Enemy();

	//�����o�֐�
	void Update(Player player, int  map[MAP_HEIGHT][MAP_WIDTH], Scroll& scroll);
	void Draw();

private:
	//�U���������邩���肷��֐�
	int DetermineIsAttackHit();

	void NomalMove(Player player);
	void Attack(Player player);
	void LoadComponent(Player player, int  map[MAP_HEIGHT][MAP_WIDTH]);

	//�e�G���Ƃ̊֐�
	void NomalMoveOfSlime();
	void AttackOfSlime();
	void DrawOfSlime();
	void LoadComponentOfSlime(Player player, int  map[MAP_HEIGHT][MAP_WIDTH]);

	void NomalMoveOfFencer();
	void AttackOfFencer(Player player);
	void DrawOfFencer();
	void LoadComponentOfFencer(Player player, int  map[MAP_HEIGHT][MAP_WIDTH]);

	void NomalMoveOfArcher(Player player);
	void DrawOfArcher();
	void AttackOfArcher(Player player);
	void LoadComponentOfArcher(Player player, int  map[MAP_HEIGHT][MAP_WIDTH]);

	//�G�֐��e���v���[�g
	//void NomalMoveOf{EnemyName}();
	//void AttackOf{EnemyName}();
	//void DrawOf{EnemyName}();
	//void LoadComponentOf{EnemyName}(Player player , int  map[MAP_HEIGHT][MAP_WIDTH]);

	void DebugDraw(Scroll scroll);

private:
	//�����o�ϐ�
	EnemyStruct enemy;
	Weapon* weapon;

};

