#pragma once
#include "gameNode.h"
#include "enemyManager.h"
#include "foxPlayer.h"


struct imgInfo
{
	float _x, _y;
	image * _img;
};

enum state
{
	NORMAL,
	ICE
};

struct tagBoxs
{
	int x, y;
	bool isActive = true;
	RECT rc;
	image* _img;
};

class stage1 : public gameNode
{
private:

	//에너미매니져 할당
	enemyManager * _eMG;

	//플레이어 할당
	foxPlayer* _player;

	state _state;
	tagBoxs _cam;
	imgInfo _river[6];
	imgInfo waterfall[3];
	imgInfo waterfalls[3];
	//ū Ǯ
	tagBoxs _bush[10];
	vector<tagBoxs> _vBush;
	vector<tagBoxs>::iterator _viBush;

	image* feild;
	image* feildpixel;

	//기훈아 내가 여기에다가 레이어 배경 두개 일단 입혀놓을게!!
	imgInfo _normalBack1;
	imgInfo _normalBack2;
	imgInfo _iceBack1;
	
	float _riverX[10], _riverY[10];

	int _count;
	int _index;
	int _count1;
	int _index1;
	

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
	stage1() {}
	~stage1() {}
};

