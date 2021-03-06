#pragma once
#include "gameNode.h"
#include "enemyManager.h"
#include "itemManager.h"
#include "foxPlayer.h"
#include "UI.h"
#include "effect.h"
#include "effectManager.h"

struct imgInfo
{
	float _x, _y;
	int _count;
	int _index;
	image * _img;
};

enum state
{
	SUMMER,
	WINTER
};

struct tagBoxs
{
	int x, y;
	bool isActive = true;
	RECT rc;
	image* _img;
	int _count;
	int _index;
};

class stage1 : public gameNode
{
private:
	//플레이어 할당
	foxPlayer * _player;

	//에너미매니져 할당
	enemyManager * _eMG;

	//아이템매니져 할당
	itemManager * _iMG;

	effect* _effect;
	effectManager* _effMG;

	UI * _ui;


	state _state;
	tagBoxs _cam;
	imgInfo _river[20];

	imgInfo _waterfall[11];
	imgInfo _waterfalls[11];
	
	//ū Ǯ
	tagBoxs _bush[10];

	tagBoxs _bee[2];
	tagBoxs _iceBee[2];

	tagBoxs _neolttwigi[2];
	tagBoxs _brid[2];

	vector<tagBoxs> _vBush;
	vector<tagBoxs>::iterator _viBush;


	vector<effect*> _vEffect;


	image* feild;
	image* stageClearImg;
	//image* feild[4];
	image* feildIce;
	image* feildpixel;
	image*  _waterWheel;


	//기훈아 내가 여기에다가 레이어 배경 두개 일단 입혀놓을게!!
	imgInfo _normalBack1;
	imgInfo _normalBack2;

	imgInfo _winterBack1;
	imgInfo	_winterBack2;


	imgInfo _iceBack1;
	
	int _bagrandslide;
	int _b = 0;
	int _count1;
	int _index1;
	int bgCount;  //배경이 너무 빨리 움직여서 배경카운트만들엇엉 -세원-
	float _eftX[9],_eftY[9];
	float _bridAngle;
	float _bridSpeed;

	bool shopMode;
	bool _neolttwigiColls;

	bool isFrist = false;
	bool stageClearChk;
	int stageClearCount;
	
	//int _x, _y;
public:

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void imageMove();
	void cameraMove();
	void imagePosition();
	void images();
	void setState(state ste) { _state = ste; }
	//void beeInit();
	void eftInit();
	//void eftMove();

	void beecollision();
	state getState() { return _state; }
	//배경 움직이는 함수

	void bgMove();
	void stageClearInit();
	void stageClear();

	stage1() {}
	~stage1() {}
};

