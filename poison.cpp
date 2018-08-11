#include "stdafx.h"
#include "poison.h"

HRESULT poison::init(float range)
{

	_range = range;
	bCount = 0;
	count = index = 0;
	_isFire = false;
	return S_OK;
}

void poison::release(void)
{
}

void poison::update(void)
{
	this->move();
	this->frameMove();
}

void poison::render(void)
{
	

	
}

void poison::fire(float x, float y, int maxPoison, float angle)
{
		/*bCount = 0;
		for (int i = 0; i < maxPoison; ++i)
		{
			tagPoison poison;
			ZeroMemory(&poison, sizeof(tagPoison));
			poison.poisonImage = IMAGEMANAGER->findImage("Poison");
			poison.speed = 12.f;
			if (angle == PI)
			{
				poison.angle = i * 15 * PI;
			}
			else if (angle == 0)
			{
				poison.angle = i * 15;
			}
			poison.x = poison.fireX = x;
			poison.y = poison.fireY = y;
			poison.isFire = true;

			_vPoison.push_back(poison);
			bCount++;
			if (bCount >= 3)
			{
				
				break;
			}
			PI / 180 * ((i * 30) + fireNum * 3);
		}*/
	for (int i = 0; i < maxPoison; i++)
	{
		tagPoison poison;

		ZeroMemory(&poison, sizeof(tagPoison));
		poison.poisonImage = IMAGEMANAGER->findImage("Poison");
		poison.speed = 12.f;
		poison.angle = angle;
		poison.x = poison.fireX = x;
		poison.y = poison.fireY = y;

		_vPoison.push_back(poison);
	}




}

void poison::move()
{
	/*for (int i = 0; i < _vPoison.size(); ++i)
	{
		if (_vPoison[i].isFire)
		{
			_vPoison[i].x += cosf(_vPoison[i].angle)*_vPoison[i].speed;
			_vPoison[i].y += -sinf(_vPoison[i].angle)*_vPoison[i].speed;
			_vPoison[i].rc = RectMakeCenter(_vPoison[i].x, _vPoison[i].y, _vPoison[i].poisonImage->getFrameWidth(), _vPoison[i].poisonImage->getFrameHeight());
			if (getDistance(_vPoison[i].x, _vPoison[i].y, _vPoison[i].fireX, _vPoison[i].fireY) > _range)
			{
				_vPoison[i].isFire = false;
				_vPoison.erase(_vPoison.begin() + i);
				--i;
			}
		}
	}*/

	for (int i = 0; i < _vPoison.size(); i++)
	{
		_vPoison[i].angle += 0.25f;
		_vPoison[i].x += cosf(_vPoison[i].angle)*_vPoison[i].speed;
		_vPoison[i].y += -sinf(_vPoison[i].angle)*_vPoison[i].speed;
		_vPoison[i].rc = RectMakeCenter(_vPoison[i].x, _vPoison[i].y, _vPoison[i].poisonImage->getWidth(), _vPoison[i].poisonImage->getHeight());
		if (getDistance(_vPoison[i].x, _vPoison[i].y, _vPoison[i].fireX, _vPoison[i].fireY)> _range)
		{
			_vPoison.erase(_vPoison.begin() + i);
		}
	}

}

void poison::frameMove()
{
	for (int i = 0; i < _vPoison.size(); ++i)
	{
		if (_vPoison[i].angle == PI)
		{
			++count;
			_vPoison[i].poisonImage->setFrameY(1);
			if (count % 3 == 0)
			{
				index--;
				if (index < 0)
				{
					index = 7;
				}
				_vPoison[i].poisonImage->setFrameX(index);
			}
		}
		if (_vPoison[i].angle == 0)
		{
			++count;
			_vPoison[i].poisonImage->setFrameY(0);
			if (count % 3 == 0)
			{
				index++;
				if (index > 7)
				{
					index = 0;
				}
				_vPoison[i].poisonImage->setFrameX(index);
			}
		}
	}


}

void poison::removeCuticle(int index)
{
}
