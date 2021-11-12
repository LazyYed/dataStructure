/**
 * 设计链表，单链表
 */

#include "iostream"

using namespace std;

class MyLinkedList {

public:
    //定义链表节点结构体
    struct LinkedList {
        int val;
        LinkedList *next;

        LinkedList(int val) : val(val), next(nullptr) {};
    };

    //初始化链表
    MyLinkedList() {
        m_size = 0;
        m_head = new LinkedList(0);
    }

    //在链表尾部添加一个节点
    void addAtTail(int val) {
        LinkedList *newNode = new LinkedList(val); //创建一个新的节点
        LinkedList *currNode = m_head; //获取到头节点
        while (currNode->next != NULL) {//向前移动，直到最后一个节点
            currNode = currNode->next;
        }
        currNode->next = newNode; //新节点给到最后一个节点
        m_size++; //size++
    }

    //获取指定下标的节点的值
    int get(int index) {
        if (index > (m_size - 1) || index < 0) {
            return -1;
        }
        LinkedList *curr = m_head->next;
        while (index--) { //从头节点 走index次
            curr = curr->next;
        }
        return curr->val;
    }

    //在链表头部插入一个节点，插入后，成为新节点
    void addAtHead(int val) {
        LinkedList *newNode = new LinkedList(val);//创建新的节点
        LinkedList *curr = m_head;
        newNode->next = curr->next;//新节点的下一个节点指向头节点的下一个节点
        curr->next = newNode;//然后把头节点的下一个节点指向新的节点
        m_size++;
    }

    //删除第index个节点，如果index大于链表长度直接return
    void deleteAtIndex(int index) {
        if (index > m_size) {
            return;
        }
        LinkedList *curr = m_head;
        while (index--) {
            curr = curr->next;
        }

        LinkedList *tempNode = curr->next;//获取到要删除的节点
        curr->next = curr->next->next; //替换掉上面的tempNode节点，这样tempNode就没有被指向了
        delete tempNode;//删除
        m_size--;
    }

private:
    int m_size;
    LinkedList *m_head;

};

int main() {
    MyLinkedList *list = new MyLinkedList();
    for (int i = 0; i < 3; ++i) {
        list->addAtTail(i * 2);
    }
    cout << list->get(0) << endl;
    cout << list->get(1) << endl;

    list->deleteAtIndex(0);
    cout << list->get(0) << endl;
}