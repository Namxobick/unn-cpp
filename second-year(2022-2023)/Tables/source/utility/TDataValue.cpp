//
// Created by Андрей Юрин on 20.03.2023.
//

#include "../../include/utility/TDataValue.h"

std::ostream& operator<<(std::ostream& ostream, const TDataValue& datValue) {
    datValue.Print(ostream);
    return ostream;
}
