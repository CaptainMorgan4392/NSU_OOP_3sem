#pragma once
#include <iostream>

typedef int value_type;

class LinkedList {
    struct Node {
        value_type value;
        Node* prev;
        Node* next;

        int index = 0;

        Node();
        explicit Node(value_type &val);
        explicit Node(const value_type &val);
    };

    Node* head;
    Node* tail;
public:
    class iterator {
        friend class LinkedList;
        Node* element;

        explicit iterator(Node* el);
    public:
        value_type value;
        iterator();
        iterator & operator=(const iterator & other);
        bool operator!=(const iterator & other) const;
        bool operator==(const iterator & other) const;
        //Возвращает ссылку на текущий элемент коллекции.
        value_type & operator*();
        //Возвращает указатель на текущий элемент коллекции.
        value_type * operator->();

        iterator & operator++();
        const iterator operator++(int);
        iterator & operator--();
        const iterator operator--(int);

        //Удаляет элемент, на который указывает итератор pos.
        iterator erase(iterator position);
        //Удаляет элементы в интервале [begin, end).
        iterator erase(iterator begin, iterator end);
        //Вставляет значение value перед элементом, на который указывает before
        iterator insert(iterator before, const value_type & value);
    };
    class const_iterator {
        friend class LinkedList;
        Node* constElement;

        explicit const_iterator(Node* el);
    public:
        value_type value;
        const_iterator();
        const_iterator & operator=(const const_iterator & other);
        bool operator!=(const const_iterator & other) const;
        bool operator==(const const_iterator & other) const;
        //Возвращает ссылку на текущий элемент коллекции.
        const value_type & operator*() const;
        //Возвращает указатель на текущий элемент коллекции.
        const value_type * operator->() const;

        const_iterator & operator++();
        const const_iterator operator++(int);
        const_iterator & operator--();
        const const_iterator operator--(int);
    };
    /* Конструкторы */
    LinkedList();
    LinkedList(const LinkedList & other);
    LinkedList(LinkedList && other) noexcept;

    /* Деструктор */
    ~LinkedList();

    /* Оператор присваивания */
    LinkedList & operator=(const LinkedList & other);
    LinkedList & operator=(LinkedList && other) noexcept;

    /* Размерность */
    //Возвращает размер списка.
    int size() const;
    //Возвращает истину, если список пуст.
    bool empty() const;

    /* Доступ к элементам */
    //Возвращает ссылку на первый элемент списка.
    value_type & front();
    const value_type & front() const;
    //Возвращает ссылку на последний элемент списка.
    value_type & back();
    const value_type & back() const;

    //Удаляет все вхождения value в список.
    int remove(const value_type & value);
    //Очищает список.
    void clear();

    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;

    void push_in_empty(const value_type & value);
    //Удаляет последний элемент списка.
    void pop_back();
    //Удаляет первый элемент списка.
    void pop_front();
    //Добавляет значение value в конец списка.
    void push_back(const value_type & value);
    //Добавляет значение value в начало списка.
    void push_front(const value_type & value);

    /* Операторы внутренние */
    //Присоединяет other к списку.
    LinkedList & operator+=(const LinkedList & other);

    /* Операторы внешние */
    friend bool operator!=(const LinkedList & left, const LinkedList & right);
    friend bool operator==(const LinkedList & left, const LinkedList & right);

};

/* Операторы внешние */
//Сравнивает 2 листа
bool operator!=(const LinkedList & left, const LinkedList & right);
bool operator==(const LinkedList & left, const LinkedList & right);

//Возвращает лист объединяющий 2 листа.
LinkedList operator+(const LinkedList & left, const LinkedList & right);
