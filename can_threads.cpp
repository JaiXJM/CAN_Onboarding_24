#include "can_global.hpp"
#include "can_global.cpp"
#include "can_threads.hpp"



/**
 * @brief A thread to be instantiated multiple times. Should access data, encode it, and 
 * 
 */
void process_thread(){
    char a;
    std::string enc;
    while(!begin);
    while(!check_thread_kill()){
        //TODO: YOUR CODE HERE
        //ACCESS MAP DATA via from_map(); (NOT SAFE FOR MULTI-ACCESS)
       
        //ENCODE DATA via encode(); (SAFE)
       
        //TRANSMIT via transmit(); (NOT SAFE FOR MULTI-ACCESS)

        //Make sure: map access is protected, transmit access is protected.
        
    }
}

std::string encode(char data){
    std::string to_return = "";
    to_return = std::to_string(data) + "         " + std::to_string(data);
    std::this_thread::sleep_for(std::chrono::milliseconds(5)); //Processing Time simulation
    return to_return;
}