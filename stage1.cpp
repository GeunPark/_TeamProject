#include "stdafx.h"
#include "stage1.h"

HRESULT stage1::init(void)
{
	// 상태
	_state = SUMMER;
	// 카메라 관련 초기화
	_cam.x = WINSIZEX / 2;
	_cam.y = 2750 - (WINSIZEY / 2);
	_cam.rc = RectMakeCenter(_cam.x, _cam.y, WINSIZEX, WINSIZEY);
	_index1 = 0;
	_count1 = 0;
	bgCount = 0;
	_bagrandslide = 0;
	imagePosition();
	images();
	eftInit();

	_player = SAVEDATA->getPlayer();

	
	_player->setX(300);
	_player->setY(2300);
	_player->setBgPixel(feildpixel);

	_ui = SAVEDATA->getUI();

	_iMG = SAVEDATA->getItemManager();
	_iMG->init();


	_eMG = SAVEDATA->getEnemyManager();
	if (isFrist == false)
		_eMG->init();
	_eMG->init();

	_shop = SAVEDATA->getShop();
	_shop->setPlayerManager(_player);

	_player->setEnemyManager(_eMG);
	_ui->setPlayerManager(_player);
	_iMG->setEMGLink(_eMG);
	_iMG->setPlayerLink(_player);
	_eMG->setItemManager(_iMG);
	_eMG->setPlayerManager(_player);

	


	_normalBack1._x = 0;
	_normalBack1._y = 0;
	_normalBack1._img = IMAGEMANAGER->findImage("레이어1");

	_normalBack2._x = 0;
	_normalBack2._y = 0;
	_normalBack2._img = IMAGEMANAGER->findImage("레이어2");

	_winterBack1._img = IMAGEMANAGER->findImage("레이어1 겨울");
	_winterBack1._x = 0;
	_winterBack1._y = 0;

	_winterBack2._img = IMAGEMANAGER->findImage("레이어2 겨울");
	_winterBack2._x = 0;
	_winterBack2._y = 0;

	_effMG = effectManager::getSingleton();
	_effMG->setPlayerLink(_player);

	stageClearInit();

	//사운드 
	SOUNDMANAGER->play("스테이지1 여름");

	return S_OK;
}
void stage1::release(void)
{
	SAFE_DELETE(_player);
	//_eMG->release();
	SAFE_DELETE(_eMG);
	SAFE_DELETE(_iMG);
	SAFE_DELETE(_effect);

}

void stage1::update(void)
{
	if (_player->getAng() == false)_state = SUMMER;
	else if (_player->getAng() == true)_state = WINTER;

	cameraMove();
	this->stageClear();

	imageMove();

	this->beecollision();
	//플레이어
	_player->update();
	//에너미매니저
	_eMG->update();

	//_ui->update();
	//아이템매니저
	_iMG->update();
	_ui->update();
	//_shop->update();

	if (KEYMANAGER->isToggleKey(VK_F2))
	{
		cameraMove();
	}
	_cam.rc = RectMakeCenter(_cam.x, _cam.y, WINSIZEX, WINSIZEY);
	//리셋(임시)
	if (KEYMANAGER->isOnceKeyDown('R'))
	{
		isFrist = true;
		this->init();
	}
	if (_state == WINTER && _bagrandslide != WINSIZEX)
	{
		_bagrandslide += 32;
	}
	if (_state == SUMMER)
	{

		_bagrandslide = 0;
	}

	if (_player->getEftChk() == true)
	{

		for (int i = 0; i < _vEffect.size(); i++)
		{
			_vEffect[i]->startEffect(_eftX[i] - _player->getPlayerCam().left, _eftY[i] - _player->getPlayerCam().top);
		}
		_player->setEftChk(false);

	}
	this->bgMove();

	for (int i = 0; i < 2; i++)
	{
		_bee[i].rc = RectMake(_bee[i].x, _bee[i].y, 240, 240);
	}

	for (int i = 0; i<_vEffect.size(); i++)_vEffect[i]->update();

	if (_player->getX() < 0)
	{
		SCENEMANAGER->loadScene("타운씬");
		_eMG->release();
		_iMG->release();
		//isFrist = true;
	}
}

