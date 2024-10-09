//#define VERBOSE

int assert(int a, int b){
    #ifdef VERBOSE
        bool check = a==b;
        if(!check) std::cout<<"Failed: Input "<<a<<" Expected: "<<b<<std::endl;
        return a==b;
    #else
    return a==b;
    #endif
}