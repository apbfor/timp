//
// Created by apbfor on 03.03.19.
//

#ifndef TEST_EMPTY_TASK2_2_H
#define TEST_EMPTY_TASK2_2_H

#endif //TEST_EMPTY_TASK2_2_H

#include <iostream>
#include <cstdlib>


#include <iostream>

#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H

#endif //BINARYTREE_TREE_H


struct Node {
    int value;
    Node* left;
    Node* right;


    Node(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }
    Node():value(0), left(NULL), right(NULL) {}
};

class Tree {
private:
    Node * head;
    bool search(int value, Node *node) {

        while (node != NULL) {
            if (value == node->value) {
                return true;
            } else {
                if (value <= node->value) return search(value, node->left);
                else return search(value, node->right);
            }
        }
        return false;
    }

    //удаление
    Node* DeleteNode(Node* node, int val){
        if(node == NULL) //если удалять нечего
            return node;

        if(val == node->value){ //если нашли элемент, который нужно удалить
            Node* tmp;
            if(node->right == NULL) //если нет правого поддерева
                tmp = node->left;
            else {
                Node* ptr = node->right; //"копируем" правое поддерево
                if(ptr->left == NULL){ //если нет левого поддерева в правом
                    ptr->left = node->left; //то левое поддерево правого поддерева становится левым поддеревом нового правого
                    tmp = ptr; //сохраняем
                } else { //если есть левое поддерево

                    Node* pmin = ptr->left;
                    while(pmin->left != NULL){ //ищем минимальный элемент дерева
                        ptr  = pmin;
                        pmin = ptr->left;
                    }
                    ptr->left   = pmin->right;
                    pmin->left  = node->left;
                    pmin->right = node->right;
                    tmp = pmin;
                }
            }

            //корректное удаление node
            node->left = node->right = NULL;
            node->value = -1;
            return tmp;
        } else if(val < node->value) //если не нашли и значение ключа меньше значения в узле
            node->left  = DeleteNode(node->left, val); //то рекурсивно вызываем функцию удаления, но для левого поддерева
        else
            node->right = DeleteNode(node->right, val); //иначе для правого
        return node;
    }
    Node* removeElem(Node* head, int x) {
        Node *t;
        if (head == NULL)
            return NULL;
        if (x == head->value) {
            if (head->left == NULL) {
                t = head->right;
                delete head;
                return t;
            }
            t = head->left;
            while (t->right) {
                t = t->right;
            }
            t->right = head->right;
            return head->left;
        }
        if (x < head->value)
            head->left = removeElem(head->left, x);
        else
            head->right = removeElem(head->right, x);
        return head;
    }

    bool add(Node * node, int value) {
        if (head == NULL) {
            Node *node = new Node(value);
            head = node;
            return true;
        }
        if (value == node->value)
            return true;
        if (value > node->value) {
            if (node->right != NULL)
                return add(node->right, value);
            else {
                Node *newNode = new Node(value);
                node->right=newNode;
                return true;
            }
        } else if (value<node->value){
            if (node->left != NULL)
                add(node->left, value);
            else {
                Node *newNode = new Node(value);
                node->left=newNode;
                return true;
            }
        }
    }
    void printNode(const Node* node){
        if(node != NULL){
            if(node->left != NULL)
                printNode(node->left);

            std::cout << node->value << ' ';

            if(node->right != NULL)
                printNode(node->right);
        }
    }

    Node* maxElement(Node* node){
        if(node == NULL)
            return node;
        while (node->right!=NULL)
            node = node->right;
        return node;
    }

    Node* minElement(Node* node){
        if(node == NULL)
            return node;
        while (node->left!=NULL)
            node = node->left;
        return node;
    }

public:

    Tree():head(NULL) {}
    Tree(int value) {
        Node *node = new Node(value);
        head = node;
    }

    Tree(Node * node) {
        head = node;
    }



    bool add(int value) {
        if (head == NULL) {
            Node *node = new Node(value);
            head = node;
            return true;
        }
        if (value == head->value)
            return true;
        if (value > head->value) {
            if (head->right != NULL)
                return add(head->right, value);
            else {
                Node *newNode = new Node(value);
                head->right=newNode;
                return true;
            }
        } else if(value<head->value) {
            if (head->left != NULL)
                return add(head->left, value);
            else {
                Node *newNode = new Node(value);
                head->left=newNode;
                return true;
            }
        }
    }

    void removeElem(int x){
        DeleteNode(head, x);
    }

    bool search(int value) {
        while (head != NULL) {
            if (value == head->value) {
                return true;
            } else {
                if (value <= head->value)
                    return search(value, head->left);
                else return search(value, head->right);
            }
        }
        return false;
    }



    int maxElement(){
        if(head==NULL||head->value<0)
            return -1;
        else {
            int max = maxElement(head)->value;
            return max;
        }
    }

    int minElement(){
        if(head==NULL||head->value<0)
            return -1;
        else {
            int min = minElement(head)->value;
            return min;
        }
    }



    void printNode(){
        printNode(head);
    }


};