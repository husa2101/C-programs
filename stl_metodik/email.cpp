/**
 * Labb 05, dt047g HT2023
 * @author Hussein Salehi
 * @date 2024-03-26
 * @brief The STL vector container, function objects
 */


#include "email.h"
#include "iostream"
#include "algorithm"
#include "vector"

// initialize the Email class member
Email::Email(std::string who, std::string date, std::string subject) :
        who(who), date(date), subject(subject) {}

        // overload the <<  operator in order to print the result
std::ostream& operator<<(std::ostream& os, const Email email) {
    os << "From: " << email.who << " Date: " << email.date << " Subject: " << email.subject;
    return os;
}

// add Email to the emailBox
void MailBox::addEmail(const Email &email) {
    emails.push_back(email);
}

// sort the emailBox lexicographically
void MailBox::sortWho() {
    std::sort(emails.begin(), emails.end(),CompWhoDateSubject() );
}

// sort the emailBox chronologically
void MailBox::sortDate() {
    std::sort(emails.begin(), emails.end(),CompDateWhoSubject() );
}

// sort the emailBox lexicographically
void MailBox::sortSubject() {
    std::sort(emails.begin(), emails.end(),CompSubjectWheDate() );
}

// get the emailBox
std::vector<Email> MailBox::getEmail() const {
    return emails;
}

// initialize the emailBox class member
MailBox::MailBox(size_t size):emails(size) {}

// get the size of the emailBox
int MailBox::getSize() const {
    return emails.size();
}



