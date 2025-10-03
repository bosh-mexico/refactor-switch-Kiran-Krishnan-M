#include <iostream>
#include "PaymentType.h"
#include "ServiceLocator.h"
#include "handlers.h"
#include "checkout.h"
#include <functional>

int main() {
    using Handler = std::function<std::string(double)>;
    auto& locator = ServiceLocator<PaymentType, Handler>::instance();

    locator.registerHandler(PaymentType::PayPal, handlePayPal);
    locator.registerHandler(PaymentType::GooglePay, handleGooglePay);
    locator.registerHandler(PaymentType::CreditCard, handleCreditCard);

    std::cout << checkout(PaymentType::PayPal, 150.0) << "\n";
    std::cout << checkout(PaymentType::GooglePay, 200.0) << "\n";
    std::cout << checkout(PaymentType::CreditCard, 300.0) << "\n";
    std::cout << checkout(PaymentType::Unknown, 400.0) << "\n";
    std::cout << checkout(PaymentType::PayPal, -10.0) << "\n";

    return 0;
}
