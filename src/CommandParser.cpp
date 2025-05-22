#include "CommandParser.h"
#include "TicketManager.h"
#include "FirstClassWagon.h"
#include "SecondClassWagon.h"
#include "SleeperWagon.h"
#include "AgeCard.h"
#include "RouteCard.h"
#include "DistanceCard.h"
#include <sstream>
#include <iostream>
#include <memory>
#include <cstdlib>

CommandParser::CommandParser(Session& s, DiscountCardRegistry& reg)
    : session(s), cardRegistry(reg) {}

Station* CommandParser::findStationByName(const std::string& name) {
    for (auto& s : stations)
        if (s.getName() == name) return &s;
    return nullptr;
}

Train* CommandParser::findTrainByID(int id) {
    for (auto& s : stations)
        for (auto& t : s.getDepartingTrains())
            if (t->getID() == id) return t.get();
    return nullptr;
}
    void CommandParser::parseAndExecute(const std::string& line) {
        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd;

        User& user = session.getCurrentUser();

        if (cmd == "print-stations") {
            user.printStations(stations);
        }
        else if (cmd == "print-schedule") {
            std::string st;
            iss >> st;
            Station* s = findStationByName(st);
            if (s) user.printSchedule(*s);
            else std::cout << "Station not found\n";
        }
        else if (cmd == "print-schedule-destination") {
            std::string st, dest;
            iss >> st >> dest;
            Station* s = findStationByName(st);
            if (s) user.printScheduleToDestination(*s, dest);
            else std::cout << "Station not found\n";
        }
        else if (cmd == "print-schedule-time") {
            std::string st, d, t;
            iss >> st >> d >> t;
            Station* s = findStationByName(st);
            if (s) user.printScheduleAfterTime(*s, d, t);
            else std::cout << "Station not found\n";
        }
        else if (cmd == "print-train") {
            int id;
            iss >> id;
            Train* t = findTrainByID(id);
            if (t) user.printTrainInfo(*t);
            else std::cout << "Train not found\n";
        }
        else if (cmd == "print-wagon") {
            int tid, wid;
            iss >> tid >> wid;
            Train* t = findTrainByID(tid);
            if (t) user.printWagonInfo(*t, wid);
            else std::cout << "Train not found\n";
        }
        else if (cmd == "buy-ticket") {
            int tid, wid, sid;
            std::string filename;
            std::vector<std::string> extras;
            iss >> tid >> wid >> sid >> filename;
            std::string p;
            while (iss >> p) extras.push_back(p);
            Train* t = findTrainByID(tid);
            if (t) user.buyTicket(*t, wid, sid, filename, extras);
            else std::cout << "Train not found\n";
        }
        else if (cmd == "buy-ticket-discount") {
            int tid, wid, sid;
            std::string filename, cardfile;
            std::vector<std::string> extras;
            iss >> tid >> wid >> sid >> filename >> cardfile;
            std::string p;
            while (iss >> p) extras.push_back(p);
            Train* t = findTrainByID(tid);
            if (t) user.buyTicketWithDiscount(*t, wid, sid, filename, cardfile, extras);
            else std::cout << "Train not found\n";
        }
        else if (cmd == "login") {
            std::string uname, pass;
            iss >> uname >> pass;
            session.login(uname, pass);
        }
        else if (cmd == "add-station") {
            std::string name;
            iss >> name;
            if (auto* admin = dynamic_cast<AdminUser*>(&user))
                admin->addStation(stations, name);
            else std::cout << "Error: Admin only\n";
        }
        else if (cmd == "add-train") {
            std::string from, to, date, time;
            int distance, speed;
            iss >> from >> to >> distance >> speed >> date >> time;
            Station* s1 = findStationByName(from);
            Station* s2 = findStationByName(to);
            if (!s1 || !s2) { std::cout << "Station not found\n"; return; }
            if (auto* admin = dynamic_cast<AdminUser*>(&user))
                admin->addTrain(*s1, *s2, distance, speed, date + " " + time, nextTrainID++);
            else std::cout << "Admin only\n";
        }
        else if (cmd == "remove-train") {
            int tid;
            iss >> tid;
            for (auto& s : stations)
                if (auto t = s.getTrainByID(tid)) {
                    if (auto* admin = dynamic_cast<AdminUser*>(&user))
                        admin->removeTrain(s, tid);
                    return;
                }
            std::cout << "Train not found\n";
        }
        else if (cmd == "add-wagon") {
            int tid;
            std::string type;
            double base;
            iss >> tid >> type >> base;
            std::vector<std::string> params;
            std::string p;
            while (iss >> p) params.push_back(p);
            Train* t = findTrainByID(tid);
            if (!t) { std::cout << "Train not found\n"; return; }
            if (auto* admin = dynamic_cast<AdminUser*>(&user)) {
                std::shared_ptr<Wagon> w;
                int id = t->getWagons().size() + 1;
                if (type == "first-class") w = std::make_shared<FirstClassWagon>(id, base, std::stod(params[0]));
                else if (type == "second-class") w = std::make_shared<SecondClassWagon>(id, base, std::stod(params[0]));
                else if (type == "sleeper") w = std::make_shared<SleeperWagon>(id, base, std::stod(params[0]));
                if (w) admin->addWagon(*t, w);
            } else std::cout << "Admin only\n";
        }
        else if (cmd == "remove-wagon") {
            int tid, wid;
            iss >> tid >> wid;
            Train* t = findTrainByID(tid);
            if (t && dynamic_cast<AdminUser*>(&user))
                dynamic_cast<AdminUser*>(&user)->removeWagon(*t, wid);
            else std::cout << "Admin only or train not found\n";
        }
        else if (cmd == "move-wagon") {
            int fromID, wid, toID;
            iss >> fromID >> wid >> toID;
            Train* f = findTrainByID(fromID);
            Train* t = findTrainByID(toID);
            if (f && t && dynamic_cast<AdminUser*>(&user))
                dynamic_cast<AdminUser*>(&user)->moveWagon(*f, *t, wid);
            else std::cout << "Admin only or train not found\n";
        }
        else if (cmd == "create-discount-card") {
            std::string type, name, file;
            iss >> type >> name >> file;
            std::vector<std::string> extras;
            std::string p;
            while (iss >> p) extras.push_back(p);
            std::string id = std::to_string(rand() % 900000 + 100000);
            std::shared_ptr<DiscountCard> card;
            if (type == "age-card") card = std::make_shared<AgeCard>(name, id, std::stoi(extras[0]));
            else if (type == "route-card") card = std::make_shared<RouteCard>(name, id, extras[0]);
            else if (type == "distance-card") card = std::make_shared<DistanceCard>(name, id, std::stoi(extras[0]));
            if (auto* admin = dynamic_cast<AdminUser*>(&user))
                admin->createDiscountCard(card, file);
        }
        else if (cmd == "validate-discount-card") {
            std::string cid;
            iss >> cid;
            if (auto* admin = dynamic_cast<AdminUser*>(&user))
                admin->validateDiscountCard(cid, cardRegistry);
        }
        else {
            std::cout << "Unknown command\n";
        }
    }
