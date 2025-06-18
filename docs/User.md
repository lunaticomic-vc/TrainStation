# User клас (абстрактен)

Класът `User` е базов (абстрактен) клас, който дефинира интерфейс за различните типове потребители в системата. Той съдържа чисто виртуални методи, които трябва да бъдат имплементирани от наследниците му (напр. `UnsignedUser`, `AdminUser`).

```cpp
class User {
public:
    virtual ~User() = default;

    virtual void printStations(const std::vector<Station>& stations) const = 0;
    virtual void printSchedule(const Station& station) const = 0;
    virtual void printScheduleToDestination(const Station& station, const std::string& destination) const = 0;
    virtual void printScheduleAfterTime(const Station& station, const std::string& date, const std::string& time) const = 0;
    virtual void printTrainInfo(const Train& train) const = 0;
    virtual void printWagonInfo(const Train& train, int wagonID) const = 0;
    virtual void buyTicket(Train& train, int wagonID, int seatID, const std::string& ticketFileName, const std::vector<std::string>& extraParams) const = 0;
    virtual void buyTicketWithDiscount(Train& train, int wagonID, int seatID, const std::string& ticketFileName, const std::string& cardFileName, const std::vector<std::string>& extraParams, const DiscountCardRegistry& registry) const = 0;
};
```

---

## Обяснение на функциите

### `printStations(const std::vector<Station>& stations)`

* Цел: Извежда списък от имената на всички станции.
* Използва цикъл, за да принтира всяка една.

### `printSchedule(const Station& station)`

* Цел: Извежда цялата расписание за дадена станция.
* Вика `station.printSchedule()`.

### `printScheduleToDestination(const Station& station, const std::string& destination)`

* Цел: Показва влакове, които отпътуват до определена дестинация.
* Вика `station.printScheduleToDestination(destination)`.

### `printScheduleAfterTime(const Station& station, const std::string& date, const std::string& time)`

* Цел: Показва влакове, които стартират след определена дата/час.
* Вика `station.printScheduleAfterTime(date, time)`.

### `printTrainInfo(const Train& train)`

* Цел: Извежда детайли за влак – начало, дестинация, скорост, време, вагони.

### `printWagonInfo(const Train& train, int wagonID)`

* Цел: Показва информация за даден вагон от влака.

### `buyTicket(...)`

* Запазва място във вагон, изчислява цена, записва билет във файл.
* `extraParams` може да включва кг багаж или други.

### `buyTicketWithDiscount(...)`

* Също купува билет, но проверява карта за отстъпка и прилага снижена цена.
* Използва `DiscountCardRegistry`, за да провери дали ID на картата е валиден.


