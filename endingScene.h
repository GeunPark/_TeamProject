#pragma once
#include "gameNode.h"
#include "foxPlayer.h"

class endingScene :	public gameNode
{
private:
	foxPlayer * _player;	
	image* pixel;
	image* bg;
	image* tree;
	image* alphaBg;
	int alpha;
	int index, count;

public:
	endingScene();
	~endingScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};

