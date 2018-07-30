#include "stdafx.h"
#include "foxPlayer.h"

HRESULT foxPlayer::init(void)
{
	_player.x = 200;
	_player.y = 2200;
	_player.speed = 10.f;
	_player.gravity = 0.f;
	_player.angle = PI / 2;
	_player.isJump = false;

	_camera.x = _player.x;
	_camera.y = _player.y;

	return S_OK;
}

void foxPlayer::release(void)
{
}

void foxPlayer::update(void)
{

	
		this->move();
	
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
	if (KEYMANAGER->isToggleKey('P'))
	{
		Rectangle(getMemDC(), _camera.rc);
	}
}
void foxPlayer::move()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_player.x += _player.speed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_player.x -= _player.speed;
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
	

	if (_player.isJump)
	{
		_player.gravity += 0.09f;
		_player.x += cosf(_player.angle)*_player.speed;
		_player.y += -sinf(_player.angle)*_player.speed + _player.gravity;
	}

	if (_player.rc.bottom - _camera.rc.top > WINSIZEY)
	{
		_player.gravity = 0.f;
		_player.rc.bottom = WINSIZEY - 90;
		_player.isJump = false;
	}
}
