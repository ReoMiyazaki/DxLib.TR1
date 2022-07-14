#include "Component.h"

//�}�b�v�`�b�v�Ƃ̓����蔻����s��
void Component::MapchipCollision(Transform& transform, Speed& speed, AerialController& aerialController, int  map[MAP_HEIGHT][MAP_WIDTH]) {

	MapCollider mapCollider = { 0 };

	//�{���̎l���̏c�����̍��W���擾����
	mapCollider.leftTopY = ((int)transform.pos.y - (int)transform.r) / MAP_SIZE;
	mapCollider.leftBottomY = ((int)transform.pos.y + (int)transform.r - 1) / MAP_SIZE;
	mapCollider.rightTopY = ((int)transform.pos.y - (int)transform.r) / MAP_SIZE;
	mapCollider.rightBottomY = ((int)transform.pos.y + (int)transform.r - 1) / MAP_SIZE;

	//�{���̎l���̉������̍��W���擾����
	mapCollider.rightTopX = ((int)transform.pos.x + (int)transform.r - 1) / MAP_SIZE;
	mapCollider.rightBottomX = ((int)transform.pos.x + (int)transform.r - 1) / MAP_SIZE;
	mapCollider.leftTopX = ((int)transform.pos.x - (int)transform.r) / MAP_SIZE;
	mapCollider.leftBottomX = ((int)transform.pos.x - (int)transform.r) / MAP_SIZE;

	//�󒆂ɂ��Ȃ��Ƃ�
	if (aerialController.isInTheAir == false) {

		//���ɑ��ꂪ�Ȃ����
		if (map[mapCollider.rightBottomY + 1][mapCollider.rightBottomX] == NONE &&
			map[mapCollider.leftBottomY + 1][mapCollider.leftBottomX] == NONE) {
			aerialController.isInTheAir = true;			//�󒆂ɂ��邱�Ƃɂ���
			speed.initialspeedY = 0;		//Y�������̏����x��0�ɂ���
		}

	}


	//���݂̎l���̏c�����̍��W�Ɉ�񕪐i�񂾏ꍇ�̍��W���擾
	mapCollider.leftTopY = (int)(transform.pos.y + speed.tmpY - transform.r) / MAP_SIZE;
	mapCollider.rightTopY = (int)(transform.pos.y + speed.tmpY - transform.r) / MAP_SIZE;
	mapCollider.leftBottomY = (int)(transform.pos.y + speed.tmpY + transform.r - 1) / MAP_SIZE;
	mapCollider.rightBottomY = (int)(transform.pos.y + speed.tmpY + transform.r - 1) / MAP_SIZE;

	if (speed.tmpY < 0) {
		if (map[mapCollider.rightTopY][mapCollider.rightTopX] == NONE &&
			map[mapCollider.leftTopY][mapCollider.leftTopX] == NONE) {
			speed.y += speed.tmpY;
		}
		else {//�V��ɂ���������
			aerialController.timer = 0;
			speed.initialspeedY = 0;
		}
	}

	else if (0 <= speed.tmpY) {
		if (map[mapCollider.rightBottomY][mapCollider.rightBottomX] == NONE &&
			map[mapCollider.leftBottomY][mapCollider.leftBottomX] == NONE) {
			speed.y += speed.tmpY;
		}
		else {
			//�n�ʂɂ�����
			aerialController.isInTheAir = false;	//�n�ʂɂ��邱�Ƃɂ���
			aerialController.timer = 0;			//aerialController.timer��0�ɂ���
			transform.pos.y = mapCollider.rightBottomY * MAP_SIZE - transform.r; //�����߂�����
		}
	}

	//�{���̎l���̏c�����̍��W���擾����
	mapCollider.leftTopY = ((int)transform.pos.y - (int)transform.r) / MAP_SIZE;
	mapCollider.leftBottomY = ((int)transform.pos.y + (int)transform.r - 1) / MAP_SIZE;
	mapCollider.rightTopY = ((int)transform.pos.y - (int)transform.r) / MAP_SIZE;
	mapCollider.rightBottomY = ((int)transform.pos.y + (int)transform.r - 1) / MAP_SIZE;




	if (transform.pos.x + transform.r < MAP_WIDTH * MAP_SIZE && 0 < transform.pos.x - transform.r) {//�w�肳�ꂽ�G���A���ɂ���Ȃ�

		if (0 < speed.tmpX) {
			//���݂̉E��A�E���̒��_�Ɉ�񕪉E�����ɐi�񂾏ꍇ�̍��W���擾
			mapCollider.rightTopX = (int)(transform.pos.x + speed.tmpX + transform.r - 1) / MAP_SIZE;
			mapCollider.rightBottomX = (int)(transform.pos.x + speed.tmpX + transform.r - 1) / MAP_SIZE;
			//�擾�������W�̈ʒu�̃}�b�v�`�b�v��NONE�ł���Ή������̃X�s�[�h���E�ɍs���悤�ɒl������
			if (map[mapCollider.rightTopY][mapCollider.rightTopX] == NONE &&
				map[mapCollider.rightBottomY][mapCollider.rightBottomX] == NONE) {
				speed.x += speed.tmpX;
			}
		}
		else {

			//���݂̍���A�����̒��_�Ɉ�񕪍������ɐi�񂾏ꍇ�̍��W���擾
			mapCollider.leftTopX = (transform.pos.x + speed.tmpX - transform.r) / MAP_SIZE;
			mapCollider.leftBottomX = (transform.pos.x + speed.tmpX - transform.r) / MAP_SIZE;
			//�擾�������W�̈ʒu�̃}�b�v�`�b�v��NONE�ł���Ή������̃X�s�[�h�����ɍs���悤�ɒl������
			if (map[mapCollider.leftTopY][mapCollider.leftTopX] == NONE &&
				map[mapCollider.leftBottomY][mapCollider.leftBottomX] == NONE) {
				speed.x += speed.tmpX;
			}
		}
	}

	//�{���̎l���̉������̍��W���擾����
	mapCollider.rightTopX = (int)((transform.pos.x + transform.r - 1) / MAP_SIZE);
	mapCollider.rightBottomX = (int)((transform.pos.x + transform.r - 1) / MAP_SIZE);
	mapCollider.leftTopX = (int)((transform.pos.x - transform.r) / MAP_SIZE);
	mapCollider.leftBottomX = (int)((transform.pos.x - transform.r) / MAP_SIZE);

}

