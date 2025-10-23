/**
 * Labb 05, dt047g HT2023
 * @author Hussein Salehi
 * @date 2024-03-26
 * @brief The STL vector container, function objects
 */



#ifndef LAB4_STL_METODIK_EMAIL_H
#define LAB4_STL_METODIK_EMAIL_H
#include<string>
#include<vector>

class Email {
private:
    std::string who;
    std::string date;
    std::string subject;

public:
    Email(std::string who, std::string date, std::string subject);
    Email() = default;


    friend std::ostream& operator<<(std::ostream& os, const Email email);
    friend struct CompWhoDateSubject;
    friend struct CompDateWhoSubject;
    friend struct CompSubjectWheDate;

};


// the comparison is based on the lexicographical order
struct CompWhoDateSubject{
    bool operator()(const Email& lhs, const Email& rhs){
        if(lhs.who != rhs.who){
            return lhs.who < rhs.who;
        }else if(lhs.date != rhs.date){
            return lhs.date < rhs.date;
        }else{
            return lhs.subject < rhs.subject;
        }
    }
};

// the comparison is based on the chronological order meaning which occur first.
struct CompDateWhoSubject{
    bool operator()(const Email& lhs, const Email& rhs){
        if(lhs.date != rhs.date){
            return lhs.date < rhs.date;
        }else if(lhs.who != rhs.who){
            return lhs.who < rhs.who;
        }else{
            return lhs.subject < rhs.subject;
        }
    }
};

// the comparison is based on the lexicographical order
struct CompSubjectWheDate{
    bool operator()(const Email& lhs, const Email& rhs){
        if(lhs.subject != rhs.subject){
            return lhs.subject < rhs.subject;
        }else if(lhs.date != rhs.date){
            return lhs.date < rhs.date;
        }else{
            return lhs.subject < rhs.subject;
        }
    }
};


class MailBox{
private:
    std::vector<Email> emails;

public:
    //MailBox()= default;
    MailBox(size_t size=0);
    void addEmail(const Email& email);
    int getSize()const;
    std::vector<Email> getEmail() const;
    void sortWho();
    void sortDate();
    void sortSubject();
};
#endif //LAB4_STL_METODIK_EMAIL_H
