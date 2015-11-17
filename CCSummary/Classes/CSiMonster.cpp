//
//  CSiMonster.cpp
//  CCSummary
//
//  Created by yanglei on 15/11/16.
//
//

#include "CSiMonster.h"
USING_NS_CC;

CSiMonster::CSiMonster() {
    m_isAlive = true;
}

CSiMonster::~CSiMonster() {
    
}

bool CSiMonster::init() {
    return true;
}

void CSiMonster::show() {
    if (getSprite() != NULL) {
        setVisible(true);
        m_isAlive = true;
    }
}

void CSiMonster::hide() {
    if (getSprite() != NULL) {
        setVisible(false);
        reset();
        m_isAlive = false;
    }
}

void CSiMonster::reset() {
    if (getSprite() != NULL) {
        setPosition(Vec2(800+CCRANDOM_0_1()*2000, 200-CCRANDOM_0_1()*100));
    }
}

bool CSiMonster::isAlive() {
    return m_isAlive;
}

bool CSiMonster::isCollideWithPlayer(CSiPlayer *player) {
    Rect entityRect = player->getBoundingBox();
    Point monsterPos = getPosition();
    return entityRect.containsPoint(monsterPos);
}




