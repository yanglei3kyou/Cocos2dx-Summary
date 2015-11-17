//
//  CSiPlayer.cpp
//  CCSummary
//
//  Created by yanglei on 15/11/15.
//
//

#include "CSiPlayer.h"
#include "FlowWord.h"

CSiPlayer::CSiPlayer() {
    m_isJumping = false;
    m_iHP = 1000;
}

CSiPlayer::~CSiPlayer() {
    
}

bool CSiPlayer::init() {
    visibleSize = Director::getInstance()->getVisibleSize();
    return true;
}

void CSiPlayer::jump() {
    if (getSprite() == NULL) {
        return ;
    }
    
    if (m_isJumping) {
        return ;
    }
    
    m_isJumping = true;
    
    auto jump = JumpBy::create(2.0, Vec2(0, 0), 250, 1);
    
    auto callFunc = CallFunc::create([&](){
        m_isJumping = false;
    });
    
    auto jumpActions = Sequence::create(jump,callFunc, NULL);
    this->runAction(jumpActions);
}

void CSiPlayer::hit() {
    if (getSprite() == NULL) {
        return ;
    }
    
    FlowWord *flowWord = FlowWord::create();
    this->addChild(flowWord);
    flowWord->showWord("-15", getSprite()->getPosition());
    
    m_iHP -= 15;
    if (m_iHP < 0) {
        m_iHP = 0;
    }
    
    auto backMove = MoveBy::create(0.1, Vec2(-20, 0));
    auto forwardMove = MoveBy::create(0.1, Vec2(20, 20));
    auto backRotate = RotateBy::create(0.1, -5, 0);
    auto forwardRotate = RotateBy::create(0.1, 5, 0);
    
    auto backActions = Spawn::create(backMove,backRotate, NULL);
    auto forwardActions = Spawn::create(forwardMove,forwardRotate, NULL);
    
    auto actions = Sequence::create(backActions,forwardActions, NULL);
    
    stopAllActions();
    
    resetData();
    runAction(actions);
    
}

void CSiPlayer::resetData() {
    if (m_isJumping) {
        m_isJumping = false;
    }
    
    setPosition(Vec2(90, 50));
    setScale(1.0f);
    setRotation(0);
}

int CSiPlayer::getiHP() {
    return this->m_iHP;
}

