//
// Created by Андрей Юрин on 26.05.2023.
//

#ifndef TABLES_TTREETABLE_H
#define TABLES_TTREETABLE_H

#include <stack>
#include "utility/TTable.h"
#include "../data-structure/utility/TTreeNode.h"

class TTreeTable : public TTable {
protected:
    TTreeNode* pRoot;
    TTreeNode** ppCurrentNode;
    std::stack<std::pair<TTreeNode*, bool>> iterStack;

public:
    TTreeTable();
    ~TTreeTable() override;

    [[nodiscard]] bool IsFull() const override;

    std::optional<TDataValue *> Find(TKey key) override;
    bool Insert(TKey key, TDataValue *value) override;
    void Remove(TKey key) override;

    int Reset() override;
    int Next() override;
    [[nodiscard]] int IsTabEnded() const override;
    [[nodiscard]] TKey GetKey() const override;
    [[nodiscard]] TDataValue * GetValue() const override;

protected:
    void DeleteTree(TTreeNode* pNode);
    TTreeNode** Minimum(TTreeNode* node);
    void FillStackLeftNodes();
};


#endif //TABLES_TTREETABLE_H
