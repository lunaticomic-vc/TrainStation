import os
import re

def extract_card_id(file):
    if not os.path.isfile(file):
        print(f" File '{file}' not found.")
        return None
    with open(file, "r") as f:
        for line in f:
            clean = line.strip().replace("|", "").strip()
            if clean.isdigit() and len(clean) == 6:
                return clean
    return None

# Step 1: Run demo test with base data
print("\n Running base demo_test.txt script...")
os.system("./build/train_app < demo_test.txt")

# Step 2: Create new train + card
print("\n Creating new train with discount card for independent test...")
with open("train_and_card_test.txt", "w") as f:
    f.write("login admin1 password123\n")
    f.write("add-station TestStart\n")
    f.write("add-station TestEnd\n")
    f.write("add-train TestStart TestEnd 100 100 01/01/2026 10:00\n")
    f.write("add-wagon 1000 first-class 50 0.9\n")
    f.write("create-discount-card route-card Test_User RouteCard.txt TestEnd\n")
    f.write("exit\n")
os.system("./build/train_app < train_and_card_test.txt")

# Step 3: Extract card ID from RouteCard.txt
card_id = extract_card_id("RouteCard.txt")
if not card_id:
    print(" Could not extract valid 6-digit card ID from RouteCard.txt")
    exit(1)
print(f" Found card ID: {card_id}")

# Step 4: Validate and buy ticket with card
with open("validate_and_buy.txt", "w") as f:
    f.write("login admin1 password123\n")
    f.write(f"validate-discount-card {card_id}\n")
    f.write(f"buy-ticket-discount 1000 1 1 ticket2.txt RouteCard.txt true\n")
    f.write("exit\n")
os.system("./build/train_app < validate_and_buy.txt")

# Step 5: Verify tickets
print("\nVerifying tickets...")
os.system("python3 verify_tickets.py")
