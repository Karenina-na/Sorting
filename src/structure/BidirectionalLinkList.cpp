//
// Created by Karenina-na on 2023/9/17.
//

#include "DataStructure.h"

// 构造函数
template<typename T>
DataStructure::BidirectionalLinkList<T>::BidirectionalLinkList() {
    head = new BidirectionalLinkListNode<T>;
    tail = new BidirectionalLinkListNode<T>;
    head->next = tail;
    tail->prev = head;
    length = 0;
}

// 析构函数
template<typename T>
DataStructure::BidirectionalLinkList<T>::~BidirectionalLinkList() {

}

// 获取链表长度
template<typename T>
int DataStructure::BidirectionalLinkList<T>::getLength() {
    return length;
}

// 获取链表指定位置的节点的数据
template<typename T>
T DataStructure::BidirectionalLinkList<T>::getData(int index){
    if (index < 0 || index >= length) {
        throw "Index out of range.";
    }
    // 二分查找
    return 0;
}

// 遍历操作链表
template<typename T>
void DataStructure::BidirectionalLinkList<T>::foreach(void (*callback)(T)){
    DataStructure::BidirectionalLinkList<T>::BidirectionalLinkListNode<T> *node = head->next;
    while (node != nullptr) {
        callback(node->data);
        node = node->next;
    }
}

// 在链表头部插入节点
template<typename T>
void DataStructure::BidirectionalLinkList<T>::insertAtHead(T data){

}

// 在链表尾部插入节点
template<typename T>
void DataStructure::BidirectionalLinkList<T>::insertAtTail(T data){

}

// 在链表指定位置插入节点
template<typename T>
void DataStructure::BidirectionalLinkList<T>::insertAt(int index, T data){

}

// 删除链表头部节点
template<typename T>
void DataStructure::BidirectionalLinkList<T>::deleteAtHead(){

}

// 删除链表尾部节点
template<typename T>
void DataStructure::BidirectionalLinkList<T>::deleteAtTail(){

}

// 删除链表指定位置的节点
template<typename T>
void DataStructure::BidirectionalLinkList<T>::deleteAt(int index){

}

// 清空链表
template<typename T>
void DataStructure::BidirectionalLinkList<T>::clear(){

}

// 打印链表
template<typename T>
void DataStructure::BidirectionalLinkList<T>::print(){

}