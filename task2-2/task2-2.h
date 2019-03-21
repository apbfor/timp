//
// Created by apbfor on 03.03.19.
//

#ifndef TEST_EMPTY_TASK2_2_H
#define TEST_EMPTY_TASK2_2_H

#endif //TEST_EMPTY_TASK2_2_H

#include <iostream>
#include <cstdlib>


struct Tree {
    int   val;
    Tree* left;
    Tree* right;
};


//удаление
Tree* DeleteNode(Tree* node, int val){
    if(node == NULL) //если удалять нечего
        return node;

    if(val == node->val){ //если нашли элемент, который нужно удалить
        Tree* tmp;
        if(node->right == NULL) //если нет правого поддерева
            tmp = node->left;
        else {
            Tree* ptr = node->right; //"копируем" правое поддерево
            if(ptr->left == NULL){ //если нет левого поддерева в правом
                ptr->left = node->left; //то левое поддерево исходного узла становится левым поддеревом нового правого
                tmp = ptr; //сохраняем
            } else { //если есть левое поддерево

                Tree* pmin = ptr->left;
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

        delete node;
        return tmp;
    } else if(val < node->val) //если не нашли и значение ключа меньше значения в узле
        node->left  = DeleteNode(node->left, val); //то рекурсивно вызываем функцию удаления, но для левого поддерева
    else
        node->right = DeleteNode(node->right, val); //иначе для правого
    return node;
}



Tree* SearchItem(Tree* node, int val){
    if(node == NULL||val==node->val) //если дошли до конца или нашли нужный элемент, то возвращаем указатель на узел
        return node;
    if(val<node->val)
        return SearchItem(node->left, val);
    else return SearchItem(node->right, val);
}


Tree* InsertNode(Tree* node, int val){


//    Tree* searching = NULL;
//    searching = SearchItem(node, val);
//    if(searching!=NULL)
//        return node;


    if(node == NULL){   //если дерево пустое, создаем его
        node = new (std::nothrow) Tree();



        if(node != NULL){ //дерево создалось, присваиваем узлу значение, а указателю левого и правого поддеревьев
            node->val  = val;
            node->left = node->right = NULL; //присваиваем NULL
        }
        return node;
    }

    if(val == node->val)
        return node;
    if(val < node->val)
        node->left  = InsertNode(node->left, val);
    else
        node->right = InsertNode(node->right, val);
    return node;
}

Tree* MaxElement(Tree* node){
    while (node->right!=NULL)
        node = node->right;
    return node;
}

Tree* MinElement(Tree* node){
    while (node->left!=NULL)
        node = node->left;
    return node;
}



void PrintNode(std::ostream& _out, const Tree* node){
    if(node != NULL){
        if(node->left != NULL)
            PrintNode(_out, node->left);

        _out << node->val << ' ';

        if(node->right != NULL)
            PrintNode(_out, node->right);
    }
}



//удаление всего
void ClearNode(Tree* node){
    if(node != NULL){
        if(node->left != NULL)
            ClearNode(node->left);
        if(node->right != NULL)
            ClearNode(node->right);
        delete node;
    }
}