void stage1::render(void)
{
	_normalBack1._img->loopRender(getMemDC(), &RectMake(0, 0 - _player->getPlayerCam().top, WINSIZEX, 2550), _normalBack1._x, _normalBack1._y);
	_normalBack2._img->loopRender(getMemDC(), &RectMake(0, 2200 - _player->getPlayerCam().top, WINSIZEX, 2550), _normalBack2._x, _normalBack2._y);
	if (_state == SUMMER)
	{
		//  풀 이미지 출력
		for (int i = 0; i < _vBush.size(); ++i)
		{
			if (!_vBush[i].isActive) continue;
			_vBush[i]._img->render(getMemDC(), _vBush[i].rc.left - _player->getPlayerCam().left, _vBush[i].rc.top - _player->getPlayerCam().top);
		}
		for (int i = 0; i < 3; i++)
		{
			_waterfall[i]._img->frameRender(getMemDC(), _waterfall[i]._x - _player->getPlayerCam().left, _waterfall[i]._y - _player->getPlayerCam().top);
			_waterfalls[i]._img->frameRender(getMemDC(), _waterfalls[i]._x - _player->getPlayerCam().left, _waterfalls[i]._y - _player->getPlayerCam().top);
		}
		for (int i = 5; i < 8; i++)
		{
			_waterfall[i]._img->frameRender(getMemDC(), _waterfall[i]._x - _player->getPlayerCam().left, _waterfall[i]._y - _player->getPlayerCam().top);
			_waterfalls[i]._img->frameRender(getMemDC(), _waterfalls[i]._x - _player->getPlayerCam().left, _waterfalls[i]._y - _player->getPlayerCam().top);
		}
		for (int i = 8; i < 11; i++)
		{
			_waterfall[i]._img->frameRender(getMemDC(), _waterfall[i]._x - _player->getPlayerCam().left, _waterfall[i]._y - _player->getPlayerCam().top);
		}
		// 강 이미지 출력
		for (int i = 0; i < 4; i++)
		{
			_river[i]._img->frameRender(getMemDC(), _river[i]._x - _player->getPlayerCam().left, _river[i]._y - _player->getPlayerCam().top);
		}
		for (int i = 0; i < 7; i++)
		{
			_river[7 + i]._img->frameRender(getMemDC(), _river[7 + i]._x - _player->getPlayerCam().left, _river[7 + i]._y - _player->getPlayerCam().top);
		}
		feild->render(getMemDC(), 0, 0, _player->getPlayerCam().left, _player->getPlayerCam().top, WINSIZEX, WINSIZEY);
		for (int i = 3; i < 5; i++)
		{
			_waterfall[i]._img->frameRender(getMemDC(), _waterfall[i]._x - _player->getPlayerCam().left, _waterfall[i]._y - _player->getPlayerCam().top);
			_waterfalls[i]._img->frameRender(getMemDC(), _waterfalls[i]._x - _player->getPlayerCam().left, _waterfalls[i]._y - _player->getPlayerCam().top);
		}
		for (int i = 4; i < 7; i++)
		{
			_river[i]._img->frameRender(getMemDC(), _river[i]._x - _player->getPlayerCam().left, _river[i]._y - _player->getPlayerCam().top);
		}
		// 벌 이미지
		for (int i = 0; i < 2; i++)
		{
			_bee[i]._img->frameRender(getMemDC(), _bee[i].x - _player->getPlayerCam().left, _bee[i].y - _player->getPlayerCam().top);

		}
		_waterWheel->frameRender(getMemDC(), 8730 - _player->getPlayerCam().left, 2175 - _player->getPlayerCam().top);

	}

	if (_state == WINTER)
	{
		for (int i = 0; i < 3; i++)
		{
			_waterfall[i]._img->frameRender(getMemDC(), _waterfall[i]._x - _player->getPlayerCam().left, _waterfall[i]._y - _player->getPlayerCam().top);
			_waterfalls[i]._img->frameRender(getMemDC(), _waterfalls[i]._x - _player->getPlayerCam().left, _waterfalls[i]._y - _player->getPlayerCam().top);
		}
		for (int i = 5; i < 8; i++)
		{
			_waterfall[i]._img->frameRender(getMemDC(), _waterfall[i]._x - _player->getPlayerCam().left, _waterfall[i]._y - _player->getPlayerCam().top);
			_waterfalls[i]._img->frameRender(getMemDC(), _waterfalls[i]._x - _player->getPlayerCam().left, _waterfalls[i]._y - _player->getPlayerCam().top);
		}
		for (int i = 8; i < 11; i++)
		{
			_waterfall[i]._img->frameRender(getMemDC(), _waterfall[i]._x - _player->getPlayerCam().left, _waterfall[i]._y - _player->getPlayerCam().top);
		}
		// 강 이미지 출력
		for (int i = 0; i < 4; i++)
		{
			_river[i]._img->frameRender(getMemDC(), _river[i]._x - _player->getPlayerCam().left, _river[i]._y - _player->getPlayerCam().top);
		}
		for (int i = 0; i < 7; i++)
		{
			_river[7 + i]._img->frameRender(getMemDC(), _river[7 + i]._x - _player->getPlayerCam().left, _river[7 + i]._y - _player->getPlayerCam().top);
		}
		for (int i = 0; i < 2; i++)
		{
			_bee[i]._img->frameRender(getMemDC(), _bee[i].x - _player->getPlayerCam().left, _bee[i].y - _player->getPlayerCam().top);

		}
		_waterWheel->frameRender(getMemDC(), 8730 - _player->getPlayerCam().left, 2175 - _player->getPlayerCam().top);

		//////////////////////////////////////////////겨          울               맵/////////////////////////////////////////////////////////////////////
		_winterBack1._img->loopRender(getMemDC(), &RectMake(0, 0 - _player->getPlayerCam().top, 0 + _bagrandslide, 2550), _winterBack1._x, _winterBack1._y);
		_winterBack2._img->loopRender(getMemDC(), &RectMake(0, 2200 - _player->getPlayerCam().top, 0 + _bagrandslide, 2550), _winterBack2._x, _winterBack2._y);
		feild->render(getMemDC(), 0 + _bagrandslide, 0, _player->getPlayerCam().left + _bagrandslide, _player->getPlayerCam().top, WINSIZEX - _bagrandslide, WINSIZEY);
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		for (int i = 3; i < 5; i++)
		{
			_waterfall[i]._img->frameRender(getMemDC(), _waterfall[i]._x - _player->getPlayerCam().left, _waterfall[i]._y - _player->getPlayerCam().top);
			_waterfalls[i]._img->frameRender(getMemDC(), _waterfalls[i]._x - _player->getPlayerCam().left, _waterfalls[i]._y - _player->getPlayerCam().top);
		}
		for (int i = 4; i < 7; i++)
		{
			_river[i]._img->frameRender(getMemDC(), _river[i]._x - _player->getPlayerCam().left, _river[i]._y - _player->getPlayerCam().top);
		}

		/////////////////////////////////////////////겨          울               맵/////////////////////////////////////////////////////////////
		feildIce->render(getMemDC(), 0, 0, _player->getPlayerCam().left, _player->getPlayerCam().top, 0 + _bagrandslide, WINSIZEY);
	}

	// 픽셀 이미지 출력

	for (int i = 0; i < _vEffect.size(); i++)
	{
		_vEffect[i]->render(0, 0);
	}

	if (_neolttwigiColls == false)
	{
		_neolttwigi[0]._img->render(getMemDC(), _neolttwigi[0].x - _player->getPlayerCam().left, _neolttwigi[0].y - _player->getPlayerCam().top);
		_brid[0]._img->frameRender(getMemDC(), _brid[0].x - _player->getPlayerCam().left, _brid[0].y - _player->getPlayerCam().top);
	}
	else if (_neolttwigiColls == true)
	{
		_neolttwigi[1]._img->frameRender(getMemDC(), _neolttwigi[1].x - _player->getPlayerCam().left, _neolttwigi[1].y - _player->getPlayerCam().top);
		_brid[1]._img->render(getMemDC(), _brid[1].x - _player->getPlayerCam().left, _brid[1].y - _player->getPlayerCam().top);
	}
	for (int i = 0; i < 2; i++)
	{
		Rectangle(getMemDC(), _neolttwigi[0].rc);
	}
	if (KEYMANAGER->isToggleKey(VK_F4))
	{
		feildpixel->render(getMemDC(), 0, 0, _player->getPlayerCam().left, _player->getPlayerCam().top, WINSIZEX, WINSIZEY);
		for (int i = 0; i < 2; i++)
		{
			Rectangle(getMemDC(), _bee[i].rc.left - _player->getPlayerCam().left, _bee[i].rc.top - _player->getPlayerCam().top, 240 + (_bee[i].rc.left - _player->getPlayerCam().left), 240 + (_bee[i].rc.top - _player->getPlayerCam().top));
		}
		Rectangle(getMemDC(), _neolttwigi[0].rc.left - _player->getPlayerCam().left, _neolttwigi[0].rc.top - _player->getPlayerCam().top, 50 + (_neolttwigi[0].rc.left - _player->getPlayerCam().left), 20 + (_neolttwigi[0].rc.top - _player->getPlayerCam().top));
	}

	//아이템매니저

	_ui->render();

	//플레이어
	_player->render();

	_iMG->render();

	_eMG->render();
	_ui->render();
	//for (int i = 0; i < _vEffect.size(); i++)
	//{
	//	_vEffect[i]->render(0,0);
	//	//_vEffect[i]->render();
	//}



	for (int i = 0; i < _vEffect.size(); i++)
	{
		_vEffect[i]->render(0, 0);
	}


	// 테스트용 상점 구현
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{

		if (!shopMode)shopMode = true;



		// 테스트용 상점 구현
		if (KEYMANAGER->isOnceKeyDown('Q'))
		{
			if (!shopMode)shopMode = true;

			else shopMode = false;
		}
		//if(shopMode)_shop->render();


		if (stageClearCount > 180)stageClearImg->render(getMemDC(), 297, 359);

		char str[128];
		sprintf_s(str, "%d    %d ", _player->getPlayerState(), stageClearCount);
		TextOut(getMemDC(), 120, WINSIZEY / 2, str, strlen(str));

	}
}

