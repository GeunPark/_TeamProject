#include "stdafx.h"
#include "itemManager.h"
#include "foxPlayer.h"
#include "enemyManager.h"


HRESULT itemManager::init(void)
{
	_itemFactory = new itemFactory;

	_healthLargePos[0].x = 500.f, _healthLargePos[0].y = 2600.f;

	for (int i = 0; i < 1; ++i)
	{
		item* _item = _itemFactory->createItem(HEALTH_LARGE);
		_item->setPosition(_healthLargePos[0].x, _healthLargePos[0].y);
		_vItem.push_back(_item);
	}
	enemyX = 0;
	enemyY = 0;
	gold = 0;
	silver = 0;
	bronze = 0;
	

	return S_OK;
}

void itemManager::release(void)
{
	SAFE_DELETE(_itemFactory);
}

void itemManager::update(void)
{
	this->dropCoin();


	// 필드아이템 //
	for (int i = 0; i < _vItem.size(); ++i)
	{
		_vItem[i]->update();

	}

	//골드
	for (int i = 0; i < _vCoinGold.size(); ++i)
	{
		_vCoinGold[i]->update();
	}
	
	//실버
	for (int i = 0; i < _vCoinSilver.size(); ++i)
	{
		_vCoinSilver[i]->update();
	}
	
	//브론즈
	for (int i = 0; i < _vCoinBronze.size(); ++i)
	{
		_vCoinBronze[i]->update();
	}
	

}

void itemManager::render()
{
	//필드아이템
	for (int i = 0; i < _vItem.size(); ++i)
	{
		_vItem[i]->getItemImage()->frameRender(getMemDC(), _vItem[i]->getRect().left - _player->getPlayerCam().left, _vItem[i]->getRect().top - _player->getPlayerCam().top, _vItem[i]->getItemImage()->getFrameX(), _vItem[i]->getItemImage()->getFrameY());
	}



	// 코인 //
	
	//골드
	for (int i = 0; i < _vCoinGold.size(); ++i)
	{
		_vCoinGold[i]->getItemImage()->frameRender(getMemDC(), _vCoinGold[i]->getRect().left - _player->getPlayerCam().left, _vCoinGold[i]->getRect().top - _player->getPlayerCam().top, _vCoinGold[i]->getItemImage()->getFrameX(), _vCoinGold[i]->getItemImage()->getFrameY());
	}
	
	//실버
	for (int i = 0; i < _vCoinSilver.size(); ++i)
	{
		_vCoinSilver[i]->getItemImage()->frameRender(getMemDC(), _vCoinSilver[i]->getRect().left - _player->getPlayerCam().left, _vCoinSilver[i]->getRect().top - _player->getPlayerCam().top, _vCoinSilver[i]->getItemImage()->getFrameX(), _vCoinSilver[i]->getItemImage()->getFrameY());
	}
	
	//브론즈
	for (int i = 0; i < _vCoinBronze.size(); ++i)
	{
		_vCoinBronze[i]->getItemImage()->frameRender(getMemDC(), _vCoinBronze[i]->getRect().left - _player->getPlayerCam().left, _vCoinBronze[i]->getRect().top - _player->getPlayerCam().top, _vCoinBronze[i]->getItemImage()->getFrameX(), _vCoinBronze[i]->getItemImage()->getFrameY());
	}


}


void itemManager::dropCoin()
{
	for (int i = 0; i < gold; ++i)
	{
		item* _goldCoin = _itemFactory->createItem(GOLD_COIN);
		_goldCoin->setPosition(enemyX, enemyY);
		_goldCoin->setAngle(_goldCoin->getAngle() + PI / 150);
		_vCoinGold.push_back(_goldCoin);
	}
	//은화
	for (int i = 0; i < silver; ++i)
	{
		item* _silverCoin = _itemFactory->createItem(SILVER_COIN);
		_silverCoin->setPosition(enemyX, enemyY);
		_vCoinSilver.push_back(_silverCoin);
	}
	//동화
	
	for (int i = 0; i < bronze; ++i)
	{
		item* _bronzeCoin = _itemFactory->createItem(BRONZE_COIN);
		_bronzeCoin->setPosition(enemyX, enemyY);
		_vCoinBronze.push_back(_bronzeCoin);
	}

	gold = 0;
	silver = 0;
	bronze = 0;
}

