#include "stdafx.h"
#include "enemyManager.h"
#include "foxPlayer.h"
#include "bossStage.h"

HRESULT enemyManager::init(void)
{
	
	// 맵데이터 가져오기
	//this->setMapData(_mapData);
	
	
	_factory = new enemyFactory;

	_ghostBullet = new ghostBullet;
	_ghostBullet->init("유령총알", 1, 1000);

	

	


	//LEFT
	EFFECTMANAGER->addEffect("잠자리죽음L", "잠자리deadL", 0.2f, 10);
	EFFECTMANAGER->addEffect("나무인간죽음L", "나무인간deadL", 0.2f, 10);
	EFFECTMANAGER->addEffect("버그죽음L", "버그deadL", 0.2f, 10);
	EFFECTMANAGER->addEffect("통나무죽음L", "통나무deadL", 0.2f, 10);
	EFFECTMANAGER->addEffect("꼼장어죽음L", "꼼장어deadL", 0.2f, 10);
	EFFECTMANAGER->addEffect("두꺼비죽음L", "두꺼비deadL", 0.2f, 10);

	//RIGHT
	EFFECTMANAGER->addEffect("잠자리죽음R", "잠자리deadR", 0.2f, 10);
	EFFECTMANAGER->addEffect("나무인간죽음R", "나무인간deadR", 0.2f, 10);
	EFFECTMANAGER->addEffect("버그죽음R", "버그deadR", 0.2f, 10);
	EFFECTMANAGER->addEffect("통나무죽음R", "통나무deadR", 0.2f, 10);
	EFFECTMANAGER->addEffect("꼼장어죽음R", "꼼장어deadR", 0.2f, 10);
	EFFECTMANAGER->addEffect("두꺼비죽음R", "두꺼비deadR", 0.2f, 10);

	//_beeBullet = new beeBullet;
	//_beeBullet->init(500);


	//INIDATA로 바꿀것
	//일단은

	//잠자리
	_dragonFlyPos[0].x = 800.f, _dragonFlyPos[0].y = 2300.f;
	_dragonFlyPos[1].x = 900.f, _dragonFlyPos[1].y = 2250.f;
	_dragonFlyPos[2].x = 1950.f, _dragonFlyPos[2].y = 2250.f;
	_dragonFlyPos[3].x = 2050.f, _dragonFlyPos[3].y = 2300.f;
	_dragonFlyPos[4].x = 2900.f, _dragonFlyPos[4].y = 2300.f;
	_dragonFlyPos[5].x = 5050.f, _dragonFlyPos[5].y = 1950.f;
	_dragonFlyPos[6].x = 6475.f, _dragonFlyPos[6].y = 1875.f;


	//나무인간
	_vineManPos[0].x = 1600.f; _vineManPos[0].y = 2280.f;
	_vineManPos[1].x = 3600.f; _vineManPos[1].y = 2350.f;
	_vineManPos[2].x = 3900.f; _vineManPos[2].y = 2350.f;
	_vineManPos[3].x = 5900.f; _vineManPos[3].y = 2350.f;
	_vineManPos[4].x = 6800.f; _vineManPos[4].y = 2350.f;


	//통나무
	_treeManPos[0].x = 7000.f; _treeManPos[0].y = 1785.f;
	_treeManPos[1].x = 7700.f; _treeManPos[1].y = 1785.f;
	//_treeManPos[2].x = 300.f; _treeManPos[2].y = 2200.f;
	//_treeManPos[3].x = 900.f; _treeManPos[3].y = 2200.f;

	//버그
	_bugPos[0].x = 7450.f; _bugPos[0].y = 1770.f;
	_bugPos[1].x = 7500.f; _bugPos[1].y = 1770.f;
	_bugPos[2].x = 9450.f; _bugPos[2].y = 2160.f;
	_bugPos[3].x = 9550.f; _bugPos[3].y = 2160.f;


	//두꺼비
	_plantFrogPos[0].x = 4300.f; _plantFrogPos[0].y = 2350.f;
	_plantFrogPos[1].x = 7500.f; _plantFrogPos[1].y = 2350.f;
	//_plantFrogPos[2].x = 130.f; _plantFrogPos[2].y = 2400.f;
	//_plantFrogPos[3].x = 190.f; _plantFrogPos[3].y = 2400.f;

	//꼼장어
	_electriceelPos[0].x = 3240.f; _electriceelPos[0].y = 2470.f;
	_electriceelPos[1].x = 6230.f; _electriceelPos[1].y = 2470.f;
	//_electriceelPos[2].x = 130.f; _electriceelPos[2].y = 2300.f;
	//_electriceelPos[3].x = 190.f; _electriceelPos[3].y = 2300.f;

	_itemX, _itemY, _num = 0;

	for (int i = 0; i < MAX_DRAGONFLY; i++)
	{
		enemy* _enemy = _factory->createEnemy(DRAGONFLY);
		_enemy->setPosition(_dragonFlyPos[i].x, _dragonFlyPos[i].y);

		_vEnemy.push_back(_enemy);
	}
	for (int i = 0; i < MAX_VINEMAN; i++)
	{
		enemy* _enemy = _factory->createEnemy(VINEMAN);
		_enemy->setPosition(_vineManPos[i].x, _vineManPos[i].y);

		_vEnemy.push_back(_enemy);
	}
	for (int i = 0; i < MAX_TREEMAN; i++)
	{
		enemy* _enemy = _factory->createEnemy(TREEMAN);
		_enemy->setPosition(_treeManPos[i].x, _treeManPos[i].y);
		_enemy->setCount(i * 50);
		_vEnemy.push_back(_enemy);
	}
	for (int i = 0; i < MAX_BUG; i++)
	{
		enemy* _enemy = _factory->createEnemy(BUG);
		_enemy->setPosition(_bugPos[i].x, _bugPos[i].y);
		_enemy->setCount(i * 50);
		_vEnemy.push_back(_enemy);
	}
	for (int i = 0; i < MAX_PLANTFROG; i++)
	{
		enemy* _enemy = _factory->createEnemy(PLANTFROG);
		_enemy->setPosition(_plantFrogPos[i].x, _plantFrogPos[i].y);

		_vEnemy.push_back(_enemy);
	}
	for (int i = 0; i < MAX_ELECTRICEEL; i++)
	{
		enemy* _enemy = _factory->createEnemy(ELECTRICEEL);
		_enemy->setPosition(_electriceelPos[i].x, _electriceelPos[i].y);

		_vEnemy.push_back(_enemy);
	}

	isAttack = 0;
	_tongue = IMAGEMANAGER->findImage("두꺼비tongue");		// 츄로올로보롭ㅇ고퍼ㅏㅁㄴㅇㅍㄷ리ㅓㅇ겨피ㅣ냐ㅡㅍ먀ㅓㄹㄹㄹㄷㄴㅇㅍㅁ러ㅑㅣㅓㅜㄹㄹ 환상~~! (납득이)

	return S_OK;
}

