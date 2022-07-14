#include "Global.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み


	// ゲームループで使う変数の宣言
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

	// 最新のキーボード情報用
	char keys[256] = { 0 };

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = { 0 };

	// ゲームループ
	while (true) {
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		//---- 更新 ----//

#pragma region 線形探索(リニアサーチ)

		while (dateCount < 11) {
			if (searchValue == linearData[dateCount]) {
				break;
			}
			dateCount++;
		}

#pragma endregion

#pragma region 二分探索(バイナリサーチ)
		while (true) {
			// データの中間値を求める
			midListNum = (minListNum + maxListNum) / 2;
			// 前提条件
			if (maxListNum < minListNum) {
				break;
			}
			// 探索値よりデータ値が小さい場合、中間値を1増加させる
			if (binaryData[midListNum] < searchValue) {
				minListNum = midListNum + 1;
			}
			// 探索値よりデータ値が大きい場合、中間値を1減少させる
			else if (searchValue < binaryData[midListNum]) {
				maxListNum = midListNum - 1;
			}
			// 探索値とデータ値が同じ場合ループを出る
			else if (searchValue == binaryData[midListNum]) {
				break;
			}
		}
#pragma endregion

#pragma region ハッシュ探索(ハッシュ法)

		quotient = searchValue / 100;
		remainder = searchValue % 100;

		quotient += remainder / 10;
		remainder = remainder % 10;

		quotient += remainder;
		quotient = quotient % 10;

#pragma endregion

		//---- 描画 ----//

#pragma region 線形探索(リニアサーチ)

//		if (dateCount <= 10) {
//			DrawFormatString(5, 5, GetColor(255, 255, 255), "searchValue[ %d ]はData内に存在します\n", searchValue, 2);
//		}
//		else if (dateCount > 10) {
//			DrawFormatString(5, 5, GetColor(255, 255, 255), "searchValue[ %d ]はData内に存在しません\n", searchValue, 2);
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

#pragma region 二分探索(バイナリサーチ)

//		if (binaryData[midListNum] == searchValue) {
//			DrawFormatString(5, 5, GetColor(255, 255, 255), "searchValue[ %d ]はData内に存在します\n", searchValue, 2);
//		}
//		else
//		{
//			DrawFormatString(5, 5, GetColor(255, 255, 255), "searchValue[ %d ]はData内に存在しません\n", searchValue, 2);
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

#pragma region ハッシュ探索(ハッシュ法)

		if (hashData[quotient] == searchValue) {
			DrawFormatString(5, 5, GetColor(255, 255, 255), "searchValue[ %d ]はData内に存在します\n", searchValue, 2);
		}
		else
		{
			DrawFormatString(5, 5, GetColor(255, 255, 255), "searchValue[ %d ]はData内に存在しません\n", searchValue, 2);
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

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}