// 프레임 이미지 움직임

// 카메라 움직임
void stage1::cameraMove()
{

	if (_cam.x - WINSIZEX / 2 <= 0)
	{
		_cam.x = WINSIZEX / 2;
	}
	if (_cam.x + WINSIZEX / 2 >= 10000)
	{
		_cam.x = 20000 - WINSIZEX / 2;
	}
	if (_cam.y - WINSIZEY / 2 <= 0)
	{
		_cam.y = WINSIZEY / 2;
	}
	if (_cam.y + WINSIZEY / 2 >= 2500)
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
	for (int i = 0; i < 7; i++)
	{
		_waterfall[i]._count++;
		if (_waterfall[i]._count % 5 == 0)_waterfall[i]._index++;

		if (_waterfall[i]._index > 15)_waterfall[i]._index = 0;
	}
	for (int i = 0; i <14; i++)
	{
		_river[i]._img->setFrameX(_river[0]._index);
	}

	for (int i = 0; i < 5; i++)
	{
		_waterfall[i]._img->setFrameX(_waterfall[0]._index);
		_waterfalls[i]._img->setFrameX(_waterfall[0]._index);
	}
	for (int i = 0; i < 2; i++)
	{
		_bee[i]._count++;
		if (_bee[i]._count % 5 == 0)_bee[i]._index++;
		if (_bee[i]._index > 6)_bee[i]._index = 0;
		_bee[i]._img->setFrameX(_bee[i]._index);
	}
	if (_neolttwigiColls == false)
	{
		_brid[0]._count++;
		if (_brid[0]._count % 5 == 0)_brid[0]._index++;
		if (_brid[0]._index > 7)_brid[0]._index = 0;
		_brid[0]._img->setFrameX(_brid[0]._index);
	}
	if (_neolttwigiColls == true)
	{
		_neolttwigi[1]._count++;
		if (_neolttwigi[1]._count % 5 == 0)_neolttwigi[1]._index++;
		if (_neolttwigi[1]._index > 0)_neolttwigi[1]._index = 1;
		_neolttwigi[1]._img->setFrameX(_neolttwigi[1]._index);
	}

	// 물레방아 이미지
	_waterWheel->setFrameX(_river[0]._index);

}
void stage1::imagePosition()
{
	// 풀
	_bee[0].x = 3390;
	_bee[0].y = 2240;

	_bee[1].x = 6200;
	_bee[1].y = 2190;

	_iceBee[0].x = 3475;
	_iceBee[0].y = 2200;

	_iceBee[1].x = 6288;
	_iceBee[1].y = 2152;

	for (int i = 0; i < 2; i++)
	{
		_bee[i]._count = 0;
		_bee[i]._index = 0;

		_iceBee[i]._count = 0;
		_iceBee[i]._index = 0;
		_bee[i].rc = RectMake(_bee[i].x, _bee[i].y, 50, 50);
		_iceBee[i].rc = RectMake(_iceBee[i].x, _iceBee[i].y, 50, 50);
	}

	_bush[9].y = 2600;

	// 물가 x좌표
	_river[0]._x = 2260;
	_river[1]._x = 5700;
	_river[2]._x = 8220;
	_river[3]._x = 9000;

	_river[4]._x = 9272;
	_river[5]._x = 9400;
	_river[6]._x = 9527;
	_river[7]._x = 6847;
	_river[8]._x = 6975;
	_river[9]._x = 7103;
	for (int i = 0; i < 4; i++)
	{
		_river[i + 10]._x = 7232 + 128 * i;
		_river[i + 10]._y = 1400;
	}

	// 폭포 좌표
	_waterfall[0]._x = 4925;
	_waterfall[1]._x = 7900;
	_waterfall[2]._x = 8985;
	_waterfall[3]._x = 9400;
	_waterfall[4]._x = 9464;
	_waterfall[5]._x = 7550;
	_waterfall[6]._x = 7614;
	_waterfall[7]._x = 7678;
	_waterfall[8]._x = 7550;
	_waterfall[9]._x = 7614;
	_waterfall[10]._x = 7678;

	_waterfall[0]._y = 2180;
	_waterfall[1]._y = 2121;
	_waterfall[2]._y = 1925;
	_waterfall[3]._y = 1797;
	_waterfall[4]._y = 1797;
	_waterfall[5]._y = 1170;
	_waterfall[6]._y = 1170;
	_waterfall[7]._y = 1170;
	_waterfall[8]._y = 1290;
	_waterfall[9]._y = 1290;
	_waterfall[10]._y = 1290;

	_waterfalls[0]._x = 4925;
	_waterfalls[1]._x = 7900;
	_waterfalls[2]._x = 8985;
	_waterfalls[3]._x = 9400;
	_waterfalls[4]._x = 9464;
	_waterfalls[5]._x = 7550;
	_waterfalls[6]._x = 7614;
	_waterfalls[7]._x = 7678;
	_waterfalls[8]._x = 7550;
	_waterfalls[9]._x = 7614;
	_waterfalls[10]._x = 7678;

	_waterfalls[0]._y = 2135;
	_waterfalls[1]._y = 2075;
	_waterfalls[2]._y = 1880;
	_waterfalls[3]._y = 1775;
	_waterfalls[4]._y = 1775;
	_waterfalls[5]._y = 1148;
	_waterfalls[6]._y = 1148;
	_waterfalls[7]._y = 1148;
	_waterfalls[8]._y = 1276;
	_waterfalls[9]._y = 1276;
	_waterfalls[10]._y = 1276;

	for (int i = 0; i < 4; i++)
	{
		_river[i]._y = 2420;
	}

	_river[4]._y = 1910;
	_river[5]._y = 1910;
	_river[6]._y = 1910;
	_river[7]._y = 1460;
	_river[8]._y = 1460;
	_river[9]._y = 1460;
}