void enemyManager::release(void)
{
	SAFE_DELETE(_factory);
	_vEnemy.clear();
	
}

void enemyManager::update(void)
{

	this->sensorCollision();

	for (int i = 0; i < _vEnemy.size(); i++)
	{
	

		_vEnemy[i]->update();
	}

	this->appearGhost();


	for (int i = 0; i < _vGhost.size(); i++)
	{
		//if (_vGhost[i]->getX() > _player->getX())
		//{
		//	_vGhost[i]->setIsLeft(true);
		//}
		//else
		//{
		//	_vGhost[i]->setIsLeft(false);
		//}

		_vGhost[i]->update();
	}


	//for (int i = 0; i < _vGhost.size(); i++)
	//{
	//	if (!_vGhost[i]->getIsActived())
	//	{
	//		_vGhost.erase(_vGhost.begin() + i);
	//	}
	//
	//}



	for (int i = 0; i < _vGhost.size(); ++i)
	{
		if (_vGhost[i]->getIsFire())
		{
			_ghostBullet->fire(_vGhost[i]->getX(), _vGhost[i]->getY(), _player->getX(), _player->getY());
			_vGhost[i]->setIsFire(false);
		}
	}

	if (_ghostBullet->getBulletFire())
	{
		_ghostBullet->update();

	}



	//_beeBullet->fire(_bee->getX(), _bee->getY(), 10);
	//_beeBullet->update();
	


	//에너미 충돌처리

	//플레이어와 에너미 충돌
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		RECT _rct;

		if (IntersectRect(&_rct, &_vEnemy[i]->getRc(), &_player->getAttRc()))
		{
			//_vEnemy[i]->setState(ENEMY_DEAD);
			_vEnemy[i]->setIsActived(false);

			_iMG->setCoin(_vEnemy[i]->getX(), _vEnemy[i]->getY(), _vEnemy[i]->getGold(), _vEnemy[i]->getSilver(), _vEnemy[i]->getBronze());
			//_vEnemy.erase(_vEnemy.begin() + i);

			//			_vPlantFrog[i]->setEnemyAction(E_DEAD);
			//			_player->setIsAttack(false);
			//			_iMG->setCoin(_vPlantFrog[i]->getX(), _vPlantFrog[i]->getY(), _vPlantFrog[i]->getGold(), _vPlantFrog[i]->getSilver(), _vPlantFrog[i]->getBronze());
			//			_vPlantFrog.erase(_vPlantFrog.begin() + i);
		}
	}
	//공격렉트 충돌 한개 더 만들엇엉~ㅎㅎ 김호뛰
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		RECT _rct;

		if (IntersectRect(&_rct, &_vEnemy[i]->getRc(), &_player->getAttRc2()))
		{
			_vEnemy[i]->setIsActived(false);
			_iMG->setCoin(_vEnemy[i]->getX(), _vEnemy[i]->getY(), _vEnemy[i]->getGold(), _vEnemy[i]->getSilver(), _vEnemy[i]->getBronze());
			//_vEnemy.erase(_vEnemy.begin() + i);
		}
	}
	//아직 총알이 없음 attRc랑 충돌이나 만들어놓자!
	//플레이어의 총알과 에너미 충돌
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		for (int j = 0; j < _player->getArrow()->getVArrow().size(); ++j)
		{
			RECT _rct;

			if (IntersectRect(&_rct, &_vEnemy[i]->getCollisionRc(), &_player->getArrow()->getVArrow()[j].rc))
			{
				//_vEnemy[i]->setState(ENEMY_DEAD);
				_iMG->setCoin(_vEnemy[i]->getX(), _vEnemy[i]->getY(), _vEnemy[i]->getGold(), _vEnemy[i]->getSilver(), _vEnemy[i]->getBronze());

				_vEnemy[i]->setIsActived(false);
				//_vEnemy.erase(_vEnemy.begin() + i);

				//선수씨~ 여기다가 저의 흔적을 남기고가요~ㅎㅎ
				_player->removeArrow(j);	//적과 화살 충돌시 화살 지워줌

				//j--;
				//			_vPlantFrog[i]->setEnemyAction(E_DEAD);
				//			_player->setIsAttack(false);
				//			_iMG->setCoin(_vPlantFrog[i]->getX(), _vPlantFrog[i]->getY(), _vPlantFrog[i]->getGold(), _vPlantFrog[i]->getSilver(), _vPlantFrog[i]->getBronze());
				//			_vPlantFrog.erase(_vPlantFrog.begin() + i);
			}
		}

	}

	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		if (_vEnemy[i]->getType() == ELECTRICEEL)
		{
			if (_player->getAng())
			{
				if (_vEnemy[i]->getState() == ENEMY_SPAWN)
				{
					_vEnemy[i]->setAng(false);
				}
				else
				{
					for (int j = _vEnemy[i]->getRc().bottom - 50; j < _vEnemy[i]->getRc().bottom - 45; j++)
					{
						COLORREF color = GetPixel(_player->getBgPixel()->getMemDC(), _vEnemy[i]->getX(), j);
						int r = GetRValue(color);
						int g = GetGValue(color);
						int b = GetBValue(color);

						if ((r == 255 && g == 255 && b == 0))
						{
							_vEnemy[i]->setIsActived(false);
						}

					}
				}
			}
			else
			{
				_vEnemy[i]->setAng(true);

			}
			
		}

	}






	this->beAttackedEffect();





}

