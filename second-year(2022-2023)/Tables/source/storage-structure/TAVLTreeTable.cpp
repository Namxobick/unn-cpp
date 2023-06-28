//
// Created by Андрей Юрин on 25.06.2023.
//

#include "../../include/storage-structure/TAVLTreeTable.h"

bool TAVLTreeTable::Insert(TKey key, TDataValue *value) {
    if (Find(key).has_value()) {
        SetRetCode(TAB_REC_DOUBLE);
        return false;
    }
    *ppCurrentNode = new TAVLTreeNode(key, value);
    efficiencyIndicator++;
    TTable::size++;

    BalancePath();

    SetRetCode(TAB_OK);
    return true;
}

void TAVLTreeTable::Remove(TKey key) {
    TTreeTable::Remove(key);

    BalancePath();
}

TAVLTreeNode* TAVLTreeTable::RotateLeft(TAVLTreeNode *node) {
    auto current = dynamic_cast<TAVLTreeNode *>(node->pRight);

    node->pRight = current->pLeft;
    current->pLeft = node;

    node->FixHeight();
    current->FixHeight();

    return current;
}

TAVLTreeNode* TAVLTreeTable::RotateRight(TAVLTreeNode *node) {
    auto current = dynamic_cast<TAVLTreeNode *>(node->pLeft);

    node->pLeft = current->pRight;
    current->pRight = node;

    node->FixHeight();
    current->FixHeight();

    return current;
}

TAVLTreeNode* TAVLTreeTable::Balance(TAVLTreeNode* node) {
    node->FixHeight();

    if (node->GetBalanceFactor() == 2){
        if (dynamic_cast<TAVLTreeNode *>(node->pRight)->GetBalanceFactor() < 0)
            node->pRight = RotateRight(dynamic_cast<TAVLTreeNode *>(node->pRight));
        return RotateLeft(node);
    }

    if (node->GetBalanceFactor() == -2){
        if (dynamic_cast<TAVLTreeNode *>(node->pLeft)->GetBalanceFactor() > 0)
            node->pLeft = RotateLeft(dynamic_cast<TAVLTreeNode *>(node->pLeft));
        return RotateRight(node);
    }
    return node;
}

void TAVLTreeTable::BalancePath() {
    while (!iterStack.empty()) {
        auto node = dynamic_cast<TAVLTreeNode *>(iterStack.top().first);
        iterStack.pop();
        node = Balance(node);

        if (!iterStack.empty()) {
            auto parentNode = dynamic_cast<TAVLTreeNode *>(iterStack.top().first);

            if (node->key < parentNode->key)
                parentNode->pLeft = node;
            else
                parentNode->pRight = node;
        }
        else
            pRoot = node;
    }
}

