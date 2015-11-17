//
//  CSiMonster.h
//  CCSummary
//
//  Created by yanglei on 15/11/16.
//
//

#ifndef CSiMonster_h
#define CSiMonster_h

#include "cocos2d.h"
#include "CSiEntity.h"
#include "CSiPlayer.h"

using namespace cocos2d;

class CSiMonster: public CSiEntity {
public:
    CSiMonster();
    ~CSiMonster();
    virtual bool init();
    CREATE_FUNC(CSiMonster);
    
    void show();
    void hide();
    void reset();
    bool isAlive();
    
    bool isCollideWithPlayer(CSiPlayer *player);
    
private:
    bool m_isAlive;
    
};

#endif /* CSiMonster_h */
