#pragma once
#include "Global.h"
#include "Player.h"
#include "Enemy.h"

namespace Component {

	//�}�b�v�`�b�v�Ƃ̓����蔻����s��
	void MapchipCollision(Transform& transform, Speed& speed, AerialController& aerialController, int  map[MAP_HEIGHT][MAP_WIDTH]);

	//�d�͂̉e�����󂯂�
	void AffectedByGravity(Speed& speed, AerialController& aerialController);

	namespace Enemy {
		namespace Serch {
			//�ڂŒǐՂ���
			void TrackWithEyes(Eye& eye, Transform enemy, Player player, int  map[MAP_HEIGHT][MAP_WIDTH]);
		}

		namespace Attack {
			//�\���ˌ�
			//��ѓ���Ȃǂ̃X�s�[�h����v�Z(�������������)
			void PredictMovement(Speed speed, float distansToPlayer, Target& target, Player player);
			//�U�������܂ł̃t���[��������v�Z(�ߐڕ������)
			void PredictMovement(int flame, Target& target, Player player);

			//�U���̊p�x�������̊p�x�Ɠ����ɂ���
			void SetAttackAngleSameAsEyeAngle(float& attackAngle, float eyeAngle);

			//�U���̊p�x�������ɂ���Ĕ��]������
			void InversionAttackAngleBasedFace(float& attsakAngle, int isFacingRight);
		}
	}
}

