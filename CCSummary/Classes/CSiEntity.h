//
//  CSiEntity.h
//  CCSummary
//
//  Created by yanglei on 15/11/15.
//
//

#ifndef CSiEntity_h
#define CSiEntity_h

#include "cocos2d.h"
USING_NS_CC;

class CSiEntity: public Node {
public:
    CSiEntity();
    ~CSiEntity();
    
    Sprite *getSprite();
    void bindSprite(Sprite *sprite);
private:
    Sprite *m_sprite;
};


#endif /* CSiEntity_h */
