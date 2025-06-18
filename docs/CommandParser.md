## Клас `CommandParser`

Класът `CommandParser` отговаря за интерпретация и изпълнение на команди, подадени от потребителя (въвеждани от конзолата или чрез скрипт). Той използва текущата сесия и регистъра за карти за намаление, за да управлява взаимодействието със системата.

### Член-данни:

```cpp
Session& session;
DiscountCardRegistry& cardRegistry;
std::vector<Station> stations;
int nextTrainID = 1000;
```

### Основни методи

#### `CommandParser(Session& s, DiscountCardRegistry& reg)`

Конструктор, който инициализира парсера със сесия и регистър.

#### `void parseAndExecute(const std::string& line)`

Основният метод, който анализира въведена команда и я изпълнява. Разпознава следните ключови команди:

* `print-stations`
* `print-schedule`, `print-schedule-destination`, `print-schedule-time`
* `print-train`, `print-wagon`
* `buy-ticket`, `buy-ticket-discount`
* `login`
* `add-station`, `add-train`, `remove-train`
* `add-wagon`, `remove-wagon`, `move-wagon`
* `create-discount-card`, `validate-discount-card`

Използва помощни функции за намиране на станции и влакове:

#### `Station* findStationByName(const std::string& name)`

Връща указател към станция с дадено име, ако съществува.

#### `Train* findTrainByID(int id)`

Връща указател към влак по неговото ID.

### Работа с потребителите

В зависимост от текущия потребител (`User& user = session.getCurrentUser()`), командите се делегират към методите на `UnsignedUser` или `AdminUser`. Използва `dynamic_cast`, за да провери дали текущият потребител има администраторски права.

### Специални особености:

* За `add-wagon`, `create-discount-card`, и `validate-discount-card` се използва `std::shared_ptr`, за да се създаде нов обект от тип `Wagon` или `DiscountCard`.
* `nextTrainID` се използва за автоматично генериране на уникални ID за новите влакове.

### Обобщение

`CommandParser` е ключов компонент за взаимодействие между потребителя и системата. Той осигурява гъвкавост и абстракция на командите, поддържа модулността на програмата и използва текущата сесия и регистри за правилна валидация и достъп до функционалности.
