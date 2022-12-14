#include <iostream>
#include <cstdlib>
#include "my_assert.h"

/* Задание 1
 * Дано 25.04.2022.
 * Написать свою реализацию двунаправленной очереди на основе данного ниже кода.
 * Для обслуживания очереди используется структура MyDeque, содержащая индексы
 * на начало очереди (head), конец очереди (tail) и текущий размер очереди (size).
 * Определить в mydeque.cpp все функции, которые объявлены в mydeque.h.
 *
 * Использовать подход кольцеового буфера (не допускать ненужного перекладывания элементов,
 * т.е. сдвига всех элементов при удалении/добавлении в начало либо в конец).
 *
 * Для проверки условий, при которых операция может выполняться следует писать assert.
 * Например, получить элемент из очереди можно только если очерень не пуста. Тогда в коде
 * должна появится строка вида: assert(deq.size>0);
 * Проверки типа assert нужно выполнять до того, как может произойти потенциальное повреждение данных.
 *
 * В функции main написаны тесты для вашего кода. Ваш код должен успешно проходить все тесты.
 */

using namespace std;

#include "mydeque.h"

///Проверить, что происходит исключение не инвалидирующее объект
#define check_assertion(expr)try{expr;\
    std::cout << "Tests failed: expression is true" << #expr << std::endl;}\
    catch (const std::exception& ex){\
    std::cout << "Tests passed: " << ex.what() << std::endl;\
    }

int main()
{
    try {
        MyDeque deq;

        assert(deq_size(deq)==0 && "Initial size is not zero!");
        check_assertion(deq_front(deq));
        check_assertion(deq_back(deq));
        check_assertion(deq_pop_back(deq));
        check_assertion(deq_pop_front(deq));

        ///Генерируем массив случайных чисел, по которому будет тестировать данные
        deque_t test[deq_data_size];
        constexpr size_t test_size = sizeof(test)/sizeof(test[0]);
        for(size_t i = 0; i<test_size; ++i)
            test[i] = rand();

        //Заполняем массив наполовину
        for(size_t i = 0; i<test_size/2; ++i)
            deq_push_back(deq, test[i]);
        assert(deq_size(deq)==test_size/2); //поменяла size=+1 на size=size+1 - прошло
        assert(deq_front(deq)==test[0]);
        assert(deq_back(deq)==test[test_size/2-1]);

        //Дозаполняем массив целиком
        for(size_t i = test_size/2; i<test_size; ++i)
            deq_push_front(deq, test[i]);
        assert(deq_front(deq)==test[test_size-1]);
        assert(deq_back(deq)==test[test_size/2-1]);
        check_assertion(deq_push_front(deq, 0));
        check_assertion(deq_push_back(deq, 0));

        //Проверяем, что вытаскиваемый с конца элемент совпадает по значению с тестовым
        assert(deq_pop_back(deq)==test[test_size/2-1]);
        //Проверяем, что конечный элемент совпадает по значению с тестовым
        assert(deq_back(deq)==test[test_size/2-2]);

        //Проверяем, что вытаскиваемый с начала элемент совпадает по значению с тестовым
        assert(deq_pop_front(deq)==test[test_size-1]);
        //Проверяем, что начальный элемент совпадает по значению с тестовым
        assert(deq_front(deq)==test[test_size-2]);

        //После вытаскивания проверяем размер
        assert(deq_size(deq)==test_size-2);

        //Очищаем очередь и проверяем функции на пустоту
        deq_clear(deq);
        assert(deq_size(deq)==0 && "Size after clear is not zero!");
        check_assertion(deq_front(deq));
        check_assertion(deq_back(deq));
        check_assertion(deq_pop_back(deq));
        check_assertion(deq_pop_front(deq));

        for(size_t i = 0; i<deq_data_size; ++i)
            deq_push_back(deq, i);
        assert(deq_size(deq)==deq_data_size);

        std::cout << "Checking circular mode" << std::endl;
        const auto& old_front = deq_front(deq);
        deq_pop_front(deq);
        deq_push_back(deq, 123);
        const auto& new_back = deq_back(deq);
        assert((&old_front == &new_back) && "Circular mode was not inplemented");

        const auto& old_back = deq_back(deq);
        deq_pop_back(deq);
        deq_push_front(deq, 123);
        const auto& new_front = deq_front(deq);
        assert((&old_back == &new_front) && "Circular mode was not inplemented");

        ///Все тесты успешно пройдены
        std::cout << "All tests were successfull!!!" << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cout << "Test failed: " << ex.what() << std::endl;
    }
}
