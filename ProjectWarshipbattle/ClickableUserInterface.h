#pragma once
#include"DefinedData.h"
#include"ButtonCollection.h"
#include"PictureLoader.h"
#include"DxLib.h"
#include"SoundLoader.h"
/*今回のゲームでは、すべての操作をマウスでできるようにしたいです。
メインメニューにも、ゲーム画面にも使えるクラスです。
目標としては同じ構造を利用して、
インターフェースを変更すれば違う中身を利用できるようにしたいです*/
/*音声ローダー、画像ローダーはすべて外部から取りますので、再宣言することを控えます*/
/*戻り値などはすべてDefinedData.hに定義します。*/
/*なお、直接触れない部分はUserInterfaceクラスに実現します。
このクラスでは、クリックできるパーツの描画と命令を返すの二つの機能を実現します。*/

class ClickableUserInterface
{
public:
	ClickableUserInterface();
	~ClickableUserInterface();

	void IngameInif(PictureLoader *PL, SoundLoader *SL);
	
	int CheckChoice();
	void Draw();
	void SetNormalStatus();

	void Free();

private:
	/*数の変更もできるようにしました*/
	void MemorySecure(int);
	void MemoryFree(int);
	void SetThisOne(int num, double x, double z, double mt);

	/*提示の点滅用カウント*/
	int countForTitle;

	ButtonCollection BC;

	/*0:ｘ座標
	  1:ｚ座標
	  2:ｘサイズ
	  3:ｚサイズ
	  4:拡大率
	  5:表示する:0,表示しない:1*/
	double **buttonPosition;
};