void stage1::images()
{
	feild = IMAGEMANAGER->findImage("스테이지1");

	/*
	feild[0] = IMAGEMANAGER->findImage("스테이지 1-1");
	feild[1] = IMAGEMANAGER->findImage("스테이지 1-2");
	feild[2] = IMAGEMANAGER->findImage("스테이지 1-3");
	feild[3] = IMAGEMANAGER->findImage("스테이지 1-4");
	*/

	feildIce = IMAGEMANAGER->findImage("스테이지 1 겨울");
	feildpixel = IMAGEMANAGER->findImage("스테이지1 픽셀");
	_waterWheel = IMAGEMANAGER->findImage("물레방아");

	for (int i = 0; i < 2; i++)
	{
		_bee[i]._img = IMAGEMANAGER->findImage("벌집");
		_iceBee[i]._img = IMAGEMANAGER->findImage("벌집꿀잠");
	}
	for (int i = 0; i < 10; i++)
	{
		tagBoxs _bushs;
		_bushs._img = new image;
		_bushs._img = IMAGEMANAGER->findImage("큰풀");
		_bushs.rc = RectMakeCenter(_bush[i].x, _bush[i].y, 100, 100);
		_vBush.push_back(_bushs);
	}

	for (int i = 0; i < 4; i++)
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
	// 우측 끝 폭포 및 물가 이미지
	for (int i = 0; i < 10; i++)
	{
		_river[4 + i]._img = IMAGEMANAGER->findImage("물가2");
	}
	for (int i = 0; i < 8; i++)
	{
		_waterfall[3 + i]._img = IMAGEMANAGER->findImage("폭포2");
		_waterfalls[3 + i]._img = IMAGEMANAGER->findImage("폭포윗물");
	}

}

