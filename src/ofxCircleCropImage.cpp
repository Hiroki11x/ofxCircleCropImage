//
//  ofxCircleCropImage.cpp
//
//  Created by HirokiNaganuma on 4/27/17.
//
//  The MIT License
//

#include "ofxCircleCropImage.hpp"

//--------------------------------------------------------------
void ofxCircleCropImage::setup(){
    ofSetCircleResolution(64);
}

//--------------------------------------------------------------
void ofxCircleCropImage::load(string path){
    img.load(path);
    fbo.allocate(img.getWidth(), img.getHeight(),GL_RGBA);
    this->size = min(img.getWidth(), img.getHeight());
    setup();
}

//--------------------------------------------------------------
void ofxCircleCropImage::update(){
    center_x = img.getWidth()/2;
    center_y = img.getHeight()/2;
    fbo.begin();
    {
        ofClear(0,0,0,0);
        ofSetColor(255);
        ofDrawEllipse(center_x, center_y, this->size, this->size);
    }
    fbo.end();
    img.getTexture().setAlphaMask(fbo.getTexture());
}

//--------------------------------------------------------------
void ofxCircleCropImage::draw(){
    img.draw(-img.getWidth()/2,-img.getHeight()/2,img.getWidth(),img.getHeight());
}

void ofxCircleCropImage::draw(float x, float y, float size){
    float scale = size/this->size;
    ofPushMatrix();
    ofTranslate(x, y);
    ofScale(scale,scale);
    img.draw(-img.getWidth()/2,-img.getHeight()/2,img.getWidth(),img.getHeight());
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofxCircleCropImage::draw(float x, float y, float w, float h){
    float ratio_x = w/img.getWidth();
    float ratio_y = h/img.getHeight();
    ofPushMatrix();
    ofTranslate(x, y);
    ofScale(ratio_x,ratio_y);
    img.draw(-img.getWidth()/2,-img.getHeight()/2,img.getWidth(),img.getHeight());
    ofPopMatrix();
}
