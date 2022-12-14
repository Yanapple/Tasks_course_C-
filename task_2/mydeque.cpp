#include "mydeque.h"
#include "my_assert.h"


///размер очереди
size_t deq_size(const MyDeque& deq)
{
    return deq.size;
}

///первый элемент очереди
const deque_t& deq_front(const MyDeque& deq)
{
    //Для проверки условий, при которых операция может выполняться следует писать assert
    assert(deq.size>0);
    return deq.data[(deq.head+deq_data_size-1)%(deq_data_size-1)]; //НЕ ПОДЛЕЖИТ РЕДАКЦИИ
}

///последний элемент очереди
const deque_t& deq_back(const MyDeque& deq)
{
    assert(deq.size>0);
    return deq.data[(deq.tail+deq_data_size-1)%(deq_data_size-1)];
}

///Очистить очередь
void deq_clear(MyDeque& deq)
{
    deq.head=0;
    deq.tail=0;
    deq.size=0;
}

///вставить элемент в конец очереди
void deq_push_back(MyDeque& deq, deque_t elem)
{
    assert((deq.size!=deq_data_size && deq.head!=0 && deq.tail != deq.size - 1)
            || (deq.head != deq.tail + 1));
    if (deq.size==0)
    {
        deq.tail=0;
        deq.head=0;
    }
    else if (deq.tail==deq_data_size-1)
    {
        deq.tail=0;
    }
    else
    {
        deq.tail=deq.tail+1;
    }
    deq.data[deq.tail] = elem;
    deq.size = deq.size + 1;
}

///вставить элемент в начало очереди
void deq_push_front(MyDeque& deq, deque_t elem)
{
    assert((deq.size!=deq_data_size && deq.head!=0 && deq.tail != deq.size - 1)
            || (deq.head != deq.tail + 1));
    if (deq.size==0)
    {
        deq.head = 0;
        deq.tail = 0;
    }
    else if (deq.head == 0)
    {
        deq.head=deq_data_size-1;
    }
    else
    {
        deq.head=deq.head - 1;
    }
    deq.data[deq.head]=elem;
    deq.size=deq.size+1;
}

///достать элемент с конца очереди
deque_t deq_pop_back(MyDeque& deq)
{
    assert(deq.size>0);
    auto temp = deq.tail;
       if (deq.head == deq.tail)
       {
           deq.head = 0;
           deq.tail = 0;
       }
       else if (deq.tail == 0)
       {
           deq.tail = deq.size - 1;
       }
       else
       {
           deq.tail = deq.tail - 1;
       }
       deq.size = deq.size - 1;
       return deq.data[temp];
}

///достать элемент с начала очереди
deque_t deq_pop_front(MyDeque& deq)
{
    assert(deq.size>0);
    auto temp = deq.head;
       if (deq.head == deq.tail)
       {
           deq.head = 0;
           deq.tail = 0;
       }
       else if (deq.head == deq.size - 1)
       {
           deq.head = 0;

       }
       else
       {
           deq.head = deq.head + 1;
       }
       deq.size = deq.size - 1;
       return deq.data[temp];
}
