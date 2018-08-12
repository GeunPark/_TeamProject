#pragma once
#include "gameNode.h"
class endingScene :	public gameNode
{
private:

public:
	endingScene();
	~endingScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};

