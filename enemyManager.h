#pragma once
#include "gameNode.h"
#include "enemy.h"

//#include "player.h"
//플레이어 상호참조하기 위해 클래스 전방선언

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
	player* _player;	//동적할당 하면 안된다!!!

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(float FX, float FY);

	//미니언 세팅 => 초기화에 넣기
	void setMinion();

	//미니언 총알발사
	//void minionBulletFire();

	//미니언 삭제
	//void removeMinion(int index);

	//충돌함수
	//void collision(vector<enemy*> _temp);
	//void sensorCollision();
	void pixelCollision(); //두꺼비


						   //몬스터별 벡터 가져오기
	vector<enemy*> getVDragonFly() { return _vDragonFly; }
	vector<enemy*> getVVineMan() { return _vVineMan; }
	vector<enemy*> getVBug() { return _vBug; }
	vector<enemy*> getVTreeMan() { return _vTreeMan; }
	vector<enemy*> getVPlantFrog() { return _vPlantFrog; }
	vector<enemy*> getVElectriceel() { return _vElectriceel; }



	//상호참조시 플레이어 포인터 넘길 셋터함수
	void setPlayerLink(player* player) { _player = player; }



	enemyManager() {}
	~enemyManager() {}
};

