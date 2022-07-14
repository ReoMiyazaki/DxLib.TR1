#pragma once
#include "Global.h"

class Weapon {
public:
	//�R���X�g���N�^�̐錾
	Weapon(int weaponType);

	//�f�X�g���N�^�̐錾
	~Weapon();

	//�����o�֐�
	void Update(Transform transform, Scroll scroll, int map[MAP_HEIGHT][MAP_WIDTH]);

	void Draw();

	//�A�N�Z�b�T
	void SetIsShot(int isShot);

	Speed GetSpeed();
	void SetSpeedFixedValue(float fixedValue);

	void SetAngle(float angle);

	float GetLength();

	void SetLength(float length);

private:
	//�����o�ϐ�

	Transform tipTransform;
	Transform rootTransform;
	Screen tipScreen;
	Screen rootScreen;
	Speed speed;
	float angle;
	int weaponType;
	int isShot;

};