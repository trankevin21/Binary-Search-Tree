#include "BST.h"

struct node {
    int Num;
    node* Left;
    node* Right;
};

struct node* BST(int inputData) {
    node* curPTR = new node;
    curPTR->Num = inputData;
    curPTR->Left = nullptr;
    curPTR->Right = nullptr;

    return curPTR;
}

void bstSort(node* &ptr, int inputData) {//Inputs the user data into the struct and sorts it
    if (ptr == nullptr) {//Initialize 
        ptr = BST(inputData);
    } else {
        if (inputData <= ptr->Num) {
            if (ptr->Left == nullptr) {
                ptr->Left = BST(inputData);//Insert Data
            } else {
                bstSort(ptr->Left, inputData);
            }
        } else if (inputData >= ptr->Num) {
            if (ptr->Right == nullptr) {//Insert Data
                ptr->Right = BST(inputData);
            } else {
                bstSort(ptr->Right, inputData);
            }
        }
    }
}

void printTree(node* ptr) {//Prints out the whole BTree from largest to smallest
    if (ptr != nullptr) {
        printTree(ptr->Left);
        cout << ptr->Num << "   ";
        printTree(ptr->Right);
    }
}

void smallestElement(node* ptr) {//Searches for the smallest element and prints it out
    while (ptr->Left != nullptr) {
        ptr = ptr->Left;
    }
    cout << "Smallest Value: " << ptr->Num << endl;
}


int main() {
    node* ptr = nullptr;

    int len;
    cout << "Enter # of Elements: ";//User enter num of elements
    cin >> len;
    
    int kth = 0;
    cout << "Enter K: ";
    cin >> kth;

    while (!(kth <= len) || !(kth >= 1)) {
        cout << "Try Again! Enter K: ";
        cin >> kth;
    }


    vector<int> temp(len);
    int inputData;
    for (int i = 1, k = 0; i <= len && k < len; i++, k++) {//User enters each element
        cout << "Enter Element [" << i << "]: ";
        cin >> temp[k];
    }
    
    sort(temp.begin(), temp.end());//Finds the middle to make it balanced as possible
    int root = floor(len / 2);
    bstSort(ptr, temp[root]);

    for (int i = 0; i < len; i++) {
        if (i != root) {
            bstSort(ptr, temp[i]);
        }
    }
    
    cout << endl << "[Smallest -> Largest]: ";
    printTree(ptr);
    cout << endl;
    smallestElement(ptr);
    cout << temp[kth - 1];

    return 0;
}