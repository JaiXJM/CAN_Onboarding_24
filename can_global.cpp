#include "can_global.hpp"

char from_map(){
    if(current>9)
    current = 1;

    return current++;
}

void transmit(std::string frame){
    int n = frame.length();
    for (int i = 0; i<n; i++){
        verif(frame[i]);
        
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void verif(char v){
    if(v==' ') return;

    if(verif_stat == 0){
        verif_stat = v;
        est_num_pkt++;
    }else if(v == verif_stat){
        verif_stat = 0;
    }else{
    collisions++;
    }

}


bool check_thread_kill(){
    kill_mutex.lock();
    bool to_return = thread_kill;
    kill_mutex.unlock();
    return to_return;
}