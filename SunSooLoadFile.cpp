#include "stdafx.h"
#include "loadingScene.h"


void loadingScene::SunSooImage()
{
	//몹
	//잠자리
	_loading->loadFrameImage("잠자리spawn", "resource/이선수/몬스터/잠자리spawn.bmp", 1536, 384, 8, 2);
	_loading->loadFrameImage("잠자리move", "resource/이선수/몬스터/잠자리move.bmp", 768, 192, 8, 2);
	_loading->loadFrameImage("잠자리dead", "resource/이선수/몬스터/잠자리dead.bmp", 2220, 384, 10, 2);

	//나무인간
	_loading->loadFrameImage("나무인간spawn", "resource/이선수/몬스터/나무인간spawn2.bmp", 1680, 444, 14, 2);
	_loading->loadFrameImage("나무인간move", "resource/이선수/몬스터/나무인간move.bmp", 770, 300, 7, 2);
	_loading->loadFrameImage("나무인간attack", "resource/이선수/몬스터/나무인간attack.bmp", 2448, 384, 8, 2);
	_loading->loadFrameImage("나무인간dead", "resource/이선수/몬스터/나무인간dead.bmp", 1752, 348, 8, 2);

	//버그
	_loading->loadFrameImage("버그move", "resource/이선수/몬스터/버그move.bmp", 540, 80, 6, 2);
	_loading->loadFrameImage("버그dead", "resource/이선수/몬스터/버그dead.bmp", 2220, 348, 10, 2);

	//통나무
	_loading->loadFrameImage("통나무move", "resource/이선수/몬스터/통나무move.bmp", 1280, 516, 8, 2);
	_loading->loadFrameImage("통나무dead", "resource/이선수/몬스터/통나무dead.bmp", 1896, 510, 8, 2);

	//두꺼비
	_loading->loadFrameImage("두꺼비spawn", "resource/이선수/몬스터/두꺼비spawn.bmp", 480, 288, 6, 2);
	_loading->loadFrameImage("두꺼비move", "resource/이선수/몬스터/두꺼비move.bmp", 1176, 288, 7, 2);
	_loading->loadFrameImage("두꺼비attack", "resource/이선수/몬스터/두꺼비attack.bmp", 792, 288, 9, 2);
	_loading->loadFrameImage("두꺼비dead", "resource/이선수/몬스터/두꺼비dead.bmp", 2442, 348, 11, 2);
	_loading->loadFrameImage("두꺼비tongue", "resource/이선수/몬스터/두꺼비tongue.bmp", 200, 18, 1, 2);

	//꼼장어
	_loading->loadFrameImage("꼼장어spawn", "resource/이선수/몬스터/꼼장어spawn.bmp", 810, 60, 6, 1);
	_loading->loadFrameImage("꼼장어move", "resource/이선수/몬스터/꼼장어move2.bmp", 4290, 186, 26, 1);
	_loading->loadFrameImage("꼼장어dead", "resource/이선수/몬스터/꼼장어dead.bmp", 2220, 348, 10, 2);

	//상자유령
	_loading->loadFrameImage("유령spawn", "resource/이선수/몬스터/상자유령/상자유령spawn.bmp", 800,267, 6, 2);
	_loading->loadFrameImage("유령attack", "resource/이선수/몬스터/상자유령/상자유령attack.bmp", 800, 267, 6, 2);
	_loading->loadFrameImage("유령dead", "resource/이선수/몬스터/상자유령/상자유령dead.bmp", 800, 267, 6, 2);
	_loading->loadFrameImage("유령총알", "resource/이선수/몬스터/상자유령/상자유령bullet.bmp", 200, 50, 4, 1);

	//보스벌
	_loading->loadFrameImage("벌attack", "resource/이선수/몬스터/보스벌/벌attact.bmp", 1000, 982, 2, 2);
	_loading->loadFrameImage("벌dizzy", "resource/이선수/몬스터/보스벌/벌dizzy.bmp", 3000, 1141, 6, 2);
	_loading->loadFrameImage("벌hurt", "resource/이선수/몬스터/보스벌/벌hurt.bmp", 3600, 1800, 4, 2);
	_loading->loadFrameImage("벌idle", "resource/이선수/몬스터/보스벌/벌idle.bmp", 3000, 1141, 6, 2);




	//아이템
	_loading->loadFrameImage("헬스라지", "resource/이선수/아이템/하트L2.bmp", 665, 30, 19, 1);
	_loading->loadFrameImage("헬스빅", "resource/이선수/아이템/하트B.bmp", 300, 14, 20, 1);
	_loading->loadFrameImage("마나빅", "resource/이선수/아이템/마나B.bmp", 660, 60, 11, 1);
	_loading->loadFrameImage("마나스몰", "resource/이선수/아이템/마나S.bmp", 660, 60, 11, 1);
	//코인
	_loading->loadFrameImage("금화", "resource/이선수/아이템/금화2.bmp", 256, 32, 8, 1);
	_loading->loadFrameImage("은화", "resource/이선수/아이템/은화2.bmp", 256, 32, 8, 1);
	_loading->loadFrameImage("동화", "resource/이선수/아이템/동화2.bmp", 256, 32, 8, 1);

	//상자
	_loading->loadFrameImage("상자", "resource/이선수/아이템/아이템상자.bmp", 200, 100, 2, 1);

}

void loadingScene::SunSooSound()
{

}