## Клас `DiscountCardRegistry`

Класът `DiscountCardRegistry` е отговорен за съхранението и проверката на валидни карти за намаление. Той работи като регистър, в който се запазват валидни номера на карти.

### Декларация (опростена)

```cpp
class DiscountCardRegistry {
private:
    std::unordered_set<std::string> validCardIDs;

public:
    void addValidCard(const std::string& cardID);
    bool isCardValid(const std::string& cardID) const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};
```

### Основни методи

#### `void addValidCard(const std::string& cardID)`

Добавя нов ID на карта към множеството от валидни IDта. Използвателят (обикновено admin) я извиква чрез `validate-discount-card <ID>`.

#### `bool isCardValid(const std::string& cardID) const`

Проверява дали конкретно ID на карта съществува в регистра.

#### `void saveToFile(const std::string& filename) const`

Записва всички валидни ID в файл на отделени редове. Примерен файл:

```
532421
827345
111495
```

#### `void loadFromFile(const std::string& filename)`

Зарежда валидни ID от текстов файл и ги добавя в множеството.

### Забележки

* Този клас няма зависимост от типовете на картите (AgeCard, RouteCard...), а само от IDта им.
* При валидиране на карта, тя бива добавяна в `DiscountCardRegistry` чрез `addValidCard`.
