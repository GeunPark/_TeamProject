#include "stdafx.h"
#include "item.h"


HRESULT item::init(const char * ImageName, POINT position, int currentFrameX, float _angle)
{
	_image = IMAGEMANAGER->findImage(ImageName);
	_bfx = IMAGEMANAGER->findImage("스테이지1 픽셀");

	this->_x = position.x;
	this->_y = position.y;
	this->speed = 2.0f;
	this->angle = _angle;
	this->gravity = 0;
	this->_currentFrameX = currentFrameX;
	_count = 0;

	return S_OK;

}

void item::release(void)
{


}

void item::update(void)
{

	this->_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
	this->move();
	this->animation();
	this->pixelCollision();
}

void item::render(float FX, float FY)
{
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(getMemDC(), _rc.left - FX, _rc.top - FY, _rc.right - FX, _rc.bottom - FY);
	}
	_image->frameRender(getMemDC(), _rc.left - FX, _rc.top - FY, _currentFrameX, 0);

}

void item::animation()
{
	_count++;
	if (_count % 5 == 0)
	{
		_currentFrameX++;
		if (_currentFrameX > _image->getMaxFrameX())
		{
			_currentFrameX = 0;
			//_count = 0;
		}
	}
}

void item::move()
{

}

void item::pixelCollision()
{

	for (int i = _rc.left; i < _rc.right; i += 2)
	{
		for (int j = _rc.bottom - 10; j <_rc.bottom; j += 2)  // _rc.bottom - 10; j < _rc.bottom; j++)
		{
			COLORREF color = GetPixel(_bfx->getMemDC(), i, j);
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 255 && b == 255))
			{
				_y = j - _image->getFrameHeight() / 2;
				gravity = 0;

				if (speed > 0)
				{
					speed -= 0.02f;
				}
				else
				{
					speed = 0;
				}
				break;
			}
		}
	}


}



void healthLarge::move()
{
}

void healthBig::move()
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

void goldCoin::move()
{
	if (speed != 0)
		gravity += 0.08f;
	_x += cosf(angle)*speed;
	_y += -sinf(angle)*speed + gravity;
}

void silverCoin::move()
{
	if (speed != 0)
		gravity += 0.08f;
	_x += cosf(angle)*speed;
	_y += -sinf(angle)*speed + gravity;
}

void bronzeCoin::move()
{
	if (speed != 0)
		gravity += 0.08f;
	_x += cosf(angle)*speed;
	_y += -sinf(angle)*speed + gravity;
}
