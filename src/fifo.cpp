#include <fifo.h>

Fifo::Fifo()
{
    len = 0;
}

int Fifo::get()
{
    int a = buffer[0];
    for (int i=0; i<len; ++i){
        buffer[i]=buffer[i+1];
    }
    len = len - 1;
    return a;
}

void Fifo::put(int item)
{
    if (len<FIFO_SIZE){
       buffer[len]=item;
       len = len + 1;
    }
    else{
    }
}

bool Fifo::is_empty()
{
    if (len==0){
        return true;
    }
    else{
        return false;
    }
}

bool Fifo::is_full()
{
    return !is_empty();
}

void Fifo::reset()
{
    len = 0;
}