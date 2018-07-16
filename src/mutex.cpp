#include "mutex.hpp"

#include <mutex>
#include <queue>
#include <unordered_map>

piThreader::piThreader(int totalTasks){
    for (int i = 1; i <= totalTasks; ++i){
        taskQueue.push(i);
    }
};

piThreader::~piThreader(){};

void piThreader::lock(){
    piMutex.lock();
};

void piThreader::unlock(){
    piMutex.unlock();
};

int piThreader::pop_front(){
    int task = taskQueue.front();
    taskQueue.pop();
    return task;    
};

bool piThreader::empty(){
    return taskQueue.empty();
};

void piThreader::mapInsert(int taskNum, std::string piDigit){
    piMap.insert(std::make_pair(taskNum, piDigit));
};

std::string piThreader::readMap(){
    std::string PI;
    for (int i = 1; i <= piMap.size(); ++i){
        auto pi = piMap.find(i);
        PI += pi->second;
    }
    return PI;
};

