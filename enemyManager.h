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
	image* _tongue;			// 츄로올로보롭ㅇ고퍼ㅏㅁㄴㅇㅍㄷ리ㅓㅇ겨피ㅣ냐ㅡㅍ먀ㅓㄹㄹㄹㄷㄴㅇㅍㅁ러ㅑㅣㅓㅜㄹㄹ 환상~~! (납득이)
	ghostBullet* _ghostBullet;
	beeBullet* _beeBullet;
	bee* _bee;

	effect* _effect;

	factory* _factory;
	vector<enemy*> _vEnemy;	// 일반 적
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


	//eBullet* _eBullet;			// 총알 클래스
public:
	void setPlayerManager(foxPlayer* player) { _player = player; }
	void setItemManager(itemManager* iMG) { _iMG = iMG; }
	// 우리 선수 괴롭히지마요


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
//플레이어 상호참조하기 위해 클래스 전방선언

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
//	foxPlayer* _player;	//동적할당 하면 안된다!!!
//	itemManager* _iMG;
//
//public:
//	HRESULT init(void);
//	void release(void);
//	void update(void);
//	void render(float FX, float FY);
//
//	//미니언 세팅 => 초기화에 넣기
//	void setMinion();
//
//	//미니언 총알발사
//	//void minionBulletFire();
//
//	//미니언 삭제
//	//void removeMinion(int index);
//
//	//충돌함수
//	
//	//void collision(vector<enemy*> _temp);
//	//void removeEnemy(vector<enemy*> _temp);
//	//void coinDrop(vector<enemy*> _temp);
//	void collision();
//	//void sensorCollision();
//	void pixelCollision(); //두꺼비
//
//
//						   //몬스터별 벡터 가져오기
//	vector<enemy*> getVDragonFly() { return _vDragonFly; }
//	vector<enemy*> getVVineMan() { return _vVineMan; }
//	vector<enemy*> getVBug() { return _vBug; }
//	vector<enemy*> getVTreeMan() { return _vTreeMan; }
//	vector<enemy*> getVPlantFrog() { return _vPlantFrog; }
//	vector<enemy*> getVElectriceel() { return _vElectriceel; }
//
//
//
//	//상호참조시 플레이어 포인터 넘길 셋터함수
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