#pragma once
#include "gameNode.h"
#include "enemy.h"

#include "factory.h"
#include "bullet.h"
#include "effect.h"

class itemManager;
class foxPlayer;

struct fPos
{
	float x;
	float y;
};

#define MAX_DRAGONFLY 6
#define MAX_VINEMAN 5
#define MAX_BUG 4
#define MAX_TREEMAN 2
#define MAX_PLANTFROG 2
#define MAX_ELECTRICEEL 2
class enemyManager : public gameNode
{
private:
	foxPlayer * _player;
	itemManager* _iMG;
	image* _tongue;			// ��ο÷κ��Ӥ����ۤ��������������ä����ǤӳĤѤ��Ϥä��������������������Ӥä̤��� ȯ��~~! (������)
	ghostBullet* _ghostBullet;
	beeBullet* _beeBullet;
	bee* _bee;

	effect* _effect;

	factory* _factory;
	vector<enemy*> _vEnemy;	// �Ϲ� ��
	vector<enemy*> _vGhost;

	fPos _dragonFlyPos[MAX_DRAGONFLY];
	fPos _vineManPos[MAX_VINEMAN];
	fPos _bugPos[MAX_BUG];
	fPos _treeManPos[MAX_TREEMAN];
	fPos _plantFrogPos[MAX_PLANTFROG];
	fPos _electriceelPos[MAX_ELECTRICEEL];

	float _itemX;
	float _itemY;
	int _num;

	int isAttack;


	//eBullet* _eBullet;			// �Ѿ� Ŭ����
public:
	void setPlayerManager(foxPlayer* player) { _player = player; }
	void setItemManager(itemManager* iMG) { _iMG = iMG; }
	// �츮 ���� ������������


	vector<enemy*> getEnemy() { return _vEnemy; }
	vector<enemy*> getGhost() { return _vGhost; }

	void setGhost(float itemX, float itemY, int number)
	{
		_itemX = itemX;
		_itemY = itemY;
		_num = number;
	}

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
	void beAttackedEffect();

	void appearGhost();
	void sensorCollision();


	enemyManager() {}
	~enemyManager() {}
};




//#include "player.h"
//�÷��̾� ��ȣ�����ϱ� ���� Ŭ���� ���漱��

//class foxPlayer;
//class itemManager;
//
//class enemyManager : public gameNode
//{
//private:
//	vector<enemy*> _vDragonFly;
//	vector<enemy*>::iterator _viDragonFly;
//
//	vector<enemy*> _vVineMan;
//	vector<enemy*>::iterator _viVineMan;
//
//	vector<enemy*> _vBug;
//	vector<enemy*>::iterator _viBug;
//
//	vector<enemy*> _vTreeMan;
//	vector<enemy*>::iterator _viTreeMan;
//
//	vector<enemy*> _vPlantFrog;
//	vector<enemy*>::iterator _viPlantFrog;
//
//	vector<enemy*> _vElectriceel;
//	vector<enemy*>::iterator _viElectriceel;
//
//	image* _bpx;
//
//	int _count;
//	//dragonfly* _dragonFly;
//	foxPlayer* _player;	//�����Ҵ� �ϸ� �ȵȴ�!!!
//	itemManager* _iMG;
//
//public:
//	HRESULT init(void);
//	void release(void);
//	void update(void);
//	void render(float FX, float FY);
//
//	//�̴Ͼ� ���� => �ʱ�ȭ�� �ֱ�
//	void setMinion();
//
//	//�̴Ͼ� �Ѿ˹߻�
//	//void minionBulletFire();
//
//	//�̴Ͼ� ����
//	//void removeMinion(int index);
//
//	//�浹�Լ�
//	
//	//void collision(vector<enemy*> _temp);
//	//void removeEnemy(vector<enemy*> _temp);
//	//void coinDrop(vector<enemy*> _temp);
//	void collision();
//	//void sensorCollision();
//	void pixelCollision(); //�β���
//
//
//						   //���ͺ� ���� ��������
//	vector<enemy*> getVDragonFly() { return _vDragonFly; }
//	vector<enemy*> getVVineMan() { return _vVineMan; }
//	vector<enemy*> getVBug() { return _vBug; }
//	vector<enemy*> getVTreeMan() { return _vTreeMan; }
//	vector<enemy*> getVPlantFrog() { return _vPlantFrog; }
//	vector<enemy*> getVElectriceel() { return _vElectriceel; }
//
//
//
//	//��ȣ������ �÷��̾� ������ �ѱ� �����Լ�
//	void setPlayerLink(foxPlayer* player) { _player = player; }
//	void setItemMGLink(itemManager* iMG) { _iMG = iMG; }
//
//
//
//	enemyManager() {}
//	~enemyManager() {}
//};
//
//