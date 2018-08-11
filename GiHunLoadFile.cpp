#include "stdafx.h"
#include "loadingScene.h"

void loadingScene::GiHunImage()
{

	// 스테이지 1 이미지
	_loading->loadImage("스테이지1", "resource/스테이지1/스테이지1 합본.bmp", 10000, 2500, true, MAGENTA);
	_loading->loadImage("스테이지 1 겨울", "resource/스테이지1/스테이지 1 겨울.bmp", 10000, 2500, true, MAGENTA);

	_loading->loadImage("스테이지 1-1", "resource/스테이지1/스테이지 1-1.bmp", 2500, 2500, true, MAGENTA);
	_loading->loadImage("스테이지 1-2", "resource/스테이지1/스테이지 1-2.bmp", 2500, 2500, true, MAGENTA);
	_loading->loadImage("스테이지 1-3", "resource/스테이지1/스테이지 1-3.bmp", 2500, 2500, true, MAGENTA);
	_loading->loadImage("스테이지 1-4", "resource/스테이지1/스테이지 1-4.bmp", 2500, 2500, true, MAGENTA);


	_loading->loadImage("레이어1", "resource/스테이지1/레이어1.bmp", 1280, 2340, true, MAGENTA);
	_loading->loadImage("레이어2", "resource/스테이지1/레이어2.bmp", 1280, 326, true, MAGENTA);
	_loading->loadImage("레이어1 겨울", "resource/스테이지1/레이어1 겨울.bmp", 1280, 2340, true, MAGENTA);
	_loading->loadImage("레이어2 겨울", "resource/스테이지1/레이어2 겨울.bmp", 1280, 326, true, MAGENTA);
	_loading->loadImage("스테이지1 픽셀", "resource/스테이지1/스테이지1 픽셀1.bmp", 10000, 2500, true, RGB(255, 0, 255));

	_loading->loadImage("스테이지 클리어", "resource/스테이지1/스테이지 클리어.bmp", 685, 82);
	// 기타 이미지
	_loading->loadImage("큰풀", "resource/스테이지1/큰풀.bmp", 100, 100, true, RGB(255, 0, 255));
	_loading->loadFrameImage("폭포", "resource/스테이지1/폭포1 프레임.bmp", 4608, 575, 16, 1);
	_loading->loadFrameImage("폭포2", "resource/스테이지1/폭포.bmp", 1024, 128, 16, 1);
	_loading->loadFrameImage("폭포물", "resource/스테이지1/폭포물.bmp", 4320, 48, 15, 1);
	_loading->loadFrameImage("폭포윗물", "resource/스테이지1/폭포윗물.bmp", 1024, 22, 15, 1);
	_loading->loadFrameImage("물레방아", "resource/스테이지1/물레방아.bmp", 2080, 256, 8, 1,true, MAGENTA);
	_loading->loadFrameImage("물가", "resource/스테이지1/물 찰랑.bmp", 11520, 120, 8, 1);
	_loading->loadFrameImage("물가2", "resource/스테이지1/물찰랑.bmp", 1024, 78, 8, 1);
	_loading->loadFrameImage("빛","resource/스테이지1/빛.bmp",1008,48,7,1);


	_loading->loadFrameImage("새노래", "resource/스테이지1/새노래.bmp", 1320,135, 8, 1, true, MAGENTA);
	_loading->loadFrameImage("널뛰기2", "resource/스테이지1/널뛰기2.bmp", 588,102, 2, 1, true, MAGENTA);
	_loading->loadImage("널뛰기1", "resource/스테이지1/널뛰기1.bmp", 300, 100, true, MAGENTA);
	_loading->loadImage("새날다", "resource/스테이지1/새날다.bmp", 78, 126, true, MAGENTA);



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
	_loading->loadImage("하트", "resource/상점/하트.bmp", 120, 120);

	_loading->loadImage("번개 마법 정보", "resource/상점/1234.bmp", 400, 400, true, MAGENTA);
	_loading->loadImage("불 마법 정보", "resource/상점/불 마법 정보.bmp", 400, 400, true, MAGENTA);
	_loading->loadImage("얼음 마법 정보", "resource/상점/얼음 마법 정보.bmp", 400, 400, true, MAGENTA);

	_loading->loadImage("초록화살 설명", "resource/상점/초록화살 설명.bmp", 400, 400, true, MAGENTA);
	_loading->loadImage("마나 업그레이드 설명", "resource/상점/마나 업그레이드 설명.bmp", 400, 400, true, MAGENTA);
	_loading->loadImage("하트 설명", "resource/상점/하트 설명.bmp", 400, 400, true, MAGENTA);

	_loading->loadImage("업그레이드 불가", "resource/상점/업그레이드 불가.bmp", 400, 400, true, MAGENTA);
	_loading->loadImage("마법 구매 불가", "resource/상점/마법 구매 불가.bmp", 400, 400, true, MAGENTA);

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

	_loading->loadImage("불마법", "resource/UI/불마법.bmp", 96, 96, true, MAGENTA);
	_loading->loadImage("번개마법", "resource/UI/번개마법.bmp", 96, 96, true, MAGENTA);
	_loading->loadImage("얼음마법", "resource/UI/얼음마법.bmp", 96, 96, true, MAGENTA);

	_loading->loadImage("골드", "resource/UI/골드.bmp", 96, 96, true, MAGENTA);
	_loading->loadFrameImage("숫자", "resource/UI/숫자.bmp", 240, 24, 10, 1);

	_loading->loadFrameImage("벌집", "resource/스테이지1/벌집.bmp", 1680, 240, 7, 1);
	_loading->loadFrameImage("벌집꿀잠", "resource/스테이지1/벌집꿀잠.bmp", 1440, 240, 6, 1);
}


void loadingScene::GiHunSound()
{

}
