#include "stdafx.h"
#include "item.h"




void item::update(void)
{
	this->_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
	if (_type != ITEM_BOX)
	{
		this->animation();
	}
	this->pixelCollision();
	this->move();

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
			//_count = 0;
		}
	}
	_image->setFrameX(_index);
	_image->setFrameY(0);
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
	_image = new image;
	_image = IMAGEMANAGER->findImage("헬스빅");
	_bfx = IMAGEMANAGER->findImage("스테이지1 픽셀");
	_speed = 3.f;
	_angle = 0;
	_gravity = 0.f;
	_count = 0, _index = 0;
	_animationSpeed = 5.f;
	_isActived = true;
	_type = HEALTH_SMALL;
	_x = 0.f;
	_y = 0.f;
}

void healthBig::move()
{
	//_angle += 0.1f;
	//_x += cosf(_angle)*_speed;
	//_y += -sinf(_angle)*_speed;
}

void manaBig::init()
{
	_image = new image;
	_image = IMAGEMANAGER->findImage("마나빅");
	_bfx = IMAGEMANAGER->findImage("스테이지1 픽셀");
	_speed = 3.f;
	_angle = 0;
	_gravity = 0.f;
	_count = 0, _index = 0;
	_animationSpeed = 5.f;
	_isActived = true;
	_type = MANA_BIG;
	_x = 0.f;
	_y = 0.f;
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
	_image = new image;
	_image = IMAGEMANAGER->findImage("마나스몰");
	_bfx = IMAGEMANAGER->findImage("스테이지1 픽셀");
	_speed = 3.f;
	_angle = 270.f * 3.14f / 180;
	_gravity = 0.f;
	_count = 0, _index = 0;
	_animationSpeed = 5.f;
	_isActived = true;
	_type = MANA_SMALL;
	_x = 0.f;
	_y = 0.f;
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
	_image = new image;
	_image = IMAGEMANAGER->findImage("금화");
	_bfx = IMAGEMANAGER->findImage("스테이지1 픽셀");
	_speed = 5.f;
	_angle = PI/2;
	_gravity = 0.f;
	_count = 0, _index = 0;
	_animationSpeed = 5.f;
	_isActived = true;
	_type = GOLD_COIN;
	_x = 0.f;
	_y = 0.f;
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
	_image = new image;
	_image = IMAGEMANAGER->findImage("은화");
	_bfx = IMAGEMANAGER->findImage("스테이지1 픽셀");
	_speed = 5.f;
	_angle = PI * 73 /150;
	_gravity = 0.f;
	_count = 0, _index = 0;
	_animationSpeed = 5.f;
	_isActived = true;
	_type = SILVER_COIN;
	_x = 0.f;
	_y = 0.f;
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
	_image = new image;
	_image = IMAGEMANAGER->findImage("동화");
	_bfx = IMAGEMANAGER->findImage("스테이지1 픽셀");
	_speed = 5.f;
	_angle = PI * 77 / 150;
	_gravity = 0.f;
	_count = 0, _index = 0;
	_animationSpeed = 5.f;
	_isActived = true;
	_type =	BRONZE_COIN;
	_x = 0.f;
	_y = 0.f;
}

void bronzeCoin::move()
{
	if (_speed != 0)
		_gravity += 0.08f;
	_x += cosf(_angle)*_speed;
	_y += -sinf(_angle)*_speed + _gravity;
}

void itemBox::init()
{
	//_image = new image;
	_image = IMAGEMANAGER->findImage("상자");
	_bfx = IMAGEMANAGER->findImage("스테이지1 픽셀");
	_speed = 5.f;
	_angle = PI * 77 / 150;
	_gravity = 0.f;
	_count = 0, _index = 0;
	_image->setFrameX(_index);
	_animationSpeed = 5.f;
	_isActived = false;
	_type = ITEM_BOX;
	_x = 0.f;
	_y = 0.f;
}

void itemBox::move()
{
	if (!_isActived)
	{
		_index = 0;
	}
	else
	{
		_index = 1;
	}
	
	//_image->setFrameX(_index);
	//_image->setFrameY(0);
}
