#include "stdafx.h"
#include "magic.h"

HRESULT magic::init()
{
	thunderInit();
	tornadoInit();
	nightMareInit();
	_angleChk = false;


	return S_OK;
}

void magic::release(void)
{
}

void magic::update(void)
{
	thunderImageMove();
}

void magic::render(void)
{

}


void magic::thunderInit()
{
	thunder._count = 0;
	thunder._index = 0;
	for (int i = 0; i < 5; i++)
	{
		thunder._img = IMAGEMANAGER->findImage("번개마법1");
		thunder._x = 0;
		thunder._y = 0;
		thunder._rc = RectMake(thunder._x, thunder._y, 96, 960);
		
		_vthunder.push_back(thunder);
	}
	
}

void magic::tornadoInit()
{
}

void magic::nightMareInit()
{
	nightMare._x = 0;
	nightMare._y = 0;
	nightMare._img = IMAGEMANAGER->findImage("나이트메어");
	nightMare._img2 = IMAGEMANAGER->findImage("나이트메어 그림자");
	thunder._rc = RectMake(nightMare._x, nightMare._y, 96, 960);
	nightMare._speed = 15.0f;
	nightMare._angle = PI / 2;

	_vnightMare.push_back(nightMare);
}

void magic::thunderImageMove()
{
	thunder._count++;
	if (thunder._count % 5 == 0)thunder._index++;
	for (int i = 0; i < 5; i++)
	{
		_vthunder[i]._img->setFrameX(thunder._index);
		if (thunder._index > 9)thunder._index = 0;
	}
}
void magic::setvthundwe(int a,int b)
{
	for (int i = 0; i < _vthunder.size(); i++)
	{
		_vthunder[i]._x = a + 256 * i;
		_vthunder[i]._y = b;
		_vthunder[i]._rc = RectMake(_vthunder[i]._x, _vthunder[i]._y,96,960);
	}
}



void magic::nightMove(float a, float b)
{
	_vnightMare[0]._x = a;
	_vnightMare[0]._y = b;
	_vnightMare[0]._rc = RectMake(_vnightMare[0]._x, _vnightMare[0]._y, 400, 400);
}

void magic::a()
{
	if (_vnightMare[0]._angle < PI / 2)
	{
		_angleChk = false;
	}
	else if (_vnightMare[0]._angle >(PI / 2) * 3)
	{
		_angleChk = true;
	}
	_vnightMare[0]._x += cosf(_vnightMare[0]._angle) * _vnightMare[0]._speed;
	_vnightMare[0]._y += -sinf(_vnightMare[0]._angle) * _vnightMare[0]._speed;

	if (_angleChk == false)_vnightMare[0]._angle += 0.1f;
	else if (_angleChk == true)_vnightMare[0]._angle -= 0.1f;
	
}


