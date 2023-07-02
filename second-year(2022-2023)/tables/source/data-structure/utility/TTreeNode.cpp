//
// Created by Андрей Юрин on 23.05.2023.
//

#include "../../../include/data-structure/utility/TTreeNode.h"

TTreeNode::TTreeNode(const TKey& key, TDataValue *pValue, TTreeNode *pLeft, TTreeNode *pRight): TTableRecord (key, pValue) {
    this->pLeft = pLeft;
    this->pRight = pRight;
}

TTreeNode *TTreeNode::GetLeft() const {
    return pLeft;
}

TTreeNode *TTreeNode::GetRight() const {
    return pRight;
}

TDataValue *TTreeNode::GetCopy() {
    auto copyPLeft = pLeft == nullptr ? nullptr : (TTreeNode*) pLeft->GetCopy();
    auto copyPRight = pRight == nullptr ? nullptr : (TTreeNode*) pRight->GetCopy();

    return new TTreeNode(key, value->GetCopy(), copyPLeft, copyPRight);
}

