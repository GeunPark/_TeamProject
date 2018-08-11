#pragma once
#include "gameNode.h"
#include "factory.h"
#include "item.h"
#include "effect.h"

class foxPlayer;
class enemyManager;

struct itemPos
{
	float x;
	float y;

};

#define MAX_HEALTHLARGE 5
#define MAX_HEALTHSMALL 5
#define MAX_MANABIG 5
#define MAX_MANASMALL 5
#define MAX_ITEMBOX 4

class itemManager : public gameNode
{
private:
	foxPlayer * _player;
	enemyManager* _eMG;
	effect* _effect;


	factory2* _itemFactory;
	//필드아이템
	vector<item*> _vItem;

	//드랍코인
	vector<item*> _vCoinGold;
	//vector<item*>::iterator _viCoinGold;
	vector<item*> _vCoinSilver;
	//vector<item*>::iterator _viCoinSilver;
	vector<item*> _vCoinBronze;
	//vector<item*>::iterator _viCoinBronze;

	vector<item*> _vItemBox;

	itemPos _healthLargePos[MAX_HEALTHLARGE];
	itemPos _healthSmallPos[MAX_HEALTHSMALL];
	itemPos _manaBigPos[MAX_MANABIG];
	itemPos _manaSmallPos[MAX_MANASMALL];
	itemPos _itemBoxPos[MAX_ITEMBOX];
	

	float enemyX;
	float enemyY;
	int gold;
	int silver;
	int bronze;

	//int boxNum;

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
