#pragma once
#include "Global.h"

//�����̓v���C���[�̏����ō���̃e�[�}�O��������ɖʔ������Ƃ͏����ĂȂ���

class Player {
public:
	//�R���X�g���N�^�̐錾
	Player();
	Player(PlayerStruct player);
	//�f�X�g���N�^�̐錾
	~Player();

	//�����o�֐�
	void Update(char* keys, char* oldkeys, int  map[MAP_HEIGHT][MAP_WIDTH], Scroll& scroll);
	void Draw();
	Transform GetTransform();
	Transform GetOldTransform();

private:
	//�����o�ϐ�
	PlayerStruct player;
};