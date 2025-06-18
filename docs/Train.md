## Клас `Train`

Класът `Train` представя влак с уникално ID, начална и крайна гара, разписание и списък от вагони.

### Декларация на класа (опростена)

```cpp
class Train {
private:
    int id;
    std::string from;
    std::string to;
    std::string departureDateTime;
    std::string arrivalDateTime;
    int departurePlatform;
    int arrivalPlatform;
    int distance;
    int speed;
    std::vector<std::shared_ptr<Wagon>> wagons;

public:
    Train(...);
    void setDeparturePlatform(int platform);
    void setArrivalPlatform(int platform);
    void calculateArrivalTime();
    void addWagon(std::shared_ptr<Wagon> wagon);
    void removeWagon(int wagonID);
    std::shared_ptr<Wagon> getWagonByID(int id) const;
    const std::vector<std::shared_ptr<Wagon>>& getWagons() const;
    void printInfo() const;

    // Гетъри
    int getID() const;
    std::string getDepartureTime() const;
    std::string getArrivalTime() const;
    std::string getDestination() const;
    int getDeparturePlatform() const;
    int getDistance() const;
};
```

### Конструктор

Инициализира влак с ID, посока, дата/час, разстояние и скорост. Вагони се добавят допълнително.

### Основни методи

#### `setDeparturePlatform(int)` и `setArrivalPlatform(int)`

Задават номер на платформа за тръгване и пристигане. Използват се при добавяне на влак от администратор.

#### `calculateArrivalTime()`

Изчислява очакваното време на пристигане, като добавя `(distance / speed)` в часове към времето на тръгване. Използва `std::tm` и `mktime()` за коректно управление на часа.

#### `addWagon(...)`

Добавя вагон към влака. При нужда му задава ID на база текущия брой вагони.

#### `removeWagon(int wagonID)`

Премахва вагон от влака по неговото ID. Използва се от `AdminUser`.

#### `getWagonByID(int id)`

Връща споделен указател към вагон с даден ID или `nullptr` ако не съществува.

#### `getWagons()`

Връща всички вагони на влака.

#### `printInfo()`

Извежда информация за влака: ID, посока, дата, часове, платформи, списък с ID-тата на вагоните.

### Гетъри

* `getID()` – уникалният идентификатор
* `getDepartureTime()` – времето на тръгване
* `getArrivalTime()` – времето на пристигане (ако е изчислено)
* `getDestination()` – името на крайната гара
* `getDeparturePlatform()` – номер на платформа
* `getDistance()` – разстоянието в километри

### Забележки

* Вагони се съхраняват като `shared_ptr`, за да може други обекти (напр. при преместване между влакове) да ги използват без дублиране.
* Времето се пази като `std::string`, за да се показва удобно, но при нужда се преобразува в `std::tm` за аритметика.

Класът `Train` е основен елемент от модела на системата. Управлява се само от `AdminUser`, а данните му се използват от всички потребители за визуализация и закупуване на билети.
