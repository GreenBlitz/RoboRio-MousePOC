#include "Mouse.h"

Mouse::Mouse() {
	mouseFile = open(MOUSE_PATH, O_RDONLY);
	if (NULL == mouseFile) {
		//TODO: handle error
	}	
}

int Mouse::Update() {
    char buffer[3];
    int nread = -1;

    MouseData result;
    nread = read(mouseFile, buffer, 3);
    if (nread == -1) {
        return -1;
    }
    data.metadata = buffer[0];
    data.x = buffer[1];
    data.y = buffer[2];
    return 0;
}

unsigned int Mouse::GetX(){
	return data.x;
}

unsigned int Mouse::GetY(){
	return data.y;
}
