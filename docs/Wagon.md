## Клас `Wagon`

Класът `Wagon` е абстрактен базов клас, който представя общата функционалност на всички типове вагони. Той се използва като родител за конкретни типове: `FirstClassWagon`, `SecondClassWagon`, и `SleeperWagon`.

### Декларация

```cpp
class Wagon {
protected:
    int id;
    double basePrice;
    std::vector<bool> seats;

public:
    Wagon(int id, double basePrice, int seatCount);
    virtual ~Wagon() = default;

    int getId() const;
    int getSeatCount() const;
    bool isSeatAvailable(int index) const;
    void occupySeat(int index);

    virtual double calculatePrice(int seatIndex, const std::vector<std::string>& extraParams) const = 0;
    virtual void printInfo() const = 0;
    virtual std::string getType() const = 0;
};
```

### Основни методи

#### `getId()`

Връща уникалния идентификатор на вагона в рамките на влака.

#### `getSeatCount()`

Връща броя на местата във вагона.

#### `isSeatAvailable(index)`

Проверява дали мястото с даден индекс е свободно.

#### `occupySeat(index)`

Маркира място като заето.

#### `calculatePrice(...)`

Чисто виртуална функция. Реализацията зависи от типа на вагона и използва допълнителни параметри (напр. багаж или комфортен коефициент).

#### `printInfo()`

Абстрактен метод, който всеки наследник имплементира, за да отпечата детайли за вагона.

#### `getType()`

Връща текстово описание на типа на вагона.

### Наследници

#### `FirstClassWagon`

* Добавя поле: `comfortFactor`
* `calculatePrice`: Базирана на `basePrice` и комфорт
* Места: 10

#### `SecondClassWagon`

* Добавя поле: `pricePerKg`
* `calculatePrice`: Добавя цена за багаж
* Места: 20

#### `SleeperWagon`

* Добавя поле: `bedSurcharge`
* `calculatePrice`: Добавя фиксирана надценка за спално място
* Места: 15

### Забележки

* Класът използва `std::vector<bool>` за места, като всеки елемент отговаря на заето/свободно.
* Използваме `shared_ptr<Wagon>` когато добавяме към влак, за да позволим споделена собственост между `Train` и други обекти (например `AdminUser`).

`Wagon` е основа за полиморфизъм при вагони и позволява лесно разширение с нови типове.
