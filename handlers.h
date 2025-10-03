#ifndef HANDLERS_H
#define HANDLERS_H

#include <string>

std::string handlePayPal(double amount);
std::string handleGooglePay(double amount);
std::string handleCreditCard(double amount);
std::string handleInvalid(double amount);

#endif
