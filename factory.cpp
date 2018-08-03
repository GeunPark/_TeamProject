#include "stdafx.h"
#include "factory.h"

enemy * enemyFactory::createEnemy(ENEMY_TYPE type)
{
	enemy* _enemy;
	switch (type)
	{
	case DRAGONFLY:
		_enemy = new dragonFly;
		break;
	case VINEMAN:
		_enemy = new vineMan;
		break;

	case BUG:
		_enemy = new bug;
		break;

	case TREEMAN:
		_enemy = new treeMan;
		break;

	case PLANTFROG:
		_enemy = new plantFrog;
		break;

	case ELECTRICEEL:
		_enemy = new electriceel;


	default:
		//´©±¸³Ä ³Í??
		break;
	}

	_enemy->init();

	return _enemy;
}

item * itemFactory::createItem(ITEM_TYPE type)
{
	item* _item;
	switch (type)
	{
	case HEALTH_LARGE:
		_item = new healthLarge;
		break;
	case HEALTH_SMALL:
		_item = new healthBig;
		break;

	case MANA_BIG:
		_item = new manaBig;
		break;

	case MANA_SMALL:
		_item = new manaSmall;
		break;
	case GOLD_COIN:
		_item = new goldCoin;
		break;
	case SILVER_COIN:
		_item = new silverCoin;
		break;
	case BRONZE_COIN:
		_item = new bronzeCoin;
		break;


	default:
		//´©±¸³Ä ³Í??
		break;
	}

	_item->init();

	return _item;
}