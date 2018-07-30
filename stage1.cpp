#include "stdafx.h"
#include "stage1.h"

HRESULT stage1::init(void)
{
	// 상태
	_state = NORMAL;
	// 카메라 관련 초기화
	_cam.x = WINSIZEX / 2;
	_cam.y = 2750 - (WINSIZEY / 2);
	_cam.rc = RectMakeCenter(_cam.x, _cam.y, WINSIZEX, WINSIZEY);
	// 프레임 이미지 카운터, 인덱스 값 초기화
	_count = 0;
	_index = 0;

	imagePosition();
	images();

	// 물가 x좌표
	
	
	// 스테이지1 필드 이미지
	feild = IMAGEMANAGER->findImage("스테이지1");
	// 스테이지1 필드 픽셀 이미지
	feildpixel = IMAGEMANAGER->findImage("스테이지1 픽셀");
	for (int i = 0; i < 6; i++)
	{
		_river[0]._x = 2467;
		_river[1]._x = 5700;
		_river[2]._x = 11700;
		_river[3]._x = 14100;
		_river[4]._x = 16100;
		_river[5]._x = 17600;
		_river[i]._y = 2630;
		_river[i]._img = IMAGEMANAGER->findImage("물가");
	}


	//에너미매니저
	_eMG = new enemyManager;

	_eMG->init();





	_normalBack1._x = 0;
	_normalBack1._y = 0;
	_normalBack1._img = IMAGEMANAGER->findImage("레이어1배경");

	_normalBack2._x = 0;
	_normalBack2._y = 0;
	_normalBack2._img = IMAGEMANAGER->findImage("레이어2배경");


	return S_OK;
}
void stage1::release(void)
{

}

void stage1::update(void)
{

	imageMove();

	if(KEYMANAGER->isToggleKey(VK_F2))cameraMove();

	//cameraMove();
	imageMove();

	//에너미매니저
	_eMG->update();

	if (KEYMANAGER->isToggleKey(VK_F2))
	{
		cameraMove();
	}

	_cam.rc = RectMakeCenter(_cam.x, _cam.y, WINSIZEX, WINSIZEY);
}

void stage1::render(void)
{
	_normalBack1._img->loopRender(getMemDC(), &RectMake(0, 0 - _cam.rc.top, WINSIZEX, 2550), _normalBack1._x, _normalBack1._y);

	//IMAGEMANAGER->findImage("스테이지1")->render(getMemDC(), 0, 0, _cam.rc.left, _cam.rc.top, WINSIZEX, WINSIZEY);
	for (int i = 0; i < 6; i++)
	{

		_river[i]._img->frameRender(getMemDC(), _river[i]._x - _cam.rc.left, _river[i]._y - _cam.rc.top);

		_river[i]._img->frameRender(getMemDC(), _riverX[i] - _cam.rc.left, _riverY[i] - _cam.rc.top);

	}
	feildpixel->render(getMemDC(), 0, 0, _cam.rc.left, _cam.rc.top, WINSIZEX, WINSIZEY);
	feild->render(getMemDC(), 0, 0, _cam.rc.left, _cam.rc.top, WINSIZEX, WINSIZEY);



	//TextOut(getMemDC(), 100, WINSIZEY, )

	//에너미매니저
	_eMG->render(_cam.rc.left, _cam.rc.top);


	char str[128];
	sprintf_s(str, "%d    %d ",_ptMouse.x + _cam.rc.left, _ptMouse.y + _cam.rc.top);
	TextOut(getMemDC(), 120 , WINSIZEY /2 , str, strlen(str));

}

// 프레임 이미지 움직임
void stage1::imageMove()
{
	_count++;
	if (_count % 5 == 0)_index++;
	if (_index > 7)_index = 0;

	for (int i = 0; i < 6; i++)
	{
		_river[i]._img->setFrameX(_index);
	}
}

// 카메라 움직임
void stage1::cameraMove()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_cam.x += 30;
		_normalBack1._x += 1;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_cam.x -= 30;
		_normalBack1._x -= 1;

	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_cam.y -= 30;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_cam.y += 30;
	}
	if (_cam.x - WINSIZEX / 2 <= 0)
	{
		_cam.x = WINSIZEX / 2;
	}
	if (_cam.x + WINSIZEX / 2 >= 20000)
	{
		_cam.x = 20000 - WINSIZEX / 2;
	}
	if (_cam.y - WINSIZEY / 2 <= 0)
	{
		_cam.y = WINSIZEY / 2;
	}
	if (_cam.y + WINSIZEY / 2 >= 2750)
	{
		_cam.y = 2750 - WINSIZEY / 2;
	}

}

void stage1::imagePosition()
{
	// 물가 x좌표
	_river[0]._x = 2467;
	_river[1]._x = 5700;
	_river[2]._x = 11700;
	_river[3]._x = 14100;
	_river[4]._x = 16100;
	_river[5]._x = 17600;
	// 폭포 좌표

	for (int i = 0; i < 6; i++)
	{
		_river[i]._y = 2630;
	}
}

void stage1::images()
{
	feild = IMAGEMANAGER->findImage("스테이지1");
	feildpixel = IMAGEMANAGER->findImage("스테이지1 픽셀");
	for (int i = 0; i < 6; i++)
	{
		_river[i]._img = IMAGEMANAGER->findImage("물가");
	}
}
