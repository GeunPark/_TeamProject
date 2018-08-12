#pragma once
#include "gameNode.h"
#include "foxPlayer.h"
#include "UI.h"
#include "shop.h"

struct tagBackGround
{
	image* img;
	float x, y;
};

class townScene : public gameNode
{
private:
	foxPlayer * _player;
	UI* _ui;

	shop* _shop;

	tagBackGround _bg;
	tagBackGround _lyr1;
	tagBackGround _lyr2;
	tagBackGround _lyr3;
	tagBackGround _pixel;


	RECT _upgradeShopRc;
	RECT _magicShopRc;
	int shopCount = 0;

	bool _test = false;

public:
	townScene();
	~townScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	//void setTest(bool test) { _test = test; }
};

