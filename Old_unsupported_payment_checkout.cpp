#include <iostream>
#include <iomanip>
using namespace std;

// Enum for Payment Modes
enum class PaymentMode {
    PayPal,
    GooglePay,
    CreditCard,
    Unknown
};

// Base Processor Interface
class Processor {
public:
    virtual void process(double amount) = 0;
    virtual ~Processor() = default;
};

// PayPal Processor
class PayPalProcessor : public Processor {
public:
    void process(double amount) override {
        cout << "Processing PayPal payment of $" << fixed << setprecision(2) << amount << endl;
    }
};

// GooglePay Processor
class GooglePayProcessor : public Processor {
public:
    void process(double amount) override {
        cout << "Processing GooglePay payment of $" << fixed << setprecision(2) << amount << endl;
    }
};

// CreditCard Processor
class CreditCardProcessor : public Processor {
public:
    void process(double amount) override {
        cout << "Processing Credit Card payment of $" << fixed << setprecision(2) << amount << endl;
    }
};

// Unknown Processor
class UnknownProcessor : public Processor {
public:
    void process(double amount) override {
        cout << "Error: Invalid payment mode selected!" << endl;
    }
};

// Factory to create processors
class ProcessorFactory {
public:
    static Processor* createProcessor(PaymentMode mode) {
        switch (mode) {
            case PaymentMode::PayPal:
                return new PayPalProcessor();
            case PaymentMode::GooglePay:
                return new GooglePayProcessor();
            case PaymentMode::CreditCard:
                return new CreditCardProcessor();
            default:
                return new UnknownProcessor();
        }
    }
};

// Main function
int main() {
    double amount = 150.75;

    PaymentMode modes[] = {
        PaymentMode::PayPal,
        PaymentMode::GooglePay,
        PaymentMode::CreditCard,
        PaymentMode::Unknown
    };

    for (auto mode : modes) {
        Processor* processor = ProcessorFactory::createProcessor(mode);
        processor->process(amount);
        delete processor;
    }

    return 0;
}
