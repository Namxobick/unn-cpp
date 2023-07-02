//
// Created by Андрей Юрин on 25.06.2023.
//

#ifndef TABLES_TAVLTREETABLE_H
#define TABLES_TAVLTREETABLE_H


#include "TTreeTable.h"
#include "../data-structure/utility/TAVLTreeNode.h"

class TAVLTreeTable: public TTreeTable{
public:
    TAVLTreeTable() : TTreeTable(){};
    ~TAVLTreeTable() override = default;

    bool Insert(TKey key, TDataValue *value) override;
    void Remove(TKey key) override;

private:
    TAVLTreeNode* RotateLeft(TAVLTreeNode* node);
    TAVLTreeNode* RotateRight(TAVLTreeNode* node);
    TAVLTreeNode* Balance(TAVLTreeNode* node);
    void BalancePath();
};


#endif //TABLES_TAVLTREETABLE_H
