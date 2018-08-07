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
	bgCount = 0;
	_bagrandslide = 0;
	imagePosition();
	images();

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


	_shop = new shop;
	_shop->init();


	_normalBack1._x = 0;
	_normalBack1._y = 0;
	_normalBack1._img = IMAGEMANAGER->findImage("���̾�1");

	_normalBack2._x = 0;
	_normalBack2._y = 0;
	_normalBack2._img = IMAGEMANAGER->findImage("���̾�2");

	_winterBack1._img = IMAGEMANAGER->findImage("���̾�1 �ܿ�");
	_winterBack1._x = 0;
	_winterBack1._y = 0;

	_winterBack2._img = IMAGEMANAGER->findImage("���̾�2 �ܿ�");
	_winterBack2._x = 0;
	_winterBack2._y = 0;

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
	_player->setShopManager(_shop);
	_shop->setPlayerManager(_player);
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
	if (_state == WINTER && _bagrandslide != WINSIZEX)
	{
		_bagrandslide += 32;
	}
	if (_state == SUMMER)_bagrandslide = 0;
	this->bgMove();


	for (int i = 0; i < 2; i++)
	{
		
		_bee[i].rc = RectMake(_bee[i].x - _player->getPlayerCam().left, _bee[i].y - _player->getPlayerCam().top, 240, 240);
	}
}

