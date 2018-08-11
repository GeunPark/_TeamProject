#include "stdafx.h"
#include "loadingScene.h"


void loadingScene::SunSooImage()
{
	//몹
	//잠자리
	_loading->loadFrameImage("잠자리spawn", "resource/이선수/몬스터/잠자리spawn.bmp", 1536, 384, 8, 2);
	_loading->loadFrameImage("잠자리move", "resource/이선수/몬스터/잠자리move.bmp", 768, 192, 8, 2);

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
	_loading->loadFrameImage("두꺼비tongue", "resource/이선수/몬스터/두꺼비tongue.bmp", 200, 18, 1, 2);

	//꼼장어
	_loading->loadFrameImage("꼼장어spawn", "resource/이선수/몬스터/꼼장어spawn.bmp", 810, 60, 6, 1);
	_loading->loadFrameImage("꼼장어move", "resource/이선수/몬스터/꼼장어move2.bmp", 4290, 186, 26, 1);

	//상자유령
	_loading->loadFrameImage("유령spawn", "resource/이선수/몬스터/상자유령/상자유령spawn.bmp", 800,267, 6, 2);
	_loading->loadFrameImage("유령attack", "resource/이선수/몬스터/상자유령/상자유령attack.bmp", 800, 267, 6, 2);
	_loading->loadFrameImage("유령dead", "resource/이선수/몬스터/상자유령/상자유령dead.bmp", 800, 267, 6, 2);
	_loading->loadFrameImage("유령총알", "resource/이선수/몬스터/상자유령/상자유령bullet.bmp", 200, 50, 4, 1);

	//보스벌
	_loading->loadFrameImage("벌attack", "resource/이선수/몬스터/보스벌/벌attact.bmp", 1000, 982, 2, 2);
	_loading->loadFrameImage("벌dizzy", "resource/이선수/몬스터/보스벌/벌dizzy.bmp", 3000, 1141, 6, 2);
	_loading->loadFrameImage("벌hurt", "resource/이선수/몬스터/보스벌/벌hurt.bmp", 4500, 1800, 5, 2);
	_loading->loadFrameImage("벌idle", "resource/이선수/몬스터/보스벌/벌idle.bmp", 3000, 1141, 6, 2);
	_loading->loadImage("디지카운트", "resource/이선수/몬스터/보스벌/디지카운트.bmp", 100, 100, true, MAGENTA);
	//보스벌 총알
	_loading->loadFrameImage("벌bullet", "resource/이선수/몬스터/보스벌/벌bullet.bmp", 150, 50, 3, 1);



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


	//이펙트
	//몬스터
	//Left
	_loading->loadFrameImage("잠자리deadL", "resource/이선수/몬스터/이펙트/잠자리deadL.bmp", 2220, 174, 10, 1);
	_loading->loadFrameImage("나무인간deadL", "resource/이선수/몬스터/이펙트/나무인간deadL.bmp", 1752, 174, 8, 1);
	_loading->loadFrameImage("버그deadL", "resource/이선수/몬스터/이펙트/버그deadL.bmp", 2220, 174, 10, 1);
	_loading->loadFrameImage("통나무deadL", "resource/이선수/몬스터/이펙트/통나무deadL.bmp", 1896, 255, 8, 1);
	_loading->loadFrameImage("두꺼비deadL", "resource/이선수/몬스터/이펙트/두꺼비deadL.bmp", 2442, 174, 11, 1);
	_loading->loadFrameImage("꼼장어deadL", "resource/이선수/몬스터/이펙트/꼼장어deadL.bmp", 2220, 174, 10, 1);
	//Right
	_loading->loadFrameImage("잠자리deadR", "resource/이선수/몬스터/이펙트/잠자리deadR.bmp", 2220, 174, 10, 1);
	_loading->loadFrameImage("나무인간deadR", "resource/이선수/몬스터/이펙트/나무인간deadR.bmp", 1752, 174, 8, 1);
	_loading->loadFrameImage("버그deadR", "resource/이선수/몬스터/이펙트/버그deadR.bmp", 2220, 174, 10, 1);
	_loading->loadFrameImage("통나무deadR", "resource/이선수/몬스터/이펙트/통나무deadR.bmp", 1896, 255, 8, 1);
	_loading->loadFrameImage("두꺼비deadR", "resource/이선수/몬스터/이펙트/두꺼비deadR.bmp", 2442, 174, 11, 1);
	_loading->loadFrameImage("꼼장어deadR", "resource/이선수/몬스터/이펙트/꼼장어deadR.bmp", 2220, 174, 10, 1);
	
	//아이템
	_loading->loadFrameImage("아이템이펙트", "resource/이선수/아이템/이펙트/아이템이펙트.bmp", 360, 60, 6, 1, true, MAGENTA);

}

void loadingScene::SunSooSound()
{

}