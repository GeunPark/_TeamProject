#include "stdafx.h"
#include "shop.h"
#include "foxPlayer.h"

HRESULT shop::init(void)
{
	_kindShop = MAGIC;				// 상점 종류 flase-> 업그레이드 상점, true -> 마법 상점
	_backImage._x = 100;
	_backImage._y = 100;
	_backImage._img = IMAGEMANAGER->findImage("기모띠");
	selectObjectInIt();
	for (int i = 0; i < 4; i++)
	{
		_priceNum[i]._img = IMAGEMANAGER->findImage("숫자");
	}
	return S_OK;
}

void shop::release(void)
{
}

void shop::update(void)
{
	ItemList();
	
	frameImageMove();
	selectObject();
	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		if (_kindShop == UPGRADE)_kindShop = MAGIC;
		else if (_kindShop == MAGIC)_kindShop = UPGRADE;
	}

}

void shop::render()
{
	_backImage._img->render(getMemDC(), _backImage._x, _backImage._y);
	for (int i = 0; i < 3; i++)
	{
		_Item[i]._img->render(getMemDC(), _Item[i]._x, _Item[i]._y);	
	}
	for (int i = 0; i < 4; i++)
	{
		_priceNum[i]._img->frameRender(getMemDC(), _priceNum[i]._x, _priceNum[i]._y, num[i], 0);
		//number[i]->frameRender(getMemDC(), 1100 + (24 * i), 50, num[i], 0);
	}

	_ItemInfo[_selectNumber]._img->render(getMemDC(), _ItemInfo[_selectNumber]._x, _ItemInfo[_selectNumber]._y);
	//_ItemInfo[1]._img->render(getMemDC(), _ItemInfo[1]._x, _ItemInfo[1]._y);
	
	if(!_isSelect)_selectOj._img->render(getMemDC(), _selectOj._x, _selectOj._y);
	else if(_isSelect)_selectOj._img->frameRender(getMemDC(), _selectOj._x, _selectOj._y);

/////////////////////////////////////////////////////////////////////////////////////////////////////////
	
}



void shop::ItemList()
{
	for (int i = 0; i < 3; i++)
	{
		_Item[i]._x = 135;
		_Item[i]._y = 135 + i * 145;
		_ItemInfo[i]._x = 300;
		_ItemInfo[i]._y = 135;

		_Item[i]._rc = RectMake(_Item[i]._x, _Item[i]._y, 120, 120);
	}
	if (_kindShop == UPGRADE)
	{
		_Item[0]._img = IMAGEMANAGER->findImage("총알 추가");
		_Item[1]._img = IMAGEMANAGER->findImage("마나업그레이드1");
		_Item[2]._img = IMAGEMANAGER->findImage("하트");

		_Item[0].price = 1000;
		_Item[1].price = 150;
		_Item[2].price = 200;

		_ItemInfo[0]._img = IMAGEMANAGER->findImage("초록화살 설명");
		_ItemInfo[1]._img = IMAGEMANAGER->findImage("마나 업그레이드 설명");
		_ItemInfo[2]._img = IMAGEMANAGER->findImage("하트 설명");
	}
	else if (MAGIC)
	{
		_Item[0]._img = IMAGEMANAGER->findImage("불 마법");
		_Item[1]._img = IMAGEMANAGER->findImage("얼음 마법");
		_Item[2]._img = IMAGEMANAGER->findImage("번개 마법");

		_ItemInfo[0]._img = IMAGEMANAGER->findImage("불 마법 정보");
		_ItemInfo[1]._img = IMAGEMANAGER->findImage("얼음 마법 정보");
		_ItemInfo[2]._img = IMAGEMANAGER->findImage("번개 마법 정보");

		_Item[0].price = 30;
		_Item[1].price = 30;
		_Item[2].price = 30;

	}
	for (int i = 0; i < 4; i++)
	{
		_priceNum[i]._img = IMAGEMANAGER->findImage("숫자");
		_priceNum[i]._x = 300 + i * 24;
		_priceNum[i]._y = 450;
	}
}

void shop::frameImageMove()
{
	if (_isSelect)
	{
		_selectOj._count++;
		_selectCount++;
		if (_selectOj._count % 5 == 0)_selectOj._index++;
		if (_selectOj._index > 1)_selectOj._index = 0;
		_selectOj._img->setFrameX(_selectOj._index);
		if (_selectCount > 60)
		{
			_isSelect = false;
			_selectCount = 0;
			_selectOj._count = 0;
			_selectOj._index = 0;
			
		}
	}
	
	num[0] = _Item[_selectNumber].price / 1000;
	num[1] = (_Item[_selectNumber].price % 1000) / 100;
	num[2] = (_Item[_selectNumber].price % 100) / 10;
	num[3] = _Item[_selectNumber].price % 10;

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
		if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD5) && _selectNumber < 2)
		{
			_selectNumber++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD8) && _selectNumber > 0)
		{
			_selectNumber--;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			_isSelect = true;
			if (_player->getGold() > _Item[_selectNumber].price )
			{
				_player->setGold(_player->getGold() - _Item[_selectNumber].price);
				ItemSell();
			}
		}
	}

	_selectOj._x = _Item[_selectNumber]._x;
	_selectOj._y = _Item[_selectNumber]._y;

	if (!_isSelect)_selectOj._img = IMAGEMANAGER->findImage("아이템 선택");
	else if(_isSelect)_selectOj._img = IMAGEMANAGER->findImage("선택함");
	
	_selectOj._rc = RectMake(_selectOj._x, _selectOj._y, 120, 120);
}

void shop::ItemSell()
{
	if (_kindShop == UPGRADE)
	{
		/*_Item[0]._img = IMAGEMANAGER->findImage("총알 추가");
		_Item[1]._img = IMAGEMANAGER->findImage("마나업그레이드1");
		_Item[2]._img = IMAGEMANAGER->findImage("하트");*/
		if (_selectNumber == 1)
		{
			_player->setMaxMAna(_player->getMaxMana() + 30);
		}
		else if (_selectNumber == 2 && _player->getMaxHp() < 100)
		{
			_player->setMaxHp(_player->getMaxHp() + 10);
			_player->setHp(_player->getMaxHp());
		}
	}
	else if (_kindShop == MAGIC)
	{

	}
}

void shop::setPlayerManager(foxPlayer * player)
{
	_player = player;

}
