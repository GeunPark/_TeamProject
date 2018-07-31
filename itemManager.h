#pragma once
#include "gameNode.h"
#include "item.h"

class player;
class enemyManager;

enum ItemKind
{
	HEALTHLARGE = 0,
	HEALTHBIG,
	HEALTHSMALL,
	MANABIG,
	MANASMALL,
	COINCOPPER,
	COINSILVER,
	COINGOLD
};
class itemManager : public gameNode
{
private:
	player * _player;
	enemyManager* _eMG;

	ItemKind _itemKind;

	vector<item*> _vHealthLarge;
	vector<item*> ::iterator _viHealthLarge;

	vector<item*> _vHealthBig;
	vector<item*> ::iterator _viHealthBig;

	vector<item*> _vManaBig;
	vector<item*> ::iterator _viManaBig;

	vector<item*> _vManaSmall;
	vector<item*> ::iterator _viManaSmall;

	vector<item*> _vCoinGold;
	vector<item*> ::iterator _viCoinGold;

	vector<item*> _vCoinSilver;
	vector<item*> ::iterator _viCoinSilver;

	vector<item*> _vCoinBronze;
	vector<item*> ::iterator _viCoinBronze;

	healthLarge* _healthLarge;

	//bronzeCoin* _bronzeCoin;

	float enemyX;
	float enemyY;
	int gold;
	int silver;
	int bronze;

public:

	HRESULT init(void);

	void release(void);
	void update(void);
	void render(float FX, float FY);


	void setCoin(float _enemyX, float _enemyY, int _gold, int _silver, int _bronze)
	{
		enemyX = _enemyX;
		enemyY = _enemyY;
		gold = _gold;
		silver = _silver;
		bronze = _bronze;
	}

	void dropCoin();

	void setItem();

	//void dropCoin();

	//void pixelCollision(vector<item*> vCoin);

	void setPlayerLink(player* player) { _player = player; }
	void setEMGLink(enemyManager* eMG) { _eMG = eMG; }

	itemManager() {}
	~itemManager() {}
};
