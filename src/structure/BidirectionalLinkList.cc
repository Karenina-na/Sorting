//
// Created by Karenina-na on 2023/9/17.
//

#include <iostream>

#ifndef SORTING_ALGORITHM_INTERFACE_FRAMEWORK_BIDIRECTIONALLINKLIST_H
#define SORTING_ALGORITHM_INTERFACE_FRAMEWORK_BIDIRECTIONALLINKLIST_H

namespace structure {

    // 双向链表
    template<typename T>
    class BidirectionalLinkList {
    private:
        // 链表节点
        template<typename NT>
        struct BidirectionalLinkListNode {
            NT data;
            BidirectionalLinkListNode<NT> *prev;
            BidirectionalLinkListNode<NT> *next;
            explicit BidirectionalLinkListNode(T data) {
                this->data = data;
                this->prev = nullptr;
                this->next = nullptr;
            }
            BidirectionalLinkListNode() {
                this->prev = nullptr;
                this->next = nullptr;
            }
            ~BidirectionalLinkListNode() {
                this->prev = nullptr;
                this->next = nullptr;
            }
        };

        // 头尾节点
        BidirectionalLinkListNode<T> *head;
        BidirectionalLinkListNode<T> *tail;
        // 链表长度
        int length;

    public:
        BidirectionalLinkList();
        ~BidirectionalLinkList();

        int size();
        T getData(int index);

        void forEach(void (*callback)(T));
        void insertAtHead(T data);
        void insertAtTail(T data);
        void insertAt(int index, T data);
        void deleteAtHead();
        void deleteAtTail();
        void deleteAt(int index);
        void set(int index, T data);
        void clear();
        void print();

        // 重载[]运算符
        T operator[](int index) {
            return getData(index);
        }

        // 重载=运算符

    };

} // structure

// 构造函数
template<typename T>
structure::BidirectionalLinkList<T>::BidirectionalLinkList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

// 析构函数
template<typename T>
structure::BidirectionalLinkList<T>::~BidirectionalLinkList() {
    clear();
}

// 获取链表长度
template<typename T>
int structure::BidirectionalLinkList<T>::size() {
    return length;
}

// 获取链表指定位置的节点的数据
template<typename T>
T structure::BidirectionalLinkList<T>::getData(int index){
    if (index < 0 || index >= length) {
        throw "Index out of range.";
    }
    if (length == 0) {
        throw "Empty list.";
    }
    if (index == 0) {
        return head->data;
    }
    // 双向查找
    if (index < length / 2) {
        BidirectionalLinkListNode<T> *node = head;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
        return node->data;
    } else {
        BidirectionalLinkListNode<T> *node = tail;
        for (int i = length - 1; i > index; i--) {
            node = node->prev;
        }
        return node->data;
    }
}

// 遍历操作链表
template<typename T>
void structure::BidirectionalLinkList<T>::forEach(void (*callback)(T)){
    if (length == 0){
        throw "Empty list.";
    }
    if (length == 1) {
        callback(head->data);
        return;
    }
    BidirectionalLinkList<T>::BidirectionalLinkListNode<T> *node = head->next;
    while (node != tail) {
        callback(node->data);
        node = node->next;
    }
    callback(node->data);
}

// 在链表头部插入节点
template<typename T>
void structure::BidirectionalLinkList<T>::insertAtHead(T data){
    if (length == 0) {
        head = new BidirectionalLinkListNode<T>(data);
        tail = head;
        length++;
        return;
    }
    auto *node = new BidirectionalLinkListNode<T>(data);
    node->next = head;
    head->prev = node;
    head = node;
    length++;
}

// 在链表尾部插入节点
template<typename T>
void structure::BidirectionalLinkList<T>::insertAtTail(T data){
    if (length == 0) {
        head = new BidirectionalLinkListNode<T>(data);
        tail = head;
        length++;
        return;
    }
    auto *node = new BidirectionalLinkListNode<T>(data);
    node->prev = tail;
    tail->next = node;
    tail = node;
    length++;
}

