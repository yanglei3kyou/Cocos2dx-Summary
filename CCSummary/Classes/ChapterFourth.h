//
//  ChapterFourth.h
//  CCSummary
//
//  Created by yanglei on 15/11/11.
//
//

#ifndef ChapterFourth_h
#define ChapterFourth_h

#include "cocos2d.h"

//#include "editor-support/cocostudio/CCSGUIReader.h"
#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;

class ChapterFourth: public Layer {
public:
    static Scene *createScene();
    virtual bool init();
    CREATE_FUNC(ChapterFourth);
    
    cocos2d::ui::ImageView * m_xiaoruoImg;
    cocos2d::ui::LoadingBar * m_loadingBar;
    void AddSomeKnowledgeAboutPlayMusic();
    void AddSomeKnowledgeAbout9Sprite();
    
    void AddSomeKnowledgeAboutCocoStudio();

    void AddSomeKnowledgeAboutLoadingBar();
    
    void onClick(Ref* psender, cocos2d::ui::Widget::TouchEventType type);
    void moveLoadingBar(Ref* pSender, cocos2d::ui::Widget::TouchEventType type);
};

#endif /* ChapterFourth_h */
