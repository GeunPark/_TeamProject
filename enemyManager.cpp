#include "stdafx.h"
#include "enemyManager.h"


HRESULT enemyManager::init(void)
{
	//미니언 생성

	this->setMinion();

	_count = 0;
	//_dragonFly = new dragonfly;


	//총알클래스 생성 및 초기화
	//_bullet = new bullet;
	//_bullet->init("bullet", 15, 600);

	//플레이어 클래스 생성 및 초기화 (메인게임의 플레이어와 아래 플레이어는 다른 클래스다)
	//_player = new player;
	//_player->init();
	//

	return S_OK;
}

void enemyManager::release(void)
{
	//총알클래스 해제
	//_bullet->release();
	//SAFE_DELETE(_bullet);
}

void enemyManager::update(void)
{
	//총알클래스 업데이트
	//_bullet->update();

	//벡터에 담긴 미니언들 업데이트
	//for (int i = 0; i < _vMinion.size(); i++)
	//{
	//	_vMinion[i]->update();
	//}
	_viDragonFly = _vDragonFly.begin();
	for (_viDragonFly; _viDragonFly != _vDragonFly.end(); ++_viDragonFly)
	{
		(*_viDragonFly)->update();
	}

	_viVineMan = _vVineMan.begin();
	for (_viVineMan; _viVineMan != _vVineMan.end(); ++_viVineMan)
	{
		(*_viVineMan)->update();
	}

	_viBug = _vBug.begin();
	for (_viBug; _viBug != _vBug.end(); ++_viBug)
	{
		(*_viBug)->update();
	}

	_viTreeMan = _vTreeMan.begin();
	for (_viTreeMan; _viTreeMan != _vTreeMan.end(); ++_viTreeMan)
	{
		(*_viTreeMan)->update();
	}

	_viPlantFrog = _vPlantFrog.begin();
	for (_viPlantFrog; _viPlantFrog != _vPlantFrog.end(); ++_viPlantFrog)
	{
		(*_viPlantFrog)->update();
	}

	_viElectriceel = _vElectriceel.begin();
	for (_viElectriceel; _viElectriceel != _vElectriceel.end(); ++_viElectriceel)
	{
		(*_viElectriceel)->update();
	}

	//this->sensorCollision();
	this->pixelCollision();
	//미니언 총알발사
	//this->minionBulletFire();

	//this->collision(_vDragonFly);
	//this->collision(_vVineMan);
	//this->collision(_vBug);
	//this->collision(_vElectriceel);
	//this->collision(_vTreeMan);
	//this->collision(_vPlantFrog);
}

void enemyManager::render(float FX, float FY)
{
	//총알클래스 렌더
	//_bullet->render();
	//벡터에 담긴 미니언들 렌더
	//for (int i = 0; i < _vMinion.size(); i++)
	//{
	//	_vMinion[i]->render();
	//}
	_viDragonFly = _vDragonFly.begin();
	for (_viDragonFly; _viDragonFly != _vDragonFly.end(); ++_viDragonFly)
	{
		(*_viDragonFly)->render(FX, FY);
	}

	_viVineMan = _vVineMan.begin();
	for (_viVineMan; _viVineMan != _vVineMan.end(); ++_viVineMan)
	{
		(*_viVineMan)->render(FX, FY);
	}

	_viBug = _vBug.begin();
	for (_viBug; _viBug != _vBug.end(); ++_viBug)
	{
		(*_viBug)->render(FX, FY);
	}

	_viTreeMan = _vTreeMan.begin();
	for (_viTreeMan; _viTreeMan != _vTreeMan.end(); ++_viTreeMan)
	{
		(*_viTreeMan)->render(FX, FY);
	}

	_viPlantFrog = _vPlantFrog.begin();
	for (_viPlantFrog; _viPlantFrog != _vPlantFrog.end(); ++_viPlantFrog)
	{
		(*_viPlantFrog)->render(FX, FY);
	}

	_viElectriceel = _vElectriceel.begin();
	for (_viElectriceel; _viElectriceel != _vElectriceel.end(); ++_viElectriceel)
	{
		(*_viElectriceel)->render(FX, FY);
	}



}

