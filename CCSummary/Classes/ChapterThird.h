//
//  ChapterThird.h
//  CCSummary
//
//  Created by yanglei on 15/11/11.
//
//

#ifndef ChapterThird_h
#define ChapterThird_h

#include "cocos2d.h"

using namespace cocos2d;

class ChapterThird: public Layer {
public:
    static Scene *createScene();
    virtual bool init();
    CREATE_FUNC(ChapterThird);
    
    Size visiableSize;
    
    void AddSomeLabel(Vec2 position);
    void AddSomeSprite(Vec2 position);
    
    void AddSomeMenu(Vec2 position);
    
    void menuCloseCallBack(Ref * psender);
    
    void AddSomeKnowledgeAboutValue();
    
    void AddSomeKnowledgeAboutVector();

    void AddSomeKnowledgeAboutMap();
};

#endif /* ChapterThird_h */
