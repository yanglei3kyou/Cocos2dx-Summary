//
//  CSiPlayer.h
//  CCSummary
//
//  Created by yanglei on 15/11/15.
//
//

#ifndef CSiPlayer_h
#define CSiPlayer_h

#include "cocos2d.h"
#include "CSiEntity.h"

USING_NS_CC;

#define JUMP_ACTION_TAG 1

class CSiPlayer: public CSiEntity {
public:
    CSiPlayer();
    ~CSiPlayer();
    
    CREATE_FUNC(CSiPlayer);
    virtual bool init();
    
    void jump();
    
    void hit();
public:
    int getiHP();
    
    void resetData();
    
private:
    bool m_isJumping;
    int m_iHP;
    
    Size visibleSize;

};

#endif /* CSiPlayer_h */