void enemyManager::render(void)
{
	for (int i = 0; i < _vEnemy.size(); i++)
	{

		if (KEYMANAGER->isToggleKey(VK_F1))
		{
			Rectangle(getMemDC(), _vEnemy[i]->getSensorRc().left - _player->getPlayerCam().left, _vEnemy[i]->getSensorRc().top - _player->getPlayerCam().top, _vEnemy[i]->getSensorRc().right - _player->getPlayerCam().left, _vEnemy[i]->getSensorRc().bottom - _player->getPlayerCam().top);
			Rectangle(getMemDC(), _vEnemy[i]->getCollisionRc().left - _player->getPlayerCam().left, _vEnemy[i]->getCollisionRc().top - _player->getPlayerCam().top, _vEnemy[i]->getCollisionRc().right - _player->getPlayerCam().left, _vEnemy[i]->getCollisionRc().bottom - _player->getPlayerCam().top);
			Rectangle(getMemDC(), _vEnemy[i]->getAttRc().left - _player->getPlayerCam().left, _vEnemy[i]->getAttRc().top - _player->getPlayerCam().top, _vEnemy[i]->getAttRc().right - _player->getPlayerCam().left, _vEnemy[i]->getAttRc().bottom - _player->getPlayerCam().top);

		}

		if (!_vEnemy[i]->getIsActived()) continue;
		_vEnemy[i]->getBodyImage()->frameRender(getMemDC(), _vEnemy[i]->getRc().left - _player->getPlayerCam().left, _vEnemy[i]->getRc().top - _player->getPlayerCam().top, _vEnemy[i]->getIndexX(), _vEnemy[i]->getIndexY());
		//카메라 메니져 대신 렌더넣기 

		if (_vEnemy[i]->getType() == PLANTFROG)
		{
			if (_vEnemy[i]->getIsTongue())
			{
				_tongue->frameRender(getMemDC(), _vEnemy[i]->getAttRc().left - _player->getPlayerCam().left, _vEnemy[i]->getAttRc().top - _player->getPlayerCam().top, _tongue->getFrameX(), _vEnemy[i]->getIndexY());
			}
		}

		//switch (_vEnemy[i]->getType())
		//{
		//case SOLDIER:
		//	//dynamic_cast<soldier*>(_vEnemy[i])->getGunImage()->frameRender(getMemDC(), _vEnemy[i]->getX() - CAMERAMANAGER->getCamera().left, _vEnemy[i]->getY() - CAMERAMANAGER->getCamera().top);
		//	//카메라 메니져 대신 렌더넣기 
		//
		//	//((soldier*)_vEnemy[i])->getGunImage()->frameRender(getMemDC(), _vEnemy[i]->getX() - CAMERAMANAGER->getCamera().left, _vEnemy[i]->getY() - CAMERAMANAGER->getCamera().top);
		//	break;
		//default:
		//	//누구냐 넌??
		//	break;
		//}
	}
	for (int i = 0; i < _vGhost.size(); i++)
	{
		_vGhost[i]->getBodyImage()->frameRender(getMemDC(), _vGhost[i]->getRc().left - _player->getPlayerCam().left, _vGhost[i]->getRc().top - _player->getPlayerCam().top, _vGhost[i]->getBodyImage()->getFrameX(), _vGhost[i]->getBodyImage()->getFrameY());

		if (_ghostBullet->getBulletFire())
		{
			_ghostBullet->getBulletImage()->frameRender(getMemDC(), _ghostBullet->getBulletRc().left - _player->getPlayerCam().left, _ghostBullet->getBulletRc().top - _player->getPlayerCam().top, _ghostBullet->getBulletImage()->getFrameX(), _ghostBullet->getBulletImage()->getFrameY());

		}
	}


	//for (int i = 0; i < _beeBullet->getVBullet().size(); ++i)
	//{
	//	if (_beeBullet->getVBullet()[i].fire)
	//	{
	//
	//		_beeBullet->getVBullet()[i].bulletImage->frameRender(getMemDC(), _beeBullet->getVBullet()[i].rc.left - _player->getPlayerCam().left, _beeBullet->getVBullet()[i].rc.top - _player->getPlayerCam().top, _beeBullet->getIndex(), 0);
	//
	//	}
	//
	//}
	//char str[64];
	//for (int i = 0; i < _vEnemy.size(); i++)
	//{
	//	sprintf(str, "%d", _vEnemy[i]->getIsLeft());
	//	TextOut(getMemDC(), 200, 400+i*50, str, strlen(str));
	//}
}



