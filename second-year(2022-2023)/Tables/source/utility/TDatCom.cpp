//
// Created by Андрей Юрин on 27.03.2023.
//

#include "../../include/utility/TDatCom.h"

int TDatCom::SetRetCode(int retCode) {
    return this->retCode = retCode;
}

TDatCom::TDatCom() {
    retCode = DATA_OK;
}

int TDatCom::GetRetCode() {
    return retCode;
}
