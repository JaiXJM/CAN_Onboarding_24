#ifndef CAN_GLOBAL
#define CAN_GLOBAL


#include <chrono>
#include <thread>
#include <mutex>
#include <iostream>

//Global Variables
char current = 1;
bool thread_kill = false, begin = false;
//Use map_mutex and transmit_mutex
std::mutex map_mutex, transmit_mutex, do_not_use_a, do_not_use_b;


char from_map();
void transmit(std::string frame);
bool check_thread_kill();

char verif_stat = 0;
int est_num_pkt = 0;
int collisions = 0;
bool map_check = false;
void verif(char v);
#endif