//�d�͂̉e�����󂯂�
void Component::AffectedByGravity(Speed& speed, AerialController& aerialController) {
	if (aerialController.isInTheAir == true) {

		//�������x�̌v�Z������
		speed.tmpY = speed.initialspeedY + (G / 50) * aerialController.timer;
		aerialController.timer++;

	}
}

//�G�p

//�ڂŒǐՂ���
void Component::Enemy::Serch::TrackWithEyes(Eye& eye, Transform enemy, Player player, int  map[MAP_HEIGHT][MAP_WIDTH]) {

	eye.isVisuable = false;

	eye.angle = atan2(eye.y - enemy.pos.y,
		eye.x - enemy.pos.x);

	Vector2 fovUpper{
		enemy.pos.x + (float)cos(eye.angle + eye.fov / 2) * eye.range ,
		enemy.pos.y + (float)sin(eye.angle + eye.fov / 2) * eye.range
	};

	Vector2 fovCenter{
		enemy.pos.x + (float)cos(eye.angle) * eye.range ,
		enemy.pos.y + (float)sin(eye.angle) * eye.range
	};

	Vector2 fovLower{
		enemy.pos.x + (float)cos(eye.angle - eye.fov / 2) * eye.range ,
		enemy.pos.y + (float)sin(eye.angle - eye.fov / 2) * eye.range
	};

	Vector2 crossA1 = enemy.pos - fovUpper;
	Vector2 crossA2 = fovUpper - fovCenter;
	Vector2 crossA3 = fovCenter - fovLower;
	Vector2 crossA4 = fovLower - enemy.pos;

	Vector2 crossB1 = enemy.pos - player.GetTransform().pos;
	Vector2 crossB2 = fovUpper - player.GetTransform().pos;
	Vector2 crossB3 = fovCenter - player.GetTransform().pos;
	Vector2 crossB4 = fovLower - player.GetTransform().pos;


	if (crossA1.cross(crossB1) < 0 &&
		crossA2.cross(crossB2) < 0 &&
		crossA3.cross(crossB3) < 0 &&
		crossA4.cross(crossB4) < 0) {


		Vector2 tmpEye = enemy.pos;
		Vector2 ray = player.GetTransform().pos - enemy.pos;

		ray.nomalize();

		while (true) {
			tmpEye += ray;
			if (map[(int)(tmpEye.y / MAP_SIZE)][(int)(tmpEye.x / MAP_SIZE)] == BLOCK) {
				break;
			}
			else if (tmpEye.x <= player.GetTransform().pos.x + player.GetTransform().r &&
				player.GetTransform().pos.x - player.GetTransform().r <= tmpEye.x) {
				if (tmpEye.y <= player.GetTransform().pos.y + player.GetTransform().r &&
					player.GetTransform().pos.y - player.GetTransform().r <= tmpEye.y) {
					eye.isVisuable = true;
					eye.x = tmpEye.x;
					eye.y = tmpEye.y;
					break;
				}
			}
		}
	}

}

void  Component::Enemy::Attack::PredictMovement(Speed speed, float distansToPlayer, Target& target, Player player) {

	target.x = player.GetTransform().pos.x;
	target.y = player.GetTransform().pos.y;

	Vector2 playerMoveValue =
	{ (player.GetTransform().pos.x - player.GetOldTransform().pos.x) / 5 ,
		(player.GetTransform().pos.y - player.GetOldTransform().pos.y) / 5 };

	float time = distansToPlayer / speed.fixedValue;

	target.x += playerMoveValue.x * time;
	target.y += playerMoveValue.y * time;

}

void  Component::Enemy::Attack::PredictMovement(int flame, Target& target, Player player) {

	target.x = player.GetTransform().pos.x;
	target.y = player.GetTransform().pos.y;

	Vector2 playerMoveValue =
	{ (player.GetTransform().pos.x - player.GetOldTransform().pos.x) / 5 ,
		(player.GetTransform().pos.y - player.GetOldTransform().pos.y) / 5 };


	target.x += playerMoveValue.x * flame;
	target.y += playerMoveValue.y * flame;

}

void  Component::Enemy::Attack::SetAttackAngleSameAsEyeAngle(float& attackAngle, float eyeAngle) {
	attackAngle = eyeAngle;
}

void Component::Enemy::Attack::InversionAttackAngleBasedFace(float& attackAngle, int isFacingRight) {

	if (isFacingRight) {
		attackAngle = 0;
	}
	else {
		attackAngle = PI;
	}

}