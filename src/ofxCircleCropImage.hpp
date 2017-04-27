//
//  ofxCircleCropImage.hpp
//
//  Created by HirokiNaganuma on 4/27/17.
//
//  The MIT License
//

#ifndef ofxCircleCropImage_hpp
#define ofxCircleCropImage_hpp

#include "ofMain.h"

class ofxCircleCropImage{
public:
    void setup();
    void load(string path);
    void update();
    void draw();
    void draw(float x, float y, float size);
    void draw(float x, float y, float w, float h);

private:
    ofImage img;
    ofFbo fbo;
    float center_x;
    float center_y;
    float size;
};

#endif /* ofxCircleCropImage_hpp */
