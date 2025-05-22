import os
import re

def extract_card_id(file):
    with open(file, "r") as f:
        for line in f:
            match = re.search(r"(\\d{6})", line)
            if match:
                return match.group(1)
    return None


card_file = "RouteCard.txt"
card_id = extract_card_id(card_file)

if not card_id:
    print("Could not extract valid 6-digit card ID from RouteCard.txt")
else:
    print(f"Found card ID: {card_id}")

    with open("validate_cmd.txt", "w") as f:
        f.write("login admin1 password123\n")
        f.write(f"validate-discount-card {card_id}\n")
        f.write(f"buy-ticket-discount 1000 1 9 ticket2.txt RouteCard.txt true\n")
        f.write("exit\n")

    os.system("./build/train_app < validate_cmd.txt")
    os.system("python3 verify_tickets.py")
