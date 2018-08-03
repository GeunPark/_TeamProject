#pragma once
#include "enemy.h"
#include "item.h"

class factory // �ֳʹ�
{
public:
	virtual enemy* createEnemy(ENEMY_TYPE) = 0;
};

class enemyFactory : public factory
{
public:
	enemy * createEnemy(ENEMY_TYPE type);
};


class factory2 // ������
{
public:
	virtual item* createItem(ITEM_TYPE) = 0;

};
class itemFactory : public factory2
{
	item* createItem(ITEM_TYPE type);
};