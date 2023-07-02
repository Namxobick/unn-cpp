//
// Created by Андрей Юрин on 27.03.2023.
//

#ifndef TABLES_TDATCOM_H
#define TABLES_TDATCOM_H

#define DATA_OK 0
#define DATA_ERROR (-1)

class TDatCom {
protected:
    int retCode;

    int SetRetCode(int retCode);

public:
    TDatCom();
    virtual ~TDatCom() = default;
    int GetRetCode();
};


#endif //TABLES_TDATCOM_H
