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

	animation();


}

void arrow::render(void)
{



}

void arrow::fire(float x, float y, float angle)
{
	if (_arrowMax < _vArrow.size() + 1)return;
	tagArrow arrow;
	ZeroMemory(&arrow, sizeof(tagArrow));
	arrow.arrowImage = new image;

	arrow.arrowImage->init("resource/foxPlayer/arrow.bmp", 192, 192, 1, 2, true, MAGENTA);

	arrow.angle = angle;
	arrow.x = arrow.fireX = x;
	arrow.y = arrow.fireY = y;
	arrow.speed = 12.f;

	arrow.rc = RectMakeCenter(arrow.x, arrow.y, arrow.arrowImage->getFrameWidth(), arrow.arrowImage->getFrameHeight());

	_vArrow.push_back(arrow);
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
			_viArrow->arrowImage->release();
			SAFE_DELETE(_viArrow->arrowImage);
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
		else if (_vArrow[i].angle == 0)
		{
			_vArrow[i].arrowImage->setFrameY(0);
		}
	}
}

void arrow::removeArrow(int index)
{
	_vArrow[index].arrowImage->release();
	SAFE_DELETE(_vArrow[index].arrowImage);
	_vArrow.erase(_vArrow.begin() + index);
}
