#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "PaymentType.h"
#include <string>

std::string checkout(PaymentType type, double amount);

#endif
