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
	_index1 = 0;
	_count1 = 0;
	imagePosition();
	images();
	

	//에너미매니저
	_eMG = new enemyManager;

	_eMG->init();

	//아이템매니저
	_iMG = new itemManager;
	_iMG->init();


	//플레이어 동적할당
	_player = new foxPlayer;
	_player->init();


	_normalBack1._x = 0;
	_normalBack1._y = 0;
	_normalBack1._img = IMAGEMANAGER->findImage("레이어1배경");

	_normalBack2._x = 0;
	_normalBack2._y = 0;
	_normalBack2._img = IMAGEMANAGER->findImage("레이어2배경");


	//상호참조
	_eMG->setPlayerLink(_player);
	_eMG->setItemMGLink(_iMG);


	return S_OK;
}
void stage1::release(void)
{
	SAFE_DELETE(_player);
	SAFE_DELETE(_eMG);
	SAFE_DELETE(_iMG);

}

void stage1::update(void)
{

	//imageMove();
	// 기훈아 두개라서 이거 주석처리했다 니가 나중에 알아서 정리해 -근화-########################################################################
	cameraMove();

	//To Do : 기훈아 내일 이거 건들지말아바 -근화- ##############################################################################################
	imageMove();

	//에너미매니저
	_eMG->update();

	//아이템매니저
	_iMG->update();

	//플레이어
	_player->update();
	if (KEYMANAGER->isToggleKey(VK_F2))
	{
		cameraMove();
	}
	_cam.rc = RectMakeCenter(_cam.x, _cam.y, WINSIZEX, WINSIZEY);
	//리셋(임시)
	if (KEYMANAGER->isOnceKeyDown('R'))
	{
		this->init();
	}
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		if (_state == ICE)_state = NORMAL;
		else if (_state == NORMAL)_state = ICE;
	}


	this->bgMove();

	//_cam.rc = RectMakeCenter(_cam.x, _cam.y, WINSIZEX, WINSIZEY);

}

void stage1::render(void)
{
	_normalBack1._img->loopRender(getMemDC(), &RectMake(0, 0 - _player->getPlayerCam().top, WINSIZEX, 2550), _normalBack1._x, _normalBack1._y);
	if (_state == NORMAL)
	{
		//  풀 이미지 출력
		for (int i = 0; i < _vBush.size(); ++i)
		{
			if (!_vBush[i].isActive) continue;
			_vBush[i]._img->render(getMemDC(), _vBush[i].rc.left - _player->getPlayerCam().left, _vBush[i].rc.top - _player->getPlayerCam().top);
		}

		// 폭포 이미지 출력
		for (int i = 0; i < 3; i++)
		{
			_waterfall[i]._img->frameRender(getMemDC(), _waterfall[i]._x - _player->getPlayerCam().left, _waterfall[i]._y - _player->getPlayerCam().top);
			_waterfalls[i]._img->frameRender(getMemDC(), _waterfalls[i]._x - _player->getPlayerCam().left, _waterfalls[i]._y - _player->getPlayerCam().top);
		}
		// 강 이미지 출력
		for (int i = 0; i < 8; i++)
		{
			_river[i]._img->frameRender(getMemDC(), _river[i]._x - _player->getPlayerCam().left, _river[i]._y - _player->getPlayerCam().top);
		}
		_waterfall[1]._img->frameRender(getMemDC(), _waterfall[1]._x - _player->getPlayerCam().left, _waterfall[1]._y - _player->getPlayerCam().top);
		_waterfalls[1]._img->frameRender(getMemDC(), _waterfalls[1]._x - _player->getPlayerCam().left, _waterfalls[1]._y - _player->getPlayerCam().top);
		_waterWheel->frameRender(getMemDC(), 14473 - _player->getPlayerCam().left, 2213 - _player->getPlayerCam().top);
		// 필드 이미지 출력
		feild->render(getMemDC(), 0, 0, _player->getPlayerCam().left, _player->getPlayerCam().top, WINSIZEX, WINSIZEY);
	}
	else if (_state == ICE)
	{
		feildIce->render(getMemDC(), 0, 0, _player->getPlayerCam().left, _player->getPlayerCam().top, WINSIZEX, WINSIZEY);
	}
	// 픽셀 이미지 출력
	if (KEYMANAGER->isToggleKey(VK_F4))
	{
		if (_state == NORMAL)feildpixel->render(getMemDC(), 0, 0, _player->getPlayerCam().left, _player->getPlayerCam().top, WINSIZEX, WINSIZEY);
		else if (_state == ICE)feildIcepixel->render(getMemDC(), 0, 0, _player->getPlayerCam().left, _player->getPlayerCam().top, WINSIZEX, WINSIZEY);
	}
	
	//에너미매니저
	_eMG->render(_player->getPlayerCam().left, _player->getPlayerCam().top);

	//아이템매니저
	_iMG->render(_player->getPlayerCam().left, _player->getPlayerCam().top);

	//플레이어
	//_player->render(_cam.rc.left, _cam.rc.top);
	
	_player->render();
	char str[128];
	sprintf_s(str, "%d    %d ",_ptMouse.x + _player->getPlayerCam().left, _ptMouse.y + _player->getPlayerCam().top);
	TextOut(getMemDC(), 120 , WINSIZEY /2 , str, strlen(str));
	
}

