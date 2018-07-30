#include "stdafx.h"
#include "enemyManager.h"


HRESULT enemyManager::init(void)
{
	//�̴Ͼ� ����

	this->setMinion();

	_count = 0;
	//_dragonFly = new dragonfly;


	//�Ѿ�Ŭ���� ���� �� �ʱ�ȭ
	//_bullet = new bullet;
	//_bullet->init("bullet", 15, 600);

	//�÷��̾� Ŭ���� ���� �� �ʱ�ȭ (���ΰ����� �÷��̾�� �Ʒ� �÷��̾�� �ٸ� Ŭ������)
	//_player = new player;
	//_player->init();
	//

	return S_OK;
}

void enemyManager::release(void)
{
	//�Ѿ�Ŭ���� ����
	//_bullet->release();
	//SAFE_DELETE(_bullet);
}

void enemyManager::update(void)
{
	//�Ѿ�Ŭ���� ������Ʈ
	//_bullet->update();

	//���Ϳ� ��� �̴Ͼ�� ������Ʈ
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
	//�̴Ͼ� �Ѿ˹߻�
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
	//�Ѿ�Ŭ���� ����
	//_bullet->render();
	//���Ϳ� ��� �̴Ͼ�� ����
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
		drangonFly->init("null", "���ڸ�spawn", "���ڸ�move", "null", "���ڸ�dead", PointMake(300, 100 + i * 100), 0, 100 * i, 0, 1, 1);
		_vDragonFly.push_back(drangonFly);
	}
	for (int i = 2; i < 4; ++i)
	{
		dragonfly* drangonFly = new dragonfly;
		drangonFly->init("null", "���ڸ�spawn", "���ڸ�move", "null", "���ڸ�dead", PointMake(400, 100 + i * 100), 0, 100 * i, 0, 1, 1);
		_vDragonFly.push_back(drangonFly);
	}
	for (int i = 0; i < 1; ++i)
	{
		vineman* _vineman = new vineman;
		_vineman->init("null", "�����ΰ�spawn", "�����ΰ�move", "�����ΰ�attack", "���ڸ�dead", PointMake(-900, 100 + i * 200), 0, 100 * i, 0, 1, 1);
		_vVineMan.push_back(_vineman);
	}
	for (int i = 0; i < 1; ++i)
	{
		bug* _bug = new bug;
		_bug->init("null", "����move", "����move", "null", "���ڸ�dead", PointMake(-200, 100 + i * 200), 0, 100 * i, 0, 1, 1);
		_vBug.push_back(_bug);
	}

	for (int i = 0; i < 1; ++i)
	{
		treeman* _treeman = new treeman;
		_treeman->init("null", "�볪��move", "�볪��move", "null", "���ڸ�dead", PointMake(-500 + i * 300, -100), 0, 100 * i, 3, 0, 0);
		_vTreeMan.push_back(_treeman);
	}

	for (int i = 0; i < 1; ++i)
	{
		plantfrog* _plantfrog = new plantfrog;
		_plantfrog->init("null", "�β���spawn", "�β���move", "�β���attack", "���ڸ�dead", PointMake(200 + 300 * i, 30), 0, 150 * i, 1, 1, 0);
		_vPlantFrog.push_back(_plantfrog);

	}

	for (int i = 0; i < 1; ++i)
	{
		electriceel* _electriceel = new electriceel;
		_electriceel->init("null", "�����move", "�����move", "null", "���ڸ�dead", PointMake(400 + i * 320, 420), i * 2, 150 * i, 0, 1, 1);
		_vElectriceel.push_back(_electriceel);

	}

	//for (int i = 0; i < 4; ++i)
	//{
	//	dragonfly* drangonFly = new dragonfly;
	//	drangonFly->init("null", "null", "���ڸ�", "null", "null", PointMake(300, 100 + i * 100), 0, 50 * i);
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
////�浹ó�� (���Ѿ˰� �÷��̾�)
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("��������1 �ȼ�")->getMemDC(), i, j);
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
