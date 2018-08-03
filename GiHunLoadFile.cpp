#include "stdafx.h"
#include "loadingScene.h"

void loadingScene::GiHunImage()
{

	// 스테이지 1 이미지
	_loading->loadImage("스테이지1", "resource/스테이지1/스테이지1.bmp", 20000, 2750, true, MAGENTA);
	//_loading->loadImage("스테이지1 얼음", "resource/스테이지1/스테이지1 얼음.bmp", 20000, 2750, true, MAGENTA);
	_loading->loadImage("스테이지1 픽셀", "resource/스테이지1/스테이지1 픽셀.bmp", 20000, 2750, true, RGB(255, 0, 255));
	//_loading->loadImage("스테이지1 얼음 픽셀", "resource/스테이지1/스테이지1 얼음 픽셀.bmp", 20000, 2750, true, RGB(255, 0, 255));
	// 기타 이미지
	_loading->loadImage("큰풀", "resource/스테이지1/큰풀.bmp", 100, 100, true, RGB(255, 0, 255));
	_loading->loadFrameImage("폭포", "resource/스테이지1/폭포2 프레임.bmp", 4608, 1000, 16, 1);
	_loading->loadFrameImage("폭포물", "resource/스테이지1/폭포물.bmp", 4320, 48, 15, 1);
	_loading->loadFrameImage("물레방아", "resource/스테이지1/물레방아.bmp", 3480, 435, 8, 1);
	_loading->loadFrameImage("물가", "resource/스테이지1/물 찰랑.bmp", 11520, 120, 8, 1);

	// 상점
	_loading->loadImage("기모띠", "resource/상점/기모띠.bmp", 800, 483);

	_loading->loadImage("마나업그레이드1", "resource/상점/마나업그레이드1.bmp", 120, 120);
	_loading->loadImage("마나업그레이드2", "resource/상점/마나업그레이드2.bmp", 120, 120);
	_loading->loadImage("마나업그레이드3", "resource/상점/마나업그레이드3.bmp", 120, 120);

	_loading->loadImage("불 마법", "resource/상점/불 마법.bmp", 120, 120);
	_loading->loadImage("얼음 마법", "resource/상점/얼음 마법.bmp", 120, 120);
	_loading->loadImage("번개 마법", "resource/상점/번개 마법.bmp", 120, 120);

	_loading->loadImage("아이템 선택", "resource/상점/아이템 선택.bmp", 120, 120, true, RGB(255, 0, 255));
	_loading->loadFrameImage("선택함", "resource/상점/선택함.bmp", 240, 120, 2, 1);
	_loading->loadImage("마법상점", "resource/상점/마법상점.bmp", 318, 64, true, RGB(255, 0, 255));
	_loading->loadImage("업그레이드상점", "resource/상점/업그레이드상점.bmp", 318, 64, true, RGB(255, 0, 255));
	_loading->loadImage("총알 추가", "resource/상점/총알 업그레이드.bmp", 120, 120);
	_loading->loadFrameImage("HP증가", "resource/상점/HP증가.bmp", 1200, 120, 10, 1);

	_loading->loadImage("번개 마법 정보", "resource/상점/1234.bmp", 400, 400, true, MAGENTA);
	_loading->loadImage("불 마법 정보", "resource/상점/불 마법 정보.bmp", 400, 400, true, MAGENTA);
	_loading->loadImage("얼음 마법 정보", "resource/상점/얼음 마법 정보.bmp", 400, 400, true, MAGENTA);


	// UI
	_loading->loadImage("fullHP", "resource/UI/fullHP.bmp", 48, 48, true, MAGENTA);
	_loading->loadImage("halfHP", "resource/UI/halfHP.bmp", 48, 48, true, MAGENTA);
	_loading->loadImage("zeroHP", "resource/UI/zeroHP.bmp", 48, 48, true, MAGENTA);
	_loading->loadImage("마나 바", "resource/UI/마나 바.bmp", 384, 96, true, MAGENTA);
	_loading->loadImage("마나", "resource/UI/마나.bmp", 216, 24, true, MAGENTA);
	_loading->loadImage("마나 업글바", "resource/UI/마나 업그레이드바.bmp", 126, 24, true, MAGENTA);
	_loading->loadImage("마나 경고", "resource/UI/헿.bmp", 216, 24, true, MAGENTA);

	_loading->loadImage("현재상태", "resource/UI/현재상태.bmp", 120, 120, true, MAGENTA);
	_loading->loadImage("일반화살", "resource/UI/일반화살.bmp", 96, 96, true, MAGENTA);
	_loading->loadImage("초록화살", "resource/UI/초록화살.bmp", 96, 96, true, MAGENTA);
	_loading->loadImage("선택L", "resource/UI/선택L.bmp", 30, 24, true, MAGENTA);
	_loading->loadImage("선택R", "resource/UI/선택R.bmp", 30, 24, true, MAGENTA);
	_loading->loadImage("노선택L", "resource/UI/노선택L.bmp", 30, 24, true, MAGENTA);
	_loading->loadImage("노선택R", "resource/UI/노선택R.bmp", 30, 24, true, MAGENTA);
	_loading->loadImage("경고선", "resource/UI/경고선.bmp", 27, 66, true, MAGENTA);

	_loading->loadImage("골드", "resource/UI/골드.bmp", 96, 96, true, MAGENTA);
	_loading->loadFrameImage("숫자", "resource/UI/숫자.bmp", 240, 24, 10, 1);


}


void loadingScene::GiHunSound()
{

}
