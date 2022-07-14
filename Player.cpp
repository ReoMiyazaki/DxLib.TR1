#include "Player.h"
#include "Component.h"

//�����̓v���C���[�̏����ō���̃e�[�}�O��������ɖʔ������Ƃ͏����ĂȂ���

//�R���X�g���N�^�̒�`
Player::Player() {
	//transform
	player.transform.pos.x = MAP_SIZE * 2;
	player.transform.pos.y = MAP_SIZE * (MAP_HEIGHT - 5);
	player.transform.r = 15;

	//speed
	player.speed.fixedValue = 3;

	//others
	player.aerialController.timer = 0;
	player.isJump = 0;
	player.aerialController.isInTheAir = 0;
}

Player::Player(PlayerStruct player) {
	this->player = player;
}

//�f�X�g���N�^�̒�`
Player::~Player() {

}

//�����o�֐�
//�X�V�����̊֐�
void Player::Update(char* keys, char* oldkeys, int  map[MAP_HEIGHT][MAP_WIDTH], Scroll& scroll) {

	//�ȑO�̈ʒu���擾
	for (int i = 4; 0 <= i; i--) {
		if (i == 0) {
			player.oldTransform[i] = player.transform;
		}
		else {
			player.oldTransform[i] = player.oldTransform[i - 1];
		}
	}

	//���x��0����
	player.speed.x = 0;
	player.speed.y = 0;
	player.speed.tmpX = 0;
	player.speed.tmpY = 0;

	//�L�[����
	if (keys[KEY_INPUT_RIGHT] == 1 || keys[KEY_INPUT_D] == 1) {//�E�L�[�������ꂽ��

		player.speed.tmpX += player.speed.fixedValue;

	}
	if (keys[KEY_INPUT_LEFT] == 1 || keys[KEY_INPUT_A] == 1) {//���L�[�������ꂽ��

		player.speed.tmpX -= player.speed.fixedValue;

	}

	if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
		if (player.isJump == false) {
			player.isJump = true;
			player.speed.initialspeedY = -5;
			player.aerialController.isInTheAir = true;
		}
		else if (player.isfloatJump == false) {
			player.isfloatJump = true;
			player.speed.initialspeedY = -5;
			player.aerialController.timer = 0;

		}
	}


	//�n�ʂɂ���Ȃ�
	if (player.aerialController.isInTheAir == false) {
		//�W�����v�t���O��false�ɂ���
		player.isJump = false;
		player.isfloatJump = false;
	}

	//�d�͂̉e�����󂯂�
	Component::AffectedByGravity(player.speed, player.aerialController);
	//�}�b�v�`�b�v�Ƃ̓����蔻����s��
	Component::MapchipCollision(player.transform, player.speed, player.aerialController, map);

	player.transform.pos.x += player.speed.x;
	if (player.speed.x != 0) {
		if (player.speed.x < 0) {
			if (player.screen.x <= MAP_SIZE * 9) {
				if (0 < scroll.x) {//�X�N���[���l��0���傫�����
					scroll.x += player.speed.x;//�v���[���[�̃X�s�[�h���X�N���[���l�����炷
				}
			}
		}
		else if (0 < player.speed.x) {
			if (MAP_SIZE * 11 <= player.screen.x) {
				if (scroll.x < scroll.MAX_X) {//�X�N���[���l��0���傫�����
					scroll.x += player.speed.x;//�v���[���[�̃X�s�[�h���X�N���[���l�����炷
				}
			}
		}
	}

	player.transform.pos.y += player.speed.y;

	player.screen.x = player.transform.pos.x - scroll.x;
	player.screen.y = player.transform.pos.y - scroll.y;
}

//�`�揈���̊֐�
void Player::Draw() {
	DrawCircle(player.screen.x,
		player.screen.y,
		player.transform.r,
		GetColor(255, 255, 255),
		true);
}

//�A�N�Z�b�T
Transform Player::GetTransform() {
	return player.transform;
}

Transform Player::GetOldTransform() {
	return player.oldTransform[4];
}