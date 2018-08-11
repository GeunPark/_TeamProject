#pragma once
#include "gameNode.h"

enum magicType
{
	THUNDER,
	TORNADO,
	NIGHTMARE
};
struct tagMagic
{
	RECT _rc;
	image* _img;
	image* _img2;
	float _x, _y;
	float _angle;
	float _speed;
	int _count;
	int _index;
	
};
class magic : public gameNode
{
	bool _angleChk;
	tagMagic thunder;
	tagMagic tornado;
	tagMagic nightMare;

	vector<tagMagic> _vthunder;
	vector<tagMagic> _vnightMare;
public:
	HRESULT init();
	void release(void);
	void update(void);
	void render(void);

	void thunderInit();
	void tornadoInit();
	void nightMareInit();

	void thunderImageMove();
	void nightMarImageMove();
	void nightMove(float a, float b);
	void a();
	vector<tagMagic> getvthunder() {return _vthunder;}
	vector<tagMagic> getvnightMare() { return _vnightMare; }

	void setrc(RECT rc) {_vnightMare[0]._rc = rc;}
	RECT rc() { return _vnightMare[0]._rc; }

	void setvthundwe(int a,int b);

	magic() {}
	~magic() {}
};

