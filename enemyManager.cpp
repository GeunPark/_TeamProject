#include "stdafx.h"
#include "enemyManager.h"
#include "foxPlayer.h"
#include "itemManager.h"

HRESULT enemyManager::init(void)
{
	
	// �ʵ����� ��������
	//this->setMapData(_mapData);

	_factory = new enemyFactory;

	//INIDATA�� �ٲܰ�
	//�ϴ���

	//���ڸ�
	_dragonFlyPos[0].x = 800.f, _dragonFlyPos[0].y = 2300.f;
	_dragonFlyPos[1].x = 900.f, _dragonFlyPos[1].y = 2250.f;
	_dragonFlyPos[2].x = 1950.f, _dragonFlyPos[2].y = 2250.f;
	_dragonFlyPos[3].x = 2050.f, _dragonFlyPos[3].y = 2300.f;
	_dragonFlyPos[4].x = 2900.f, _dragonFlyPos[4].y = 2300.f;
	_dragonFlyPos[5].x = 5050.f, _dragonFlyPos[5].y = 1950.f;
	_dragonFlyPos[6].x = 6475.f, _dragonFlyPos[6].y = 1875.f;


	//�����ΰ�
	_vineManPos[0].x = 1600.f; _vineManPos[0].y = 2240.f;
	_vineManPos[1].x = 3600.f; _vineManPos[1].y = 2350.f;
	_vineManPos[2].x = 3900.f; _vineManPos[2].y = 2350.f;
	_vineManPos[3].x = 5900.f; _vineManPos[3].y = 2350.f;
	_vineManPos[4].x = 6800.f; _vineManPos[4].y = 2350.f;


	//�볪��
	_treeManPos[0].x = 7000.f; _treeManPos[0].y = 1785.f;
	_treeManPos[1].x = 7000.f; _treeManPos[1].y = 1400.f;
	//_treeManPos[2].x = 300.f; _treeManPos[2].y = 2200.f;
	//_treeManPos[3].x = 900.f; _treeManPos[3].y = 2200.f;

	//����
	_bugPos[0].x = 7300.f; _bugPos[0].y = 1770.f;
	_bugPos[1].x = 7400.f; _bugPos[1].y = 1770.f;
	_bugPos[2].x = 9450.f; _bugPos[2].y = 1960.f;
	_bugPos[3].x = 9550.f; _bugPos[3].y = 1960.f;


	//�β���
	_plantFrogPos[0].x = 7100.f; _plantFrogPos[0].y = 2350.f;
	_plantFrogPos[1].x = 7200.f; _plantFrogPos[1].y = 2350.f;
	//_plantFrogPos[2].x = 130.f; _plantFrogPos[2].y = 2400.f;
	//_plantFrogPos[3].x = 190.f; _plantFrogPos[3].y = 2400.f;

	//�����
	_electriceelPos[0].x = 3240.f; _electriceelPos[0].y = 2410.f;
	_electriceelPos[1].x = 6230.f; _electriceelPos[1].y = 2410.f;
	//_electriceelPos[2].x = 130.f; _electriceelPos[2].y = 2300.f;
	//_electriceelPos[3].x = 190.f; _electriceelPos[3].y = 2300.f;



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

		_vEnemy.push_back(_enemy);
	}
	for (int i = 0; i < MAX_BUG; i++)
	{
		enemy* _enemy = _factory->createEnemy(BUG);
		_enemy->setPosition(_bugPos[i].x, _bugPos[i].y);

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
		if (_vEnemy[i]->getX() > _player->getX())
		{
			_vEnemy[i]->setIsLeft(true);
		}
		else
		{
			_vEnemy[i]->setIsLeft(false);
		}

		_vEnemy[i]->update();
	}


	//���ʹ� �浹ó��

	//�÷��̾�� ���ʹ� �浹
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		RECT _rct;

		if (IntersectRect(&_rct, &_vEnemy[i]->getRc(), &_player->getAttRc()))
		{
			//_vEnemy[i]->setState(ENEMY_DEAD);
			_iMG->setCoin(_vEnemy[i]->getX(), _vEnemy[i]->getY(), _vEnemy[i]->getGold(), _vEnemy[i]->getSilver(), _vEnemy[i]->getBronze());
			_vEnemy.erase(_vEnemy.begin() + i);

			//			_vPlantFrog[i]->setEnemyAction(E_DEAD);
			//			_player->setIsAttack(false);
			//			_iMG->setCoin(_vPlantFrog[i]->getX(), _vPlantFrog[i]->getY(), _vPlantFrog[i]->getGold(), _vPlantFrog[i]->getSilver(), _vPlantFrog[i]->getBronze());
			//			_vPlantFrog.erase(_vPlantFrog.begin() + i);
		}
	}
	//���� �Ѿ��� ���� attRc�� �浹�̳� ��������!
	//�÷��̾��� �Ѿ˰� ���ʹ� �浹
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		for (int j = 0; j < _player->getArrow()->getVArrow().size(); ++j)
		{
			RECT _rct;

			if (IntersectRect(&_rct, &_vEnemy[i]->getRc(), &_player->getArrow()->getVArrow()[j].rc))
			{
				//_vEnemy[i]->setState(ENEMY_DEAD);
				_iMG->setCoin(_vEnemy[i]->getX(), _vEnemy[i]->getY(), _vEnemy[i]->getGold(), _vEnemy[i]->getSilver(), _vEnemy[i]->getBronze());
				_vEnemy.erase(_vEnemy.begin() + i);
				//������~ ����ٰ� ���� ������ �������~����
				_player->removeArrow(j);	//���� ȭ�� �浹�� ȭ�� ������
				
				//j--;
				//			_vPlantFrog[i]->setEnemyAction(E_DEAD);
				//			_player->setIsAttack(false);
				//			_iMG->setCoin(_vPlantFrog[i]->getX(), _vPlantFrog[i]->getY(), _vPlantFrog[i]->getGold(), _vPlantFrog[i]->getSilver(), _vPlantFrog[i]->getBronze());
				//			_vPlantFrog.erase(_vPlantFrog.begin() + i);
			}
		}
		
	}


}

