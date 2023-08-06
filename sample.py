import csv

fooditems = {}
rating  = {}

with open('data.csv', 'r') as f:
    csv_read = csv.DictReader(f)

    for row in csv_read:
        foodname = row['Food_Name']
        rating = float['Rating']
        if (foodname not in fooditems):
            fooditems[foodname] = rating
            fooditems[foodname] = 1
        else:
            fooditems[foodname] += 1
            fooditems[foodname] += rating



for foodname, total_reviews in fooditems.items():
    remaining_reviews = 50 - total_reviews
    print(f" {foodname}: {total_reviews} reviews ")
    print(f"Remaining Reviews Needed: {remaining_reviews}")