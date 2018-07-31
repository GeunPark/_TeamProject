#pragma once
#include "gameNode.h"

enum EnemyState
{
	E_LEFT = 0,
	E_RIGHT,

};
enum EnemyAction
{
	E_IDLE = 0,
	E_SPAWN,
	E_MOVE,
	E_ATTACK,
	E_DEAD
};

class player;

class enemy : public gameNode
{
protected:
	//상호참조
	player * _player;
	// goldCoin* _goldCoin;
	// silverCoin* _silverCoin;
	// bronzeCoin* _bronzeCoin;


	EnemyState enemyState;
	EnemyAction enemyAction;

	image * _image[5];		//에너미 이미지
	RECT _rc;			//충돌용 렉트
	RECT _sensor;
	RECT _collRc;
	RECT _attRc;
	RECT _tongueRc;

	float _x, _y;
	float gravity;

	//프레임 이미지를 돌리기 위한 변수들
	int _count;
	int _currentFrameX;
	int _currentFrameY;

	//움직임패턴
	int _moveCount;
	bool isJump;
	//혀발사
	bool isTongue;

	//랜덤으로 총알 발사 쿨타임 주기
	int _fireCount;
	int _rndFireCount;

	//item drop
	bool isDead;
	bool isDrop;
	int _gold;
	int _silver;
	int _bronze;




public:
	HRESULT init(void);
	HRESULT init(const char* idleImageName, const char* spawnImageName, const char* moveImageName, const char* attackImageName, const char* deadImageName, POINT position, int currentFrameX, int moveCount, int gold, int silver, int bronze);
	void release(void);
	void update(void);
	void render(float FX, float FY);

	virtual void move() = 0;		//업데이트에 넣기
	virtual void attack() = 0;
	//virtual void pixelCollision() = 0; 

	void draw(float FX, float FY);		//렌더 안에 넣기
	void animation();	//업데이트에 넣기
	//void enemyDead();
	//void coinDrop();

	bool bulletCountFire();

	RECT getRect() { return _rc; }
	RECT getColliRect() { return _collRc; }
	RECT getSensorRect() { return _sensor; }
	RECT getAttRect() { return _attRc; }
	RECT getTongueRect() { return _tongueRc; }



	image* getEnemyImage(int i) { return _image[i]; }

	float getX() { return _x; }
	void setX(float x) { _x = x; }
	float getY() { return _y; }
	void setY(float y) { _y = y; }
	float getGravity() { return gravity; }
	void setGravity(float _gravity) { gravity = _gravity; }
	void setIsJump(bool _isJump) { isJump = _isJump; }

	void setEnemyAction(EnemyAction _enemyAction) { enemyAction = _enemyAction; }
	EnemyAction getEnemyAction() { return enemyAction; }
	void setEnemyState(EnemyState _enemyState) { enemyState = _enemyState; }

	void setPlayerLink(player* player) { _player = player; }

	//죽음
	int getCurrentFrameX() { return _currentFrameX; }

	//아이템
	bool getIsDead() { return isDead; }
	bool getIsDrop() { return isDrop; }
	int getGold() { return _gold; }
	int getSilver() { return _silver; }
	int getBronze() { return _bronze; }


	enemy() {}
	virtual ~enemy() {}
};

class dragonfly : public enemy
{

private:
	float angle = 0;

public:

	void move();
	void attack();
	//void pixelCollision();

};
class vineman : public enemy
{

private:
	//float angle = 0;

public:

	void move();
	void attack();
	//void pixelCollision();
};

class bug : public enemy
{

private:
	//float angle = 0;

public:

	void move();
	void attack();
	//void pixelCollision();

};

class treeman : public enemy
{

private:
	//float angle = 0;

public:

	void move();
	void attack();
	//void pixelCollision();

};

class plantfrog : public enemy
{

private:
	float angle = PI / 3;


	int randNum;
public:

	void move();
	void attack();


	//void pixelCollision();
};

class electriceel : public enemy
{

private:
	float angle = PI / 3;


	int randNum;
public:

	void move();
	void attack();


	//void pixelCollision();
};