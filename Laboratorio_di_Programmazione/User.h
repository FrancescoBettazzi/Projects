//
// Created by francesco on 31/08/19.
//

#ifndef LABORATORYEXERCISE_USER_H
#define LABORATORYEXERCISE_USER_H

#include <list>
#include <iostream>
#include <memory>
#include "Chat.h"

class User {
public:
    User(std::string n) : name(n) {
    }

    ~User() {
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        User::name = name;
    }

    void addChat(std::shared_ptr<Chat> ch) {
        if(ch->getMyName() == this->getName() || ch->getOtherName() == this->getName())
            chats.push_back(ch);
        else
            throw std::runtime_error("Error in users");
    }

    void removeChat(const std::shared_ptr<User> &re) {
        chats.remove(findChat(re));
    }

    void setReadByPosition(std::shared_ptr<User> &re, int pos) {
        findChat(re)->setReadByPosition(pos);
    }

    void setTextByPosition(const std::shared_ptr<User> &re, int pos, std::string &text) {
        findChat(re)->setTextByPosition(pos,text);
    }

    std::shared_ptr<Chat> findChat(std::shared_ptr<User> re) {
        for(const auto &chat:chats) {
            if(chat->getOtherName() == re->getName())
                return chat;
        }
        throw std::runtime_error("La chat cercata non è presente");
    }

    void sendMessage(std::shared_ptr<User> &re, std::shared_ptr<Message> msg) {
        findChat(re)->addMessage(msg);
    }

private:
    std::list<std::shared_ptr<Chat>> chats;
    std::string name;
};


#endif //LABORATORYEXERCISE_USER_H