void stage1::render(void)
{
	
	_normalBack1._img->loopRender(getMemDC(), &RectMake(0, 0 - _player->getPlayerCam().top, WINSIZEX, 2550), _normalBack1._x, _normalBack1._y);
	_normalBack2._img->loopRender(getMemDC(), &RectMake(0, 2200 - _player->getPlayerCam().top, WINSIZEX, 2550), _normalBack2._x, _normalBack2._y);
	if (_state == SUMMER)
	{
		
		//  Ǯ �̹��� ���
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
		// �� �̹��� ���
		for (int i = 0; i < 4; i++)
		{
			_river[i]._img->frameRender(getMemDC(), _river[i]._x - _player->getPlayerCam().left, _river[i]._y - _player->getPlayerCam().top);
		}
		for (int i = 0; i < 7; i++)
		{
			_river[7 + i]._img->frameRender(getMemDC(), _river[7 + i]._x - _player->getPlayerCam().left, _river[7 + i]._y - _player->getPlayerCam().top);
		}
		feild->render(getMemDC(), 0 , 0, _player->getPlayerCam().left, _player->getPlayerCam().top, WINSIZEX, WINSIZEY);
		for (int i = 3; i < 5; i++)
		{
			_waterfall[i]._img->frameRender(getMemDC(), _waterfall[i]._x - _player->getPlayerCam().left, _waterfall[i]._y - _player->getPlayerCam().top);
			_waterfalls[i]._img->frameRender(getMemDC(), _waterfalls[i]._x - _player->getPlayerCam().left, _waterfalls[i]._y - _player->getPlayerCam().top);
		}
		for (int i = 4; i < 7; i++)
		{
			_river[i]._img->frameRender(getMemDC(), _river[i]._x - _player->getPlayerCam().left, _river[i]._y - _player->getPlayerCam().top);
		}
		// �� �̹���
		for (int i = 0; i < 2; i++)
		{
			_bee[i]._img->frameRender(getMemDC(),_bee[i].x - _player->getPlayerCam().left, _bee[i].y- _player->getPlayerCam().top);
			
		}
		
		_waterWheel->frameRender(getMemDC(), 8730 - _player->getPlayerCam().left, 2175 - _player->getPlayerCam().top);
		/*
		for (int i = 0; i < 4; i++)
		{
			feild[i]->render(getMemDC(), 0 + 2500 * i, 0, _player->getPlayerCam().left, _player->getPlayerCam().top, WINSIZEX, WINSIZEY);
		}
		*/
		
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
		// �� �̹��� ���
		for (int i = 0; i < 4; i++)
		{
			_river[i]._img->frameRender(getMemDC(), _river[i]._x - _player->getPlayerCam().left, _river[i]._y - _player->getPlayerCam().top);
		}
		for (int i = 0; i < 7; i++)
		{
			_river[7 + i]._img->frameRender(getMemDC(), _river[7 + i]._x - _player->getPlayerCam().left, _river[7 + i]._y - _player->getPlayerCam().top);
		}
		
		_waterWheel->frameRender(getMemDC(), 8730 - _player->getPlayerCam().left, 2175 - _player->getPlayerCam().top);
		//////////////////////////////////////////////��          ��               ��/////////////////////////////////////////////////////////////////////
		_winterBack1._img->loopRender(getMemDC(), &RectMake(0, 0 - _player->getPlayerCam().top, 0 + _bagrandslide, 2550), _winterBack1._x, _winterBack1._y);
		_winterBack2._img->loopRender(getMemDC(), &RectMake(0, 2200 - _player->getPlayerCam().top, 0 + _bagrandslide, 2550), _winterBack2._x, _winterBack2._y);
		feild->render(getMemDC(), 0 + _bagrandslide, 0, _player->getPlayerCam().left + _bagrandslide, _player->getPlayerCam().top, WINSIZEX - _bagrandslide, WINSIZEY);
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		for (int i = 0; i < 2; i++)
		{
			_bee[i]._img->frameRender(getMemDC(), _bee[i].x - _player->getPlayerCam().left, _bee[i].y - _player->getPlayerCam().top);

		}
		for (int i = 3; i < 5; i++)
		{
			_waterfall[i]._img->frameRender(getMemDC(), _waterfall[i]._x - _player->getPlayerCam().left, _waterfall[i]._y - _player->getPlayerCam().top);
			_waterfalls[i]._img->frameRender(getMemDC(), _waterfalls[i]._x - _player->getPlayerCam().left, _waterfalls[i]._y - _player->getPlayerCam().top);
		}
		for (int i = 4; i < 7; i++)
		{
			_river[i]._img->frameRender(getMemDC(), _river[i]._x - _player->getPlayerCam().left, _river[i]._y - _player->getPlayerCam().top);
		}

		/////////////////////////////////////////////��          ��               ��/////////////////////////////////////////////////////////////
		feildIce->render(getMemDC(), 0, 0, _player->getPlayerCam().left, _player->getPlayerCam().top, 0 + _bagrandslide, WINSIZEY);
		for (int i = 0; i < 2; i++)
		{
			_iceBee[i]._img->frameRender(getMemDC(), _iceBee[i].x - _player->getPlayerCam().left, _iceBee[i].y - _player->getPlayerCam().top);
		}
	}
	// �ȼ� �̹��� ���
	if (KEYMANAGER->isToggleKey(VK_F4))
	{
		feildpixel->render(getMemDC(), 0, 0, _player->getPlayerCam().left, _player->getPlayerCam().top, WINSIZEX, WINSIZEY);
		Rectangle(getMemDC(), _bee[0].rc);
		Rectangle(getMemDC(), _bee[1].rc);
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
	sprintf_s(str, "%d    %d ",_ptMouse.x + _player->getPlayerCam().left,_ptMouse.y + _player->getPlayerCam().top);
	TextOut(getMemDC(), 120 , WINSIZEY /2 , str, strlen(str));
	
}

// ������ �̹��� ������

// ī�޶� ������
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


	// ������� �̹���
	_waterWheel->setFrameX(_river[0]._index);

}
void stage1::imagePosition()
{
	// Ǯ
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
	}

	_bush[9].y = 2600;

	// ���� x��ǥ
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

	// ���� ��ǥ
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
	feild = IMAGEMANAGER->findImage("��������1");
	
	/*
	feild[0] = IMAGEMANAGER->findImage("�������� 1-1");
	feild[1] = IMAGEMANAGER->findImage("�������� 1-2");
	feild[2] = IMAGEMANAGER->findImage("�������� 1-3");
	feild[3] = IMAGEMANAGER->findImage("�������� 1-4");
	*/

	feildIce = IMAGEMANAGER->findImage("�������� 1 �ܿ�");
	feildpixel = IMAGEMANAGER->findImage("��������1 �ȼ�");
	_waterWheel = IMAGEMANAGER->findImage("�������");

	for (int i = 0; i < 2; i++)
	{
		_bee[i]._img = IMAGEMANAGER->findImage("����");
		_iceBee[i]._img = IMAGEMANAGER->findImage("��������");
	}
	for (int i = 0; i < 10; i++)
	{
		tagBoxs _bushs;
		_bushs._img = new image;
		_bushs._img = IMAGEMANAGER->findImage("ūǮ");
		_bushs.rc = RectMakeCenter(_bush[i].x, _bush[i].y, 100, 100);
		_vBush.push_back(_bushs);
	}

	for (int i = 0; i < 4; i++)
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
	// ���� �� ���� �� ���� �̹���
	for (int i = 0; i < 10; i++)
	{
		_river[4 + i]._img = IMAGEMANAGER->findImage("����2");
	}
	for (int i = 0; i < 8; i++)
	{
		_waterfall[3 + i]._img = IMAGEMANAGER->findImage("����2");
		_waterfalls[3 + i]._img = IMAGEMANAGER->findImage("��������");
	}
	
}
void stage1::bgMove()
{
	bgCount++;
	if (_player->getLeft())
	{
		if (bgCount > 2)
		{
			_normalBack1._x -= 1;
			_normalBack2._x -= 1;
			_winterBack1._x -= 1;
			_winterBack2._x -= 1;
		}
		
	}
	if(_player->getRight())
	{
		if (bgCount > 2)
		{
			_normalBack1._x += 1;
			_normalBack2._x += 1;
			_winterBack1._x += 1;
			_winterBack2._x += 1;
		}
	
	}
	if (bgCount > 3)
	{
		bgCount = 0;
	}
}
