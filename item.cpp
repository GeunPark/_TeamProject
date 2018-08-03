#include "stdafx.h"
#include "item.h"




void item::update(void)
{
	this->_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
	this->move();
	this->animation();
	this->pixelCollision();
}



void item::animation()
{
	_count++;
	if (_count % 5 == 0)
	{
		_index++;
		if (_index > _image->getMaxFrameX())
		{
			_index = 0;
			_count = 0;
		}
	}
}

void item::pixelCollision()
{

	for (int j = _rc.bottom - 4; j < _rc.bottom; j += 2)
	{
		COLORREF color = GetPixel(_bfx->getMemDC(), _x, j);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 255 && b == 255))
		{
			_y = j - _image->getFrameHeight() / 2;
			_gravity = 0;

			if (_speed > 0.5f)
			{
				_speed /= 2.0f;
			}
			else
			{
				_speed = 0;
			}
			break;
		}
	}
}



void healthLarge::init()
{
	_image = new image;
	_image = IMAGEMANAGER->findImage("헬스라지");
	_bfx = IMAGEMANAGER->findImage("스테이지1 픽셀");
	_speed = 3.f;
	_angle = 270.f * 3.14f / 180;
	_gravity = 0.f;
	_count = 0, _index = 0;
	_animationSpeed = 5.f;
	_isActived = true;
	_type = HEALTH_LARGE;
	_x = 0.f;
	_y = 0.f;
}

void healthLarge::move()
{
}

void healthBig::init()
{
}

void healthBig::move()
{
}

void manaBig::init()
{
}

void manaBig::move()
{
	if (_count % 100 < 50)
	{
		_y += 0.2f;
	}
	else if (_count % 100 <= 100)
	{
		_y -= 0.2f;
	}
}

void manaSmall::init()
{
}

void manaSmall::move()
{
	if (_count % 100 < 50)
	{
		_y += 0.2f;
	}
	else if (_count % 100 <= 100)
	{
		_y -= 0.2f;
	}
}

void goldCoin::init()
{
}

void goldCoin::move()
{
	if (_speed != 0)
		_gravity += 0.08f;
	_x += cosf(_angle)*_speed;
	_y += -sinf(_angle)*_speed + _gravity;
}

void silverCoin::init()
{
}

void silverCoin::move()
{
	if (_speed != 0)
		_gravity += 0.08f;
	_x += cosf(_angle)*_speed;
	_y += -sinf(_angle)*_speed + _gravity;
}

void bronzeCoin::init()
{
}

void bronzeCoin::move()
{
	if (_speed != 0)
		_gravity += 0.08f;
	_x += cosf(_angle)*_speed;
	_y += -sinf(_angle)*_speed + _gravity;
}
