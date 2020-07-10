import csv
import sqlite3
from cs50 import SQL
from sys import argv, exit

if len(argv) == 2 and argv[1].endswith(".csv"):

# Create database
    open("students.db", "w").close()
    db = SQL("sqlite:///students.db")

    # Create tables
    db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth INT)")

    with open(argv[1], "r") as student:

        # Create DictReader
        reader = csv.DictReader(student)

        # Iterate over CSV file
        for row in reader:
            name = row["name"].split(" ")
            house = row["house"]
            birth = int(row["birth"])
            if len(name) == 2:
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", name[0], None, name[1], house, birth)
            elif len(name) == 3:
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", name[0], name[1], name[2], house, birth)

else:
    print(f"Error there should be 2 argv, you have {argv}")
    exit(1)