void stage1::bgMove()
{
	bgCount++;
	if (_player->getLeft())
	{
		if (bgCount > 2)
		{
			_normalBack1._x -= 0.5f;

			_normalBack2._x -= 2.f;

			_winterBack1._x -= 0.5f;
			_winterBack2._x -= 2.f;
		}

	}
	if (_player->getRight())
	{
		if (bgCount > 2)
		{
			_normalBack1._x += 0.5f;
			_normalBack2._x += 2.f;
			_winterBack1._x += 0.5f;
			_winterBack2._x += 2.f;
		}

	}
	if (bgCount > 3)
	{
		bgCount = 0;
	}
}




void stage1::eftInit()
{


	_eftX[0] = 6360;
	_eftY[0] = 2190;

	_eftX[1] = 6590;
	_eftY[1] = 2120;

	_eftX[2] = 6360;
	_eftY[2] = 2060;

	_eftX[3] = 6590;
	_eftY[3] = 2000;

	_eftX[4] = 6590;
	_eftY[4] = 1800;

	_eftX[5] = 6360;
	_eftY[5] = 1745;

	_eftX[6] = 6590;
	_eftY[6] = 1680;

	_eftX[7] = 7240;
	_eftY[7] = 2325;

	_eftX[8] = 7470;
	_eftY[8] = 2255;

	for (int i = 0; i < 9; i++)
	{
		_effect = new effect;
		_effect->init(IMAGEMANAGER->findImage("빛"), 0.3f);
		_vEffect.push_back(_effect);
	}
}

