#include <fifo.h>

Fifo::Fifo()
{
    len = 0;
    s=0;
    e=0;
}

//Get part 2
// int Fifo::get()
// {
//     int a = buffer[0];
//     for (int i=0; i<len; ++i){
//         buffer[i]=buffer[i+1];
//     }
//     len = len - 1;
//     return a;
// }

//Get part 3
int Fifo::get()
{
    if (len>0){
        int r = buffer[s];
        len = len - 1;
        if (s==(FIFO_SIZE-1)){
            s = 0;
        }
        else{
            s = s + 1;
        }
        return r;
    }
    else{
    }
}

//Put part 2
// void Fifo::put(int item)
// {
//     if (len<FIFO_SIZE){
//        buffer[len]=item;
//        len = len + 1;
//     }
//     else{
//     }
// }

//Put part 3
void Fifo::put(int item)
{
    if (len<FIFO_SIZE){
        buffer[e]=item;
        len = len + 1;
        if (e ==FIFO_SIZE){
            e = 0;
        }
        else{
            e = e +1;
        }
    }
}

bool Fifo::is_empty()
{
    return (len==0);
}

bool Fifo::is_full()
{
    return (len==FIFO_SIZE);
}

void Fifo::reset()
{
    len = 0;
}