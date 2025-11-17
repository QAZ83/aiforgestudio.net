#ifndef ENGINE_H
#define ENGINE_H

class Engine {
public:
    Engine() = default;
    ~Engine() = default;
    
    bool init();
    void initialize();
    void update();
};

#endif // ENGINE_H