// 프레임 이미지 움직임

// 카메라 움직임
void stage1::cameraMove()
{
	if (KEYMANAGER->isStayKeyDown('W'))
	{
		_cam.x += 30;
		//_normalBack1._x += 1;
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		_cam.x -= 30;
		//_normalBack1._x -= 1;

	}
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		_cam.y -= 30;
	}
	if (KEYMANAGER->isStayKeyDown('D'))
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
void stage1::imageMove()
{
	for (int i = 0; i < 8; i++)
	{
		_river[i]._count++;
		if (_river[i]._count % 5 == 0)_river[i]._index++;
		if (_river[i]._index > 7)_river[i]._index = 0;

	}
	for (int i = 0; i < 3; i++)
	{
		_waterfall[i]._count++;
		if (_waterfall[i]._count % 5 == 0)_waterfall[i]._index++;
		if (_waterfall[i]._index > 15)_waterfall[i]._index = 0;
	}
	for (int i = 0; i < 8; i++)
	{
		_river[i]._img->setFrameX(_river[i]._index);
	}
	
	for (int i = 0; i < 3; i++)
	{
		_waterfall[i]._img->setFrameX(_waterfall[i]._index);
		_waterfalls[i]._img->setFrameX(_waterfall[i]._index);
	}
	// 물레방아 이미지
	_waterWheel->setFrameX(_river[0]._index);

}
void stage1::imagePosition()
{
	// 풀

	_bush[0].x = 1470;
	_bush[0].y = 2600;
	_bush[1].x = 1390;
	_bush[1].y = 2600;
	_bush[2].x = 3450;
	_bush[2].y = 2185;
	_bush[3].x = 3530;
	_bush[3].y = 2185;
	_bush[4].x = 9470;
	_bush[4].y = 2500;

	_bush[5].x = 13615;
	_bush[5].y = 1310;
	_bush[6].x = 18220;
	_bush[6].y = 2600;
	_bush[7].x = 18300;
	_bush[7].y = 2600;
	_bush[8].x = 12260;
	_bush[8].y = 2600;
	_bush[9].x = 12340;
	_bush[9].y = 2600;

	// 물가 x좌표
	_river[0]._x = 2467;
	_river[1]._x = 5700;
	_river[2]._x = 11700;
	_river[3]._x = 14100;
	_river[4]._x = 16100;
	_river[5]._x = 17600;
	_river[6]._x = 9000;
	_river[7]._x = 10646;
	// 폭포 좌표
	_waterfall[0]._x = 8692;
	_waterfall[1]._x = 10288;
	_waterfall[2]._x = 14908;

	_waterfall[0]._y = 2196;
	_waterfall[1]._y = 1896;
	_waterfall[2]._y = 2070;

	_waterfalls[0]._x = 8692;
	_waterfalls[1]._x = 10288;
	_waterfalls[2]._x = 14908;

	_waterfalls[0]._y = 2148;
	_waterfalls[1]._y = 1848;
	_waterfalls[2]._y = 2022;

	for (int i = 0; i < 8; i++)
	{
		_river[i]._y = 2630;
	}


}

void stage1::images()
{
	feild = IMAGEMANAGER->findImage("스테이지1");
	feildIce = IMAGEMANAGER->findImage("스테이지1 얼음");
	feildpixel = IMAGEMANAGER->findImage("스테이지1 픽셀");
	feildIcepixel = IMAGEMANAGER->findImage("스테이지1 얼음 픽셀");
	_waterWheel = IMAGEMANAGER->findImage("물레방아");
	for (int i = 0; i < 10; i++)
	{
		tagBoxs _bushs;
		_bushs._img = new image;
		_bushs._img = IMAGEMANAGER->findImage("큰풀");
		_bushs.rc = RectMakeCenter(_bush[i].x, _bush[i].y, 100, 100);
		_vBush.push_back(_bushs);
	}

	for (int i = 0; i < 8; i++)
	{
		_river[i]._img = IMAGEMANAGER->findImage("물가");
		_river[i]._count = 0;
		_river[i]._index = 0;
	}
	for (int i = 0; i < 3; i++)
	{
		_waterfall[i]._img = IMAGEMANAGER->findImage("폭포");
		_waterfalls[i]._img = IMAGEMANAGER->findImage("폭포물");
		_waterfall[i]._count = _waterfalls[i]._count = 0;
		_waterfall[i]._index = _waterfalls[i]._index = 0;
	}
	
}

void stage1::bgMove()
{
	if (_player->getLeft())
	{
		_normalBack1._x -= 1;
	}
	if(_player->getRight())
	{
		_normalBack1._x += 1;
	}
}
