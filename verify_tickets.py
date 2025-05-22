import os

def check_ticket_file(filename, expected_fields):
    if not os.path.isfile(filename):
        print(f"File '{filename}' not found.")
        return False

    with open(filename, 'r') as file:
        content = file.read()

    success = True
    for key, expected in expected_fields.items():
        if expected not in content:
            print(f"'{filename}' missing expected: {key} → {expected}")
            success = False
        else:
            print(f"'{filename}' contains {key}: {expected}")
    return success

print("Verifying ticket1.txt...")
ticket1_ok = check_ticket_file("ticket1.txt", {
    "Train ID": "1000",
    "Wagon ID": "2",
    "Seat ID": "5",
    "Price": "70 lv.",
    "Discount": "0 lv."
})

print("\nVerifying ticket2.txt...")
ticket2_ok = check_ticket_file("ticket2.txt", {
    "Train ID": "1000",
    "Wagon ID": "1",
    "Seat ID": "9",
    "Price": "0 lv.",
    "Discount": "50 lv."
})

if ticket1_ok and ticket2_ok:
    print("\nAll tickets look correct!")
else:
    print("\nSome tickets have issues.")
