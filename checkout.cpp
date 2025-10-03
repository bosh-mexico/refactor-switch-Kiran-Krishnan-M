#include "checkout.h"
#include "handlers.h"
#include "ServiceLocator.h"
#include <functional>

std::string checkout(PaymentType type, double amount) {
    if (amount <= 0) {
        return "Invalid amount! Payment not processed.";
    }

    using Handler = std::function<std::string(double)>;
    auto& locator = ServiceLocator<PaymentType, Handler>::instance();
    auto handler = locator.getHandler(type, handleInvalid);
    return handler(amount);
}
