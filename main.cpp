#include "Global.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlib�̏�����
	if (DxLib_Init() == -1) { return -1; }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���


	// �Q�[�����[�v�Ŏg���ϐ��̐錾
	srand(time(nullptr));
	// const int dataMax = 10;

	int linearData[10] = { 0 };

	int binaryData[] = { 1, 4, 6, 7, 9, 11, 13 };

	int hashData[] = { 901, 678, 345, 12, 789, 456, 123, 890, 567, 234 };

	int minListNum = 1;
	int midListNum = 0;
	int maxListNum = 7;

	int quotient = 0;
	int remainder = 0;

	int searchValue = 901;
	int dateCount = 0;

	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = { 0 };

	// �Q�[�����[�v
	while (true) {
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		// �ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		//---- �X�V ----//

#pragma region ���`�T��(���j�A�T�[�`)

		while (dateCount < 11) {
			if (searchValue == linearData[dateCount]) {
				break;
			}
			dateCount++;
		}

#pragma endregion

#pragma region �񕪒T��(�o�C�i���T�[�`)
		while (true) {
			// �f�[�^�̒��Ԓl�����߂�
			midListNum = (minListNum + maxListNum) / 2;
			// �O�����
			if (maxListNum < minListNum) {
				break;
			}
			// �T���l���f�[�^�l���������ꍇ�A���Ԓl��1����������
			if (binaryData[midListNum] < searchValue) {
				minListNum = midListNum + 1;
			}
			// �T���l���f�[�^�l���傫���ꍇ�A���Ԓl��1����������
			else if (searchValue < binaryData[midListNum]) {
				maxListNum = midListNum - 1;
			}
			// �T���l�ƃf�[�^�l�������ꍇ���[�v���o��
			else if (searchValue == binaryData[midListNum]) {
				break;
			}
		}
#pragma endregion

#pragma region �n�b�V���T��(�n�b�V���@)

		quotient = searchValue / 100;
		remainder = searchValue % 100;

		quotient += remainder / 10;
		remainder = remainder % 10;

		quotient += remainder;
		quotient = quotient % 10;

#pragma endregion

		//---- �`�� ----//

#pragma region ���`�T��(���j�A�T�[�`)

//		if (dateCount <= 10) {
//			DrawFormatString(5, 5, GetColor(255, 255, 255), "searchValue[ %d ]��Data���ɑ��݂��܂�\n", searchValue, 2);
//		}
//		else if (dateCount > 10) {
//			DrawFormatString(5, 5, GetColor(255, 255, 255), "searchValue[ %d ]��Data���ɑ��݂��܂���\n", searchValue, 2);
//		}
//		for (int i = 0; i < 10; i++) {
//			if (searchValue == linearData[i]) {
//				DrawFormatString(5, 30 + 30 * i, GetColor(255, 25, 25), "TargetList[ %d ]\n", linearData[i], 2);
//			}
//			else if (searchValue != linearData[i]) {
//				DrawFormatString(5, 30 + 30 * i, GetColor(255, 255, 255), "TargetList[ %d ]\n", linearData[i], 2);
//			}
//		}

#pragma endregion

#pragma region �񕪒T��(�o�C�i���T�[�`)

//		if (binaryData[midListNum] == searchValue) {
//			DrawFormatString(5, 5, GetColor(255, 255, 255), "searchValue[ %d ]��Data���ɑ��݂��܂�\n", searchValue, 2);
//		}
//		else
//		{
//			DrawFormatString(5, 5, GetColor(255, 255, 255), "searchValue[ %d ]��Data���ɑ��݂��܂���\n", searchValue, 2);
//		}
//		for (int i = 0; i < 7; i++) {
//			if (searchValue == binaryData[i]) {
//				DrawFormatString(5, 30 + 30 * i, GetColor(255, 25, 25), "TargetList[ %d ]\n", binaryData[i], 2);
//			}
//			else if (searchValue != binaryData[i]) {
//				DrawFormatString(5, 30 + 30 * i, GetColor(255, 255, 255), "TargetList[ %d ]\n", binaryData[i], 2);
//			}
//		}

#pragma endregion

#pragma region �n�b�V���T��(�n�b�V���@)

		if (hashData[quotient] == searchValue) {
			DrawFormatString(5, 5, GetColor(255, 255, 255), "searchValue[ %d ]��Data���ɑ��݂��܂�\n", searchValue, 2);
		}
		else
		{
			DrawFormatString(5, 5, GetColor(255, 255, 255), "searchValue[ %d ]��Data���ɑ��݂��܂���\n", searchValue, 2);
		}
		for (int i = 0; i < 10; i++) {
			if (searchValue == hashData[i]) {
				DrawFormatString(5, 30 + 30 * i, GetColor(255, 25, 25), "TargetList[ %d ]\n", hashData[i], 2);
			}
			else if (searchValue != hashData[i]) {
				DrawFormatString(5, 30 + 30 * i, GetColor(255, 255, 255), "TargetList[ %d ]\n", hashData[i], 2);
			}
		}

#pragma endregion

		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}
