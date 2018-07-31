#include "stdafx.h"
#include "foxPlayer.h"

HRESULT foxPlayer::init(void)
{
	_player.x = 180;
	_player.y = MAX_HEIGHT - 180;
	_player.speed = 10.f;
	_player.gravity = 0.f;
	_player.angle = PI / 2;
	_player.radian = 90;
	_player.isJump = _player.isLeft = _player.isRight = _player.isAtt = false;
	
	_camera.x = _player.x;
	_camera.y = _player.y;

	_bfx = IMAGEMANAGER->findImage("스테이지1 픽셀");
	return S_OK;
}

void foxPlayer::release(void)
{
}

void foxPlayer::update(void)
{
	
	this->keySetting();	  //키셋팅 함수 호출
	
	this->camera();			//카메라 움직이는 함수 호출
	
	this->pixelCollision();		//픽셀충돌 함수 호출
	if (_player.isAtt)
	{
		attRc = RectMakeCenter(_player.x + _player.radian + 50, _player.y, 50, 50);
	}
	else
	{
		attRc = RectMakeCenter(-10000,-10000 , 30, 30);
	}
	_player.rc = RectMakeCenter(_player.x, _player.y , 180 , 180);
	_camera.rc = RectMakeCenter(_camera.x, _camera.y, WINSIZEX, WINSIZEY);
}

//void foxPlayer::render(float FX, float FY)
//{
//	Rectangle(getMemDC(), _player.rc.left -FX , _player.rc.top -FY , _player.rc.right - FX, _player.rc.bottom - FY);
//}

void foxPlayer::render()
{
	
	Rectangle(getMemDC(), _player.rc.left - _camera.rc.left, _player.rc.top - _camera.rc.top, _player.rc.right - _camera.rc.left, _player.rc.bottom - _camera.rc.top);
	
	Rectangle(getMemDC(), attRc.left - _camera.rc.left, attRc.top - _camera.rc.top, attRc.right - _camera.rc.left, attRc.bottom - _camera.rc.top);
	if (KEYMANAGER->isToggleKey('P'))
	{
		Rectangle(getMemDC(), _camera.rc);
	}
}

void foxPlayer::keySetting()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_player.isRight = true;
		_player.x += _player.speed;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_player.isRight = false;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_player.isLeft = true;
		_player.x -= _player.speed;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_player.isLeft = false;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_player.y -= _player.speed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_player.y += _player.speed;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_player.isJump = true;
	}
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		_player.isAtt = true;
	}
	if (KEYMANAGER->isOnceKeyUp('A'))
	{
		_player.isAtt = false;
	}
	if (_player.isJump)
	{
		_player.gravity += 0.09f;
		_player.x += cosf(_player.angle)*_player.speed;
		_player.y += -sinf(_player.angle)*_player.speed + _player.gravity;
	}

	//if (_player.rc.bottom - _camera.rc.top > WINSIZEY)
	//{
	//	_player.gravity = 0.f;
	//	_player.rc.bottom = WINSIZEY - _player.radian;
	//	_player.isJump = false;
	//}
	if (_player.x - _player.radian < 0)
	{
		_player.x = _player.radian;
		_player.isLeft = false;
	}
	
}

void foxPlayer::camera()		//카메라 움직이는 함수
{
	_camera.x = _player.x;
	_camera.y = _player.y;

	if (_camera.x - WINSIZEX / 2 < 0)
	{
		_camera.x = WINSIZEX / 2;
	}
	if (_camera.x + WINSIZEX / 2 > MAX_WIDTH)
	{
		_camera.x = MAX_WIDTH - WINSIZEX / 2;
	}
	if (_camera.y - WINSIZEY / 2 < 0)
	{
		_camera.y = WINSIZEY / 2;
	}
	if (_camera.y + WINSIZEY / 2 > MAX_HEIGHT)
	{
		_camera.y = MAX_HEIGHT - WINSIZEY / 2;
	}
}

void foxPlayer::pixelCollision()		//픽셀 충돌
{
	for (int i = _player.rc.bottom-50; i < _player.rc.bottom + 1 ; ++i)
	{
		
			COLORREF color = GetPixel(_bfx->getMemDC(), _player.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if (r == 0 && g == 255 && b == 255)
			{
				_player.y = i - _player.radian-1;
				_player.gravity = 0.f;
				_player.isJump = false;
				break;
			}
			else
			{
	//			_player.y += 0.2f;
			}
	}
	//for (int i = _player.rc.top; i > _player.rc.top - 1; --i)
	//{
	//	COLORREF color = GetPixel(_bfx->getMemDC(), _player.x, i);

	//	int r = GetRValue(color);
	//	int g = GetGValue(color);
	//	int b = GetBValue(color);

	//	if (r == 0 && g == 255 && b == 255)
	//	{
	//		_player.y = i - _player.radian - 1;
	//		
	//		break;
	//	}
	//	else
	//	{
	//		//			_player.y += 0.2f;
	//	}
	//}
	//for (int i = _player.rc.left; i < _player.rc.right; ++i)
	//{
	//	COLORREF color = GetPixel(_bfx->getMemDC(), i, _player.y);

	//	int r = GetRValue(color);
	//	int g = GetGValue(color);
	//	int b = GetBValue(color);

	//	if (r == 0 && g == 255 && b == 255)
	//	{
	//		_player.y = i - _player.radian - 1;

	//		break;
	//	}
	//	else
	//	{
	//		//			_player.y += 0.2f;
	//	}
	//}
}
