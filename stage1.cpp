#include "stdafx.h"
#include "stage1.h"

HRESULT stage1::init(void)
{
	// ����
	_state = SUMMER;
	// ī�޶� ���� �ʱ�ȭ
	_cam.x = WINSIZEX / 2;
	_cam.y = 2750 - (WINSIZEY / 2);
	_cam.rc = RectMakeCenter(_cam.x, _cam.y, WINSIZEX, WINSIZEY);
	_index1 = 0;
	_count1 = 0;
	imagePosition();
	images();
	

	_shop = new shop;
	_shop->init();



	//�÷��̾� �����Ҵ�
	_player = new foxPlayer;
	_player->init();

	//���ʹ̸Ŵ���
	_eMG = new enemyManager;
	_eMG->init();

	//�����۸Ŵ���
	_iMG = new itemManager;
	_iMG->init();

	_ui = new UI;
	_ui->init();

	_normalBack1._x = 0;
	_normalBack1._y = 0;
	_normalBack1._img = IMAGEMANAGER->findImage("���̾�1");

	_normalBack2._x = 0;
	_normalBack2._y = 0;
	_normalBack2._img = IMAGEMANAGER->findImage("���̾�2");

	_winterBack1._img = IMAGEMANAGER->findImage("���̾�1 �ܿ�");
	_winterBack2._img = IMAGEMANAGER->findImage("���̾�2 �ܿ�");

	//��ȣ����
	//_eMG->setPlayerLink(_player);
	//_eMG->setItemMGLink(_iMG);

	// �÷��̾�Ŵ��� Ŭ���� ��������
	_eMG->setPlayerManager(_player);
	_eMG->setItemManager(_iMG);
	_iMG->setPlayerLink(_player);
	_iMG->setEMGLink(_eMG);
	_player->setEnemyManager(_eMG);
	_player->setUIManager(_ui);
	_ui->setPlayerManager(_player);


	//���� 
	SOUNDMANAGER->play("��������1 ����");

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
	if (_player->getAng() == false)_state = SUMMER;
	else if (_player->getAng() == true)_state = WINTER;
	//imageMove();
	// ���ƾ� �ΰ��� �̰� �ּ�ó���ߴ� �ϰ� ���߿� �˾Ƽ� ������ -��ȭ-########################################################################
	cameraMove();

	//To Do : ���ƾ� ���� �̰� �ǵ������ƹ� -��ȭ- ##############################################################################################
	imageMove();

	//�÷��̾�
	_player->update();
	//���ʹ̸Ŵ���
	_eMG->update();

	//�����۸Ŵ���
	_iMG->update();

	_shop->update();

	if (KEYMANAGER->isToggleKey(VK_F2))
	{
		cameraMove();
	}
	_cam.rc = RectMakeCenter(_cam.x, _cam.y, WINSIZEX, WINSIZEY);
	//����(�ӽ�)
	if (KEYMANAGER->isOnceKeyDown('R'))
	{
		this->init();
	}
	if (KEYMANAGER->isOnceKeyDown('Z'))		//����Ű�ϰ� ���İ����� ��� ���� �̹������ ������ Z�� �ٲ���� -����-
	{
		if (_state == WINTER)_state = SUMMER;
		else if (_state == SUMMER)_state = WINTER;
	}

	if (_state == WINTER && _a < WINSIZEX)_a+= 30;
	if (_state == SUMMER)_a = 0;
	this->bgMove();

	//_cam.rc = RectMakeCenter(_cam.x, _cam.y, WINSIZEX, WINSIZEY);

}

