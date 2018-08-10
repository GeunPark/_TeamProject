#include "stdafx.h"
#include "arrow.h"

HRESULT arrow::init(int arrowMax, float range)
{
	_arrowMax = arrowMax;
	_range = range;


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

void arrow::fire2(float x, float y, float angle, float angle2, float angle3)
{
	if (_arrowMax < _vArrow.size() + 1)return;
	tagArrow2 poisonArrow;
	ZeroMemory(&poisonArrow, sizeof(tagArrow2));

	poisonArrow.angle = angle;
	poisonArrow.angle2 = angle2;
	poisonArrow.angle3 = angle3;
	poisonArrow.x = poisonArrow.fireX = x;
	poisonArrow.y = poisonArrow.fireY = y;
	poisonArrow.speed = 12.f;

	poisonArrow.arrowImage = IMAGEMANAGER->findImage("Poison");
	poisonArrow.arrowImage2 = IMAGEMANAGER->findImage("Poison");
	poisonArrow.arrowImage3 = IMAGEMANAGER->findImage("Poison");

	poisonArrow.rc = RectMakeCenter(poisonArrow.x, poisonArrow.y, poisonArrow.arrowImage->getFrameWidth(), poisonArrow.arrowImage->getFrameHeight());
	poisonArrow.rc2 = RectMakeCenter(poisonArrow.x, poisonArrow.y, poisonArrow.arrowImage2->getFrameWidth(), poisonArrow.arrowImage2->getFrameHeight());
	poisonArrow.rc3 = RectMakeCenter(poisonArrow.x, poisonArrow.y, poisonArrow.arrowImage3->getFrameWidth(), poisonArrow.arrowImage3->getFrameHeight());

	_vPoison.push_back(poisonArrow);
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
		_viPoison->y += -sinf(_viPoison->angle)*_viPoison->speed;

		_viPoison->x += cosf(_viPoison->angle2)*_viPoison->speed;
		_viPoison->y += -sinf(_viPoison->angle2)*_viPoison->speed;

		_viPoison->x += cosf(_viPoison->angle3)*_viPoison->speed;
		_viPoison->y += -sinf(_viPoison->angle3)*_viPoison->speed;
		
		_viPoison->rc = RectMakeCenter(_viPoison->x, _viPoison->y, _viPoison->arrowImage->getFrameWidth(), _viPoison->arrowImage->getFrameHeight());
		_viPoison->rc2 = RectMakeCenter(_viPoison->x, _viPoison->y, _viPoison->arrowImage2->getFrameWidth(), _viPoison->arrowImage2->getFrameHeight());
		_viPoison->rc3 = RectMakeCenter(_viPoison->x, _viPoison->y, _viPoison->arrowImage3->getFrameWidth(), _viPoison->arrowImage3->getFrameHeight());
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
		if (_vPoison[i].angle == (PI || PI / 3 || PI / 4))
		{
			_vPoison[i].arrowImage->setFrameY(1);
			_vPoison[i].arrowImage2->setFrameY(1);
			_vPoison[i].arrowImage3->setFrameY(1);
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
