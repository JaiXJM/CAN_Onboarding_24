#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <string>

#include "can_global.hpp"
#include "can_threads.cpp"
#include "protection_value.cpp"

#include "assert.cpp"

#define TEST_TIME 3000
#define TEST_COUNT 100

void signal_thread();
std::string tabulate_results();

int main(int argc, char* argv[]){
    std::cout<<"\nTesting Protection Values"<<std::endl;

    //In: 0b0010     rc1      Expected: 0b1101
    std::cout<<"Case 1:  "<<(assert(protection_value(0b0010,1,4), 0b1101)?"Pass":"Fail")<<std::endl;
    //In: 0b1101000  rc3   Expected: 0b0010101
    std::cout<<"Case 2a: "<<(assert(protection_value(0b1101000,3,7), 0b0010101)?"Pass":"Fail")<<std::endl;
    //In: 0b1101000  rc2   Expected: 0b0010101
    std::cout<<"Case 2b: "<<(assert(protection_value(0b1101000,2,7), 0b0010110)?"Pass":"Fail")<<std::endl;
    //In: 0b1101000  rc1   Expected: 0b0010101
    std::cout<<"Case 2c: "<<(assert(protection_value(0b1101000,1,7), 0b0010111)?"Pass":"Fail")<<std::endl;
    //In: 0b1101000  rc0   Expected: 0b0010101
    std::cout<<"Case 2d: "<<(assert(protection_value(0b1101000,0,7), 0b0011000)?"Pass":"Fail")<<std::endl;
    //In: 0b1        rc1   Expected: 0b10
    std::cout<<"Case 3a: "<<(assert(protection_value(0b1,1,1), 0b10)?"Pass":"Fail")<<std::endl;
    //In: 0b1        rc3   Expected: 0b00
    std::cout<<"Case 3b: "<<(assert(protection_value(0b1,3,0), 0b00)?"Pass":"Fail")<<std::endl;

    std::cout<<"\n\nEmpirically Testing Thread Syncronization..."<<std::flush;

    std::thread processes[TEST_COUNT];
    for(int i = 0; i<TEST_COUNT; i++)
        processes[i] = std::thread(&process_thread);
    
    std::thread timer = std::thread(&signal_thread);
    begin = true;
    int count = 0;

    while(!thread_kill){
        std::cout<< ((count%4 == 0)?"\b\b\b   \b\b\b":".")<<std::flush;
        count++;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    std::cout<<"\nTest Complete. Attempting to join threads (If this does not complete promptly, test is a failure) "<<std::endl;
    timer.join();
    for(int i = 0; i<TEST_COUNT; i++){
        processes[i].join();
    }

    std::cout<< "Rejoined. Result: "<<tabulate_results()<<"\n\n"<<std::endl;
    return 0; //Threads now unallocated via loss of scope.
}

void signal_thread(){
    std::this_thread::sleep_for(std::chrono::milliseconds(TEST_TIME));
    kill_mutex.lock();
    thread_kill = true;
    kill_mutex.unlock();
}


std::string tabulate_results(){
    std::string to_return = "";
    if(collisions == 0){
        to_return = to_return + "Success | ";
        to_return = to_return + std::to_string(est_num_pkt)+" pkts"; 
    }else {
        to_return = to_return + "Failure | ";
        to_return = to_return + std::to_string(collisions)+" Collisions, "+std::to_string(est_num_pkt)+" pkts";
    }
    return to_return;
}