void enemyManager::beAttackedEffect()
{
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		if (!_vEnemy[i]->getIsActived())
		{
			_iMG->setCoin(_vEnemy[i]->getX(), _vEnemy[i]->getY(), _vEnemy[i]->getGold(), _vEnemy[i]->getSilver(), _vEnemy[i]->getBronze());


			if (_vEnemy[i]->getIndexY() == 0)
			{
				switch (_vEnemy[i]->getType())
				{
				case DRAGONFLY:
					EFFECTMANAGER->play("잠자리죽음L", _vEnemy[i]->getX(), _vEnemy[i]->getY());// - _player->getPlayerCam().left, _vEnemy[i]->getY() - _player->getPlayerCam().top);

					break;

				case VINEMAN:
					EFFECTMANAGER->play("나무인간죽음L", _vEnemy[i]->getX(), _vEnemy[i]->getY());// - _player->getPlayerCam().left, _vEnemy[i]->getY() - _player->getPlayerCam().top);


					break;

				case BUG:

					EFFECTMANAGER->play("버그죽음L", _vEnemy[i]->getX(), _vEnemy[i]->getY());// - _player->getPlayerCam().left, _vEnemy[i]->getY() - _player->getPlayerCam().top);

					break;

				case TREEMAN:
					EFFECTMANAGER->play("통나무죽음L", _vEnemy[i]->getX(), _vEnemy[i]->getY());// - _player->getPlayerCam().left, _vEnemy[i]->getY() - _player->getPlayerCam().top);


					break;

				case ELECTRICEEL:
					EFFECTMANAGER->play("꼼장어죽음L", _vEnemy[i]->getX(), _vEnemy[i]->getY());// - _player->getPlayerCam().left, _vEnemy[i]->getY() - _player->getPlayerCam().top);


					break;

				case PLANTFROG:
					EFFECTMANAGER->play("두꺼비죽음L", _vEnemy[i]->getX(), _vEnemy[i]->getY());// - _player->getPlayerCam().left, _vEnemy[i]->getY() - _player->getPlayerCam().top);


					break;

				default:

					break;
				}
			}
			else if (_vEnemy[i]->getIndexY() == 1)
			{
				switch (_vEnemy[i]->getType())
				{
				case DRAGONFLY:
					EFFECTMANAGER->play("잠자리죽음R", _vEnemy[i]->getX(), _vEnemy[i]->getY());// - _player->getPlayerCam().left, _vEnemy[i]->getY() - _player->getPlayerCam().top);

					break;

				case VINEMAN:
					EFFECTMANAGER->play("나무인간죽음R", _vEnemy[i]->getX(), _vEnemy[i]->getY());// - _player->getPlayerCam().left, _vEnemy[i]->getY() - _player->getPlayerCam().top);


					break;

				case BUG:

					EFFECTMANAGER->play("버그죽음R", _vEnemy[i]->getX(), _vEnemy[i]->getY());// - _player->getPlayerCam().left, _vEnemy[i]->getY() - _player->getPlayerCam().top);

					break;

				case TREEMAN:
					EFFECTMANAGER->play("통나무죽음R", _vEnemy[i]->getX(), _vEnemy[i]->getY());// - _player->getPlayerCam().left, _vEnemy[i]->getY() - _player->getPlayerCam().top);


					break;

				case ELECTRICEEL:
					EFFECTMANAGER->play("꼼장어죽음R", _vEnemy[i]->getX(), _vEnemy[i]->getY());// - _player->getPlayerCam().left, _vEnemy[i]->getY() - _player->getPlayerCam().top);


					break;

				case PLANTFROG:
					EFFECTMANAGER->play("두꺼비죽음R", _vEnemy[i]->getX(), _vEnemy[i]->getY());// - _player->getPlayerCam().left, _vEnemy[i]->getY() - _player->getPlayerCam().top);


					break;

				default:

					break;
				}
			}

			_vEnemy.erase(_vEnemy.begin() + i);
		}
	}
}

void enemyManager::appearGhost()
{
	for (int i = 0; i < _num; ++i)
	{
		enemy* _ghost = _factory->createEnemy(GHOST);
		_ghost->setPosition(_itemX, _itemY-50);
		_ghost->setIndexX(0);
		_vGhost.push_back(_ghost);
	}

	_itemX = 0;
	_itemY = 0;
	_num = 0;

}

void enemyManager::sensorCollision()
{
	RECT rct;
	for (int i = 0; i < _vEnemy.size(); i++)
	{
		if (_vEnemy[i]->getType() == VINEMAN)
		{
			if (IntersectRect(&rct, &_player->getCollisionRc(), &_vEnemy[i]->getSensorRc()))
			{
				_vEnemy[i]->setState(ENEMY_ATTACK);
				if (_vEnemy[i]->getX() > _player->getX())
				{
					_vEnemy[i]->setIsLeft(true);
				}
				else
				{
					_vEnemy[i]->setIsLeft(false);
				}
			}
			else
			{
				_vEnemy[i]->setState(ENEMY_WALK);
			}
		}
		else if (_vEnemy[i]->getType() == PLANTFROG && (_vEnemy[i]->getIndexX() == 0 || _vEnemy[i]->getIndexX() == 6) && _vEnemy[i]->getGravity() ==0)
		{
			if (IntersectRect(&rct, &_player->getCollisionRc(), &_vEnemy[i]->getSensorRc()))
			{
				_vEnemy[i]->setState(ENEMY_ATTACK);

				if (_vEnemy[i]->getX() > _player->getX())
				{
					_vEnemy[i]->setIsLeft(true);
					//_vEnemy[i]->setIndexX(0);
				}
				else
				{
					_vEnemy[i]->setIsLeft(false);
					//_vEnemy[i]->setIndexX(6);

				}
			}
			
		}



	}


}





