//
//  CSiEntity.cpp
//  CCSummary
//
//  Created by yanglei on 15/11/15.
//
//

#include "CSiEntity.h"

CSiEntity::CSiEntity() {
    m_sprite = NULL;
}

CSiEntity::~CSiEntity() {
    
}

Sprite * CSiEntity::getSprite() {
    return this->m_sprite;
}

void CSiEntity::bindSprite(cocos2d::Sprite *sprite) {
    this->m_sprite = sprite;
    this->addChild(sprite);
    
    Size size = m_sprite->getContentSize();
    m_sprite->setPosition(Vec2(size.width/2, size.height/2));
    this->setContentSize(size);
}

