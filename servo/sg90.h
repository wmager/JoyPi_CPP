#ifndef SG90_H // include guard
#define SG90_H
class Sg90{
public:
    Sg90(int pin, int direction);
    ~Sg90();
    int currentDirection();
    void setDirection(int direction, int speed);
    void setDirection(int direction);

private:
    int   pin_;
    int direction_;
};

#endif /* SG90_H */