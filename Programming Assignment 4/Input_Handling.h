#include <string.h>
class Invalid_Input{
    public:
        Invalid_Input(string in_ptr) : msg_ptr(in_ptr){}
        const string msg_ptr;
    private:
        Invalid_Input();
};