#pragma once
#include "gameNode.h"

#define MAXHEART 10
class foxPlayer;
class shop;

struct tagBox
{
	RECT _rc;
	float _x, _y;
	image* _img;
	int _numChk;
	float _now;
	int _MaxNum;
};

class UI : public gameNode
{
private:

	int maxHeart;
	tagBox _heart[MAXHEART];
	tagBox _manaBar;
	tagBox _mana;
	tagBox _manaUp;

	tagBox _ArrowChoice[5];
	tagBox _MagicChoice[5];
	tagBox _nowArrow;
	tagBox _nowMagic;


	image * _manaWa;
	image * _nowState[2];

	image * _number[4];
	image * _goldImage;
	image * _warningLine;
	image * _magicImage[5];
	foxPlayer * _player;
	shop* _shop;
	int manaUpNum;
	int manaWarning;
	int MaxMana;

	int _frameNum[4];
	bool frameNumChk[4];
	bool _isManaUse;
	int _goldNum;

	int b = 0;
	int _heartNum;
	bool _isManaWarning;
	int _arrowNum;
	int _arrowNumChk = 0;
	int _magicNum;
	int _magicNumChk;
public:

	HRESULT init(void);
	void release(void);
	void update(void);
	void render();

	void mana();
	void heart();
	void nowHeart();
	void nowArrow();
	void nowMagic();



	void nowGold();

	void setArrowNumChk(int anc) { _arrowNumChk = anc; }
	void setArrowNum(int an) { _arrowNum = an; }
	int getArrowNumChk() { return _arrowNumChk; }
	int getArrowNum() { return _arrowNum; }

	//get, set �Լ���
	void setPlayerManager(foxPlayer* player) { _player = player; }
	void setShopLink(shop* shop) { _shop = shop; }
	//void setPLink(foxPlayer* py) { _players = py; }
	UI() {}
	~UI() {}
};