void enemyManager::setMinion()
{
	for (int i = 0; i < 2; ++i)
	{
		dragonfly* drangonFly = new dragonfly;
		drangonFly->init("null", "잠자리spawn", "잠자리move", "null", "잠자리dead", PointMake(300, 100 + i * 100), 0, 100 * i, 0, 1, 1);
		_vDragonFly.push_back(drangonFly);
	}
	for (int i = 2; i < 4; ++i)
	{
		dragonfly* drangonFly = new dragonfly;
		drangonFly->init("null", "잠자리spawn", "잠자리move", "null", "잠자리dead", PointMake(400, 100 + i * 100), 0, 100 * i, 0, 1, 1);
		_vDragonFly.push_back(drangonFly);
	}
	for (int i = 0; i < 1; ++i)
	{
		vineman* _vineman = new vineman;
		_vineman->init("null", "나무인간spawn", "나무인간move", "나무인간attack", "잠자리dead", PointMake(-900, 100 + i * 200), 0, 100 * i, 0, 1, 1);
		_vVineMan.push_back(_vineman);
	}
	for (int i = 0; i < 1; ++i)
	{
		bug* _bug = new bug;
		_bug->init("null", "버그move", "버그move", "null", "잠자리dead", PointMake(-200, 100 + i * 200), 0, 100 * i, 0, 1, 1);
		_vBug.push_back(_bug);
	}

	for (int i = 0; i < 1; ++i)
	{
		treeman* _treeman = new treeman;
		_treeman->init("null", "통나무move", "통나무move", "null", "잠자리dead", PointMake(-500 + i * 300, -100), 0, 100 * i, 3, 0, 0);
		_vTreeMan.push_back(_treeman);
	}

	for (int i = 0; i < 1; ++i)
	{
		plantfrog* _plantfrog = new plantfrog;
		_plantfrog->init("null", "두꺼비spawn", "두꺼비move", "두꺼비attack", "잠자리dead", PointMake(200 + 300 * i, 30), 0, 150 * i, 1, 1, 0);
		_vPlantFrog.push_back(_plantfrog);

	}

	for (int i = 0; i < 1; ++i)
	{
		electriceel* _electriceel = new electriceel;
		_electriceel->init("null", "꼼장어move", "꼼장어move", "null", "잠자리dead", PointMake(400 + i * 320, 420), i * 2, 150 * i, 0, 1, 1);
		_vElectriceel.push_back(_electriceel);

	}

	//for (int i = 0; i < 4; ++i)
	//{
	//	dragonfly* drangonFly = new dragonfly;
	//	drangonFly->init("null", "null", "잠자리", "null", "null", PointMake(300, 100 + i * 100), 0, 50 * i);
	//	_vMinion.push_back(drangonFly);
	//}
}

//void enemyManager::minionBulletFire()
//{
//	_viMinion = _vMinion.begin();
//	for (_viMinion; _viMinion != _vMinion.end(); ++_viMinion)
//	{
//		if ((*_viMinion)->bulletCountFire())
//		{
//			RECT rc = (*_viMinion)->getRect();
//			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom + 30, -PI_2, 3.0f);
//		}
//	}
//}
//
//void enemyManager::removeMinion(int index)
//{
//	_vMinion.erase(_vMinion.begin() + index);
//}
//
////충돌처리 (적총알과 플레이어)
//void enemyManager::collision(vector<enemy*> _temp)
//{
//	vector<enemy*> temp;
//	temp = _temp;
//
//	for (int i = 0; i < temp.size(); i++)
//	{
//		RECT rct;
//		if (IntersectRect(&rct, &temp[i]->getColliRect(), &_player->getAttRect()) && temp[i]->getEnemyAction() != E_SPAWN)
//		{
//			temp[i]->setEnemyAction(E_DEAD);
//		}
//	}
//}
//
//void enemyManager::sensorCollision()
//{
//	for (int i = 0; i < _vVineMan.size(); i++)
//	{
//		RECT rct;
//		if (IntersectRect(&rct, &_vVineMan[i]->getSensorRect(), &_player->getColliRect()) && _vVineMan[i]->getEnemyAction() != E_SPAWN)
//		{
//
//			if (_player->getX() > _vVineMan[i]->getX())
//			{
//				_vVineMan[i]->setEnemyState(E_RIGHT);
//
//			}
//			else
//				_vVineMan[i]->setEnemyState(E_LEFT);
//
//			_vVineMan[i]->setEnemyAction(E_ATTACK);
//
//		}
//	}
//
//	for (int i = 0; i < _vPlantFrog.size(); i++)
//	{
//		RECT rct;
//		if (IntersectRect(&rct, &_vPlantFrog[i]->getSensorRect(), &_player->getColliRect()) && _vPlantFrog[i]->getEnemyAction() != E_SPAWN && _vPlantFrog[i]->getGravity() == 0)
//		{
//			_vPlantFrog[i]->setEnemyAction(E_ATTACK);
//
//			if (_player->getX() > _vPlantFrog[i]->getX())
//			{
//				_vPlantFrog[i]->setEnemyState(E_RIGHT);
//
//			}
//			else
//				_vPlantFrog[i]->setEnemyState(E_LEFT);
//		}
//	}
//
//}

void enemyManager::pixelCollision()
{
	for (int k = 0; k < 1; ++k)
	{
		for (int i = _vPlantFrog[k]->getRect().left; i < _vPlantFrog[k]->getRect().right; i += 2)
		{
			for (int j = _vPlantFrog[k]->getRect().bottom - 10; j <_vPlantFrog[k]->getRect().bottom; j += _vPlantFrog[k]->getEnemyImage(E_MOVE)->getFrameHeight() / 2)  // _rc.bottom - 10; j < _rc.bottom; j++)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("스테이지1 픽셀")->getMemDC(), i, j);
				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if ((r == 0 && g == 255 && b == 255))
				{
					_vPlantFrog[k]->setY(j - _vPlantFrog[k]->getEnemyImage(_vPlantFrog[k]->getEnemyAction())->getFrameHeight() / 2);           // = j - _image[E_MOVE]->getFrameHeight();
					_vPlantFrog[k]->setGravity(0);
					//_vPlantFrog[k]->setIsJump(false);
					_vPlantFrog[k]->setEnemyAction(E_SPAWN);
					break;
				}
			}
		}
	}
}
