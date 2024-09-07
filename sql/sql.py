import duckdb

# Create and connect to the SQLite database
with duckdb.connect("sql/db.sql") as db:
    result = db.sql("SELECT * FROM employees")
    print(result)
