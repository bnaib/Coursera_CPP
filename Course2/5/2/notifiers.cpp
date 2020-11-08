#include <iostream>
#include <string>

using namespace std;

void SendSms(const string& number, const string& message);
void SendEmail(const string& email, const string& message);

class INotifier {
  public:
    virtual void Notify(const string& message) const = 0;
};

class SmsNotifier : public INotifier {
  private:
    const string Phone;
  public:
    SmsNotifier(const string& phone) : Phone(phone) {}
    void Notify(const string& message) const override {
      SendSms(Phone, message);
    }
};

class EmailNotifier : public INotifier {
  private:
    const string Email;
  public:
    EmailNotifier(const string& email) : Email(email) {}
    void Notify(const string& message) const override {
      SendEmail(Email, message);
    }
};
