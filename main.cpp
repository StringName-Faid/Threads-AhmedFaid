#include <iostream>
#include <thread>
#include <vector>
#include <stdlib.h>

using namespace std;

int NumGenerator(int max, int min){
     int n = (max - min + 1);
     int random = rand()%n + 1;

     return random;
}

void filler(vector<int> &container){
    container.resize(NumGenerator(10000, 100000));

    for(int i=0; i < container.size(); i++){
        container [i] = NumGenerator(0,100000);
    }

}

void printer(vector<int> &container){
    for(int i=0; i < container.size(); i++){
        cout << container[i] << endl;
    }
}

int main(){

    vector<int> firstContainer;
    vector<int> secondContainer;
    vector<int> thirdContainer;

    thread t1(&filler, &firstContainer);
    thread t2(&filler, &secondContainer);
    thread t3(&filler, &thirdContainer);

    thread t4(&printer, &firstContainer);
    thread t5(&printer, &secondContainer);
    thread t6(&printer, &thirdContainer);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    return 0;
}
