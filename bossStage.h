#pragma once
#include "gameNode.h"
#include "foxPlayer.h"
#include "UI.h"
#include "bullet.h"
#include "enemy.h"
#include "enemyManager.h"
#include "itemManager.h"
struct tagLeaf
{
	int x, y;
	image* img;
	int count, index;
};
class bossStage : public gameNode
{
private:
	image* summer;
	image* fall;
	image* pixel;
	tagLeaf leaf[20];

	foxPlayer* _player;
	enemyManager* _eMG;
	itemManager* _iMG;

	//beeBullet* _beeBullet;
	bee* _bee;


	UI* _ui;

	int count;
	int alpha;
	bool isSeason;
	

	RECT rc;
	RECT exit;


public:
	bossStage();
	~bossStage();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};