void stage1::render(void)
{
	
	_normalBack1._img->loopRender(getMemDC(), &RectMake(0, 0 - _player->getPlayerCam().top, WINSIZEX, 2550), _normalBack1._x, _normalBack1._y);
	_normalBack2._img->loopRender(getMemDC(), &RectMake(0, 2400 - _player->getPlayerCam().top, WINSIZEX, 2550), _normalBack2._x, _normalBack2._y);
	if (_state == SUMMER)
	{
		
		//  Ǯ �̹��� ���
		for (int i = 0; i < _vBush.size(); ++i)
		{
			if (!_vBush[i].isActive) continue;
			_vBush[i]._img->render(getMemDC(), _vBush[i].rc.left - _player->getPlayerCam().left, _vBush[i].rc.top - _player->getPlayerCam().top);
		}
		_waterfall[0]._img->frameRender(getMemDC(), _waterfall[0]._x - _player->getPlayerCam().left, 2180 -   _player->getPlayerCam().top);
		_waterfall[1]._img->frameRender(getMemDC(), _waterfall[1]._x - _player->getPlayerCam().left, 2121 - _player->getPlayerCam().top);
		_waterfall[2]._img->frameRender(getMemDC(), _waterfall[2]._x - _player->getPlayerCam().left, 1925 - _player->getPlayerCam().top);

		// ���� �̹��� ���
		for (int i = 0; i < 3; i++)
		{
			
			_waterfalls[i]._img->frameRender(getMemDC(), _waterfalls[i]._x - _player->getPlayerCam().left, _waterfalls[i]._y - _player->getPlayerCam().top);
		}
		// �� �̹��� ���
		for (int i = 0; i < 8; i++)
		{
			_river[i]._img->frameRender(getMemDC(), _river[i]._x - _player->getPlayerCam().left, _river[i]._y - _player->getPlayerCam().top);
		}

		
		// �ʵ� �̹��� ���
		feild->render(getMemDC(), 0, 0, _player->getPlayerCam().left, _player->getPlayerCam().top, WINSIZEX, WINSIZEY);
		_waterWheel->frameRender(getMemDC(), 8582 - _player->getPlayerCam().left, 2000 - _player->getPlayerCam().top);
	}
	if (_state == WINTER)
	{

		_winterBack1._img->loopRender(getMemDC(), &RectMake(0, 0 - _player->getPlayerCam().top, 0 + _a, 2550), _normalBack1._x, _normalBack1._y);
		_winterBack2._img->loopRender(getMemDC(), &RectMake(0, 2400 - _player->getPlayerCam().top, 0 + _a, 2550), _normalBack2._x, _normalBack2._y);

		feild->render(getMemDC(), 0 + _a, 0, _player->getPlayerCam().left +_a, _player->getPlayerCam().top, WINSIZEX - _a , WINSIZEY);
		feildIce->render(getMemDC(), 0, 0, _player->getPlayerCam().left, _player->getPlayerCam().top, 0 + _a, WINSIZEY);
	}
	// �ȼ� �̹��� ���
	if (KEYMANAGER->isToggleKey(VK_F4))
	{
		feildpixel->render(getMemDC(), 0, 0, _player->getPlayerCam().left, _player->getPlayerCam().top, WINSIZEX, WINSIZEY);
	}

	//�����۸Ŵ���
	_iMG->render();
	//�÷��̾�
	//_player->render(_cam.rc.left, _cam.rc.top);
	_player->render();

	//���ʹ̸Ŵ���
	//_eMG->render(_player->getPlayerCam().left, _player->getPlayerCam().top);
	_eMG->render();



	// �׽�Ʈ�� ���� ����
	if (KEYMANAGER->isToggleKey('Q'))
	{
		_shop->render();
	}


	char str[128];
	sprintf_s(str, "%d    %d ",_state,_a);
	TextOut(getMemDC(), 120 , WINSIZEY /2 , str, strlen(str));
	
}

// ������ �̹��� ������

// ī�޶� ������
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
	// ������� �̹���
	_waterWheel->setFrameX(_river[0]._index);

}
void stage1::imagePosition()
{
	// Ǯ

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

	// ���� x��ǥ
	_river[0]._x = 2260;
	_river[1]._x = 5700;
	_river[2]._x = 8220;
	_river[3]._x = 9000;
	_river[4]._x = 16100;

	// ���� ��ǥ
	_waterfall[0]._x = 4925;
	_waterfall[1]._x = 7900;
	_waterfall[2]._x = 9016;



	_waterfalls[0]._x = 4925;
	_waterfalls[1]._x = 7900;
	_waterfalls[2]._x = 9016;

	_waterfalls[0]._y = 2135;
	_waterfalls[1]._y = 2075;
	_waterfalls[2]._y = 1880;

	for (int i = 0; i < 8; i++)
	{
		_river[i]._y = 2420;
	}


}

void stage1::images()
{
	feild = IMAGEMANAGER->findImage("��������1");
	feildIce = IMAGEMANAGER->findImage("�������� 1 �ܿ�");
	feildpixel = IMAGEMANAGER->findImage("��������1 �ȼ�");
	_waterWheel = IMAGEMANAGER->findImage("�������");
	for (int i = 0; i < 10; i++)
	{
		tagBoxs _bushs;
		_bushs._img = new image;
		_bushs._img = IMAGEMANAGER->findImage("ūǮ");
		_bushs.rc = RectMakeCenter(_bush[i].x, _bush[i].y, 100, 100);
		_vBush.push_back(_bushs);
	}

	for (int i = 0; i < 8; i++)
	{
		_river[i]._img = IMAGEMANAGER->findImage("����");
		_river[i]._count = 0;
		_river[i]._index = 0;
	}
	for (int i = 0; i < 3; i++)
	{
		_waterfall[i]._img = IMAGEMANAGER->findImage("����");
		_waterfalls[i]._img = IMAGEMANAGER->findImage("������");
		_waterfall[i]._count = _waterfalls[i]._count = 0;
		_waterfall[i]._index = _waterfalls[i]._index = 0;
	}
	
}

void stage1::bgMove()
{
	if (_player->getLeft())
	{
		_normalBack1._x -= 1;
		_normalBack2._x -= 1;
	}
	if(_player->getRight())
	{
		_normalBack1._x += 1;
		_normalBack2._x += 1;
	}
}
