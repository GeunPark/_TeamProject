#include "stdafx.h"
#include "enemyManager.h"
#include "foxPlayer.h"

HRESULT enemyManager::init(void)
{
	
	// 맵데이터 가져오기
	//this->setMapData(_mapData);

	_factory = new enemyFactory;

	//INIDATA로 바꿀것
	_dragonFlyPos[0].x = 100.f, _dragonFlyPos[0].y = 2400.f;
	_dragonFlyPos[1].x = 200.f, _dragonFlyPos[1].y = 2400.f;
	_dragonFlyPos[2].x = 300.f, _dragonFlyPos[2].y = 2400.f;
	_dragonFlyPos[3].x = 400.f, _dragonFlyPos[3].y = 2400.f;

	for (int i = 0; i < 4; i++)
	{
		enemy* _enemy = _factory->createEnemy(DRAGONFLY);
		_enemy->setPosition(_dragonFlyPos[i].x, _dragonFlyPos[i].y);

		_vEnemy.push_back(_enemy);
	}

	//for (int i = 0; i < 1; i++)
	//{
	//	enemy* _enemy = _factory->createEnemy(BROVIL);
	//	_vEnemy.push_back(_enemy);
	//}

	return S_OK;
}

void enemyManager::release(void)
{
	SAFE_DELETE(_factory);
}

void enemyManager::update(void)
{
	for (int i = 0; i < _vEnemy.size(); i++)
	{
		//if ((180 / 3.14f * getAngle(_vEnemy[i]->getX(), _vEnemy[i]->getY(), _playerManager->getPlayer()->getX(), _playerManager->getPlayer()->getY())) >= 91.f && (180 / 3.14f * getAngle(_vEnemy[i]->getX(), _vEnemy[i]->getY(), _playerManager->getPlayer()->getX(), _playerManager->getPlayer()->getY()) <= 270.f))
		//{
		//	_vEnemy[i]->setIsLeft(true);
		//}
		//else
		//{
		//	_vEnemy[i]->setIsLeft(false);
		//}

		_vEnemy[i]->update();
	}



	//에너미 충돌처리

	//플레이어 총알과 에너미 충돌
	//for (int i = 0; i<_player->getPBullet()->getVPlayerBullet().size(); i++)
	//{
	//	//if (!_playerManager->getPBullet()->getVPlayerBullet()[i].isActived) continue;
	//	for (int j = 0; j < _vEnemy.size(); j++)
	//	{
	//		//if (COLLISIONMANAGER->rectCollision(_playerManager->getPBullet()->getVPlayerBullet()[i].rc, _vEnemy[j]->getBoundingBox()))
	//		//{
	//		//	_vEnemy[j]->setState(ENEMY_DEAD);
	//		//}
	//		//충돌처리넣기
	//	}
	//}
	//아직 총알이 없음 attRc랑 충돌이나 만들어놓자!


}

void enemyManager::render(void)
{
	for (int i = 0; i < _vEnemy.size(); i++)
	{
		if (!_vEnemy[i]->getIsActived()) continue;

		_vEnemy[i]->getBodyImage()->frameRender(getMemDC(), _vEnemy[i]->getRc().left - _player->getPlayerCam().left, _vEnemy[i]->getRc().top - _player->getPlayerCam().top, _vEnemy[i]->getBodyImage()->getFrameX(), _vEnemy[i]->getBodyImage()->getFrameY());
		//카메라 메니져 대신 렌더넣기 


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

	//char str[64];
	//for (int i = 0; i < _vEnemy.size(); i++)
	//{
	//	sprintf(str, "%d", _vEnemy[i]->getIsLeft());
	//	TextOut(getMemDC(), 200, 400+i*50, str, strlen(str));
	//}
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