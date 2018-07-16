#include <iostream>
#include <thread>
#include <vector>
#include <memory>
#include <fstream>
#include <string>
#include <queue>
#include <unordered_map>

#include "computePi.hpp"
#include "mutex.hpp"


void threadWorker(std::uint16_t threadNum, piThreader& eatPi) {
    while(!eatPi.empty()){
        eatPi.lock();
        int task = eatPi.pop_front();
        eatPi.unlock();

        unsigned int digi = computePiDigit(task);
        std::string strPiDigit = std::to_string(digi);

        eatPi.lock();
        eatPi.mapInsert(task,strPiDigit);
        std::cout <<".";
        std::cout.flush();
        eatPi.unlock();
    }
}

void printPi(std::string number) {
 
    std::ifstream inFile;
    inFile.open("../pi.txt");
    if (inFile) {
    int count = 0;
    while (!inFile.eof()){
        std::string ch = " ";
        inFile >>  ch;
        for (int i = 0; i < ch.length(); ++i){
            if (ch[i] == '_'){
                std::cout << " ";
            }
            else if (ch[i] == '*'){
                std::cout << number[count];
                ++count;
            }
            else {
                    std::cout << ch[i];
                }
            }
            std::cout << std::endl;
    }
    inFile.close();
    }
    else {
        std::cout << "3." << number << std::endl;
    }
}

int main(void) {

    piThreader eatPi(1000);

	// Make as many threads as there are CPU cores
    // Assign them to run our threadWorker function, and supply arguments as necessary for that function
	std::vector<std::shared_ptr<std::thread>> threads;
	for (std::uint16_t core = 0; core < std::thread::hardware_concurrency(); core++)
        // The arguments you wish to pass to threadWorker are passed as
        // arguments to the constructor of std::thread
		threads.push_back(std::make_shared<std::thread>(threadWorker, core, std::ref(eatPi)));

	//
	// Wait for all of these threads to complete

	for (auto&& thread : threads){
		thread->join();
    }
    std::cout << std::endl << std::endl;
    //
    // Convert unordered map<int, string> to string then use that
    // to print to the console in the shape of pi
    printPi(eatPi.readMap());
	return 0;
}
