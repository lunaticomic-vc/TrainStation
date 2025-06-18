## Клас: AdminUser

`AdminUser` е конкретна реализация на абстрактния базов клас `User`. Представлява администратор в системата, който има право да променя данни: добавя/премахва гари, влакове и вагони, създава и валидира карти за отстъпка, и извършва действия като покупка на билети.

---

### Конструктор:

```cpp
AdminUser(const std::string& username);
```

* Създава нов обект с дадено потребителско име.

---

### Информация

#### `void printStations(const std::vector<Station>& stations) const override;`

Извежда имената на всички гари от подадения вектор на конзолата.

#### `void printSchedule(const Station& s) const override;`

Извежда пълното разписание на дадена гара.

#### `void printScheduleToDestination(const Station& s, const std::string& d) const override;`

Извежда само влаковете, които пътуват от дадената гара до посочената дестинация `d`.

#### `void printScheduleAfterTime(const Station& s, const std::string& d, const std::string& t) const override;`

Извежда само влаковете от гарата `s`, които тръгват след време `t` към дестинация `d`.

#### `void printTrainInfo(const Train& t) const override;`

Извежда цялата информация за конкретен влак `t` (ID, маршрути, разписание, платформи, вагони).

#### `void printWagonInfo(const Train& t, int id) const override;`

Намира вагон с ID `id` във влака `t` и извежда информация за него (тип, места, цена и т.н.).

---

### Билети

#### `void buyTicket(...) const override;`

Извиква глобалната функция `buyTicket()` от `TicketManager`, за да купи билет без отстъпка.

#### `void buyTicketWithDiscount(...) const override;`

Извиква глобалната функция `buyTicketWithDiscount()` от `TicketManager`, за да купи билет с отстъпка.

---

### Добавяне на обекти

#### `void addStation(std::vector<Station>& stations, const std::string& name) const;`

Добавя нова гара с име `name` в подадения списък и отпечатва съобщение.

#### `void addTrain(Station& from, Station& to, ...) const;`

Създава нов обект `Train`, инициализира параметрите му (разстояние, скорост, време, платформи), изчислява време на пристигане и добавя влака към гарата на тръгване.

#### `void addWagon(Train& train, std::shared_ptr<Wagon> wagon) const;`

Добавя подадения вагон към влака. Извиква метода `train.addWagon()`, който автоматично му присвоява ID.

---

### Премахване и преместване

#### `void removeTrain(Station& station, int trainID) const;`

Премахва влак с ID `trainID` от дадената гара. Извежда съобщение.

#### `void removeWagon(Train& train, int wagonID) const;`

Премахва вагон с дадено ID от конкретен влак.

#### `void moveWagon(Train& source, Train& dest, int wagonID) const;`

Премества вагон с ID `wagonID` от влак `source` във влак `dest`, ако съществува.

---

### Отстъпки

#### `void createDiscountCard(std::shared_ptr<DiscountCard> card, const std::string& fileName) const;`

Създава файл с информация за карта за отстъпка (в зависимост от типа: Age, Route, Distance). Извежда потвърждение.

#### `void validateDiscountCard(const std::string& cardID, DiscountCardRegistry& registry) const;`

Добавя ID на карта към регистъра на валидни карти.

---

### Забележки

* Повечето действия използват `std::shared_ptr`, тъй като влаковете и вагоните се споделят между обекти и се управляват динамично.
* Класът е изцяло ориентиран към администрация на данни и не съдържа вътрешно състояние (освен `username`).


