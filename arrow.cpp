#include "stdafx.h"
#include "arrow.h"

HRESULT arrow::init(int arrowMax, float range)
{
	_arrowMax = arrowMax;
	_range = range;

	index = 0;
	count = 0;
	return S_OK;
}

void arrow::release(void)
{


}

void arrow::update(void)
{
	move();
	//move2();
	
	animation();
	//animation2();
	

}

void arrow::render(void)
{

}

void arrow::fire(float x, float y, float angle)
{
	if (_arrowMax < _vArrow.size() + 1)return;
	tagArrow arrow;
	ZeroMemory(&arrow, sizeof(tagArrow));
	arrow.arrowImage = IMAGEMANAGER->findImage("arrow");

	//arrow.arrowImage->init("resource/foxPlayer/arrow.bmp", 192, 192, 1, 2, true, MAGENTA);

	arrow.angle = angle;
	arrow.x = arrow.fireX = x;
	arrow.y = arrow.fireY = y;
	arrow.speed = 12.f;

	arrow.rc = RectMakeCenter(arrow.x, arrow.y, arrow.arrowImage->getFrameWidth(), arrow.arrowImage->getFrameHeight());

	_vArrow.push_back(arrow);
}

void arrow::fire2(float x, float y, float angle)
{
	int arrowCount = 0;
	for (int i = 0; i < _arrowMax; ++i)
	{
		poison[i].arrowImage = IMAGEMANAGER->findImage("POISON");

		poison[i].angle = angle;
		poison[i].x = x;
		poison[i].y = y;
		poison[i].speed = 12.f;

		poison[i].rc = RectMakeCenter(poison[i].x, poison[i].y, poison[i].arrowImage->getFrameWidth(), poison[i].arrowImage->getFrameHeight());

		poison[i].fireX += cosf(PI / 180 * poison[i].angle)*poison[i].speed;
		poison[i].fireY += -sinf(PI / 180 * poison[i].angle)*poison[i].speed;

		poison[i].angle -= 15.f;
		arrowCount++;
		if (arrowCount >= 3)
		{
			break;
		}
	}
	
	
}




void arrow::move()
{
	_viArrow = _vArrow.begin();
	for (; _viArrow != _vArrow.end();)
	{
		_viArrow->x += cosf(_viArrow->angle)*_viArrow->speed;
		_viArrow->rc = RectMakeCenter(_viArrow->x, _viArrow->y, _viArrow->arrowImage->getFrameWidth(), _viArrow->arrowImage->getFrameHeight());

		float distance = sqrtf((_viArrow->x - _viArrow->fireX)*(_viArrow->x - _viArrow->fireX) + (_viArrow->y - _viArrow->fireY)*(_viArrow->y - _viArrow->fireY));

		if (_range < distance)
		{
			//_viArrow->arrowImage->release();
			//SAFE_DELETE(_viArrow->arrowImage);
			//SOUNDMANAGER->play("화살펄스사운드", 10.f);
			_viArrow = _vArrow.erase(_viArrow);
		}
		else
		{
			_viArrow++;
		}
	}
}



void arrow::animation()
{
	for (int i = 0; i < _vArrow.size(); ++i)
	{
		if (_vArrow[i].angle == PI)
		{
			_vArrow[i].arrowImage->setFrameY(1);
		}
		if (_vArrow[i].angle == 0)
		{
			_vArrow[i].arrowImage->setFrameY(0);
		}
	}
}

void arrow::animation2()
{
	for (int i = 0; i < 3; i++)
	{
		if (poison[i].angle == PI)
		{
			count++;
			poison[i].arrowImage->setFrameY(1);
			if (count % 3 == 0)
			{
				index--;
				if (index < 0)
				{
					index = poison[i].arrowImage->getMaxFrameX();
				}
				poison[i].arrowImage->setFrameX(index);
			}
		}
		if (poison[i].angle == 0)
		{
			count++;
			poison[i].arrowImage->setFrameY(0);
			if (count % 3 == 0)
			{
				index++;
				if (index > poison[i].arrowImage->getMaxFrameX())
				{
					index = 0;
				}
				poison[i].arrowImage->setFrameX(index);
			}
		}
	}
}

void arrow::removeArrow(int index)
{
	//_vArrow[index].arrowImage->release();
	//SAFE_DELETE(_vArrow[index].arrowImage);

	//SOUNDMANAGER->play("화살펄스사운드", 10.f);
	_vArrow.erase(_vArrow.begin() + index);
}

void arrow::removePoison(int index)
{
	_vPoison.erase(_vPoison.begin() + index);
}
