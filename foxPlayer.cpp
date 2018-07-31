#include "stdafx.h"
#include "foxPlayer.h"

HRESULT foxPlayer::init(void)
{
	imageSetting();
	_state = IDLE;
	_player.x = 180;
	_player.y = MAX_HEIGHT - 180;
	_player.speed = 10.f;
	_player.gravity = 0.f;
	_player.angle = PI / 2;
	_player.radian = 90;
	_player.isJump = _player.isLeft = _player.isRight = _player.isAtt = _player.isUp = _player.isDown = false;
	
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
	_player.rc = RectMakeCenter(_player.x, _player.y, 180, 180);
	
	_player.rc = RectMakeCenter(_player.x, _player.y, 180, 180);

	this->pixelCollision();		//픽셀충돌 함수 호출
	if (_player.isAtt)
	{
		attRc = RectMakeCenter(_player.x + _player.radian + 50, _player.y, 50, 50);
	}
	else
	{
		attRc = RectMakeCenter(-10000,-10000 , 50, 50);
	}
	
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
	
}

void foxPlayer::imageSetting()
{
	nick[IDLE] = IMAGEMANAGER->findImage("Idle");		//아이들
	nick[RUN] = IMAGEMANAGER->findImage("Run");			//달리기
	nick[JUMP] = IMAGEMANAGER->findImage("Jump");		//점프
	nick[DOUBLEJUMP] = IMAGEMANAGER->findImage("Jump2");	//이단점프
	nick[FALL] = IMAGEMANAGER->findImage("Fall");		//떨어지는
	nick[FIRE] = IMAGEMANAGER->findImage("Fire");		//발사
	nick[UPATT] = IMAGEMANAGER->findImage("UpAtt");		//상단베기
	nick[SITATT] = IMAGEMANAGER->findImage("SitAtt");	//앉아공격
	nick[SIT] = IMAGEMANAGER->findImage("Sit");			//앉기
	nick[JUMPATT] = IMAGEMANAGER->findImage("JumpAtt");	//점프공격
	nick[JUMPATT2] = IMAGEMANAGER->findImage("JumpAtt2");	//점프공격2 회전회오리~!
	nick[DOWNATT] = IMAGEMANAGER->findImage("DownAtt");	//내려찍기
}

void foxPlayer::frameMove()
{
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
		_player.isUp = true;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_player.isDown = true;
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
	//플레이어 렉트 바텀 픽셀충돌
	for (int i = _player.rc.bottom - _player.speed; i < _player.rc.bottom+30; ++i)
	{
		
			COLORREF color = GetPixel(_bfx->getMemDC(), _player.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if (r == 0 && g == 255 && b == 255 && (-sinf(_player.angle)*_player.speed + _player.gravity > 0 || !_player.isJump))
			{ 
				_player.y = i - _player.radian;
				_player.gravity = 0.f;
				_player.isJump = false;
				break;
			}
			else if (!(r == 0 && g == 255 && b == 255) && !_player.isJump)
			{
				_player.y += 0.2f;
			}
		
			
	}
	//for (int i = _player.rc.top-10; i < _player.rc.top; ++i)
	//{
	//	COLORREF color = GetPixel(_bfx->getMemDC(), _player.x, i);
	//
	//	int r = GetRValue(color);
	//	int g = GetGValue(color);
	//	int b = GetBValue(color);
	//
	//	if (r == 0 && g == 255 && b == 255)
	//	{
	//		_player.y = i + _player.radian;
	//		
	//		break;
	//	}
	//	else
	//	{
	//		//			_player.y += 0.2f;
	//	}
	//}
	
	for (int i = _player.rc.right - _player.speed ; i < _player.rc.right+5 ; i++ )
	{
		COLORREF color = GetPixel(_bfx->getMemDC(), i, _player.y);
	
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
	
		if (r == 0 && g == 255 && b == 255)
		{
			_player.x = i - _player.radian;
			
			_player.isRight = false;
			

	
			break;
		}
		else
		{
			//_player.x -= 0.2f;
		}
	}
	for (int i = _player.rc.left + _player.speed; i > _player.rc.left; --i)
	{
		COLORREF color = GetPixel(_bfx->getMemDC(), i, _player.y);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 0 && g == 255 && b == 255)
		{
			_player.x = i + _player.radian;
			_player.isLeft = false;
			//if (_player.isLeft == false)
			//{
			//	_player.x -= 2;
			//}

			break;
		}
	}
	//for (int i = _player.rc.top; i < _player.rc.bottom; i += (_player.rc.bottom - _player.rc.top) / 2)
	//{
	//	for (int j = _player.rc.right; j < _player.rc.right; ++j)
	//	{
	//		COLORREF color = GetPixel(_bfx->getMemDC(), j, i);
	//
	//		int r = GetRValue(color);
	//		int g = GetGValue(color);
	//		int b = GetBValue(color);
	//
	//		if (r == 0 && g == 255 && b == 255 )
	//		{
	//			_player.x = j - _player.radian;
	//			_player.isJump = false;
	//			break;
	//		}
	//	}
	//}
}
