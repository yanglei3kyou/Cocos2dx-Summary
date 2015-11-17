//
//  CSiMonsterManager.h
//  CCSummary
//
//  Created by yanglei on 15/11/16.
//
//

#ifndef CSiMonsterManager_h
#define CSiMonsterManager_h
#include "cocos2d.h"
#include "CSiMonster.h"

using namespace cocos2d;

#define MAX_MONSTER_RUN 10

class CSiMonsterManager: public Node {
public:
    virtual bool init();
    CREATE_FUNC(CSiMonsterManager);
    
    virtual void update(float dt);
    
    void bindPlayer(CSiPlayer *player);
    
private:
    void createMonsters();
    
private:
    Vector<CSiMonster *> m_monsterArr;
    CSiPlayer *m_player;
    
};


#endif /* CSiMonsterManager_h */
