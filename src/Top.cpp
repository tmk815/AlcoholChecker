#include "Top.h"

void Top::setup(){
    top_image.load("image/top.png");
}


//--------------------------------------------------------------
void Top::update(){

}

//--------------------------------------------------------------
void Top::draw(){
    top_image.draw(0,0, 500*2,720*2);

}

void Top::mousePressed(int x, int y, int button){

}

string Top::getName(){
    return "Top";
}
