#include "stdafx.h"
#include "itemManager.h"
#include "foxPlayer.h"
#include "enemyManager.h"


HRESULT itemManager::init(void)
{
	_itemFactory = new itemFactory;

	EFFECTMANAGER->addEffect("아이템이펙트", "아이템이펙트", 0.2f, 10);



	_healthLargePos[0].x = 2475.f, _healthLargePos[0].y = 2200.f;
	_healthLargePos[1].x = 5500.f, _healthLargePos[1].y = 2050.f;
	_healthLargePos[2].x = 5600.f, _healthLargePos[2].y = 2100.f;
	_healthLargePos[3].x = 9450.f, _healthLargePos[3].y = 2115.f;
	_healthLargePos[4].x = 9550.f, _healthLargePos[4].y = 2115.f;

	_healthSmallPos[0].x = 2375.f, _healthSmallPos[0].y = 2250.f;
	_healthSmallPos[1].x = 2575.f, _healthSmallPos[1].y = 2250.f;
	_healthSmallPos[2].x = 6990.f, _healthSmallPos[2].y = 1220.f;
	_healthSmallPos[3].x = 6940.f, _healthSmallPos[3].y = 1150.f;
	_healthSmallPos[4].x = 7040.f, _healthSmallPos[4].y = 1150.f;

	_manaBigPos[0].x = 2900.f, _manaBigPos[0].y = 2150.f;
	_manaBigPos[1].x = 3550.f, _manaBigPos[1].y = 2000.f;
	_manaBigPos[2].x = 8150.f, _manaBigPos[2].y = 1675.f;
	_manaBigPos[3].x = 8150.f, _manaBigPos[3].y = 1575.f;
	_manaBigPos[4].x = 8150.f, _manaBigPos[4].y = 1475.f;

	_manaSmallPos[0].x = 6965.f, _manaSmallPos[0].y = 2050.f;
	_manaSmallPos[1].x = 6965.f, _manaSmallPos[1].y = 2120.f;
	_manaSmallPos[2].x = 9950.f, _manaSmallPos[2].y = 1720.f;
	_manaSmallPos[3].x = 9715.f, _manaSmallPos[3].y = 1630.f;
	_manaSmallPos[4].x = 9520.f, _manaSmallPos[4].y = 1475.f;

	_itemBoxPos[0].x = 3550.f; _itemBoxPos[0].y = 2155.f;
	_itemBoxPos[1].x = 7750.f; _itemBoxPos[1].y = 2195.f;
	_itemBoxPos[2].x = 9050.f; _itemBoxPos[2].y = 1490.f;
	_itemBoxPos[3].x = 6990.f; _itemBoxPos[3].y = 2200.f;

//	_itemBoxPos[3].x = 8440.f; _itemBoxPos[3].y = 2395.f;





	for (int i = 0; i < MAX_HEALTHLARGE; ++i)
	{
		item* _item = _itemFactory->createItem(HEALTH_LARGE);
		_item->setPosition(_healthLargePos[i].x, _healthLargePos[i].y);
		_vItem.push_back(_item);
	}
	for (int i = 0; i < MAX_HEALTHSMALL; ++i)
	{
		item* _item = _itemFactory->createItem(HEALTH_SMALL);
		_item->setPosition(_healthSmallPos[i].x, _healthSmallPos[i].y);
		_vItem.push_back(_item);
	}
	for (int i = 0; i < MAX_MANABIG; ++i)
	{
		item* _item = _itemFactory->createItem(MANA_BIG);
		_item->setPosition(_manaBigPos[i].x, _manaBigPos[i].y);
		_vItem.push_back(_item);
	}
	for (int i = 0; i < MAX_MANASMALL; ++i)
	{
		item* _item = _itemFactory->createItem(MANA_SMALL);
		_item->setPosition(_manaSmallPos[i].x, _manaSmallPos[i].y);
		_vItem.push_back(_item);
	}

	for (int i = 0; i < MAX_ITEMBOX; ++i)
	{
		item* _item = _itemFactory->createItem(ITEM_BOX);
		_item->setPosition(_itemBoxPos[i].x, _itemBoxPos[i].y);
		_vItemBox.push_back(_item);
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
	//SAFE_DELETE(_itemFactory);
	_vItem.clear();
	_vCoinBronze.clear();
	_vCoinSilver.clear();
	_vCoinGold.clear();
	_vItemBox.clear();
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

	// 아이템박스 //
	for (int i = 0; i < _vItemBox.size(); ++i)
	{
		_vItemBox[i]->update();

	}
	

	//플레이어와 아이템 충돌
	for (int i = 0; i < _vItem.size(); ++i)
	{
		RECT _rct;

		if (IntersectRect(&_rct, &_vItem[i]->getRc(), &_player->getCollisionRc()))
		{

			/*
				HEALTH_LARGE,
				HEALTH_SMALL,
				MANA_BIG,
				MANA_SMALL,
			*/

			_vItem[i]->setIsActive(false);

			if (_vItem[i]->getItemType() == HEALTH_LARGE)
			{
				_player->setHp(_player->getHp() + 30);
			}
			else if(_vItem[i]->getItemType() == HEALTH_SMALL)
			{
				_player->setHp(_player->getHp() + 5);
			}
			else if (_vItem[i]->getItemType() == MANA_BIG)
			{
				_player->setMana(_player->getMana() + 50);
			}
			else if (_vItem[i]->getItemType() == MANA_SMALL)
			{
				_player->setMana(_player->getMana() + 20);
			}



		}
	}
	


	//플레이어 공격렉트와 아이템상자 충돌
	
		for (int i = 0; i < _vItemBox.size(); ++i)
		{
			RECT _rct;
			//if (!_vItemBox[i]->getIsActive())
			//{
			if (IntersectRect(&_rct, &_vItemBox[i]->getRc(), &_player->getAttRc()) && _player->getIsAtt() && !_player->getIsTouch())
				{
					//_vEnemy[i]->setState(ENEMY_DEAD);
					//_iMG->setCoin(_vEnemy[i]->getX(), _vEnemy[i]->getY(), _vEnemy[i]->getGold(), _vEnemy[i]->getSilver(), _vEnemy[i]->getBronze());
					_vItemBox[i]->setIsActive(true);
					_player->setIsTouch(true);
					
					if (i == 3 )
					{
						_eMG->setGhost(_vItemBox[i]->getX(), _vItemBox[i]->getY(),1);
						
					}
					else if (i == 2)
					{
						enemyX = _vItemBox[i]->getX();
						enemyY = _vItemBox[i]->getY();
						gold = 10;

					}
					else
					{
						enemyX = _vItemBox[i]->getX();
						enemyY = _vItemBox[i]->getY();
						gold = 6;
						silver = 4;
						bronze = 2;
					}
		
					break;

					//			_vPlantFrog[i]->setEnemyAction(E_DEAD);
					//			_player->setIsAttack(false);
					//			_iMG->setCoin(_vPlantFrog[i]->getX(), _vPlantFrog[i]->getY(), _vPlantFrog[i]->getGold(), _vPlantFrog[i]->getSilver(), _vPlantFrog[i]->getBronze());
					//			_vPlantFrog.erase(_vPlantFrog.begin() + i);
				}
			//}
		}

	//플레이어와 코인충돌
		for (int i = 0; i < _vCoinGold.size(); ++i)
		{
			RECT _rct;

			if (IntersectRect(&_rct, &_vCoinGold[i]->getRc(), &_player->getCollisionRc()))
			{
				_player->setGold(_player->getGold() + 10);
				EFFECTMANAGER->play("아이템이펙트", _vCoinGold[i]->getX(), _vCoinGold[i]->getY());
				SOUNDMANAGER->play("코인획득사운드", 2.0f);

				_vCoinGold.erase(_vCoinGold.begin() + i);
			}
		}
		for (int i = 0; i < _vCoinSilver.size(); ++i)
		{
			RECT _rct;

			if (IntersectRect(&_rct, &_vCoinSilver[i]->getRc(), &_player->getCollisionRc()))
			{
				_player->setGold(_player->getGold() + 5);
				EFFECTMANAGER->play("아이템이펙트", _vCoinSilver[i]->getX(), _vCoinSilver[i]->getY());
				SOUNDMANAGER->play("코인획득사운드", 2.0f);

				_vCoinSilver.erase(_vCoinSilver.begin() + i);
			}
		}
		for (int i = 0; i < _vCoinBronze.size(); ++i)
		{
			RECT _rct;

			if (IntersectRect(&_rct, &_vCoinBronze[i]->getRc(), &_player->getCollisionRc()))
			{
				_player->setGold(_player->getGold() + 1);
				EFFECTMANAGER->play("아이템이펙트", _vCoinBronze[i]->getX(), _vCoinBronze[i]->getY());
				SOUNDMANAGER->play("코인획득사운드", 2.0f);

				_vCoinBronze.erase(_vCoinBronze.begin() + i);
			}
		}

		for (int i = 0; i < _vItem.size(); ++i)
		{
			if (!_vItem[i]->getIsActive())
			{
				EFFECTMANAGER->play("아이템이펙트", _vItem[i]->getX(), _vItem[i]->getY());
				SOUNDMANAGER->play("마나획득사운드", 2.0f);

				_vItem.erase(_vItem.begin() + i);

			}

		}


		this->pixelCollisionAng(_vCoinBronze);
		this->pixelCollisionAng(_vCoinGold);
		this->pixelCollisionAng(_vCoinSilver);

}

void itemManager::render()
{
	//필드아이템
	for (int i = 0; i < _vItem.size(); ++i)
	{
		_vItem[i]->getItemImage()->frameRender(getMemDC(), _vItem[i]->getRc().left - _player->getPlayerCam().left, _vItem[i]->getRc().top - _player->getPlayerCam().top, _vItem[i]->getItemImage()->getFrameX(), _vItem[i]->getItemImage()->getFrameY());
	}

	// 아이템박스 //
	for (int i = 0; i < _vItemBox.size(); ++i)
	{

		_vItemBox[i]->getItemImage()->frameRender(getMemDC(), _vItemBox[i]->getRc().left - _player->getPlayerCam().left, _vItemBox[i]->getRc().top - _player->getPlayerCam().top,_vItemBox[i]->getIndex(), _vItemBox[i]->getItemImage()->getFrameY());

	}

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		for (int i = 0; i < _vItem.size(); ++i)
		{
			Rectangle(getMemDC(), _vItem[i]->getRc().left - _player->getPlayerCam().left, _vItem[i]->getRc().top - _player->getPlayerCam().top, _vItem[i]->getRc().right - _player->getPlayerCam().left, _vItem[i]->getRc().bottom - _player->getPlayerCam().top );

		}
		for (int i = 0; i < _vItemBox.size(); ++i)
		{
			Rectangle(getMemDC(), _vItemBox[i]->getRc().left - _player->getPlayerCam().left, _vItemBox[i]->getRc().top - _player->getPlayerCam().top, _vItemBox[i]->getRc().right - _player->getPlayerCam().left, _vItemBox[i]->getRc().bottom - _player->getPlayerCam().top);
		}
	}

	// 코인 //
	
	//골드
	for (int i = 0; i < _vCoinGold.size(); ++i)
	{
		_vCoinGold[i]->getItemImage()->frameRender(getMemDC(), _vCoinGold[i]->getRc().left - _player->getPlayerCam().left, _vCoinGold[i]->getRc().top - _player->getPlayerCam().top, _vCoinGold[i]->getItemImage()->getFrameX(), _vCoinGold[i]->getItemImage()->getFrameY());
	}
	
	//실버
	for (int i = 0; i < _vCoinSilver.size(); ++i)
	{
		_vCoinSilver[i]->getItemImage()->frameRender(getMemDC(), _vCoinSilver[i]->getRc().left - _player->getPlayerCam().left, _vCoinSilver[i]->getRc().top - _player->getPlayerCam().top, _vCoinSilver[i]->getItemImage()->getFrameX(), _vCoinSilver[i]->getItemImage()->getFrameY());
	}
	
	//브론즈
	for (int i = 0; i < _vCoinBronze.size(); ++i)
	{
		_vCoinBronze[i]->getItemImage()->frameRender(getMemDC(), _vCoinBronze[i]->getRc().left - _player->getPlayerCam().left, _vCoinBronze[i]->getRc().top - _player->getPlayerCam().top, _vCoinBronze[i]->getItemImage()->getFrameX(), _vCoinBronze[i]->getItemImage()->getFrameY());
	}


}


