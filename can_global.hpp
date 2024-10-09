#ifndef CAN_GLOBAL
#define CAN_GLOBAL


#include <chrono>
#include <thread>
#include <mutex>
#include <iostream>

//Global Variables
char current = 1;
bool thread_kill = false, begin = false;
std::mutex map_mutex, transmit_mutex, kill_mutex;


char from_map();
void transmit(std::string frame);
bool check_thread_kill();

char verif_stat = 0;
int est_num_pkt = 0;
int collisions = 0;
void verif(char v);
#endif