//#include "foxPlayer.h"
//#include "itemManager.h"
//
//HRESULT enemyManager::init(void)
//{
//	//미니언 생성
//
//	this->setMinion();
//
//	_count = 0;
//	//_dragonFly = new dragonfly;
//
//	_bpx = IMAGEMANAGER->findImage("스테이지1 픽셀");
//
//	//총알클래스 생성 및 초기화
//	//_bullet = new bullet;
//	//_bullet->init("bullet", 15, 600);
//
//	//플레이어 클래스 생성 및 초기화 (메인게임의 플레이어와 아래 플레이어는 다른 클래스다)
//	//_player = new player;
//	//_player->init();
//	//
//
//	return S_OK;
//}
//
//void enemyManager::release(void)
//{
//	//총알클래스 해제
//	//_bullet->release();
//	//SAFE_DELETE(_bullet);
//}
//
//void enemyManager::update(void)
//{
//	//총알클래스 업데이트
//	//_bullet->update();
//
//	//벡터에 담긴 미니언들 업데이트
//
//	_viDragonFly = _vDragonFly.begin();
//	for (_viDragonFly; _viDragonFly != _vDragonFly.end(); ++_viDragonFly)
//	{
//		(*_viDragonFly)->update();
//	}
//
//	_viVineMan = _vVineMan.begin();
//	for (_viVineMan; _viVineMan != _vVineMan.end(); ++_viVineMan)
//	{
//		(*_viVineMan)->update();
//	}
//
//	_viBug = _vBug.begin();
//	for (_viBug; _viBug != _vBug.end(); ++_viBug)
//	{
//		(*_viBug)->update();
//	}
//
//	_viTreeMan = _vTreeMan.begin();
//	for (_viTreeMan; _viTreeMan != _vTreeMan.end(); ++_viTreeMan)
//	{
//		(*_viTreeMan)->update();
//	}
//
//	_viPlantFrog = _vPlantFrog.begin();
//	for (_viPlantFrog; _viPlantFrog != _vPlantFrog.end(); ++_viPlantFrog)
//	{
//		(*_viPlantFrog)->update();
//	}
//
//	_viElectriceel = _vElectriceel.begin();
//	for (_viElectriceel; _viElectriceel != _vElectriceel.end(); ++_viElectriceel)
//	{
//		(*_viElectriceel)->update();
//	}
//
//	//this->sensorCollision();
//	this->pixelCollision();
//	this->collision();
//	//this->collision(_vDragonFly);
//	//this->collision(_vVineMan);
//	//this->collision(_vBug);
//	//this->collision(_vElectriceel);
//	//this->collision(_vTreeMan);
//	//this->collision(_vPlantFrog);
//
//	//this->removeEnemy(_vDragonFly);
//	//this->removeEnemy(_vVineMan);
//	//this->removeEnemy(_vBug);
//	//this->removeEnemy(_vElectriceel);
//	//this->removeEnemy(_vTreeMan);
//	//this->removeEnemy(_vPlantFrog);
//}
//
//void enemyManager::render(float FX, float FY)
//{
//	//총알클래스 렌더
//	//_bullet->render();
//	//벡터에 담긴 미니언들 렌더
//	//for (int i = 0; i < _vMinion.size(); i++)
//	//{
//	//	_vMinion[i]->render();
//	//}
//	_viDragonFly = _vDragonFly.begin();
//	for (_viDragonFly; _viDragonFly != _vDragonFly.end(); ++_viDragonFly)
//	{
//		(*_viDragonFly)->render(FX, FY);
//	}
//
//	_viVineMan = _vVineMan.begin();
//	for (_viVineMan; _viVineMan != _vVineMan.end(); ++_viVineMan)
//	{
//		(*_viVineMan)->render(FX, FY);
//	}
//
//	_viBug = _vBug.begin();
//	for (_viBug; _viBug != _vBug.end(); ++_viBug)
//	{
//		(*_viBug)->render(FX, FY);
//	}
//
//	_viTreeMan = _vTreeMan.begin();
//	for (_viTreeMan; _viTreeMan != _vTreeMan.end(); ++_viTreeMan)
//	{
//		(*_viTreeMan)->render(FX, FY);
//	}
//
//	_viPlantFrog = _vPlantFrog.begin();
//	for (_viPlantFrog; _viPlantFrog != _vPlantFrog.end(); ++_viPlantFrog)
//	{
//		(*_viPlantFrog)->render(FX, FY);
//	}
//
//	_viElectriceel = _vElectriceel.begin();
//	for (_viElectriceel; _viElectriceel != _vElectriceel.end(); ++_viElectriceel)
//	{
//		(*_viElectriceel)->render(FX, FY);
//	}
//
//}
//
//void enemyManager::setMinion()
//{
//
//	//잠자리
//	for (int i = 0; i < 2; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "잠자리spawn", "잠자리move", "null", "잠자리dead", PointMake(1400, 2250 + i * 100), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//	for (int i = 0; i < 2; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "잠자리spawn", "잠자리move", "null", "잠자리dead", PointMake(3750, 2100 + i * 200), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//	for (int i = 0; i < 2; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "잠자리spawn", "잠자리move", "null", "잠자리dead", PointMake(5230 + i * 200, 2250 + i * 200), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//	for (int i = 0; i < 2; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "잠자리spawn", "잠자리move", "null", "잠자리dead", PointMake(6200 + i * 200, 2500 ), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//	for (int i = 0; i < 2; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "잠자리spawn", "잠자리move", "null", "잠자리dead", PointMake(8250 , 2000 + i * 200), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//	for (int i = 0; i < 2; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "잠자리spawn", "잠자리move", "null", "잠자리dead", PointMake(10850, 1800 + i * 200), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//
//	for (int i = 0; i < 2; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "잠자리spawn", "잠자리move", "null", "잠자리dead", PointMake(12050 + i * 200, 1250 + i * 100), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//
//	for (int i = 0; i < 6; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "잠자리spawn", "잠자리move", "null", "잠자리dead", PointMake(12600 + i * 100, 850 - i * 100), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//
//
//	for (int i = 0; i < 2; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "잠자리spawn", "잠자리move", "null", "잠자리dead", PointMake(16580, 2200 + i * 200), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//	for (int i = 0; i < 2; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "잠자리spawn", "잠자리move", "null", "잠자리dead", PointMake(17000, 1800 + i * 300), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//	for (int i = 0; i < 2; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "잠자리spawn", "잠자리move", "null", "잠자리dead", PointMake(18080, 1750 + i * 200), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//
//	//나무인간
//	for (int i = 0; i < 1; ++i)
//	{
//		vineman* _vineman = new vineman;
//		_vineman->init("null", "나무인간spawn", "나무인간move", "나무인간attack", "잠자리dead", PointMake(1650, 2390 + i * 200), 0, 100 * i, 0, 1, 1);
//		_vVineMan.push_back(_vineman);
//	}
//	for (int i = 0; i < 2; ++i)
//	{
//		vineman* _vineman = new vineman;
//		_vineman->init("null", "나무인간spawn", "나무인간move", "나무인간attack", "잠자리dead", PointMake(7400 + i * 500, 2570), 0, 100 * i, 0, 1, 1);
//		_vVineMan.push_back(_vineman);
//	}
//	for (int i = 0; i < 2; ++i)
//	{
//		vineman* _vineman = new vineman;
//		_vineman->init("null", "나무인간spawn", "나무인간move", "나무인간attack", "잠자리dead", PointMake(12300 + i * 100, 2570), 0, 100 * i, 0, 1, 1);
//		_vVineMan.push_back(_vineman);
//	}
//
//	//버그 (벌레)
//	for (int i = 0; i < 2; ++i)
//	{
//		bug* _bug = new bug;
//		_bug->init("null", "버그move", "버그move", "null", "잠자리dead", PointMake(13250 + i * 200, 2530 ), 0, 100 * i, 0, 1, 1);
//		_vBug.push_back(_bug);
//	}
//
//	for (int i = 0; i < 2; ++i)
//	{
//		bug* _bug = new bug;
//		_bug->init("null", "버그move", "버그move", "null", "잠자리dead", PointMake(15500 + i * 300, 2240), 0, 100 * i, 0, 1, 1);
//		_vBug.push_back(_bug);
//	}
//
//	//통나무
//	for (int i = 0; i < 2; ++i)
//	{
//		treeman* _treeman = new treeman;
//		_treeman->init("null", "통나무move", "통나무move", "null", "잠자리dead", PointMake(3270 + i * 450, 2520), 0, 100 * i, 3, 0, 0);
//		_vTreeMan.push_back(_treeman);
//	}
//	for (int i = 0; i < 1; ++i)
//	{
//		treeman* _treeman = new treeman;
//		_treeman->init("null", "통나무move", "통나무move", "null", "잠자리dead", PointMake(9800 + i * 450, 2040), 0, 100 * i, 3, 0, 0);
//		_vTreeMan.push_back(_treeman);
//	}
//	for (int i = 0; i < 2; ++i)
//	{
//		treeman* _treeman = new treeman;
//		_treeman->init("null", "통나무move", "통나무move", "null", "잠자리dead", PointMake(15200 + i * 780, 2530), 0, 100 * i, 3, 0, 0);
//		_vTreeMan.push_back(_treeman);
//	}
//	for (int i = 0; i < 1; ++i)
//	{
//		treeman* _treeman = new treeman;
//		_treeman->init("null", "통나무move", "통나무move", "null", "잠자리dead", PointMake(18200 + i * 450, 2530), 0, 100 * i, 3, 0, 0);
//		_vTreeMan.push_back(_treeman);
//	}
//
//	//두꺼비
//	for (int i = 0; i < 1; ++i)
//	{
//		plantfrog* _plantfrog = new plantfrog;
//		_plantfrog->init("null", "두꺼비spawn", "두꺼비move", "두꺼비attack", "잠자리dead", PointMake(3900 + 300 * i, 2550), 0, 150 * i, 1, 1, 0);
//		_vPlantFrog.push_back(_plantfrog);
//	}
//	for (int i = 0; i < 1; ++i)
//	{
//		plantfrog* _plantfrog = new plantfrog;
//		_plantfrog->init("null", "두꺼비spawn", "두꺼비move", "두꺼비attack", "잠자리dead", PointMake(13135 + 300 * i, 2080), 0, 150 * i, 1, 1, 0);
//		_vPlantFrog.push_back(_plantfrog);
//	}
//
//	//꼼장어
//	for (int i = 0; i < 2; ++i)
//	{
//		electriceel* _electriceel = new electriceel;
//		_electriceel->init("null", "꼼장어move", "꼼장어move", "null", "잠자리dead", PointMake(11870 + i * 1070, 2630), i * 2, 150 * i, 0, 1, 1);
//		_vElectriceel.push_back(_electriceel);
//
//	}
//
//	//for (int i = 0; i < 4; ++i)
//	//{
//	//	dragonfly* drangonFly = new dragonfly;
//	//	drangonFly->init("null", "null", "잠자리", "null", "null", PointMake(300, 100 + i * 100), 0, 50 * i);
//	//	_vMinion.push_back(drangonFly);
//	//}
//}
//
////void enemyManager::minionBulletFire()
////{
////	_viMinion = _vMinion.begin();
////	for (_viMinion; _viMinion != _vMinion.end(); ++_viMinion)
////	{
////		if ((*_viMinion)->bulletCountFire())
////		{
////			RECT rc = (*_viMinion)->getRect();
////			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom + 30, -PI_2, 3.0f);
////		}
////	}
////}
////
////void enemyManager::removeMinion(int index)
////{
////	_vMinion.erase(_vMinion.begin() + index);
////}
////
//////충돌처리 (적총알과 플레이어)
////void enemyManager::collision(vector<enemy*> _temp)
////{
////	vector<enemy*> temp;
////	temp = _temp;
////
////	for (int i = 0; i < temp.size(); i++)
////	{
////		RECT rct;
////		if (IntersectRect(&rct, &temp[i]->getColliRect(), &_player->getAttRect()) && temp[i]->getEnemyAction() != E_SPAWN)
////		{
////			temp[i]->setEnemyAction(E_DEAD);
////		}
////	}
////}
////
////void enemyManager::sensorCollision()
////{
////	for (int i = 0; i < _vVineMan.size(); i++)
////	{
////		RECT rct;
////		if (IntersectRect(&rct, &_vVineMan[i]->getSensorRect(), &_player->getColliRect()) && _vVineMan[i]->getEnemyAction() != E_SPAWN)
////		{
////
////			if (_player->getX() > _vVineMan[i]->getX())
////			{
////				_vVineMan[i]->setEnemyState(E_RIGHT);
////
////			}
////			else
////				_vVineMan[i]->setEnemyState(E_LEFT);
////
////			_vVineMan[i]->setEnemyAction(E_ATTACK);
////
////		}
////	}
////
////	for (int i = 0; i < _vPlantFrog.size(); i++)
////	{
////		RECT rct;
////		if (IntersectRect(&rct, &_vPlantFrog[i]->getSensorRect(), &_player->getColliRect()) && _vPlantFrog[i]->getEnemyAction() != E_SPAWN && _vPlantFrog[i]->getGravity() == 0)
////		{
////			_vPlantFrog[i]->setEnemyAction(E_ATTACK);
////
////			if (_player->getX() > _vPlantFrog[i]->getX())
////			{
////				_vPlantFrog[i]->setEnemyState(E_RIGHT);
////
////			}
////			else
////				_vPlantFrog[i]->setEnemyState(E_LEFT);
////		}
////	}
////
////}
//
//void enemyManager::collision()
//{
//	for (int i = 0; i < _vDragonFly.size(); i++)
//	{
//		RECT rct;
//		if (IntersectRect(&rct, &_vDragonFly[i]->getColliRect(), &_player->getAttRc()) && _vDragonFly[i]->getEnemyAction() != E_SPAWN)
//		{
//	
//			_vDragonFly[i]->setEnemyAction(E_DEAD);
//			_player->setIsAttack(false);
//			_iMG->setCoin(_vDragonFly[i]->getX(), _vDragonFly[i]->getY(), _vDragonFly[i]->getGold(), _vDragonFly[i]->getSilver(), _vDragonFly[i]->getBronze());
//			_vDragonFly.erase(_vDragonFly.begin() + i);
//	
//			//_vBug[i]->setY(-1000);
//			//--i;
//		}
//	}
//
//	for (int i = 0; i < _vVineMan.size(); i++)
//	{
//		RECT rct;
//		if (IntersectRect(&rct, &_vVineMan[i]->getColliRect(), &_player->getAttRc()) && _vVineMan[i]->getEnemyAction() != E_SPAWN)
//		{
//
//			_vVineMan[i]->setEnemyAction(E_DEAD);
//			_player->setIsAttack(false);
//			_iMG->setCoin(_vVineMan[i]->getX(), _vVineMan[i]->getY(), _vVineMan[i]->getGold(), _vVineMan[i]->getSilver(), _vVineMan[i]->getBronze());
//			_vVineMan.erase(_vVineMan.begin() + i);
//
//			//_vBug[i]->setY(-1000);
//			//--i;
//		}
//	}
//
//	for (int i = 0; i < _vBug.size(); i++)
//	{
//		RECT rct;
//		if (IntersectRect(&rct, &_vBug[i]->getColliRect(), &_player->getAttRc()) && _vBug[i]->getEnemyAction() != E_SPAWN)
//		{
//
//			_vBug[i]->setEnemyAction(E_DEAD);
//			_player->setIsAttack(false);
//			_iMG->setCoin(_vBug[i]->getX(), _vBug[i]->getY(), _vBug[i]->getGold(), _vBug[i]->getSilver(), _vBug[i]->getBronze());
//			_vBug.erase(_vBug.begin() + i);
//
//			//_vBug[i]->setY(-1000);
//			//--i;
//		}
//	}
//
//	for (int i = 0; i < _vTreeMan.size(); i++)
//	{
//		RECT rct;
//		if (IntersectRect(&rct, &_vTreeMan[i]->getColliRect(), &_player->getAttRc()) && _vTreeMan[i]->getEnemyAction() != E_SPAWN)
//		{
//
//			_vTreeMan[i]->setEnemyAction(E_DEAD);
//			_player->setIsAttack(false);
//			_iMG->setCoin(_vTreeMan[i]->getX(), _vTreeMan[i]->getY(), _vTreeMan[i]->getGold(), _vTreeMan[i]->getSilver(), _vTreeMan[i]->getBronze());
//			_vTreeMan.erase(_vTreeMan.begin() + i);
//
//			//_vBug[i]->setY(-1000);
//			//--i;
//		}
//	}
//
//	for (int i = 0; i < _vElectriceel.size(); i++)
//	{
//		RECT rct;
//		if (IntersectRect(&rct, &_vElectriceel[i]->getColliRect(), &_player->getAttRc()) && _vElectriceel[i]->getEnemyAction() != E_SPAWN)
//		{
//
//			_vElectriceel[i]->setEnemyAction(E_DEAD);
//			_player->setIsAttack(false);
//			_iMG->setCoin(_vElectriceel[i]->getX(), _vElectriceel[i]->getY(), _vElectriceel[i]->getGold(), _vElectriceel[i]->getSilver(), _vElectriceel[i]->getBronze());
//			_vElectriceel.erase(_vElectriceel.begin() + i);
//
//			//_vBug[i]->setY(-1000);
//			//--i;
//		}
//	}
//
//	for (int i = 0; i < _vPlantFrog.size(); i++)
//	{
//		RECT rct;
//		if (IntersectRect(&rct, &_vPlantFrog[i]->getColliRect(), &_player->getAttRc()) && _vPlantFrog[i]->getEnemyAction() != E_SPAWN)
//		{
//
//			_vPlantFrog[i]->setEnemyAction(E_DEAD);
//			_player->setIsAttack(false);
//			_iMG->setCoin(_vPlantFrog[i]->getX(), _vPlantFrog[i]->getY(), _vPlantFrog[i]->getGold(), _vPlantFrog[i]->getSilver(), _vPlantFrog[i]->getBronze());
//			_vPlantFrog.erase(_vPlantFrog.begin() + i);
//
//			//_vBug[i]->setY(-1000);
//			//--i;
//		}
//	}
//
//
//
//}
//
//void enemyManager::pixelCollision()
//{
//	for (int k = 0; k < _vPlantFrog.size(); ++k)
//	{
//		for (int i = _vPlantFrog[k]->getColliRect().left; i < _vPlantFrog[k]->getColliRect().right; i += 2)
//		{
//			for (int j = _vPlantFrog[k]->getRect().bottom - 10; j <_vPlantFrog[k]->getRect().bottom; j += _vPlantFrog[k]->getEnemyImage(E_MOVE)->getFrameHeight() / 2)  // _rc.bottom - 10; j < _rc.bottom; j++)
//			{
//				COLORREF color = GetPixel(_bpx->getMemDC(), i, j);
//				int r = GetRValue(color);
//				int g = GetGValue(color);
//				int b = GetBValue(color);
//
//				if ((r == 0 && g == 255 && b == 255) && _vPlantFrog[k]->getGravity() > 10)// && _vPlantFrog[k]->getEnemyAction() != E_DEAD)
//				{
//					_vPlantFrog[k]->setY(j - _vPlantFrog[k]->getEnemyImage(_vPlantFrog[k]->getEnemyAction())->getFrameHeight() / 2);           // = j - _image[E_MOVE]->getFrameHeight();
//					_vPlantFrog[k]->setGravity(0);
//					//_vPlantFrog[k]->setIsJump(false);
//					_vPlantFrog[k]->setEnemyAction(E_SPAWN);
//					break;
//				}
//			}
//		}
//	}
//}
//
////void enemyManager::collision(vector<enemy*> _temp)
////{
////	//vector<enemy*> temp;
////	//temp = _temp;
////
////	for (int i = 0; i < _temp.size(); i++)
////	{
////		RECT rct;
////		if (IntersectRect(&rct, &_temp[i]->getColliRect(), &_player->getAttRc()) && _temp[i]->getEnemyAction() != E_SPAWN)
////		{
////
////			_temp[i]->setEnemyAction(E_DEAD);
////			_player->setIsAttack(false);
////			_iMG->setCoin(_temp[i]->getX(), _temp[i]->getY(), _temp[i]->getGold(), _temp[i]->getSilver(), _temp[i]->getBronze());
////
////			_temp[i]->setY(-1000);
////			//_temp.erase(_temp.begin() + i);
////			
////			//--i;
////		}
////	}
////}
//
////void enemyManager::removeEnemy(vector<enemy*> _temp)
////{
////	vector<enemy*> temp;
////	temp = _temp;
////
////	for (int i = 0; i < temp.size(); i++)
////	{
////		if (_temp[i]->getIsDrop())
////		{
////		}
////	}
////
////}
//
////void enemyManager::coinDrop(vector<enemy*> _temp)
////{
////	vector<enemy*> temp;
////	temp = _temp;
////
////	for (int i = 0; i < temp.size(); i++)
////	{
////		if (temp[i]->getEnemyAction() == E_DEAD)
////		{
////
////
////
////		}
////	}
////
////}
//
//
//
//
//
//
////void enemyManager::sensorCollision()
////{
////	for (int i = 0; i < _vVineMan.size(); i++)
////	{
////		RECT rct;
////		if (IntersectRect(&rct, &_vVineMan[i]->getSensorRect(), &_player->getColliRect()) && _vVineMan[i]->getEnemyAction() != E_SPAWN)
////		{
////
////			if (_player->getX() > _vVineMan[i]->getX())
////			{
////				_vVineMan[i]->setEnemyState(E_RIGHT);
////
////			}
////			else
////				_vVineMan[i]->setEnemyState(E_LEFT);
////
////			_vVineMan[i]->setEnemyAction(E_ATTACK);
////
////		}
////	}
////
////	for (int i = 0; i < _vPlantFrog.size(); i++)
////	{
////		RECT rct;
////		if (IntersectRect(&rct, &_vPlantFrog[i]->getSensorRect(), &_player->getColliRect()) && _vPlantFrog[i]->getEnemyAction() != E_SPAWN && _vPlantFrog[i]->getGravity() == 0)
////		{
////			_vPlantFrog[i]->setEnemyAction(E_ATTACK);
////
////			if (_player->getX() > _vPlantFrog[i]->getX())
////			{
////				_vPlantFrog[i]->setEnemyState(E_RIGHT);
////
////			}
////			else
////				_vPlantFrog[i]->setEnemyState(E_LEFT);
////		}
////	}
////
////}