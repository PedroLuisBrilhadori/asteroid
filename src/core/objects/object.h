#include "../game/event/event.cpp"

class Object
{

private:
    float x;
    float y;
    float xVel;
    float yVel;
    float speed;

    float width;
    float height;

public:
    Object();
    void draw();
    void udpate(Event event);
};