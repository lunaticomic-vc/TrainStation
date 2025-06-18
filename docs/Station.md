## Клас `Station`

Класът `Station` представя една железопътна гара. Съдържа информация за името на гарата, брой платформи и списък с влакове, които тръгват от нея.

### Декларация (опростена)

```cpp
class Station {
private:
    std::string name;
    int platformCount;
    std::vector<std::shared_ptr<Train>> departingTrains;
    std::vector<bool> platformOccupied;

public:
    Station(const std::string& name, int platforms);
    const std::string& getName() const;
    int getAvailablePlatform();
    void addTrain(std::shared_ptr<Train> train);
    void removeTrain(int trainID);
    std::shared_ptr<Train> getTrainByID(int trainID) const;
    const std::vector<std::shared_ptr<Train>>& getDepartingTrains() const;
    void printSchedule() const;
    void printScheduleToDestination(const std::string& destination) const;
    void printScheduleAfterTime(const std::string& date, const std::string& time) const;
};
```

### Конструктор

```cpp
Station(const std::string& name, int platforms);
```

Създава гара с име и зададен брой платформи. Всички платформи се отбелязват като свободни в `platformOccupied`.

### Основни методи

#### `getName()`

Връща името на гарата.

#### `getAvailablePlatform()`

Намира и връща първата свободна платформа. Ако няма свободни, връща `1` по подразбиране.

#### `addTrain(...)`

Добавя влак към списъка на тръгващите. Платформата се отбелязва като заета.

#### `removeTrain(trainID)`

Премахва влак с дадено ID от гарата. Ако го намери, освобождава и платформата.

#### `getTrainByID(trainID)`

Търси и връща влак по ID. Ако не съществува, връща `nullptr`.

#### `getDepartingTrains()`

Връща списък с всички влакове, тръгващи от гарата.

#### `printSchedule()`

Извежда пълно разписание на тръгващите влакове от гарата: дестинация, час на тръгване, ID на влак и платформа.

#### `printScheduleToDestination(destination)`

Филтрира разписанието и показва само влаковете, които отиват до дадената дестинация.

#### `printScheduleAfterTime(date, time)`

Показва влаковете, които тръгват след зададеното време. Използва се `std::tm` за сравнение на дати и часове.

### Забележки

* Всеки влак се съхранява като `shared_ptr<Train>`, за да може да бъде използван от други обекти (напр. дестинационна гара).
* Платформите се отбелязват чрез `std::vector<bool>`, който отразява дали дадена платформа е заета.

Класът `Station` играе централна роля за организацията на транспорта. Почти всички команди за печат и търсене минават през обект от този клас.
