#include "stdafx.h"
#include "stage1.h"

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
<<<<<<< HEAD
	imagePosition();
	images();
=======
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
>>>>>>> e3f537a6e8a5cf56efb32f678640a2db0b115137
	return S_OK;
}
void stage1::release(void)
{

}

void stage1::update(void)
{
<<<<<<< HEAD
	imageMove();

	if(KEYMANAGER->isToggleKey(VK_F2))cameraMove();
=======
	//cameraMove();
	imageMove();

	if (KEYMANAGER->isToggleKey(VK_F2))
	{
		cameraMove();
	}
>>>>>>> e3f537a6e8a5cf56efb32f678640a2db0b115137
	_cam.rc = RectMakeCenter(_cam.x, _cam.y, WINSIZEX, WINSIZEY);
}

void stage1::render(void)
{
	//IMAGEMANAGER->findImage("��������1")->render(getMemDC(), 0, 0, _cam.rc.left, _cam.rc.top, WINSIZEX, WINSIZEY);
	for (int i = 0; i < 6; i++)
	{
<<<<<<< HEAD
		_river[i]._img->frameRender(getMemDC(), _river[i]._x - _cam.rc.left, _river[i]._y - _cam.rc.top);
=======
		_river[i]._img->frameRender(getMemDC(), _riverX[i] - _cam.rc.left, _riverY[i] - _cam.rc.top);
>>>>>>> e3f537a6e8a5cf56efb32f678640a2db0b115137
	}
	feildpixel->render(getMemDC(), 0, 0, _cam.rc.left, _cam.rc.top, WINSIZEX, WINSIZEY);
	feild->render(getMemDC(), 0, 0, _cam.rc.left, _cam.rc.top, WINSIZEX, WINSIZEY);

	char str[128];
	sprintf_s(str, "%d    %d ",_ptMouse.x + _cam.rc.left, _ptMouse.y + _cam.rc.top);
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
		_cam.x += 100;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_cam.x -= 100;

	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_cam.y -= 100;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_cam.y += 100;
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
