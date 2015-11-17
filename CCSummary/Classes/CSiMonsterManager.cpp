//
//  CSiMonsterManager.cpp
//  CCSummary
//
//  Created by yanglei on 15/11/16.
//
//

#include <stdio.h>
#include "CSiMonsterManager.h"
#include "CSiPlayer.h"
#include "CSiMonster.h"

bool CSiMonsterManager::init() {
    createMonsters();
    this->scheduleUpdate();
        
    return true;
}

void CSiMonsterManager::update(float dt) {
    for (auto monster : m_monsterArr) {
        if (monster->isAlive()) {
            monster->setPositionX(monster->getPositionX()-4);
            
            if (monster->getPositionX() < 0) {
                monster->hide();
            } else if (monster->isCollideWithPlayer(m_player)) {
                m_player->hit();
                monster->hide();
            }
            
            
            
        } else {
            monster->show();
        }
    }
}

void CSiMonsterManager::createMonsters() {
    CSiMonster *monster = NULL;
    Sprite *sprite = NULL;
    
    for (int i = 0; i < MAX_MONSTER_RUN; i++) {
        monster = CSiMonster::create();
        monster->bindSprite(Sprite::create("monster.png"));
        monster->reset();
        this->addChild(monster);
        
        m_monsterArr.pushBack(monster);
    }
}

void CSiMonsterManager::bindPlayer(CSiPlayer *player) {
    m_player = player;
}