void enemyManager::render(void)
{
	for (int i = 0; i < _vEnemy.size(); i++)
	{
		if (!_vEnemy[i]->getIsActived()) continue;

		_vEnemy[i]->getBodyImage()->frameRender(getMemDC(), _vEnemy[i]->getRc().left - _player->getPlayerCam().left, _vEnemy[i]->getRc().top - _player->getPlayerCam().top, _vEnemy[i]->getIndexX(), _vEnemy[i]->getIndexY());
		//ī�޶� �޴��� ��� �����ֱ� 


		//switch (_vEnemy[i]->getType())
		//{
		//case SOLDIER:
		//	//dynamic_cast<soldier*>(_vEnemy[i])->getGunImage()->frameRender(getMemDC(), _vEnemy[i]->getX() - CAMERAMANAGER->getCamera().left, _vEnemy[i]->getY() - CAMERAMANAGER->getCamera().top);
		//	//ī�޶� �޴��� ��� �����ֱ� 
		//
		//	//((soldier*)_vEnemy[i])->getGunImage()->frameRender(getMemDC(), _vEnemy[i]->getX() - CAMERAMANAGER->getCamera().left, _vEnemy[i]->getY() - CAMERAMANAGER->getCamera().top);
		//	break;
		//default:
		//	//������ ��??
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
//	//�̴Ͼ� ����
//
//	this->setMinion();
//
//	_count = 0;
//	//_dragonFly = new dragonfly;
//
//	_bpx = IMAGEMANAGER->findImage("��������1 �ȼ�");
//
//	//�Ѿ�Ŭ���� ���� �� �ʱ�ȭ
//	//_bullet = new bullet;
//	//_bullet->init("bullet", 15, 600);
//
//	//�÷��̾� Ŭ���� ���� �� �ʱ�ȭ (���ΰ����� �÷��̾�� �Ʒ� �÷��̾�� �ٸ� Ŭ������)
//	//_player = new player;
//	//_player->init();
//	//
//
//	return S_OK;
//}
//
//void enemyManager::release(void)
//{
//	//�Ѿ�Ŭ���� ����
//	//_bullet->release();
//	//SAFE_DELETE(_bullet);
//}
//
//void enemyManager::update(void)
//{
//	//�Ѿ�Ŭ���� ������Ʈ
//	//_bullet->update();
//
//	//���Ϳ� ��� �̴Ͼ�� ������Ʈ
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
//	//�Ѿ�Ŭ���� ����
//	//_bullet->render();
//	//���Ϳ� ��� �̴Ͼ�� ����
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
//	//���ڸ�
//	for (int i = 0; i < 2; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "���ڸ�spawn", "���ڸ�move", "null", "���ڸ�dead", PointMake(1400, 2250 + i * 100), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//	for (int i = 0; i < 2; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "���ڸ�spawn", "���ڸ�move", "null", "���ڸ�dead", PointMake(3750, 2100 + i * 200), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//	for (int i = 0; i < 2; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "���ڸ�spawn", "���ڸ�move", "null", "���ڸ�dead", PointMake(5230 + i * 200, 2250 + i * 200), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//	for (int i = 0; i < 2; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "���ڸ�spawn", "���ڸ�move", "null", "���ڸ�dead", PointMake(6200 + i * 200, 2500 ), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//	for (int i = 0; i < 2; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "���ڸ�spawn", "���ڸ�move", "null", "���ڸ�dead", PointMake(8250 , 2000 + i * 200), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//	for (int i = 0; i < 2; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "���ڸ�spawn", "���ڸ�move", "null", "���ڸ�dead", PointMake(10850, 1800 + i * 200), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//
//	for (int i = 0; i < 2; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "���ڸ�spawn", "���ڸ�move", "null", "���ڸ�dead", PointMake(12050 + i * 200, 1250 + i * 100), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//
//	for (int i = 0; i < 6; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "���ڸ�spawn", "���ڸ�move", "null", "���ڸ�dead", PointMake(12600 + i * 100, 850 - i * 100), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//
//
//	for (int i = 0; i < 2; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "���ڸ�spawn", "���ڸ�move", "null", "���ڸ�dead", PointMake(16580, 2200 + i * 200), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//	for (int i = 0; i < 2; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "���ڸ�spawn", "���ڸ�move", "null", "���ڸ�dead", PointMake(17000, 1800 + i * 300), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//	for (int i = 0; i < 2; ++i)
//	{
//		dragonfly* drangonFly = new dragonfly;
//		drangonFly->init("null", "���ڸ�spawn", "���ڸ�move", "null", "���ڸ�dead", PointMake(18080, 1750 + i * 200), 0, 100 * i, 0, 1, 1);
//		_vDragonFly.push_back(drangonFly);
//	}
//
//	//�����ΰ�
//	for (int i = 0; i < 1; ++i)
//	{
//		vineman* _vineman = new vineman;
//		_vineman->init("null", "�����ΰ�spawn", "�����ΰ�move", "�����ΰ�attack", "���ڸ�dead", PointMake(1650, 2390 + i * 200), 0, 100 * i, 0, 1, 1);
//		_vVineMan.push_back(_vineman);
//	}
//	for (int i = 0; i < 2; ++i)
//	{
//		vineman* _vineman = new vineman;
//		_vineman->init("null", "�����ΰ�spawn", "�����ΰ�move", "�����ΰ�attack", "���ڸ�dead", PointMake(7400 + i * 500, 2570), 0, 100 * i, 0, 1, 1);
//		_vVineMan.push_back(_vineman);
//	}
//	for (int i = 0; i < 2; ++i)
//	{
//		vineman* _vineman = new vineman;
//		_vineman->init("null", "�����ΰ�spawn", "�����ΰ�move", "�����ΰ�attack", "���ڸ�dead", PointMake(12300 + i * 100, 2570), 0, 100 * i, 0, 1, 1);
//		_vVineMan.push_back(_vineman);
//	}
//
//	//���� (����)
//	for (int i = 0; i < 2; ++i)
//	{
//		bug* _bug = new bug;
//		_bug->init("null", "����move", "����move", "null", "���ڸ�dead", PointMake(13250 + i * 200, 2530 ), 0, 100 * i, 0, 1, 1);
//		_vBug.push_back(_bug);
//	}
//
//	for (int i = 0; i < 2; ++i)
//	{
//		bug* _bug = new bug;
//		_bug->init("null", "����move", "����move", "null", "���ڸ�dead", PointMake(15500 + i * 300, 2240), 0, 100 * i, 0, 1, 1);
//		_vBug.push_back(_bug);
//	}
//
//	//�볪��
//	for (int i = 0; i < 2; ++i)
//	{
//		treeman* _treeman = new treeman;
//		_treeman->init("null", "�볪��move", "�볪��move", "null", "���ڸ�dead", PointMake(3270 + i * 450, 2520), 0, 100 * i, 3, 0, 0);
//		_vTreeMan.push_back(_treeman);
//	}
//	for (int i = 0; i < 1; ++i)
//	{
//		treeman* _treeman = new treeman;
//		_treeman->init("null", "�볪��move", "�볪��move", "null", "���ڸ�dead", PointMake(9800 + i * 450, 2040), 0, 100 * i, 3, 0, 0);
//		_vTreeMan.push_back(_treeman);
//	}
//	for (int i = 0; i < 2; ++i)
//	{
//		treeman* _treeman = new treeman;
//		_treeman->init("null", "�볪��move", "�볪��move", "null", "���ڸ�dead", PointMake(15200 + i * 780, 2530), 0, 100 * i, 3, 0, 0);
//		_vTreeMan.push_back(_treeman);
//	}
//	for (int i = 0; i < 1; ++i)
//	{
//		treeman* _treeman = new treeman;
//		_treeman->init("null", "�볪��move", "�볪��move", "null", "���ڸ�dead", PointMake(18200 + i * 450, 2530), 0, 100 * i, 3, 0, 0);
//		_vTreeMan.push_back(_treeman);
//	}
//
//	//�β���
//	for (int i = 0; i < 1; ++i)
//	{
//		plantfrog* _plantfrog = new plantfrog;
//		_plantfrog->init("null", "�β���spawn", "�β���move", "�β���attack", "���ڸ�dead", PointMake(3900 + 300 * i, 2550), 0, 150 * i, 1, 1, 0);
//		_vPlantFrog.push_back(_plantfrog);
//	}
//	for (int i = 0; i < 1; ++i)
//	{
//		plantfrog* _plantfrog = new plantfrog;
//		_plantfrog->init("null", "�β���spawn", "�β���move", "�β���attack", "���ڸ�dead", PointMake(13135 + 300 * i, 2080), 0, 150 * i, 1, 1, 0);
//		_vPlantFrog.push_back(_plantfrog);
//	}
//
//	//�����
//	for (int i = 0; i < 2; ++i)
//	{
//		electriceel* _electriceel = new electriceel;
//		_electriceel->init("null", "�����move", "�����move", "null", "���ڸ�dead", PointMake(11870 + i * 1070, 2630), i * 2, 150 * i, 0, 1, 1);
//		_vElectriceel.push_back(_electriceel);
//
//	}
//
//	//for (int i = 0; i < 4; ++i)
//	//{
//	//	dragonfly* drangonFly = new dragonfly;
//	//	drangonFly->init("null", "null", "���ڸ�", "null", "null", PointMake(300, 100 + i * 100), 0, 50 * i);
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
//////�浹ó�� (���Ѿ˰� �÷��̾�)
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