#ifndef MYDEQUE_H
#define MYDEQUE_H

#include <cstdlib>

typedef int deque_t;

constexpr size_t deq_data_size = 20;

struct MyDeque {
    deque_t data[deq_data_size];
    size_t head = 0;
    size_t tail = 0;
    size_t size = 0;
};

///размер очереди
size_t deq_size(const MyDeque& deq);
///первый элемент очереди
const deque_t& deq_front(const MyDeque& deq);
///последний элемент очереди
const deque_t &deq_back(const MyDeque& deq);
///Очистить очередь
void deq_clear(MyDeque& deq);
///вставить элемент в конец очереди
void deq_push_back(MyDeque& deq, deque_t elem);
///вставить элемент в начало очереди
void deq_push_front(MyDeque& deq, deque_t elem);
///достать элемент с конца очереди
deque_t deq_pop_back(MyDeque& deq);
///достать элемент с начала очереди
deque_t deq_pop_front(MyDeque& deq);

#endif // MYDEQUE_H
