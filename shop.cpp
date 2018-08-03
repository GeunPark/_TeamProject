#include "stdafx.h"
#include "shop.h"

HRESULT shop::init(void)
{
	_kindShop = false;				// 상점 종류 flase-> 업그레이드 상점, true -> 마법 상점
	_backImage._x = 100;
	_backImage._y = 100;
	_backImage._img = IMAGEMANAGER->findImage("기모띠");
	selectObjectInIt();
	return S_OK;
}

void shop::release(void)
{
}

void shop::update(void)
{
	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		if (!_kindShop)_kindShop = true;
		else if (_kindShop)_kindShop = false;
	}
	ItemList();
	frameImageMove();
	selectObject();
	if (!_kindShop)
	{
		
	}
	else if (_kindShop)
	{

	}

}

void shop::render()
{
	_backImage._img->render(getMemDC(), _backImage._x, _backImage._y);
	for (int i = 0; i < 3; i++)
	{
		_Item[i]._img->render(getMemDC(), _Item[i]._x, _Item[i]._y);
		if (!_kindShop)
		{
			_Item[2]._img->frameRender(getMemDC(), _Item[2]._x, _Item[2]._y);
		}
	}
	
	if(!_isSelect)_selectOj._img->render(getMemDC(), _selectOj._x, _selectOj._y);
	else if(_isSelect)_selectOj._img->frameRender(getMemDC(), _selectOj._x, _selectOj._y);

/////////////////////////////////////////////////////////////////////////////////////////////////////////
	char str[128];
	sprintf_s(str, "%04d     %d", _ptMouse.x, _ptMouse.y);
	TextOut(getMemDC(), 300, 200, str, strlen(str));
}



void shop::ItemList()
{
	for (int i = 0; i < 3; i++)
	{
		_Item[i]._x = 135;
		_Item[i]._y = 135 + i * 145;
		_Item[i]._rc = RectMake(_Item[i]._x, _Item[i]._y, 120, 120);
	}
	
	if (!_kindShop)
	{
		_Item[0]._img = IMAGEMANAGER->findImage("총알 추가");
		_Item[1]._img = IMAGEMANAGER->findImage("마나업그레이드1");
		_Item[2]._img = IMAGEMANAGER->findImage("HP증가");
	}
	else if (_kindShop)
	{
		_Item[0]._img = IMAGEMANAGER->findImage("불 마법");
		_Item[1]._img = IMAGEMANAGER->findImage("얼음 마법");
		_Item[2]._img = IMAGEMANAGER->findImage("번개 마법");
	}
}

void shop::frameImageMove()
{
	if (!_kindShop)
	{
		_Item[2]._count++;
		if (_Item[2]._count % 3 == 0)_Item[2]._index++;
		if (_Item[2]._index > 10)_Item[2]._index = 0;
		_Item[2]._img->setFrameX(_Item[2]._index);
	}
	if (_isSelect)
	{
		_selectOj._count++;
		_selectCount++;
		if (_selectOj._count % 5 == 0)_selectOj._index++;
		if (_selectOj._index > 1)_selectOj._index = 0;
		_selectOj._img->setFrameX(_selectOj._index);
		if (_selectCount > 60)
		{
			_selectCount = 0;
			_selectOj._count = 0;
			_selectOj._index = 0;
			_isSelect = false;
		}
	}

}

void shop::selectObjectInIt()
{
	_isSelect = false;
	_selectCount = 0;
	_selectNumber = 0;
	_selectOj._count = 0;
	_selectOj._index = 0;
}

void shop::selectObject()
{
	if (!_isSelect)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && _selectNumber < 3)
		{
			_selectNumber++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP) && _selectNumber > 0)
		{
			_selectNumber--;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			_isSelect = true;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (_selectNumber == i)
		{
			_selectOj._x = _Item[i]._x;
			_selectOj._y = _Item[i]._y;
		}
	}
	if (!_isSelect)_selectOj._img = IMAGEMANAGER->findImage("아이템 선택");
	else if(_isSelect)_selectOj._img = IMAGEMANAGER->findImage("선택함");

	_selectOj._rc = RectMake(_selectOj._x, _selectOj._y, 120, 120);
}
