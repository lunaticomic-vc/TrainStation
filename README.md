Класове

Wagon (абстрактен базов клас)
Подкласове:
FirstClassWagon: комфортен фактор
SecondClassWagon: цена за багаж
SleeperWagon: цена според разстояние
Съдържа: ID, места, цена, метод calculatePrice(...)

Train
Има: начало, край, разстояние, платформи, списък от Wagon
Методи: addWagon, printInfo, getWagonByID

Station
Има име, платформи, списък от влакове
Методи: printSchedule, printScheduleToDestination, printScheduleAfterTime

DiscountCard (абстрактен)
Подкласове:
AgeCard
RouteCard
DistanceCard
Метод: getDiscount(const Train&)

DiscountCardRegistry
Пази валидни карти
addValidCard, isCardValid
Зареждане/запис във файл

User (абстрактен интерфейс)
Подкласове:
UnsignedUser: достъп до print, buy-ticket
AdminUser: + add-train, add-wagon, validate-card, create-discount-card

Session
Пази текущия логнат User
login, logout, getCurrentUser
Зарежда админ акаунти

CommandParser
Чете команди от потребителя (или от файл)
Изпълнява ги чрез Session и User
Разпознава всички команди от условието

TicketManager
Функции: buyTicket, buyTicketWithDiscount
Пише билет във .txt файл

ТЕСТОВЕ И ИНТЕГРАЦИЯ

demo_test.txt: демонстрационен скрипт със всички команди
verify_tickets.py: проверява дали ticket1.txt и ticket2.txt са правилни
master_test_script.py: създава влак, карта, валидира я, купува билет, проверява
