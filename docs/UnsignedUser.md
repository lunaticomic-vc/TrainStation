## Клас `UnsignedUser`

Класът `UnsignedUser` е конкретна реализация на абстрактния базов клас `User`. Представлява потребител без регистрация (гост), който има достъп само до четящи операции, без права за промени или администриране.

### Декларация на класа

```cpp
class UnsignedUser : public User {
public:
    UnsignedUser() = default;
    ~UnsignedUser() override = default;

    void printStations(const std::vector<Station>& stations) const override;
    void printSchedule(const Station& station) const override;
    void printScheduleToDestination(const Station& station, const std::string& destination) const override;
    void printScheduleAfterTime(const Station& station, const std::string& date, const std::string& time) const override;
    void printTrainInfo(const Train& train) const override;
    void printWagonInfo(const Train& train, int wagonID) const override;

    void buyTicket(Train& train, int wagonID, int seatID, const std::string& ticketFileName, const std::vector<std::string>& extraParams) const override;
    void buyTicketWithDiscount(Train& train, int wagonID, int seatID, const std::string& ticketFileName, const std::string& cardFileName, const std::vector<std::string>& extraParams) const override;
};
```

### Описание на методите

#### `printStations(...)`

Извежда списък с всички станции по имена. Използва се `std::cout` за принтиране.

#### `printSchedule(...)`

Показва пълното разписание за дадена гара (обект от тип `Station`). Вика метода `printSchedule()` на самата гара.

#### `printScheduleToDestination(...)`

Показва само влаковете от дадена гара до конкретна дестинация. Използва `station.printScheduleToDestination(destination)`.

#### `printScheduleAfterTime(...)`

Показва влаковете, които тръгват след зададено време от дадена дата. Използва метода `printScheduleAfterTime(date, time)` на гарата.

#### `printTrainInfo(...)`

Извежда детайлна информация за конкретен влак – ID, посока, платформи, време на тръгване и пристигане.

#### `printWagonInfo(...)`

Извежда детайли за конкретен вагон (тип, цена, свободни места). Ако вагонът не съществува, извежда съобщение за грешка.

#### `buyTicket(...)`

Позволява на гост-потребител да купи билет. Използва глобалната функция `::buyTicket(...)` от `TicketManager.h`. Създава и записва билет във файл с посочено име.

#### `buyTicketWithDiscount(...)`

Същото като `buyTicket(...)`, но използва и карта за отстъпка. Използва глобалната функция `::buyTicketWithDiscount(...)`. Проверката за валидност на картата също е включена.

### Ограничения

* Не притежава администраторски права.
* Няма достъп до методи за добавяне/премахване на станции, влакове и вагони.

### Роля в архитектурата

* Осигурява базова функционалност за потребители, които не са влезли в системата.
* Използва се в `Session`, като началният потребител е от тип `UnsignedUser`.
