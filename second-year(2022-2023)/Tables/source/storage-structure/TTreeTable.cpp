//
// Created by Андрей Юрин on 26.05.2023.
//

#include "../../include/storage-structure/TTreeTable.h"

TTreeTable::TTreeTable(){
    pRoot = nullptr;
    ppCurrentNode = nullptr;
}

TTreeTable::~TTreeTable() {
    DeleteTree(pRoot);
}

bool TTreeTable::IsFull() const {
    return false;
}

std::optional<TDataValue *> TTreeTable::Find(TKey key) {
    while(!iterStack.empty()) iterStack.pop();
    SetRetCode(TAB_OK);
    ppCurrentNode = &pRoot;
    while((*ppCurrentNode) != nullptr){
        iterStack.emplace(*ppCurrentNode, false);
        efficiencyIndicator++;
        auto tempKey = (*ppCurrentNode)->key;

        if (tempKey == key)
            return (*ppCurrentNode)->value;
        else if (tempKey < key)
            ppCurrentNode = &(*ppCurrentNode)->pRight;
        else
            ppCurrentNode = &(*ppCurrentNode)->pLeft;
    }

    SetRetCode(TAB_NO_RECORD);
    return {};
}

bool TTreeTable::Insert(TKey key, TDataValue *value) {
    if (Find(key).has_value()) {
        SetRetCode(TAB_REC_DOUBLE);
        return false;
    }
    *ppCurrentNode = new TTreeNode(key, value);
    efficiencyIndicator++;
    TTable::size++;
    SetRetCode(TAB_OK);
    return true;
}

void TTreeTable::Remove(TKey key) {
    if (!Find(key).has_value())
        return;
    SetRetCode(TAB_OK);

    iterStack.pop();

    TTreeNode* pResultFind = *ppCurrentNode;

    if (pResultFind->pRight == nullptr)
        *ppCurrentNode = pResultFind->pLeft;
    else if (pResultFind->pLeft == nullptr)
        *ppCurrentNode = pResultFind->pRight;
    else{
        TTreeNode** ppMinNodeInRightSubtree = Minimum(pResultFind->pRight);
        TTreeNode* pMinNodeInRightSubtree = *ppMinNodeInRightSubtree;

        *ppMinNodeInRightSubtree = pMinNodeInRightSubtree->pRight;

        pMinNodeInRightSubtree->pLeft = pResultFind->pLeft;
        pMinNodeInRightSubtree->pRight = pResultFind->pRight;

        *ppCurrentNode = pMinNodeInRightSubtree;
    }
    delete pResultFind;
    TTable::size--;
}


int TTreeTable::Reset() {

    ppCurrentNode = &pRoot;
    while(!iterStack.empty()) iterStack.pop();

    if (pRoot != nullptr) {
        FillStackLeftNodes();
        Next();
    }
    return 0;
}

int TTreeTable::Next() {
    if (iterStack.empty()) {
        *ppCurrentNode = nullptr;
        return IsTabEnded();
    }

    if (iterStack.top().first->pRight == nullptr)
        iterStack.top().second = true;

    if (iterStack.top().second) {
        ppCurrentNode = &iterStack.top().first;
        iterStack.pop();
        return IsTabEnded();
    }

    ppCurrentNode = &(iterStack.top().first->pRight);
    iterStack.top().second = true;

    FillStackLeftNodes();

    return Next();
}

int TTreeTable::IsTabEnded() const {
    return *ppCurrentNode == nullptr;
}

TKey TTreeTable::GetKey() const {
    return (*ppCurrentNode)->key;
}

TDataValue *TTreeTable::GetValue() const {
    return (*ppCurrentNode)->value;
}

void TTreeTable::DeleteTree(TTreeNode *pNode) {
    for (Reset(); !IsTabEnded(); Next())
        delete (*ppCurrentNode);
}

TTreeNode** TTreeTable::Minimum(TTreeNode *node) {
    auto pNode = &node;
    std::stack<TTreeNode*> temp;
    while (node->pLeft != nullptr){
        temp.push(node);
        pNode = &(node->pLeft);
        node = *pNode;
    }
    iterStack.emplace(node, false);

    while (!temp.empty()) {
        iterStack.emplace(temp.top(), false);
        temp.pop();
    }

    return pNode;
}

void TTreeTable::FillStackLeftNodes() {
    iterStack.emplace(*ppCurrentNode, false);
    while ((*ppCurrentNode)->pLeft != nullptr){
        ppCurrentNode = &(*ppCurrentNode)->pLeft;
        iterStack.emplace(*ppCurrentNode, false);
    }
}
