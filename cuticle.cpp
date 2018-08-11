#include "stdafx.h"
#include "cuticle.h"

HRESULT cuticle::init(float range)
{

	_range = range;

	return S_OK;
}

void cuticle::release(void)
{


}

void cuticle::update(void)
{
	this->move();


}

void cuticle::render(void)
{

	
}

void cuticle::fire(float x, float y, float cuticleMax)
{
	
		for (int i = 0; i < cuticleMax; i++)
		{
			tagCuticle cuticle;

			ZeroMemory(&cuticle, sizeof(tagCuticle));
			cuticle.cuticleImage = IMAGEMANAGER->findImage("Cuticle");
			cuticle.speed = 20.f;
			cuticle.angle = RND->getFloat(10) * ((i * 30) + fireNum * 3);
			cuticle.x = cuticle.fireX = x;
			cuticle.y = cuticle.fireY = y;

			_vCuticle.push_back(cuticle);
			fireNum++;
		}
	
	
		for (int i = 0; i < cuticleMax; i++)
		{
			tagCuticle cuticle;

			ZeroMemory(&cuticle, sizeof(tagCuticle));
			cuticle.cuticleImage = IMAGEMANAGER->findImage("Cuticle");
			cuticle.speed = 13.f;
			cuticle.angle = RND->getFloat(10) * (( i* 15) + fireNum * 3);
			cuticle.x = cuticle.fireX = x;
			cuticle.y = cuticle.fireY = y;

			_vCuticle.push_back(cuticle);
			fireNum++;
		}
}

void cuticle::move()
{
	for (int i = 0; i < _vCuticle.size(); i++)
	{
		_vCuticle[i].angle += 0.25f;
		_vCuticle[i].x += cosf(_vCuticle[i].angle)*_vCuticle[i].speed;
		_vCuticle[i].y += -sinf(_vCuticle[i].angle)*_vCuticle[i].speed;
		_vCuticle[i].rc = RectMakeCenter(_vCuticle[i].x, _vCuticle[i].y, _vCuticle[i].cuticleImage->getWidth(), _vCuticle[i].cuticleImage->getHeight());
		if (getDistance(_vCuticle[i].x, _vCuticle[i].y, _vCuticle[i].fireX, _vCuticle[i].fireY)> _range)
		{
			_vCuticle.erase(_vCuticle.begin() + i);
		}
	}
}

void cuticle::removeCuticle(int index)
{
	

}
