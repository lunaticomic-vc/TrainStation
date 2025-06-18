## Клас `Session`

Класът `Session` отговаря за текущата потребителска сесия – дали е влязъл потребител, дали е администратор, както и управлението на смяната на потребители.

### Декларация (опростена)

```cpp
class Session {
private:
    std::unique_ptr<User> currentUser;
    std::unordered_map<std::string, std::string> adminAccounts;
    DiscountCardRegistry& cardRegistry;

public:
    Session(DiscountCardRegistry& registry);
    void login(const std::string& username, const std::string& password);
    User& getCurrentUser();
    void loadAdminAccounts(const std::string& filename);
};
```

### Конструктор

```cpp
Session(DiscountCardRegistry& registry);
```

Създава нова сесия със зададен референция към регистъра за карти за намаление. По подразбиране текущият потребител е `UnsignedUser`.

### Основни методи

#### `void login(const std::string& username, const std::string& password)`

Проверява дали даденото име и парола съвпадат с администраторски акаунт. Ако съвпадат, създава `AdminUser`. В противен случай – извежда съобщение за грешка.

#### `User& getCurrentUser()`

Връща референция към текущия потребител. Може да бъде както `UnsignedUser`, така и `AdminUser`.

#### `void loadAdminAccounts(const std::string& filename)`

Зарежда потребителски имена и пароли от текстов файл, където всеки ред съдържа име и парола, разделени с интервал.

### Особености

* Използва `std::unique_ptr<User>` за текущ потребител, което позволява лесно превключване между различни типове потребители.
* Управлението на потребителските команди и права се извършва на базата на `dynamic_cast` в командния парсър.
* Работи съвместно с `DiscountCardRegistry`, за да валидира карти за намаление.

### Обобщение

`Session` е помощен клас, който държи текущото състояние на потребителя и позволява вход и смяна на права. Работи задкулисно с другите компоненти на системата, но е жизненоважен за правилната логика на достъп и администриране.
