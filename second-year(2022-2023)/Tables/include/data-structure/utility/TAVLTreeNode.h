//
// Created by Андрей Юрин on 25.06.2023.
//

#ifndef TABLES_TAVLTREENODE_H
#define TABLES_TAVLTREENODE_H


#include "TTreeNode.h"

class TAVLTreeNode: public TTreeNode{
protected:
    int8_t height;
public:
    explicit TAVLTreeNode(const TKey& key = "", TDataValue* pValue = nullptr, TTreeNode* pLeft = nullptr, TTreeNode* pRight = nullptr);
    ~TAVLTreeNode() override = default;

    [[nodiscard]] int8_t GetHeight() const;
    int8_t GetBalanceFactor();
    void FixHeight();

    friend class TAVLTreeTable;
};


#endif //TABLES_TAVLTREENODE_H
