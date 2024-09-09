from random import choice, randint
from string import digits, punctuation, ascii_lowercase, ascii_uppercase
from csv import DictWriter, DictReader
from cryptography.fernet import Fernet
import os


FIELDS = ["Name", "Password"]
DB = "temp/db.csv"


def load_key() -> Fernet:
    with open("temp/key.db", mode="a+") as file:
        file.seek(0)
        key: str = file.readline()
        if file.tell() == 0:
            key = Fernet.generate_key().decode("utf-8")
        file.write(key)
        return Fernet(key.encode("utf-8"))


def encrypt(password: str) -> str:
    fernet = load_key()
    processed_password = fernet.encrypt(password.encode("utf-8"))
    return processed_password.decode()


def decrypt(password: str) -> str:
    fernet = load_key()
    processed_password = fernet.decrypt(password.encode("utf-8"))
    return processed_password.decode()


def generate_password() -> str:
    maxPassLen = 0
    result = ""

    while maxPassLen < 8:
        maxPassLen = int(input("Length of your password (minimum 8): "))

    maxUpperLen = maxPassLen // 4
    maxLowerLen = maxPassLen // 4
    maxDigitsLen = maxPassLen // 4
    maxPunctuationLen = maxPassLen // 4

    maxLowerLen += maxPassLen - (maxLowerLen * 4)

    while maxPassLen > len(result):
        if maxUpperLen and randint(0, 1):
            result += choice(ascii_uppercase)
            maxUpperLen -= 1
            continue

        if maxLowerLen and randint(0, 1):
            result += choice(ascii_lowercase)
            maxLowerLen -= 1
            continue

        if maxDigitsLen and randint(0, 1):
            result += choice(digits)
            maxDigitsLen -= 1
            continue

        if maxPunctuationLen:
            result += choice(punctuation)
            maxPunctuationLen -= 1

    return result


def save_password(newPassword: dict) -> None:
    with open(DB, mode="a+") as file:
        newPassword["Password"] = encrypt(newPassword["Password"])
        file.seek(0)
        data = DictReader(file)

        for row in data:
            if row.get("Name") == newPassword["Name"]:
                print("Already Password Exits!")
                return

        writer = DictWriter(file, fieldnames=FIELDS)
        if file.tell() == 0:
            writer.writeheader()

        file.seek(0, os.SEEK_END)
        writer.writerow(newPassword)


def find_password(name: str) -> str:
    with open(DB, mode="r") as file:
        password = ""
        data = DictReader(file)

        for row in data:
            if row.get("Name") == name:
                password = row.get("Password", "Password Not Found!")

        return decrypt(password)


while True:
    option = input(
        """
Choice you option:

1) New password
2) Find your password
3) Exit

➡️ """
    )

    if option == "1":
        name = input("Name of the password: ")
        newPass = generate_password()

        save_password({"Name": name, "Password": newPass})

        print("Your given name :", name)
        print("Your Password :", newPass)

    elif option == "2":
        print("\n", find_password(input("Password Name:")), sep="")
    elif option == "3":
        exit()
    else:
        print("Invalid Choice!")