// 在链表指定位置插入节点
template<typename T>
void structure::BidirectionalLinkList<T>::insertAt(int index, T data){
    if (index < 0 || index > length) {
        throw "Index out of range.";
    }
    if (index == 0) {
        insertAtHead(data);
        return;
    }
    if (index == length) {
        insertAtTail(data);
        return;
    }
    if (length == 0 && index != 0) {
        throw "Empty list.";
    }else if (length == 1 && index != 0) {
        throw "Index out of range.";
    }
    auto *node = new BidirectionalLinkListNode<T>(data);
    BidirectionalLinkListNode<T> *tmp = nullptr;
    // 双向查找
    if (index < length / 2) {
        tmp = head;
        for (int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
    } else {
        tmp = tail;
        for (int i = length - 1; i > index; i--) {
            tmp = tmp->prev;
        }
    }
    // temp -> data -> tmp
    node->next = tmp;
    node->prev = tmp->prev;
    tmp->prev->next = node;
    tmp->prev = node;
    length++;
}

// 删除链表头部节点
template<typename T>
void structure::BidirectionalLinkList<T>::deleteAtHead(){
    if (length == 0) {
        throw "Empty list.";
    }
    if (length == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
        length = 0;
        return;
    }
    BidirectionalLinkListNode<T> *tmp = head->next;
    delete head;
    head = tmp;
    head->prev = nullptr;
    length--;
}

// 删除链表尾部节点
template<typename T>
void structure::BidirectionalLinkList<T>::deleteAtTail(){
    if (length == 0) {
        throw "Empty list.";
    }
    if (length == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
        length = 0;
        return;
    }
    BidirectionalLinkListNode<T> *tmp = tail->prev;
    delete tail;
    tail = tmp;
    tail->next = nullptr;
    length--;
}

// 删除链表指定位置的节点
template<typename T>
void structure::BidirectionalLinkList<T>::deleteAt(int index){
    if (index < 0 || index >= length) {
        throw "Index out of range.";
    }
    if (length == 0) {
        throw "Empty list.";
    }
    if (index == 0) {
        deleteAtHead();
        return;
    }
    if (index == length - 1) {
        deleteAtTail();
        return;
    }
    BidirectionalLinkListNode<T> *tmp = nullptr;
    // 双向查找
    if (index < length / 2) {
        tmp = head;
        for (int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
    } else {
        tmp = tail;
        for (int i = length - 1; i > index; i--) {
            tmp = tmp->prev;
        }
    }
    // tmp -> data -> tmp
    BidirectionalLinkListNode<T> *node = tmp->prev;
    node->next = tmp->next;
    tmp->next->prev = node;
    delete tmp;
    length--;
}

// 修改链表指定位置的节点的数据
template<typename T>
void structure::BidirectionalLinkList<T>::set(int index, T data){
    if (index < 0 || index >= length) {
        throw "Index out of range.";
    }
    if (length == 0) {
        throw "Empty list.";
    }
    if (index == 0) {
        head->data = data;
        return;
    }
    if (index == length - 1) {
        tail->data = data;
        return;
    }
    BidirectionalLinkListNode<T> *tmp = nullptr;
    // 双向查找
    if (index < length / 2) {
        tmp = head;
        for (int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
    } else {
        tmp = tail;
        for (int i = length - 1; i > index; i--) {
            tmp = tmp->prev;
        }
    }
    tmp->data = data;
}

// 清空链表
template<typename T>
void structure::BidirectionalLinkList<T>::clear(){
    if (length == 0) {
        return;
    }
    if (length == 1) {
        delete head;
        delete tail;
        head = nullptr;
        tail = nullptr;
        length = 0;
        return;
    }
    BidirectionalLinkListNode<T> *node = head->next;
    while (node != tail) {
        delete node->prev;
        node = node->next;
    }
    delete node->prev;
    delete node;
    head = nullptr;
    tail = nullptr;
    length = 0;
}

// 打印链表
template<typename T>
void structure::BidirectionalLinkList<T>::print() {
    if (length == 0) {
        std::cout << "Empty list." << std::endl;
        return;
    }
    if (length == 1) {
        std::cout << head->data << std::endl;
        return;
    }
    BidirectionalLinkListNode<T> *node = head;
    while (node != tail) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << node->data << std::endl;
}

#endif //SORTING_ALGORITHM_INTERFACE_FRAMEWORK_BIDIRECTIONALLINKLIST_H