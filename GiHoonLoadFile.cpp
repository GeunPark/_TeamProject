#include "stdafx.h"
#include "loadingScene.h"



void loadingScene::GiHoonImage()
{

	// 스테이지 1 이미지

	_loading->loadImage("스테이지1", "resource/스테이지1/스테이지1.bmp", 20000, 2750, true, MAGENTA);
	_loading->loadImage("스테이지1 픽셀", "resource/스테이지1/스테이지1 픽셀.bmp", 20000, 2750, true, MAGENTA);
	//_loading->loadImage("스티이지")

	_loading->loadImage("스테이지1-1", "resource/스테이지1/스테이지1-1.bmp", 10000, 2750, true, MAGENTA);
	_loading->loadImage("스테이지1-1 픽셀", "resource/스테이지1/스테이지1-1 픽셀.bmp", 10000, 2750, true, MAGENTA);
	_loading->loadImage("스테이지1-2", "resource/스테이지1/스테이지1-2.bmp", 10000, 2750, true, MAGENTA);
	_loading->loadImage("스테이지1-2 픽셀", "resource/스테이지1/스테이지1-2 픽셀.bmp", 10000, 2750, true, MAGENTA);
	_loading->loadImage("스테이지1-1 얼음", "resource/스테이지1/스테이지1-1 얼음.bmp", 10000, 2750, true, MAGENTA);
	_loading->loadImage("스테이지1-2 얼음", "resource/스테이지1/스테이지1-2 얼음.bmp", 10000, 2750, true, MAGENTA);
	_loading->loadImage("스테이지1-1 얼음 픽셀", "resource/스테이지1/스테이지1-1 얼음 픽셀.bmp", 10000, 2750, true, MAGENTA);
	_loading->loadImage("스테이지1-11", "resource/스테이지1/스테이지1.bmp", 20000, 2750, true, MAGENTA);

	// 기타 이미지
	_loading->loadImage("큰풀", "resource/스테이지1/큰풀.bmp", 100, 100, true, MAGENTA);
	_loading->loadFrameImage("폭포1", "resource/스테이지1/폭포1 프레임.bmp", 4608, 575, 16, 1);//4608,575
	_loading->loadFrameImage("폭포2", "resource/스테이지1/폭포2 프레임.bmp", 4608, 1150, 16, 1);//4608,575
	_loading->loadFrameImage("폭포3", "resource/스테이지1/폭포2 프레임.bmp", 4608, 1150, 16, 1);//4608,575

	_loading->loadFrameImage("폭포물1", "resource/스테이지1/폭포물.bmp", 4320, 48, 15, 1);
	_loading->loadFrameImage("폭포물2", "resource/스테이지1/폭포물.bmp", 4320, 48, 15, 1);
	_loading->loadFrameImage("폭포물3", "resource/스테이지1/폭포물.bmp", 4320, 48, 15, 1);

	_loading->loadFrameImage("물레방아", "resource/스테이지1/물레방아.bmp", 3480, 435, 8, 1);
	_loading->loadFrameImage("물 찰랑1", "resource/스테이지1/물 찰랑.bmp", 11520, 120, 8, 1);
	_loading->loadFrameImage("물 찰랑2", "resource/스테이지1/물 찰랑.bmp", 11520, 120, 8, 1);
	_loading->loadFrameImage("물 찰랑3", "resource/스테이지1/물 찰랑.bmp", 11520, 120, 8, 1);
	_loading->loadFrameImage("물 찰랑4", "resource/스테이지1/물 찰랑.bmp", 11520, 120, 8, 1);
	_loading->loadFrameImage("물 찰랑5", "resource/스테이지1/물 찰랑.bmp", 11520, 120, 8, 1);
	_loading->loadFrameImage("물 찰랑6", "resource/스테이지1/물 찰랑.bmp", 11520, 120, 8, 1);


	// 상점 관련
	_loading->loadImage("기모띠", "resource/스테이지1/기모띠.bmp", 800, 483);

	_loading->loadImage("마나업그레이드1", "resource/스테이지1/마나업그레이드1.bmp",120, 120);
	_loading->loadImage("마나업그레이드2", "resource/스테이지1/마나업그레이드2.bmp", 120, 120);
	_loading->loadImage("마나업그레이드3", "resource/스테이지1/마나업그레이드3.bmp", 120, 120);

	_loading->loadImage("불 마법", "resource/스테이지1/불 마법.bmp", 120, 120);
	_loading->loadImage("얼음 마법", "resource/스테이지1/얼음 마법.bmp", 120, 120);
	_loading->loadImage("번개 마법", "resource/스테이지1/번개 마법.bmp", 120, 120);

	_loading->loadImage("아이템 선택", "resource/스테이지1/아이템 선택.bmp", 120, 120,true,RGB(255,0,255));
	_loading->loadFrameImage("선택함","resource/스테이지1/선택함.bmp", 240, 120, 2,1);
	_loading->loadImage("마법상점","resource/스테이지1/마법상점.bmp", 318, 64,true,RGB(255,0,255));
	_loading->loadImage("업그레이드상점", "resource/스테이지1/업그레이드상점.bmp", 318, 64, true, RGB(255, 0, 255));
	_loading->loadImage("총알 업그레이드","resource/스테이지1/총알 업그레이드.bmp",120,120);
	_loading->loadFrameImage("HP증가", "resource/스테이지1/HP증가.bmp", 1200, 120, 10, 1);

	_loading->loadImage("번개 마법 정보", "resource/스테이지1/1234.bmp", 400,400, true, MAGENTA);
	_loading->loadImage("불 마법 정보", "resource/스테이지1/불 마법 정보.bmp", 400, 400, true, MAGENTA);
	_loading->loadImage("얼음 마법 정보", "resource/스테이지1/얼음 마법 정보.bmp", 400, 400, true, MAGENTA);


}


void loadingScene::GiHoonSound()
{

}