void itemManager::dropCoin()
{
	for (int i = 0; i < gold; ++i)
	{
		item* _goldCoin = _itemFactory->createItem(GOLD_COIN);
		_goldCoin->setPosition(enemyX, enemyY);
		_goldCoin->setAngle(_goldCoin->getAngle() + PI / 150 * i);
		_vCoinGold.push_back(_goldCoin);
	}
	//은화
	for (int i = 0; i < silver; ++i)
	{
		item* _silverCoin = _itemFactory->createItem(SILVER_COIN);
		_silverCoin->setPosition(enemyX, enemyY);
		_silverCoin->setAngle(_silverCoin->getAngle() + PI / 150 * i);
		_vCoinSilver.push_back(_silverCoin);
	}
	//동화
	
	for (int i = 0; i < bronze; ++i)
	{
		item* _bronzeCoin = _itemFactory->createItem(BRONZE_COIN);
		_bronzeCoin->setPosition(enemyX, enemyY);
		_bronzeCoin->setAngle(_bronzeCoin->getAngle() + PI / 150 * i);
		_vCoinBronze.push_back(_bronzeCoin);
	}

	gold = 0;
	silver = 0;
	bronze = 0;
}

void itemManager::pixelCollisionAng(vector<item*> _tempVector)
{
	if (_player->getAng())
	{
		//vector<item*> _tempVector;

		for (int i = 0; i < _tempVector.size(); ++i)
		{
			for (int j = _tempVector[i]->getRc().bottom - 4; j <  _tempVector[i]->getRc().bottom; j += 2)
			{
				COLORREF color = GetPixel(_tempVector[i]->getPixelImage()->getMemDC(), _tempVector[i]->getX(), j);
				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if ((r == 255 && g == 255 && b == 0))
				{
					_tempVector[i]->setY(j - _tempVector[i]->getItemImage()->getFrameHeight()/2);
					_tempVector[i]->setGravity(0);

					if (_tempVector[i]->getSpeed() > 0.5f)
					{
						_tempVector[i]->setSpeed(_tempVector[i]->getSpeed() / 2.0f);
					}
					else
					{
						_tempVector[i]->setSpeed(0);
					}
					break;
				}
			}


		}
	
	}
	else
	{
		for (int i = 0; i < _tempVector.size(); ++i)
		{
			for (int j = _tempVector[i]->getRc().bottom - 30; j < _tempVector[i]->getRc().bottom +30; j += 2)
			{
				COLORREF color = GetPixel(_tempVector[i]->getPixelImage()->getMemDC(), _tempVector[i]->getX(), j);
				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if ((r == 255 && g == 255 && b == 0))
				{
					_tempVector[i]->setY(_tempVector[i]->getY() + 0.05f);
					_tempVector[i]->setX(_tempVector[i]->getX() + _tempVector[i]->getAngle()*0.0001f);
					_tempVector[i]->setAngle(_tempVector[i]->getAngle() + 0.5f);

					if (_tempVector[i]->getY() > 2900)
					{
						_tempVector.erase(_tempVector.begin()+i);
					}
					//break;
				}
			}


		}

	}


}

