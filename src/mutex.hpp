#pragma once
#include <mutex>
#include <queue>
#include <unordered_map>

class piThreader {
    public:
        piThreader(int totalTasks);
        ~piThreader();
        void lock();
        void unlock();
        int pop_front();
        bool empty();
        void mapInsert(int taskNum, std::string piDigit);
        std::string readMap();

    private:
    std::queue<int> taskQueue;
    std::mutex piMutex;
    std::unordered_map<int, std::string> piMap;
};
