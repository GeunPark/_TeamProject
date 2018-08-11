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
	if (_arrowMax < _vPoison.size() + 1)return;
	tagArrow2 poison;
	ZeroMemory(&poison, sizeof(tagArrow2));
	poison.arrowImage = IMAGEMANAGER->findImage("Poison");

	poison.angle = angle;
	poison.x = poison.fireX = x;
	poison.y = poison.fireY = y;
	poison.speed = 12.f;

	poison.rc = RectMakeCenter(poison.x, poison.y, poison.arrowImage->getFrameWidth(), poison.arrowImage->getFrameHeight());

	_vPoison.push_back(poison);
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
			_viArrow = _vArrow.erase(_viArrow);
		}
		else
		{
			_viArrow++;
		}
	}
}

void arrow::move2()
{
	_viPoison = _vPoison.begin();
	for (; _viPoison != _vPoison.end();)
	{
		_viPoison->x += cosf(_viPoison->angle)*_viPoison->speed;
		_viPoison->rc = RectMakeCenter(_viPoison->x, _viPoison->y, _viPoison->arrowImage->getFrameWidth(), _viPoison->arrowImage->getFrameHeight());

		if (_range < getDistance(_viPoison->x, _viPoison->y, _viPoison->fireX, _viPoison->fireY))
		{
			_viPoison = _vPoison.erase(_viPoison);
		}
		else
		{
			_viPoison++;
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
		else if (_vArrow[i].angle == 0)
		{
			_vArrow[i].arrowImage->setFrameY(0);
		}
	}
}

void arrow::animation2()
{
	for (int i = 0; i < _vPoison.size(); ++i)
	{
		if (_vPoison[i].angle == PI)
		{
			_vPoison[i].arrowImage->setFrameY(1);
		}
		else if (_vPoison[i].angle == 0)
		{
			_vPoison[i].arrowImage->setFrameY(0);
		}
	}
}

void arrow::removeArrow(int index)
{
	//_vArrow[index].arrowImage->release();
	//SAFE_DELETE(_vArrow[index].arrowImage);
	_vArrow.erase(_vArrow.begin() + index);
}

void arrow::removePoison(int index)
{
	_vPoison.erase(_vPoison.begin() + index);
}
