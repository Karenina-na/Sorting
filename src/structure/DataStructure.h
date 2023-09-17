//
// Created by Karenina-na on 2023/9/17.
//

#ifndef SORTING_ALGORITHM_INTERFACE_FRAMEWORK_DATASTRUCTURE_H
#define SORTING_ALGORITHM_INTERFACE_FRAMEWORK_DATASTRUCTURE_H
namespace DataStructure {

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
                delete prev;
                delete next;
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

        int getLength();
        T getData(int index);

        void foreach(void (*callback)(T));
        void insertAtHead(T data);
        void insertAtTail(T data);
        void insertAt(int index, T data);
        void deleteAtHead();
        void deleteAtTail();
        void deleteAt(int index);
        void clear();
        void print();
    };




} // DataStructure
#endif //SORTING_ALGORITHM_INTERFACE_FRAMEWORK_DATASTRUCTURE_H
