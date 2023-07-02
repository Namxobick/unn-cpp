//
// Created by Андрей Юрин on 23.05.2023.
//

#ifndef TABLES_TTREENODE_H
#define TABLES_TTREENODE_H


#include "../../storage-structure/utility/TTable.h"

class TTreeNode : public TTableRecord{
protected:
    TTreeNode* pLeft, *pRight;
public:
    explicit TTreeNode(const TKey& key = "", TDataValue* pValue = nullptr, TTreeNode* pLeft = nullptr, TTreeNode* pRight = nullptr);
    ~TTreeNode() override = default;

    [[nodiscard]] TTreeNode* GetLeft() const;
    [[nodiscard]] TTreeNode* GetRight() const;
    TDataValue* GetCopy() override;

    friend class TTreeTable;
    friend class TAVLTreeTable;
};


#endif //TABLES_TTREENODE_H
