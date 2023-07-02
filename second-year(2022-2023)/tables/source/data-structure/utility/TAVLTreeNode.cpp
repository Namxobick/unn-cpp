//
// Created by Андрей Юрин on 25.06.2023.
//

#include "../../../include/data-structure/utility/TAVLTreeNode.h"

TAVLTreeNode::TAVLTreeNode(const TKey &key, TDataValue *pValue, TTreeNode *pLeft, TTreeNode *pRight) : TTreeNode(key,
                                                                                                                 pValue,
                                                                                                                 pLeft,
                                                                                                                 pRight) {
    height = 1;
}

int8_t TAVLTreeNode::GetHeight() const {
    return height;
}

int8_t TAVLTreeNode::GetBalanceFactor() {
    int8_t heightLeft = dynamic_cast<TAVLTreeNode *>(pLeft) ? dynamic_cast<TAVLTreeNode *>(pLeft)->height : 0;
    int8_t heightRight = dynamic_cast<TAVLTreeNode *>(pRight) ?  dynamic_cast<TAVLTreeNode *>(pRight)->height : 0;
    return heightRight - heightLeft;
}

void TAVLTreeNode::FixHeight() {
    int8_t heightLeft = dynamic_cast<TAVLTreeNode *>(pLeft) ? dynamic_cast<TAVLTreeNode *>(pLeft)->height : 0;
    int8_t heightRight = dynamic_cast<TAVLTreeNode *>(pRight) ?  dynamic_cast<TAVLTreeNode *>(pRight)->height : 0;
    height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}


