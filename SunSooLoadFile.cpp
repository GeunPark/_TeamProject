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
	//버그
	_loading->loadFrameImage("버그move", "resource/이선수/몬스터/버그move.bmp", 540, 80, 6, 2);
	//통나무
	_loading->loadFrameImage("통나무move", "resource/이선수/몬스터/통나무move.bmp", 1280, 516, 8, 2);
	//두꺼비
	_loading->loadFrameImage("두꺼비spawn", "resource/이선수/몬스터/두꺼비spawn.bmp", 480, 288, 6, 2);
	_loading->loadFrameImage("두꺼비move", "resource/이선수/몬스터/두꺼비move.bmp", 1176, 288, 7, 2);
	_loading->loadFrameImage("두꺼비attack", "resource/이선수/몬스터/두꺼비attack.bmp", 792, 288, 9, 2);
	//꼼장어
	//IMAGEMANAGER->addFrameImage("꼼장어spawn", "resource/꼼장어spawn.bmp", 810, 60, 6, 1);
	_loading->loadFrameImage("꼼장어move", "resource/이선수/몬스터/꼼장어move2.bmp", 4290, 186, 26, 1);



	//아이템
	_loading->loadFrameImage("헬스라지", "resource/이선수/아이템/하트L2.bmp", 665, 30, 19, 1);
	_loading->loadFrameImage("헬스빅", "resource/이선수/아이템/하트B.bmp", 300, 14, 20, 1);
	_loading->loadFrameImage("마나빅", "resource/이선수/아이템/마나B.bmp", 660, 60, 11, 1);
	_loading->loadFrameImage("마나스몰", "resource/이선수/아이템/마나S.bmp", 660, 60, 11, 1);
	//코인
	_loading->loadFrameImage("금화", "resource/이선수/아이템/금화2.bmp", 256, 32, 8, 1);
	_loading->loadFrameImage("은화", "resource/이선수/아이템/은화2.bmp", 256, 32, 8, 1);
	_loading->loadFrameImage("동화", "resource/이선수/아이템/동화2.bmp", 256, 32, 8, 1);



}

void loadingScene::SunSooSound()
{

}