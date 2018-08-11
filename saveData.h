#pragma once
#include "singletonBase.h"


class foxPlayer;
class UI;
class shop;
class enemyManager;
class itemManager;
class effectManager;

class saveData : public singletonBase <saveData>
{
private:
	int _hp;

	foxPlayer* _player;
	UI* _ui;
	shop* _shop;
	enemyManager* _em;
	itemManager* _im;
	effectManager* _effMG;

public:
	HRESULT init();
	void release();

	int getHp() { return _hp; }
	void setHp(int hp) { _hp = hp; }

	//플레이어 세이브 데이터
	foxPlayer* getPlayer() { return _player; }
	void setPlayer(foxPlayer* player) { _player = player; }

	//UI 세이브 데이터
	UI* getUI() { return _ui; }
	void setUI(UI* ui) { _ui = ui; }

	shop* getShop() { return _shop; }
	void setShop(shop* shop) { _shop = shop; }

	enemyManager* getEnemyManager() { return _em; }
	void setEnemyManager(enemyManager* em) { _em = em; }

	itemManager* getItemManager() { return _im; }
	void setItemManager(itemManager* im) { _im = im; }
	
	effectManager* getEffectManager() { return _effMG; }
	void setEffectManager(effectManager* effMG) { _effMG = effMG; }


	saveData() {}
	~saveData() {}
};

