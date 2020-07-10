import csv
import sqlite3
from cs50 import SQL
from sys import argv, exit

if len(argv) == 2:
    db = SQL("sqlite:///students.db")
    lsts = db.execute("SELECT * FROM students WHERE house = (?) ORDER BY last, first", argv[1])
    for lst in lsts:
        if lst['middle'] == None:
            print(f"{lst['first']} {lst['last']}, born {lst['birth']}")
        else:
            print(f"{lst['first']} {lst['middle']} {lst['last']}, born {lst['birth']}")

else:
    print(f"Error there should be 2 argv, you have {argv}")
    exit(1)

