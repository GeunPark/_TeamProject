#pragma once
#include "gameNode.h"
#include "foxPlayer.h"

struct tagWorld
{
	image* img;
	float x, y;
	int count, index;
	int alpha;
};
class worldMapScene : public gameNode
{
private:
	tagWorld _backGround;
	tagWorld _wayPoint;
	tagWorld _wayRoad;
	tagWorld _stagePoint;
	tagWorld _stageTxt;
	tagWorld _townTxt;
	tagWorld _bossPoint;
	tagWorld _bossRoad;

	tagWorld _player;
	bool move;

	foxPlayer* _fox;
	//테스트 임시 변수
	int clearCount;
	int loopCount;

public:
	worldMapScene();
	~worldMapScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};

