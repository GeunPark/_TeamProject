#include "stdafx.h"
#include "arrow.h"

HRESULT arrow::init(int arrowMax, float range)
{
	count = 0;
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

void arrow::fire2(float x, float y, float angle)
{
	if (_arrowMax < _vPoison.size() + 1)return;
	tagArrow2 poisonArrow;
	ZeroMemory(&poisonArrow, sizeof(tagArrow2));

	poisonArrow.angle = angle;
	poisonArrow.x = poisonArrow.fireX = x;
	poisonArrow.y = poisonArrow.fireY = y;
	poisonArrow.speed = 12.f;

	poisonArrow.arrowImage = IMAGEMANAGER->findImage("Poison");

	poisonArrow.rc = RectMakeCenter(poisonArrow.x, poisonArrow.y, poisonArrow.arrowImage->getFrameWidth(), poisonArrow.arrowImage->getFrameHeight()); 

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

	
	for(int i=0;i< _vPoison.size();i++)
	{	
		_vPoison[i].x += cosf(PI / 180 * _vPoison[i].angle)*_vPoison[i].speed;
		_vPoison[i].y += -sinf(PI / 180 * _vPoison[i].angle)*_vPoison[i].speed;
		
		_vPoison[i].rc = RectMakeCenter(_vPoison[i].x, _vPoison[i].y, _vPoison[i].arrowImage->getFrameWidth(), _vPoison[i].arrowImage->getFrameHeight());
		_vPoison[i].angle += 15.f;
		
		count++;
		if (count >= 3)
		{
			break;
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
		//if(_vPoison[i].angle)
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