void stage1::beecollision()
{
	RECT _Trc;
	for (int i = 0; i<2; i++)
	{
		if (IntersectRect(&_Trc, &_bee[i].rc, &_player->getCollisionRc()) && _state == SUMMER && _player->getUnHit() >50 && _player->getPlayerState() != HIT)
		{
			_player->setState(HIT);
			_player->setUnHit(0);
		}
	}
}
void stage1::stageClearInit()
{
	_neolttwigi[0]._img = IMAGEMANAGER->findImage("널뛰기1");
	_neolttwigi[1]._img = IMAGEMANAGER->findImage("널뛰기2");
	_brid[0]._img = IMAGEMANAGER->findImage("새노래");
	_brid[1]._img = IMAGEMANAGER->findImage("새날다");

	stageClearImg = new image;
	stageClearImg = IMAGEMANAGER->findImage("스테이지 클리어");
	_bridAngle = PI / 3;
	_bridSpeed = 20.0f;
	_neolttwigiColls = false;
	stageClearChk = false;
	stageClearCount = 0;

	//널뛰기
	for (int i = 0; i < 2; i++)
	{
		_neolttwigi[i].x = 9500;
		_neolttwigi[i].y = 1250;
		_neolttwigi[i]._count = 0;
		_neolttwigi[1]._index = 0;
		_neolttwigi[i].rc = RectMake(_neolttwigi[i].x, _neolttwigi[i].y + 40, 50, 10);

		_brid[i].x = 9700;
		_brid[i].y = 1220;
		_brid[i]._count = 0;
		_brid[i]._index = 0;
	}
	// 새노래

}


void stage1::stageClear()
{
	RECT _rcT;
	for (int i = 0; i < 2; i++)
	{
		if (IntersectRect(&_rcT, &_neolttwigi[i].rc, &_player->getCollisionRc()) && (_player->getPlayerState() == FALL || _player->getPlayerState() == FALL2))
		{
			_neolttwigiColls = true;
			stageClearChk = true;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		_neolttwigi[i].rc = RectMake(_neolttwigi[i].x /* - _player->getPlayerCam().left */, (_neolttwigi[i].y + 40) /*- _player->getPlayerCam().top*/, 50, 20);
	}
	if (_neolttwigiColls == true)
	{
		_brid[1].x += cosf(_bridAngle)*_bridSpeed;
		_brid[1].y += -sinf(_bridAngle)*_bridSpeed;
		
	}
	if (stageClearChk)
	{
		stageClearCount++;
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			SCENEMANAGER->loadScene("타운씬");
		}
	}
}