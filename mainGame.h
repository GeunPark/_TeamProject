#pragma once
#include "gameNode.h"
/*�����δ� �� ������ϸ� �߰����ش�*/
#include "loadingScene.h"
#include "startScene.h"
#include "townScene.h"
#include "stage1.h"
#include "bossStage.h"

#include "foxPlayer.h"
#include "UI.h"
#include "shop.h"
#include "enemyManager.h"
#include "itemManager.h"
//#include "effectManager.h"

class mainGame : public gameNode
{
private:

	foxPlayer * _player;
	UI* _ui;
	shop* _shop;
	enemyManager* _em;
	itemManager* _im;
	//effectManager* _effMG;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	mainGame() {}
	~mainGame() {}
};

