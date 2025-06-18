## Класове за карти за отстъпка

В системата има базов абстрактен клас `DiscountCard` и три конкретни негови наследника:

* `AgeCard`
* `RouteCard`
* `DistanceCard`

Тези карти предоставят възможност за различни видове отстъпки при покупка на билет.

---

### Базов клас: `DiscountCard`

```cpp
class DiscountCard {
protected:
    std::string owner;
    std::string cardID;

public:
    DiscountCard(std::string owner, std::string cardID);
    virtual ~DiscountCard() = default;

    std::string getOwner() const;
    std::string getCardID() const;

    virtual std::string getType() const = 0;
};
```

* `owner` – име на притежателя
* `cardID` – уникален идентификатор на картата
* `getType()` – връща типа на картата като текст (виртуален метод)

---

### `AgeCard`

Карта, която предоставя отстъпка според възрастта на притежателя.

```cpp
class AgeCard : public DiscountCard {
private:
    int age;
public:
    AgeCard(std::string owner, std::string cardID, int age);
    int getAge() const;
    std::string getType() const override;
};
```

* Под 10 години: 100% отстъпка
* Под 18 години: 50%
* Иначе: 20%

---

### `RouteCard`

Карта, която предоставя 100% отстъпка ако дестинацията на влака съвпада с дестинацията в картата.

```cpp
class RouteCard : public DiscountCard {
private:
    std::string destination;
public:
    RouteCard(std::string owner, std::string cardID, std::string destination);
    std::string getDestination() const;
    std::string getType() const override;
};
```

---

### `DistanceCard`

Карта, която предоставя отстъпка в зависимост от разстоянието на пътуването.

```cpp
class DistanceCard : public DiscountCard {
private:
    int maxDistance;
public:
    DistanceCard(std::string owner, std::string cardID, int maxDistance);
    int getMaxDistance() const;
    std::string getType() const override;
};
```

* Ако разстоянието на пътуването е по-малко от `maxDistance` → 50% отстъпка
* Иначе → 30% отстъпка

---

### Обработка и използване

* Картите се зареждат от файлове чрез `loadCardFromFile()`
* Валидират се чрез `DiscountCardRegistry`
* Прилагат се автоматично при извикване на `buyTicketWithDiscount()`

---

### Обобщение

Трите вида карти наследяват общ базов интерфейс и реализират специфични правила за отстъпки. Това позволява система с отворена архитектура, където могат лесно да се добавят нови типове карти в бъдеще.
