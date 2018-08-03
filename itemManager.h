#pragma once
#include "gameNode.h"
#include "item.h"
#include "factory.h"
#include "item.h"

class foxPlayer;
class enemyManager;

struct itemPos
{
	float x;
	float y;

};
class itemManager : public gameNode
{
private:
	foxPlayer * _player;
	enemyManager* _eMG;
	factory2* _itemFactory;
	//필드아이템
	vector<item*> _vItem;

	//드랍코인
	vector<item*> _vCoinGold;
	vector<item*>::iterator _viCoinGold;
	vector<item*> _vCoinSilver;
	vector<item*>::iterator _viCoinSilver;
	vector<item*> _vCoinBronze;
	vector<item*>::iterator _viCoinBronze;



	itemPos _healthLargePos[1];
	itemPos _healthSmallPos[1];
	itemPos _manaBigPos[1];
	itemPos _manaSmallPos[1];

	

	float enemyX;
	float enemyY;
	int gold;
	int silver;
	int bronze;

public:

	HRESULT init();
	void release();
	void update();
	void render();


	void setCoin(float _enemyX, float _enemyY, int _gold, int _silver, int _bronze)
	{
		enemyX = _enemyX;
		enemyY = _enemyY;
		gold = _gold;
		silver = _silver;
		bronze = _bronze;
	}

	void dropCoin();



	//void dropCoin();

	//void pixelCollision(vector<item*> vCoin);

	void setPlayerLink(foxPlayer* player) { _player = player; }
	void setEMGLink(enemyManager* eMG) { _eMG = eMG; }

	itemManager() {}
	~itemManager() {}
};
