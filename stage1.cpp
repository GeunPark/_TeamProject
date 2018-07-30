#include "stdafx.h"
#include "stage1.h"
#include "foxPlayer.h"
HRESULT stage1::init(void)
{
	// ����
	_state = NORMAL;
	// ī�޶� ���� �ʱ�ȭ
	_cam.x = WINSIZEX / 2;
	_cam.y = 2750 - (WINSIZEY / 2);
	_cam.rc = RectMakeCenter(_cam.x, _cam.y, WINSIZEX, WINSIZEY);
	// ������ �̹��� ī����, �ε��� �� �ʱ�ȭ
	_count = 0;
	_index = 0;

	imagePosition();
	images();

	// ���� x��ǥ
	
	
	// ��������1 �ʵ� �̹���
	feild = IMAGEMANAGER->findImage("��������1");
	// ��������1 �ʵ� �ȼ� �̹���
	feildpixel = IMAGEMANAGER->findImage("��������1 �ȼ�");
	for (int i = 0; i < 6; i++)
	{
		_river[0]._x = 2467;
		_river[1]._x = 5700;
		_river[2]._x = 11700;
		_river[3]._x = 14100;
		_river[4]._x = 16100;
		_river[5]._x = 17600;
		_river[i]._y = 2630;
		_river[i]._img = IMAGEMANAGER->findImage("����");
	}


	//���ʹ̸Ŵ���
	_eMG = new enemyManager;

	_eMG->init();

	//�÷��̾� �����Ҵ�
	_player = new foxPlayer;
	_player->init();


	_normalBack1._x = 0;
	_normalBack1._y = 0;
	_normalBack1._img = IMAGEMANAGER->findImage("���̾�1���");

	_normalBack2._x = 0;
	_normalBack2._y = 0;
	_normalBack2._img = IMAGEMANAGER->findImage("���̾�2���");


	return S_OK;
}
void stage1::release(void)
{

}

void stage1::update(void)
{

	//imageMove();
	// ���ƾ� �ΰ��� �̰� �ּ�ó���ߴ� �ϰ� ���߿� �˾Ƽ� ������ -��ȭ-########################################################################
	//if(KEYMANAGER->isToggleKey(VK_F2))cameraMove();

	//To Do : ���ƾ� ���� �̰� �ǵ������ƹ� -��ȭ- ##############################################################################################


	//cameraMove();
	imageMove();

	//���ʹ̸Ŵ���
	_eMG->update();

	//�÷��̾�
	_player->update();

	

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




	//_cam.rc = RectMakeCenter(_cam.x, _cam.y, WINSIZEX, WINSIZEY);

}

void stage1::render(void)
{
	_normalBack1._img->loopRender(getMemDC(), &RectMake(0, 0 - _player->getPlayerCam().top, WINSIZEX, 2550), _normalBack1._x, _normalBack1._y);

	//IMAGEMANAGER->findImage("��������1")->render(getMemDC(), 0, 0, _cam.rc.left, _cam.rc.top, WINSIZEX, WINSIZEY);
	for (int i = 0; i < 6; i++)
	{

		_river[i]._img->frameRender(getMemDC(), _river[i]._x - _player->getPlayerCam().left, _river[i]._y - _player->getPlayerCam().top);

		_river[i]._img->frameRender(getMemDC(), _riverX[i] - _player->getPlayerCam().left, _riverY[i]-_player->getPlayerCam().top);

	}
	feildpixel->render(getMemDC(), 0, 0, _player->getPlayerCam().left, _player->getPlayerCam().top, WINSIZEX, WINSIZEY);
	feild->render(getMemDC(), 0, 0, _player->getPlayerCam().left, _player->getPlayerCam().top, WINSIZEX, WINSIZEY);



	//TextOut(getMemDC(), 100, WINSIZEY, )

	//���ʹ̸Ŵ���
	_eMG->render(_player->getPlayerCam().left, _player->getPlayerCam().top);


	//�÷��̾�
	//_player->render(_cam.rc.left, _cam.rc.top);
	_player->render();
	char str[128];
	sprintf_s(str, "%d    %d ",_ptMouse.x + _player->getPlayerCam().left, _ptMouse.y + _player->getPlayerCam().top);
	TextOut(getMemDC(), 120 , WINSIZEY /2 , str, strlen(str));

}

// ������ �̹��� ������
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

// ī�޶� ������
void stage1::cameraMove()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_cam.x += 30;
		//_normalBack1._x += 1;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_cam.x -= 30;
		//_normalBack1._x -= 1;

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
	// ���� x��ǥ
	_river[0]._x = 2467;
	_river[1]._x = 5700;
	_river[2]._x = 11700;
	_river[3]._x = 14100;
	_river[4]._x = 16100;
	_river[5]._x = 17600;
	// ���� ��ǥ

	for (int i = 0; i < 6; i++)
	{
		_river[i]._y = 2630;
	}
}

void stage1::images()
{
	feild = IMAGEMANAGER->findImage("��������1");
	feildpixel = IMAGEMANAGER->findImage("��������1 �ȼ�");
	for (int i = 0; i < 6; i++)
	{
		_river[i]._img = IMAGEMANAGER->findImage("����");
	}
}
