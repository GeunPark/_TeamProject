#pragma once
#include "gameNode.h"
#include "enemy.h"

//#include "player.h"
//�÷��̾� ��ȣ�����ϱ� ���� Ŭ���� ���漱��

class player;

class enemyManager : public gameNode
{
private:
	vector<enemy*> _vDragonFly;
	vector<enemy*>::iterator _viDragonFly;

	vector<enemy*> _vVineMan;
	vector<enemy*>::iterator _viVineMan;

	vector<enemy*> _vBug;
	vector<enemy*>::iterator _viBug;

	vector<enemy*> _vTreeMan;
	vector<enemy*>::iterator _viTreeMan;

	vector<enemy*> _vPlantFrog;
	vector<enemy*>::iterator _viPlantFrog;

	vector<enemy*> _vElectriceel;
	vector<enemy*>::iterator _viElectriceel;


	int _count;
	//dragonfly* _dragonFly;
	player* _player;	//�����Ҵ� �ϸ� �ȵȴ�!!!

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(float FX, float FY);

	//�̴Ͼ� ���� => �ʱ�ȭ�� �ֱ�
	void setMinion();

	//�̴Ͼ� �Ѿ˹߻�
	//void minionBulletFire();

	//�̴Ͼ� ����
	//void removeMinion(int index);

	//�浹�Լ�
	//void collision(vector<enemy*> _temp);
	//void sensorCollision();
	void pixelCollision(); //�β���


						   //���ͺ� ���� ��������
	vector<enemy*> getVDragonFly() { return _vDragonFly; }
	vector<enemy*> getVVineMan() { return _vVineMan; }
	vector<enemy*> getVBug() { return _vBug; }
	vector<enemy*> getVTreeMan() { return _vTreeMan; }
	vector<enemy*> getVPlantFrog() { return _vPlantFrog; }
	vector<enemy*> getVElectriceel() { return _vElectriceel; }



	//��ȣ������ �÷��̾� ������ �ѱ� �����Լ�
	void setPlayerLink(player* player) { _player = player; }



	enemyManager() {}
	~enemyManager() {}
};

