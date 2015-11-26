#ifndef ___MOUSE_H__
#define ___MOUSE_H__

#include <unistd.h>
#include <fcntl.h>

#define MOUSE_PATH "/dev/input/mouse0"

typedef struct {
	char metadata;
	unsigned int x;
	unsigned int y;
} MouseData;

class Mouse {
private:
	MouseData data;
	int TotalX;
	int TotalY;
	int mouseFile;
public:
	Mouse();
	int Update();
	unsigned int GetX();
	unsigned int GetY();
};

#endif //___MOUSE_H__
