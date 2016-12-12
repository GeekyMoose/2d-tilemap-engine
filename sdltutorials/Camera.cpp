#include "Camera.h"

Camera Camera::cameraControl;

Camera::Camera(){
	x			= 0;
	y			= 0;
	targetX		= NULL;
	targetY		= NULL;
	targetMode	= TARGET_MODE_NORMAL;
}

void Camera::moveCamera(int moveX, int moveY){
	x += moveX;
	y += moveY;
}

int Camera::getX(){
	//If no target, return current position
	if(targetX==NULL){
		return x;
	}
	//Here, means target set, return position according to camera mode
	if(targetMode==TARGET_MODE_CENTER){
		return *targetX-(SCREEN_WIDTH/2);
	}
	return *targetX;
}

int Camera::getY(){
	//If no target, return current position
	if(targetY==NULL){
		return y;
	}
	//Here, means target set, return position according to camera mode
	if(targetMode==TARGET_MODE_CENTER){
		return *targetY-(SCREEN_HEIGHT/2);
	}
	return *targetY;
}

void Camera::setPosition(float posX, float posY){
	x = posX;
	y = posY;
}

void Camera::setTarget(float *posX, float* posY){
	targetX = posX;
	targetY = posY;
}