#pragma once
#include "gameNode.h"

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
	state _state;
	tagBoxs _cam;
	//ū Ǯ
	tagBoxs _bush[10];
	vector<tagBoxs> _vBush;
	vector<tagBoxs>::iterator _viBush;

	image* feild;
	image* feildpixel;
	

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
	stage1() {}
	~stage1() {}
};

