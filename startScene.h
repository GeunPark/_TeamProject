#pragma once
#include "gameNode.h"
#define START 235
#define SETTING 360

struct tagWindow
{
	image* img;
	RECT rc;
	POINT pos;
	int count;
	bool turn;
};

class startScene : public gameNode
{
private:
	tagWindow _fox;
	tagWindow _bird;
	tagWindow _selectBox;

	image* _backGround;
	image* _logo;
	image* _button;
	
	image* _selectBg;
	image* _selectWindow;
	

	int alpha, alpha2;
	int count;

	int _enterCount;

public:
	startScene();
	~startScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void move();
	void selectMove();

};

