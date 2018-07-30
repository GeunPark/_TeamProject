#pragma once
#include "gameNode.h"

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

