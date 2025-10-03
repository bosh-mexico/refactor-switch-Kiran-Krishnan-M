#include "handlers.h"
#include <string>

std::string handlePayPal(double amount) {
    return "Processed PayPal payment of " + std::to_string(amount);
}

std::string handleGooglePay(double amount) {
    return "Processed GooglePay payment of " + std::to_string(amount);
}

std::string handleCreditCard(double amount) {
    return "Processed CreditCard payment of " + std::to_string(amount);
}

std::string handleInvalid(double amount) {
    return "Invalid payment method. Amount " + std::to_string(amount) + " not processed.";
}
