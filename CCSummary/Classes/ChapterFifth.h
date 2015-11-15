//
//  ChapterFifth.h
//  CCSummary
//
//  Created by yanglei on 15/11/13.
//
//

#ifndef ChapterFifth_h
#define ChapterFifth_h

#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;


class ChapterFifth: public Layer {
public:
    static Scene * createScene();
    virtual bool init();
    
    Size visibleSize;
    Sprite *xiaoRuo;
    
    CREATE_FUNC(ChapterFifth);
    
    void AddFunctionAboutMoveTo();
    
    void AddFunctionAboutMoveBy();
    
    void AddFunctionAboutScaleTo();
    
    void AddFunctionAboutScaleBy();
    
    void AddFunctionAboutBlink();

    void AddFunctionAboutBezierTo();
    
    void AddFunctionAboutBezierBy();
    
    void AddFunctionAboutRepeatForever();
    
    void AddFunctionAboutSequenceAndSpawn();
    
    void AddFunctionAboutActionCallBack();
    
    void backHome();
    
    void AddFunctionAboutTouchEvent();
    
    void AddFunctionAboutTouchEventSample2();
    
    void AddFunctionAboutTouchEventSample3();
};




#endif /* ChapterFifth_h */
