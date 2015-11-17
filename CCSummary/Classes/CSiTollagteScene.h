//
//  CSiTollagteScene.h
//  CCSummary
//
//  Created by yanglei on 15/11/15.
//
//

#ifndef CSiTollagteScene_h
#define CSiTollagteScene_h

#include "cocos2d.h"
#include "CSiPlayer.h"
#include "cocos-ext.h"

#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

class CSiTollgateScene: public Layer {
public:
    static Scene *createScene();
    virtual bool init();
    CREATE_FUNC(CSiTollgateScene);
    
    virtual void update(float dt);
private:
    void initBG();
    
    void loadUI();
    
    void jumpEven(Ref* psender, cocos2d::ui::Widget::TouchEventType type);

    Sprite *m_bgSprite1;
    Sprite *m_bgSprite2;
    CSiPlayer *m_player;
    
    Size visibleSize;
    
    int m_iScore;
    Text *m_scoreLab;
    LoadingBar *m_hpBar;
    
};


#endif /* CSiTollagteScene_h */
